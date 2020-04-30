/*
Author: Michael Martin
CSCE 236 Embedded Systems - UNL
Spring 2020 Semester

Driver for robot project using Atmega 328p
*/
#include "robotlib.h"
#include "motors.h"
#include "ObstacleCode.h"
void setup() {
  // setupLED();
  // setupUltraSonic();
  // setupServo();
  // setupMotors();
  // Serial.begin(9600);
  // RedON();
  // detect(RIGHT);
  // delay(100);
  // detect(RIGHT);
  // RedOFF();
  // stopMotors();
  setupForOAM();
  Serial.begin(9600);
}
void doTheWallThing();
void secondTryWall();


void loop() {
  //doTheWallThing();
  //turnServoFront();
  AvoidanceMode();
  //cycleServo();
  //printDirectionalDistances();
}



void secondTryWall(){
  uint16_t x = getDistance(RIGHT);
  switch(x){
    case 8:
      addSpeedRight(20);
    case 9:
      addSpeedRight(20);
      break;
    case 12:
    case 13:
    case 14:
      addSpeedLeft(10);
      delay(100);
    case 11:
    case 10:
      setForwardSpeed(120);
      break;
    case 17:
    case 15:
    case 16:
      addSpeedLeft(20);
      break;
    default:
      if(x > 17){
        addSpeedLeft(30);
      }
      else if(x < 8){
        addSpeedRight(30);
      }
      delay(200);
      setForwardSpeed(50);

  }
  delay(100);
  setForwardSpeed(120);

}
void doTheWallThing(){
 // detect(RIGHT);
  LEDoff();

  int x = detectWall(RIGHT);
  Serial.println(x);
  switch(x){
    case -1:
      addSpeedRight(30);
      GreenON();
      delay(150);
      //addSpeedLeft(10);
      break;
    case -2:
      addSpeedRight(30);
      GreenON();
      RedON();
      delay(150);
      break;
    case 2:
      addSpeedLeft(20);
      BlueON();
      RedON();
      delay(75);
      //addSpeedRight(5);
      break;
    case 1:
      addSpeedLeft(20);
      BlueON();
      delay(150);
      //addSpeedRight(2);
      break;
    default:
      setForwardSpeed(120);
  }
  delay(150);
  setForwardSpeed(120);
}
