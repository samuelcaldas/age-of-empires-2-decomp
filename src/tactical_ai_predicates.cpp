#include "sub_list.h"

struct TacticalAI {
    void *m_vtable;
    char pad_04[0x30];
};

extern "C" {

void func_144550(void*, void*, void*, void*, void*);
void func_0013C580(void*, void*, void*, void*, void*);
int func_00141A70(TacticalAI *self, void *a1, int *a2);

asm int func_00141A70(TacticalAI *self, void *a1, int *a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x50
    sq ra, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    lw a3, 0x0(a2)
    addiu v0, zero, 0x3
    paddub s3, a0, zero
    paddub s2, a1, zero
    addiu v1, a3, 0x1
    sw v1, 0x0(a2)
    sll v1, a3, 2
    addu v1, v1, a3
    sll v1, v1, 2
    addu v1, a1, v1
    addiu s0, v1, 0x8
    lh v1, 0x8(v1)
    bne v1, v0, _L00141AF4
    paddub s1, a2, zero
    lh a0, 0x2(s0)
    lw v0, 0x10(s3)
    lw a1, 0x4(s0)
    lw a2, 0x8(s0)
    lw a3, 0xC(s0)
    lw t0, 0x10(s0)
    sll v1, a0, 1
    addu v1, v1, a0
    sll v1, v1, 3
    jal func_144550
    addu a0, v0, v1
    .word 0x10000058
    lq ra, 0x40(sp)
_L00141AF4:
    lh v0, 0x2(s0)
    bnez v0, _L00141B18
    nop
    jal func_00141A70
    nop
    sltu v0, zero, v0
    xori v0, v0, 0x1
    .word 0x1000004E
    andi v0, v0, 0xFF
_L00141B18:
    jal func_00141A70
    nop
    paddub a2, s1, zero
    paddub a0, s3, zero
    paddub a1, s2, zero
    jal func_00141A70
    paddub s1, v0, zero
    lh v1, 0x2(s0)
    sltiu at, v1, 0x7
    beql at, zero, _L00141C4C
    paddub v0, zero, zero
    .word 0x3C040049
    addiu a0, a0, 0x0E80
    sll v1, v1, 2
    addu v1, v1, a0
    lw v1, 0x0(v1)
    .word 0x00600008
    nop
    sltu v1, zero, s1
    beql v1, zero, _L00141B74
    andi v0, v1, 0xFF
    sltu v1, zero, v0
    andi v0, v1, 0xFF
_L00141B74:
    .word 0x10000035
    nop
    sltu v1, zero, s1
    beqz v1, _L00141B90
    nop
    sltu v1, zero, v0
    xori v1, v1, 0x1
_L00141B90:
    bnel v1, zero, _L00141BB0
    andi v0, v1, 0xFF
    sltu v1, zero, s1
    xori v1, v1, 0x1
    beqz v1, _L00141BAC
    nop
    sltu v1, zero, v0
_L00141BAC:
    andi v0, v1, 0xFF
_L00141BB0:
    .word 0x10000026
    nop
    sltu v1, zero, s1
    bnel v1, zero, _L00141BCC
    andi v0, v1, 0xFF
    sltu v1, zero, v0
    andi v0, v1, 0xFF
_L00141BCC:
    .word 0x1000001F
    nop
    sltu v1, zero, s1
    bnel v1, zero, _L00141BE8
    xori v0, v1, 0x1
    sltu v1, zero, v0
    xori v0, v1, 0x1
_L00141BE8:
    .word 0x10000018
    andi v0, v0, 0xFF
    sltu v1, zero, s1
    beqz v1, _L00141C00
    nop
    sltu v1, zero, v0
_L00141C00:
    bnel v1, zero, _L00141C24
    andi v0, v1, 0xFF
    sltu v1, zero, s1
    xori v1, v1, 0x1
    beqz v1, _L00141C20
    nop
    sltu v0, zero, v0
    xori v1, v0, 0x1
_L00141C20:
    andi v0, v1, 0xFF
_L00141C24:
    .word 0x10000009
    nop
    sltu v1, zero, s1
    beql v1, zero, _L00141C40
    xori v0, v1, 0x1
    sltu v1, zero, v0
    xori v0, v1, 0x1
_L00141C40:
    .word 0x10000002
    andi v0, v0, 0xFF
    paddub v0, zero, zero
_L00141C4C:
    lq ra, 0x40(sp)
_L00141C50:
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

asm int func_00141C70(TacticalAI *self, void *a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s1, a0, zero
    paddub s0, a1, zero
    .word 0x10000009
    sw zero, 0x3C(sp)
    addiu a2, sp, 0x3C
_L00141C94:
    paddub a0, s1, zero
    jal func_00141A70
    paddub a1, s0, zero
    bnez v0, _L00141CB0
    nop
    b _L00141D2C
    paddub v0, zero, zero
_L00141CB0:
    lw v0, 0x3C(sp)
    lbu v1, 0x6(s0)
    slt v0, v0, v1
    bnez v0, _L00141C94
    addiu a2, sp, 0x3C
    .word 0x10000013
    sw v1, 0x3C(sp)
    sll v0, v1, 2
_L00141CD0:
    addu v1, v0, v1
    sll v1, v1, 2
    addu v1, s0, v1
    lw v0, 0x18(s1)
    lh a0, 0xA(v1)
    lw a1, 0xC(v1)
    lw a2, 0x10(v1)
    lw a3, 0x14(v1)
    lw t0, 0x18(v1)
    sll v1, a0, 1
    addu v1, v1, a0
    sll v1, v1, 2
    jal func_0013C580
    addu a0, v0, v1
    lw v0, 0x3C(sp)
    addiu v0, v0, 0x1
    sw v0, 0x3C(sp)
_L00141D14:
    lw v1, 0x3C(sp)
    lbu v0, 0x7(s0)
    slt v0, v1, v0
    bnez v0, _L00141CD0
    sll v0, v1, 2
    addiu v0, zero, 0x1
_L00141D2C:
    lq ra, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x40
    .set reorder
    .set at
}

}
