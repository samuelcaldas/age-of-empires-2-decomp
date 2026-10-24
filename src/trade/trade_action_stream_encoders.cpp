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

void func_001577F0() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00157890() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00157930() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_001579D0() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00157A70() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00157B20() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

void func_00157BD0() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
}

void func_00157C80() {
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
    *D_004E2DB4++ = D_004E2DA0.b[0];
    *D_004E2DB4++ = D_004E2DA0.b[1];
}

}
