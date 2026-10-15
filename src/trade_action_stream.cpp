#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern void *D_004E2D94; // src
extern void *D_004E2D98; // dst
extern char D_004E2D84[]; // buffer

void func_001522C0(void *buf, void *src);

void func_001522E0() {
}

void func_001522F0() {
    char *src = (char *)D_004E2D94;
    char *dst = (char *)D_004E2D98;
    *dst = *src;
    D_004E2D98 = dst + 1;
    D_004E2D94 = src + 1;
}

void func_00152320() {
    func_001522C0(D_004E2D84, D_004E2D94);
    char *src = (char *)D_004E2D94;
    char *dst = (char *)D_004E2D98;
    D_004E2D94 = src + 2;
    *dst = D_004E2D84[0];
    dst = (char *)D_004E2D98 + 1;
    D_004E2D98 = dst;
    *dst = D_004E2D84[1];
    D_004E2D98 = dst + 1;
}

void func_00152380() {
    func_001522C0(D_004E2D84, D_004E2D94);
    char *src = (char *)D_004E2D94;
    char *dst = (char *)D_004E2D98;
    D_004E2D94 = src + 2;
    *dst = D_004E2D84[0];
    dst = (char *)D_004E2D98 + 1;
    D_004E2D98 = dst;
    *dst = D_004E2D84[1];
    D_004E2D98 = dst + 1;
}

void func_001523E0() {
    func_001522C0(D_004E2D84, D_004E2D94);
    char *src = (char *)D_004E2D94;
    char *dst = (char *)D_004E2D98;
    D_004E2D94 = src + 3;
    *dst = D_004E2D84[0];
    dst = (char *)D_004E2D98 + 1;
    D_004E2D98 = dst;
    *dst = D_004E2D84[1];
    dst = (char *)D_004E2D98 + 1;
    D_004E2D98 = dst;
    *dst = D_004E2D84[2];
    D_004E2D98 = dst + 1;
}

void func_00152460() {
    func_001522C0(D_004E2D84, D_004E2D94);
    char *src = (char *)D_004E2D94;
    char *dst = (char *)D_004E2D98;
    D_004E2D94 = src + 3;
    *dst = D_004E2D84[0];
    dst = (char *)D_004E2D98 + 1;
    D_004E2D98 = dst;
    *dst = D_004E2D84[1];
    dst = (char *)D_004E2D98 + 1;
    D_004E2D98 = dst;
    *dst = D_004E2D84[2];
    D_004E2D98 = dst + 1;
}

static inline void copy4() {
    char *src = (char *)D_004E2D94;
    char *dst = (char *)D_004E2D98;
    *dst = *src;
    dst = (char *)D_004E2D98 + 1;
    D_004E2D98 = dst;
    src = (char *)D_004E2D94 + 1;
    D_004E2D94 = src;

    *dst = *src;
    dst = (char *)D_004E2D98 + 1;
    D_004E2D98 = dst;
    src = (char *)D_004E2D94 + 1;
    D_004E2D94 = src;

    *dst = *src;
    dst = (char *)D_004E2D98 + 1;
    D_004E2D98 = dst;
    src = (char *)D_004E2D94 + 1;
    D_004E2D94 = src;

    *dst = *src;
    dst = (char *)D_004E2D98 + 1;
    D_004E2D98 = dst;
    src = (char *)D_004E2D94 + 1;
    D_004E2D94 = src;
}

void func_001524E0() {
    copy4();
}

void func_00152590() {
    copy4();
}

void func_00152640() {
    copy4();
}

void func_001526F0() {
    copy4();
}

}
