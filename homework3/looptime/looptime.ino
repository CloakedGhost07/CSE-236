#include<stdint.h>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
/*
srand(time(NULL));
uint8_t bit8A = rand();
uint16_t bit16A = rand();
uint32_t bit32A = rand();
uint8_t bit8B = rand();
uint16_t bit16B = rand();
uint32_t bit32B = rand();
*/
void setup() {
  // put your setup code here, to run once:
srand(time(NULL));
}

uint8_t findDiff8bit(uint8_t x, uint8_t y){
  //int start = micros();
  uint8_t t = x - y;
  //int endtime = micros();
  //Serial.println(start - endtime);
  return t;
}
uint16_t findDiff16bit(uint16_t x, uint16_t y){
  //int start = micros();
  uint16_t t = x - y;
  //int endtime = micros();
  //Serial.println(start - endtime);
  return t;
}
uint32_t findDiff32bit(uint32_t x, uint32_t y){
  //int start = micros();
  uint32_t t = x - y;
  //int endtime = micros();
  //Serial.println(start - endtime);
  return t;
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t bit8A = rand();
  uint16_t bit16A = rand();
  uint32_t bit32A = rand();
  uint8_t bit8B = rand();
  uint16_t bit16B = rand();
  uint32_t bit32B = rand();
  
  uint8_t res8 = findDiff8bit(bit8A,bit8B);

  uint16_t res16 = findDiff16bit(bit16A,bit16B);

  uint32_t res32 = findDiff32bit(bit32A,bit32B);
}
