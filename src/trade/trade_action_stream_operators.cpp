#pragma exceptions off
#include "sub_list.h"

extern "C" {

union Buffer4 {
    unsigned char b[4];
    int w;
    unsigned int u;
};

extern Buffer4 D_004E2DA0;
extern int D_004E2DA4;
extern int D_004E2DA8;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
extern int D_004E30A8;
extern int D_004E30B0;

void func_001522C0(unsigned char *buf, unsigned char *src);

void func_0015C2F0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.w |= D_004E2DA4;

    *D_004E2DB4 = D_004E2DA0.b[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[2];
    D_004E2DB4++;
    D_004E2DA8 -= 6;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.w |= D_004E2DA4;
        *D_004E2DB4 = D_004E2DA0.b[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.b[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.b[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.b[3];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);

    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.w |= D_004E2DA4;
    *D_004E2DB4 = D_004E2DA0.b[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[2];
    D_004E2DB4++;
}

void func_0015C490() {
    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w &= D_004E30A8;
    D_004E2DA0.w |= D_004E30B0;
    *D_004E2DB4 = D_004E2DA0.b[0];
    D_004E2DB4++;
}

void func_0015C4E0() {
    D_004E2DA0.b[1] = *D_004E2DB0++;
    D_004E2DA0.w &= D_004E30A8;
    D_004E2DA0.w |= D_004E30B0;
    *D_004E2DB4 = D_004E2DA0.b[1];
    D_004E2DB4++;
}

void func_0015C530() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 2;
    D_004E2DA0.w &= D_004E30A8;
    D_004E2DA0.w |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0.b[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[1];
    D_004E2DB4++;
}

void func_0015C5B0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0 - 1);
    D_004E2DB0 += 2;
    D_004E2DA0.w &= D_004E30A8;
    D_004E2DA0.w |= D_004E30B0;
    D_004E2DA0.u >>= 8;

    *D_004E2DB4 = D_004E2DA0.b[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[1];
    D_004E2DB4++;
}

void func_0015C640() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.w &= D_004E30A8;
    D_004E2DA0.w |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0.b[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[2];
    D_004E2DB4++;
}

void func_0015C6E0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0 - 1);
    D_004E2DB0 += 3;
    D_004E2DA0.w &= D_004E30A8;
    D_004E2DA0.w |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0.b[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[3];
    D_004E2DB4++;
}

void func_0015C780() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 2;
    D_004E2DA0.w &= D_004E30A8;
    D_004E2DA0.w |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0.b[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[1];
    D_004E2DB4++;

    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w &= D_004E30A8;
    D_004E2DA0.w |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0.b[0];
    D_004E2DB4++;
}

void func_0015C850() {
    D_004E2DA0.b[1] = *D_004E2DB0++;
    D_004E2DA0.w &= D_004E30A8;
    D_004E2DA0.w |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0.b[1];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 2;
    D_004E2DA0.w &= D_004E30A8;
    D_004E2DA0.w |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0.b[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.b[1];
    D_004E2DB4++;
}

}
