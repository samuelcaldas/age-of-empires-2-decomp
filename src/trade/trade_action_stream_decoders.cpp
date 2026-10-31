#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
extern int D_004E2DA8;
extern unsigned char D_004E2DA0[4];

void func_001522C0(unsigned char *buf, unsigned char *src);

void func_00153440() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    D_004E2DB0 += 2;
    *D_004E2DB4++ = D_004E2DA0[0];
    *D_004E2DB4++ = D_004E2DA0[1];
    D_004E2DA8 -= 2;

    do {
        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;
    } while ((D_004E2DA8 -= 4) != 0);
}

void func_00153560() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    D_004E2DB0 += 3;
    *D_004E2DB4++ = D_004E2DA0[0];
    *D_004E2DB4++ = D_004E2DA0[1];
    *D_004E2DB4++ = D_004E2DA0[2];
    D_004E2DA8 -= 3;

    do {
        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;
    } while ((D_004E2DA8 -= 4) != 0);
}

void func_00153690() {
    D_004E2DA8 -= 1;

    do {
        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;
    } while ((D_004E2DA8 -= 4) != 0);

    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB4++;
    D_004E2DB0++;
}

void func_00153780() {
    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB4++;
    D_004E2DB0++;
    D_004E2DA8 -= 2;

    do {
        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;
    } while ((D_004E2DA8 -= 4) != 0);

    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB4++;
    D_004E2DB0++;
}

void func_00153890() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    D_004E2DB0 += 2;
    *D_004E2DB4++ = D_004E2DA0[0];
    *D_004E2DB4++ = D_004E2DA0[1];
    D_004E2DA8 -= 3;

    do {
        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;

        *D_004E2DB4 = *D_004E2DB0;
        D_004E2DB4++;
        D_004E2DB0++;
    } while ((D_004E2DA8 -= 4) != 0);

    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB4++;
    D_004E2DB0++;
}

}
