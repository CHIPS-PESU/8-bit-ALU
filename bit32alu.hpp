extern ap_int<32> acc[1];
extern ap_int<32> mulh[1];
extern ap_int<32> flag[1];
int has_even_parity(ap_int<32> x);
void bit32alu(ap_int<8> a, ap_int<8> b, ap_int<8> c, ap_int<32> *acc, ap_int<32> *mulh, ap_int<32> *flag);
