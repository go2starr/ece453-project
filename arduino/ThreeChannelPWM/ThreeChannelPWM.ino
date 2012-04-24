

/* Setup - Initialize PWM registers */
void setup() {
  pinMode(13, OUTPUT);
}

/* Loop - update PWM counters */
void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
