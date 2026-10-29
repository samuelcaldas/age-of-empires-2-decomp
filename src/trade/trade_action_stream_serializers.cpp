#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern unsigned char D_004E2DA0[4];
extern int D_004E2DA8;
extern unsigned char *D_004E2DB4;

void func_00157D30() {
    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_00157DB0() {
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    D_004E2DA8--;
    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_00157E50() {
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
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_00157F10() {
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    D_004E2DA8 -= 3;
    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_00157FE0() {
    D_004E2DA8--;
    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

void func_00158080() {
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    D_004E2DA8 -= 2;
    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

void func_00158130() {
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
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

void func_001581F0() {
    D_004E2DA8 -= 4;
    do {
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0[1];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

}
