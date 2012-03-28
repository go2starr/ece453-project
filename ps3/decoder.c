#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "infraRed.h"
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef uint32_t __u32;
unsigned int *pmem;

/*set up the pointer of the memory*/
#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)
#define BASE_ADDRESS 0xD3000000
uint32_t* setP()
{
	int fd;
	unsigned int offset = 0, data = 0;
	unsigned int *pbase;
	
	printf("Memory Access Application\n\r");

	// open the driver
	fd = open("/dev/mem", O_RDWR|O_SYNC);
	if(!fd) {
		printf("Unable to open /dev/mem.  Ensure it exists (major=1, minor=1)\n");
		return -1;
	}	

	// get the offset to read from
	printf("Enter the hex offset to read from: ");
	scanf("%X", &offset);

	// calculate address and do read
	pbase = (unsigned int *)mmap(0, MAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0xD3000000 & ~MAP_MASK);
	pmem = pbase + ((offset & MAP_MASK)>>2);
	data = *pmem;
        
        return *pmem;
	return 0;
}


struct msg decode (struct js_event e, struct msg * heli){
  struct msg message;
  switch(e.type){
  case 1:
    switch(e.number){
      case 7: //dpad left -> fine calibration left
	(*heli).trim++;
      case 5://dpad right -> fine calibration right
	(*heli).trim++;
      case 15://square -> rough calibration left
	(*heli).trim+=10;
      case 13://circle -> rough calibration right
	(*heli).trim-=10;
      case 0://select -> channel A
	(*heli).channel=0;
      case 3://start -> channel B
	(*heli).channel=1;
    }break;
   case 2:
    switch(e.number){
      case 2: //right thumb x -> yaw
        message.yaw=-3*e.value/2048+47+message.trim/4;
      case 3://right thumb y -> pitch
	message.pitch=e.value/512+64;
      case 12://L2 -> throttle
	message.throttle=e.value/512+64;
//	MESSAGE MAY BE SENT WHILE BUTTON IS IN AXIS TYPE. ADD THAT IF NEEDED
    };break;
  default:;
  }
  message.trim=(*heli).trim;
  message.channel=(*heli).channel;
//bound the value
  if (message.trim>=63) message.trim=63;
  if (message.trim<=0) message.trim=0;
  printf("%d %d %d %d\n", message.yaw, message.pitch, message.throttle, message.trim);
  return message;
}

/* write an IR pulse for @length microseconds */
void ir_write(int length)
{
  int cycles = length / 14;
  int i=0;
  for (i = 0; i < cycles; i++) {
    *pmem=1;usleep(7);
    *pmem=0;usleep(7);  
  }
}


void sendbit (unsigned short bit){
  int i=0;
  ir_write(260);//send pulse for 260us
  usleep(bit*350+350);//delay at low
}

void sendmsg (struct msg message){
  ir_write(1000);
  usleep(1000);//delay for 1000us to avoid confliction
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
  
//  if (fd == -1)    return -1;
  while (1) {
    struct js_event e;
    struct msg heli;// use a current heli state to remember some semi-static value like calibration and channel
    read(fd, &e, sizeof(struct js_event));
    //e.type=1;e.number=3;e.value=50;
    struct msg message=decode(e, &heli);
    message.trim=0x3F;//temporary message while js is not availiable for testing.
    message.throttle=126; message.channel=0; message.pitch=1; message.yaw=0x3F;
    sendmsg(message);
    printf("%u:: Value=%d  Type=%d  Number=%d\n",
           e.time, e.value, e.type, e.number);
  }
    return 0;
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
