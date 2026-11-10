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
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
extern int D_004E30A8;
extern int D_004E30AC;
extern int D_004E2DA8;

void func_001522C0(unsigned char *buf, unsigned char *src);

void func_00155B10() {
    D_004E2DA0.bytes[1] = *D_004E2DB0;
    D_004E2DB0++;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 4;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[3];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 2;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
}

void func_00155C70() {
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.word &= D_004E30A8;
        D_004E2DA0.word |= D_004E30AC;

        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);
}

void func_00155D30() {
    D_004E2DA0.bytes[1] = *D_004E2DB0;
    D_004E2DB0++;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    D_004E2DA8--;

    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.word &= D_004E30A8;
        D_004E2DA0.word |= D_004E30AC;

        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);
}

void func_00155E50() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 2;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    D_004E2DA8 -= 2;

    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.word &= D_004E30A8;
        D_004E2DA0.word |= D_004E30AC;

        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);
}

void func_00155F80() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0 - 1);
    D_004E2DB0 += 3;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[3];
    D_004E2DB4++;
    D_004E2DA8 -= 3;

    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.word &= D_004E30A8;
        D_004E2DA0.word |= D_004E30AC;

        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4++;
    } while ((D_004E2DA8 -= 4) != 0);
}

}
