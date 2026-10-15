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
extern int D_004E2DA8;
extern Buffer4 D_004E2DA0;
extern int D_004E30A8;
extern int D_004E30AC;

void func_001522C0(unsigned char *buf, unsigned char *src);

void func_00154480() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 3;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    D_004E2DA8 -= 6;

    do {
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);

    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 3;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
}

void func_00154610() {
    unsigned char *src = D_004E2DB0;
    int mask1 = D_004E30A8;
    int mask2 = D_004E30AC;
    unsigned char *dst = D_004E2DB4;

    D_004E2DA0.b[0] = *src++;
    D_004E2DB0 = src;

    D_004E2DA0.w = D_004E2DA0.w & mask1;
    D_004E2DA0.w = D_004E2DA0.w | mask2;

    *dst = D_004E2DA0.b[0];
    D_004E2DB4 = D_004E2DB4 + 1;
}

void func_00154660() {
    unsigned char *src = D_004E2DB0;
    int mask1 = D_004E30A8;
    int mask2 = D_004E30AC;
    unsigned char *dst = D_004E2DB4;

    D_004E2DA0.b[1] = *src++;
    D_004E2DB0 = src;

    D_004E2DA0.w = D_004E2DA0.w & mask1;
    D_004E2DA0.w = D_004E2DA0.w | mask2;

    *dst = D_004E2DA0.b[1];
    D_004E2DB4 = D_004E2DB4 + 1;
}

void func_001546B0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00154730() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0 - 1);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    D_004E2DA0.u >>= 8;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_001547C0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0 - 1);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    D_004E2DA0.u >>= 8;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00154850() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 3;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
}

void func_001548F0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0 - 1);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 3;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];
}

void func_00154990() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];

    unsigned char *src = D_004E2DB0;
    int mask1 = D_004E30A8;
    int mask2 = D_004E30AC;
    unsigned char *dst = D_004E2DB4;

    D_004E2DA0.b[0] = *src++;
    D_004E2DB0 = src;

    D_004E2DA0.w = D_004E2DA0.w & mask1;
    D_004E2DA0.w = D_004E2DA0.w | mask2;

    *dst = D_004E2DA0.b[0];
    D_004E2DB4 = D_004E2DB4 + 1;
}

void func_00154A60() {
    unsigned char *src = D_004E2DB0;
    int mask1 = D_004E30A8;
    int mask2 = D_004E30AC;
    unsigned char *dst = D_004E2DB4;

    D_004E2DA0.b[1] = *src++;
    D_004E2DB0 = src;

    D_004E2DA0.w = D_004E2DA0.w & mask1;
    D_004E2DA0.w = D_004E2DA0.w | mask2;

    *dst = D_004E2DA0.b[1];
    D_004E2DB4 = D_004E2DB4 + 1;

    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

}
