// Verilog
// c17
// Ninputs 5
// Noutputs 2
// NtotalGates 6
// NAND2 6
#include<stdio.h>
#include<stdlib.h>

void nand(unsigned char *op, unsigned char in1, unsigned char in2){

   *op = (in1 & in2)^0x01;

   return;
}

unsigned char min(unsigned char *op, unsigned char x, unsigned char y, unsigned char z){
   unsigned char temp;
   temp = (x&y)|(y&z)|(z&x);
   *op = temp ^ 0x01;
    return *op;
}

//use min as NAND

unsigned char minNAND(unsigned char *op, unsigned char x, unsigned char y){
   unsigned char temp;
    unsigned char z='0';
   temp = (x&y)|(y&z)|(z&x);
   *op = temp ^ 0x01;
    return *op;
}

void c17 (unsigned char N1,unsigned char N2,unsigned char N3,unsigned char N6,unsigned char N7,unsigned char *N22,unsigned char *N23){
//input N1,N2,N3,N6,N7;

//output N22,N23;

unsigned char N10,N11,N16,N19;

//nand(&N10, N1, N3);
//nand(&N11, N3, N6);
//nand(&N16, N2, N11);
//nand(&N19, N11, N7);
//nand(N22, N10, N16);
//nand(N23, N16, N19);
    
    minNAND(&N10, N1, N3);
    minNAND(&N11, N3, N6);
    minNAND(&N16, N2, N11);
    minNAND(&N19, N11, N7);
    minNAND(N22, N10, N16);
    minNAND(N23, N16, N19);
    
return;
}

int main(){
    
    unsigned char in, n1, n2, n3, n6, n7, n22, n23;
    
   for(in=0x00; in<0x20; in++){
      n1 = (in & (1<<0))>>0;
      n2 = (in & (1<<1))>>1;
      n3 = (in & (1<<2))>>2;
      n6 = (in & (1<<3))>>3;
      n7 = (in & (1<<4))>>4;
    c17(n1, n2, n3, n6, n7, &n22, &n23);
       
    printf("\n in: %01x, n1: %01x, n2: %01x, n3: %01x, n6: %01x, n7: %01x, n22: %01x, n23: %01x",in,n1,n2,n3,n6,n7,n22,n23);
   }
   printf("\n");
    return 0;
}
