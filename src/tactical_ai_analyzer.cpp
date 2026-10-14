#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

int func_142980(void *ptr);
void func_144340(void *ptr, int a1, int a2);
int func_0011AA78(const char *s1, const char *s2);
char *func_0011ABBC(char *dst, const char *src);
int func_001427A0(void *self);
void func_1441B0(void);
int func_00142560(TacticalAI2 *self, void *buf);
void func_144050(void *self);
int func_143AD0(void *self);
int func_145740(void *ptr);
int func_143E00(void *self);
int func_00141250(void *self, int a1, int a2, void *a3);
int func_114378(const char *str);
void *func_00142730(void *self, void *buf, int a2);
int func_00142130(void *self, int a1, void *a2, int a3);

asm int func_143440(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x240
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    jal func_142980
    paddub s0, a0, zero
    addiu v1, zero, 0x2
    beq v0, v1, _L0014348C
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L00143484
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L00143484:
    .word 0x100000F1
    lq ra, 0x20(sp)
_L0014348C:
    lw v1, 0x19C(s0)
    addiu v0, zero, 0x1
    beq v1, v0, _L001434B4
    nop
    addiu a1, zero, 0xD
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    .word 0x100000E6
    paddub v0, zero, zero
_L001434B4:
    .word 0x3C020049
    addiu a0, s0, 0x1A0
    jal func_0011AA78
    addiu a1, v0, 0x0EA0
    bnez v0, _L00143580
    nop
    jal func_142980
    paddub a0, s0, zero
    addiu v1, zero, 0x2
    beq v0, v1, _L00143508
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L00143500
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L00143500:
    .word 0x100000D1
    nop
_L00143508:
    lw v1, 0x19C(s0)
    addiu v0, zero, 0x4
    beq v1, v0, _L00143534
    addiu a0, sp, 0x30
    addiu a1, zero, 0xB
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    .word 0x100000C7
    paddub v0, zero, zero
    addiu a0, sp, 0x30
_L00143534:
    jal func_0011ABBC
    addiu a1, s0, 0x1A0
    jal func_001427A0
    paddub a0, s0, zero
    bnez v0, _L00143558
    paddub a0, s0, zero
    .word 0x100000BE
    paddub v0, zero, zero
    paddub a0, s0, zero
_L00143558:
    jal func_1441B0
    nop
    addiu a1, sp, 0x30
    jal func_00142560
    paddub a0, s0, zero
    paddub s1, v0, zero
    jal func_144050
    paddub a0, s0, zero
    .word 0x100000B3
    paddub v0, s1, zero
_L00143580:
    .word 0x3C020049
    addiu a0, s0, 0x1A0
    jal func_0011AA78
    addiu a1, v0, 0x0EA8
    bnez v0, _L001435A8
    nop
    jal func_143AD0
    paddub a0, s0, zero
    .word 0x100000A9
    nop
_L001435A8:
    .word 0x3C020049
    addiu a0, s0, 0x1A0
    jal func_0011AA78
    addiu a1, v0, 0x0EB8
    bnez v0, _L00143650
    nop
    addiu v0, zero, -0x1
    sw zero, 0x40(s0)
    addiu a0, s0, 0x44
    jal func_145740
    sw v0, 0x18C(s0)
    jal func_143E00
    paddub a0, s0, zero
    bnez v0, _L001435F0
    addiu v0, zero, 0x1
    .word 0x10000098
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L001435F0:
    sw v0, 0x194(s0)
    lw v1, 0x198(s0)
    bnez v1, _L00143608
    nop
    .word 0x10000091
    nop
_L00143608:
    sb v0, 0x49(s0)
    lw a1, 0x190(s0)
    lw a2, 0x18C(s0)
    addiu a3, s0, 0x44
    jal func_00141250
    paddub a0, s0, zero
    addiu v1, zero, -0x1
    bne v0, v1, _L00143648
    addiu v0, zero, 0x1
    addiu a1, zero, 0x6
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    .word 0x10000082
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L00143648:
    .word 0x1000007F
    nop
_L00143650:
    .word 0x3C020049
    addiu a0, s0, 0x1A0
    jal func_0011AA78
    addiu a1, v0, 0x0EC0
    bnez v0, _L00143838
    addiu a2, s0, 0x1A0
    jal func_142980
    paddub a0, s0, zero
    addiu v1, zero, 0x2
    beq v0, v1, _L001436A4
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L0014369C
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L0014369C:
    .word 0x1000006A
    nop
_L001436A4:
    lw v1, 0x19C(s0)
    addiu v0, zero, 0x1
    beq v1, v0, _L001436D0
    addiu a0, sp, 0x140
    addiu a1, zero, 0xC
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    .word 0x10000060
    paddub v0, zero, zero
    addiu a0, sp, 0x140
_L001436D0:
    jal func_0011ABBC
    addiu a1, s0, 0x1A0
    jal func_142980
    paddub a0, s0, zero
    addiu a2, zero, 0x2
    beq v0, a2, _L00143714
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L0014370C
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L0014370C:
    .word 0x1000004E
    nop
_L00143714:
    lw v1, 0x19C(s0)
    addiu v0, zero, 0x1
    beq v1, v0, _L0014373C
    nop
    addiu a1, zero, 0xC
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    .word 0x10000044
    paddub v0, zero, zero
_L0014373C:
    lb v1, 0x1A0(s0)
    .word 0x3C020049
    addiu v0, v0, -0x1EFF
    addu v0, v0, v1
    lb v0, 0x0(v0)
    andi v0, v0, 0x4
    bnez v0, _L00143780
    addiu a0, s0, 0x1A0
    dsll32 v1, v1, 24
    addiu v0, zero, 0x2B
    dsra32 v1, v1, 24
    beq v1, v0, _L0014377C
    nop
    addiu v0, zero, 0x2D
    bne v1, v0, _L00143798
    .word 0x260501A0
_L0014377C:
    addiu a0, s0, 0x1A0
_L00143780:
    jal func_114378
    nop
    dsll32 s1, v0, 16
    .word 0x1000000E
    dsra32 s1, s1, 16
    addiu a1, s0, 0x1A0
_L00143798:
    jal func_00142730
    paddub a0, s0, zero
    bnez v0, _L001437C0
    nop
    addiu a2, s0, 0x1A0
    addiu a1, zero, 0x3
    jal func_144340
    paddub a0, s0, zero
    .word 0x10000023
    paddub v0, zero, zero
_L001437C0:
    lh s1, 0x2(v0)
    nop
_L001437C8:
    jal func_001427A0
    paddub a0, s0, zero
    bnez v0, _L001437E0
    nop
    .word 0x1000001B
    paddub v0, zero, zero
_L001437E0:
    lw v0, 0x198(s0)
    bnez v0, _L001437F4
    nop
    .word 0x10000016
    addiu v0, zero, 0x1
_L001437F4:
    lw a1, 0x190(s0)
    addiu a2, sp, 0x140
    paddub a3, s1, zero
    jal func_00142130
    paddub a0, s0, zero
    bnez v0, _L0014382C
    addiu v0, zero, 0x1
    addiu a2, sp, 0x140
    paddub a0, s0, zero
    jal func_144340
    paddub a1, zero, zero
    .word 0x10000009
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L0014382C:
    .word 0x10000006
    nop
    addiu a2, s0, 0x1A0
_L00143838:
    addiu a1, zero, 0x4
    jal func_144340
    paddub a0, s0, zero
    paddub v0, zero, zero
_L00143848:
    lq ra, 0x20(sp)
_L0014384C:
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x240
    nop
    .set reorder
    .set at
}

}
