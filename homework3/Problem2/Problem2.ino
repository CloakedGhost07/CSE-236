#include<stdint.h>



uint8_t val1_8bit = (uint8_t)random(32);
uint8_t val2_8bit = (uint8_t)random(32);
uint16_t val1_16bit = (uint16_t)random(65536);
uint16_t val2_16bit =(uint16_t) random(65536);
uint32_t val1_32bit = (uint32_t)random(4294996);
uint32_t val2_32bit = (uint32_t)random(4294966);

float t = 3.5431;
float u = 4.8431;


uint16_t startTime = 0;
uint16_t endTime = 0;

void setup() {
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  Serial.begin(9600);
  Serial.println(val1_8bit);
  Serial.println(val2_8bit);
  Serial.println(val1_16bit);
  Serial.println(val2_16bit);
  Serial.println(val1_32bit);
  Serial.println(val2_32bit);
  Serial.println(t);
  Serial.println(u);

  //Init counter1
  TCCR1A = 0; //Normal mode 0xffff top, rolls over
  TCCR1B &= ~(7);
  TCCR1B |= (0 << CS12) | (1 << CS10); //Clock prescaler 1024

  // put your setup code here, to run once:
 uint8_t result8 = findDiff_8(val1_8bit,val2_8bit);
  Serial.println("result8");
  Serial.println(result8);
  uint16_t result16 = findDiff_16(val1_16bit,val2_16bit);
  Serial.println("result16");
  Serial.println(result16);
  uint32_t result32 = findDiff_32(val1_32bit,val2_32bit);
  Serial.println("result32");
  Serial.println(result32);

  float res_float = findFloatSubTime(t,u);
  Serial.println(res_float);
  res_float = findFloatDivTime(t,u);
  Serial.println(res_float);
}

uint8_t findDiff_8(uint8_t val1, uint8_t val2){
  uint8_t diff = 0;
  startTime = micros();
  diff = val1 / val2;
  endTime = micros();
  Serial.println("8 bit time");
  Serial.println(endTime-startTime);
  return diff;
}


uint16_t findDiff_16(uint16_t val1, uint16_t val2){
  uint16_t diff = 0;
  startTime = micros();
  diff = val1 / val2;
  endTime = micros();
  Serial.println("16 bit time");
  Serial.println(endTime-startTime);
  return diff;
}

uint32_t findDiff_32(uint32_t val1, uint32_t val2){
  uint32_t diff = 0;
  startTime = micros();
  diff = val1 / val2;
  endTime = micros();
  Serial.println("32 bit time");
  Serial.println(endTime-startTime);
  return diff;
}


float findFloatSubTime(float x,float y){
  float z = 0;
  startTime = micros();
  z = x - y;
  endTime = micros();
  Serial.println("float sub time");
  Serial.println(endTime-startTime);
  return z;
}

float findFloatDivTime(float x,float y){
  float z = 0;
  startTime= 0;
  TCNT1 = 0;
  z = x / y;
  endTime = TCNT1;
  Serial.println("float div time");
  Serial.println(endTime-startTime);
  return z;
}


void loop() {
  /*
  // put your main code here, to run repeatedly:
  uint8_t result8 = findDiff_8(val1_8bit,val2_8bit);
  result8 = result8 * 78;
  uint16_t result16 = findDiff_16(val1_16bit,val2_16bit);
  result16 = result16 + 100;
  uint32_t result32 = findDiff_32(val1_32bit,val2_32bit);
  result32 = result32 + 80;
  */
}
