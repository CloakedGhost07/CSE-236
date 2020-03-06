#include<stdio.h>
#include<stdint.h>
//#include<Arduino.h>



int main(){
    //1000_0000
    uint8_t var = 0x80;
    //1111_1111
    uint8_t DDRC = 0xFF;
    //0x18 = 0001_1000
    //1110_0111

    DDRC = (DDRC &~(0x18))  | ((var>>6)<<3);

    printf("%#x is the value in DDRC\n", DDRC);

    return 0;
  }
