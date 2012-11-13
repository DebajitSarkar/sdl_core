#ifndef RPC2COMMUNICATION_UI_GETCAPABILITIESRESPONSEMARSHALLER_INCLUDE
#define RPC2COMMUNICATION_UI_GETCAPABILITIESRESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/RPC2Objects/UI/GetCapabilitiesResponse.h"

namespace RPC2Communication
{
  namespace UI
  {

    struct GetCapabilitiesResponseMarshaller
    {
      static bool checkIntegrity(GetCapabilitiesResponse& e);
      static bool checkIntegrityConst(const GetCapabilitiesResponse& e);
    
      static bool fromString(const std::string& s,GetCapabilitiesResponse& e);
      static const std::string toString(const GetCapabilitiesResponse& e);
    
      static bool fromJSON(const Json::Value& s,GetCapabilitiesResponse& e);
      static Json::Value toJSON(const GetCapabilitiesResponse& e);
    };
  }
}

#endif
