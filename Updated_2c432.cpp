// Verilog
// c432
// Ninputs 36
// Noutputs 7
// NtotalGates 160
// NOT1 40
// NAND2 64
// NOR2 19
// AND9 3
// XOR2 18
// NAND4 14
// AND8 1
// NAND3 1
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
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

//*************Not gate********************************//
unsigned char NOT(unsigned char *op, unsigned char in1){
     *op = in1 ^ 0x01;
     return *op;
}

//********************** not gate replaced with -------------> Minority logic
unsigned char notMIN(unsigned char *op, unsigned char in1)
{
    unsigned char t;
    t=min(op,in1,in1,in1);
    return t;
}

//*********************** nand2 gate  *******************//
void nand2(unsigned char *op, unsigned char in1, unsigned char in2){
     *op = (in1 & in2) ^ 0x01;
     return;
}

//*********************** nand2 replaced with ------> nand2MAJ Using Majority  logic ***************************************//
unsigned char nand2MAJ(unsigned char *op, unsigned char in1, unsigned char in2)
{
     unsigned char t;
    t=maj(op,in1,in2,'0');
    t=NOT(op,t);  //additional not gate
    return t;
}

//*********************** nand2 replaced with ------> nand2MIN Using Minority logic ***************************************//
unsigned char nand2MIN(unsigned char *op, unsigned char in1, unsigned char in2)
{
    unsigned char temp;
    temp=min(op,in1,in2,'0');
    return temp;
    
}

void and2(unsigned char *op, unsigned char in1, unsigned char in2){
     *op = (in1 & in2);
     return;
}

//********and2 replaced with -------> and2MAJ Majority logic
unsigned char and2MAJ(unsigned char *op, unsigned char in1, unsigned char in2)
{
     unsigned char t;
    t=maj(op,in1,in2,'0');
    return t;
}

//********and2 replaced with -------> and2MIN Minority logic
unsigned char and2MIN(unsigned char *op, unsigned char in1, unsigned char in2)
{
    unsigned char t1,t2;
    t1=min(op,in1,in2,'0');
    t2=NOT(op,t1);
    return t2;
}

void nand3(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3){
     *op = (in1 & in2 & in3) ^ 0x01;
     return;
}

//****************nand3 replaced with ---------------> nand3 MAJORITY logic //
unsigned char nand3MAJ(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3)
{
    unsigned char t1;
    t1=maj(op,in1,in2,'0');
    t1=maj(op,t1,in3,'0');
    t1=NOT(op, t1);
    return t1;
}

//****************nand3 replaced with ---------------> nand3 MINORITY logic //

unsigned char nand3MIN(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3)
{
    unsigned char t1;
    t1=min(op,in1,in2,'0');
    t1=NOT(op,t1);
    t1=min(op,t1,in3,'0');
    return t1;
}

void nand4(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4){
     *op = (in1 & in2 & in3 & in4) ^ 0x01;
     return;
}

//****************nand4 replaced with ---------------> nand4 MAJORITY logic //
unsigned char nand4MAJ(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3,unsigned char in4)
{
    unsigned char t1;
    t1=maj(op,in1,in2,'0');
    t1=maj(op,t1,in3,'0');
    t1=maj(op,t1,in4,'0');
    t1=NOT(op, t1);
    return t1;
}

//****************nand4 replaced with ---------------> nand4 MINORITY logic //
unsigned char nand4MIN(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3,unsigned char in4)
{
    unsigned char temp;
    temp=min(op,in1,in2,'0');
    temp=NOT(op,temp);
    temp=min(op,temp,in3,'0');
    temp=NOT(op,temp);
    temp=min(op,temp,in4,'0');
    return temp;
}

void xor2(unsigned char *op, unsigned char in1, unsigned char in2){
     *op = (in1 ^ in2);
     return;
}

//******************xor2 replaced with --------------->xor2MAJ Majority logic ************************//
unsigned char XOR2MAJ(unsigned char *op, unsigned char in1, unsigned char in2)
{
    unsigned char t1,t2,f1,f2,f;
    t1=NOT(op, in1);
    f1=maj(op,t1,in2,'0');
    t2=NOT(op, in2);
    f2=maj(op,in1,t2,'0');
    f=maj(op,f1,f2,'1');
    return f;
}


//******************xor2 replaced with --------------->xor2MIN Minority logic ************************//
unsigned char XOR2MIN(unsigned char *op, unsigned char in1, unsigned char in2)
{
    unsigned char t1,t2,f1,f2,f;
    t1=NOT(op,in1);
    f1=min(op,t1,in2,'0');
    t2=NOT(op,in2);
    f2=min(op,in1,t2,'0');
    f=min(op,f1,f2,'0');
    return f;
}

void and8(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8){
     *op = (in1 & in2 & in3 & in4 & in5 & in6 & in7 & in8);
     return;
}

//*********************** and8 replaced with ------> and8MAJ Using Majority  logic ***************************************//
unsigned char and8MAJ(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8)
{
    unsigned char op1;
    op1=maj(op,in1,in2,'0');
     op1=maj(op,op1,in3,'0');
    op1=maj(op,op1,in4,'0');
       op1=maj(op,op1,in5,'0');
          op1=maj(op,op1,in6,'0');
             op1=maj(op,op1,in7,'0');
                op1=maj(op,op1,in8,'0');
    return op1;
}

//***************************** and8 replaced with ---------------> and8MIN using Minority logic *********************//
unsigned char and8MIN(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8)
{
    unsigned char op1;
    op1=min(op,in1,in2,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in3,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in4,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in5,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in6,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in7,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in8,'0');
    op1=NOT(op,op1);
    return op1;
}

void and9(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8, unsigned char in9){
     *op = (in1 & in2 & in3 & in4 & in5 & in6 & in7 & in8 & in9);
     return;
}

//*********************** and9 replaced with ------> and9MAJ Using Majority  logic ***************************************//
unsigned char and9MAJ(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8, unsigned char in9)
{
    unsigned char op1;
    op1=maj(op,in1,in2,'0');
     op1=maj(op,op1,in3,'0');
    op1=maj(op,op1,in4,'0');
       op1=maj(op,op1,in5,'0');
          op1=maj(op,op1,in6,'0');
             op1=maj(op,op1,in7,'0');
                op1=maj(op,op1,in8,'0');
                   op1=maj(op,op1,in9,'0');
    return op1;
}


//***************************** and9 replaced with ---------------> and9MIN using Minority logic *********************//
unsigned char and9MIN(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8, unsigned char in9)
{
    unsigned char op1;
    op1=min(op,in1,in2,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in3,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in4,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in5,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in6,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in7,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in8,'0');
    op1=NOT(op,op1);
    
    op1=min(op,op1,in9,'0');
    op1=NOT(op,op1);
    return op1;
}


void nor2(unsigned char *op, unsigned char in1, unsigned char in2){
     *op =(in1 | in2) ^ 0x01;
     return;
}

//**************************nor2 replaced with -------------------->nor2MAJ Majority logic
unsigned char nor2MAJ(unsigned char *op, unsigned char in1, unsigned char in2)
{
    unsigned char t1,t2,f;
    t1=NOT(op, in1);
    t2=NOT(op, in2);
    f=maj(op,t1,t2,'0');
    return f;
}

//**************************nor2 replaced with -------------------->nor2MIN Minority logic
unsigned char nor2MIN(unsigned char *op, unsigned char in1, unsigned char in2)
{
    unsigned char t1,t2,t,f;
    t1=NOT(op, in1);
    t2=NOT(op, in2);
    f=min(op,t1,t2,'0');
    f=NOT(op, f);
    return f;
}


void c432(unsigned char N1,unsigned char N4,unsigned char N8,unsigned char N11,unsigned char N14,unsigned char N17,unsigned char N21,unsigned char N24,unsigned char N27,unsigned char N30,
          unsigned char N34, unsigned char N37,unsigned char N40,unsigned char N43,unsigned char N47,unsigned char N50,unsigned char N53,unsigned char N56,unsigned char N60,unsigned char N63,
          unsigned char N66, unsigned char N69,unsigned char N73,unsigned char N76,unsigned char N79,unsigned char N82,unsigned char N86,unsigned char N89,unsigned char N92,unsigned char N95,
             unsigned char N99,unsigned char N102,unsigned char N105,unsigned char N108,unsigned char N112,unsigned char N115,unsigned char N223,unsigned char N329,unsigned char N370,unsigned char N421,
             unsigned char N430,unsigned char N431,unsigned char N432){
    
//input N1,N4,N8,N11,N14,N17,N21,N24,N27,N30,
//      N34,N37,N40,N43,N47,N50,N53,N56,N60,N63,
//      N66,N69,N73,N76,N79,N82,N86,N89,N92,N95,
//      N99,N102,N105,N108,N112,N115;

//output N223,N329,N370,
    //N421
    //N430;//N431;
    //N432;
    
unsigned char N118,N119,N122,N123,N126,N127,N130,N131,N134,N135,
     N138,N139,N142,N143,N146,N147,N150,N151,N154,N157,
     N158,N159,N162,N165,N168,N171,N174,N177,N180,N183,
     N184,N185,N186,N187,N188,N189,N190,N191,N192,N193,
     N194,N195,N196,N197,N198,N199,N203,N213,N224,N227,
     N230,N233,N236,N239,N242,N243,N246,N247,N250,N251,
     N254,N255,N256,N257,N258,N259,N260,N263,N264,N267,
     N270,N273,N276,N279,N282,N285,N288,N289,N290,N291,
     N292,N293,N294,N295,N296,N300,N301,N302,N303,N304,
     N305,N306,N307,N308,N309,N319,N330,N331,N332,N333,
     N334,N335,N336,N337,N338,N339,N340,N341,N342,N343,
     N344,N345,N346,N347,N348,N349,N350,N351,N352,N353,
     N354,N355,N356,N357,N360,N371,N372,N373,N374,N375,
     N376,N377,N378,N379,N380,N381,N386,N393,N399,N404,
     N407,N411,N414,N415,N416,N417,N418,N419,N420,N422,
     N425,N428,N429;

//not(N118, N1);
//not(N119, N4);
//not(N122, N11);
//not(N123, N17);
//not(N126, N24);
//not(N127, N30);
//not(N130, N37);
//not(N131, N43);
//not(N134, N50);
//not(N135, N56);
//not(N138, N63);
//not(N139, N69);
//not(N142, N76);
//not(N143, N82);
//not(N146, N89);
//not(N147, N95);
//not(N150, N102);
//not(N151, N108);
    
//nand2(N154, N118, N4);
    
//nor2(N157, N8, N119);
    
//nor2(N158, N14, N119);
    
//nand2(N159, N122, N17);
    
//nand2(N162, N126, N30);
    
//nand2(N165, N130, N43);
    
//nand2(N168, N134, N56);
    
//nand2(N171, N138, N69);
    
//nand2(N174, N142, N82);
    
//nand2(N177, N146, N95);
    
//nand2(N180, N150, N108);
    
//nor2(N183, N21, N123);
    
//nor2(N184, N27, N123);
    
//nor2(N185, N34, N127);
    
//nor2(N186, N40, N127);
    
//nor2(N187, N47, N131);
    
//nor2(N188, N53, N131);
    
//nor2(N189, N60, N135);
    
//nor2(N190, N66, N135);
    
//nor2(N191, N73, N139);
    
//nor2(N192, N79, N139);
    
//nor2(N193, N86, N143);
    
//nor2(N194, N92, N143);
    
//nor2(N195, N99, N147);
    
//nor2(N196, N105, N147);
    
//nor2(N197, N112, N151);
    
//nor2(N198, N115, N151);
    
//and9(N199, N154, N159, N162, N165, N168, N171, N174, N177, N180);
//not(N203, N199);
//not(N213, N199);
//not(N223, N199);
    
//xor2(N224, N203, N154);
    
//xor2(N227, N203, N159);
    
//xor2(N230, N203, N162);
    
//xor2(N233, N203, N165);
    
//xor2(N236, N203, N168);
    
//xor2(N239, N203, N171);
    
//nand2(N242, N1, N213);
    
//xor2(N243, N203, N174);
    
//nand2(N246, N213, N11);
    
//xor2(N247, N203, N177);
    
//nand2(N250, N213, N24);
    
//xor2(N251, N203, N180);
    
//nand2(N254, N213, N37);
    
    
//nand2(N255, N213, N50);
    
    
//nand2(N256, N213, N63);
    
//nand2(N257, N213, N76);
    
//nand2(N258, N213, N89);
    
//nand2(N259, N213, N102);
    
//nand2(N260, N224, N157);
    
//nand2(N263, N224, N158);
    
//nand2(N264, N227, N183);
    
//nand2(N267, N230, N185);
    
//nand2(N270, N233, N187);
    
//nand2(N273, N236, N189);
    
//nand2(N276, N239, N191);
    
//nand2(N279, N243, N193);
    
//nand2(N282, N247, N195);
    
//nand2(N285, N251, N197);
    
//nand2(N288, N227, N184);
    
//nand2(N289, N230, N186);
    
//nand2(N290, N233, N188);
    
//nand2(N291, N236, N190);
//nand2(N292, N239, N192);
    
//nand2(N293, N243, N194);
    
//nand2(N294, N247, N196);
    
//nand2(N295, N251, N198);
    
//and9(N296, N260, N264, N267, N270, N273, N276, N279, N282, N285);
    
//not(N300, N263);
//not(N301, N288);
//not(N302, N289);
//not(N303, N290);
//not(N304, N291);
//not(N305, N292);
//not(N306, N293);
//not(N307, N294);
//not(N308, N295);
//not(N309, N296);
    
//not(N319, N296);
    
//not(N329, N296);
//xor2(N330, N309, N260);
    
//xor2(N331, N309, N264);
    
//xor2(N332, N309, N267);
    
//xor2(N333, N309, N270);
    
//nand2(N334, N8, N319);
    
//xor2(N335, N309, N273);
    
//nand2(N336, N319, N21);
    
//xor2(N337, N309, N276);
    
//nand2(N338, N319, N34);
    
//xor2(N339, N309, N279);
    
//nand2(N340, N319, N47);
    
//xor2(N341, N309, N282);
    
//nand2(N342, N319, N60);
    
//xor2(N343, N309, N285);
    
//nand2(N344, N319, N73);
    
//nand2(N345, N319, N86);
    
//nand2(N346, N319, N99);
    
//nand2(N347, N319, N112);
    
//nand2(N348, N330, N300);
//nand2(N349, N331, N301);
//nand2(N350, N332, N302);
//nand2(N351, N333, N303);
//nand2(N352, N335, N304);
    
//nand2(N353, N337, N305);
    
//nand2(N354, N339, N306);
//nand2(N355, N341, N307);
//nand2(N356, N343, N308);
    
//and9(N357, N348, N349, N350, N351, N352, N353, N354, N355, N356);
    
//not(N360, N357);
    
//not(N370, N357);
//nand2(N371, N14, N360);
    
//nand2(N372, N360, N27);
    
//nand2(N373, N360, N40);
    
//nand2(N374, N360, N53);
    
//nand2(N375, N360, N66);
    
//nand2(N376, N360, N79);
    
//nand2(N377, N360, N92);
    
//nand2(N378, N360, N105);
    
//nand2(N379, N360, N115);
    
//nand4(N380, N4, N242, N334, N371);
    
//nand4(N381, N246, N336, N372, N17);
    
//nand4(N386, N250, N338, N373, N30);
    
    
//nand4(N393, N254, N340, N374, N43);
    
    
//nand4(N399, N255, N342, N375, N56);
    
    
//nand4(N404, N256, N344, N376, N69);
    
//nand4(N407, N257, N345, N377, N82);
    
//nand4(N411, N258, N346, N378, N95);
    
//nand4(N414, N259, N347, N379, N108);
//not(N415, N380);
//and8(N416, N381, N386, N393, N399, N404, N407, N411, N414);
//not(N417, N393);
    
//not(N418, N404);
    
//not(N419, N407);
    
//not(N420, N411);
//nor2(N421, N415, N416);
    
//nand2(N422, N386, N417);
    
//nand4(N425, N386, N393, N418, N399);
    
//nand3(N428, N399, N393, N419);
    
//nand4(N429, N386, N393, N407, N420);
    
//nand4(N430, N381, N386, N422, N399);
    
//nand4(N431, N381, N386, N425, N428);
    
//nand4(N432, N381, N422, N425, N429);

}

//**************************Partition_1 Implementation using Majority and Minority logic***********************//
//Here Input=N1,N4,N11,N17,N24,N30,N37,N43,N50,N56,N163,N69,N76,N82,N89,N95,N102,N108
//output= N223
int main()
{
    
    //Cateogry 1: Majority +Inverter
    //Cateogry 2: Minority + Inverter
    //Cateogry 3: Majority + Minority + Inverter
    
    //*******************Cateogry 1: Majority +Inverter Implementation of partition7 *************************//
       
    unsigned char N118,N119,N122,N123,N126,N127,N130,N131,N134,N135,
    N138,N139,N142,N143,N146,N147,N150,N151,N154,N157,
    N158,N159,N162,N165,N168,N171,N174,N177,N180,N183,
    N184,N185,N186,N187,N188,N189,N190,N191,N192,N193,
    N194,N195,N196,N197,N198,N199,N203,N213,N224,N227,
    N230,N233,N236,N239,N242,N243,N246,N247,N250,N251,
    N254,N255,N256,N257,N258,N259,N260,N263,N264,N267,
    N270,N273,N276,N279,N282,N285,N288,N289,N290,N291,
    N292,N293,N294,N295,N296,N300,N301,N302,N303,N304,
    N305,N306,N307,N308,N309,N319,N330,N331,N332,N333,
    N334,N335,N336,N337,N338,N339,N340,N341,N342,N343,
    N344,N345,N346,N347,N348,N349,N350,N351,N352,N353,
    N354,N355,N356,N357,N360,N370,N371,N372,N373,N374,N375,
    N376,N377,N378,N379,N380,N381,N386,N393,N399,N404,
    N407,N411,N414,N415,N416,N417,N418,N419,N420,N422,
    N425,N428,N429;

    unsigned char op,f;

    //Input to partition1

    unsigned char N1=1;
    unsigned char N4=1;
    unsigned char N8=1;
    unsigned char N11=1;
    unsigned char N17=1;
    unsigned char N24=1;
    unsigned char N30=1;
    unsigned char N37=1;
    unsigned char N43=1;
    unsigned char N50=1;
    unsigned char N56=1;
    unsigned char N163=1;
    unsigned char N69=1;
    unsigned char N76=1;
    unsigned char N82=1;
    unsigned char N89=1;
    unsigned char N95=1;
    unsigned char N102=1;
    unsigned char N108=1;
    unsigned char N14=1;
    unsigned char N21=1;
    unsigned char N27=1;
    unsigned char N34=1;
    unsigned char N40=1;
    unsigned char N47=1;
    unsigned char N53=1;
    unsigned char N60=1;
    unsigned char N63=1;
    unsigned char N66=1;
    unsigned char N73=1;
    unsigned char N79=1;
    unsigned char N86=1;
    unsigned char N92=1;
    unsigned char N99=1;
    unsigned char N105=1;
    unsigned char N112=1;
    unsigned char N115=1;
        
    //implement "a" sub-partition
    
    N150=NOT(&op,N102);
    N180=nand2MAJ(&op,N150,N108);

    N146=NOT(&op,N89);
    N177=nand2MAJ(&op,N146,N95);

    N142=NOT(&op,N76);
    N174=nand2MAJ(&op,N142,N82);

    N138=NOT(&op,N163);
    N171=nand2MAJ(&op,N138,N69);

    N134=NOT(&op,N50);
    N168=nand2MAJ(&op,N134,N56);

    N130=NOT(&op,N37);
    N165=nand2MAJ(&op,N130,N43);

    N126=NOT(&op,N24);
    N162=nand2MAJ(&op,N126,N30);

    N122=NOT(&op,N11);
    N159=nand2MAJ(&op,N122,N17);

    N118=NOT(&op,N1);
    N154=nand2MAJ(&op,N118,N4);

  //  printf("\nN154=%x",N154);

//    //Partition4 implementation
//    N199=and9MAJ(&op,N154,N159,N162,N165,N168,N171,N174,N177,N180);
//    N203=NOT(&op,N199);
//    N118=NOT(&op,N1);
//    N154=nand2MAJ(&op,N118, N4);
//    N224=XOR2MAJ(&op, N203, N154);
//    N119=NOT(&op, N4);
//    N157=nor2MAJ(&op, N8, N119);
//    N260=nand2MAJ(&op, N224, N157);
//
//    N122=NOT(&op, N11);
//    N159=nand2MAJ(&op, N122, N17);
//    N227=XOR2MAJ(&op, N203, N159);
//    N123=NOT(&op, N17);
//    N183=nor2MAJ(&op, N21, N123);
//    N264=nand2MAJ(&op, N227, N183);
    
//    N126=NOT(&op, N24);
//    N162=nand2MAJ(&op, N126, N30);
//    N230=XOR2MAJ(&op, N203, N162);
//    N127=NOT(&op, N30);
//    N185=nor2MAJ(&op, N34, N127);
//    N267=nand2MAJ(&op, N230, N185);
    
    //***************************Partition3 Implementation***********************************//
    
    N199=and9MAJ(&op,N154,N159,N162,N165,N168,N171,N174,N177,N180);
    N203=NOT(&op,N199);
    N118=NOT(&op, N1);
    N154=nand2MAJ(&op, N4, N118);
    N224=XOR2MAJ(&op, N203, N154);
    N119=NOT(&op, N4);
    N157=nor2MAJ(&op, N8, N119);
    N260=nand2MAJ(&op, N224, N157);
    //here I need to use partition2 output.
    N118=NOT(&op, N1);
    N154=nand2MAJ(&op, N118, N4);
    N224=XOR2MAJ(&op, N203, N154);
    N119=NOT(&op, N4);
    N157=nor2MAJ(&op, N8, N119);
    N260=nand2MAJ(&op, N224, N157);
    
    N122=NOT(&op, N11);
    N159=nand2MAJ(&op, N122, N17);
    N227=XOR2MAJ(&op, N159, N203);
    N123=NOT(&op, N17);
    N183=nor2MAJ(&op, N21, N123);
    N264=nand2MAJ(&op, N227, N183);
    
    N126=NOT(&op, N24);
    N162=nand2MAJ(&op, N126, N30);
    N230=XOR2MAJ(&op, N162, N203);
    N127=NOT(&op, N30);
    N185=nor2MAJ(&op, N34, N127);
    N267=nand2MAJ(&op, N230, N185);
    
    N130=NOT(&op, N37);
    N165=nand2MAJ(&op, N130, N43);
    N233=XOR2MAJ(&op, N165, N203);
    N131=NOT(&op, N43);
    N187=nor2MAJ(&op, N47, N131);
    N270=nand2MAJ(&op, N233, N187);
   
    N134=NOT(&op, N50);
    N168=nand2MAJ(&op, N134, N56);
    N236=XOR2MAJ(&op, N168, N203);
    N135=NOT(&op, N56);
    N189=nor2MAJ(&op, N60, N135);
    N273=nand2MAJ(&op, N236, N189);
    
    N138=NOT(&op, N63);
    N171=nand2MAJ(&op, N138, N69);
    N239=XOR2MAJ(&op, N171, N203);
    N139=NOT(&op, N69);
    N191=nor2MAJ(&op, N73, N139);
    N276=nand2MAJ(&op, N239, N191);
    
    N142=NOT(&op, N76);
    N174=nand2MAJ(&op, N82, N142);
    N243=XOR2MAJ(&op, N174, N203);
    N143=NOT(&op, N82);
    N193=nor2MAJ(&op, N86, N143);
    N279=nand2MAJ(&op, N243, N193);
    N146=NOT(&op, N89);
    N177=nand2MAJ(&op, N146, N95);
    N247=XOR2MAJ(&op, N177, N203);
    N147=NOT(&op, N95);
    N195=nor2MAJ(&op, N99, N147);
    N282=nand2MAJ(&op, N247, N195);
    
    N150=NOT(&op, N102);
    N180=nand2MAJ(&op, N108, N150);
    N251=XOR2MAJ(&op, N180, N203);
    N151=NOT(&op, N108);
    N197=nor2MAJ(&op, N112, N151);
    N285=nand2MAJ(&op, N251, N197);
    
    N296=and9MAJ(&op, N260, N264, N267, N270, N273, N276, N279, N282, N285); //output of partition2
    
    //N296=1;
    
    N309=NOT(&op, N296);
    N330=XOR2MAJ(&op, N309, N260);
    N158=nor2MAJ(&op, N119, N14);
    N263=nand2MAJ(&op, N224, N158);
    N300=NOT(&op, N263);
    N348=nand2MAJ(&op, N330, N300);
    
    N123=NOT(&op, N17);
    N183=nor2MAJ(&op, N21, N123);
    N122=NOT(&op, N11);
    N159=nand2MAJ(&op, N122, N17);
    N227=XOR2MAJ(&op, N203, N159);
    N264=nand2MAJ(&op, N183, N227);
    N331=XOR2MAJ(&op, N264, N309);
    N184=nand2MAJ(&op, N27, N123);
    N288=nand2MAJ(&op, N184, N227);
    N301=NOT(&op, N288);
    N349=nand2MAJ(&op, N331, N301);
    
    N126=NOT(&op, N24);
    N162=nand2MAJ(&op, N126, N30);
    N230=XOR2MAJ(&op, N203, N162);
    N127=NOT(&op, N30);
    N185=nor2MAJ(&op, N34, N127);
    N267=nand2MAJ(&op, N230, N185);
    N332=XOR2MAJ(&op, N267, N309);
    N186=nor2MAJ(&op, N40, N127);
    N289=nand2MAJ(&op, N230, N186);
    N302=NOT(&op, N289);
    N350=nand2MAJ(&op, N332, N302);
    
    N130=NOT(&op, N37);
    N165=nand2MAJ(&op, N130, N43);
    N233=XOR2MAJ(&op, N203, N165);
    N131=NOT(&op, N43);
    N187=nor2MAJ(&op, N47, N131);
    N270=nand2MAJ(&op, N233, N187);
    N333=XOR2MAJ(&op, N270, N309);
    N131=NOT(&op, N43);
    N188=nor2MAJ(&op, N53, N131);
    N290=nand2MAJ(&op, N233, N188);
    N303=NOT(&op, N290);
    N351=nand2MAJ(&op, N333, N303);
    
    N134=NOT(&op, N50);
    N168=nand2MAJ(&op, N134, N56);
    N236=XOR2MAJ(&op, N203, N168);
    N135=NOT(&op, N56);
    N189=nor2MAJ(&op, N60, N135);
    N273=nand2MAJ(&op, N236, N189);
    N335=XOR2MAJ(&op, N273, N309);
    N190=nor2MAJ(&op, N66, N135);
    N291=nand2MAJ(&op, N190, N236);
    N304=NOT(&op, N291);
    N335=XOR2MAJ(&op, N273, N309);
    N352=nand2MAJ(&op, N335, N304);
    
    N138=NOT(&op, N63);
    N171=nand2MAJ(&op, N138, N69);
    N239=XOR2MAJ(&op, N203, N171);
    N139=NOT(&op, N69);
    N191=nor2MAJ(&op, N73, N139);
    N276=nand2MAJ(&op, N239, N191);
    N337=XOR2MAJ(&op, N276, N309);
    N192=nor2MAJ(&op, N79, N139);
    N292=nand2MAJ(&op, N239, N192);
    N305=NOT(&op, N292);
    N353=nand2MAJ(&op, N337, N305);
    
    N142=NOT(&op, N76);
    N174=nand2MAJ(&op, N142, N82);
    N243=XOR2MAJ(&op, N203, N174);
    N143=NOT(&op, N82);
    N193=nor2MAJ(&op, N86, N143);
    N279=nand2MAJ(&op, N243, N193);
    N339=XOR2MAJ(&op, N279, N309);
    N194=nor2MAJ(&op, N143, N92);
    N293=nand2MAJ(&op, N194, N243);
    N306=NOT(&op, N293);
    N354=nand2MAJ(&op, N339, N306);
    
    N146=NOT(&op, N89);
    N177=nand2MAJ(&op, N146, N95);
    N247=XOR2MAJ(&op, N177, N203);
    N147=NOT(&op, N95);
    N195=nor2MAJ(&op, N99, N147);
    N282=nand2MAJ(&op, N247, N195);
    N341=XOR2MAJ(&op, N282, N309);
    N147=NOT(&op,N95);
    N196=nor2MAJ(&op, N147, N105);
    N294=nand2MAJ(&op, N196, N247);
    N307=NOT(&op, N294);
    N355=nand2MAJ(&op, N341, N307);
    
    N150=NOT(&op, N102);
    N180=nand2MAJ(&op, N150, N108);
    N251=nand2MAJ(&op, N203, N180);
    N151=NOT(&op, N108);
    N197=nor2MAJ(&op, N112, N151);
    N285=nand2MAJ(&op, N251, N197);
    N343=XOR2MAJ(&op, N285, N309);
    N198=nor2MAJ(&op, N115, N151);
    N295=nand2MAJ(&op, N251, N198);
    N308=NOT(&op, N295);
    N356=nand2MAJ(&op, N343, N308);
    
    N357=and9MAJ(&op, N348, N349, N350, N351, N352, N353, N354, N355, N356);
    N370=NOT(&op, N357);
    
 //   printf("\nN357=%x ",N357);  //f ---------> final o/p
       
 //   printf("\nN370=%x ",N370);  //f ---------> final o/p
   
    // printf("\nN199=%x",N199);
   // f=NOT(&op,N199);
  //  printf("\nf=%x ",f);  //f ---------> final o/p
    
    //Testing of all the functions
    //1)NOT
    unsigned char a='1',b,c='1',d='1',e='1',r='1',g='1',h='1',i='1',j='1';
//    b=NOT(&op, a);
   // b=nand2MAJ(&op, a, c);
//    b=nand2MIN(&op, a, c);
  //  b=and2MAJ(&op, a, c);
 //   b=and2MIN(&op, a, c);
   // b=nand3MAJ(&op, a, c, d);
   // b=nand3MIN(&op, a, c, d);
   // b=nand4MAJ(&op, a, c, d, e);
  //  b=nand4MIN(&op, a, c, d, e);
//    b=XOR2MAJ(&op, a, c);
//    b=XOR2MIN(&op, a, c);
//    b=and8MAJ(&op, a, c, d, e, r, g, h, i, j);
//    b=and8MIN(&op, a, c, d, e, r, g, h, i);
 //   b=and9MAJ(&op, a, c, d, e, r, g, h, i, j);
//    b=and9MIN(&op, a, c, d, e, r, g, h, i, j);
//    b=nor2MAJ(&op, a, c);
//    b=nor2MIN(&op, a, c);
    b=nand2MIN(&op, a, c);
    printf("\na=%c",a);
    printf("\nc=%c",c);
    printf("\nd=%c",d);
    printf("\ne=%c",e);
    printf("\nf=%c\n",b);
    
    return 0;
}
