#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

int func_142980(void *ptr);
void func_144340(void *ptr, int a1, int a2);
char *func_21A4A0(int id);
void func_11A7BC(char *dst, const char *src);

asm int func_00142830(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x20
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    jal func_142980
    paddub s0, a0, zero
    addiu v1, zero, 0x2
    beq v0, v1, _L00142878
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L00142870
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L00142870:
    .word 0x1000000B
    lq ra, 0x10($sp)
_L00142878:
    lw v1, 0x19C(s0)
    addiu v0, zero, 0x1
    beq v1, v0, _L0014289C
    nop
    addiu a1, zero, 0x10
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L0014289C:
    lq ra, 0x10(sp)
_L001428A0:
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    nop
    .set reorder
    .set at
}

asm int func_001428B0(TacticalAI2 *self, char *a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    lw v0, 0x6BC(a0)
    lw s0, 0x6B8(a0)
    paddub s2, a0, zero
    paddub s1, a1, zero
    sll v0, v0, 1
    addu s0, s0, v0
    sb zero, 0x0(a1)
_L001428E0:
    lhu v1, 0x0(s0)
    ori v0, zero, 0xFFFF
    beq v1, v0, _L0014292C
    paddub v0, zero, zero
    ori v0, zero, 0xFFFE
    beq v1, v0, _L00142904
    nop
    .word 0x1000000E
    andi a0, v1, 0xFFFF
_L00142904:
    .word 0x3C020049
    addiu a1, v0, 0x0E9C
    jal func_11A7BC
    paddub a0, s1, zero
    lw v1, 0x6BC(s2)
    addiu v0, zero, 0x1
    addiu v1, v1, 0x1
    .word 0x1000000F
    sw v1, 0x6BC(s2)
    paddub v0, zero, zero
_L0014292C:
    .word 0x1000000D
    lq ra, 0x30(sp)
    andi a0, v1, 0xFFFF
_L00142938:
    jal func_21A4A0
    nop
    paddub a1, v0, zero
    jal func_11A7BC
    paddub a0, s1, zero
    lw v0, 0x6BC(s2)
    addiu s0, s0, 0x2
    addiu v0, v0, 0x1
    .word 0x1000FFE1
    sw v0, 0x6BC(s2)
_L00142960:
    lq ra, 0x30(sp)
_L00142964:
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
