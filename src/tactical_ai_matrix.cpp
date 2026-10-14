
#include "sub_list.h"

struct TacticalAI {
    void *m_vtable;
    char pad_04[0x30];
};

extern "C" {
void *func_100730(int size);
void func_1004E0(void *ptr, void *ctor, void *dtor, int elem_size, int count);
void func_1002A0(void *ptr, void *fn, int count);
void func_00100630(void *ptr);
int func_141A20(void *self, int a1);
void func_141C70(void*, int);
void func_144530(void*, void*, int);

asm int func_00141500(TacticalAI *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x50
    sq ra, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s3, a0, zero
    lh a0, 0x1C(a0)
    b _L00141600
    paddub s0, zero, zero
    _L00141528:
    lw v0, 0x20(s3)
    sll v1, s0, 4
    addu s2, v0, v1
    lw v0, 0x0(s2)
    bnel v0, zero, _L00141600
    addiu s0, s0, 0x1
    addiu v0, zero, 0x1
    dsll32 s1, a1, 16
    sw v0, 0x0(s2)
    dsra32 s1, s1, 16
    dsll v0, s1, 2
    daddu v0, v0, s1
    dsll v0, v0, 3
    daddu v0, v0, s1
    dsll v0, v0, 3
    daddiu v0, v0, 0x10
    sw s0, 0x4(s2)
    dsll32 a0, v0, 0
    sh a1, 0x8(s2)
    dsra32 a0, a0, 0
    jal func_100730
    sh zero, 0xA(s2)
    paddub a0, v0, zero
    .word 0x3C020014
    addiu a1, v0, 0x5680
    .word 0x3C020014
    addiu a2, v0, 0x56F0
    addiu a3, zero, 0x148
    jal func_1004E0
    paddub t0, s1, zero
    sw v0, 0xC(s2)
    lw v1, 0x24(s3)
    sll a1, s0, 3
    addiu v0, zero, 0x64
    addiu a0, zero, 0xC8
    addu s0, v1, a1
    sh v0, 0x0(s0)
    jal func_100730
    sh zero, 0x2(s0)
    addiu a0, zero, -0x1
    sw v0, 0x4(s0)
    b _L001415E8
    paddub a1, zero, zero
    _L001415D4:
    lw v0, 0x4(s0)
    sll v1, a1, 1
    addiu a1, a1, 0x1
    addu v0, v0, v1
    sh a0, 0x0(v0)
    _L001415E8:
    slti v0, a1, 0x64
    bnez v0, _L001415D4
    nop
    .word 0x10000006
    lw v0, 0x4(s2)
    addiu s0, s0, 0x1
    _L00141600:
    slt v0, s0, a0
    bnez v0, _L00141528
    nop
    addiu v0, zero, -0x1
    _L00141610:
    lq ra, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x50
    nop
    .set reorder
    .set at
}

asm int func_00141630(TacticalAI *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x50
    sq ra, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    paddub s3, a0, zero
    paddub s2, a1, zero
    jal func_141A20
    sq s0, 0x0(sp)
    bnez v0, _L00141664
    nop
    b _L00141740
    paddub v0, zero, zero
    _L00141664:
    lw v0, 0x20(s3)
    sll v1, s2, 4
    addu s0, v0, v1
    lw a0, 0xC(s0)
    beqz a0, _L00141688
    nop
    .word 0x3C020014
    jal func_1002A0
    addiu a1, v0, 0x56F0
    _L00141688:
    sh zero, 0xA(s0)
    lh s1, 0x8(s0)
    dsll v0, s1, 2
    daddu v0, v0, s1
    dsll v0, v0, 3
    daddu v0, v0, s1
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
    paddub t0, s1, zero
    sw v0, 0xC(s0)
    lw v0, 0x24(s3)
    sll v1, s2, 3
    addu s0, v0, v1
    lw a0, 0x4(s0)
    beqz a0, _L001416FC
    addiu v0, zero, 0x64
    jal func_00100630
    nop
    addiu v0, zero, 0x64
    _L001416FC:
    sh v0, 0x0(s0)
    addiu a0, zero, 0xC8
    jal func_100730
    sh zero, 0x2(s0)
    addiu a0, zero, -0x1
    sw v0, 0x4(s0)
    b _L00141730
    paddub a1, zero, zero
    _L0014171C:
    lw v0, 0x4(s0)
    sll v1, a1, 1
    addiu a1, a1, 0x1
    addu v0, v0, v1
    sh a0, 0x0(v0)
    _L00141730:
    slti v0, a1, 0x64
    bnez v0, _L0014171C
    nop
    addiu v0, zero, 0x1
    _L00141740:
    lq ra, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x50
    .set reorder
    .set at
}

asm int func_00141760(TacticalAI *self, int a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x60
    sq ra, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s2, a2, zero
    paddub s3, a0, zero
    jal func_141A20
    paddub s0, a1, zero
    bnez v0, _L00141798
    nop
    b _L00141894
    paddub v0, zero, zero
    _L00141798:
    lw v0, 0x20(s3)
    sll a0, s0, 4
    sll v1, s0, 3
    paddub s0, zero, zero
    addu v0, v0, a0
    sw v0, 0x2C(s3)
    lw v0, 0x24(s3)
    addu v0, v0, v1
    .word 0x10000008
    sw v0, 0x30(s3)
    sll v0, s0, 1
    _L001417C4:
    addu v1, v0, s0
    lw v0, 0x10(s3)
    sll v1, v1, 3
    jal func_144530
    addu a0, v0, v1
    addiu s0, s0, 0x1
    _L001417DC:
    lh v0, 0xE(s3)
    slt v0, s0, v0
    bnez v0, _L001417C4
    sll v0, s0, 1
    lw v0, 0x2C(s3)
    addiu s1, sp, 0x5E
    paddub s0, zero, zero
    lh v0, 0xA(v0)
    sh v0, 0x5C(sp)
    b _L00141854
    .word 0xA6200000
    _L00141808:
    lw v0, 0xC(v1)
    sll v1, s0, 2
    addu v1, v1, s0
    sll v1, v1, 3
    addu v1, v1, s0
    sll v1, v1, 3
    addu a1, v0, v1
    lbu v0, 0x5(a1)
    beql v0, zero, _L00141854
    addiu s0, s0, 0x1
    sw a1, 0x28(s3)
    jal func_141C70
    paddub a0, s3, zero
    beqz v0, _L00141850
    nop
    lh v0, 0x0(s1)
    addiu v0, v0, 0x1
    sh v0, 0x0(s1)
    _L00141850:
    addiu s0, s0, 0x1
    _L00141854:
    lw v1, 0x2C(s3)
    lh v0, 0xA(v1)
    slt v0, s0, v0
    bnez v0, _L00141808
    nop
    beqz s2, _L00141884
    nop
    addiu v0, sp, 0x5C
    .word 0x84430000
    .word 0x84420002
    sh v1, 0x0(s2)
    sh v0, 0x2(s2)
    _L00141884:
    sw zero, 0x28(s3)
    sw zero, 0x2C(s3)
    addiu v0, zero, 0x1
    sw zero, 0x30(s3)
    _L00141894:
    lq ra, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x60
    .set reorder
    .set at
}

asm int func_001418B0(TacticalAI *self, int a1) {
    .set noreorder
    .set noat
    lw v0, 0x28(a0)
    bnez v0, _L001418C4
    nop
    b _L001418CC
    paddub v0, zero, zero
    _L001418C4:
    sb zero, 0x5(v0)
    addiu v0, zero, 0x1
    _L001418CC:
    jr ra
    nop
    .set reorder
    .set at
}

}
