#ifndef RPC2COMMUNICATION_UI_ONCOMMANDMARSHALLER_INCLUDE
#define RPC2COMMUNICATION_UI_ONCOMMANDMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/RPC2Objects/UI/OnCommand.h"

namespace RPC2Communication
{
  namespace UI
  {

    struct OnCommandMarshaller
    {
      static bool checkIntegrity(OnCommand& e);
      static bool checkIntegrityConst(const OnCommand& e);
    
      static bool fromString(const std::string& s,OnCommand& e);
      static const std::string toString(const OnCommand& e);
    
      static bool fromJSON(const Json::Value& s,OnCommand& e);
      static Json::Value toJSON(const OnCommand& e);
    };
  }
}

#endif
