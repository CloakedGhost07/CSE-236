#define RED 2
#define BLUE 3
#define GREEN 4
#define BUTTON 5
#include "morse.h"

void setup() {
  // put your setup code here, to run once:
    DDRD |= (1<<RED);
    DDRD |= (1<<BLUE);
    DDRD |= (1<<GREEN);
    Serial.begin(9600);

    PORTD |= (1<<GREEN);
    PORTD |= (1<<RED);
    PORTD |= (1<<BLUE);
    delay(1500);
    PORTD &= ~(1<<GREEN);
    PORTD &= ~(1<<RED);
    PORTD &= ~(1<<BLUE);
    delay(1000);
    Serial.begin(9600);

    morseBlinkString(GREEN,"h",1);
    morseBlinkString(RED,"i",1);
}

bool setPrescale = false;
void buttonReadMorse(){
  if(!setPrescale){
    DDRD &= ~(1<<BUTTON);
    //Init counter1
    TCCR1A = 0; //Normal mode 0xffff top, rolls over
    TCCR1B &= ~(7);
    TCCR1B |= (1 << CS12) | (1 << CS10); //Clock prescaler 1024

    TCCR1C = 0;
    //Set counter to zero, high byte first
    TCNT1H = 0;
    TCNT1L = 0;
    //Make sure interrupts are disabled
    TIMSK1 = 0;
    TIFR1 = 0;
    setPrescale = true;
  }

  timeButtonHold();

}

int morseArr[4] = {0,0,0,0};
int i = 0;

void resetARR(){
  for(i=0;i<4;i++){
    morseArr[i] = 0;
  }
  i =0;
}

bool justReleased = false;
unsigned long startTime, endTime;
void timeButtonHold(){
  if((PIND & (1<<BUTTON)) == 0){
    TCNT1 = 0;
    while(TCNT1 < 100){}
    startTime = millis();
    
    while((PIND & (1<<BUTTON))== 0){}
    endTime = millis();
    //Serial.println("Button Held");
    
    //Serial.println((endTime-startTime)/1000.0);
    if((endTime-startTime)/1000.0 < 1.0){
      Serial.println("d");
      morseArr[i] = 1;
      i++;
    }
    else if((endTime-startTime)/1000.0 >=1.0){
      Serial.println("D");
      morseArr[i] = 2;
      i++;
    }
   justReleased = true; 
  }
  if(i > 2){
    if(morseArr[0] == 1 && morseArr[1] == 2 && morseArr[2] == 1){
      Serial.println("R");
      morseBlinkLong(RED);
      resetARR();
    }
    else if(morseArr[0] == 2 && morseArr[1] == 2 && morseArr[2] == 1){
      Serial.println("G");
      morseBlinkLong(GREEN);
      resetARR();
    }
    else if(morseArr[0] == 2 && morseArr[1] == 1 && morseArr[2] == 1 && morseArr[3] == 1){
      Serial.println("B");
      morseBlinkLong(BLUE);
      resetARR();
    }
    
  }
  if(justReleased == true && (PIND & (1<<BUTTON)) != 0){
    justReleased = false;
    TCNT1 = 0;
    while(TCNT1 < 15625){
      if((PIND & (1<<BUTTON)) == 0){
        timeButtonHold();
        return;
      }
    }
    Serial.println("s");
    resetARR();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
   buttonReadMorse();
}
