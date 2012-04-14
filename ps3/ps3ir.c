#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/joystick.h>

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

enum Buttons {
  YAW = 2,
  PITCH = 3,
  THROTTLE = 13,
};


#define BUFFLEN 32
#define SERVER "10.42.43.2"
#define SERVPORT 2000


char packet[4];
int pitch, yaw, throttle, cal;

int scale(int val, int srange, int erange)
{
  return val * erange / srange;
}


int main () {
  int i, j;
  int resct = 0;
  int fd = open("/dev/input/js0", O_RDONLY);
  
  if (fd == -1)
    return -1;

  int sd, rc, length = sizeof(int);
  struct sockaddr_in serveraddr;
  char server[255];
  char temp;
  struct hostent *hostp;


  /* /\* Get a socket *\/ */
  /* sd = socket(AF_INET, SOCK_STREAM, 0); */

  /* /\* Set server *\/ */
  /* strcpy(server, SERVER); */

  /* memset(&serveraddr, 0x00, sizeof(struct sockaddr_in)); */
  /* serveraddr.sin_family = AF_INET; */
  /* serveraddr.sin_port = htons(SERVPORT); */

  /* serveraddr.sin_addr.s_addr = inet_addr(server); */

  /* /\* Get host *\/ */
  /* hostp = gethostbyname(server); */

  /* memcpy(& */

  
  pitch = yaw = throttle = cal = 0;
  while (1) {
    struct js_event e;
    read(fd, &e, sizeof(struct js_event));

    if (e.type == 2) {
      switch (e.number) {
      case YAW:
        yaw = scale(e.value, 1<<16, 127) + 127/2;
        break;
      case PITCH:
        pitch = scale(e.value, 1<<16, 127) + 127/2;
        break;
      case THROTTLE:
        throttle = scale(e.value, 1<<16, 127) + 127/2;
        break;
      }
    }
    
    
    packet[0] = (char)yaw + 63/4;
    packet[1] = (char)pitch;
    packet[2] = (char)throttle & ~(1 << 8);
    packet[3] = 63;

    /*
    printf("Y: %d\tP: %d\t T:%d\t:: %x %x %x %x\n", yaw, pitch, throttle, packet[0], packet[1], packet[2], packet[3]);
    */

    if (resct++ % 5 == 0) {
      printf("^");
      for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
          printf("%d", (packet[i] >> (8 - j)) & 1);
        }
      }
      printf("\n");    
      fflush(stdout);
    }
  }
}
