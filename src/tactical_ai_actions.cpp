#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

void *func_001407B0(void *self, int a1, int a2, int a3, int t0);
void *func_001409B0(void *self, void *stream);
void func_26AD90(void *ptr, int id);
void func_145680(void *ptr);
void *func_100730(int size);

asm void *func_00141D40(TacticalAI2 *self, int a1, int a2, int a3, int t0) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    sw a0, 0x2C(sp)
    lw a0, 0x2C(sp)
    jal func_001407B0
    paddub s0, t0, zero
    .word 0x3C02004D
    addiu v1, v0, 0x7768
    lw v0, 0x2C(sp)
    addiu a1, zero, 0x3F5
    sw v1, 0x0(v0)
    lw v0, 0x2C(sp)
    jal func_26AD90
    addiu a0, v0, 0x34
    lw v0, 0x2C(sp)
    jal func_145680
    addiu a0, v0, 0x44
    dsll32 v0, s0, 16
    dsra32 v0, v0, 16
    dsll v0, v0, 2
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    lw v1, 0x2C(sp)
    dsll32 a1, s0, 16
    dsra32 a1, a1, 16
    paddub a0, zero, zero
    b _L00141DD0
    sw v0, 0x3C(v1)
_L00141DB8:
    lw v0, 0x2C(sp)
    sll v1, a0, 2
    addiu a0, a0, 0x1
    lw v0, 0x3C(v0)
    addu v0, v0, v1
    sw zero, 0x0(v0)
_L00141DD0:
    slt v0, a0, a1
    bnez v0, _L00141DB8
    nop
    lw v0, 0x2C(sp)
    addiu a0, zero, -0x1
    addiu v1, zero, 0x1
    addiu a2, zero, 0x28F0
    sw zero, 0x40(v0)
    lw v0, 0x2C(sp)
    paddub a1, zero, zero
    sw a0, 0x18C(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x190(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x194(v0)
    lw v0, 0x2C(sp)
    sw v1, 0x198(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x19C(v0)
    lw v0, 0x2C(sp)
    sb zero, 0x1A0(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x2A0(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x2A4(v0)
    lw v0, 0x2C(sp)
    sb zero, 0x2A8(v0)
    lw v1, 0x2C(sp)
    addiu v0, v1, 0x2A8
    sw v0, 0x6A8(v1)
    lw v0, 0x2C(sp)
    sw zero, 0x6AC(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x6B0(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x6B4(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x6B8(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x6BC(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x6C0(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x2FB4(v0)
    lw v0, 0x2C(sp)
    sw zero, 0x3080(v0)
    lw v0, 0x2C(sp)
    jal memset
    addiu a0, v0, 0x6C4
    lw v0, 0x2C(sp)
    addiu a2, zero, 0xC8
    paddub a1, zero, zero
    jal memset
    addiu a0, v0, 0x2FB8
    lw v0, 0x2C(sp)
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    .set reorder
    .set at
}

asm void *func_00141EC0(TacticalAI2 *self, void *stream) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x20
    sq ra, 0x0(sp)
    sw a0, 0x1C(sp)
    jal func_001409B0
    lw a0, 0x1C(sp)
    .word 0x3C02004D
    addiu v1, v0, 0x7768
    lw v0, 0x1C(sp)
    addiu a1, zero, 0x3F5
    sw v1, 0x0(v0)
    lw v0, 0x1C(sp)
    jal func_26AD90
    addiu a0, v0, 0x34
    lw v0, 0x1C(sp)
    jal func_145680
    addiu a0, v0, 0x44
    lw v0, 0x1C(sp)
    lh v0, 0x1C(v0)
    dsll v0, v0, 2
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    lw v1, 0x1C(sp)
    paddub a0, zero, zero
    b _L00141F3C
    sw v0, 0x3C(v1)
_L00141F28:
    lw v0, 0x3C(v0)
    sll v1, a0, 2
    addiu a0, a0, 0x1
    addu v0, v0, v1
    sw zero, 0x0(v0)
_L00141F3C:
    lw v0, 0x1C(sp)
    lh v1, 0x1C(v0)
    slt v1, a0, v1
    bnez v1, _L00141F28
    nop
    lq ra, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    .set reorder
    .set at
}

}
