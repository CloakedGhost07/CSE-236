/*
Author: Michael Martin
CSCE 236 Embedded Systems - UNL
Spring 2020 Semester

Library functions for robot project using Atmega 328p
*/
#define MOTOR_SPEED_CMP 50
///////////////////////////////////////////////////////
// Robot motor Functions
///////////////////////////////////////////////////////
void setupMotors();
void forwardMotors();
void backwardMotors();
void stopMotors();
void leftMotors(int x);
void rightMotors(int x);
