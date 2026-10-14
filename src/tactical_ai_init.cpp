
#include "sub_list.h"

extern "C" {
void *func_100730(int size);
void func_1004E0(void *ptr, void *ctor, void *dtor, int elem_size, int count);

asm void *func_001407B0(void *self, int a1, int a2, int a3, int t0) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    .word 0x3C02004D
    sq s0, 0x0(sp)
    addiu v0, v0, 0x7758
    sw v0, 0x0(a0)
    sh t0, 0x1C(a0)
    sw zero, 0x28(a0)
    sw zero, 0x2C(a0)
    sw zero, 0x30(a0)
    dsll32 v0, a1, 16
    sh a1, 0x4(a0)
    dsra32 v0, v0, 16
    paddub s1, a0, zero
    sh zero, 0x6(a0)
    dsll v0, v0, 2
    dsll32 a0, v0, 0
    paddub s2, a2, zero
    paddub s0, a3, zero
    jal func_100730
    dsra32 a0, a0, 0
    sw v0, 0x8(s1)
    sh s2, 0xC(s1)
    dsll32 s2, s2, 16
    dsra32 s2, s2, 16
    dsll v0, s2, 1
    daddu v0, v0, s2
    dsll v0, v0, 3
    daddiu v0, v0, 0x10
    dsll32 a0, v0, 0
    dsra32 a0, a0, 0
    jal func_100730
    sh zero, 0xE(s1)
    paddub a0, v0, zero
    .word 0x3C020014
    addiu a1, v0, 0x4440
    .word 0x3C020014
    addiu a2, v0, 0x4470
    addiu a3, zero, 0x18
    jal func_1004E0
    paddub t0, s2, zero
    sw v0, 0x10(s1)
    sh s0, 0x14(s1)
    dsll32 s0, s0, 16
    dsra32 s0, s0, 16
    dsll v0, s0, 1
    daddu v0, v0, s0
    dsll v0, v0, 2
    daddiu v0, v0, 0x10
    dsll32 a0, v0, 0
    dsra32 a0, a0, 0
    jal func_100730
    sh zero, 0x16(s1)
    paddub a0, v0, zero
    .word 0x3C020014
    addiu a1, v0, -0x3B10
    .word 0x3C020014
    addiu a2, v0, -0x3AF0
    addiu a3, zero, 0xC
    jal func_1004E0
    paddub t0, s0, zero
    sw v0, 0x18(s1)
    lh v0, 0x1C(s1)
    dsll v0, v0, 4
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    addiu a0, zero, -0x1
    sw v0, 0x20(s1)
    b _L00140918
    paddub a1, zero, zero
    _L001408D4:
    lw v0, 0x20(s1)
    sll v1, a1, 4
    addiu a1, a1, 0x1
    addu v0, v0, v1
    sw zero, 0x0(v0)
    lw v0, 0x20(s1)
    addu v0, v0, v1
    sw a0, 0x4(v0)
    lw v0, 0x20(s1)
    addu v0, v0, v1
    sh zero, 0x8(v0)
    lw v0, 0x20(s1)
    addu v0, v0, v1
    sh zero, 0xA(v0)
    lw v0, 0x20(s1)
    addu v0, v0, v1
    sw zero, 0xC(v0)
    _L00140918:
    lh v1, 0x1C(s1)
    slt v0, a1, v1
    bnez v0, _L001408D4
    nop
    dsll32 v0, v1, 16
    dsra32 v0, v0, 16
    dsll v0, v0, 3
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    sw v0, 0x24(s1)
    b _L00140978
    paddub v1, zero, zero
    _L0014094C:
    lw v0, 0x24(s1)
    sll a0, v1, 3
    addiu v1, v1, 0x1
    addu v0, v0, a0
    sh zero, 0x0(v0)
    lw v0, 0x24(s1)
    addu v0, v0, a0
    sh zero, 0x2(v0)
    lw v0, 0x24(s1)
    addu v0, v0, a0
    sw zero, 0x4(v0)
    _L00140978:
    lh v0, 0x1C(s1)
    slt v0, v1, v0
    bnez v0, _L0014094C
    nop
    paddub v0, s1, zero
    lq ra, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x40
    .set reorder
    .set at
}

}
