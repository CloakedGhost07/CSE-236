/*
Author: Michael Martin
CSCE 236 Embedded Systems - UNL
Spring 2020 Semester

Library functions for robot project using Atmega 328p
*/
#include <Arduino.h>

#define CLK_SPEED 16000000

#define TRIGGER_PIN 1
#define ECHO_PIN 0
#define RED_LED 7
#define BLUE_LED 6
#define GREEN_LED 5
#define TRIGGER_DISTANCE 12
#define MOTOR_SPEED_CMP 50

typedef enum{FORWARD,LEFT,RIGHT}facing;

//sets the prescaler of timer 2 to 1024 and PWM to phase correct
//servo motor on pinD3
void setupServo();

//functions to turn the servo to the correct angles
void turnServoRight();
void turnServoFront();
void turnServoLeft();

//Functions that set up the ultrasonic sensor and do sensing
void setupUltraSonic();
uint16_t runUltraSonic();

//debug function to make sure delay() works correctly
void timercheck();

//main running function, look in all directions and update LED
void cycleServo();

//sensing function, store in global variable
void detect(facing);
//Serial printing the distances
void printDirectionalDistances();
//turn on/off corresponding LED's functionality
void updateLEDs();
void GreenON();
void GreenOFF();


///////////////////////////////////////////////////////
// Robot motor Functions
///////////////////////////////////////////////////////
void setupMotors();
void forwardMotors();
void backwardMotors();
void stopMotors();
void leftMotors(int x);
void rightMotors(int x);
