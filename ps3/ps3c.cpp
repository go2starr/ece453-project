#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include </linux/joystick.h>

int main () {
  int fd = open("/dev/input/js0", O_RDONLY);
  
  if (fd == -1)
    return -1;

  while (1) {
    struct js_event e;
    read(fd, &e, sizeof(struct js_event));
    printf("%u:: Value=%d  Type=%d  Number=%d\n",
           e.time, e.value, e.type, e.number);
  }
}


/**

   AxisAssignment
   0Left thumb X
   1Left thumb Y
   2Right thumb X
   3Right thumb Y
   4-7nothing
   8Dpad Up
   9Dpad Right
   10Dpad Down
   11Dpad Left
   12L2
   13R2
   14L1
   15R1
   16Triangle
   17Circle
   18Cross
   19Square
   20-27nothing
   ButtonAssignment
   0Select
   1L3
   2R3
   3Start
   4Dpad Up
   5Dpad Right
   6Dpad Down
   7Dpad Left
   8L2
   9R2
   10L1
   11R1
   12Triangle
   13Circle
   14Cross
   15Square
   16PS Button
   17-18nothing
*/
