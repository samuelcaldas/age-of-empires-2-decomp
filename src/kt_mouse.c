#include "common.h"

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00134DE8);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00134E50);

extern int D_50A060;
int func_134210(int, int, int);
void func_1344C0(int);
void func_134500(int);
void func_134440(int);

void func_00134F18(void) {
}

void func_00134F20(void) {
    D_50A060 = func_134210(1, 1, 0);
}

void func_00134F50(void) {
    if (D_50A060 != -1) {
        func_1344C0(D_50A060);
        D_50A060 = -1;
    }
}

void func_00134F90(void) {
    if (D_50A060 != -1) {
        func_134500(D_50A060);
    }
}

void func_00134FB8(void) {
    if (D_50A060 != -1) {
        func_134440(D_50A060);
    }
}

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00134FE0);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135008);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135058);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135090);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001350E0);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135118);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001351B0);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001351B8);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135238);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135258);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001352D8);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001353C0);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135478);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001354A0);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001354C8);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135508);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135530);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135598);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001355D0);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135638);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001356D8);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001356E8);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135798);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135870);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135980);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001359B8);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_001359D0);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135A38);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135AB8);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135B88);

void func_134A20(void);
void func_00135BE8(void) {
    func_134A20();
}

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135BF0);

void func_00135B88(void);
int func_00135DA0(void);

void func_00135D60(void) {
    func_00135B88();
    while (func_00135DA0()) {
        func_00135BE8();
    }
}

void func_00135D98(void) {
}

typedef struct {
    char pad[0x24];
    unsigned int status;
} MouseDevice_DA0;

extern MouseDevice_DA0 D_50A240;
void func_1075C8(int);
void func_107C38(MouseDevice_DA0 *, unsigned int, int);

int func_00135DA0(void) {
    func_1075C8(0);
    func_107C38(&D_50A240, 0x80000210, 0);
    return D_50A240.status < 1;
}

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135DE8);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135E30);

INCLUDE_ASM("build/SLES-50282/asm/nonmatchings/kt_mouse", func_00135E78);
