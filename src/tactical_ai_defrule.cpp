#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

int func_142980(void *ptr);
void func_144340(void *ptr, int a1, int a2);
int func_00142680(void *self, void *buf);
int func_00142CC0(void *self);
int func_00143020(TacticalAI2 *self, int a1);
int func_0011AA78(const char *s1, const char *s2);
int func_00142D10(TacticalAI2 *self);

asm int func_143E00(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s1, a0, zero
    paddub s0, zero, zero
_L00143E18:
    jal func_142980
    paddub a0, s1, zero
    addiu v1, zero, 0x2
    beq v0, v1, _L00143E54
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L00143E4C
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s1, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L00143E4C:
    .word 0x1000007C
    lq ra, 0x20(sp)
_L00143E54:
    lw a0, 0x19C(s1)
    beq a0, v1, _L00143EAC
    nop
    bnez s0, _L00143EF4
    nop
    lb v1, 0x1A0(s1)
    .word 0x3C020048
    addiu v0, v0, -0x1F00
    addu v0, v0, v1
    lb v0, 0x1(v0)
    andi v0, v0, 0x3
    beqz v0, _L00143EF4
    nop
    lw v0, 0x198(s1)
    beqz v0, _L00143EAC
    nop
    addiu a1, s1, 0x1A0
    jal func_00142680
    paddub a0, s1, zero
    dsll32 v0, v0, 16
    dsra32 v0, v0, 16
    sw v0, 0x18C(s1)
_L00143EAC:
    beqz s0, _L00143ED0
    addiu a1, zero, 0x1
    jal func_00142CC0
    paddub a0, s1, zero
    bnez v0, _L00143ECC
    nop
    .word 0x1000005D
    paddub v0, zero, zero
_L00143ECC:
    addiu a1, zero, 0x1
_L00143ED0:
    jal func_00143020
    paddub a0, s1, zero
    bnez v0, _L00143EEC
    addiu s0, zero, 0x1
    .word 0x10000056
    paddub v0, zero, zero
    addiu s0, zero, 0x1
_L00143EEC:
    .word 0x1000FFCA
    nop
_L00143EF4:
    bnez s0, _L00143F18
    addiu v0, zero, 0x1
    addiu a1, zero, 0xE
    paddub a0, s1, zero
    jal func_144340
    .word 0x70003628
    .word 0x1000004B
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L00143F18:
    bne a0, v0, _L00143F3C
    addiu a1, zero, 0x7
    .word 0x3C020049
    addiu a0, s1, 0x1A0
    jal func_0011AA78
    addiu a1, v0, 0x0F18
    beqz v0, _L00143F50
    nop
    addiu a1, zero, 0x7
_L00143F3C:
    paddub a0, s1, zero
    jal func_144340
    .word 0x70003628
    .word 0x1000003C
    paddub v0, zero, zero
_L00143F50:
    lbu v0, 0x40(s1)
    paddub s0, zero, zero
    addiu v0, v0, 0x1
    sb v0, 0x4A(s1)
_L00143F60:
    jal func_142980
    paddub a0, s1, zero
    addiu v1, zero, 0x2
    beq v0, v1, _L00143F9C
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L00143F94
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s1, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L00143F94:
    .word 0x10000029
    nop
_L00143F9C:
    lw v0, 0x19C(s1)
    bne v0, v1, _L00143FE8
    nop
    jal func_00142CC0
    paddub a0, s1, zero
    bnez v0, _L00143FC4
    paddub a0, s1, zero
    .word 0x10000020
    paddub v0, zero, zero
    paddub a0, s1, zero
_L00143FC4:
    jal func_00142D10
    nop
    bnez v0, _L00143FE0
    addiu s0, zero, 0x1
    .word 0x10000019
    paddub v0, zero, zero
    addiu s0, zero, 0x1
_L00143FE0:
    .word 0x1000FFDF
    nop
_L00143FE8:
    lbu v0, 0x40(s1)
    addiu v0, v0, 0x1
    bnez s0, _L00144010
    sb v0, 0x4B(s1)
    addiu a1, zero, 0x11
    paddub a0, s1, zero
    jal func_144340
    .word 0x70003628
    .word 0x1000000C
    paddub v0, zero, zero
_L00144010:
    lw v1, 0x19C(s1)
    addiu v0, zero, 0x3
    beq v1, v0, _L0014403C
    addiu v0, zero, 0x1
    addiu a1, zero, 0x8
    paddub a0, s1, zero
    jal func_144340
    .word 0x70003628
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L0014403C:
    lq ra, 0x20(sp)
_L00144040:
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    .set reorder
    .set at
}

}
