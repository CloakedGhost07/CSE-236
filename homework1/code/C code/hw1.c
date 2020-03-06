/*--------------------------------------------------------------------
Name: 	Michael Martin
Date: 	1/21/2020
Course: CSCE 236 Embedded Systems (Spring 2020)
File: 	hw1.c
HW/Lab:	Homework 1, programming component

Purp:	A brief description of what this program does and
		the general solution strategy.

Doc:	no collaboration

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code.  I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/
/*
Look for comments that include "Student Code" to indicate where you
should fill in code.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> // need this for uint8_t


//helper function to print binary
void bin(unsigned n)
{
    /* step 1 */
    if (n > 1)
        bin(n/2);

    /* step 2 */
    printf("%d", n % 2);
}
/**
 * Return your user name
 **/
char* getFullName(void){
  ////////////////////////// Student Code //////////////////////////
  //  Write code to return a pointer to a _global_ variable that
  //  contains your full name.
  char temp[] = "Michael Martin";
  char* name = (char*)malloc(sizeof(char) * (1+ strlen(temp)));
  strcpy(name,"Michael Martin");
  return name;
}

////////////////////////// Student Code //////////////////////////
// Write a funciton called getLastName() that returns a pointer to the
// same _global_ variable that contains your full name, but that
// starts at your last name.
//
char* getLastName(){
  char* name = getFullName();
  char* last;
  int i;
  int flag = 0;
  for(i=0;i<strlen(name);i++){
    if(name[i] == ' '){
      return &name[i+1];
    }
  }
  return NULL;
}


/**
 * Gets the ith character of the user name or returns '!' if the name
 * is not that long.
 **/
char getFullNameChar(int i){
  char *name = getFullName();

  ////////////////////////// Student Code //////////////////////////
  //  Write code to return the ith character of name or '!' if an out
  //  of bounds index is requested.  Do _not_ use strlen or equivalent
  //  functions to determine the length of the string, instead, write
  //  your own code to determine the length of the string (look for
  //  the null termination of the name string: '\0').
  int j =0;
  while(name[j] != '\0'){
    j++;
  }
  if(j <= i){
    return '!';
  }
  else{
    return name[i];
  }
}

/**
 * Print the results of the string operation tests
 **/
void stringOperations(void){
  char *name = getFullName();

  printf("Name: %s\n",name);
  ////////////////////////// Student Code //////////////////////////
  // Uncomment the following code once you create the getLastName()function

  printf("LastName: %s\n",getLastName());

  printf("Name[0]: %c\n",getFullNameChar(0));
  printf("Name[4]: %c\n",getFullNameChar(4));
  printf("Name[%d] (last): %c\n",(int)strlen(name)-1,
         getFullNameChar(strlen(name)-1));
  printf("Name[%d] (oob): %c\n",(int)strlen(name),
         getFullNameChar(strlen(name)));
  printf("Name[%d] (oob): %c\n",(int)strlen(name)+10,
         getFullNameChar(strlen(name)+10));

  printf("\n");
}

/**
 * Print the output of various bit operations
 **/
void bitOperations(void){
  int varA = 0x81914;
  int varB = 0x10236;

  ////////////////////////// Student Code //////////////////////////
  // Complete the following print statements by ouputing the value
  // after doing the bit operations indicated in the comments.  You
  // should not periminately modifiy the value of the variables.
  // You also should _not_ hard code the result.

  // Output the value (1 or 0) of bit 3 (zero referenced) in varA and varB
  printf("Bit 3 in varA: %#x\n",
           varA & (1 << 2));
  printf("Bit 3 in varB: %#x\n",
           varB & (1 << 2));

  // Output the value of varA after setting bit 5 (zero referenced) to 0
  printf("Original VarA: %#x\n", varA);
  int t = (~(1 << 4));
  varA &= t;
  printf("Bit 5 set to 0 varA: %#x\n",
           varA);

  // Output the value of varB after setting bit 7 (zero referenced) to 1
  varB |=(1 << 6);
  printf("Bit 7 set to 1 varB: %#x\n",
           varB);

  // Output the value of the varA after setting the 3-5 bits
  // (inclusive) of varA to the lower 3 bits of varB.

  t = ((varB & 7) << 2); // get lowest three bits and shift left 2
  varA &= (~(7 << 2));//clear bits 3 - 5 on VarA
  varA |= t; // or the two bit strings
  printf("varA after...: %#x\n",
           varA);

  t = ((236>>3) & (0x3<<1)) | 19;
  printf("output of ((236>>3) & (0x3<<1)) | 19 is %#x\n", t);
  t = (((0x16<<2) + 0x18) & (1<<6));
  printf("output of (((0x16<<2) + 0x18) & (1<<6)) is %#x\n", t);

  uint8_t output = 0;

  uint8_t counter = 15;

  uint16_t offset = 0x236;

  while(counter > 0){

    counter = counter >> 1;

    output++;

  }

  output += offset;
  printf("This is the offset: %#x\n", output);

}

/**
 * Main function that calls the corresponding functions
 **/
int main(){
  printf("CSCE 236 HW1 Output\n");
  printf("-------------------\n");
  stringOperations();
  bitOperations();

  return(0);
}
