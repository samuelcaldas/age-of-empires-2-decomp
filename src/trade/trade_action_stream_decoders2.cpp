#pragma exceptions off
#include "trade_action_stream_decoders2.h"

void func_0015A710() {
    func_001522C0(D_004E2DA0.b, D_004E2DB0);
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    D_004E2DB0 += 4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];

    D_004E2DA0.b[0] = *D_004E2DB0++;
    D_004E2DA0.w = D_004E2DA0.w | D_004E2DA4;
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_0015A7F0() {
    Buffer4 *buf = &D_004E2DA0;
    func_001522C0(buf->b, D_004E2DB0);
    buf->w = buf->w | D_004E2DA4;
    D_004E2DB0 += 4;
    *D_004E2DB4++ = buf->b[0];
    *D_004E2DB4++ = buf->b[1];
    *D_004E2DB4++ = buf->b[2];
    *D_004E2DB4++ = buf->b[3];

    buf->b[0] = D_004E2DB0[0];
    buf->b[1] = D_004E2DB0[1];
    buf->w = buf->w | D_004E2DA4;
    D_004E2DB0 += 2;
    *D_004E2DB4++ = buf->b[0];
    *D_004E2DB4++ = buf->b[1];
}

void func_0015A8F0() {
    Buffer4 *buf = &D_004E2DA0;
    func_001522C0(buf->b, D_004E2DB0);
    buf->w = buf->w | D_004E2DA4;
    D_004E2DB0 += 4;
    *D_004E2DB4++ = buf->b[0];
    *D_004E2DB4++ = buf->b[1];
    *D_004E2DB4++ = buf->b[2];
    *D_004E2DB4++ = buf->b[3];

    buf->b[0] = D_004E2DB0[0];
    buf->b[1] = D_004E2DB0[1];
    buf->w = buf->w | D_004E2DA4;
    D_004E2DB0 += 2;
    *D_004E2DB4++ = buf->b[0];
    *D_004E2DB4++ = buf->b[1];
}

void func_0015A9F0() {
    Buffer4 *buf = &D_004E2DA0;
    func_001522C0(buf->b, D_004E2DB0);
    buf->w = buf->w | D_004E2DA4;
    D_004E2DB0 += 4;
    *D_004E2DB4++ = buf->b[0];
    *D_004E2DB4++ = buf->b[1];
    *D_004E2DB4++ = buf->b[2];
    *D_004E2DB4++ = buf->b[3];

    buf->b[0] = D_004E2DB0[0];
    buf->b[1] = D_004E2DB0[1];
    buf->w = buf->w | D_004E2DA4;
    D_004E2DB0 += 2;
    *D_004E2DB4++ = buf->b[0];
    *D_004E2DB4++ = buf->b[1];
}

void func_0015AAF0() {
    Buffer4 *buf = &D_004E2DA0;
    func_001522C0(buf->b, D_004E2DB0);
    buf->w = buf->w | D_004E2DA4;
    D_004E2DB0 += 4;
    *D_004E2DB4++ = buf->b[0];
    *D_004E2DB4++ = buf->b[1];
    *D_004E2DB4++ = buf->b[2];
    *D_004E2DB4++ = buf->b[3];

    buf->b[0] = D_004E2DB0[0];
    buf->b[1] = D_004E2DB0[1];
    buf->w = buf->w | D_004E2DA4;
    D_004E2DB0 += 2;
    *D_004E2DB4++ = buf->b[0];
    *D_004E2DB4++ = buf->b[1];
}
