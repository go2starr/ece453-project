#include <SoftwareSerial.h>

#define IRpin 4

// (RX, TX)
//SoftwareSerial mySerial(2, 3);

void setup(void) {
  Serial.begin(9600);
  //Serial.println("Ready to decode IR!");

  //mySerial.begin(9600);

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
  byte c;

  byte ok = 0;
  if (Serial.available()) {
    c = Serial.read();
    if (c == '^') {
      for (int i = 0; i < 32; i++) {
        while (!Serial.available());
        c = Serial.read();
        if (c == '0')
          sig[i] = 0;
        else if (c == '1')
          sig[i] = 1;
      }  
      ok = 1;
    }
  }
  if (ok)
    Serial.println("OK!");
  else
    Serial.println("MISS!");

  while (Serial.available())
    Serial.read();


  for (int k = 0; k < 1; k++) {

    // Leading start bit
    ir_write(2000);
    // Hold
    delayMicroseconds(2000);


    for (int i = 0; i < 32; i++) {
      ir_write(260);
      delayMicroseconds(sig[i]*350 + 350);
    }

    delay(90);
  }
}


