/*
 *Author Liu Diansheng
 *<chnlds@gmail.com>
 */

/*
 *This header file constains struct for infraRed transmitting information package and joystick event struct.
 */

#include <stdint.h>

struct msg{
  unsigned short trim    : 7; //calibration
  unsigned short nothing1: 1; //Force alignment to next boundary
  unsigned short throttle: 7;
  unsigned short channel : 1;
  unsigned short pitch   : 7; //forward and backward
  unsigned short nothing2: 1; //force alignment
  unsigned short yaw     : 7; //turning
  unsigned short nothing3: 1;
};


struct js_event {
        uint32_t time;     /* event timestamp in milliseconds */
        int16_t value;    /* value */
        uint8_t type;      /* event type */
        uint8_t number;    /* axis/button number */
};
