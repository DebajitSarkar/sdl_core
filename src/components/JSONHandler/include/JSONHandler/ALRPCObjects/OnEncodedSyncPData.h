#ifndef APPLINKRPC_ONENCODEDSYNCPDATA_INCLUDE
#define APPLINKRPC_ONENCODEDSYNCPDATA_INCLUDE

#include <vector>
#include <string>

#include "JSONHandler/ALRPCNotification.h"


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

///  Callback including encoded data of any SyncP packets that SYNC needs to send back to the mobile device.

  class OnEncodedSyncPData : public ALRPCNotification
  {
  public:
  
    OnEncodedSyncPData(const OnEncodedSyncPData& c);
    OnEncodedSyncPData(void);
    
    virtual ~OnEncodedSyncPData(void);
  
    OnEncodedSyncPData& operator =(const OnEncodedSyncPData&);
  
    bool checkIntegrity(void);

    const std::vector<std::string>* get_data(void) const;

    void reset_data(void);
    bool set_data(const std::vector<std::string>& data_);

  private:
  
    friend class OnEncodedSyncPDataMarshaller;


///  Contains base64 encoded string of SyncP packets.
      std::vector<std::string>* data;	//!<   [%s..%s] (10000)
  };

}

#endif
