/*
Author: Michael Martin
CSCE 236 Embedded Systems - UNL
Spring 2020 Semester

Driver for robot project using Atmega 328p
*/
#include "robotlib.h"

void setup() {
  //setupServo();
  //setupUltraSonic();
  setupMotors();
  forwardMotors();
   delay(1000);
   backwardMotors();
  delay(1000);
  stopMotors();
  delay(1500);
  leftMotors(45);
   delay(2000);
  rightMotors(45);
  delay(2000);
  leftMotors(90);
   delay(2000);
  rightMotors(90);
  stopMotors();
}

void loop() {
  //timercheck();
//  cycleServo();
  //runUltraSonic();
  //detect(FORWARD);
  //detect(RIGHT);
  //detect(LEFT);
 //printDirectionalDistances();
}
