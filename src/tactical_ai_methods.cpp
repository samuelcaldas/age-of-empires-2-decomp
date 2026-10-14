#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

void func_26AE00(void *ptr, int val);
void *func_26AF90(void *ptr, int a1, void *a2);
void *func_00100630(void *ptr);
void *func_00100670(void *ptr);
void func_1456F0(void *ptr, int val);
void func_00140D40(void *self, int flag);
void Save__10TacticalAIFPv(void *self, void *stream);

asm void *func_00141F60(TacticalAI2 *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s1, a0, zero
    beqz s1, _L00142030
    paddub s0, a1, zero
    .word 0x3C02004D
    addiu v0, v0, 0x7768
    sw v0, 0x0(s1)
    .word 0x1000000A
    paddub s2, zero, zero
_L00141F94:
    lw v0, 0x3C(s1)
    sll v1, s2, 2
    addu v0, v0, v1
    lw a0, 0x0(v0)
    beql a0, zero, _L00141FB8
    addiu s2, s2, 0x1
    jal func_26AE00
    addiu a1, zero, 0x1
    addiu s2, s2, 0x1
_L00141FB8:
    lh v0, 0x1C(s1)
    slt v0, s2, v0
    bnez v0, _L00141F94
    nop
    lw a0, 0x3C(s1)
    beqz a0, _L00141FDC
    nop
    jal func_00100630
    nop
_L00141FDC:
    sw zero, 0x2A0(s1)
    sw zero, 0x2A4(s1)
    sw zero, 0x6A8(s1)
    sw zero, 0x6AC(s1)
    sw zero, 0x6B4(s1)
    addiu a0, s1, 0x44
    addiu a1, zero, -0x1
    jal func_1456F0
    sw zero, 0x3080(s1)
    addiu a0, s1, 0x34
    jal func_26AE00
    addiu a1, zero, -0x1
    paddub a0, s1, zero
    jal func_00140D40
    paddub a1, zero, zero
    dsll32 v0, s0, 16
    dsra32 v0, v0, 16
    blez v0, _L00142034
    paddub v0, s1, zero
    jal func_00100670
    .word 0x72202628
_L00142030:
    paddub v0, s1, zero
_L00142034:
    lq ra, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x40
    nop
    .set reorder
    .set at
}

asm void func_00142050() {
    .set noreorder
    .set noat
    j Save__10TacticalAIFPv
    nop
    .set reorder
    .set at
}

asm int func_00142060(TacticalAI2 *self, void *a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    addiu v0, zero, 0x1
    addiu s0, sp, 0x2E
    sb v0, 0x2C(sp)
    .word 0xA6060000
    addiu a0, a0, 0x34
    jal func_26AF90
    addiu a2, sp, 0x2C
    lh v1, 0x2(v0)
    lh v0, 0x0(s0)
    beq v1, v0, _L001420A4
    addiu v0, zero, 0x1
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L001420A4:
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    nop
    nop
    nop
    .set reorder
    .set at
}

asm int func_001420C0(TacticalAI2 *self, int a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    addiu v0, zero, 0x5
    sb v0, 0x2C(sp)
    addiu v0, zero, 0x1
    addiu s0, sp, 0x2E
    .word 0xA6020000
    lw v0, 0x3C(a0)
    sll v1, a1, 2
    paddub a1, a2, zero
    addu v0, v0, v1
    lw a0, 0x0(v0)
    jal func_26AF90
    addiu a2, sp, 0x2C
    lh v1, 0x2(v0)
    lh v0, 0x0(s0)
    beq v1, v0, _L00142118
    addiu v0, zero, 0x1
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L00142118:
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    nop
    nop
    .set reorder
    .set at
}

}
