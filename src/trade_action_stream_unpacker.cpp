#pragma exceptions off
#include "trade_action_stream_unpacker.h"

void func_001539E0() {
    D_004E2DB0 += 3;
    *D_004E2DB4++ = D_004E2DA0[0];
    *D_004E2DB4++ = D_004E2DA0[1];
    *D_004E2DB4++ = D_004E2DA0[2];
    D_004E2DA8 -= 4;

    do {
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);

    *D_004E2DB4++ = *D_004E2DB0++;
}

void func_00153B30() {
    D_004E2DA8 -= 2;

    do {
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);

    func_001522C0(D_004E2DA0, D_004E2DB0);
    D_004E2DB0 += 2;
    *D_004E2DB4++ = D_004E2DA0[0];
    *D_004E2DB4++ = D_004E2DA0[1];
}

void func_00153C50() {
    *D_004E2DB4++ = *D_004E2DB0++;
    D_004E2DA8 -= 3;

    do {
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);

    func_001522C0(D_004E2DA0, D_004E2DB0);
    D_004E2DB0 += 2;
    *D_004E2DB4++ = D_004E2DA0[0];
    *D_004E2DB4++ = D_004E2DA0[1];
}

void func_00153D90() {
    func_001522C0(D_004E2DA0, D_004E2DB0);
    D_004E2DB0 += 2;
    *D_004E2DB4++ = D_004E2DA0[0];
    *D_004E2DB4++ = D_004E2DA0[1];
    D_004E2DA8 -= 4;

    do {
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        *D_004E2DB4++ = *D_004E2DB0++;
        D_004E2DA8 -= 4;
    } while (D_004E2DA8 != 0);

    *D_004E2DB4++ = *D_004E2DB0++;
    *D_004E2DB4++ = *D_004E2DB0++;
}
