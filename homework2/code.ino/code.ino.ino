/*--------------------------------------------------------------------
Name:   Michael Martin
Date:   1/30/2020
Course: CSCE 236 Embedded Systems (Spring 2020)
File:   
HW/Lab: Lab 1, programming component

Purp: Source code for Arduino board, 

Doc: 

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code.  I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/
#include<stdint.h>
#include<Arduino.h>

#define LED_PIN 13

int in_byte =0;
int flashcount = 0;
int speed = 0;
int i;

uint32_t bit32count;
uint16_t bit16count = 0xffff;
uint16_t bit16countB = 0xffff;
uint8_t bit8countA;
uint8_t bit8countB;
uint8_t bit8countC;


void setup() {
 Serial.begin(9600);
 while(!Serial){};
 //pinMode(LED_PIN,OUTPUT);
/*
 Serial.println("cycle start");
 for(bit16count = 0; bit16count < 0x3fffff; bit16count++){
    asm volatile("nop");
    
 }
  Serial.println("cycle done");
  */
 pinMode(LED_PIN,OUTPUT);
 blinkSequenceUsingBits();
}

void blinkSequenceUsingBits(){
  
  Serial.println("cycle start for 3 sec");
  digitalWrite(LED_PIN,HIGH);
  for(bit32count = 0; bit32count < 0x13ffff ; bit32count++){
    asm volatile("nop");
  }
  digitalWrite(LED_PIN,LOW);
  Serial.println("32 bit cycle done");
  
  delay(500);
  digitalWrite(LED_PIN,HIGH);
  delay(500);
  digitalWrite(LED_PIN,LOW);
  delay(500);

  Serial.println("cycle start for 6 sec");
  digitalWrite(LED_PIN,HIGH);
  for(bit16countB = 0; bit16countB < 0x48; bit16countB++){
  for(bit16count = 0; bit16count < 0xffff; bit16count ++){
     asm volatile("nop");
  }}
  digitalWrite(LED_PIN,LOW);
  Serial.println("16 bit cycle done");

  delay(500);
  digitalWrite(LED_PIN,HIGH);
  delay(500);
  digitalWrite(LED_PIN,LOW);
  delay(500);
  digitalWrite(LED_PIN,HIGH);
  delay(500);
  digitalWrite(LED_PIN,LOW);
  delay(500);
  
  digitalWrite(LED_PIN,HIGH);
  Serial.println("cycle start for 2 sec");
  for(bit8countA = 0; bit8countA < 41; bit8countA++){
    for(bit8countB = 0; bit8countB < 0xff; bit8countB++){
      for(bit8countC = 0; bit8countC < 0xff; bit8countC++){
      asm volatile("nop");
      }
    }
  }
  digitalWrite(LED_PIN,LOW);
  Serial.println("8 bit cycle done");
}  




void flashSerial(){
  if(Serial.available()>0){
    in_byte = Serial.read();
    if(in_byte != 10){
      Serial.print("This is what I read: ");
      Serial.println(in_byte);
      if(in_byte >= 48 && in_byte <= 57){
        flashcount = in_byte - 48;
        Serial.println(flashcount);
      }
      else if(in_byte == 102){
        speed = 1;
        Serial.println("Speed set to fast.");
      }
      else if(in_byte == 115){
        speed = 0;
        Serial.println("Speed set to slow");
      }
    }
    for(i = 0; i < flashcount; i++){
      digitalWrite(LED_PIN,HIGH);
      if(speed == 0){delay(750);}
      delay(250);
      digitalWrite(LED_PIN,LOW);
      if(speed == 0){delay(750);}
      delay(250);
    }
    flashcount = 0;
  }
}




void loop() {
  flashSerial();

}
