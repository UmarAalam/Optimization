#include<stdio.h>
#include<iostream>
#include<bitset>

using namespace std;

char c = 0,c1,c2;

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

int mux(char s,char x,char y)
{
 
    return ((!s)&x)|(s&y);
}


int adder(bitset<8> A,bitset<8> B)
{
    int r1 = 0;
    int m[100];
      char tmp1 = halfadd( A[0], B[0] );
      r1 = tmp1;
     c1=c;
    
    //store each sum and carry and apply operation
    int r2=0;
    char tmp2=halfadd(tmp1,0);
    c2=c;
    int s=c1|c2;
    
    m[0]=mux(s,tmp1,tmp2);
    printf("\nm=%d",m[0]);
    

      int i,k,r=0;
      for( i = 1,k=1; (i<8)&&(k<8);i++,k++){
          //printf("\nx=%d,y=%d",A[i],B[i]);
          cout<<"\nA[i]= "<<A[i];
          cout<<"B[i]="<<B[i]<<endl;
          tmp1 = fulladd(A[i],B[i]);
          c1=c;
          tmp2= fulladd(tmp1,1);
          c2=c;
          int s=c1|c2;
          m[k]=mux(s,tmp1,tmp2);
        //  cout<<"\ntmp="<<tmp;
          
          printf("\ni=%d",i);
          printf("\ntmp=%x",tmp);
          printf("\ntmp<<i=%d",tmp<<i);
          r+=tmp<<i;
         printf("\nsum=%d",r);
        // printf("\nc=%x",c);
      }
    return 0;
}

int main(){
    
    bitset<8> A(4);
    bitset<8> B(3);
    
    int r1= adder(A,B);
    
    //************o/p of Adder A**************//
    
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
//
//    // ORing of 2 carry of Adder A and Adder B----------> c1+c2
////    int oroutput=c1|c2;
////    cout<<"\noroutput="<<oroutput;
////
//
//
//
    
    return 0;
}
