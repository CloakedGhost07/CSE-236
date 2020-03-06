/*--------------------------------------------------------------------
Name: 	Michael Martin
Date: 	1/18/2020
Course: CSCE 236 Embedded Systems (Spring 2020)
File: 	main.cpp
HW/Lab:	Homework 1, Blink with button

Purp:	This code makes the arduino board blink fast or slow depending 
on button pressed or not.

Doc:	no collaboration

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code.  I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/
#include<Arduino.h>
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
const int buttonPin = 5;
const int ledPin = 13;
void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  if (buttonState == HIGH) {
    //flash fast
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);

  } else {
    // flash slowly
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}
