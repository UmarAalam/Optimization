#include<stdio.h>
#include<stdlib.h>

void maj(unsigned char *op, unsigned char x, unsigned char y, unsigned char z){
   *op = (x&y)|(y&z)|(z&x);
}

void min(unsigned char *op, unsigned char x, unsigned char y, unsigned char z){
   unsigned char temp;
   temp = (x&y)|(y&z)|(z&x);
   *op = temp ^ 0x01;
}


int main(){

  unsigned char x, y, z, in;
  unsigned char op;

  for(in=0x00; in<0x08; in++){
     x = (in & (1<<0))>> 0;
     y = (in & (1<<1))>> 1;
     z = (in & (1<<2))>> 2;

     maj(&op, x, y, z);
     printf("\nz=%x, y=%x, x=%x----> %x",z,y,x,op);
  }

  printf("\n");

   return 0;
}

