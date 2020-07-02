#include<stdio.h>
#include<iostream>
#include<bitset>

using namespace std;

char c = 0,c11;

char halfadd( char x, char y ){
    c= x & y;
    printf("\nx=%d,y=%d",x,y);
    printf("\ns=%x",x^y);
    printf("\nc=%x",x&y);
    return x ^ y;
}

char fulladd( char x, char y ){
    printf("\nx=%d,y=%d",x,y);
    
    char sum=x^y^c;
    
    c=(x&y)|(y&c)|(x&c);
    
    printf("\nsum=%x",sum);
    printf("\nc=%x",c);
    return sum;
}

int twoinputor(int c1,int c2)
{
    int oroutput=c1|c2;
       cout<<"\noroutput="<<oroutput;
    return oroutput;
}


int adder(bitset<8> A,bitset<8> B)
{
    int r = 0;
      char tmp = halfadd( A[0], B[0] );
      r = tmp;
    c11=c;
    //store each sum and carry and apply operation
    printf("tmp=%x",tmp);
    
    
      int i;
      for( i = 1; i <8;i++ ){
          //printf("\nx=%d,y=%d",A[i],B[i]);
          cout<<"\nA[i]= "<<A[i];
          cout<<"B[i]="<<B[i]<<endl;
          tmp = fulladd(A[i],B[i]);
          c11=c;
        //  cout<<"\ntmp="<<tmp;
          printf("\ni=%d",i);
          printf("\ntmp=%x",tmp);
          printf("\ntmp<<i=%d",tmp<<i);
          r+=tmp<<i;
         printf("\nsum=%d",r);
        // printf("\nc=%x",c);
      }
    return r;
}



int main(){
    
    bitset<8> A(250);
    bitset<8> B(250);
    
   int r1= adder(A,B);
    
    
    
    //************o/p of Adder A**************//
    
//
//
//    printf("\nsum1=%d",r1);
//    printf("\nc1=%x",c);
//    int c1=c;
////
//
//    //here modulus=2^8
//    //k=floor(logm)+1 -------> k=9
//
//    //2 input for Adder B
//    //i/p 1 -------> o/p of prev adder, i/p 2 --------> 2^k -m i.e 2^9 - 256 = 256
//
//    bitset<8> C(r1);
//    bitset<8> D(10);
//
//    cout<<"\nC="<<C;
//    cout<<"\nD="<<D;
//    int r2= adder(C,D);
//
//
//
//    int c22=c;
//        printf("\nsum2=%d",r2);
//        printf("\nc2=%x",c);
    
    // ORing of 2 carry of Adder A and Adder B----------> c1+c2
//    int oroutput=c1|c2;
//    cout<<"\noroutput="<<oroutput;
//
    
    
    //Apply MUX
    
//    char select=oroutput,x;
//    int *a[100];
//    for(int i=0;i<8;i++)
//    {
////        a[i]=((!select)&x)|((select)&x);
//    }
//
//
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

