#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

void *func_26AF90(void *ptr, int a1, void *a2);
void func_26AD90(void *ptr, int id);
void func_26AE00(void *ptr, int val);
int func_001411E0(void *self, int a1, int a2);
int func_00141500(void *self, int a1);
int func_00141630(void *self, int a1);
void *func_100850(int size);

asm int func_001422F0(TacticalAI2 *self, int a1, int a2, int a3) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s0, a1, zero
    paddub a1, a2, zero
    paddub s1, a0, zero
    jal func_001411E0
    paddub a2, a3, zero
    addiu v1, zero, -0x1
    bne v0, v1, _L0014232C
    paddub a1, s0, zero
    .word 0x1000000F
    paddub v0, zero, zero
    paddub a1, s0, zero
_L0014232C:
    addiu s0, sp, 0x3E
    sb zero, 0x3C(sp)
    addiu a0, s1, 0x34
    addiu a2, sp, 0x3C
    jal func_26AF90
    .word 0xA6020000
    lh v1, 0x2(v0)
    lh v0, 0x0(s0)
    beq v1, v0, _L00142360
    addiu v0, zero, 0x1
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L00142360:
    lq ra, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x40
    nop
    nop
    nop
    .set reorder
    .set at
}

asm int func_00142380(TacticalAI2 *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    paddub s2, a0, zero
    jal func_00141500
    sq s0, 0x0(sp)
    paddub s0, v0, zero
    addiu v0, zero, -0x1
    beq s0, v0, _L001423DC
    paddub v0, s0, zero
    jal func_100850
    addiu a0, zero, 0x8
    beqz v0, _L001423C8
    paddub s1, v0, zero
    addiu a1, zero, 0xD3
    jal func_26AD90
    paddub a0, s1, zero
_L001423C8:
    lw v0, 0x3C(s2)
    sll v1, s0, 2
    addu v0, v0, v1
    sw s1, 0x0(v0)
    paddub v0, s0, zero
_L001423DC:
    lq ra, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x40
    nop
    nop
    nop
    .set reorder
    .set at
}

asm int func_00142400(TacticalAI2 *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s2, a0, zero
    jal func_00141630
    paddub s0, a1, zero
    bnez v0, _L00142430
    nop
    .word 0x10000015
    paddub v0, zero, zero
_L00142430:
    lw v0, 0x3C(s2)
    sll s1, s0, 2
    addu v0, v0, s1
    lw a0, 0x0(v0)
    beql a0, zero, _L00142454
    addiu a0, zero, 0x8
    jal func_26AE00
    addiu a1, zero, 0x1
    addiu a0, zero, 0x8
_L00142454:
    jal func_100850
    nop
    beqz v0, _L00142470
    paddub s0, v0, zero
    addiu a1, zero, 0xD3
    jal func_26AD90
    paddub a0, s0, zero
_L00142470:
    lw v1, 0x3C(s2)
    addiu v0, zero, 0x1
    addu v1, v1, s1
    sw s0, 0x0(v1)
_L00142480:
    lq ra, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x40
    nop
    nop
    .set reorder
    .set at
}

}
