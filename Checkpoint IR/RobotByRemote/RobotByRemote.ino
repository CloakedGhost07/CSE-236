#include <avr/io.h>
#include "IR_library.h"
#include "robotlib.h"
#include "motors.h"
void setup() {
  //setupServo();
  //setupUltraSonic();
  setupMotors();
  setupIR();

}


void loop() {
  handleIRinput();
}
