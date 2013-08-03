/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 */

// Pin 13 has an LED connected
int led = 13;

void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
