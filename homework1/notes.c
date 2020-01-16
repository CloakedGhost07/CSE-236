//turn on the led
PORTB |= (1<<2); //oring with 0000_0100
//turn off the led
PORTB &= ~(1<<2);//anding with 1111_1011

///////////////////////////////////////////////
uint8 var1 = 9;
uint8 var2 = 4;

uint8* ptr;
ptr = &var1;

*ptr = 2; //value at var1 is now 2

///////////////////////////////////////////////
