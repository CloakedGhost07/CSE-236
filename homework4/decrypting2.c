//#include <Arduino.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

void decryptMessage(const uint8_t* msg,int size_msg,const uint8_t* key,int size_key, uint8_t* mem);
uint8_t decryptValue(uint8_t val, uint8_t key);
void printMessage(uint8_t* msg, int);

int main(){
    uint8_t arr[] = {0xf8, 0xb7, 0x46, 0x8c, 0xb2, 0x46, 0xdf, 0xac, 0x42, 0xcb, 0xba, 0x03, 0xc7,
0xba, 0x5a, 0x8c, 0xb3, 0x46, 0xc2, 0xb8, 0x57, 0xc4, 0xff, 0x4a, 0xdf, 0xff,
0x12, 0x9a, 0xff, 0x41, 0xc5, 0xab, 0x50, 0x82, 0xff, 0x03, 0xe5, 0xab, 0x03,
0xc3, 0xb1, 0x4f, 0xd5, 0xff, 0x40, 0xc3, 0xb1, 0x57, 0xcd, 0xb6, 0x4d, 0xdf,
0xff, 0x4f, 0xc9, 0xab, 0x57, 0xc9, 0xad, 0x50, 0x80, 0xff, 0x53, 0xc9, 0xad,
0x4a, 0xc3, 0xbb, 0x50, 0x80, 0xff, 0x42, 0xc2, 0xbb, 0x03, 0xdf, 0xaf, 0x42,
0xcf, 0xba, 0x50};
    uint8_t key[] = {0xac,0xdf,0x23};
    int size_arr = sizeof(arr) / sizeof(uint8_t);
    int size_key = sizeof(key) / sizeof(uint8_t);
    uint8_t* msg = (uint8_t*)malloc(sizeof(uint8_t)* size_arr);
    int i;
    for(i=0;i<size_arr;i++){
      msg[i] = arr[i];
    }
    printf("%d is the size of my array\n", size_arr);
    uint8_t* mem = (uint8_t*)malloc(sizeof(uint8_t) * size_arr);
    decryptMessage(arr,size_arr,key,size_key,mem);
    printf("%c", 0xf8);
    printMessage(arr, size_arr);
    printMessage(mem, size_arr);

}


void decryptMessage(const uint8_t* msg,int size_msg,const uint8_t* key,int size_key, uint8_t* mem){
  int i;
  int j = 0;
  //int size_msg = sizeof(msg) / sizeof(uint8_t);
  //int size_key = sizeof(key) / sizeof(uint8_t);
  printf("%d is the size of the message, %d is key size\n",size_msg, size_key);
  for(i=0;i<size_msg;i++){
    mem[i] = decryptValue(msg[i],key[i % size_key]);
  }

}
uint8_t decryptValue(uint8_t val, uint8_t key){
  return val ^ key;
}
void printMessage(uint8_t* msg, int length){
  //Serial.begin(9600);
  int i;
  //char str[10];
  for(i=0;i<length;i++){
    //sprintf(str,"%c",msg[i]);
    //Serial.print(str);
    printf("%c", msg[i]);
  }
  printf("\n");
  //Serial.println();
  return;
}
