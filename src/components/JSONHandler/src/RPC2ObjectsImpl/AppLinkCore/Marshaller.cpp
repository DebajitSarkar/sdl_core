#include <cstring>
#include "../include/JSONHandler/RPC2Objects/AppLinkCore/Marshaller.h"

#include "../include/JSONHandler/RPC2Objects/AppLinkCore/ActivateApp.h"
#include "../include/JSONHandler/RPC2Objects/AppLinkCore/ActivateAppResponse.h"
#include "../include/JSONHandler/RPC2Objects/AppLinkCore/OnAppRegistered.h"
#include "../include/JSONHandler/RPC2Objects/AppLinkCore/OnAppUnregistered.h"

namespace RPC2Communication
{
  namespace AppLinkCore
  {
#include "Marshaller.inc"
  }
}

/*
  interface	RPC2Communication::AppLinkCore
  version	1.2
  generated at	Wed Nov  7 11:25:43 2012
  source stamp	Wed Nov  7 09:35:35 2012
  author	robok0der
*/

using namespace RPC2Communication;
using namespace AppLinkRPC;
using namespace RPC2Communication::AppLinkCore;


const Marshaller::Methods Marshaller::getIndex(const char* s)
{
  if(!s)
    return METHOD_INVALID;  const struct localHash* p=Marshaller_intHash::getPointer(s,strlen(s));
  return p ? static_cast<Methods>(p->idx) : METHOD_INVALID;
}

RPC2Command* Marshaller::fromString(const std::string& s)
{
  RPC2Command* rv=0;
  try
  {
    Json::Reader reader;
    Json::Value json;

    if(!reader.parse(s,json,false))  return 0;    if(!(rv=fromJSON(json)))  return 0;
  }
  catch(...)
  {
    return 0;
  }
  return rv;
}

std::string Marshaller::toString(const RPC2Command* msg)
{
  if(!msg)  return "";

  Json::Value json=toJSON(msg);

  if(json.isNull()) return "";

  Json::FastWriter writer;
  std::string rv;
  return writer.write(json);
}

RPC2Command* Marshaller::fromJSON(const Json::Value& json)
{
  if(!json.isObject())  return 0;
  if(!json.isMember("jsonrpc") || !json["jsonrpc"].isString() || json["jsonrpc"].asString().compare("2.0"))  return 0;

  if(json.isMember("error"))				// error
  {
    RPC2Error rv;
    if(!RPC2ErrorMarshaller::fromJSON(json,rv))  return 0;

    return new RPC2Error(rv);
  }

  if(!json.isMember("id"))				// notification
  {
    if(!json.isMember("method") || !json["method"].isString())  return 0;

    Methods m=getIndex(json["method"].asString().c_str());

    switch(m)
    {
      case METHOD_ONAPPREGISTERED:
      {
        OnAppRegistered *rv=new OnAppRegistered;
        return OnAppRegisteredMarshaller::fromJSON(json,*rv) ? rv : 0;
      }
      case METHOD_ONAPPUNREGISTERED:
      {
        OnAppUnregistered *rv=new OnAppUnregistered;
        return OnAppUnregisteredMarshaller::fromJSON(json,*rv) ? rv : 0;
      }
      default:
        return 0;
    }
    return 0;
  }

  if(json.isMember("method"))				// request
  {
    if(!json["id"].isInt())  return 0;

    Methods m=getIndex(json["method"].asString().c_str());
    switch(m)
    {
      case METHOD_ACTIVATEAPP:
      {
        ActivateApp *rv=new ActivateApp;
        return ActivateAppMarshaller::fromJSON(json,*rv) ? rv : 0;
      }
      default:
        return 0;
    }
    return 0;
  }
							// response
  if(!json.isMember("result"))  return 0;

  if(!json["id"].isInt()) return 0;

// here is extension of protocol, two fields added: resultCode and method
  if(!json["result"].isMember("resultCode") || !json["result"]["resultCode"].isString())  return 0;
  if(!json["result"].isMember("method") || !json["result"]["method"].isString())  return 0;

  Methods m=getIndex(json["result"]["method"].asString().c_str());

  switch(m)
  {
    case METHOD_ACTIVATEAPPRESPONSE:
    {
      ActivateAppResponse *rv=new ActivateAppResponse;
      return ActivateAppResponseMarshaller::fromJSON(json,*rv) ? rv : 0;
    }
    default:
      return 0;
  }

  return 0;
}


Json::Value Marshaller::Notification2JSON(const RPC2Communication::RPC2Notification* msg)
{
  Json::Value j=Json::Value(Json::nullValue);
  if(!msg) return j;

  switch(msg->getMethod())
  {
    case METHOD_ONAPPREGISTERED:
      return OnAppRegisteredMarshaller::toJSON(*static_cast<const OnAppRegistered*>(msg));
    case METHOD_ONAPPUNREGISTERED:
      return OnAppUnregisteredMarshaller::toJSON(*static_cast<const OnAppUnregistered*>(msg));
    default:
      return j;
  }
}


Json::Value Marshaller::Request2JSON(const RPC2Communication::RPC2Request* msg)
{
  Json::Value j=Json::Value(Json::nullValue);
  if(!msg) return j;
  switch(msg->getMethod())
  {
    case METHOD_ACTIVATEAPP:
      return ActivateAppMarshaller::toJSON(*static_cast<const ActivateApp*>(msg));
    default:
      return j;
  }
}


Json::Value Marshaller::Response2JSON(const RPC2Communication::RPC2Response* msg)
{
  Json::Value j=Json::Value(Json::nullValue);
  if(!msg) return j;
  switch(msg->getMethod())
  {
    case METHOD_ACTIVATEAPPRESPONSE:
      return ActivateAppResponseMarshaller::toJSON(*static_cast<const ActivateAppResponse*>(msg));
    default:
      return j;
  }
}


Json::Value Marshaller::toJSON(const RPC2Command* msg)
{
  Json::Value j=Json::Value(Json::nullValue);
  if(!msg) return j;

  switch(msg->getCommandType())
  {
    case RPC2Command::REQUEST:
      return Request2JSON(static_cast<const RPC2Request*>(msg));
    case RPC2Command::RESPONSE:
      return Response2JSON(static_cast<const RPC2Response*>(msg));
    case RPC2Command::NOTIFICATION:
      return Notification2JSON(static_cast<const RPC2Notification*>(msg));

    case RPC2Command::ERROR:
      return RPC2ErrorMarshaller::toJSON(*static_cast<const RPC2Error*>(msg));

    case RPC2Command::UNDEFINED:
    default:
      return j;
  }
}


const Marshaller::localHash Marshaller::mHashTable[4]=
{
  {"AppLinkCore.ActivateApp",0,&Marshaller::mActivateApp},
  {"AppLinkCore.ActivateAppResponse",1,&Marshaller::mActivateAppResponse},
  {"AppLinkCore.OnAppRegistered",2,&Marshaller::mOnAppRegistered},
  {"AppLinkCore.OnAppUnregistered",3,&Marshaller::mOnAppUnregistered}

};

RPC2Communication::RPC2ErrorMarshaller Marshaller::mRPC2ErrorInternal;

ActivateAppMarshaller Marshaller::mActivateApp;
ActivateAppResponseMarshaller Marshaller::mActivateAppResponse;
OnAppRegisteredMarshaller Marshaller::mOnAppRegistered;
OnAppUnregisteredMarshaller Marshaller::mOnAppUnregistered;
