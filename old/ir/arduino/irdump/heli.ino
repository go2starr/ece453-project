/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

int val = 0;    // val read from ADC

void setup() {  
 Serial.begin(9600);  
}


// State machine
int state = 0;   // 0 off, 1 on
int count;

void loop() {

  // Update input
  val = !(PIND & (1 << 2));
  
  if (state) {
    // On
    if (!val) {
      // No change
      count++;
    } else {
     state = 0;
      
     if (count > 100) {
       Serial.print("On: "); 
       Serial.println(count);
     }  
     count = 0;
    }
  } else {
    // Off
    if (val) {
      state = 1;
     
      if (count > 100) {
        Serial.print("Off: ");
        Serial.println(count);
      }   
      count = 0;
    } else {
     // No change
     count++;
    }
  }
}
