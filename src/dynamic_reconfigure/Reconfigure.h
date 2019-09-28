#ifndef _ROS_SERVICE_Reconfigure_h
#define _ROS_SERVICE_Reconfigure_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "dynamic_reconfigure/Config.h"

namespace dynamic_reconfigure
{

#ifdef ESP8266
    static const char RECONFIGURE[] = "dynamic_reconfigure/Reconfigure";
#else
    static const char RECONFIGURE[] PROGMEM = "dynamic_reconfigure/Reconfigure";
#endif

  class ReconfigureRequest : public ros::Msg
  {
    public:
      typedef dynamic_reconfigure::Config _config_type;
      _config_type config;

    ReconfigureRequest():
      config()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->config.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->config.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return RECONFIGURE; };
    #ifdef ESP8266
        const char * getMD5() { return  ("ac41a77620a4a0348b7001641796a8a1");};
    #else
        const char * getMD5() { return  PSTR("ac41a77620a4a0348b7001641796a8a1");};
    #endif

  };

  class ReconfigureResponse : public ros::Msg
  {
    public:
      typedef dynamic_reconfigure::Config _config_type;
      _config_type config;

    ReconfigureResponse():
      config()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->config.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->config.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return RECONFIGURE; };
    #ifdef ESP8266
        const char * getMD5() { return  ("ac41a77620a4a0348b7001641796a8a1");};
    #else
        const char * getMD5() { return  PSTR("ac41a77620a4a0348b7001641796a8a1");};
    #endif

  };

  class Reconfigure {
    public:
    typedef ReconfigureRequest Request;
    typedef ReconfigureResponse Response;
  };

}
#endif
