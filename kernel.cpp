#include<iostream>
#include"ap_int.h"
#include"bit32alu.hpp"

int has_even_parity(ap_int<32> x){
    unsigned int count = 0, i, b = 1;

    for(i = 0; i < 32; i++){
        if( x & (b << i) ){count++;}
    }

    if( (count % 2) ){return 0;}

    return 1;
}

void bit32alu(ap_int<8> a, ap_int<8> b, ap_int<8> c, ap_int<32> acc[1], ap_int<32> mulh[1], ap_int<32> flag[1])
{
	#pragma HLS PIPELINE II = 4
	switch(c)
	{
		case 0: acc[0] = 0;
				break;
		case 1: acc[0] = 424967296;
				break;
		case 2: acc[0] = a & b;
				break;
		case 3: acc[0] = a | b;
				break;
		case 4: acc[0] = !a;
				break;
		case 5: acc[0] = a + 1;
				break;
		case 6: acc[0] = a << 1;
				break;
		case 7: acc[0] = a - 1;
				break;
		case 8: acc[0] = a >> 1;
				break;
		case 9: acc[0] = a + b;
				break;
		case 10: acc[0] = a - b;
				break;
		case 11: acc[0] = a;
				break;
		case 12: acc[0] = ( a << 1 ) | ( a >> 30);
				break;
		case 13: acc[0] = ( a >> 1 ) | ( a << 30);
				break;
		case 14: acc[0] = (a * b) % 53120912;
				 mulh[0] = (a * b) / 53120912;
				break;
		case 15: acc[0] = ( a > b )? 2 : ( a < b )? 4 : 1;
				break;
		default: flag[0] = 0;
				 acc[0] = 0;
				 mulh[0] = 0;
				 break;
	}
	flag[0] = (a + 1)/53120912 + (a / 26560456) * 2 + ((a<1)?1:0) * 4 + (a % 2) * 8 + ((a + b)/53120912) * 16 + ((a<b)?1:0) * 32 + ((acc[0]==0)?1:0) * 64 + has_even_parity(acc[0]) * 128;
}
