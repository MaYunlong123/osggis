/**
/* osgGIS - GIS Library for OpenSceneGraph
 * Copyright 2007-2008 Glenn Waldron and Pelican Ventures, Inc.
 * http://osggis.org
 *
 * osgGIS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <osgGISProjects/MapLayerCompiler>
#include <osgGIS/FeatureLayerCompiler>
#include <osgGIS/ResourcePackager>
#include <osgGIS/Report>
#include <osgGIS/Session>
#include <osgGIS/Utils>
#include <osgGIS/Registry>
#include <osgDB/FileUtils>
#include <osgDB/FileNameUtils>
#include <osgDB/WriteFile>
#include <osgDB/ReadFile>
#include <osg/LOD>
#include <osg/MatrixTransform>
#include <osg/PagedLOD>
#include <osg/ProxyNode>
#include <osg/NodeVisitor>
#include <osg/Timer>
#include <sstream>

using namespace osgGIS;
using namespace osgGISProjects;
using namespace OpenThreads;

#define MY_PRIORITY_SCALE 1.0f //0.5f


/*****************************************************************************/

class CompileSessionImpl : public CompileSession
{
public:
    osg::ref_ptr<Task> getNextCompletedTask()
    {
        osg::ref_ptr<Task> next;
        if ( recently_completed_tasks.size() > 0 )
        {
            next = recently_completed_tasks.front();
            recently_completed_tasks.pop();
        }
        return osg::ref_ptr<Task>( next.get() );
    }

    double getElapsedTimeSeconds() const {
        osg::Timer_t now = osg::Timer::instance()->tick();
        return osg::Timer::instance()->delta_s( start_time, now );
    }
    
    double getPredicitedRemainingTimeSeconds() const {
        return 0.0;
    }

    osg::Group* getOrCreateSceneGraph()
    {
        if ( !scene_graph.valid() )
        {
            scene_graph = new osg::Group();
        }
        return scene_graph.get();
    }

public:
    CompileSessionImpl( TaskManager* _task_man, 
                        Profile*     _profile,
                        unsigned int _total_tasks,
                        osg::Timer_t _start_time )
        : task_man( _task_man ), profile( _profile ),
          total_tasks( _total_tasks ), start_time( _start_time ) {
        //NOP
    }

    void clearTaskQueue()
    {
        while( recently_completed_tasks.size() > 0 )
            recently_completed_tasks.pop();
    }

    TaskQueue& getTaskQueue()
    {
        return recently_completed_tasks;
    }

    TaskManager* getTaskManager()
    {
        return task_man.get();
    }

    unsigned int getTotalTasks() const
    {
        return total_tasks;
    }

    Report* getReport()
    {
        //if ( !report.valid() )
        //    report = new Report();
        return report.get();
    }

    Profile* getProfile()
    {
        return profile.get();
    }

private:
    osg::ref_ptr<TaskManager> task_man;
    osg::Timer_t start_time;
    unsigned int total_tasks;
    osg::Timer_t current_time;
    TaskQueue recently_completed_tasks;
    osg::ref_ptr<osg::Group> scene_graph;
    osg::ref_ptr<Report> report;
    osg::ref_ptr<Profile> profile;
};

/*****************************************************************************/

MapLayerCompiler::MapLayerCompiler( MapLayer* _layer, Session* _session )
{
    map_layer   = _layer;
    session     = _session;
    paged       = true;
    depth_first = true;
}

MapLayer*
MapLayerCompiler::getMapLayer() const {
    return map_layer.get();
}

void
MapLayerCompiler::setPaged( bool value )
{
    if ( paged != value )
    {
        paged = value;
    }
}

bool
MapLayerCompiler::getPaged() const {
    return paged;
}

void
MapLayerCompiler::setBuildDepthFirst( bool value ) {
    depth_first = value;
}

void
MapLayerCompiler::setAbsoluteOutputURI( const std::string& value ) {
    output_uri = value;
}

void
MapLayerCompiler::setTerrain(osg::Node*              _terrain,
                             const SpatialReference* _terrain_srs,
                             const GeoExtent&        _terrain_extent )
{
    terrain_node   = _terrain;
    terrain_srs    = (SpatialReference*)_terrain_srs;
    terrain_extent = _terrain_extent;

    if ( !terrain_srs.valid() )
        terrain_srs = osgGIS::Registry::SRSFactory()->createSRSfromTerrain( terrain_node.get() );

    if ( !terrain_srs.valid() )
        osgGIS::warn() << "[MapLayerCompiler] WARNING: cannot determine SRS of terrain!" << std::endl;
}

osg::Node*
MapLayerCompiler::getTerrainNode()
{
    return terrain_node.get();
}

SpatialReference* 
MapLayerCompiler::getTerrainSRS() const
{
    return terrain_srs.get();
}

const GeoExtent& 
MapLayerCompiler::getTerrainExtent() const
{
    return terrain_extent;
}

void
MapLayerCompiler::setArchive( osgDB::Archive* _archive, const std::string& _filename )
{
    archive = _archive;
    archive_filename = _filename;
}

osgDB::Archive*
MapLayerCompiler::getArchive() 
{
    return archive.get();
}

const std::string&
MapLayerCompiler::getArchiveFileName() const
{
    return archive_filename;
}

void
MapLayerCompiler::setResourcePackager( ResourcePackager* value ) {
    resource_packager = value;
}

ResourcePackager*
MapLayerCompiler::getResourcePackager() const {
    return resource_packager.get();
}

Session*
MapLayerCompiler::getSession()
{
    if ( !session.valid() )
    {
        session = new Session();
    }
    return session.get();
}

osgGIS::SpatialReference*
MapLayerCompiler::getOutputSRS()
{
    return map_layer->getOutputSRS( getSession(), getTerrainSRS() );
}

std::string
MapLayerCompiler::createAbsPathFromTemplate( const std::string& core )
{
    return PathUtils::combinePaths(
        osgDB::getFilePath( output_uri ),
        core + "." + osgDB::getLowerCaseFileExtension( output_uri ) );
}

std::string
MapLayerCompiler::createRelPathFromTemplate( const std::string& core )
{
    return core + "." + osgDB::getLowerCaseFileExtension( output_uri );
}

void
MapLayerCompiler::setCellSelector( CellSelector* _selector )
{
    cell_selector = _selector;
}

void
MapLayerCompiler::setCenterAndRadius( osg::Node* node, const GeoExtent& cell_extent, SmartReadCallback* reader )
{
    SpatialReference* srs = map_layer->getOutputSRS( getSession(), getTerrainSRS() );
    // first get the output srs centroid: 
    GeoPoint centroid = srs->transform( cell_extent.getCentroid() );
    GeoPoint sw = srs->transform( cell_extent.getSouthwest() );

    double radius = map_layer->getEncodeCellRadius()?
        (centroid-sw).length() :
        -1.0;
    
    if ( terrain_node.valid() && terrain_srs.valid() )
    {
        GeoPoint clamped;
        for( int t=0; t<5; t++ )
        {
            clamped = GeomUtils::clampToTerrain( centroid, terrain_node.get(), terrain_srs.get(), reader );
            if ( !clamped.isValid() )
            {
                // if the clamp failed, it's due to the geocentric intersection bug in which the isect
                // fails when coplanar with a tile boundary/skirt. Fudge the centroid and try again.
                double fudge = 0.001*((double)(1+(::rand()%10)));
                centroid.x() += fudge;
                centroid.y() -= fudge;
                centroid.z() += fudge*fudge;
            }
            else
            {
                break;
            }
        }

        if ( !clamped.isValid() )
        {
            const SpatialReference* geo = srs->getGeographicSRS();
            GeoPoint latlon = geo->transform( centroid );
            osgGIS::warn() << "*** UNABLE TO CLAMP CENTROID: ***" << latlon.toString() << std::endl;
        }
        else
        {
            centroid = clamped;
        }
    }
    else
    {
        osgGIS::warn() << "*** Failed to clamp Center/Radius for cell" << std::endl;
    }

    if ( dynamic_cast<osg::LOD*>( node ) )
    {
        osg::LOD* plod = static_cast<osg::LOD*>(node);
        plod->setCenter( centroid );
        plod->setRadius( radius );
    }
    else if ( dynamic_cast<osg::ProxyNode*>( node ) )
    {
        osg::ProxyNode* proxy = static_cast<osg::ProxyNode*>(node);
        proxy->setCenter( centroid );
        proxy->setRadius( radius );
    }
}

CompileSession*
MapLayerCompiler::startCompiling( TaskManager* my_task_man )
{
    // make a task manager to run the compilation:
    osg::ref_ptr<TaskManager> task_man = my_task_man;
    if ( !task_man.valid() )
        task_man = new TaskManager( 0 );

    // make a profile describing this compilation setup:
    osg::ref_ptr<Profile> profile = createProfile();

    // create and queue up all the tasks to run:
    unsigned int total_tasks = queueTasks( profile.get(), task_man.get() );

    // configure the packager so that skins and model end up in the right place:
    if ( resource_packager.valid() )
    {
        resource_packager->setArchive( getArchive() );
        resource_packager->setOutputLocation( osgDB::getFilePath( output_uri ) );
    }

    // pre-gen the spatial indexes (optional, but saves a little time)
    for( MapLayerLevelsOfDetail::iterator i = map_layer->getLevels().begin(); i != map_layer->getLevels().end(); i++ )
    {
        i->get()->getFeatureLayer()->assertSpatialIndex();
    }
    
    // make a reporting channel:
    osg::ref_ptr<Report> default_report = new Report();

    // create and return a compile session that should be sent to continueCompiling()
    // and finishCompiling().
    return new CompileSessionImpl( task_man.get(), profile.get(), total_tasks, osg::Timer::instance()->tick() );
}

bool
MapLayerCompiler::continueCompiling( CompileSession* cs_interface )
{
    CompileSessionImpl* cs = static_cast<CompileSessionImpl*>( cs_interface );

    cs->clearTaskQueue();
    
    if( cs->getTaskManager()->wait( 1000L ) )
    {
        osg::ref_ptr<Task> completed_task = cs->getTaskManager()->getNextCompletedTask();
        if ( completed_task.valid() )
        {
            CellCompiler* cell_compiler = reinterpret_cast<CellCompiler*>( completed_task.get() );
            if ( cell_compiler->isInExceptionState() )
            {
                //TODO: replace this with Report facility
                osgGIS::notify( osg::WARN ) << "ERROR: cell failed; unhandled exception state."
                    << std::endl;
                cs->getTaskQueue().push( cell_compiler );
            }
            else if ( cell_compiler->getResult().isOK() )
            {
                cell_compiler->runSynchronousPostProcess( cs->getReport() );

                // give the layer compiler an opportunity to do something:
                processCompletedTask( cell_compiler );

                // record the completed task to the caller can see it
                cs->getTaskQueue().push( cell_compiler );

                unsigned int total_tasks = cs->getTotalTasks();
                unsigned int tasks_completed = total_tasks - cs->getTaskManager()->getNumTasks();

                float p = 100.0f * (float)tasks_completed/(float)total_tasks;
                float elapsed = (float)cs->getElapsedTimeSeconds();
                float avg_task_time = elapsed/(float)tasks_completed;
                float time_remaining = ((float)total_tasks-(float)tasks_completed)*avg_task_time;

                unsigned int hrs,mins,secs;
                TimeUtils::getHMSDuration( time_remaining, hrs, mins, secs );

                char buf[10];
                sprintf( buf, "%02d:%02d:%02d", hrs, mins, secs );
                osgGIS::notify(osg::NOTICE) << tasks_completed << "/" << total_tasks 
                    << " tasks (" << (int)p << "%) complete, " 
                    << buf << " remaining" << std::endl;
            }
            else
            {
                //TODO: replace this with Report facility
                osgGIS::notify( osg::WARN ) << "ERROR: compilation of cell "
                    << cell_compiler->getName() << " failed : "
                    << cell_compiler->getResult().getMessage()
                    << std::endl;
            }
        }
    }

    return cs->getTaskManager()->hasMoreTasks();
}

bool 
MapLayerCompiler::finishCompiling( CompileSession* cs_interface )
{
    CompileSessionImpl* cs = static_cast<CompileSessionImpl*>( cs_interface );

    cs->clearTaskQueue();
    
    buildIndex( cs->getProfile(), cs->getOrCreateSceneGraph() );

    if ( cs->getOrCreateSceneGraph() )
    {
        osgUtil::Optimizer opt;
        opt.optimize( cs->getOrCreateSceneGraph(), 
            osgUtil::Optimizer::SPATIALIZE_GROUPS |
            osgUtil::Optimizer::STATIC_OBJECT_DETECTION |
            osgUtil::Optimizer::SHARE_DUPLICATE_STATE );
    }

    osgGIS::notify( osg::NOTICE )
        << "Compilation finished, total time = " << cs->getElapsedTimeSeconds() << " seconds"
        << std::endl;

    return true;
}

osg::Group*
MapLayerCompiler::compile( TaskManager* my_task_man )
{
    osg::ref_ptr<CompileSession> cs = static_cast<CompileSessionImpl*>( startCompiling( my_task_man ) );

    while( continueCompiling( cs.get() ) );

    if ( finishCompiling( cs.get() ) )
    {
        osg::Group* result = cs->getOrCreateSceneGraph();
        result->ref(); // since the CS will be destroyed, unref'ing the result
        return result;
    }
    else
    {
        return NULL;
    }
}


osg::Group*
MapLayerCompiler::compileIndexOnly( CompileSession* cs_interface )
{
    CompileSessionImpl* cs = static_cast<CompileSessionImpl*>( cs_interface );

    // make a profile describing this compilation setup:
    osg::ref_ptr<Profile> profile = createProfile();

    buildIndex( profile.get(), cs->getOrCreateSceneGraph() );

    if ( cs->getOrCreateSceneGraph() )
    {
        osgUtil::Optimizer opt;
        opt.optimize( cs->getOrCreateSceneGraph(), 
            osgUtil::Optimizer::SPATIALIZE_GROUPS |
            osgUtil::Optimizer::STATIC_OBJECT_DETECTION |
            osgUtil::Optimizer::SHARE_DUPLICATE_STATE );
    }

    return cs->getOrCreateSceneGraph();
}
