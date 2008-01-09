/*
** Lua binding: Lua_ScriptEngine_tolua
** Generated automatically by tolua 5.1b on 01/08/08 09:17:46.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include <osgGIS/Attribute>
#include <osgGIS/Feature>
#include <osgGIS/FilterEnv>
#include <osgGIS/Resource>
#include <osgGIS/ResourceLibrary>
#include <string>
using namespace osgGIS;

extern "C" {
#include "tolua.h"

/* Exported function */
TOLUA_API int tolua_Lua_ScriptEngine_tolua_open (lua_State* tolua_S);
LUALIB_API int luaopen_Lua_ScriptEngine_tolua (lua_State* tolua_S);

/* function to release collected object */
#ifdef __cplusplus
 static int tolua_collect_GeoPoint (lua_State* tolua_S)
{
 GeoPoint* self = (GeoPoint*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}
 static int tolua_collect_std_string (lua_State* tolua_S)
{
 std::string* self = (std::string*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}
 static int tolua_collect_Attribute (lua_State* tolua_S)
{
 Attribute* self = (Attribute*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}
 static int tolua_collect_GeoExtent (lua_State* tolua_S)
{
 GeoExtent* self = (GeoExtent*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}
#else
static int tolua_collect (lua_State* tolua_S)
{
 void* self = tolua_tousertype(tolua_S,1,0);
 free(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Feature");
 tolua_usertype(tolua_S,"FilterEnv");
 tolua_usertype(tolua_S,"GeoPoint");
 tolua_usertype(tolua_S,"SpatialReference");
 tolua_usertype(tolua_S,"std::string");
 tolua_usertype(tolua_S,"Attribute");
 tolua_usertype(tolua_S,"GeoExtent");
}

/* method: getOID of class  Feature */
static int tolua_Lua_ScriptEngine_tolua_Feature_getOID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Feature",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Feature* self = (Feature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOID'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getOID();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOID'.",&tolua_err);
 return 0;
#endif
}

/* method: getAttribute of class  Feature */
static int tolua_Lua_ScriptEngine_tolua_Feature_getAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Feature",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Feature* self = (Feature*)  tolua_tousertype(tolua_S,1,0);
  const char* tolua_var_1 = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttribute'",NULL);
#endif
 {
  Attribute tolua_ret = (Attribute)  self->getAttribute(tolua_var_1);
 {
#ifdef __cplusplus
 void* tolua_obj = new Attribute(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_Attribute),"Attribute");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Attribute));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect),"Attribute");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttribute'.",&tolua_err);
 return 0;
#endif
}

/* method: getAttributeAsDouble of class  Feature */
static int tolua_Lua_ScriptEngine_tolua_Feature_getAttributeAsDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Feature",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Feature* self = (Feature*)  tolua_tousertype(tolua_S,1,0);
  const char* tolua_var_2 = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttributeAsDouble'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getAttributeAsDouble(tolua_var_2);
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttributeAsDouble'.",&tolua_err);
 return 0;
#endif
}

/* method: getAttributeAsInt of class  Feature */
static int tolua_Lua_ScriptEngine_tolua_Feature_getAttributeAsInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Feature",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Feature* self = (Feature*)  tolua_tousertype(tolua_S,1,0);
  const char* tolua_var_3 = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttributeAsInt'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getAttributeAsInt(tolua_var_3);
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttributeAsInt'.",&tolua_err);
 return 0;
#endif
}

/* method: getAttributeAsString of class  Feature */
static int tolua_Lua_ScriptEngine_tolua_Feature_getAttributeAsString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Feature",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Feature* self = (Feature*)  tolua_tousertype(tolua_S,1,0);
  const char* tolua_var_4 = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttributeAsString'",NULL);
#endif
 {
  std::string tolua_ret = (std::string)  self->getAttributeAsString(tolua_var_4);
 {
#ifdef __cplusplus
 void* tolua_obj = new std::string(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_std_string),"std::string");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(std::string));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect),"std::string");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttributeAsString'.",&tolua_err);
 return 0;
#endif
}

/* method: getAttributeAsBool of class  Feature */
static int tolua_Lua_ScriptEngine_tolua_Feature_getAttributeAsBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Feature",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Feature* self = (Feature*)  tolua_tousertype(tolua_S,1,0);
  const char* tolua_var_5 = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttributeAsBool'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getAttributeAsBool(tolua_var_5);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttributeAsBool'.",&tolua_err);
 return 0;
#endif
}

/* method: getExtent of class  Feature */
static int tolua_Lua_ScriptEngine_tolua_Feature_getExtent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Feature",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Feature* self = (Feature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getExtent'",NULL);
#endif
 {
  GeoExtent tolua_ret = (GeoExtent)  self->getExtent();
 {
#ifdef __cplusplus
 void* tolua_obj = new GeoExtent(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_GeoExtent),"GeoExtent");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GeoExtent));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect),"GeoExtent");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getExtent'.",&tolua_err);
 return 0;
#endif
}

/* method: isValid of class  Attribute */
static int tolua_Lua_ScriptEngine_tolua_Attribute_isValid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Attribute",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Attribute* self = (Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isValid'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isValid();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isValid'.",&tolua_err);
 return 0;
#endif
}

/* method: asString of class  Attribute */
static int tolua_Lua_ScriptEngine_tolua_Attribute_asString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Attribute",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Attribute* self = (Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'asString'",NULL);
#endif
 {
  std::string tolua_ret = (std::string)  self->asString();
 {
#ifdef __cplusplus
 void* tolua_obj = new std::string(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_std_string),"std::string");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(std::string));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect),"std::string");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'asString'.",&tolua_err);
 return 0;
#endif
}

/* method: asInt of class  Attribute */
static int tolua_Lua_ScriptEngine_tolua_Attribute_asInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Attribute",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Attribute* self = (Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'asInt'",NULL);
#endif
 {
  int tolua_ret = (int)  self->asInt();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'asInt'.",&tolua_err);
 return 0;
#endif
}

/* method: asDouble of class  Attribute */
static int tolua_Lua_ScriptEngine_tolua_Attribute_asDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Attribute",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Attribute* self = (Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'asDouble'",NULL);
#endif
 {
  double tolua_ret = (double)  self->asDouble();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'asDouble'.",&tolua_err);
 return 0;
#endif
}

/* method: asBool of class  Attribute */
static int tolua_Lua_ScriptEngine_tolua_Attribute_asBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Attribute",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Attribute* self = (Attribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'asBool'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->asBool();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'asBool'.",&tolua_err);
 return 0;
#endif
}

/* method: getExtent of class  FilterEnv */
static int tolua_Lua_ScriptEngine_tolua_FilterEnv_getExtent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FilterEnv",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FilterEnv* self = (FilterEnv*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getExtent'",NULL);
#endif
 {
  GeoExtent tolua_ret = (GeoExtent)  self->getExtent();
 {
#ifdef __cplusplus
 void* tolua_obj = new GeoExtent(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_GeoExtent),"GeoExtent");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GeoExtent));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect),"GeoExtent");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getExtent'.",&tolua_err);
 return 0;
#endif
}

/* method: getInputSRS of class  FilterEnv */
static int tolua_Lua_ScriptEngine_tolua_FilterEnv_getInputSRS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FilterEnv",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FilterEnv* self = (FilterEnv*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInputSRS'",NULL);
#endif
 {
  SpatialReference* tolua_ret = (SpatialReference*)  self->getInputSRS();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpatialReference");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInputSRS'.",&tolua_err);
 return 0;
#endif
}

/* method: getXMin of class  GeoExtent */
static int tolua_Lua_ScriptEngine_tolua_GeoExtent_getXMin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GeoExtent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GeoExtent* self = (GeoExtent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getXMin'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getXMin();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getXMin'.",&tolua_err);
 return 0;
#endif
}

/* method: getYMin of class  GeoExtent */
static int tolua_Lua_ScriptEngine_tolua_GeoExtent_getYMin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GeoExtent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GeoExtent* self = (GeoExtent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getYMin'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getYMin();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getYMin'.",&tolua_err);
 return 0;
#endif
}

/* method: getXMax of class  GeoExtent */
static int tolua_Lua_ScriptEngine_tolua_GeoExtent_getXMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GeoExtent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GeoExtent* self = (GeoExtent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getXMax'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getXMax();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getXMax'.",&tolua_err);
 return 0;
#endif
}

/* method: getYMax of class  GeoExtent */
static int tolua_Lua_ScriptEngine_tolua_GeoExtent_getYMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GeoExtent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GeoExtent* self = (GeoExtent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getYMax'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getYMax();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getYMax'.",&tolua_err);
 return 0;
#endif
}

/* method: contains of class  GeoExtent */
static int tolua_Lua_ScriptEngine_tolua_GeoExtent_contains00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GeoExtent",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GeoExtent* self = (GeoExtent*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'contains'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->contains(x,y);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'contains'.",&tolua_err);
 return 0;
#endif
}

/* method: contains of class  GeoExtent */
static int tolua_Lua_ScriptEngine_tolua_GeoExtent_contains01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GeoExtent",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"GeoPoint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  GeoExtent* self = (GeoExtent*)  tolua_tousertype(tolua_S,1,0);
  GeoPoint p = *((GeoPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'contains'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->contains(p);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_Lua_ScriptEngine_tolua_GeoExtent_contains00(tolua_S);
}

/* method: getArea of class  GeoExtent */
static int tolua_Lua_ScriptEngine_tolua_GeoExtent_getArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GeoExtent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GeoExtent* self = (GeoExtent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArea'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getArea();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArea'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  GeoPoint */
static int tolua_Lua_ScriptEngine_tolua_GeoPoint_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"GeoPoint",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"SpatialReference",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  SpatialReference* srs = ((SpatialReference*)  tolua_tousertype(tolua_S,4,0));
 {
  GeoPoint* tolua_ret = (GeoPoint*)  new GeoPoint(x,y,srs);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GeoPoint");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: x of class  GeoPoint */
static int tolua_Lua_ScriptEngine_tolua_GeoPoint_x00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GeoPoint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GeoPoint* self = (GeoPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'x'",NULL);
#endif
 {
  double tolua_ret = (double)  self->x();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'x'.",&tolua_err);
 return 0;
#endif
}

/* method: y of class  GeoPoint */
static int tolua_Lua_ScriptEngine_tolua_GeoPoint_y00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GeoPoint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GeoPoint* self = (GeoPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'y'",NULL);
#endif
 {
  double tolua_ret = (double)  self->y();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'y'.",&tolua_err);
 return 0;
#endif
}

/* method: z of class  GeoPoint */
static int tolua_Lua_ScriptEngine_tolua_GeoPoint_z00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GeoPoint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GeoPoint* self = (GeoPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'z'",NULL);
#endif
 {
  double tolua_ret = (double)  self->z();
 tolua_pushnumber(tolua_S,(double)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'z'.",&tolua_err);
 return 0;
#endif
}

/* method: transform of class  SpatialReference */
static int tolua_Lua_ScriptEngine_tolua_SpatialReference_transform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SpatialReference",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"GeoPoint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SpatialReference* self = (SpatialReference*)  tolua_tousertype(tolua_S,1,0);
  GeoPoint in = *((GeoPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'transform'",NULL);
#endif
 {
  GeoPoint tolua_ret = (GeoPoint)  self->transform(in);
 {
#ifdef __cplusplus
 void* tolua_obj = new GeoPoint(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_GeoPoint),"GeoPoint");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GeoPoint));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect),"GeoPoint");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transform'.",&tolua_err);
 return 0;
#endif
}

/* method: getBasisSRS of class  SpatialReference */
static int tolua_Lua_ScriptEngine_tolua_SpatialReference_getBasisSRS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SpatialReference",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SpatialReference* self = (SpatialReference*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBasisSRS'",NULL);
#endif
 {
  SpatialReference* tolua_ret = (SpatialReference*)  self->getBasisSRS();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpatialReference");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBasisSRS'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_Lua_ScriptEngine_tolua (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Feature","Feature","",0);
#else
 tolua_cclass(tolua_S,"Feature","Feature","",tolua_collect);
#endif
 tolua_beginmodule(tolua_S,"Feature");
 tolua_function(tolua_S,"getOID",tolua_Lua_ScriptEngine_tolua_Feature_getOID00);
 tolua_function(tolua_S,"getAttribute",tolua_Lua_ScriptEngine_tolua_Feature_getAttribute00);
 tolua_function(tolua_S,"getAttributeAsDouble",tolua_Lua_ScriptEngine_tolua_Feature_getAttributeAsDouble00);
 tolua_function(tolua_S,"getAttributeAsInt",tolua_Lua_ScriptEngine_tolua_Feature_getAttributeAsInt00);
 tolua_function(tolua_S,"getAttributeAsString",tolua_Lua_ScriptEngine_tolua_Feature_getAttributeAsString00);
 tolua_function(tolua_S,"getAttributeAsBool",tolua_Lua_ScriptEngine_tolua_Feature_getAttributeAsBool00);
 tolua_function(tolua_S,"getExtent",tolua_Lua_ScriptEngine_tolua_Feature_getExtent00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Attribute","Attribute","",tolua_collect_Attribute);
#else
 tolua_cclass(tolua_S,"Attribute","Attribute","",tolua_collect);
#endif
 tolua_beginmodule(tolua_S,"Attribute");
 tolua_function(tolua_S,"isValid",tolua_Lua_ScriptEngine_tolua_Attribute_isValid00);
 tolua_function(tolua_S,"asString",tolua_Lua_ScriptEngine_tolua_Attribute_asString00);
 tolua_function(tolua_S,"asInt",tolua_Lua_ScriptEngine_tolua_Attribute_asInt00);
 tolua_function(tolua_S,"asDouble",tolua_Lua_ScriptEngine_tolua_Attribute_asDouble00);
 tolua_function(tolua_S,"asBool",tolua_Lua_ScriptEngine_tolua_Attribute_asBool00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"FilterEnv","FilterEnv","",0);
#else
 tolua_cclass(tolua_S,"FilterEnv","FilterEnv","",tolua_collect);
#endif
 tolua_beginmodule(tolua_S,"FilterEnv");
 tolua_function(tolua_S,"getExtent",tolua_Lua_ScriptEngine_tolua_FilterEnv_getExtent00);
 tolua_function(tolua_S,"getInputSRS",tolua_Lua_ScriptEngine_tolua_FilterEnv_getInputSRS00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"GeoExtent","GeoExtent","",tolua_collect_GeoExtent);
#else
 tolua_cclass(tolua_S,"GeoExtent","GeoExtent","",tolua_collect);
#endif
 tolua_beginmodule(tolua_S,"GeoExtent");
 tolua_function(tolua_S,"getXMin",tolua_Lua_ScriptEngine_tolua_GeoExtent_getXMin00);
 tolua_function(tolua_S,"getYMin",tolua_Lua_ScriptEngine_tolua_GeoExtent_getYMin00);
 tolua_function(tolua_S,"getXMax",tolua_Lua_ScriptEngine_tolua_GeoExtent_getXMax00);
 tolua_function(tolua_S,"getYMax",tolua_Lua_ScriptEngine_tolua_GeoExtent_getYMax00);
 tolua_function(tolua_S,"contains",tolua_Lua_ScriptEngine_tolua_GeoExtent_contains00);
 tolua_function(tolua_S,"contains",tolua_Lua_ScriptEngine_tolua_GeoExtent_contains01);
 tolua_function(tolua_S,"getArea",tolua_Lua_ScriptEngine_tolua_GeoExtent_getArea00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"GeoPoint","GeoPoint","",tolua_collect_GeoPoint);
#else
 tolua_cclass(tolua_S,"GeoPoint","GeoPoint","",tolua_collect);
#endif
 tolua_beginmodule(tolua_S,"GeoPoint");
 tolua_function(tolua_S,"new",tolua_Lua_ScriptEngine_tolua_GeoPoint_new00);
 tolua_function(tolua_S,"x",tolua_Lua_ScriptEngine_tolua_GeoPoint_x00);
 tolua_function(tolua_S,"y",tolua_Lua_ScriptEngine_tolua_GeoPoint_y00);
 tolua_function(tolua_S,"z",tolua_Lua_ScriptEngine_tolua_GeoPoint_z00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"SpatialReference","SpatialReference","",0);
#else
 tolua_cclass(tolua_S,"SpatialReference","SpatialReference","",tolua_collect);
#endif
 tolua_beginmodule(tolua_S,"SpatialReference");
 tolua_function(tolua_S,"transform",tolua_Lua_ScriptEngine_tolua_SpatialReference_transform00);
 tolua_function(tolua_S,"getBasisSRS",tolua_Lua_ScriptEngine_tolua_SpatialReference_getBasisSRS00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_Lua_ScriptEngine_tolua_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_Lua_ScriptEngine_tolua);
 lua_pushstring(tolua_S, "Lua_ScriptEngine_tolua");
 lua_call(tolua_S, 1, 0);
 return 1;
}

}