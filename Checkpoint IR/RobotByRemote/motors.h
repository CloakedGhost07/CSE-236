/*
Author: Michael Martin
CSCE 236 Embedded Systems - UNL
Spring 2020 Semester

Library functions for robot project using Atmega 328p
*/
//#define MOTOR_SPEED_CMP 120
#include <Arduino.h>
#define MOTOR_SPEED_CMP 120

///////////////////////////////////////////////////////
// Robot motor Functions
///////////////////////////////////////////////////////
void setupMotors();
void forwardMotors();
void backwardMotors();
void stopMotors();
void leftMotors(int x);
void rightMotors(int x);

void dance();

void addSpeedRight(int x);
void addSpeedLeft(int x);
void setForwardSpeed(int x);
