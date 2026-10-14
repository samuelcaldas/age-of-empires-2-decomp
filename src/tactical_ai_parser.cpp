#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

int func_142980(void *ptr);
void func_144340(void *ptr, int a1, int a2);
void *func_26B0A0(void *ptr, void *a1, int a2);
int func_0013C650(void *ptr);
int func_001410E0(void *self, void *buf);
int func_114378(const char *str);
void *func_00142730(void *self, void *buf, int a2);
int func_001427A0(void *self);

asm int func_00142D10(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x50
    sq ra, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    paddub s3, a0, zero
    jal func_142980
    sq s0, 0x0(sp)
    addiu v1, zero, 0x2
    beq v0, v1, _L00142D60
    addiu v1, zero, 0x1
    bne v0, v1, _L00142D58
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L00142D58:
    .word 0x100000A9
    lq ra, 0x40(sp)
_L00142D60:
    lw v1, 0x19C(s3)
    addiu v0, zero, 0x1
    beq v1, v0, _L00142D88
    addiu a0, s3, 0x34
    addiu a1, zero, 0xC
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    .word 0x1000009E
    paddub v0, zero, zero
_L00142D88:
    addiu a1, s3, 0x1A0
    jal func_26B0A0
    .word 0x70003628
    paddub s0, v0, zero
    bnez s0, _L00142DB4
    addiu a2, s3, 0x1A0
    addiu a1, zero, 0x3
    jal func_144340
    paddub a0, s3, zero
    .word 0x10000093
    paddub v0, zero, zero
_L00142DB4:
    lh a0, 0x2(s0)
    lw v0, 0x18(s3)
    sll v1, a0, 1
    addu v1, v1, a0
    sll v1, v1, 2
    jal func_0013C650
    addu a0, v0, v1
    lw v1, 0x40(s3)
    paddub s1, v0, zero
    addiu a0, zero, 0x1
    paddub s2, zero, zero
    sll v0, v1, 2
    addu v0, v0, v1
    sll v0, v0, 2
    addu v0, v0, s3
    sh a0, 0x4C(v0)
    lw v1, 0x40(s3)
    lh a0, 0x2(s0)
    sll v0, v1, 2
    addu v0, v0, v1
    sll v0, v0, 2
    addu v0, v0, s3
    .word 0x10000076
    sh a0, 0x4E(v0)
_L00142E14:
    jal func_142980
    paddub a0, s3, zero
    addiu v1, zero, 0x2
    beq v0, v1, _L00142E4C
    addiu v1, zero, 0x1
    bne v0, v1, _L00142E44
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L00142E44:
    .word 0x1000006D
    nop
_L00142E4C:
    lw v1, 0x19C(s3)
    addiu v0, zero, 0x1
    beq v1, v0, _L00142E80
    addiu v0, zero, 0x4
    addiu v0, zero, 0x4
    beq v1, v0, _L00142E7C
    addiu a1, zero, 0xC
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    .word 0x10000061
    paddub v0, zero, zero
_L00142E7C:
    addiu v0, zero, 0x4
_L00142E80:
    bne v1, v0, _L00142ECC
    nop
    lw v0, 0x198(s3)
    beqz v0, _L00142EC4
    paddub v0, zero, zero
    addiu a1, s3, 0x1A0
    jal func_001410E0
    paddub a0, s3, zero
    addiu v1, zero, -0x1
    bne v0, v1, _L00142F50
    addiu v1, zero, 0x3
    addiu a1, zero, 0x15
    paddub a0, s3, zero
    jal func_144340
    .word 0x70003628
    .word 0x1000004F
    paddub v0, zero, zero
_L00142EC4:
    .word 0x10000021
    nop
_L00142ECC:
    lb v1, 0x1A0(s3)
    .word 0x3C020048
    addiu v0, v0, -0x1F00
    addu v0, v0, v1
    lb v0, 0x1(v0)
    andi v0, v0, 0x4
    bnez v0, _L00142F0C
    addiu a0, s3, 0x1A0
    dsll32 v1, v1, 24
    addiu v0, zero, 0x2B
    dsra32 v1, v1, 24
    beq v1, v0, _L00142F08
    addiu v0, zero, 0x2D
    bne v1, v0, _L00142F1C
    .word 0x266501A0
_L00142F08:
    addiu a0, s3, 0x1A0
_L00142F0C:
    jal func_114378
    nop
    .word 0x1000000D
    nop
_L00142F1C:
    addiu a2, zero, 0x2
    jal func_00142730
    paddub a0, s3, zero
    bnez v0, _L00142F44
    addiu a2, s3, 0x1A0
    addiu a1, zero, 0x3
    jal func_144340
    paddub a0, s3, zero
    .word 0x1000002F
    paddub v0, zero, zero
_L00142F44:
    lh v0, 0x2(v0)
    nop
_L00142F4C:
    addiu v1, zero, 0x3
_L00142F50:
    beq s2, v1, _L00142FCC
    addiu v1, zero, 0x2
    beq s2, v1, _L00142FB0
    addiu v1, zero, 0x1
    beq s2, v1, _L00142F94
    nop
    beqz s2, _L00142F78
    nop
    .word 0x1000001D
    addiu s2, s2, 0x1
_L00142F78:
    lw a0, 0x40(s3)
    sll v1, a0, 2
    addu v1, v1, a0
    sll v1, v1, 2
    addu v1, s3, v1
    .word 0x10000015
    sw v0, 0x50(v1)
_L00142F94:
    lw a0, 0x40(s3)
    sll v1, a0, 2
    addu v1, v1, a0
    sll v1, v1, 2
    addu v1, s3, v1
    .word 0x1000000E
    sw v0, 0x54(v1)
_L00142FB0:
    lw a0, 0x40(s3)
    sll v1, a0, 2
    addu v1, v1, a0
    sll v1, v1, 2
    addu v1, s3, v1
    .word 0x10000007
    sw v0, 0x58(v1)
_L00142FCC:
    lw a0, 0x40(s3)
    sll v1, a0, 2
    addu v1, v1, a0
    sll v1, v1, 2
    addu v1, s3, v1
    sw v0, 0x5C(v1)
_L00142FE4:
    addiu s2, s2, 0x1
_L00142FE8:
    slt v0, s2, s1
    bnez v0, _L00142E14
    paddub a0, s3, zero
    jal func_001427A0
    nop
_L00142FFC:
    lq ra, 0x40(sp)
_L00143000:
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x50
    nop
    nop
    .set reorder
    .set at
}

}
