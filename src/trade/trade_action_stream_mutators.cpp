#pragma exceptions off
#include "sub_list.h"

extern "C" {

union Buffer4 {
    unsigned char b[4];
    int w;
    unsigned int u;
};

extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
extern Buffer4 D_004E2DA0;
extern int D_004E2DA4;

void func_001522C0(unsigned char *buf, unsigned char *src);

void func_0015A1D0() {
    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w |= D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_0015A210() {
    unsigned char *src = D_004E2DB0;
    unsigned char *dst = D_004E2DA0.b;
    dst[0] = src[0];
    dst[1] = src[1];
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    D_004E2DB0 += 2;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_0015A280() {
    unsigned char *src = D_004E2DB0;
    unsigned char *dst = D_004E2DA0.b;
    dst[0] = src[0];
    dst[1] = src[1];
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    D_004E2DB0 += 2;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_0015A2F0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    D_004E2DB0 += 3;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
}

void func_0015A380() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    D_004E2DB0 += 3;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
}

void func_0015A410() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    D_004E2DB0 += 4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];
}

void func_0015A4B0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    D_004E2DB0 += 4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];
}

void func_0015A550() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    D_004E2DB0 += 4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];
    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_0015A630() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    D_004E2DB0 += 4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];
    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

}
