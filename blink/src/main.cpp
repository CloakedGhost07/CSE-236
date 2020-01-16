/*
Author: Michael Martin
This is a simple blink program for the arduino board
*/
#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // long on
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  // short off
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
  // short on
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  // short off
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
  // short on
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  // long off
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  // long on
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  // long off
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}