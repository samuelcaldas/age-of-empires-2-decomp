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

void func_00155B10() {
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
    D_004E2DB0 += 4;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];

    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00155C70() {
    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
        *D_004E2DB4 = D_004E2DA0.b[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.b[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.b[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.b[3];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_00155D30() {
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
    D_004E2DA8 -= 1;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_00155E50() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    D_004E2DA8 -= 2;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_00155F80() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0 - 1);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 3;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];
    D_004E2DA8 -= 3;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

}
