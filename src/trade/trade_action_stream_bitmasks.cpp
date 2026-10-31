#pragma exceptions off
#include "trade_action_stream_bitmasks.h"

extern "C" {

void func_001550A0() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 2;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;

    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4++;
}

void func_001551A0() {
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
}

void func_001552A0() {
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

void func_001553C0() {
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

    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4++;
}

void func_001554E0() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 2;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
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
}

}
