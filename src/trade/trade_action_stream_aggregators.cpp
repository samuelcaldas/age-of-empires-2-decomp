#pragma exceptions off
#include "trade_action_stream_aggregators.h"

void func_001560D0() {
    D_004E2DA8 -= 1;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
    } while ((D_004E2DA8 -= 4) != 0);

    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_001561F0() {
    D_004E2DA0.b[1] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[1];
    D_004E2DA8 -= 2;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
    } while ((D_004E2DA8 -= 4) != 0);

    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00156350() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    D_004E2DA8 -= 3;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
    } while ((D_004E2DA8 -= 4) != 0);

    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_001564D0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0 - 1);
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DB0 += 3;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];
    D_004E2DA8 -= 4;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
    } while ((D_004E2DA8 -= 4) != 0);

    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w & D_004E30A8;
    D_004E2DA0.w = D_004E2DA0.w | D_004E30AC;
    *D_004E2DB4++ = D_004E2DA0.b[0];
}
