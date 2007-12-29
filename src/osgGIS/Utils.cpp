#include <osgGIS/Utils>
#include <algorithm>

using namespace osgGIS;

bool
StringUtils::endsWith(const std::string& input,
                      const std::string& suffix,
                      bool case_sensitive )
{
    int suffix_len = suffix.length();
    std::string input_p = input;
    std::string suffix_p = suffix;
    if ( !case_sensitive ) {
        std::transform( input_p.begin(), input_p.end(), input_p.begin(), ::tolower );
        std::transform( suffix_p.begin(), suffix_p.end(), suffix_p.begin(), ::tolower );
    }
    return input_p.length() >= suffix_len && input_p.substr( input_p.length()-suffix_len ) == suffix_p;
}