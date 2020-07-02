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

  unsigned char x, y, z,u,v, in;
  unsigned char op;
  unsigned char f11,f1,f2,f22,f3,f33;
    int t=0;
  for(in=0x00; in<=0x1F; in++){
     x = (in & (1<<0))>> 0;
     y = (in & (1<<1))>> 1;
     z = (in & (1<<2))>> 2;
     u = (in & (1<<3))>> 3;
     v = (in & (1<<4))>> 4;
      
           f1=min(&op, u, v, z);
            f11=min(&op,x,y,f1);
      
      //    printf("\nv=%x, u=%x, z=%x, y=%x, x=%x----> %x",v,u,z,y,x,f11);
      
      f2=min(&op, x, y, u);
      f3=min(&op,x,y,v);
      f33=min(&op,f2,f3,z);
      
           
     //     printf("\nv=%x, u=%x, z=%x, y=%x, x=%x----> %x",v,u,z,y,x,f33);
    
      if(f11==f33)
            {
                t++;
            }
        }
          if(t==32)
          {
             printf("equivalent\n");
          }
          else
             printf("ne\n");
    
  printf("\n");

   return 0;
}
