#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern unsigned char D_004E2DA0[4];
extern unsigned int D_004E2DA4;
extern int D_004E2DA8;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;

void func_001522C0(unsigned char *a0, unsigned char *a1);

void func_0015ABF0() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 |= D_004E2DA4;
    D_004E2DB0 += 4;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[3];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 |= D_004E2DA4;
    D_004E2DB0 += 3;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_0015AD00() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 |= D_004E2DA4;
    D_004E2DB0 += 4;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[3];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 |= D_004E2DA4;
    D_004E2DB0 += 3;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_0015AE10() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 |= D_004E2DA4;
    D_004E2DB0 += 4;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[3];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 |= D_004E2DA4;
    D_004E2DB0 += 3;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_0015AF20() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 |= D_004E2DA4;
    D_004E2DB0 += 4;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[3];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 |= D_004E2DA4;
    D_004E2DB0 += 3;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_0015B030() {
    do {
        func_001522C0(D_004E2DA0, D_004E2DB0);
        *(unsigned int *)D_004E2DA0 |= D_004E2DA4;
        D_004E2DB0 += 4;

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

}
