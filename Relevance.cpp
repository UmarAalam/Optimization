#include<stdio.h>
#include<stdlib.h>

unsigned char maj(unsigned char *op, unsigned char x, unsigned char y, unsigned char z){
   *op = (x&y)|(y&z)|(z&x);
    return *op;
}

unsigned char min(unsigned char *op, unsigned char x, unsigned char y, unsigned char z){
   unsigned char temp;
   temp = (x&y)|(y&z)|(z&x);
   *op = temp ^ 0x01;
    return *op;
}

int main(){

  unsigned char x, y, z,u, in;
  unsigned char op;
  unsigned char f11,f1,f2,f22,f3,f33,f111,f222,f333;
    int t=0;
  for(in=0x00; in<=0x0F; in++){
     x = (in & (1<<0))>> 0;
     y = (in & (1<<1))>> 1;
     z = (in & (1<<2))>> 2;
     u = (in & (1<<3))>> 3;

//C-I when bottom,top x,y as input variable
      
          f1=min(&op, !y, y, z);
          f11=min(&op,u,!z,f1);
          f111=min(&op,x,y,f11);
          printf("\nu=%x, z=%x, y=%x, x=%x----> %x",u,z,y,x,f111);
      
            f2=min(&op, x, y, z);
//            f22=min(&op,!u,!x,f2);
//            f222=!f22;
     //     printf("\nz=%x, y=%x, x=%x----> %x",z,y,x,f2);
      
             f3=min(&op, u, y, z);
             f33=min(&op,!x,u,f3);
   //   f333=!f33;

    //   printf("\nu=%x, z=%x, y=%x, x=%x----> %x",u,z,y,x,f33);
            if(f111==f2)
            {
                t++;
            }
        }
          if(t==16)
          {
             printf("equivalent\n");
          }
          else
             printf("ne\n");
  
    
  printf("\n");
   return 0;
}

