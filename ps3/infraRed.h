/*
 *Author Liu Diansheng
 *<chnlds@gmail.com>
 */

/*
 *This header file constains struct for infraRed transmitting information package and joystick event struct.
 */

#include <stdint.h>

struct msg{
  uint8_t trim    : 7; //calibration
  uint8_t 	  : 0; //Force alignment to next boundary
  uint8_t throttle: 7;
  uint8_t channel : 1;
  uint8_t pitch   : 7; //forward and backward
  uint8_t 	  : 0; //Force alignment to next boundary
  uint8_t yaw     : 7; //turning
  uint8_t 	  : 0; //Force alignment to next boundary
};


struct js_event {
        uint32_t time;     /* event timestamp in milliseconds */
        int16_t value;    /* value */
        uint8_t type;      /* event type */
        uint8_t number;    /* axis/button number */
};
