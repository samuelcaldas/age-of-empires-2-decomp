#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern unsigned char D_004E2DA0[];
extern int D_004E2DA8;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;

void func_001522C0(unsigned char *a0, unsigned char *a1);

#define COPY_BYTE() \
    *D_004E2DB4 = *D_004E2DB0; \
    D_004E2DB4++; \
    D_004E2DB0++;

void func_00152F30() {
    unsigned char *buf = D_004E2DA0;

    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()

    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB0++;
    func_001522C0(buf, D_004E2DB0);
    D_004E2DB4++;

    D_004E2DB0 += 3;
    *D_004E2DB4 = buf[0];
    D_004E2DB4++;
    *D_004E2DB4 = buf[1];
    D_004E2DB4++;
    *D_004E2DB4 = buf[2];
    D_004E2DB4++;
}

void func_00153050() {
    unsigned char *buf = D_004E2DA0;

    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()

    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB0++;
    func_001522C0(buf, D_004E2DB0);
    D_004E2DB4++;

    D_004E2DB0 += 3;
    *D_004E2DB4 = buf[0];
    D_004E2DB4++;
    *D_004E2DB4 = buf[1];
    D_004E2DB4++;
    *D_004E2DB4 = buf[2];
    D_004E2DB4++;
}

void func_00153170() {
    unsigned char *buf = D_004E2DA0;

    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()

    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB0++;
    func_001522C0(buf, D_004E2DB0);
    D_004E2DB4++;

    D_004E2DB0 += 3;
    *D_004E2DB4 = buf[0];
    D_004E2DB4++;
    *D_004E2DB4 = buf[1];
    D_004E2DB4++;
    *D_004E2DB4 = buf[2];
    D_004E2DB4++;
}

void func_00153290() {
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
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

void func_00153360() {
    D_004E2DB4++;
    D_004E2DB0++;
    D_004E2DA8--;
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
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);
}

}
