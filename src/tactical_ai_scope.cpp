#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

char *func_0011ABBC(char *dst, const char *src);

asm void func_1441B0(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x20
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    lw v1, 0x6C0(a0)
    paddub s0, a0, zero
    lw a2, 0x2A4(a0)
    addiu a1, s0, 0x2A8
    sll v0, v1, 6
    addu v0, v0, v1
    sll v0, v0, 1
    addu v0, v0, v1
    sll v0, v0, 3
    addu v0, v0, a0
    sw a2, 0x6C4(v0)
    lw v1, 0x6C0(a0)
    lw a2, 0x6AC(a0)
    sll v0, v1, 6
    addu v0, v0, v1
    sll v0, v0, 1
    addu v0, v0, v1
    sll v0, v0, 3
    addu v0, v0, a0
    sw a2, 0xACC(v0)
    lw v1, 0x6C0(a0)
    lw a2, 0x6A8(a0)
    sll v0, v1, 6
    addu v0, v0, v1
    sll v0, v0, 1
    addu v0, v0, v1
    sll v0, v0, 3
    addu v0, v0, a0
    sw a2, 0xAC8(v0)
    lw v1, 0x6C0(a0)
    lw a2, 0x6B0(a0)
    sll v0, v1, 6
    addu v0, v0, v1
    sll v0, v0, 1
    addu v0, v0, v1
    sll v0, v0, 3
    addu v0, v0, a0
    sw a2, 0xAD0(v0)
    lw v1, 0x6C0(a0)
    sll v0, v1, 6
    addu v0, v0, v1
    sll v0, v0, 1
    addu v0, v0, v1
    sll v0, v0, 3
    addu v0, a0, v0
    jal func_0011ABBC
    addiu a0, v0, 0x6C8
    lw a0, 0x6C0(s0)
    lw a1, 0x6B8(s0)
    sll v1, a0, 6
    addu v1, v1, a0
    sll v1, v1, 1
    addu v1, v1, a0
    sll v1, v1, 3
    addu v1, v1, s0
    sw a1, 0xAD4(v1)
    lw a0, 0x6C0(s0)
    lw a1, 0x6BC(s0)
    sll v1, a0, 6
    addu v1, v1, a0
    sll v1, v1, 1
    addu v1, v1, a0
    sll v1, v1, 3
    addu v1, v1, s0
    sw a1, 0xAD8(v1)
    lw v1, 0x6C0(s0)
    addiu v1, v1, 0x1
    sw v1, 0x6C0(s0)
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    nop
    .set reorder
    .set at
}

asm void func_1442E0(TacticalAI2 *self) {
    .set noreorder
    .set noat
    lw v1, 0x2FB4(a0)
    lw a1, 0x198(a0)
    sll v1, v1, 2
    addu v1, v1, a0
    sw a1, 0x2FB8(v1)
    lw v1, 0x2FB4(a0)
    addiu v1, v1, 0x1
    jr ra
    sw v1, 0x2FB4(a0)
    nop
    nop
    nop
    .set reorder
    .set at
}

asm void func_144310(TacticalAI2 *self) {
    .set noreorder
    .set noat
    lw v1, 0x6B4(a0)
    addiu a2, zero, -0x1
    addiu a1, zero, 0x19
    sb zero, 0x0(v1)
    lw v1, 0x6B4(a0)
    sw a2, 0x104(v1)
    lw v1, 0x6B4(a0)
    sb zero, 0x108(v1)
    lw v1, 0x6B4(a0)
    jr ra
    sw a1, 0x188(v1)
    nop
    .set reorder
    .set at
}

asm void func_144340(TacticalAI2 *self, int a1, const char *a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s2, a0, zero
    lw a0, 0x6B4(a0)
    paddub s1, a1, zero
    beqz a0, _L00144424
    paddub s0, a2, zero
    lw a1, 0x6AC(s2)
    beqz a1, _L00144384
    nop
    jal func_0011ABBC
    nop
    .word 0x10000005
    sltiu at, s1, 0x1B
_L00144384:
    .word 0x3C020049
    jal func_0011ABBC
    addiu a1, v0, 0x0F1C
    sltiu at, s1, 0x1B
_L00144394:
    beqz at, _L001443D8
    nop
    .word 0x3C020049
    addiu v1, v0, 0x0F20
    sll v0, s1, 2
    addu v0, v0, v1
    lw v0, 0x0(v0)
    .word 0x00400008
    nop
    lw v1, 0x6B0(s2)
    lw v0, 0x6B4(s2)
    .word 0x10000009
    sw v1, 0x104(v0)
    lw v0, 0x6B4(s2)
    addiu v1, zero, -0x1
    .word 0x10000005
    sw v1, 0x104(v0)
_L001443D8:
    lw v0, 0x6B4(s2)
    addiu v1, zero, -0x1
    addiu s1, zero, 0x16
    sw v1, 0x104(v0)
_L001443E8:
    beqz s0, _L00144408
    nop
    lw v0, 0x6B4(s2)
    paddub a1, s0, zero
    jal func_0011ABBC
    addiu a0, v0, 0x108
    .word 0x10000007
    lw v1, 0x6B4(s2)
_L00144408:
    lw v1, 0x6B4(s2)
    .word 0x3C020049
    addiu a1, v0, 0x0F1C
    jal func_0011ABBC
    addiu a0, v1, 0x108
    lw v1, 0x6B4(s2)
_L00144420:
    sw s1, 0x188(v1)
_L00144424:
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

}
