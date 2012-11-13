#ifndef APPLINKRPC_ONBUTTONEVENTMARSHALLER_INCLUDE
#define APPLINKRPC_ONBUTTONEVENTMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/OnButtonEvent.h"


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Wed Nov  7 13:10:41 2012
  source stamp	Thu Oct 25 06:49:27 2012
  author	robok0der
*/

namespace AppLinkRPC
{

  struct OnButtonEventMarshaller
  {
    static bool checkIntegrity(OnButtonEvent& e);
    static bool checkIntegrityConst(const OnButtonEvent& e);
  
    static bool fromString(const std::string& s,OnButtonEvent& e);
    static const std::string toString(const OnButtonEvent& e);
  
    static bool fromJSON(const Json::Value& s,OnButtonEvent& e);
    static Json::Value toJSON(const OnButtonEvent& e);
  };
}

#endif
