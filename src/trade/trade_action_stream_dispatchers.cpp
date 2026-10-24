#pragma exceptions off
#include "sub_list.h"

extern "C" {

extern unsigned char D_004E2DA0[4];
extern int D_004E2DA8;
extern unsigned char *D_004E2DB4;

void func_00159500() {
    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[3];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_00159580() {
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    D_004E2DA8 -= 1;

    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[3];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_00159620() {
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    D_004E2DA8 -= 2;

    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[3];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_001596E0() {
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    D_004E2DA8 -= 3;

    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[3];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_001597B0() {
    D_004E2DA8 -= 1;

    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[3];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

void func_00159850() {
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    D_004E2DA8 -= 2;

    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[3];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

void func_00159900() {
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    D_004E2DA8 -= 3;

    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[3];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

void func_001599D0() {
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    D_004E2DA8 -= 4;

    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[3];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

}
