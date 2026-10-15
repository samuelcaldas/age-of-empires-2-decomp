#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern unsigned char D_004E2DA0[4];
extern unsigned int D_004E2DA4;
extern int D_004E2DA8;
extern unsigned int D_004E30A8;
extern unsigned int D_004E30B0;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;

void func_001522C0(unsigned char *a0, unsigned char *a1);

void func_0015C2F0() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 |= D_004E2DA4;
    D_004E2DB0 += 3;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
    D_004E2DA8 -= 6;

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

void func_0015C490() {
    D_004E2DA0[0] = *D_004E2DB0;
    D_004E2DB0++;
    *(unsigned int *)D_004E2DA0 = (*(unsigned int *)D_004E2DA0 & D_004E30A8) | D_004E30B0;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

void func_0015C4E0() {
    D_004E2DA0[1] = *D_004E2DB0;
    D_004E2DB0++;
    *(unsigned int *)D_004E2DA0 = (*(unsigned int *)D_004E2DA0 & D_004E30A8) | D_004E30B0;

    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
}

void func_0015C530() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 2;
    *(unsigned int *)D_004E2DA0 |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
}

void func_0015C5B0() {
    func_001522C0(D_004E2DA0, D_004E2DB0 - 1);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 2;
    *(unsigned int *)D_004E2DA0 = (*(unsigned int *)D_004E2DA0 | D_004E30B0) >> 8;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
}

void func_0015C640() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 3;
    *(unsigned int *)D_004E2DA0 |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_0015C6E0() {
    func_001522C0(D_004E2DA0, D_004E2DB0 - 1);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 3;
    *(unsigned int *)D_004E2DA0 |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[3];
    D_004E2DB4++;
}

void func_0015C780() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 2;
    *(unsigned int *)D_004E2DA0 |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;

    D_004E2DA0[0] = *D_004E2DB0;
    D_004E2DB0++;
    *(unsigned int *)D_004E2DA0 = (*(unsigned int *)D_004E2DA0 & D_004E30A8) | D_004E30B0;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

void func_0015C850() {
    D_004E2DA0[1] = *D_004E2DB0;
    D_004E2DB0++;
    *(unsigned int *)D_004E2DA0 = (*(unsigned int *)D_004E2DA0 & D_004E30A8) | D_004E30B0;

    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 2;
    *(unsigned int *)D_004E2DA0 |= D_004E30B0;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
}

}
