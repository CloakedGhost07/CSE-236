/*
Author: Michael Martin
CSCE 236 Embedded Systems - UNL
Spring 2020 Semester

Driver for robot obstacle avoidance project using Atmega 328p
Distances were changed to pure values returned by ultrasonic sensor
to greater increase the accuracy of measurement.
*/
#include "robotlib.h"
#include "motors.h"
#include <math.h>

void setupForOAM(){
  setupLED();
  setupMotors();
  setForwardSpeed(80);
}

volatile int f = 0; //front distance
volatile int r = 0; // right distance
volatile int rp = 0; //right previous distance
bool turned = false;
bool first = true;
void AvoidanceMode(){
  stopMotors();
  rp = r; //save right previous distance
  LEDoff();
  turnServoFront();
  delay(50);
  detect(FORWARD);
  f = getDistance(FORWARD);
  turnServoRight();
  detect(RIGHT);
  r = getDistance(RIGHT);
  Serial.println(r);
  if(first){
    first = false;
    return;
  }

  //90 degree left turn when we reach an obstacle
  if(f <= 15*38){
    RedON();
    GreenON();
    leftMotors(100);
    delay(250);
    turned = true;
    return;
  }
  //fwd clear and right clear, 90 degrees right turn
  if(r >= 20*38 && f > 20*38 && !turned){
    RedON();
    BlueON();
    forwardMotors();
    delay(800);
    stopMotors();
    rightMotors(90);
    forwardMotors();
    delay(1000);
    turned = true;
  }
  //turn left if too close to wall or closer than last scanned
  else if(((r < rp - 40) || (r < 220)) && !turned){
    BlueON();
    leftMotors(20);
    forwardMotors();
    delay(300);
    LEDoff();
    // turned = true;
  }
  //turn right if too far from wall or farther than last scanned.
  else if (((r > rp + 40) || (r > 500)) && !turned){
    RedON();
    rightMotors(20);
    forwardMotors();
    delay(300);
    LEDoff();
    // turned = true;
  }

  //other conditions not met, go forward and rescan
  else{
    GreenON();
    forwardMotors();
    delay(1000);
    turned = false;
  }

}
