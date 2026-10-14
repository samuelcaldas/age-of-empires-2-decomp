#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

void *func_26AF90(void *ptr, int a1, void *a2);
int func_00141170(void *self, int a1, int a2, int a3);

asm int func_00142130(TacticalAI2 *self, int a1, int a2, int a3) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    addiu v0, zero, 0x2
    addiu s0, sp, 0x2E
    sb v0, 0x2C(sp)
    .word 0xA6070000
    lw v0, 0x3C(a0)
    sll v1, a1, 2
    paddub a1, a2, zero
    addu v0, v0, v1
    lw a0, 0x0(v0)
    jal func_26AF90
    addiu a2, sp, 0x2C
    lh v1, 0x2(v0)
    lh v0, 0x0(s0)
    beq v1, v0, _L00142184
    addiu v0, zero, 0x1
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L00142184:
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

asm int func_001421A0(TacticalAI2 *self, int a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    addiu v0, zero, 0x5
    sb v0, 0x2C(sp)
    addiu v0, zero, 0x1
    addiu s0, sp, 0x2E
    addiu a0, a0, 0x34
    addiu a2, sp, 0x2C
    jal func_26AF90
    .word 0xA6020000
    lh v1, 0x2(v0)
    lh v0, 0x0(s0)
    beq v1, v0, _L001421E8
    addiu v0, zero, 0x1
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L001421E8:
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    nop
    nop
    .set reorder
    .set at
}

asm int func_00142200(TacticalAI2 *self, int a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    addiu v0, zero, 0x2
    addiu s0, sp, 0x2E
    sb v0, 0x2C(sp)
    .word 0xA6060000
    addiu a0, a0, 0x34
    jal func_26AF90
    addiu a2, sp, 0x2C
    lh v1, 0x2(v0)
    lh v0, 0x0(s0)
    beq v1, v0, _L00142244
    addiu v0, zero, 0x1
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L00142244:
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

asm int func_00142260(TacticalAI2 *self, int a1, int a2, int a3, int t0) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s0, a1, zero
    paddub a1, a2, zero
    paddub a2, a3, zero
    paddub s1, a0, zero
    jal func_00141170
    paddub a3, t0, zero
    addiu v1, zero, -0x1
    bne v0, v1, _L001422A0
    paddub a1, s0, zero
    .word 0x10000010
    paddub v0, zero, zero
    paddub a1, s0, zero
_L001422A0:
    addiu v1, zero, 0x3
    addiu s0, sp, 0x3E
    sb v1, 0x3C(sp)
    addiu a0, s1, 0x34
    addiu a2, sp, 0x3C
    jal func_26AF90
    .word 0xA6020000
    lh v1, 0x2(v0)
    lh v0, 0x0(s0)
    beq v1, v0, _L001422D8
    addiu v0, zero, 0x1
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L001422D8:
    lq ra, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x40
    nop
    .set reorder
    .set at
}

}
