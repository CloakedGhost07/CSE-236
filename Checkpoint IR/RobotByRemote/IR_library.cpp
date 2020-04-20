#include <avr/io.h>
#include "IR_library.h"
#include "motors.h"

volatile uint8_t  newIrPacket = FALSE;
uint16_t time1[SAMPLE_SIZE], time0[SAMPLE_SIZE];
uint8_t  i;
uint32_t x;

void printRemoteButton(uint32_t val){
  switch(val){
    case REMOTE_UP:
      Serial.println("UP");
      break;
    case REMOTE_DOWN:
      Serial.println("DOWN");
      break;
    case REMOTE_LEFT:
      Serial.println("LEFT");
      break;
    case REMOTE_RIGHT:
      Serial.println("RIGHT");
      break;
    case REMOTE_OK:
      Serial.println("OK");
      break;
    case REMOTE_NUM1:
      Serial.println("NUM1");
      break;
    case REMOTE_NUM2:
      Serial.println("NUM2");
      break;
    case REMOTE_NUM3:
      Serial.println("NUM3");
      break;
    case REMOTE_CH_UP:
      Serial.println("CH_UP");
      break;
    case REMOTE_CH_DOWN:
      Serial.println("CH_DOWN");
      break;
    default :
      Serial.println("Unknown code.");
  }
}

int speed = 0;

void decodeRemote(uint32_t val){
  switch(val){
    case REMOTE_UP:
      forwardMotors();
      break;
    case REMOTE_DOWN:
      backwardMotors();
      break;
    case REMOTE_LEFT:
      leftMotors(90);
      break;
    case REMOTE_RIGHT:
      rightMotors(90);
      break;
    case REMOTE_OK:
      stopMotors();
      break;
    case REMOTE_NUM1:
      setForwardSpeed(100);
      break;
    case REMOTE_NUM2:
      setForwardSpeed(150);
      break;
    case REMOTE_NUM3:
      setForwardSpeed(200);
      break;
    case REMOTE_CH_UP:
      if(speed < 190){
        speed += 10;
      }else{
        speed = 200;
      }
      setForwardSpeed(speed);
      break;
    case REMOTE_CH_DOWN:
      if(speed >=10){
        speed += -10;
      }else{
        speed = 0;
      }
      setForwardSpeed(speed);
      break;
    default :
      break;
  }
}

void setupIR(){
  WDTCSR = 0x00;

  Serial.begin(9600);
  Serial.println("Starting up.");

  //Init Timer 1
  //write line of code      /* Reset TCCR1A & TCCR1B to defaults */
  TCCR1A = 0;
  TCCR1B = 0;

  //write line of code	   	/* Set Timer 1 to CTC with OCR1A as top */
  TCCR1B |= (1<<3);

  //write line of code	    /* Set clock prescaler to clk/64 */
  TCCR1B |= (1<<1) | (1<<0);
  /* Configure OCR1A (the counter top) to generate an interrupt every 65ms. */
  OCR1A = 0x3f7a;
  //write line of code     	/* Clear timer 1 counter register high byte first*/
  TCNT1H = 0;
  TCNT1L = 0;
  //write line of code

  /* Configure IR input on Port D, Pin 2 using registers and (1 << IR_PIN) value */
							/* Input IR on Port D, Pin 2 */
							/* Enable Pullup on Port D, Pin 2 */
  DDRD |= (0<<IR_PIN);
  PORTD |= (1<<IR_PIN);
}

void handleIRinput(){
  while(IR_DECODER_PIN != 0);
  TCNT1 = 0;
  newIrPacket = FALSE;
  TIFR1 |= (1<<1);
  TIMSK1 |= (1<<1);

  for(i=0; i<SAMPLE_SIZE; i++) {

    TCNT1 = 0;                  // reset timer and
    while(IR_DECODER_PIN!=0 && newIrPacket == FALSE);   // wait while IR is logic 0
    time0[i] = TCNT1;           // and store timer 1 count

    TCNT1 = 0;                  // reset timer and
    while(IR_DECODER_PIN == 0 && newIrPacket == FALSE); // wait while IR is logic 1
    time1[i] = TCNT1;           // and store timer 1 count

  }
  for(i=0; i<SAMPLE_SIZE; i++) {
      if(i > 1 && time0[i] > 300){
        x = (x<<1) + 1;
      }
      else if(i > 1){
        x = (x<<1);
      }

  }
  Serial.print("This is the value  in hex 0x");
  Serial.println(x,HEX);
  printRemoteButton(x);
  decodeRemote(x);

}

ISR(TIMER1_COMPA_vect){
	//write line of code	// Disable interrupt on match with OCR1A
  TIMSK1 &= ~(1<<1);
  newIrPacket = TRUE;
}
