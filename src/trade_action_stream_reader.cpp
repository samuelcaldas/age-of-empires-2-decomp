#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern unsigned char D_004E2DA0[];
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;

void func_001522C0(unsigned char *a0, unsigned char *a1);

#define COPY_BYTE() \
    *D_004E2DB4 = *D_004E2DB0; \
    D_004E2DB4++; \
    D_004E2DB0++;

void func_001527A0() {
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
}

void func_00152870() {
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
}

void func_00152940() {
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
}

void func_00152A10() {
    unsigned char *buf = D_004E2DA0;

    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()

    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB0++;
    func_001522C0(buf, D_004E2DB0);
    D_004E2DB4++;

    D_004E2DB0 += 2;
    *D_004E2DB4 = buf[0];
    D_004E2DB4++;
    *D_004E2DB4 = buf[1];
    D_004E2DB4++;
}

}
