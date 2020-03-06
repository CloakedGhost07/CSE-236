/*--------------------------------------------------------------------
Name:   Michael Martin
Date:   1/26/2020
Course: CSCE 236 Embedded Systems (Spring 2020)
File:   lab1.cpp
HW/Lab: Lab 1, programming component

Purp: Source code for Arduino board, has a few funcions that can flash RGB
LED, and use photosensors to find light source.

Doc:  Partnered with Jeremiah Cantu

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code.  I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/

#include<stdint.h>
#include<Arduino.h>
#include<Servo.h>
#include<math.h>

//memory locations
#define DDRD_reg (*((volatile uint8_t *) 0x2A))
#define DDRD_out (*((volatile uint8_t *) 0x2B))
#define DDRD_in (*((volatile uint8_t *) 0x29))

//MACROS for color lights and button IO
#define red 5
#define green 6
#define blue 7
#define button 3

//MACROS for direction of servo
#define LEFT 1
#define RIGHT (-1)

//variables for servo motor
Servo myservo;
int pos = 90;
int state = 0;

//variables for photoSensor
uint16_t left_prev, right_prev;
uint16_t left_curr, right_curr;
int direction = RIGHT;


void setup() {
  //set switch to input
  DDRD_reg &= ~(1 << button);
  
  Serial.begin(9600);
  pinMode(A0,INPUT);

  //Set DDRD lights to output ports
  DDRD_reg |= (1 << blue);
  DDRD_reg |= (1 << green);
  DDRD_reg |= (1 << red);
  myservo.attach(11);
  
}

//Light cycle function
void lights(){

  DDRD_out |= (1 << red); //red on
  delay(500);
  DDRD_out |= (1 << green);//red and green on
  delay(500);
  DDRD_out &= ~(1 << red); // green on
  delay(500);
  DDRD_out |= (1 << blue); //green and blue on
  delay(500);
  DDRD_out &= ~(1 << green); // blue on
  delay(500);
  DDRD_out |= (1 << red); // red and blue on
  delay(500);
  DDRD_out &= ~(1 << red); // all off
  DDRD_out &= ~(1 << blue);
  delay(1000);
}


void Button_function(){
   if(((PIND & (1 << button)) >> button) > 0){
    lights();
  }
}

//Lights with Arduino library, for comparison
void lights2(){
  digitalWrite(red,HIGH);
  delay(500);
  digitalWrite(green,HIGH);
  delay(500);
  digitalWrite(red,LOW);
  delay(500);
  digitalWrite(blue,HIGH);
  delay(500);
  digitalWrite(green,LOW);
  delay(500);
  digitalWrite(red,HIGH);
  delay(500);
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  delay(500);
}

//Read input from photoSensor through serial port
void photoSensor(){
  uint16_t val = analogRead(A0);
  Serial.println(val);
}

//This cycles the servo 90 degrees per button press: 4 states
void runMotor(){
  
  if(((PIND & (1 << button)) >> button) > 0 && state == 0){
    for(pos = 0; pos <= 90; pos +=1){
      myservo.write(pos);
      delay(5);
      Serial.println(pos);
    }
    state = 1;
  }
  else if((PIND & (1 << button)) >> button > 0 && state == 1){
    for(pos = 90; pos <=180; pos += 1){
      myservo.write(pos);
      delay(5);
      Serial.println(pos);
    }
    state = 2;
  }
  else if((PIND & (1 << button)) >> button > 0 && state == 2){
    for(pos = 180; pos >= 90; pos -= 1){
      myservo.write(pos);
      delay(5);
      Serial.println(pos);
    }
    state = 3;
  }
  else if((PIND & (1 << button)) >> button > 0 && state == 3){
    for(pos = 90; pos >=0; pos -= 1){
      myservo.write(pos);
      delay(5);
      Serial.println(pos);
    }
    state = 0;
  }
}

//function using 2 photoSensors to locate light source
void findLight2(){
  int tolerance = 3;
  //previously declared global variables (for reference)
  //uint16_t left_prev, right_prev;
  //uint16_t left_curr, right_curr;

  left_curr = analogRead(A1);
  right_curr = analogRead(A0);
  int diff = left_curr - right_curr;
  Serial.println(diff);
  if((left_curr < right_curr && ((-1) * diff) > tolerance )){
    pos -= 1; // turn right
    myservo.write(pos);
    delay(20);
    Serial.println("moving right");
  }
  if(right_curr < left_curr && (diff) > tolerance){
    pos += 1;//turn left
    myservo.write(pos);
    delay(20);
    Serial.println("moving left");
  }
  //Make sure position doesn't go off to the unknown
  if(pos > 180){pos = 180;}
  if(pos < 0){pos = 0;}
  
}

void findLight1(){
  left_curr = analogRead(A1);
  
  if(left_curr > left_prev){
    pos += 1;
    myservo.write(pos);
    delay(10);
  }
  if(left_curr < left_prev){
    pos-= 1;
    myservo.write(pos);
    delay(10);
  }
  left_prev = left_curr;
  if(pos > 180){pos = 180;}
  if(pos < 0){pos = 0;}
  
}



void loop() {
  findLight2();
  //findLight1();
  //Button_function();
  //runMotor();
  //lights();
  //photoSensor();
  // put your main code here, to run repeatedly:
}
