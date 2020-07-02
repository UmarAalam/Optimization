
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<bitset>
#include<stdint.h>

#define SIZE_INT sizeof(int)*8

using namespace std;
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


int circularShift(unsigned n, int k, bool leftShift)
   {
       // left shift by k
       if (leftShift)
           return (n << k) | (n >> (SIZE_INT - k));
      else
       return 0;
   }


int main(){
    
    
    unsigned n=127;
    
    bitset<64> bset64(n);
    
    // bset64[1]=1;
    
    //1.divide plain text into 2 halves

    bitset<32> bset1;
    bitset<32> bset2;

    for(int i=31,k=0;(i>=0)&&(k<32);i--,k++)
    {
        bset1[k]=bset64[i];
   //     cout<<bset1[k];
    }
   
    
    for(int i=63,k=0;(i>=0)&&(k<32);i--,k++)
    {
        bset2[k]=bset64[i];
  //      cout<<bset2[k];
    }
    cout<<"bset1="<<bset1; //set1 32 bit
       cout<<endl;
    cout<<"bset2="<<bset2; //set2 32 bit
    cout<<endl;
  //  y = (bset1 << 2) | (x >> (8 - 2));
    bitset<32> s1=((bset1 << 1)|(bset1 >> (SIZE_INT - 1)));
    bitset<32> s8=((bset1 << 8)|(bset1 >> (SIZE_INT - 8)));
    bitset<32> s2=((bset1 << 2)|(bset1 >> (SIZE_INT - 2)));
    
    
    bitset<32> s1ands8=s1&s8;
    cout<<"s1="<<s1<<endl;
    cout<<"s1[0]="<<s1[1]<<endl;;
    cout<<"s8="<<s8<<endl;
    cout<<"s1ands8="<<s1ands8<<endl;
    cout<<"s2="<<s2<<endl;
    
    bitset<32> s1ands8exorbset2=s1ands8^bset2;
    
    cout<<"s1ands8exorbset2=="<<s1ands8exorbset2<<endl;
    
    bitset<32> s1ands8exorbset2exors2=s1ands8exorbset2^(s2);
    cout<<"s1ands8exorbset2exors2== "<<s1ands8exorbset2exors2<<endl;
    
    bitset<32> key(string("10101000000000000000000111100001"));  //assumed
    cout<<"key="<<key<<endl;
    
    
    bitset<32> s1ands8exorbset2exors2exorKEY=(s1ands8exorbset2exors2)^key;
    
    cout<<"(A')->s1ands8exorbset2exors2exorKEY="<<s1ands8exorbset2exors2exorKEY<<endl;
    cout<<"(B')->bset1="<<bset1<<endl;
    
    
    
    
    //Inplace of & --------->Use Majority logic

    
    
     unsigned char x, y, z,u, in;
     unsigned char op;
     unsigned char f11,f1,f2,f22,f3,f33,f12,f13;
     int t=0;
    
    
  //  printf("s1MAJ_ANDs8=");
    for(int i=31;i>=0;i--){
    x=s1[i];
    y=s8[i];
    f1=maj(&op,x,y,0);
 //   printf("%x",f1);
    
        
    
    //Inplace of Exor ----------->Use  Minority logic
    
    
    //s1ands8 MIN_EXOR bset2
    
    
   f11= min(&op,min(&op,!f1,bset2[i],0),min(&op,f1,!(bset2[i]),0),0);
   // printf("%x",f11);
        
        //f11 MIN_EXOR s2
        
   f12= min(&op,min(&op,!f11,s2[i],0),min(&op,f11,!(s2[i]),0),0);
//   printf("%x",f12);
        
        
        
        //f12 MIN_EXOR key
        f13=min(&op,min(&op,!f12,key[i],0),min(&op,f12,!key[i],0),0);
      
           printf("%x",f13);
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//   cout<<((bitset<64>(n) << 3) | (bitset<64>(n) >> (SIZE_INT - 3)));
  // bitset<64>((n<< 3)|((n)>>(SIZE_INT-3)));
    
  //  cout<<bitset<64>((n<< 3)|((n)>>(SIZE_INT-3)));
 //   unsigned s1=((n<< 1)|((n)>>(SIZE_INT-1)));
//    unsigned s8=((n<< 8)|((n)>>(SIZE_INT-8)));
//    unsigned s2=((n<< 2)|((n)>>(SIZE_INT-2)));
//
 //   cout<<bitset<64>(i);
      
      
      return 0;
}

