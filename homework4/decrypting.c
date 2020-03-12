/*
Author Michael Martin
3/8/2020

Decryption program for CSCE 236 Embedded Systems homework 4

some functions are included that decrypt a message.
Code has been altered to solve the final problem of finding the key to decrypt a message
*/

//#include <Arduino.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

void decryptMessage(const uint8_t* msg,int size_msg,const uint8_t* key,int size_key, uint8_t* mem);
uint8_t decryptValue(uint8_t val, uint8_t key);
void printMessage(uint8_t* msg, int,FILE*);
char* toString(uint8_t* msg, int size);
bool checkString(char*,int);

int main(){
    uint8_t arr[] = {0x35, 0xdf, 0x00, 0xca, 0x5d, 0x9e, 0x3d, 0xdb, 0x12, 0xca, 0x5d, 0x9e, 0x32,
0xc8, 0x16, 0xcc, 0x12, 0xd9, 0x16, 0x90, 0x53, 0xf8, 0x01, 0xd7, 0x16, 0xd0,
0x17, 0xd2, 0x0a, 0x90, 0x53, 0xf9, 0x1c, 0xd1, 0x17, 0x90, 0x53, 0xf9, 0x1c,
0xd1, 0x17, 0x9e};
    uint8_t key[] = {0,0};
    int size_arr = sizeof(arr) / sizeof(uint8_t);
    int size_key = sizeof(key) / sizeof(uint8_t);

    int i,j,k,n;

    printf("%d is the size of my array\n", size_arr);

    uint8_t* mem = (uint8_t*)malloc(sizeof(uint8_t) * size_arr);

    FILE* file = fopen("data.txt", "w");
    if(file == NULL){
      printf("failed to open file.\n");
      return 0;
    }

    fprintf(file,"Start file:\n");

    for(i = 0;i<=0xff;i++){
      for(j=0;j<=0xff;j++){
        // for(k=0;k<=0xff;k++){
        //  for(n=0;n<=0xff;n++){

            key[0] = (uint8_t)i;
            key[1] = (uint8_t)j;
          // key[2] = (uint8_t)k;
          //  key[3] = (uint8_t)n;
            decryptMessage(arr,size_arr,key,size_key,mem);
            char* s = toString(mem,size_arr);
            if(checkString(s,41)){
              fprintf(file,"Found at key : 0x%x%x\n",i,j );
              printMessage(mem, size_arr,file);

            }
          //}
        // }
      }
    }
    free(mem);
    free(key);
    free(arr);
    fclose(file);
    //decryptMessage(arr,size_arr,key,size_key,mem);
    //printf("%c", 0xf8);

}

//decrypts the message and puts it in the mem variables location
void decryptMessage(const uint8_t* msg,int size_msg,const uint8_t* key,int size_key, uint8_t* mem){
  int i;
  int j = 0;
  //printf("%d is the size of the message, %d is key size\n",size_msg, size_key);
  for(i=0;i<size_msg;i++){
    mem[i] = decryptValue(msg[i],key[i % size_key]);
  }
  return;
}

//xor the value with the key
uint8_t decryptValue(uint8_t val, uint8_t key){
  return val ^ key;
}

char* toString(uint8_t* msg, int size){
    char* str = (char*)malloc(sizeof(char) * (size +1) );
    int i;
    for(i=0;i<size;i++){
      str[i] = msg[i];
    }
    str[i]= '\0';
    return str;
}

//I printed to a file, code can be uncommented to be able to print to serial.
void printMessage(uint8_t* msg, int length,FILE* file){
  //Serial.begin(9600);
  int i;
  char str[10];
  for(i=0;i<length;i++){
    sprintf(str,"%c",msg[i]);
    //Serial.print(str);
    //printf("%c", str[0]);
    fprintf(file,"%c", str[0]);
  }
 // printf("\n");
  fprintf(file,"\n");
  //Serial.println();
  return;
}

bool checkString(char* s, int size){
  int i;
  int count = 0;
  if(s[0] == 'F' && s[1] == 'a' && s[2] == 's' && s[3] == 't'){
    return true;
  }

  return false;
}
