/* From /usr/include/linux/joystick.h */

#include <stdint.h>

struct js_event {
  uint32_t time;	/* event timestamp in milliseconds */
  int16_t value;	/* value */
  uint8_t type;	/* event type */
  uint8_t number;	/* axis/button number */
};
