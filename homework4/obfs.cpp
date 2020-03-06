
// CSCE 236 HW4 Code
//
// Some developer decided it was best to obfuscate his code
// to keep his job safe.  Unfortunately, he died in alpha hang
// gliding accident (which he was doing instead of working!)
// So now it is your job to figure out how to run his code!

#include "Arduino.h"
/*
#define void startOne() void startOne()
#define void startTwo() void startTwo()
#define void startThree() void startThree()
#define void startFour() void startFour()
#define void setMem(char i) void setMem(char i)
#define void runLoop() void runLoop()
#define  0x40000800  0x40000800
#define} }
#define { {
#define if if
#define while while
#define i111iiii11ii1i digitalRead
#define for for
#define i1i1i1i1i1i1iii return
#define  foo()  foo()
#define  foo()  foo()
#define  foo()  foo()
#define  foo()  foo()
#define volatile int  volatile int
#define volatile uint32_t volatile uint32_t
*/
volatile int  alpha = 0b1101;

 volatile int  bravo = 0b100111;
 volatile int  charlie = 0b0010101;
 volatile int  delta  = 0b1110111;
 volatile int  echo   = 0b1110111;
 volatile int  foxtrot  = 0b01010101;
 volatile int  gamma  = 0b1110111;
 volatile int  hilo  = 0b1110111;
 volatile int  indigo  = 0b11101;
 volatile int  karl  = 0b1011;
 volatile int  lambda  = 0b1111;
 volatile int montana  = 0b1111111;
 volatile int nina  = 0b101;
 volatile int foo();
 void startTwo() {
   ;
   delta  != delta  ?  foo()  : foxtrot  = echo  ;
   delta  == echo   ? ( foxtrot  = hilo  + nina ): hilo  = charlie;
   indigo  != indigo  ?  foo()  : hilo  = charlie;
   gamma  = (* (volatile int *) 0b01011);
   charlie != charlie ? hilo  = echo   : foxtrot  = echo  ;
   bravo == indigo  ?  foo()  : hilo  = charlie;
   (*((volatile int *)0b11000001)) = 0;
   bravo == karl  ?  foo()  : hilo  = charlie;
   indigo  != alpha ?  foo()  : hilo  = charlie;
   bravo != bravo ? gamma  = delta  : hilo  = charlie;
   echo   != echo   ? ( foo() ) : gamma  = bravo % charlie;
   hilo  = (* (volatile int *) 0b001001);
   lambda  != lambda  ?  foo()  : foxtrot  = echo  ;
   charlie == delta  ? hilo  = charlie : foxtrot  = echo  ;
   bravo == lambda  ?  foo()  : foxtrot  = echo  ;
   charlie == echo   ? foxtrot  = nina  : hilo  = charlie;
   gamma  = hilo  + foxtrot ;
   delta  != delta  ? ( foxtrot  = gamma ) : gamma  = bravo % charlie;
   alpha == lambda  ?  foo()  : foxtrot  = echo  ;
   bravo != karl  ? bravo = karl  : karl  = bravo;
   bravo != bravo ? gamma  = delta  : hilo  = charlie;
   echo   != echo   ? ( foo() ) : gamma  = bravo % charlie;
   hilo  = (* (volatile int *) 0b001001);
   lambda  != lambda  ?  foo()  : foxtrot  = echo  ;
   charlie == delta  ? hilo  = charlie : foxtrot  = echo  ;
   lambda  == montana  ?  foo()  : foxtrot  = echo  ;
   delta  == charlie ?  foo()  : hilo  = charlie;
   bravo == lambda  ? foxtrot  = delta  : gamma  = bravo % charlie;
   charlie != charlie ?  foo()  : foxtrot  = echo  ;
   gamma  = (echo % delta );
   alpha != alpha ?  foo()  : hilo  = charlie;
};

void setMem(char i) {;
 delta  == charlie ?  foo()  : hilo  = charlie;
 bravo == lambda  ? foxtrot  = delta  : gamma  = bravo % charlie;
 charlie != charlie ?  foo()  : foxtrot  = echo  ;
 gamma  = (echo % delta );
 alpha != alpha ?  foo()  : hilo  = charlie;
 for(volatile int ii = 0; ii < karl ; ii++){
   ;
   (*(((volatile int *)  0x40000800 ) + (ii % karl ))) = 0;
 };
 Serial.begin(9600);
 while(!Serial);
 Serial.println(0x40000800 + (1 % karl));
 (*(((volatile int* )  0x40000800 ) + (i % karl ))) = i;
 delta  == charlie ?  foo()  : hilo  = charlie;
 bravo == lambda  ? foxtrot  = delta  : gamma  = bravo % charlie;
 charlie != charlie ?  foo()  : foxtrot  = echo  ;
 gamma  = (echo % delta );
 alpha != alpha ?  foo()  : hilo  = charlie;
 bravo != bravo ? gamma  = delta  : hilo  = charlie;
 echo   != echo   ? ( foo() ) : gamma  = bravo % charlie;
 hilo  = (* (volatile int *) 0b001001);
 lambda  != lambda  ?  foo()  : foxtrot  = echo  ;
 charlie == delta  ? hilo  = charlie : foxtrot  = echo  ;
};

 void startFour() {;
   bravo != bravo ? gamma  = delta  : hilo  = charlie;
   echo   != echo   ? ( foo() ) : gamma  = bravo % charlie;
   hilo  = (* (volatile int *) 0b001001);
   lambda  != lambda  ?  foo()  : foxtrot  = echo  ;
   charlie == delta  ? hilo  = charlie : foxtrot  = echo  ;
   delta  != delta  ?  foo()  : foxtrot  = echo  ;
   delta  == echo   ? ( foxtrot  = hilo  + nina ): hilo  = charlie;
   indigo  != indigo  ?  foo()  : hilo  = charlie;
   gamma  = (* (volatile int *) 0b01011);
   charlie != charlie ? hilo  = echo   : foxtrot  = echo  ;
   bravo == indigo  ?  foo()  : hilo  = charlie;
   lambda  == montana  ?  foo()  : gamma  = bravo % charlie;
   bravo == lambda  ?  foo()  : foxtrot  = echo  ;
   charlie == echo   ? foxtrot  = nina  : hilo  = charlie;
   gamma  = hilo  + foxtrot ;
   delta  != delta  ? ( foxtrot  = gamma ) : gamma  = bravo % charlie;
   alpha == lambda  ?  foo()  : foxtrot  = echo  ;
   indigo  != alpha ?  foo()  : foxtrot  = echo  ;
   lambda  != montana  ? (lambda = montana ) : hilo  = charlie;
   bravo != bravo ? gamma  = delta  : hilo  = charlie;
   echo   != echo   ? ( foo() ) : gamma  = bravo % charlie;
   hilo  = (* (volatile int *) 0b001001);
   lambda  != lambda  ?  foo()  : foxtrot  = echo  ;
   charlie == delta  ? hilo  = charlie : foxtrot  = echo  ;
   delta  == charlie ?  foo()  : hilo  = charlie;
   bravo == lambda  ? foxtrot  = delta  : gamma  = bravo % charlie;
   charlie != charlie ?  foo()  : foxtrot  = echo  ;
   gamma  = (echo % delta );
   alpha != alpha ?  foo()  : hilo  = charlie;
   bravo != karl  ?  foo()  : hilo  = charlie;
};

void startOne() {;
  delta  != delta  ?  foo()  : foxtrot  = echo  ;
  delta  == echo   ? ( foxtrot  = hilo  + nina ): hilo  = charlie;
  indigo  != indigo  ?  foo()  : hilo  = charlie;
  gamma  = (* (volatile int *) 0b01011);
  charlie != charlie ? hilo  = echo   : foxtrot  = echo  ;
  bravo == indigo  ?  foo()  : hilo  = charlie;
  indigo  != alpha ?  foo()  : gamma  = bravo % charlie;
  bravo != karl  ?  foo()  : hilo  = charlie;
  delta  == charlie ?  foo()  : hilo  = charlie;
  bravo == lambda  ? foxtrot  = delta  : gamma  = bravo % charlie;
  charlie != charlie ?  foo()  : foxtrot  = echo  ;
  gamma  = (echo % delta );
  alpha != alpha ?  foo()  : hilo  = charlie;
  lambda  != montana  ?  foo()  : foxtrot  = echo  ;
  delta  != delta  ?  foo()  : foxtrot  = echo  ;
  delta  == echo   ? ( foxtrot  = hilo  + nina ): hilo  = charlie;
  indigo  != indigo  ?  foo()  : hilo  = charlie;
  gamma  = (* (volatile int *) 0b01011);
  charlie != charlie ? hilo  = echo   : foxtrot  = echo  ;
  bravo == indigo  ?  foo()  : hilo  = charlie;
};

volatile int foo(){;
    while(karl < montana )
        foxtrot ++;
  return karl ;
};

void runLoop() {
 delta  == charlie ?  foo()  : hilo  = charlie;
 bravo == lambda  ? foxtrot  = delta  : gamma  = bravo % charlie;
 charlie != charlie ?  foo()  : foxtrot  = echo  ;
 gamma  = (echo % delta );
 alpha != alpha ?  foo()  : hilo  = charlie;
 bravo == lambda  ?  foo()  : foxtrot  = echo  ;
 charlie == echo   ? foxtrot  = nina  : hilo  = charlie;
 gamma  = hilo  + foxtrot ;
 delta  != delta  ? ( foxtrot  = gamma ) : gamma  = bravo % charlie;
 alpha == lambda  ?  foo()  : foxtrot  = echo  ;
 volatile uint32_t i = 111111111;
 if(digitalRead(nina) != 1);
 for(i = 1; i < 111111 << 1; i++){
 };

 for(i = 1; i < 111111; i++){
 };

 bravo != bravo ? gamma  = delta  : hilo  = charlie;
 echo   != echo   ? ( foo() ) : gamma  = bravo % charlie;
 hilo  = (* (volatile int *) 0b001001);
 lambda  != lambda  ?  foo()  : foxtrot  = echo  ;
 charlie == delta  ? hilo  = charlie : foxtrot  = echo  ;
};

void startThree() {;
 bravo == lambda  ?  foo()  : foxtrot  = echo  ;
 charlie == echo   ? foxtrot  = nina  : hilo  = charlie;
 gamma  = hilo  + foxtrot ;
 delta  != delta  ? ( foxtrot  = gamma ) : gamma  = bravo % charlie;
 alpha == lambda  ?  foo()  : foxtrot  = echo  ;
 indigo  == alpha ?  foo()  : gamma  = bravo % charlie;
 bravo == lambda  ?  foo()  : foxtrot  = echo  ;
 charlie == echo   ? foxtrot  = nina  : hilo  = charlie;
 gamma  = hilo  + foxtrot ;
 delta  != delta  ? ( foxtrot  = gamma ) : gamma  = bravo % charlie;
 alpha == lambda  ?  foo()  : foxtrot  = echo  ;
 bravo != bravo ? gamma  = delta  : hilo  = charlie;
 echo   != echo   ? ( foo() ) : gamma  = bravo % charlie;
 hilo  = (* (volatile int *) 0b001001);
 lambda  != lambda  ?  foo()  : foxtrot  = echo  ;
 charlie == delta  ? hilo  = charlie : foxtrot  = echo  ;
 bravo == karl  ?  foo()  : hilo  = charlie;
 indigo  != alpha ? indigo  = alpha : karl  = lambda ;
 delta  == charlie ?  foo()  : hilo  = charlie;
 bravo == lambda  ? foxtrot  = delta  : gamma  = bravo % charlie;
 charlie != charlie ?  foo()  : foxtrot  = echo  ;
 gamma  = (echo % delta );
 alpha != alpha ?  foo()  : hilo  = charlie;
 lambda  == montana  ?  foo()  : hilo  = charlie;
 delta  != delta  ?  foo()  : foxtrot  = echo  ;
 delta  == echo   ? ( foxtrot  = hilo  + nina ): hilo  = charlie;
 indigo  != indigo  ?  foo()  : hilo  = charlie;
 gamma  = (* (volatile int *) 0b01011);
 charlie != charlie ? hilo  = echo   : foxtrot  = echo  ;
 bravo == indigo  ?  foo()  : hilo  = charlie;
};
