#pragma exceptions off
#include "trade_action_stream.h"

#define COPY_BYTE() \
    *D_004E2DB4 = *D_004E2DB0; \
    D_004E2DB4++; \
    D_004E2DB0++;

void func_001522E0() {
}

void func_001522F0() {
    COPY_BYTE()
}

void func_00152320() {
    func_001522C0(D_004E2DA0, D_004E2DB0);

    D_004E2DB0 += 2;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
}

void func_00152380() {
    func_001522C0(D_004E2DA0, D_004E2DB0);

    D_004E2DB0 += 2;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
}

void func_001523E0() {
    func_001522C0(D_004E2DA0, D_004E2DB0);

    D_004E2DB0 += 3;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_00152460() {
    func_001522C0(D_004E2DA0, D_004E2DB0);

    D_004E2DB0 += 3;
    *D_004E2DB4 = D_004E2DA0[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0[2];
    D_004E2DB4++;
}

void func_001524E0() {
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
}

void func_00152590() {
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
}

void func_00152640() {
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
}

void func_001526F0() {
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
    COPY_BYTE()
}
