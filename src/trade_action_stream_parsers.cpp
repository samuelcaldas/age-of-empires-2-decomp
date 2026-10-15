#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern unsigned char D_004E2DA0[4];
extern unsigned int D_004E30A8;
extern unsigned int D_004E30AC;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;

void func_001522C0(unsigned char *a0, unsigned char *a1);

void func_00154B30() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 4;
    *(unsigned int *)D_004E2DA0 |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[3];
    D_004E2DB4++;
}

void func_00154BE0() {
    func_001522C0(D_004E2DA0, D_004E2DB0 - 1);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 3;
    *(unsigned int *)D_004E2DA0 |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[3];
    D_004E2DB4++;

    D_004E2DA0[0] = *D_004E2DB0;
    D_004E2DB0++;
    *(unsigned int *)D_004E2DA0 = (*(unsigned int *)D_004E2DA0 & D_004E30A8) | D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

void func_00154CD0() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 2;
    *(unsigned int *)D_004E2DA0 |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 2;
    *(unsigned int *)D_004E2DA0 |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
}

void func_00154DC0() {
    D_004E2DA0[1] = *D_004E2DB0;
    D_004E2DB0++;
    *(unsigned int *)D_004E2DA0 = (*(unsigned int *)D_004E2DA0 & D_004E30A8) | D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 3;
    *(unsigned int *)D_004E2DA0 |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_00154EA0() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 4;
    *(unsigned int *)D_004E2DA0 |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[3];
    D_004E2DB4++;

    D_004E2DA0[0] = *D_004E2DB0;
    D_004E2DB0++;
    *(unsigned int *)D_004E2DA0 = (*(unsigned int *)D_004E2DA0 & D_004E30A8) | D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
}

void func_00154FA0() {
    func_001522C0(D_004E2DA0, D_004E2DB0 - 1);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 3;
    *(unsigned int *)D_004E2DA0 |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[3];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0, D_004E2DB0);
    *(unsigned int *)D_004E2DA0 &= D_004E30A8;
    D_004E2DB0 += 2;
    *(unsigned int *)D_004E2DA0 |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
}

}
