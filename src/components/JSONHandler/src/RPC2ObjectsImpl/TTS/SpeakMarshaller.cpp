#include "../include/JSONHandler/RPC2Objects/TTS/Speak.h"
#include "../src/ALRPCObjectsImpl/TTSChunkMarshaller.h"
#include "../src/ALRPCObjectsImpl/ResultMarshaller.h"
#include "SpeakMarshaller.h"

/*
  interface	RPC2Communication::TTS
  version	1.2
  generated at	Wed Nov  7 11:25:55 2012
  source stamp	Wed Nov  7 09:34:03 2012
  author	robok0der
*/

using namespace RPC2Communication;
using namespace AppLinkRPC;
using namespace RPC2Communication::TTS;

bool SpeakMarshaller::checkIntegrity(Speak& s)
{
  return checkIntegrityConst(s);
}


bool SpeakMarshaller::fromString(const std::string& s,Speak& e)
{
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(!fromJSON(json,e))  return false;
  }
  catch(...)
  {
    return false;
  }
  return true;
}


const std::string SpeakMarshaller::toString(const Speak& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool SpeakMarshaller::checkIntegrityConst(const Speak& s)
{
  {
    unsigned int i=s.ttsChunks.size();
    if(i<1)  return false;
    if(i>100)  return false;
  }

  return true;
}


Json::Value SpeakMarshaller::toJSON(const Speak& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["jsonrpc"]=Json::Value("2.0");
  json["method"]=Json::Value("TTS.Speak");

  json["id"]=Json::Value(e.getId());
  json["params"]=Json::Value(Json::objectValue);
  {
    unsigned int i=e.ttsChunks.size();
    Json::Value j=Json::Value(Json::arrayValue);
    j.resize(i);
    while(i--)
      j[i]=TTSChunkMarshaller::toJSON(e.ttsChunks[i]);

    json["params"]["ttsChunks"]=j;
  }
  return json;
}


bool SpeakMarshaller::fromJSON(const Json::Value& json,Speak& c)
{
  try
  {
    if(!json.isObject())  return false;
    if(!json.isMember("jsonrpc") || !json["jsonrpc"].isString() || json["jsonrpc"].asString().compare("2.0"))  return false;
    if(!json.isMember("method") || !json["method"].isString() || json["method"].asString().compare("TTS.Speak"))  return false;
    if(!json.isMember("id") || !json["id"].isInt()) return false;
    c.setId(json["id"].asInt());

    if(!json.isMember("params")) return false;

    Json::Value js=json["params"];
    if(!js.isObject())  return false;
    if(!js.isMember("ttsChunks") || !js["ttsChunks"].isArray())  return false;
    {
      unsigned int i=js["ttsChunks"].size();
      if(i<1)  return false;
      if(i>100)  return false;
      std::vector<TTSChunk> z(i);
      while(i--)
        if(!TTSChunkMarshaller::fromJSON(js["ttsChunks"][i],c.ttsChunks[i]))  return false;
      c.ttsChunks=z;
    }

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}
