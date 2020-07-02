#include<stdio.h>
#include<stdlib.h>
#include<iostream>

typedef char bit;

bit carry = 0;
bit halfadd( bit A, bit B ){
    carry = A & B;
    return A ^ B;
}

bit fulladd( bit A, bit B ){
    bit c = A ^ B;
    bit ret = carry ^ c;
    carry = (carry & c) | (A & B);
    return ret;
}

void fillNum( int num, bit *array ){
    int i;
    for( i = 0; i < 8; ++ i ){
        array[i] = ( num >> i ) & 1;
        printf("%d ",array[i]);
    }}

int main(){
    bit num1[8] = {0}, num2[8] = {0};
    int A = 15, B = 10;
    fillNum( A, num1 );
    printf("\n");
    fillNum( B, num2 );
     printf("\n");
    
    int r = 0;
    bit tmp = halfadd( num1[0], num2[0] );
    putchar( tmp ? '1' : '0' );
    r = tmp;
    int i;
    for( i = 1; i < 8; ++i ){
        tmp = fulladd( num1[i], num2[i] );
        r += tmp << i;
        putchar( tmp ? '1' : '0' );
    }
    putchar( carry ? '1' : '0' );
    printf("\n%d\n\n%d + %d = %d", r, A, B, A+B);
    return 0;
}
