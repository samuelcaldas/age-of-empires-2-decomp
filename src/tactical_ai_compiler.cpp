#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

int func_142980(void *ptr);
void func_144340(void *ptr, int a1, int a2);
void *func_26B0A0(void *ptr, void *a1, int a2);
int func_00142CC0(void *self);
int func_00143020(TacticalAI2 *self, int a1);
int func_001427A0(void *self);
int func_1446A0(void *ptr);
int func_114378(const char *str);
void *func_00142730(void *self, void *buf, int a2);

asm int func_00143020(TacticalAI2 *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x50
    sq ra, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    bnez a1, _L001430A0
    paddub s3, a0, zero
    jal func_142980
    nop
    addiu v1, zero, 0x2
    beq v0, v1, _L0014307C
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L00143074
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L00143074:
    .word 0x100000E9
    lq ra, 0x40(sp)
_L0014307C:
    lw v0, 0x19C(s3)
    beq v0, v1, _L001430A4
    paddub a0, s3, zero
    addiu a1, zero, 0xF
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    .word 0x100000DF
    paddub v0, zero, zero
_L001430A0:
    paddub a0, s3, zero
_L001430A4:
    jal func_142980
    nop
    addiu v1, zero, 0x2
    beq v0, v1, _L001430E0
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L001430D8
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L001430D8:
    .word 0x100000CF
    nop
_L001430E0:
    lw v0, 0x19C(s3)
    addiu a2, zero, 0x1
    beq v0, a2, _L0014310C
    addiu a0, s3, 0x34
    addiu a1, zero, 0xC
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    .word 0x100000C5
    paddub v0, zero, zero
    addiu a0, s3, 0x34
_L0014310C:
    jal func_26B0A0
    addiu a1, s3, 0x1A0
    paddub s0, v0, zero
    beqz s0, _L001431E4
    addiu a0, s3, 0x34
    lw v1, 0x40(s3)
    addiu a1, zero, 0x2
    paddub a0, s3, zero
    sll v0, v1, 2
    addu v0, v0, v1
    sll v0, v0, 2
    addu v0, v0, s3
    sh a1, 0x4C(v0)
    lw v1, 0x40(s3)
    lh a1, 0x2(s0)
    sll v0, v1, 2
    addu v0, v0, v1
    sll v0, v0, 2
    addu v0, v0, s3
    jal func_00142CC0
    sh a1, 0x4E(v0)
    bnez v0, _L00143174
    paddub a0, s3, zero
    .word 0x100000AB
    paddub v0, zero, zero
    paddub a0, s3, zero
_L00143174:
    jal func_00143020
    paddub a1, zero, zero
    bnez v0, _L0014318C
    nop
    .word 0x100000A4
    paddub v0, zero, zero
_L0014318C:
    lh v0, 0x2(s0)
    beqz v0, _L001431D0
    paddub a0, s3, zero
    jal func_00142CC0
    .word 0x72602628
    bnez v0, _L001431B4
    paddub a0, s3, zero
    .word 0x1000009B
    paddub v0, zero, zero
    paddub a0, s3, zero
_L001431B4:
    jal func_00143020
    paddub a1, zero, zero
    bnez v0, _L001431CC
    nop
    .word 0x10000094
    paddub v0, zero, zero
_L001431CC:
    paddub a0, s3, zero
_L001431D0:
    jal func_001427A0
    nop
    .word 0x1000008F
    nop
    addiu a0, s3, 0x34
_L001431E4:
    addiu a1, s3, 0x1A0
    jal func_26B0A0
    addiu a2, zero, 0x3
    paddub s2, v0, zero
    bnez s2, _L00143214
    nop
    addiu a2, s3, 0x1A0
    addiu a1, zero, 0x3
    jal func_144340
    paddub a0, s3, zero
    .word 0x10000082
    paddub v0, zero, zero
_L00143214:
    lh a0, 0x2(s2)
    lw v0, 0x10(s3)
    sll v1, a0, 1
    addu v1, v1, a0
    sll v1, v1, 3
    jal func_1446A0
    addu a0, v0, v1
    lw v1, 0x40(s3)
    paddub s0, v0, zero
    addiu a0, zero, 0x3
    paddub s1, zero, zero
    sll v0, v1, 2
    addu v0, v0, v1
    sll v0, v0, 2
    addu v0, v0, s3
    sh a0, 0x4C(v0)
    lw v1, 0x40(s3)
    lh a0, 0x2(s2)
    sll v0, v1, 2
    addu v0, v0, v1
    sll v0, v0, 2
    addu v0, v0, s3
    .word 0x10000065
    sh a0, 0x4E(v0)
_L00143274:
    jal func_142980
    paddub a0, s3, zero
    addiu a2, zero, 0x2
    beq v0, a2, _L001432B0
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L001432A8
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L001432A8:
    .word 0x1000005B
    nop
_L001432B0:
    lw v1, 0x19C(s3)
    addiu v0, zero, 0x1
    beq v1, v0, _L001432D8
    nop
    addiu a1, zero, 0xC
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    .word 0x10000051
    paddub v0, zero, zero
_L001432D8:
    lb v1, 0x1A0(s3)
    .word 0x3C020048
    addiu v0, v0, -0x1F00
    addu v0, v0, v1
    lb v0, 0x1(v0)
    andi v0, v0, 0x4
    bnez v0, _L0014331C
    addiu a0, s3, 0x1A0
    dsll32 v1, v1, 24
    addiu v0, zero, 0x2B
    dsra32 v1, v1, 24
    beq v1, v0, _L00143318
    nop
    addiu v0, zero, 0x2D
    bne v1, v0, _L00143330
    .word 0x266501A0
_L00143318:
    addiu a0, s3, 0x1A0
_L0014331C:
    jal func_114378
    nop
    .word 0x1000000F
    addiu v1, zero, 0x3
    addiu a1, s3, 0x1A0
_L00143330:
    jal func_00142730
    paddub a0, s3, zero
    bnez v0, _L00143358
    nop
    addiu a2, s3, 0x1A0
    addiu a1, zero, 0x3
    jal func_144340
    paddub a0, s3, zero
    .word 0x10000031
    paddub v0, zero, zero
_L00143358:
    lh v0, 0x2(v0)
    nop
    addiu v1, zero, 0x3
_L00143364:
    beq s1, v1, _L001433E8
    nop
    addiu v1, zero, 0x2
    beq s1, v1, _L001433CC
    nop
    addiu v1, zero, 0x1
    beq s1, v1, _L001433B0
    nop
    beqz s1, _L00143394
    nop
    .word 0x1000001D
    addiu s1, s1, 0x1
_L00143394:
    lw a0, 0x40(s3)
    sll v1, a0, 2
    addu v1, v1, a0
    sll v1, v1, 2
    addu v1, s3, v1
    .word 0x10000015
    sw v0, 0x50(v1)
_L001433B0:
    lw a0, 0x40(s3)
    sll v1, a0, 2
    addu v1, v1, a0
    sll v1, v1, 2
    addu v1, s3, v1
    .word 0x1000000E
    sw v0, 0x54(v1)
_L001433CC:
    lw a0, 0x40(s3)
    sll v1, a0, 2
    addu v1, v1, a0
    sll v1, v1, 2
    addu v1, s3, v1
    .word 0x10000007
    sw v0, 0x58(v1)
_L001433E8:
    lw a0, 0x40(s3)
    sll v1, a0, 2
    addu v1, v1, a0
    sll v1, v1, 2
    addu v1, s3, v1
    sw v0, 0x5C(v1)
_L00143400:
    addiu s1, s1, 0x1
_L00143404:
    slt v0, s1, s0
    bnez v0, _L00143274
    nop
    jal func_001427A0
    paddub a0, s3, zero
_L00143418:
    lq ra, 0x40(sp)
_L0014341C:
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x50
    nop
    nop
    nop
    .set reorder
    .set at
}

}
