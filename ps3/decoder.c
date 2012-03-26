#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "infraRed.h"

typedef uint32_t __u32;

struct msg decode (js_event e){
  struct msg message;
  switch(e.type){
  case 1:
    switch(e.number){
      case 7://dpad left -> fine calibration left
	message.trim++;
      case 5://dpad right -> fine calibration right
	message.trim--;
      case 15://square -> rough calibration left
	message.trim+=10;
      case 13://circle -> rough calibration right
	message.trim-=10;
      case 0://select -> channel A
	message.channel=0;
      case 3://select -> channel B
	message.channel=1;
    }break;
   case 2:
    switch(e.number){
      case 2://right thumb x -> yaw
        message.yaw=abs(e.value);
      case 3://right thumb y -> pitch
	message.pitch=abs(e.value);
      case 12://L2 -> throttle
	message.throttle=abs(e.value);
    };break;
  default:;
  }
  printf("%d %d %d %d\n", message.yaw, message.pitch, message.throttle, message.trim);
  return message;
}

void sendbit (unsigned short bit){
  printf("_");//send high for 260us
  if (bit) printf("~");//delay for 350us
  else printf("~~");//delay for 700us
}

void sendmsg (struct msg message){
  printf("\n_______");//delay for 1000us to avoid confliction
  int i=0;
  for (i=0;i<32;i++){
    __u32 message=*((__u32*)(void*)(&message));//force cast message from struct to unsigned int
    unsigned short bit= (unsigned short)(message & (__u32)1);
    sendbit(bit);
    message = message >> 1;
  }
}

int main () {
  int fd = open("/dev/input/js0", O_RDONLY);
  
  //if (fd == -1)    return -1;
  while (1) {
    struct js_event e;
    read(fd, &e, sizeof(struct js_event));
    e.type=1;e.number=3;e.value=50;
    struct msg message=decode(e);
    sendmsg(message);
    printf("%u:: Value=%d  Type=%d  Number=%d\n",
           e.time, e.value, e.type, e.number);
    return 0;
  }
}





/**

   AxisAssignment type 2
   0 Left thumb X
   1 Left thumb Y
   2 Right thumb X
   3 Right thumb Y
   4-7 nothing
   8 Dpad Up
   9 Dpad Right
   10 Dpad Down
   11 Dpad Left
   12 L2
   13 R2
   14 L1
   15 R1
   16 Triangle
   17 Circle
   18 Cross
   19 Square
   20-27 nothing

   ButtonAssignment type 1
   0 Select
   1 L3
   2 R3
   3 Start
   4 Dpad Up
   5 Dpad Right
   6 Dpad Down
   7 Dpad Left
   8 L2
   9 R2
   10 L1
   11 R1
   12 Triangle
   13 Circle
   14 Cross
   15 Square
   16 PS Button
   17-18 nothing
*/
