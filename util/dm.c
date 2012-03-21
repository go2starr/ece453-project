#include <stdio.h>

#define GPIO (*((volatile long*) 0xD3000004))

int main()
{
  int x = GPIO;
}
