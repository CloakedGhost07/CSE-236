/*
 * CSCE236 Embedded Systems Spring
 * HW4
 */

//These are the functions that we know exist in obfs.cpp

/*
1234  x
1243  x
1423  x
4123  x
4132  x
1432
1342
1324
3124
3142
3412
4312
4321
3421
3241
3214
2314
2341
2431
4231
4213
2413
2143
2134
*/
void startOne();
void startTwo();
void startThree();
void startFour();
void setMem(char i);
void runLoop();


void setup() {
  Serial.begin(9600);
  while(!Serial){};
  Serial.println("Starting up...");
  delay(500);
  //This order works //2341
  startThree();
  Serial.begin(9600);
  Serial.println("I made it here");
  startTwo();
  Serial.begin(9600);
  Serial.println("I made it here");
  startFour();
  Serial.begin(9600);
  Serial.println("I made it here");
  startOne();

  //Write _YOUR_ initials to memory and determine where they are put
  //Note you should only do one at a time since they may overwrite each other
  setMem('c');
  setMem('d');

 //The serial port gets messed up, so this won't print
 Serial.begin(9600);
 Serial.println("Finished setup");

}

void loop() {
  //Figure out how long this function takes to run with
  //and without the button pressed.
  runLoop();
}
