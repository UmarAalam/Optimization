#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<bitset>
using namespace std;

unsigned char min(unsigned char *op, unsigned char x, unsigned char y, unsigned char z){
unsigned char temp;
temp = (x&y)|(y&z)|(z&x);
*op = temp ^ 0x01;
 return *op;
}

void marx2(unsigned char *in, unsigned char *out){

   unsigned char t[4];
    unsigned char opr;

    //circular shift
  t[3] = (in[3]<<1)|(in[3]>>7);
  t[2] = (in[2]<<2)|(in[2]>>6);
  t[1] = (in[1]<<7)|(in[1]>>1);
  t[0] = (in[0]<<3)|(in[0]>>5);

    //modular addition
  out[3] = (t[3] + in[2])%(1<<8);
  out[1] = (t[1] + in[0])%(1<<8);
    
    //exor
    
//  out[2] = out[1] ^ t[0];
    
    // Inplace of EXOR  --------> Minority logic Used
    printf("\n******Inplace of EXOR in MARX-2 --------> Minority logic Used********\n");
    
    bitset<8> o1(out[1]);
    
   bitset<8> t1(t[0]);
    
   bitset<8> f1;
 
    unsigned char f11,f12,f13,f14,o1not,t1not;
 
    
    for(int i=7;i>=0;i--)
    {
        o1not=!o1[i];
        t1not=!t1[i];
        f11=min(&opr,o1not,t1[i],0);
//       printf("\nf11===%x",f11);
//         cout<<"\nf11="<<f11;
        f12=min(&opr,o1[i],t1not,0);
//       printf("\nf12===%x",f12);
            
//         cout<<"\nf12="<<f11;
        f1[i]=min(&opr,f11,f12,0);
//         cout<<"\nf13="<<f11;
//       printf("\n\t\tf13===%x",f13);
    }
     
 
    
    out[2]=f1.to_ulong();
// printf("\nout[2]=%x",out[2]);

    
 // out[0] = out[3] ^ t[2];
 
    
      bitset<8> o2(out[3]);
       
      bitset<8> t2(t[2]);
       
      bitset<8> f2;
    
       unsigned char f111,f112,o2not,t2not;
      
      for(int i=7;i>=0;i--)
        {
       //     f1[i]=o1[i]^t1[i];
            o2not=!o2[i];
            t2not=!t2[i];
            f111=min(&opr,o2not,t2[i],0);
        //    printf("\nf11===%x",f11);
            f112=min(&opr,o2[i],t2not,0);
          //  printf("\nf12===%x",f12);
                
            // cout<<"\nf12="<<f11;
            f2[i]=min(&opr,f111,f112,0);
      //     printf("\n\t\tf13===%x",f13);
          //  out[2]=f1[i];
        }
        out[0]=f2.to_ulong();
    //   printf("\nout[0]=%x",out[0]);
  return;
}


void speckey(unsigned int *in, unsigned int *out){
    
   unsigned int t[3];

   t[1] = ((in[1]<<7)|(in[1]>>9)) & 0xffff;
   t[0] = ((in[0]<<2)|(in[0]>>14)) & 0xffff;
   out[1] = (t[1] + in[0])%(1<<16);
    
    
  // out[0] = out[1] ^ t[0];

    // Inplace of EXOR  --------> Minority logic Used
    printf("\n***Inplace of EXOR in SPECKEY--------> Minority logic Used***\n");
    
    
  //  printf("\nout[0]=%x",out[0]);
    
    bitset<16> o3(out[1]);
    bitset<16> t3(t[0]);
    bitset<16> f3;
       
    unsigned char f1111,f1112,o3not,t3not,opr;
         
         for(int i=15;i>=0;i--)
           {
          //     f1[i]=o1[i]^t1[i];
               o3not=!o3[i];
               t3not=!t3[i];
               f1111=min(&opr,o3not,t3[i],0);
           //    printf("\nf11===%x",f11);
               f1112=min(&opr,o3[i],t3not,0);
             //  printf("\nf12===%x",f12);
                   
               // cout<<"\nf12="<<f11;
               f3[i]=min(&opr,f1111,f1112,0);
         //     printf("\n\t\tf13===%x",f13);
             //  out[2]=f1[i];
           }
           out[0]=f3.to_ulong();
   //       printf("\nout[0]=%x",out[0]);
    
   return;
}

int main(){

  unsigned char in_marx2[4], out_marx2[4]; // input, output of marx2: each input/output partition (in_marx[0]...in_marx[3]) is of 8 bits
  unsigned int in_speckey[2], out_speckey[2]; // input, output of speckey: each input/output partition (in_marx[0], in_marx[1]) is of 16 bits
  unsigned int x, i;
 
  srand(time(NULL));

  x = rand();
  //===================== Marx2 ===========================================

    //  printf("\nx>>8=%x",(x>>8)&(0xff));
  for(i=0; i<4; i++){
  in_marx2[i] = (x>>(8*i)) & 0xff;
//  printf("\nin_marx2[%d]=%08x",i,in_marx2[i]);
  }
  marx2(in_marx2, out_marx2);
  for(i=0; i<4; i++){
     printf("\nin_marx2[%d]=%02x, out_marx2[%d]=%02x",i,in_marx2[i],i,out_marx2[i]);
  }
   
  //===================== Speckey ===========================================

  printf("\n********************************\n");
  x = rand();
 // printf("x=%x",x);
  for(i=0; i<2; i++){
     in_speckey[i] = (x>>(16*i)) & 0xffff;
     //printf("\nspeckey[%d]=%04x",i,in_speckey[i]);
  }
  speckey(in_speckey, out_speckey);
  for(i=0; i<2; i++){
     printf("\nin_speckey[%d]=%04x, out_speckey[%d]=%04x",i,in_speckey[i],i,out_speckey[i]);
  }
   
  printf("\n");
  return 0;
}
