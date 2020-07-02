#include<stdio.h>
#include<stdlib.h>

FILE *log_file;

  unsigned char   n257, n258, n259, n260, n261, n262, n263, n264, n265, n266, n267,
         n268, n269, n270, n271, n272, n273, n274, n275, n276, n277, n278,
         n279, n280, n281, n282, n283, n284, n285, n286, n287, n288, n289,
         n290, n291, n292, n293, n294, n295, n296, n297, n298, n299, n300,
         n301, n302, n303, n304, n305, n306, n307, n308, n309, n310, n311,
         n312, n313, n314, n315, n316, n317, n318, n319, n320, n321, n322,
         n323, n324, n325, n326, n327, n328, n329, n330, n331, n332, n333,
         n334, n335, n336, n337, n338, n339, n340, n341, n342, n343, n344,
         n345, n346, n347, n348, n349, n350, n351, n352, n353, n354, n355,
         n356, n357, n358, n359, n360, n361, n362, n363, n364, n365, n366,
         n367, n368, n369, n370, n371, n372, n373, n374, n375, n376, n377,
         n378, n379, n380, n381, n382, n383, n384, n385, n386, n387, n388,
         n389, n390, n391, n392, n393, n394, n395, n396, n397, n398, n399,
         n400, n401, n402, n403, n404, n405, n406, n407, n408, n409, n410,
         n411, n412, n413, n414, n415, n416, n417, n418, n419, n420, n421,
         n422, n423, n424, n425, n426, n427, n428, n429, n430, n431, n432,
         n433, n434, n435, n436, n437, n438, n439, n440, n441, n442, n443,
         n444, n445, n446, n447, n448, n449, n450, n451, n452, n453, n454,
         n455, n456, n457;

   unsigned char G1355;
   
   unsigned char t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
   unsigned char keyinput21;

 unsigned char G1, G10, G11, G12, G13, G14, G15, G16, G17, G18, G19, G2, G20, G21,
         G22, G23, G24, G25, G26, G27, G28, G29, G3, G30, G31, G32, G33, G34,
         G35, G36, G37, G38, G39, G4, G40, G41, G5, G6, G7, G8, G9, keyinput0,
         keyinput1, keyinput2, keyinput3, keyinput4, keyinput5, keyinput6,
         keyinput7, keyinput8, keyinput9, keyinput10, keyinput11, keyinput12,
         keyinput13, keyinput14, keyinput15, keyinput16, keyinput17,
         keyinput18, keyinput19, keyinput20, keyinput21, keyinput22,
         keyinput23, keyinput24, keyinput25, keyinput26, keyinput27,
         keyinput28, keyinput29, keyinput30, keyinput31;

 unsigned char G1324, G1325, G1326, G1327, G1328, G1329, G1330, G1331, G1332, G1333,
         G1334, G1335, G1336, G1337, G1338, G1339, G1340, G1341, G1342, G1343,
         G1344, G1345, G1346, G1347, G1348, G1349, G1350, G1351, G1352, G1353,
         G1354, G1355;

// Logic gates -------------------------------------------------------------------------------------------

void nand(unsigned char *op, unsigned char in1, unsigned char in2){
     *op = (in1 & in2) ^ 0x01;
     return;
}

void nand3(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3){
     *op = (in1 & in2 & in3) ^ 0x01;
     return;
}

void and(unsigned char *op, unsigned char in1, unsigned char in2){
     *op = (in1 & in2);
     return;
}

void and3(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3){
     *op = (in1 & in2 & in3);
     return;
}

void and4(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4){
     *op = (in1 & in2 & in3 & in4);
     return;
}

void and5(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5){
     *op = (in1 & in2 & in3 & in4 & in5);
     return;
}

void or(unsigned char *op, unsigned char in1, unsigned char in2){
     *op = (in1 | in2);
     return;
}

void or3(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3){
     *op = (in1 | in2 | in3);
     return;
}

void or4(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4){
     *op = (in1 | in2 | in3 | in4);
     return;
}


void nor(unsigned char *op, unsigned char in1, unsigned char in2){
     *op = (in1 | in2) ^ 0x01;
     return;
}

void nor3(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3){
     *op = (in1 | in2 | in3) ^ 0x01;
     return;
}

void xor(unsigned char *op, unsigned char in1, unsigned char in2){
     *op = (in1 ^ in2);
     return;
}

void xor3(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3){
     *op = (in1 ^ in2 ^ in3);
     return;
}

void xnor(unsigned char *op, unsigned char in1, unsigned char in2){
     *op = (in1 ^ in2) ^ 0x01;
     return;
}

void xnor3(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char in3){
     *op = (in1 ^ in2 ^ in3) ^ 0x01;
     return;
}

void not(unsigned char *op, unsigned char in1){
     *op = in1 ^ 0x01;
     return;
}

void mux(unsigned char *op, unsigned char in1, unsigned char in2, unsigned char sel){

   if(sel==0x00) *op = in1;
   else if(sel==0x01) *op = in2;

   return;
}

void inv(unsigned char *op, unsigned char in){

   *op = in ^ 0x01;
   return;
}



// Partitions ----------------------------------------------------------------------------------------------

//============================= Partition 1 ==========================================================================================================================
void part1(){ // Input to key_In_0_0

  unsigned char lin_op;
  int in, lin_comb;
  int nin=10, nop=8, nmatch[8][1<<10], max_match[2];
  float pr_match;
  int i,j;

  for(i=0; i<nop; i++){// # outputs
     for(j=0; j<(1<<nin); j++){ // # linear combinations
        nmatch[i][j] = 0;
     }
  } 

  for(lin_comb=0x00; lin_comb<(1<<nin); lin_comb++){
     if((lin_comb%(1<<9))==0) {printf("\nlin_comb: %d",lin_comb); fflush(stdout);}
     for(in=0x00; in<(1<<nin); in++){
     
        n284 = (in & (1<<0)) >> 0;
        n334 = (in & (1<<1)) >> 1;
        n335 = (in & (1<<2)) >> 2;
        n336 = (in & (1<<3)) >> 3;
        n285 = (in & (1<<4)) >> 4;
        n277 = (in & (1<<5)) >> 5;
        n286 = (in & (1<<6)) >> 6;
        n403 = (in & (1<<7)) >> 7;
        keyinput21 = (in & (1<<8)) >> 8;
        G32 = (in & (1<<9)) >> 9;
     
        inv(&n267, n284);
        mux(&n297, n334, n335, n336);
        and3(&n268, n285, n277, n286);
        xor(&n266, n403, keyinput21);
        nand3(&n259, n266, n267, n268);
        inv(&n258, n297); 
        nor(&n257, n258, n259);
        xnor(&G1355, G32, n257);

        lin_op = 0x00;
        for(i=0; i<nin; i++) lin_op ^= (((lin_comb & (1<<i)) >> i) & ((in & (1<<i)) >> i));
        
        if(lin_op == G1355) nmatch[0][lin_comb]++;
        if(lin_op == n257) nmatch[1][(int)lin_comb]++;
        if(lin_op == n258) nmatch[2][(int)lin_comb]++;
        if(lin_op == n259) nmatch[3][(int)lin_comb]++;
        if(lin_op == n266) nmatch[4][(int)lin_comb]++;
        if(lin_op == n268) nmatch[5][(int)lin_comb]++;
        if(lin_op == n297) nmatch[6][(int)lin_comb]++;
        if(lin_op == n267) nmatch[7][(int)lin_comb]++;

     } // for all possible inputs in
  } // for all linear combinations

  for(i=0; i<nop; i++){ // for output number
      max_match[0] = 0;
      for(j=2; j<(1<<nin); j++){ // linear combination value
         if(nmatch[i][j]>=max_match[0]){
            max_match[0] = nmatch[i][j]; 
            pr_match = (float)nmatch[i][j]/(1<<nin); 
            max_match[1] = j;
         }
      }

      //fprintf(log_file,"\n******** Linear Approx Part 1 ********************************************************************\n");
      fprintf(log_file,"\nLinear Approx Part 1: For op %2d, max_match[0] (#count): %6d, Pr[match]:%1.3f, max_match[1](which lin_comb): %6d",i,max_match[0],pr_match,max_match[1]);
      //fprintf(log_file,"\n****************************************************************************\n");
  }

  return;
}
//============================= Partition 2 ==========================================================================================================================

void part2_1(){ // Input to key_In_0_0

  unsigned char lin_op;
  int in, lin_comb;
  int nin=14, nop=10, nmatch[10][1<<14], max_match[2];
  float pr_match;
  int i,j;

  for(i=0; i<nop; i++){// # outputs
     for(j=0; j<(1<<nin); j++){ // # linear combinations
        nmatch[i][j] = 0;
     }
  } 

  for(lin_comb=0x00; lin_comb<(1<<nin); lin_comb++){
     if((lin_comb%(1<<9))==0) {printf("\nlin_comb: %d",lin_comb); fflush(stdout);}
     for(in=0x00; in<(1<<nin); in++){
     
        G40 = (in & (1<<0)) >> 0;
        G41 = (in & (1<<1)) >> 1;
        n340 = (in & (1<<2)) >> 2;
        t1 = (in & (1<<3)) >> 3;
        n382 = (in & (1<<4)) >> 4;
        n381 = (in & (1<<5)) >> 5;
        n383 = (in & (1<<6)) >> 6;
        G12 = (in & (1<<7)) >> 7;
        G16 = (in & (1<<8)) >> 8;
        n397 = (in & (1<<9)) >> 9;
        n410 = (in & (1<<10)) >> 10;
        keyinput20 = (in & (1<<11)) >> 11;
        n406 = (in & (1<<12)) >> 12;
        keyinput19 = (in & (1<<13)) >> 13;

        //Inputs: G40, g41, n340, t1, n381, n382, n383, G12, G16, n397, n410, keyinput20, keyinput19,     n398, n399, n453, n454, n448, n298, n299, n300, n 295, n296, n297,
 
        //l6
        nand3(&n338, G40, G41, n340);
        or(&n339, n340, t1);
        nand(&n335, n339, n338);
        and(&n334, n338, n339);
        mux(&n274, n381, n382, n383);
        inv(&n285, n274);
        xor3(&n396, G12, G16, n397);
        xnor(&n404, n410, keyinput20);
        xnor(&n405, n406, keyinput19);
        nand(&n403, n404, n405);

        /*nand(&n395, n398, n399);
        and(&n394, n398, n399);
        and(&n448, n453, n454);
        inv(&n449, n448);
        or3(&n293, n298, n299, n300);
        or3(&n294, n295, n296, n297);*/

        //l5
        /*nand(&n277, n293, n294);
        inv(&n285, n274);
        mux(&n284, n448, n449, n450);
        nand(&n403, n404, n405);
        mux(&n286, n395, n394, n396);
        nand(&n335, n339, n338);
        and(&n334, n338, n339);*/
        
        lin_op = 0x00;
        for(i=0; i<nin; i++) lin_op ^= (((lin_comb & (1<<i)) >> i) & ((in & (1<<i)) >> i));
        
        if(lin_op == n338) nmatch[0][lin_comb]++;
        if(lin_op == n339) nmatch[1][(int)lin_comb]++;
        if(lin_op == n335) nmatch[2][(int)lin_comb]++;
        if(lin_op == n334) nmatch[3][(int)lin_comb]++;
        if(lin_op == n274) nmatch[4][(int)lin_comb]++;
        if(lin_op == n285) nmatch[5][(int)lin_comb]++;
        if(lin_op == n396) nmatch[6][(int)lin_comb]++;
        if(lin_op == n404) nmatch[7][(int)lin_comb]++;
        if(lin_op == n405) nmatch[8][(int)lin_comb]++;
        if(lin_op == n403) nmatch[9][(int)lin_comb]++;

     } // for all possible inputs in
  } // for all linear combinations

  for(i=0; i<nop; i++){ // for output number
      max_match[0] = 0;
      for(j=2; j<(1<<nin); j++){ // linear combination value
         if(nmatch[i][j]>=max_match[0]){
            max_match[0] = nmatch[i][j]; 
            pr_match = (float)nmatch[i][j]/(1<<nin); 
            max_match[1] = j;
         }
      }

      //fprintf(log_file,"\n******** Linear Approx Part 2_1 ********************************************************************\n");
      fprintf(log_file,"\nLinear Approx Part 2_1:  For op %2d, max_match[0] (#count): %6d, Pr[match]:%1.3f, max_match[1](which lin_comb): %6d",i,max_match[0],pr_match,max_match[1]);
  }

  return;
}

void part2_2(){ // Input to key_In_0_0

  unsigned char lin_op;
  int in, lin_comb;
  int nin=13, nop=9, nmatch[9][1<<13], max_match[2];
  float pr_match;
  int i,j;

  for(i=0; i<nop; i++){// # outputs
     for(j=0; j<(1<<nin); j++){ // # linear combinations
        nmatch[i][j] = 0;
     }
  } 

  for(lin_comb=0x00; lin_comb<(1<<nin); lin_comb++){
     if((lin_comb%(1<<9))==0) {printf("\nlin_comb: %d",lin_comb); fflush(stdout);}
     for(in=0x00; in<(1<<nin); in++){
     
        n398 = (in & (1<<0)) >> 0;
        n399 = (in & (1<<1)) >> 1;
        n396 = (in & (1<<2)) >> 2;
        n453 = (in & (1<<3)) >> 3;
        n454 = (in & (1<<4)) >> 4;
        n448 = (in & (1<<5)) >> 5;
        n450 = (in & (1<<6)) >> 6;
        n298 = (in & (1<<7)) >> 7;
        n299 = (in & (1<<8)) >> 8;
        n300 = (in & (1<<9)) >> 9;
        n295 = (in & (1<<10)) >> 10;
        n296 = (in & (1<<11)) >> 11;
        n297 = (in & (1<<12)) >> 12;

        nand(&n395, n398, n399);
        and(&n394, n398, n399);
        mux(&n286, n395, n394, n396);
        and(&n448, n453, n454);
        inv(&n449, n448);
        mux(&n284, n448, n449, n450);
        or3(&n293, n298, n299, n300);
        or3(&n294, n295, n296, n297);
        nand(&n277, n293, n294);
        
        lin_op = 0x00;
        for(i=0; i<nin; i++) lin_op ^= (((lin_comb & (1<<i)) >> i) & ((in & (1<<i)) >> i));
        
        if(lin_op == n395) nmatch[0][lin_comb]++;
        if(lin_op == n394) nmatch[1][(int)lin_comb]++;
        if(lin_op == n286) nmatch[2][(int)lin_comb]++;
        if(lin_op == n448) nmatch[3][(int)lin_comb]++;
        if(lin_op == n449) nmatch[4][(int)lin_comb]++;
        if(lin_op == n284) nmatch[5][(int)lin_comb]++;
        if(lin_op == n293) nmatch[6][(int)lin_comb]++;
        if(lin_op == n294) nmatch[7][(int)lin_comb]++;
        if(lin_op == n277) nmatch[8][(int)lin_comb]++;

     } // for all possible inputs in
  } // for all linear combinations

  for(i=0; i<nop; i++){ // for output number
      max_match[0] = 0;
      for(j=2; j<(1<<nin); j++){ // linear combination value
         if(nmatch[i][j]>=max_match[0]){
            max_match[0] = nmatch[i][j]; 
            pr_match = (float)nmatch[i][j]/(1<<nin); 
            max_match[1] = j;
         }
      }

      //fprintf(log_file,"\n******** Linear Approx Part 2_1 ********************************************************************\n");
      fprintf(log_file,"\nLinear Approx Part 2_2:  For op %2d, max_match[0] (#count): %6d, Pr[match]:%1.3f, max_match[1](which lin_comb): %6d",i,max_match[0],pr_match,max_match[1]);
  }

  return;
}


void part3_1(){ // Input to key_In_0_0

  unsigned char lin_op;
  int in, lin_comb;
  int nin=14, nop=9, nmatch[9][1<<14], max_match[2];
  float pr_match;
  int i,j;

  for(i=0; i<nop; i++){// # outputs
     for(j=0; j<(1<<nin); j++){ // # linear combinations
        nmatch[i][j] = 0;
     }
  } 

  printf("\npart3_1..........................................................................");
  for(lin_comb=0x00; lin_comb<(1<<nin); lin_comb++){
     if((lin_comb%(1<<9))==0) {printf("\nlin_comb: %d",lin_comb); fflush(stdout);}
     for(in=0x00; in<(1<<nin); in++){
     
        G13 = (in & (1<<0)) >> 0;
        G14 = (in & (1<<1)) >> 1;
        n353 = (in & (1<<2)) >> 2;
        n341 = (in & (1<<3)) >> 3;
        n342 = (in & (1<<4)) >> 4;
        n389 = (in & (1<<5)) >> 5;
        t4 = (in & (1<<6)) >> 6;
        G35 = (in & (1<<7)) >> 7;
        G41 = (in & (1<<8)) >> 8;
        n389 = (in & (1<<9)) >> 9;
        G15 = (in & (1<<10)) >> 10;
        G3 = (in & (1<<11)) >> 11;
        n386 = (in & (1<<12)) >> 12;
        G11 = (in & (1<<13)) >> 13;

        xnor3(&n341, G13, G14, n353);
        xnor(&n340, n341, n342);
        or(&n388, n389, t4);
        nand3(&n387, G35, G41, n389);
        nand(&n381, n388, n387);
        inv(&n382, n381);
        inv(&n384, G15);
        xnor(&n385, G3, n386);
        xnor3(&n383, n384, n385, G11);
        
        lin_op = 0x00;
        for(i=0; i<nin; i++) lin_op ^= (((lin_comb & (1<<i)) >> i) & ((in & (1<<i)) >> i));
        
        if(lin_op == n341) nmatch[0][lin_comb]++;
        if(lin_op == n340) nmatch[1][(int)lin_comb]++;
        if(lin_op == n388) nmatch[2][(int)lin_comb]++;
        if(lin_op == n387) nmatch[3][(int)lin_comb]++;
        if(lin_op == n381) nmatch[4][(int)lin_comb]++;
        if(lin_op == n382) nmatch[5][(int)lin_comb]++;
        if(lin_op == n384) nmatch[6][(int)lin_comb]++;
        if(lin_op == n385) nmatch[7][(int)lin_comb]++;
        if(lin_op == n383) nmatch[8][(int)lin_comb]++;

     } // for all possible inputs in
  } // for all linear combinations

  for(i=0; i<nop; i++){ // for output number
      max_match[0] = 0;
      for(j=2; j<(1<<nin); j++){ // linear combination value
         if(nmatch[i][j]>=max_match[0]){
            max_match[0] = nmatch[i][j]; 
            pr_match = (float)nmatch[i][j]/(1<<nin); 
            max_match[1] = j;
         }
      }

      //fprintf(log_file,"\n******** Linear Approx Part 2_1 ********************************************************************\n");
      fprintf(log_file,"\nLinear Approx Part 3_1:  For op %2d, max_match[0] (#count): %6d, Pr[match]:%1.3f, max_match[1](which lin_comb): %6d",i,max_match[0],pr_match,max_match[1]);
  }

  return;
}


void part3_2(){ // Input to key_In_0_0

  unsigned char lin_op;
  int in, lin_comb;
  int nin=15, nop=11, nmatch[11][1<<15], max_match[2];
  float pr_match;
  int i,j;

  for(i=0; i<nop; i++){// # outputs
     for(j=0; j<(1<<nin); j++){ // # linear combinations
        nmatch[i][j] = 0;
     }
  } 

  printf("\npart3_2..........................................................................");
  for(lin_comb=0x00; lin_comb<(1<<nin); lin_comb++){
     if((lin_comb%(1<<9))==0) {printf("\nlin_comb: %d",lin_comb); fflush(stdout);}
     for(in=0x00; in<(1<<nin); in++){
     
        n401 = (in & (1<<0)) >> 0;
        n402 = (in & (1<<1)) >> 1;
        G41 = (in & (1<<2)) >> 2;
        G36 = (in & (1<<3)) >> 3;
        n400 = (in & (1<<4)) >> 4;
        G40 = (in & (1<<5)) >> 5;
        n409 = (in & (1<<6)) >> 6;
        keyinput18 = (in & (1<<7)) >> 7;
        n411 = (in & (1<<8)) >> 8;
        n412 = (in & (1<<9)) >> 9;
        n409 = (in & (1<<10)) >> 10;
        n407 = (in & (1<<11)) >> 11;
        n401 = (in & (1<<12)) >> 12;
        n390 = (in & (1<<13)) >> 13;
        t3 = (in & (1<<14)) >> 14;

        //l7
        
        xor(&n400, n401, n402);
        nand3(&n398, G41, G36, n400);
        and(&t2, G36, G41);
        or(&n399, n400, t2);
        and(&t1, G40, G41);
        xnor(&n411, n409, keyinput18);
        nand(&n410, n411, n412);
        xor(&n408, n409, keyinput18);
        nor(&n406, n407, n408);
        xor(&n455, n401, n390);   
        or(&n454, n455, t3);
        
   
        lin_op = 0x00;
        for(i=0; i<nin; i++) lin_op ^= (((lin_comb & (1<<i)) >> i) & ((in & (1<<i)) >> i));
        
        if(lin_op == n400) nmatch[0][lin_comb]++;
        if(lin_op == n398) nmatch[1][(int)lin_comb]++;
        if(lin_op == t2) nmatch[2][(int)lin_comb]++;
        if(lin_op == n399) nmatch[3][(int)lin_comb]++;
        if(lin_op == t1) nmatch[4][(int)lin_comb]++;
        if(lin_op == n411) nmatch[5][(int)lin_comb]++;
        if(lin_op == n410) nmatch[6][(int)lin_comb]++;
        if(lin_op == n408) nmatch[7][(int)lin_comb]++;
        if(lin_op == n406) nmatch[8][(int)lin_comb]++;
        if(lin_op == n455) nmatch[9][(int)lin_comb]++;
        if(lin_op == n454) nmatch[10][(int)lin_comb]++;

     } // for all possible inputs in
  } // for all linear combinations

  for(i=0; i<nop; i++){ // for output number
      max_match[0] = 0;
      for(j=2; j<(1<<nin); j++){ // linear combination value
         if(nmatch[i][j]>=max_match[0]){
            max_match[0] = nmatch[i][j]; 
            pr_match = (float)nmatch[i][j]/(1<<nin); 
            max_match[1] = j;
         }
      }

      //fprintf(log_file,"\n******** Linear Approx Part 2_1 ********************************************************************\n");
      fprintf(log_file,"\nLinear Approx Part 3_2:  For op %2d, max_match[0] (#count): %6d, Pr[match]:%1.3f, max_match[1](which lin_comb): %6d",i,max_match[0],pr_match,max_match[1]);
  }

  return;
}


void part3_3(){ // Input to key_In_0_0

  unsigned char lin_op;
  int in, lin_comb;
  unsigned int nin=12, nop=9, nmatch[9][1<<12], max_match[2];
  float pr_match;
  int i,j;

  for(i=0; i<nop; i++){// # outputs
     for(j=0; j<(1<<nin); j++){ // # linear combinations
        nmatch[i][j] = 0;
     }
  } 

  printf("\npart3_3..........................................................................");
  for(lin_comb=0x00; lin_comb<(1<<nin); lin_comb++){
     if((lin_comb%(1<<9))==0) {printf("\nlin_comb: %d",lin_comb); fflush(stdout);}
     for(in=0x00; in<(1<<nin); in++){
     
        G33 = (in & (1<<0)) >> 0;
        G41 = (in & (1<<1)) >> 1;
        n455 = (in & (1<<2)) >> 2;
        n361 = (in & (1<<3)) >> 3;
        n362 = (in & (1<<4)) >> 4;
        n357 = (in & (1<<5)) >> 5;
        G19 = (in & (1<<6)) >> 6;
        n358 = (in & (1<<7)) >> 7;
        n300 = (in & (1<<8)) >> 8;
        n295 = (in & (1<<9)) >> 9;
        n258 = (in & (1<<10)) >> 10;
        n261 = (in & (1<<11)) >> 11;

        
        nand3(&n453, G33, G41, n455);
        and(&n354, n361, n362);
        inv(&n355, n354);
        xnor3(&n356, n357, G19, n358);
        mux(&n298, n354, n355, n356);
        inv(&n265, n300);
        inv(&n263, n295);
        nor(&n299, n258, n263);
        nor(&n296, n261, n265);
        
        lin_op = 0x00;
        for(i=0; i<nin; i++) lin_op ^= (((lin_comb & (1<<i)) >> i) & ((in & (1<<i)) >> i));
        
        if(lin_op == n453) nmatch[0][lin_comb]++;
        if(lin_op == n354) nmatch[1][(int)lin_comb]++;
        if(lin_op == n355) nmatch[2][(int)lin_comb]++;
        if(lin_op == n356) nmatch[3][(int)lin_comb]++;
        if(lin_op == n298) nmatch[4][(int)lin_comb]++;
        if(lin_op == n265) nmatch[5][(int)lin_comb]++;
        if(lin_op == n263) nmatch[6][(int)lin_comb]++;
        if(lin_op == n299) nmatch[7][(int)lin_comb]++;
        if(lin_op == n296) nmatch[8][(int)lin_comb]++;

     } // for all possible inputs in
  } // for all linear combinations

  for(i=0; i<nop; i++){ // for output number
      max_match[0] = 0;
      for(j=2; j<(1<<nin); j++){ // linear combination value
         if(nmatch[i][j]>=max_match[0]){
            max_match[0] = nmatch[i][j]; 
            pr_match = (float)nmatch[i][j]/(1<<nin); 
            max_match[1] = j;
         }
      }

      //fprintf(log_file,"\n******** Linear Approx Part 2_1 ********************************************************************\n");
      fprintf(log_file,"\nLinear Approx Part 3_3:  For op %2d, max_match[0] (#count): %6u, Pr[match]:%1.3f, max_match[1](which lin_comb): %6u",i,max_match[0],pr_match,max_match[1]);
  }

  return;
}




void part3_4(){ // Input to key_In_0_0

  unsigned char lin_op;
  unsigned long int in, lin_comb;
  unsigned int nin=17, nop=12, nmatch[12][1<<17], max_match[2];
  float pr_match;
  int i,j;

  for(i=0; i<nop; i++){// # outputs
     for(j=0; j<(1<<nin); j++){ // # linear combinations
        nmatch[i][j] = 0;
     }
  } 

  printf("\npart3_4..........................................................................");
  for(lin_comb=0x00; lin_comb<(1<<nin); lin_comb++){
     if((lin_comb%(1<<9))==0) {printf("\nlin_comb: %lu",lin_comb); fflush(stdout);}
     for(in=0x00; in<(1<<nin); in++){
     
        n338 = (in & (1<<0)) >> 0;
        n339 = (in & (1<<1)) >> 1;
        n337 = (in & (1<<2)) >> 2;
        G20 = (in & (1<<3)) >> 3;
        G24 = (in & (1<<4)) >> 4;
        G4 = (in & (1<<5)) >> 5;
        G8 = (in & (1<<6)) >> 6;
        n413 = (in & (1<<7)) >> 7;
        G33 = (in & (1<<8)) >> 8;
        G41 = (in & (1<<9)) >> 9;
        n298 = (in & (1<<10)) >> 10;
        n346 = (in & (1<<11)) >> 11;
        G18 = (in & (1<<12)) >> 12;
        n347 = (in & (1<<13)) >> 13;
        n349 = (in & (1<<14)) >> 14;
        n350 = (in & (1<<15)) >> 15;
        G5 = (in & (1<<16)) >> 16;

        nand(&n335, n338, n339);
        xor3(&n336, n337, G20, G24);
        and(&n334, n338, n339);
        mux(&n297, n334, n335, n336);
        xor(&n397, G4, G8);   
        inv(&n412, n413);
        and(&t3, G33, G41);
        inv(&n261, n298);
        xnor3(&n345, n346, G18, n347);
        and(&n343, n349, n350);
        inv(&n344, n343);
        inv(&n452, G5);
        
   
        lin_op = 0x00;
        for(i=0; i<nin; i++) lin_op ^= (((lin_comb & (1<<i)) >> i) & ((in & (1<<i)) >> i));
        
        if(lin_op == n335) nmatch[0][lin_comb]++;
        if(lin_op == n336) nmatch[1][(int)lin_comb]++;
        if(lin_op == n334) nmatch[2][(int)lin_comb]++;
        if(lin_op == n297) nmatch[3][(int)lin_comb]++;
        if(lin_op == n397) nmatch[4][(int)lin_comb]++;
        if(lin_op == n412) nmatch[5][(int)lin_comb]++;
        if(lin_op == t3) nmatch[6][(int)lin_comb]++;
        if(lin_op == n261) nmatch[7][(int)lin_comb]++;
        if(lin_op == n345) nmatch[8][(int)lin_comb]++;
        if(lin_op == n343) nmatch[9][(int)lin_comb]++;
        if(lin_op == n344) nmatch[10][(int)lin_comb]++;
        if(lin_op == n452) nmatch[11][(int)lin_comb]++;

     } // for all possible inputs in
  } // for all linear combinations

  for(i=0; i<nop; i++){ // for output number
      max_match[0] = 0;
      for(j=2; j<(1<<nin); j++){ // linear combination value
         if(nmatch[i][j]>=max_match[0]){
            max_match[0] = nmatch[i][j]; 
            pr_match = (float)nmatch[i][j]/(1<<nin); 
            max_match[1] = j;
         }
      }

      //fprintf(log_file,"\n******** Linear Approx Part 2_1 ********************************************************************\n");
      fprintf(log_file,"\nLinear Approx Part 3_4:  For op %d, max_match[0] (#count): %u, Pr[match]:%f, max_match[1](which lin_comb): %u",i,max_match[0],pr_match,max_match[1]);
  }

  return;
}

void part4_1(){

   // Partition 4: l9-l10 --------------------------------------------------------------------

  unsigned char lin_op;
  unsigned long int in, lin_comb;
  unsigned int nin=17, nop=12, nmatch[12][1<<17], max_match[2];
  float pr_match;
  int i,j;

  for(i=0; i<nop; i++){// # outputs
     for(j=0; j<(1<<nin); j++){ // # linear combinations
        nmatch[i][j] = 0;
     }
  } 

  printf("\npart4_1..........................................................................");
  for(lin_comb=0x00; lin_comb<(1<<nin); lin_comb++){
     if((lin_comb%(1<<9))==0) {printf("\nlin_comb: %lu",lin_comb); fflush(stdout);}
     for(in=0x00; in<(1<<nin); in++){
     
        G7 = (in & (1<<0)) >> 0;
        G10 = (in & (1<<1)) >> 1;
        n414 = (in & (1<<2)) >> 2;
        n415 = (in & (1<<3)) >> 3;
        n416 = (in & (1<<4)) >> 4;
        keyinput17 = (in & (1<<5)) >> 5;
        G25 = (in & (1<<6)) >> 6;
        G26 = (in & (1<<7)) >> 7;
        n447 = (in & (1<<8)) >> 8;
        G19 = (in & (1<<9)) >> 9;
        G20 = (in & (1<<10)) >> 10;
        G17 = (in & (1<<11)) >> 11;
        G18 = (in & (1<<12)) >> 12;

        inv(&n386, G7);
        xnor3(&n407, G10, n414, n415);
        xnor(&n413, n416, keyinput17);
        nor(&n409, n407, n413);
        xnor3(&n391, G25, G26, n447);
        xnor(&n457, G19, G20);
        xor3(&n390, G17, G18, n457);
        xor(&n389, n390, n391);

        lin_op = 0x00;
        for(i=0; i<nin; i++) lin_op ^= (((lin_comb & (1<<i)) >> i) & ((in & (1<<i)) >> i));
        
        if(lin_op == n386) nmatch[0][lin_comb]++;
        if(lin_op == n407) nmatch[1][(int)lin_comb]++;
        if(lin_op == n413) nmatch[2][(int)lin_comb]++;
        if(lin_op == n409) nmatch[3][(int)lin_comb]++;
        if(lin_op == n391) nmatch[4][(int)lin_comb]++;
        if(lin_op == n457) nmatch[5][(int)lin_comb]++;
        if(lin_op == n390) nmatch[6][(int)lin_comb]++;
        if(lin_op == n389) nmatch[7][(int)lin_comb]++;
        if(lin_op == n345) nmatch[8][(int)lin_comb]++;
        if(lin_op == n343) nmatch[9][(int)lin_comb]++;
        if(lin_op == n344) nmatch[10][(int)lin_comb]++;
        if(lin_op == n452) nmatch[11][(int)lin_comb]++;

     } // for all possible inputs in
  } // for all linear combinations

  for(i=0; i<nop; i++){ // for output number
      max_match[0] = 0;
      for(j=2; j<(1<<nin); j++){ // linear combination value
         if(nmatch[i][j]>=max_match[0]){
            max_match[0] = nmatch[i][j]; 
            pr_match = (float)nmatch[i][j]/(1<<nin); 
            max_match[1] = j;
         }
      }

      //fprintf(log_file,"\n******** Linear Approx Part 2_1 ********************************************************************\n");
      fprintf(log_file,"\nLinear Approx Part 3_4:  For op %d, max_match[0] (#count): %u, Pr[match]:%f, max_match[1](which lin_comb): %u",i,max_match[0],pr_match,max_match[1]);
  }

   // l9
   /*xnor(&n456, G23, G24);
   xnor3(&n401, G22, G21, n456);
   xnor(&n457, G19, G20);
   xor3(&n390, G17, G18, n457);
   nand3(&n361, G39, G41, n363);
   and(&t5, G39, G41);
   or(&n362, n363, t5);

   inv(&n357, G23);
   xor(&n359, n360, keyinput10);
   and(&n358, n359, t6);  
   xor(&n340, n341, n342);
   nand3(&n338, G40, G41, n340);
   nand(&t7, G40, G41);
   or(&n339, n340, t7);
   
   or3(&n368, G21, G17, n369);
   nand(&n366, n371, n372);
   inv(&n367, n366);
   mux(&n300, n366, n367, n368);
   nand(&n349, G38, G41, n351);
   or(&n350, n351, t9);
   inv(&n346, G22);
   inv(&n348, G30);
   nor(&n347, n348, G26);
   and(&t10, G35,G41);*/
   
   // l10 

   return;
}

void pat4_2(){

  unsigned char lin_op;
  unsigned long int in, lin_comb;
  unsigned int nin=17, nop=12, nmatch[12][1<<17], max_match[2];
  float pr_match;
  int i,j;

  for(i=0; i<nop; i++){// # outputs
     for(j=0; j<(1<<nin); j++){ // # linear combinations
        nmatch[i][j] = 0;
     }
  } 

  printf("\npart4_1..........................................................................");
  for(lin_comb=0x00; lin_comb<(1<<nin); lin_comb++){
     if((lin_comb%(1<<9))==0) {printf("\nlin_comb: %lu",lin_comb); fflush(stdout);}
     for(in=0x00; in<(1<<nin); in++){
     
        G7 = (in & (1<<0)) >> 0;
        G10 = (in & (1<<1)) >> 1;
        n414 = (in & (1<<2)) >> 2;
        n415 = (in & (1<<3)) >> 3;
        n416 = (in & (1<<4)) >> 4;
        keyinput17 = (in & (1<<5)) >> 5;
        G25 = (in & (1<<6)) >> 6;
        G26 = (in & (1<<7)) >> 7;
        n447 = (in & (1<<8)) >> 8;
        G19 = (in & (1<<9)) >> 9;
        G20 = (in & (1<<10)) >> 10;
        G17 = (in & (1<<11)) >> 11;
        G18 = (in & (1<<12)) >> 12;

        xnor(&n456, G23, G24);
        xnor3(&n401, G22, G21, n456);
        nand3(&n361, G39, G41, n363);
        and(&t5, G39, G41);
        or(&n362, n363, t5);
        inv(&n357, G23);
        xor(&n359, n360, keyinput10);
        and(&n358, n359, t6);  
        xor(&n340, n341, n342);
        nand3(&n338, G40, G41, n340);
  
        lin_op = 0x00;
        for(i=0; i<nin; i++) lin_op ^= (((lin_comb & (1<<i)) >> i) & ((in & (1<<i)) >> i));
        
        if(lin_op == n335) nmatch[0][lin_comb]++;
        if(lin_op == n336) nmatch[1][(int)lin_comb]++;
        if(lin_op == n334) nmatch[2][(int)lin_comb]++;
        if(lin_op == n297) nmatch[3][(int)lin_comb]++;
        if(lin_op == n397) nmatch[4][(int)lin_comb]++;
        if(lin_op == n412) nmatch[5][(int)lin_comb]++;
        if(lin_op == t3) nmatch[6][(int)lin_comb]++;
        if(lin_op == n261) nmatch[7][(int)lin_comb]++;
        if(lin_op == n345) nmatch[8][(int)lin_comb]++;
        if(lin_op == n343) nmatch[9][(int)lin_comb]++;
        if(lin_op == n344) nmatch[10][(int)lin_comb]++;
        if(lin_op == n452) nmatch[11][(int)lin_comb]++;

     } // for all possible inputs in
  } // for all linear combinations

  for(i=0; i<nop; i++){ // for output number
      max_match[0] = 0;
      for(j=2; j<(1<<nin); j++){ // linear combination value
         if(nmatch[i][j]>=max_match[0]){
            max_match[0] = nmatch[i][j]; 
            pr_match = (float)nmatch[i][j]/(1<<nin); 
            max_match[1] = j;
         }
      }

      //fprintf(log_file,"\n******** Linear Approx Part 2_1 ********************************************************************\n");
      fprintf(log_file,"\nLinear Approx Part 3_4:  For op %d, max_match[0] (#count): %u, Pr[match]:%f, max_match[1](which lin_comb): %u",i,max_match[0],pr_match,max_match[1]);
  }


   return;
}

void pat4_3(){


        nand(&t7, G40, G41);
        or(&n339, n340, t7);
        or3(&n368, G21, G17, n369);
        nand(&n366, n371, n372);
        inv(&n367, n366);
        mux(&n300, n366, n367, n368);
        nand(&n349, G38, G41, n351);
        or(&n350, n351, t9);
        inv(&n346, G22);
        inv(&n348, G30);
        nor(&n347, n348, G26);
        and(&t10, G35,G41);

        lin_op = 0x00;
        for(i=0; i<nin; i++) lin_op ^= (((lin_comb & (1<<i)) >> i) & ((in & (1<<i)) >> i));
        
        if(lin_op == n335) nmatch[0][lin_comb]++;
        if(lin_op == n336) nmatch[1][(int)lin_comb]++;
        if(lin_op == n334) nmatch[2][(int)lin_comb]++;
        if(lin_op == n297) nmatch[3][(int)lin_comb]++;
        if(lin_op == n397) nmatch[4][(int)lin_comb]++;
        if(lin_op == n412) nmatch[5][(int)lin_comb]++;
        if(lin_op == t3) nmatch[6][(int)lin_comb]++;
        if(lin_op == n261) nmatch[7][(int)lin_comb]++;
        if(lin_op == n345) nmatch[8][(int)lin_comb]++;
        if(lin_op == n343) nmatch[9][(int)lin_comb]++;
        if(lin_op == n344) nmatch[10][(int)lin_comb]++;
        if(lin_op == n452) nmatch[11][(int)lin_comb]++;

     } // for all possible inputs in
  } // for all linear combinations

  for(i=0; i<nop; i++){ // for output number
      max_match[0] = 0;
      for(j=2; j<(1<<nin); j++){ // linear combination value
         if(nmatch[i][j]>=max_match[0]){
            max_match[0] = nmatch[i][j]; 
            pr_match = (float)nmatch[i][j]/(1<<nin); 
            max_match[1] = j;
         }
      }

      //fprintf(log_file,"\n******** Linear Approx Part 2_1 ********************************************************************\n");
      fprintf(log_file,"\nLinear Approx Part 3_4:  For op %d, max_match[0] (#count): %u, Pr[match]:%f, max_match[1](which lin_comb): %u",i,max_match[0],pr_match,max_match[1]);
  }

   return;
}

int main(){

  // Key inputs

  if((log_file=fopen("log_file.txt","w"))==NULL){
     printf("Cannot open log_file.txt");
     exit(1);
  }

  // Logic locked combo ciruit

  /*c1355( G1, G10, G11, G12, G13, G1324, G1325, G1326, G1327, G1328, G1329, G1330,
            G1331, G1332, G1333, G1334, G1335, G1336, G1337, G1338, G1339, G1340, G1341, G1342, 
  G1343, G1344, G1345, G1346, G1347, G1348, G1349, G1350, G1351, G1352, G1353, G1354, 
  G1355, G14, G15, G16, G17, G18, G19, G2, G20, G21, G22, G23, G24, G25, G26, G27, G28, G29, G3, 
  G30, G31, G32, G33, G34, G35, G36, G37, G38, G39, G4, G40, G41, G5, G6, G7, G8, G9, 
  keyIn_0_0,  keyIn_0_1,  keyIn_0_2,  keyIn_0_3,  keyIn_0_4, 
  keyIn_0_5,  keyIn_0_6,  keyIn_0_7,  keyIn_0_8,  keyIn_0_9, 
  keyIn_0_10,  keyIn_0_11,  keyIn_0_12,  keyIn_0_13,  keyIn_0_14, 
  keyIn_0_15,  keyIn_0_16,  keyIn_0_17,  keyIn_0_18,  keyIn_0_19, 
  keyIn_0_20,  keyIn_0_21,  keyIn_0_22,  keyIn_0_23,  keyIn_0_24, 
  keyIn_0_25,  keyIn_0_26,  keyIn_0_27,  keyIn_0_28,  keyIn_0_29, 
  keyIn_0_30,  keyIn_0_31);*/

  //part1();
  //part2();
  fprintf(log_file,"\n======================================================================================================================================\n");
  //part2_1();
  //part2_2();
  //fprintf(log_file,"\n======================================================================================================================================\n");
  part3_1();
  fprintf(log_file,"\n======================================================================================================================================\n");
  part3_2();
  fprintf(log_file,"\n======================================================================================================================================\n");
  part3_3();
  fprintf(log_file,"\n======================================================================================================================================\n");
  part3_4();
  printf("\n");
  fclose(log_file);
   return 0;
}



