#define INTERRUPT_PIN 3
#define GREEN_LED 4
#define RED_LED 6

ISR(INT1_vect){
  //cli();
  //interrupt handling
  //turn on green led when subroutine is called
  PORTD |= (1<<GREEN_LED);
  delay(10); //hold for 10 milliseconds
}

void setup(){
  DDRD &= ~(1<<INTERRUPT_PIN);
  PORTD |= (1<<INTERRUPT_PIN);
  DDRD |= (1 << RED_LED) | (1<<GREEN_LED);
  EICRA |= (0<<3) | (1<<2); //any logical change to the pin
  // EICRA |= (1<<3) | (0<<2); //falling edge on the pin
  EIMSK |= (1<<1); //enable INT1 register
}

void loop(){

  if((PIND & (1<<3)) > 0){ //button not pressed
    green_off();
  }


}

//LED toggle functions to clarify code
void green_off(){
  PORTD &= ~(1<<GREEN_LED);
}
void green_on(){
  PORTD |= (1<<GREEN_LED);
}
void red_on(){
  PORTD |= (1<<RED_LED);
}
void red_off(){
  PORTD &= ~(1<<RED_LED);
}
