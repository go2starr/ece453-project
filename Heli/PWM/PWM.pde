#include <avr/io.h>

void setup() {
// this code sets up counter0 for an 8kHz Fast PWM wave @ 16Mhz Cloc
    double dutyCycle=100;
    DDRD |= (1 << DDD6);
    // PD6 is now an output
    OCR0A = 2.55*dutyCycle;
    // set PWM for 50% duty cycle
    TCCR0A |= (1 << COM0A1);
    // set none-inverting mode
    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    // set fast PWM Mode
    TCCR0B |= (1 << CS01);
    // set prescaler to 8 and starts PWM
}

void loop() {
  // put your main code here, to run repeatedly: 
  }
