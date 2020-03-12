/*
Author: Michael Martin
CSCE 236 Embedded Systems - UNL
Spring 2020 Semester

Driver for robot project using Atmega 328p
*/
#include "robotlib.h"

void setup() {
  setupServo();
  setupUltraSonic();
}

void loop() {
  //timercheck();
  cycleServo();
  //runUltraSonic();
  //detect(FORWARD);
  //detect(RIGHT);
  //detect(LEFT);
 printDirectionalDistances();
}
