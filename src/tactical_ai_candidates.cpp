#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

void *func_26B0A0(void *ptr, int a1, int a2);
void *func_26AF90(void *ptr, int a1, void *a2);
int func_00141370(void *self, int a1);
int func_142980(void *ptr);
void func_144340(void *ptr, int a1, int a2);

asm int func_00142680(TacticalAI2 *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x50
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    lw v1, 0x190(a0)
    lw v0, 0x3C(a0)
    paddub s2, a0, zero
    addiu a2, zero, 0x4
    sll v1, v1, 2
    addu v0, v0, v1
    lw a0, 0x0(v0)
    jal func_26B0A0
    paddub s1, a1, zero
    beqz v0, _L001426C8
    nop
    .word 0x10000014
    lh v0, 0x2(v0)
_L001426C8:
    lw a1, 0x190(s2)
    jal func_00141370
    paddub a0, s2, zero
    paddub s0, v0, zero
    addiu v0, zero, -0x1
    beq s0, v0, _L00142714
    paddub v0, s0, zero
    addiu v0, zero, 0x4
    sb v0, 0x4C(sp)
    sh s0, 0x4E(sp)
    lw v1, 0x190(s2)
    lw v0, 0x3C(s2)
    addiu a2, sp, 0x4C
    sll v1, v1, 2
    addu v0, v0, v1
    lw a0, 0x0(v0)
    jal func_26AF90
    paddub a1, s1, zero
    paddub v0, s0, zero
_L00142714:
    lq ra, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x50
    nop
    .set reorder
    .set at
}

asm void *func_00142730(TacticalAI2 *self, int a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    lw v1, 0x190(a0)
    lw v0, 0x3C(a0)
    paddub s2, a0, zero
    paddub s1, a1, zero
    sll v1, v1, 2
    addu v0, v0, v1
    lw a0, 0x0(v0)
    jal func_26B0A0
    paddub s0, a2, zero
    beqz v0, _L0014277C
    addiu a0, s2, 0x34
    .word 0x10000006
    lq ra, 0x30(sp)
    addiu a0, s2, 0x34
_L0014277C:
    paddub a1, s1, zero
    jal func_26B0A0
    paddub a2, s0, zero
    lq ra, 0x30(sp)
_L0014278C:
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x40
    .set reorder
    .set at
}

asm int func_001427A0(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x20
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    jal func_142980
    paddub s0, a0, zero
    addiu v1, zero, 0x2
    beq v0, v1, _L001427E8
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L001427E0
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L001427E0:
    .word 0x1000000D
    lq ra, 0x10(sp)
_L001427E8:
    lw v1, 0x19C(s0)
    addiu v0, zero, 0x3
    beq v1, v0, _L00142814
    addiu v0, zero, 0x1
    addiu a1, zero, 0x8
    paddub a0, s0, zero
    jal func_144340
    paddub a2, zero, zero
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L00142814:
    lq ra, 0x10(sp)
_L00142818:
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    nop
    nop
    nop
    .set reorder
    .set at
}

}
