#include <Arduino.h>

#define DDRB_Reg (*((volatile uint8_t *) 0x24))
#define PORTB_Reg (*((volatile uint8_t *) 0x25))

void setup() {
  // put your setup code here, to run once:
  DDRB_Reg |= (1 << 5);

}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB_Reg |= (1 << 5);
  delay(500);
  PORTB_Reg &= ~(1 << 5);
  delay(500);
}