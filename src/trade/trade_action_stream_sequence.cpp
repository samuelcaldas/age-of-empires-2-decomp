#pragma exceptions off
#include "sub_list.h"

extern "C" {

union Buffer4 {
    unsigned char b[4];
    int w;
    unsigned int u;
};

extern unsigned char *D_004E2DB4;
extern Buffer4 D_004E2DA0;

void func_00158A00() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00158A20() {
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00158A40() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00158A80() {
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00158AC0() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00158B10() {
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00158B60() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00158BB0() {
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00158C00() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];
}

void func_00158C70() {
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00158CE0() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00158D50() {
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00158DC0() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[2];
    *D_004E2DB4++ = D_004E2DA0.b[3];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00158E40() {
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00158EC0() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

}
