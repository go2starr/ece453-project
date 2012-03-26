#define IRpin 2

void setup(void) {
  Serial.begin(9600);
  Serial.println("Ready to decode IR!");
  
  pinMode(IRpin, OUTPUT);
}

/* write an IR pulse for @length microseconds */
void ir_write(int length)
{
  int cycles = length / 14;
  for (int i = 0; i < cycles; i++) {
    PIND = 1 << IRpin;
    delayMicroseconds(7);
    PIND = 0;
    delayMicroseconds(7);  
  }
}

int sig[] = {
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,1,1,1,1,1,1,1,
  0,0,0,0,0,0,0,0  
};

int sigH[] = {
  0, 0, 0x7F, 0
};
  

void loop(void) {
 // PIND = 1 << IRpin;

 // Leading start bit
 ir_write(2000);
 // Hold
 delayMicroseconds(2000);

 for (int i = 0; i < 4; i++) {
   /*
   ir_write(260);
   delayMicroseconds(sig[i]*350 + 350);
   */
   for (int j = 0; j < 8; j++) {
      ir_write(260);
      delayMicroseconds(((sigH[i] >> (8-j))&1)*350 + 350);
   }
 }
 
 sigH[2] = 0x7F;
 
 delay(90);
}
