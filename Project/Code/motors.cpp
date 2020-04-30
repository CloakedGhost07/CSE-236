
#include "motors.h"
///////////////////////////////////////////////////////
// Robot motor Functions
///////////////////////////////////////////////////////

//using the H-brige as a gateway connector, phase correct mode
// on timer 2, will be supplying PWM to the enable pins to
// define speed of the motors.
void setupMotors(){
  DDRD |= (1<<3); // pin 3
  DDRB |= (1<<3); // pin 11
  DDRC |= (1<<1) | (1<<2) | (1<<3) | (1<<4); //analog pins 1-4 outputs
  TCCR2A = (1<<COM2A1) | (1<<COM2B1) | (1<<WGM20);// | (1<<WGM21);
  //TCCR2B = (1<<CS22) ;//| (1 <<WGM22);
  OCR2A = 1;
  OCR2B = 1;
}

int speedleft= 90;
int speedright = 90;

void addSpeedRight(int x){
  speedright = 90 + x;
  speedleft = 90;
  forwardMotors();
}
void addSpeedLeft(int x){
  speedright = 90;
  speedleft = 90 + x;
  forwardMotors();
}
void setForwardSpeed(int x){
  speedright = x+1;
  speedleft = x;
  //forwardMotors();
}

void forwardMotors(){

  PORTC |= (1<<1) | (1<<3);
  PORTC &= ~((1<<2) | (1<<4));
  delay(15);
  OCR2A = speedleft;
  OCR2B = speedright;

}

void backwardMotors(){

  PORTC &= ~((1<<1) | (1<<3));
  PORTC |= ((1<<2) | (1<<4));

  OCR2A = MOTOR_SPEED_CMP;
  OCR2B = MOTOR_SPEED_CMP;
}

void stopMotors(){

  OCR2A = 1;
  OCR2B = 1;

  PORTC &= ~((1<<2) | (1<<4));
  PORTC &= ~((1<<1) | (1<<3));
}

void leftMotors(int x){
  PORTC &= ~((1<<2) | (1<<4));
  PORTC &= ~((1<<1) | (1<<3));
  PORTC |= (1<<2) | (1<<3);
  OCR2A = MOTOR_SPEED_CMP;
  OCR2B = MOTOR_SPEED_CMP;
  delay(x * 3);
  PORTC &= ~((1<<2) | (1<<4));
  PORTC &= ~((1<<1) | (1<<3));
}

void rightMotors(int x){
  PORTC &= ~((1<<2) | (1<<4));
  PORTC &= ~((1<<1) | (1<<3));
  PORTC |= (1<<1) | (1<<4);
  OCR2A = MOTOR_SPEED_CMP;
  OCR2B = MOTOR_SPEED_CMP;
  delay(x * 3);
  PORTC &= ~((1<<2) | (1<<4));
  PORTC &= ~((1<<1) | (1<<3));
}

void dance(){
  setupMotors();
  forwardMotors();
  delay(1000);
  stopMotors();
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
