/*
Author: Michael Martin
CSCE 236 Embedded Systems - UNL
Spring 2020 Semester

Library functions for robot project using Atmega 328p
*/
#include <Arduino.h>
#include "robotlib.h"

void setupServo(){
  TCCR1B &= ~7;
  TCCR1B |= (1<<CS12) | (0<<CS11) | (1<<CS10); //prescaler for timer 2 //1024
  DDRB |= (1<<2); //pin out
  TCCR1B |= (1<<WGM12);
  TCCR1A |= (1<<WGM10);//wave form generation mode
  TCCR1A |= (1<<COM1A1) | (1<<COM1B1); //turn on compare mode
  //OCR1B = 500; //top compare register
  delay(100);
}

void turnServoRight45(){
  setupServo();//set prescaler and appropriate wgm
  OCR1B = 12; //right facing 45 degrees
  delay(250);
}

void turnServoRight(){
  setupServo();//set prescaler and appropriate wgm
  OCR1B = 5; //right facing
  delay(250);
}

void turnServoFront(){
  setupServo();//set prescaler and appropriate wgm
  OCR1B = 20; //forward facing
  delay(250);
}

void turnServoLeft(){
  setupServo();//set prescaler and appropriate wgm
  OCR1B = 35; //left facing
  delay(250);
}

void setupLED(){
  DDRD |= (1 << GREEN_LED) | (1<<BLUE_LED) | (1<<RED_LED);
}

void setupUltraSonic(){
  // Serial.begin(9600);
  // delay(50);
  // Serial.println("starting setup of ultrasonic");

  DDRB |= (1<<TRIGGER_PIN);
  DDRB &= ~(1<<ECHO_PIN);

  TCCR1A &= (0x00);
  TCCR1B &= ~(0xdf); // clear all bit values that matter
  TCCR1B |= (1<<1) | (1<<0); // set lower to bits prescaler 64
  TCCR1C &= 0x00;
  //TIMSK1 |= (1<<5)|(0<<0); //adding this line of code screws up the delay and makes things loopy
  TIFR1 |= (0x01);

  // delay(50);
  // Serial.println("setup complete");
  // delay(50);

}

int flag; //global flag variable

uint16_t runUltraSonic(){
  setupUltraSonic(); //set prescaler and appropriate wgm
  uint16_t a = 0, distance;
  flag = 0;

  PORTB &= ~(1<<TRIGGER_PIN);
  delayMicroseconds(1);
  PORTB |=(1<<TRIGGER_PIN);
  delayMicroseconds(10);
  PORTB &= ~(1<<TRIGGER_PIN);

  while(1){
    if(PINB & (1<<ECHO_PIN)){
      TCNT1 = 0;
      break;
    }
  }

  while(TCNT1 < 14000){ // about 60 ms based on prescaler
    if(TIFR1 & (1<<5)){ //interrupt flag raised due to falling edge
      a = ICR1;
      flag = 1; //flag var to make sure data is valid
      break;
    }
  }

  if(flag == 0){
    // Serial.println("No Echo detected.");
  }
  else{
  distance = a;// / 38; //calculated divisor based upon measured test cases
  //Serial.print(distance);
  //Serial.println(" inches");
  }
  delay(60);
  return distance;
}

void timercheck(){ //debug function
  unsigned long x, y;
  x = micros();
  delayMicroseconds(100);
  y = micros();
  Serial.println(y-x);
}

void cycleServo(){ //move the servo to each position and get measurements
  turnServoRight();
  delay(250);
  GreenON();
  detect(RIGHT);
  GreenOFF();
  turnServoFront();
  delay(250);
  GreenON();
  detect(FORWARD);
  GreenOFF();
  turnServoLeft();
  delay(250);
  GreenON();
  detect(LEFT);
  GreenOFF();
  turnServoFront();
  delay(250);
  GreenON();
  detect(FORWARD);
  GreenOFF();
  // printDirectionalDistances();
}

//global distance variables
uint16_t left_distance = 13, right_distance = 13, front_distance = 13;
uint16_t right45_distance = 0;
uint16_t left_distance_prev = left_distance;
uint16_t right_distance_prev = right_distance;
uint16_t front_distance_prev = front_distance;

void detect(facing d){
  int i, samples = 8; //loop variables
  //get the pointer to store info in the correct place
  uint16_t* dir = (d == FORWARD? &front_distance:(d == RIGHT? &right_distance: &left_distance));
  if(d == RIGHT45){dir = &right45_distance;}
  unsigned long x = 0;
  for(i=0;i<samples;i++){
    x = runUltraSonic(); //get a sum of data
  }
  left_distance_prev = left_distance;
  right_distance_prev = right_distance;
  front_distance_prev = front_distance;
  *dir = x  ;/// samples; //get average of data
  //updateLEDs(); //after updating global variables, update LED's
}

uint16_t getDistance(facing d){
  uint16_t* dir = (d == FORWARD? &front_distance:(d == RIGHT? &right_distance: &left_distance));
  if(d == RIGHT45){dir = &right45_distance;}
  return *dir;
}

int detectWall(facing d){
  uint16_t* dir = (d == FORWARD? &front_distance:(d == RIGHT? &right_distance: &left_distance));
  uint16_t* dir_prev = (d == FORWARD? &front_distance_prev:(d == RIGHT? &right_distance_prev: &front_distance_prev));

  //while((*dir) <= (*dir_prev) + 0 && (*dir) >= (*dir_prev) - 0  && (*dir) < 13 && (*dir) > 6){
    detect(d);
  //}
  if((*dir) <=  6){
    return -2;
  }
  else if ((*dir) >= TRIGGER_DISTANCE){
    return 2;
  }
  else if((*dir) < (*dir_prev)){
    return -1;
  }
  else if((*dir) > (*dir_prev) ){
    return 1;
  }
  return 0;

}

//print out to Serial, distances after scanning all three directions
void printDirectionalDistances(){
  Serial.print(left_distance);Serial.println(" inches on the left side.");
  Serial.print(front_distance);Serial.println(" inches on the front side.");
  Serial.print(right_distance);Serial.println(" inches on the right side.");
}

void GreenON(){
  PORTD |= (1<<GREEN_LED);
}
void GreenOFF(){
  PORTD &= ~(1<<GREEN_LED);
}
void BlueON(){
  PORTD |= (1<<BLUE_LED);
}
void BlueOFF(){
  PORTD &= ~(1<<BLUE_LED);
}
void RedON(){
  PORTD |= (1<<RED_LED);
}
void RedOFF(){
  PORTD &= ~(1<<RED_LED);
}
void LEDoff(){
  GreenOFF();
  BlueOFF();
  RedOFF();
}
//self commenting macros
void updateLEDs(){
  if(left_distance < TRIGGER_DISTANCE){
    PORTD |= (1<<BLUE_LED);
  }

  if(right_distance < TRIGGER_DISTANCE){
    PORTD |= (1<<RED_LED);
  }

  if(front_distance < TRIGGER_DISTANCE){
    PORTD |= (1<<BLUE_LED);
    PORTD |= (1<<RED_LED);
  }else{
    if(right_distance > TRIGGER_DISTANCE ){
      PORTD &= ~(1<<RED_LED);
    }
    if(left_distance > TRIGGER_DISTANCE){
      PORTD &= ~(1<<BLUE_LED);
    }
  }
}
