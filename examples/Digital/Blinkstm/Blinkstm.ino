/*
 Blink: Turns on the built-in LED on for one second, then off for one second, repeatedly.
 Arduino 1.6.0rc1
   Sketch uses 11,900 bytes (11%) of program storage space. Maximum is 108,000 bytes.
   Global variables use 2,592 bytes of dynamic memory.
 Ported to Maple from the Arduino example 27 May 2011 By Marti Bolivar
*/

void setup() {
    // Set up the built-in LED pin as an output:
    pinMode(PA5, OUTPUT);
}

void loop() {
 digitalWrite(PA5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(380);              // wait for a second
  digitalWrite(PA5, LOW);    // turn the LED off by making the voltage LOW
  delay(768);              // wait for a second
}

