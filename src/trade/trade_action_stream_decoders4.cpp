#pragma exceptions off
#include "trade_action_stream_decoders4.h"

void func_0015B660() {
    unsigned char *dst = (unsigned char *)&D_004E2DA0;
    unsigned char *src = D_004E2DB0;
    dst[0] = src[0];
    dst[1] = src[1];
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    D_004E2DA8 -= 3;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
    } while ((D_004E2DA8 -= 4) != 0);

    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_0015B7C0() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    D_004E2DA8 -= 4;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
    } while ((D_004E2DA8 -= 4) != 0);

    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_0015B930() {
    D_004E2DA8 -= 2;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
    } while ((D_004E2DA8 -= 4) != 0);

    unsigned char *dst = (unsigned char *)&D_004E2DA0;
    unsigned char *src = D_004E2DB0;
    dst[0] = src[0];
    dst[1] = src[1];
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_0015BA50() {
    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    D_004E2DA8 -= 3;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
    } while ((D_004E2DA8 -= 4) != 0);

    unsigned char *dst = (unsigned char *)&D_004E2DA0;
    unsigned char *src = D_004E2DB0;
    dst[0] = src[0];
    dst[1] = src[1];
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_0015BBB0() {
    unsigned char *dst = (unsigned char *)&D_004E2DA0;
    unsigned char *src = D_004E2DB0;
    dst[0] = src[0];
    dst[1] = src[1];
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    D_004E2DA8 -= 4;

    do {
        func_001522C0(D_004E2DA0.b, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
        *D_004E2DB4++ = D_004E2DA0.b[0];
        *D_004E2DB4++ = D_004E2DA0.b[1];
        *D_004E2DB4++ = D_004E2DA0.b[2];
        *D_004E2DB4++ = D_004E2DA0.b[3];
    } while ((D_004E2DA8 -= 4) != 0);

    dst = (unsigned char *)&D_004E2DA0;
    src = D_004E2DB0;
    dst[0] = src[0];
    dst[1] = src[1];
    D_004E2DB0 += 2;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}
