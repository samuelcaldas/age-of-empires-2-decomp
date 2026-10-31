#pragma exceptions off
#include "trade_action_stream_decoders2.h"

extern "C" {
extern int D_004E2DA8;

void func_0015ABF0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 4;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];

    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
}

void func_0015AD00() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 4;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];

    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
}

void func_0015AE10() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 4;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];

    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
}

void func_0015AF20() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 4;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];

    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
}

void func_0015B030() {
    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
    } while ((D_004E2DA8 -= 4) != 0);
}

}
