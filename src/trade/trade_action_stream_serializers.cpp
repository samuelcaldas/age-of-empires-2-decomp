#pragma exceptions off
#include "sub_list.h"

extern "C" {

union Buffer4 {
    unsigned char b[4];
    unsigned char bytes[4];
    int w;
    int word;
    unsigned int u;
};

extern Buffer4 D_004E2DA0;
extern unsigned char *D_004E2DB4;
extern int D_004E2DA8;

void func_00157D30() {
    do {
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);
}

void func_00157DB0() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    D_004E2DA8--;

    do {
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);
}

void func_00157E50() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    D_004E2DA8 -= 2;

    do {
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);
}

void func_00157F10() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    D_004E2DA8 -= 3;

    do {
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);
}

void func_00157FE0() {
    D_004E2DA8--;

    do {
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}

void func_00158080() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    D_004E2DA8 -= 2;

    do {
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}

void func_00158130() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    D_004E2DA8 -= 3;

    do {
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}

void func_00158200() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    D_004E2DA8 -= 4;

    do {
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}

}
