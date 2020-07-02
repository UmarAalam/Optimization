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
      unsigned char r1,r2,r3,r4,r5,r6,r7;
    int t=0;
  for(in=0x00; in<0x08; in++){
     x = (in & (1<<0))>> 0;
     y = (in & (1<<1))>> 1;
     z = (in & (1<<2))>> 2;

      //x^y^z
      r1=maj(&op,maj(&op,y,0,!x),1,maj(&op,x,0,!y));
      r2=maj(&op,maj(&op,z,0,!r1),1,maj(&op,r1,0,!z));
             
      r3=maj(&op,maj(&op,z,!x,y),x,maj(&op,!y,!x,!z));
//      if(r2==r3)
//      {
//          t++;
//      }
//
      //x^y^z in min
      r4=min(&op,min(&op,!y,1,x),1,min(&op,!x,1,y));
      r5=min(&op,min(&op,z,0,r4),0,min(&op,!r4,0,!z));
      
      //check1
      r6=min(&op,min(&op,z,x,!y),x,min(&op,y,x,y^z));
      
      //check 2old substn formula set
  //    r7=min(&op,min(&op,!z,!x,y),!x,min(&op,!y,!x,z));
      
      //newcheck 3
      r7=min(&op,min(&op,z,x,!y),x,min(&op,y,x,!z));
      
      if(r5==r7)
            {
                t++;
            }
  }
//
//
////2.To check Associative law in minority gate
//    //1.complement majority logic--->minority logic,inverter propagation
//
//         f1=min(&op, u, y, z);
//            f11=min(&op,!x,!u,f1);
//        //    f111=!f11;
//          printf("\nu=%x, z=%x, y=%x, x=%x----> %x",u,z,y,x,f11);
//
//            f2=min(&op, u, y, x);
//            f22=min(&op,!z,!u,f2);
//     // f222=!f22;
//          printf("\nu=%x, z=%x, y=%x, x=%x----> %x",u,z,y,x,f22);
//
//             f3=min(&op, u, x, z);
//            f33=min(&op,!y,!u,f3);
//   //   f333=!f33;
//
//       printf("\nu=%x, z=%x, y=%x, x=%x----> %x",u,z,y,x,f33);
//
//            if((f11==f22)&&(f11==f33))
//            {
//                t++;
//            }
        
          if(t==8)
          {
             printf("equivalent\n");
          }
          else
             printf("ne\n");
    
  printf("\n");
   return 0;
}

