
#include "sub_list.h"

extern "C" {
void *func_100730(int size);
void func_1004E0(void *ptr, void *ctor, void *dtor, int elem_size, int count);
void func_1002A0(void *ptr, void *fn, int count);
void func_00100630(void *ptr);
void func_00100670(void *ptr);
void func_00226D90(void *stream, void *dst, int size);
void func_116F40(void*, void*, int);
void func_116F68(void*, void*, int);

asm void *func_001409B0(void *self, void *stream) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x70
    sq ra, 0x50(sp)
    sq s4, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    .word 0x3C02004D
    sq s0, 0x0(sp)
    addiu v0, v0, 0x7758
    paddub s1, a0, zero
    paddub s0, a1, zero
    sw v0, 0x0(a0)
    addiu a1, s1, 0x4
    addiu a2, zero, 0x8
    jal func_00226D90
    paddub a0, s0, zero
    lh v0, 0x4(s1)
    dsll v0, v0, 2
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    sw v0, 0x8(s1)
    b _L00140A70
    paddub s2, zero, zero
    _L00140A14:
    addiu a1, sp, 0x6C
    addiu a2, zero, 0x4
    jal func_00226D90
    paddub a0, s0, zero
    lw v0, 0x6C(sp)
    jal func_116F40
    addiu a0, v0, 0x1
    lw v1, 0x8(s1)
    sll s3, s2, 2
    addu v1, v1, s3
    sw v0, 0x0(v1)
    lw v0, 0x8(s1)
    lw a2, 0x6C(sp)
    addu v0, v0, s3
    lw a1, 0x0(v0)
    jal func_00226D90
    paddub a0, s0, zero
    lw v1, 0x8(s1)
    lw v0, 0x6C(sp)
    addiu s2, s2, 0x1
    addu v1, v1, s3
    lw v1, 0x0(v1)
    addu v0, v1, v0
    sb zero, 0x0(v0)
    _L00140A70:
    lh v0, 0x6(s1)
    slt v0, s2, v0
    bnez v0, _L00140A14
    addiu a1, sp, 0x6C
    addiu a1, s1, 0xC
    addiu a2, zero, 0x2
    jal func_00226D90
    paddub a0, s0, zero
    sh zero, 0xE(s1)
    lh s2, 0xC(s1)
    dsll v0, s2, 1
    daddu v0, v0, s2
    dsll v0, v0, 3
    daddiu v0, v0, 0x10
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    paddub a0, v0, zero
    .word 0x3C020014
    addiu a1, v0, 0x4440
    .word 0x3C020014
    addiu a2, v0, 0x4470
    addiu a3, zero, 0x18
    jal func_1004E0
    paddub t0, s2, zero
    addiu a1, s1, 0x14
    addiu a2, zero, 0x2
    sw v0, 0x10(s1)
    jal func_00226D90
    paddub a0, s0, zero
    sh zero, 0x16(s1)
    lh s2, 0x14(s1)
    dsll v0, s2, 1
    daddu v0, v0, s2
    dsll v0, v0, 2
    daddiu v0, v0, 0x10
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    paddub a0, v0, zero
    .word 0x3C020014
    addiu a1, v0, -0x3B10
    .word 0x3C020014
    addiu a2, v0, -0x3AF0
    addiu a3, zero, 0xC
    jal func_1004E0
    paddub t0, s2, zero
    addiu a1, s1, 0x1C
    addiu a2, zero, 0x2
    sw v0, 0x18(s1)
    jal func_00226D90
    paddub a0, s0, zero
    lh v0, 0x1C(s1)
    dsll v0, v0, 4
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    sw v0, 0x20(s1)
    b _L00140C24
    paddub s2, zero, zero
    _L00140B60:
    lw v0, 0x20(s1)
    sll v1, s2, 4
    addiu a2, zero, 0x10
    paddub a0, s0, zero
    addu s3, v0, v1
    jal func_00226D90
    paddub a1, s3, zero
    lw v0, 0x0(s3)
    bnez v0, _L00140B90
    nop
    b _L00140C20
    sw zero, 0xC(s3)
    _L00140B90:
    lh s4, 0x8(s3)
    dsll v0, s4, 2
    daddu v0, v0, s4
    dsll v0, v0, 3
    daddu v0, v0, s4
    dsll v0, v0, 3
    daddiu v0, v0, 0x10
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    paddub a0, v0, zero
    .word 0x3C020014
    addiu a1, v0, 0x5680
    .word 0x3C020014
    addiu a2, v0, 0x56F0
    addiu a3, zero, 0x148
    jal func_1004E0
    paddub t0, s4, zero
    sw v0, 0xC(s3)
    b _L00140C10
    paddub s4, zero, zero
    _L00140BE8:
    sll v0, s4, 2
    addu v1, v0, s4
    lw v0, 0xC(s3)
    sll v1, v1, 3
    addu v1, v1, s4
    sll v1, v1, 3
    addiu a2, zero, 0x148
    addu a1, v0, v1
    jal func_00226D90
    paddub a0, s0, zero
    addiu s4, s4, 0x1
    _L00140C10:
    lh v0, 0xA(s3)
    slt v0, s4, v0
    bnez v0, _L00140BE8
    sll v0, s4, 2
    _L00140C20:
    addiu s2, s2, 0x1
    _L00140C24:
    lh v1, 0x1C(s1)
    slt v0, s2, v1
    bnez v0, _L00140B60
    nop
    dsll32 v0, v1, 16
    dsra32 v0, v0, 16
    dsll v0, v0, 3
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    sw v0, 0x24(s1)
    b _L00140CF4
    paddub s2, zero, zero
    _L00140C58:
    lw v0, 0x24(s1)
    sll v1, s2, 3
    addiu a2, zero, 0x8
    paddub a0, s0, zero
    addu s3, v0, v1
    jal func_00226D90
    paddub a1, s3, zero
    lw v0, 0x20(s1)
    sll v1, s2, 4
    addu v0, v0, v1
    lw v0, 0x0(v0)
    bnez v0, _L00140C94
    nop
    b _L00140CF0
    sw zero, 0x4(s3)
    _L00140C94:
    lh v0, 0x0(s3)
    dsll v0, v0, 1
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    sw v0, 0x4(s3)
    lh v0, 0x2(s3)
    lw a1, 0x4(s3)
    paddub a0, s0, zero
    jal func_00226D90
    sll a2, v0, 1
    lh a1, 0x2(s3)
    b _L00140CE0
    addiu a0, zero, -0x1
    _L00140CCC:
    lw v0, 0x4(s3)
    sll v1, a1, 1
    addiu a1, a1, 0x1
    addu v0, v0, v1
    sh a0, 0x0(v0)
    _L00140CE0:
    lh v0, 0x0(s3)
    slt v0, a1, v0
    bnez v0, _L00140CCC
    nop
    _L00140CF0:
    addiu s2, s2, 0x1
    _L00140CF4:
    lh v0, 0x1C(s1)
    slt v0, s2, v0
    bnez v0, _L00140C58
    nop
    sw zero, 0x28(s1)
    sw zero, 0x2C(s1)
    sw zero, 0x30(s1)
    paddub v0, s1, zero
    lq ra, 0x50(sp)
    lq s4, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x70
    .set reorder
    .set at
}

asm void *func_00140D40(void *self, int flag) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    paddub s2, a0, zero
    sq s0, 0x0(sp)
    beqz s2, _L00140ECC
    paddub s1, a1, zero
    .word 0x3C02004D
    addiu v0, v0, 0x7758
    sw v0, 0x0(s2)
    b _L00140D8C
    paddub s0, zero, zero
    _L00140D74:
    lw v0, 0x8(s2)
    sll v1, s0, 2
    addu v0, v0, v1
    jal func_116F68
    lw a0, 0x0(v0)
    addiu s0, s0, 0x1
    _L00140D8C:
    lh v0, 0x6(s2)
    slt v0, s0, v0
    bnez v0, _L00140D74
    nop
    lw a0, 0x8(s2)
    beqz a0, _L00140DB0
    nop
    jal func_00100630
    nop
    _L00140DB0:
    lw a0, 0x10(s2)
    beqz a0, _L00140DC8
    nop
    .word 0x3C020014
    jal func_1002A0
    addiu a1, v0, 0x4470
    _L00140DC8:
    lw a0, 0x18(s2)
    beqz a0, _L00140DE4
    paddub s0, zero, zero
    .word 0x3C020014
    jal func_1002A0
    addiu a1, v0, -0x3AF0
    paddub s0, zero, zero
    _L00140DE4:
    b _L00140E24
    lh v0, 0x1C(s2)
    _L00140DEC:
    lw v0, 0x20(s2)
    sll v1, s0, 4
    addu v1, v0, v1
    lw v0, 0x0(v1)
    beql v0, zero, _L00140E20
    addiu s0, s0, 0x1
    lw a0, 0xC(v1)
    beqz a0, _L00140E1C
    nop
    .word 0x3C020014
    jal func_1002A0
    addiu a1, v0, 0x56F0
    _L00140E1C:
    addiu s0, s0, 0x1
    _L00140E20:
    lh v0, 0x1C(s2)
    _L00140E24:
    slt v0, s0, v0
    bnez v0, _L00140DEC
    nop
    b _L00140E74
    paddub s0, zero, zero
    _L00140E38:
    lw v0, 0x20(s2)
    sll v1, s0, 4
    addu v0, v0, v1
    lw v0, 0x0(v0)
    beql v0, zero, _L00140E74
    addiu s0, s0, 0x1
    lw v0, 0x24(s2)
    sll v1, s0, 3
    addu v0, v0, v1
    lw a0, 0x4(v0)
    beqz a0, _L00140E70
    nop
    jal func_00100630
    nop
    _L00140E70:
    addiu s0, s0, 0x1
    _L00140E74:
    lh v0, 0x1C(s2)
    slt v0, s0, v0
    bnez v0, _L00140E38
    nop
    lw a0, 0x24(s2)
    beqz a0, _L00140E98
    nop
    jal func_00100630
    nop
    _L00140E98:
    lw a0, 0x20(s2)
    beqz a0, _L00140EAC
    nop
    jal func_00100630
    nop
    _L00140EAC:
    sw zero, 0x28(s2)
    dsll32 v0, s1, 16
    sw zero, 0x2C(s2)
    dsra32 v0, v0, 16
    blez v0, _L00140ECC
    sw zero, 0x30(s2)
    jal func_00100670
    paddub a0, s2, zero
    _L00140ECC:
    paddub v0, s2, zero
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
