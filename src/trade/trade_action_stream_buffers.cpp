#pragma exceptions off
#include "trade_action_stream_buffers.h"

#define COPY_BYTE() \
    *D_004E2DB4 = *D_004E2DB0; \
    D_004E2DB4++; \
    D_004E2DB0++;

void func_00152F30() {
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()

    func_001522C0(D_004E2DA0, D_004E2DB0);

    D_004E2DB0 += 3;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_00153050() {
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()

    func_001522C0(D_004E2DA0, D_004E2DB0);

    D_004E2DB0 += 3;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_00153170() {
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()

    func_001522C0(D_004E2DA0, D_004E2DB0);

    D_004E2DB0 += 3;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_00153290() {
    do {
        COPY_BYTE()
        COPY_BYTE()
        COPY_BYTE()
        COPY_BYTE()
    } while (D_004E2DA8 -= 4);
}

void func_00153350() {
    COPY_BYTE()
    D_004E2DA8--;
    do {
        COPY_BYTE()
        COPY_BYTE()
        COPY_BYTE()
        COPY_BYTE()
    } while (D_004E2DA8 -= 4);
}
