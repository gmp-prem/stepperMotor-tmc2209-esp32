#ifndef _ROS_SERVICE_WriteMRegister_h
#define _ROS_SERVICE_WriteMRegister_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace motoman_msgs
{

static const char WRITEMREGISTER[] = "motoman_msgs/WriteMRegister";

  class WriteMRegisterRequest : public ros::Msg
  {
    public:
      typedef uint32_t _address_type;
      _address_type address;
      typedef uint16_t _value_type;
      _value_type value;

    WriteMRegisterRequest():
      address(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->address >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->address >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->address >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->address >> (8 * 3)) & 0xFF;
      offset += sizeof(this->address);
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value >> (8 * 1)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->address =  ((uint32_t) (*(inbuffer + offset)));
      this->address |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->address |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->address |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->address);
      this->value =  ((uint16_t) (*(inbuffer + offset)));
      this->value |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->value);
     return offset;
    }

    virtual const char * getType() override { return WRITEMREGISTER; };
    virtual const char * getMD5() override { return "5343d995d764283727c41eb509727e5f"; };

  };

  class WriteMRegisterResponse : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;
      typedef bool _success_type;
      _success_type success;

    WriteMRegisterResponse():
      message(""),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return WRITEMREGISTER; };
    virtual const char * getMD5() override { return "9bf829f07d795d3f9e541a07897da2c4"; };

  };

  class WriteMRegister {
    public:
    typedef WriteMRegisterRequest Request;
    typedef WriteMRegisterResponse Response;
  };

}
#endif
