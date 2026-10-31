#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

extern "C" {
extern void *jtbl_492BF0[];
void func_1ab8f0();
void func_001ACDF0();
void func_001AD940();
void func_001ADA70();
void func_001ADC00();
void func_1ab9d0();

/* 0x00218820 */
asm void func_00218820(void *self) {
    addiu      sp, sp, -0x40
    sq         ra, 0x30(sp)
    sq         s0, 0x20(sp)
    lw         v1, 0x1AC(a0)
    beqz       v1, lbl_00218A50
    paddub    s0, a0, zero
    lw         a0, 0x20(s0)
    jal        func_1ab8f0
    addiu     a1, zero, 0x1
    beqz       v0, lbl_00218A44
    nop
    lw         v0, 0x1AC(s0)
    sltiu      at, v0, 0x8
    beqz       at, lbl_00218A44
    nop
    la v1, jtbl_492BF0
    sll        v0, v0, 2
    addu       v0, v0, v1
    lw         v0, 0x0(v0)
    .word 0x00400008
    .word 0x00000000
lbl_00218878:
    lw         a2, 0x10(s0)
    lw         v0, 0x18(s0)
    lw         a1, 0xC(s0)
    lw         v1, 0x14(s0)
    lw         a0, 0x20(s0)
    lbu        t1, 0x194(s0)
    addu       v0, a2, v0
    addu       v1, a1, v1
    addiu      a3, v1, -0x1
    jal        func_001ACDF0
    addiu     t0, v0, -0x1
    .word 0x10000068
    .word 0x8E040020
lbl_002188AC:
    lw         a2, 0x10(s0)
    lw         v0, 0x18(s0)
    lw         a1, 0xC(s0)
    lw         v1, 0x14(s0)
    lw         a0, 0x20(s0)
    lbu        t1, 0x1B5(s0)
    lbu        t2, 0x1B0(s0)
    addu       v0, a2, v0
    addu       v1, a1, v1
    addiu      a3, v1, -0x1
    jal        func_001AD940
    addiu     t0, v0, -0x1
    .word 0x10000059
    .word 0x00000000
lbl_002188E4:
    lw         a2, 0x10(s0)
    lw         a1, 0xC(s0)
    lbu        v0, 0x1B0(s0)
    sd         v0, 0x0(sp)
    lw         v1, 0x14(s0)
    lw         v0, 0x18(s0)
    lw         a0, 0x20(s0)
    lbu        t1, 0x1B5(s0)
    lbu        t2, 0x1B4(s0)
    lbu        t3, 0x1B1(s0)
    addu       v1, a1, v1
    addu       v0, a2, v0
    addiu      a3, v1, -0x1
    jal        func_001ADA70
    addiu     t0, v0, -0x1
    .word 0x10000048
    .word 0x00000000
lbl_00218928:
    lw         a2, 0x10(s0)
    lw         a1, 0xC(s0)
    lbu        v0, 0x1B2(s0)
    sd         v0, 0x0(sp)
    lbu        v0, 0x1B1(s0)
    sd         v0, 0x8(sp)
    lbu        v0, 0x1B0(s0)
    sd         v0, 0x10(sp)
    lw         v1, 0x14(s0)
    lw         v0, 0x18(s0)
    lw         a0, 0x20(s0)
    lbu        t1, 0x1B5(s0)
    lbu        t2, 0x1B4(s0)
    lbu        t3, 0x1B3(s0)
    addu       v1, a1, v1
    addu       v0, a2, v0
    addiu      a3, v1, -0x1
    jal        func_001ADC00
    addiu     t0, v0, -0x1
    .word 0x10000033
    .word 0x00000000
lbl_0021897C:
    lw         a2, 0x10(s0)
    lw         v0, 0x18(s0)
    lw         a1, 0xC(s0)
    lw         v1, 0x14(s0)
    lw         a0, 0x20(s0)
    lbu        t1, 0x1B0(s0)
    lbu        t2, 0x1B5(s0)
    addu       v0, a2, v0
    addu       v1, a1, v1
    addiu      a3, v1, -0x1
    jal        func_001AD940
    addiu     t0, v0, -0x1
    .word 0x10000025
    .word 0x00000000
lbl_002189B4:
    lw         a2, 0x10(s0)
    lw         a1, 0xC(s0)
    lbu        v0, 0x1B5(s0)
    sd         v0, 0x0(sp)
    lw         v1, 0x14(s0)
    lw         v0, 0x18(s0)
    lw         a0, 0x20(s0)
    lbu        t1, 0x1B0(s0)
    lbu        t2, 0x1B1(s0)
    lbu        t3, 0x1B4(s0)
    addu       v1, a1, v1
    addu       v0, a2, v0
    addiu      a3, v1, -0x1
    jal        func_001ADA70
    addiu     t0, v0, -0x1
    .word 0x10000014
    .word 0x00000000
lbl_002189F8:
    lw         a2, 0x10(s0)
    lw         a1, 0xC(s0)
    lbu        v0, 0x1B3(s0)
    sd         v0, 0x0(sp)
    lbu        v0, 0x1B4(s0)
    sd         v0, 0x8(sp)
    lbu        v0, 0x1B5(s0)
    sd         v0, 0x10(sp)
    lw         v1, 0x14(s0)
    lw         v0, 0x18(s0)
    lw         a0, 0x20(s0)
    lbu        t1, 0x1B0(s0)
    lbu        t2, 0x1B1(s0)
    lbu        t3, 0x1B2(s0)
    addu       v1, a1, v1
    addu       v0, a2, v0
    addiu      a3, v1, -0x1
    jal        func_001ADC00
    addiu     t0, v0, -0x1
lbl_00218A44:
    lw         a0, 0x20(s0)
lbl_00218A48:
    jal        func_1ab9d0
    nop
lbl_00218A50:
    lq         ra, 0x30(sp)
    lq         s0, 0x20(sp)
    jr         ra
    addiu     sp, sp, 0x40
}
}

#else

extern "C" {
int func_001AB8F0(void *arg0, int arg1);
int func_001ACDF0(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5);
int func_001AD940(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6);
int func_001ADA70(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8);
int func_001ADC00(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10);
int func_001AB9D0(void *arg0);

/* 0x00218820 */
void func_00218820(void *self) {
    char *s0 = (char *)self;
    int state1AC = *(int *)(s0 + 0x1AC);
    if (state1AC == 0) {
        return;
    }

    void *arg20 = *(void **)(s0 + 0x20);
    int res = func_001AB8F0(arg20, 1);
    if (res == 0) {
        arg20 = *(void **)(s0 + 0x20);
        func_001AB9D0(arg20);
        return;
    }

    state1AC = *(int *)(s0 + 0x1AC);
    if ((unsigned int)state1AC >= 8) {
        arg20 = *(void **)(s0 + 0x20);
        func_001AB9D0(arg20);
        return;
    }

    arg20 = *(void **)(s0 + 0x20);

    void *f0c = *(void **)(s0 + 0xC);
    void *f10 = *(void **)(s0 + 0x10);
    void *f14 = *(void **)(s0 + 0x14);
    void *f18 = *(void **)(s0 + 0x18);

    int computed_arg3 = (int)((unsigned long)f0c + (unsigned long)f14 - 1);
    int computed_arg4 = (int)((unsigned long)f10 + (unsigned long)f18 - 1);

    unsigned char b1B0 = *(unsigned char *)(s0 + 0x1B0);
    unsigned char b1B1 = *(unsigned char *)(s0 + 0x1B1);
    unsigned char b1B2 = *(unsigned char *)(s0 + 0x1B2);
    unsigned char b1B3 = *(unsigned char *)(s0 + 0x1B3);
    unsigned char b1B4 = *(unsigned char *)(s0 + 0x1B4);
    unsigned char b1B5 = *(unsigned char *)(s0 + 0x1B5);
    unsigned char b194 = *(unsigned char *)(s0 + 0x194);

    switch (state1AC) {
        case 1:
            func_001ACDF0(arg20, f0c, f10, computed_arg3, computed_arg4, b194);
            break;
        case 2:
            func_001AD940(arg20, f0c, f10, computed_arg3, computed_arg4, b1B5, b1B0);
            break;
        case 3:
            func_001ADA70(arg20, f0c, f10, computed_arg3, computed_arg4, b1B5, b1B4, b1B1, b1B0);
            break;
        case 4:
            func_001ADC00(arg20, f0c, f10, computed_arg3, computed_arg4, b1B5, b1B4, b1B3, b1B2, b1B1, b1B0);
            break;
        case 5:
            func_001AD940(arg20, f0c, f10, computed_arg3, computed_arg4, b1B0, b1B5);
            break;
        case 6:
            func_001ADA70(arg20, f0c, f10, computed_arg3, computed_arg4, b1B0, b1B1, b1B4, b1B5);
            break;
        case 7:
            func_001ADC00(arg20, f0c, f10, computed_arg3, computed_arg4, b1B0, b1B1, b1B2, b1B3, b1B4, b1B5);
            break;
        default:
            break;
    }

    arg20 = *(void **)(s0 + 0x20);
    func_001AB9D0(arg20);
}
}

#endif
