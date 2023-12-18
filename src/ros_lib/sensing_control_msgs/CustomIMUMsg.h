#ifndef _ROS_sensing_control_msgs_CustomIMUMsg_h
#define _ROS_sensing_control_msgs_CustomIMUMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensing_control_msgs
{

  class CustomIMUMsg : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      float acceleration[3];
      float gyroscope[3];
      float magnetometer[3];

    CustomIMUMsg():
      header(),
      acceleration(),
      gyroscope(),
      magnetometer()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_accelerationi;
      u_accelerationi.real = this->acceleration[i];
      *(outbuffer + offset + 0) = (u_accelerationi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accelerationi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accelerationi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accelerationi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acceleration[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_gyroscopei;
      u_gyroscopei.real = this->gyroscope[i];
      *(outbuffer + offset + 0) = (u_gyroscopei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyroscopei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gyroscopei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gyroscopei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gyroscope[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_magnetometeri;
      u_magnetometeri.real = this->magnetometer[i];
      *(outbuffer + offset + 0) = (u_magnetometeri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magnetometeri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magnetometeri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magnetometeri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->magnetometer[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_accelerationi;
      u_accelerationi.base = 0;
      u_accelerationi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accelerationi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accelerationi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accelerationi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acceleration[i] = u_accelerationi.real;
      offset += sizeof(this->acceleration[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_gyroscopei;
      u_gyroscopei.base = 0;
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gyroscope[i] = u_gyroscopei.real;
      offset += sizeof(this->gyroscope[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_magnetometeri;
      u_magnetometeri.base = 0;
      u_magnetometeri.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magnetometeri.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magnetometeri.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magnetometeri.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->magnetometer[i] = u_magnetometeri.real;
      offset += sizeof(this->magnetometer[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "sensing_control_msgs/CustomIMUMsg"; };
    virtual const char * getMD5() override { return "e5caa9162e195ad161e6e93fe1f83380"; };

  };

}
#endif
