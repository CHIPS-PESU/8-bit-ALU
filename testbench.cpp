#include"ap_int.h"
#include<fstream>
#include<iostream>
#include"bit32alu.hpp"
#include<string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main() {

	ap_int<8> a;
	ap_int<8> b;
	ap_int<8> c;
	ap_int<32> x;
	ap_int<32> acc[1];
	ap_int<32> mulh[1];
	ap_int<32> flag[1];


	a = 4;
	b = 5;
	x = 6;


	ofstream m; // m is the file object
	        m.open("write.txt");

	        for(c= 0;c<=15;c++)
	        {
	             bit32alu(a,b,c,acc,mulh,flag);
	             m<<"Case "<<c<<": "<<"acc = "<<acc[0]<<", mulh = "<<mulh[0]<<", flag = "<<flag[0]<<endl;
	        }
	        m.close();

	 return 0;

}
