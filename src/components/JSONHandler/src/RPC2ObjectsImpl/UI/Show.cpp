#include "../include/JSONHandler/RPC2Objects/UI/Show.h"
#include "../include/JSONHandler/RPC2Objects/UI/Marshaller.h"

/*
  interface	RPC2Communication::UI
  version	1.2
  generated at	Wed Nov  7 11:26:14 2012
  source stamp	Wed Nov  7 09:29:07 2012
  author	robok0der
*/

using namespace RPC2Communication;
using namespace AppLinkRPC;
using namespace RPC2Communication::UI;


Show& Show::operator =(const Show& c)
{
  if(mainField1)  delete mainField1;
  mainField1= c.mainField1 ? new std::string(c.mainField1[0]) : 0;
  if(mainField2)  delete mainField2;
  mainField2= c.mainField2 ? new std::string(c.mainField2[0]) : 0;
  if(alignment)  delete alignment;
  alignment= c.alignment ? new TextAlignment(c.alignment[0]) : 0;
  if(statusBar)  delete statusBar;
  statusBar= c.statusBar ? new std::string(c.statusBar[0]) : 0;
  if(mediaClock)  delete mediaClock;
  mediaClock= c.mediaClock ? new std::string(c.mediaClock[0]) : 0;
  if(mediaTrack)  delete mediaTrack;
  mediaTrack= c.mediaTrack ? new std::string(c.mediaTrack[0]) : 0;
  return *this;
}


Show::~Show(void)
{
  if(mainField1)  delete mainField1;
  if(mainField2)  delete mainField2;
  if(alignment)  delete alignment;
  if(statusBar)  delete statusBar;
  if(mediaClock)  delete mediaClock;
  if(mediaTrack)  delete mediaTrack;
}


Show::Show(void) : 
  RPC2Request(Marshaller::METHOD_SHOW),
  mainField1(0),
  mainField2(0),
  alignment(0),
  statusBar(0),
  mediaClock(0),
  mediaTrack(0)
{
}


Show::Show(const Show& c) : RPC2Request(Marshaller::METHOD_SHOW,c.getId())
{
  *this=c;
}


const std::string* Show::get_mainField1(void)
{
  return mainField1;
}

bool Show::set_mainField1(const std::string& mainField1_)
{
  if(mainField1)  delete mainField1;
  mainField1=new std::string(mainField1_);
  return true;
}

void Show::reset_mainField1(void)
{
  if(mainField1)  delete mainField1;
  mainField1=0;
}

const std::string* Show::get_mainField2(void)
{
  return mainField2;
}

bool Show::set_mainField2(const std::string& mainField2_)
{
  if(mainField2)  delete mainField2;
  mainField2=new std::string(mainField2_);
  return true;
}

void Show::reset_mainField2(void)
{
  if(mainField2)  delete mainField2;
  mainField2=0;
}

const TextAlignment* Show::get_alignment(void)
{
  return alignment;
}

bool Show::set_alignment(const TextAlignment& alignment_)
{
  if(alignment)  delete alignment;
  alignment=new TextAlignment(alignment_);
  return true;
}

void Show::reset_alignment(void)
{
  if(alignment)  delete alignment;
  alignment=0;
}

const std::string* Show::get_statusBar(void)
{
  return statusBar;
}

bool Show::set_statusBar(const std::string& statusBar_)
{
  if(statusBar)  delete statusBar;
  statusBar=new std::string(statusBar_);
  return true;
}

void Show::reset_statusBar(void)
{
  if(statusBar)  delete statusBar;
  statusBar=0;
}

const std::string* Show::get_mediaClock(void)
{
  return mediaClock;
}

bool Show::set_mediaClock(const std::string& mediaClock_)
{
  if(mediaClock)  delete mediaClock;
  mediaClock=new std::string(mediaClock_);
  return true;
}

void Show::reset_mediaClock(void)
{
  if(mediaClock)  delete mediaClock;
  mediaClock=0;
}

const std::string* Show::get_mediaTrack(void)
{
  return mediaTrack;
}

bool Show::set_mediaTrack(const std::string& mediaTrack_)
{
  if(mediaTrack)  delete mediaTrack;
  mediaTrack=new std::string(mediaTrack_);
  return true;
}

void Show::reset_mediaTrack(void)
{
  if(mediaTrack)  delete mediaTrack;
  mediaTrack=0;
}

bool Show::checkIntegrity(void)
{
  return ShowMarshaller::checkIntegrity(*this);
}
