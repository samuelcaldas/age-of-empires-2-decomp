
#include "sub_list.h"

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    char m_field100[10];
};

extern "C" {

void func_13FEF0(void*, int, int, int, int);

asm void func_0013FC80(DiplomacyAI *self, int player, int mode, int val) {
    .set noreorder
    .set noat
    blez a1, _L0013FD94
    nop
    lw v1, 0xAC(a0)
    lw v1, 0xAC(v1)
    lw v1, 0xB98(v1)
    lh v1, 0x50(v1)
    slt v1, a1, v1
    bnez v1, _L0013FCAC
    addiu v1, zero, 0x2
    b _L0013FD94
    nop
    _L0013FCAC:
    beq a2, v1, _L0013FD38
    sll v1, a1, 2
    addiu v1, zero, 0x1
    beq a2, v1, _L0013FD94
    nop
    beqz a2, _L0013FCD0
    sll v1, a1, 2
    b _L0013FD94
    nop
    _L0013FCD0:
    addu a2, v1, a0
    addu v1, a1, a0
    sw a3, 0xB0(a2)
    lbu v1, 0x100(v1)
    beqz v1, _L0013FD0C
    addiu a0, a2, 0xB0
    lw v1, 0x0(a0)
    bgez v1, _L0013FCFC
    slti at, v1, 0x65
    b _L0013FD94
    sw zero, 0x0(a0)
    _L0013FCFC:
    bnez at, _L0013FD94
    addiu v1, zero, 0x64
    b _L0013FD94
    sw v1, 0x0(a0)
    _L0013FD0C:
    lw v1, 0x0(a0)
    slti at, v1, 0x32
    beqz at, _L0013FD28
    slti at, v1, 0x65
    addiu v1, zero, 0x32
    b _L0013FD94
    sw v1, 0x0(a0)
    _L0013FD28:
    bnez at, _L0013FD94
    addiu v1, zero, 0x64
    b _L0013FD94
    sw v1, 0x0(a0)
    _L0013FD38:
    addu a2, v1, a0
    addu v1, a1, a0
    sw a3, 0xD8(a2)
    lbu v1, 0x100(v1)
    beqz v1, _L0013FD74
    addiu a0, a2, 0xD8
    lw v1, 0x0(a0)
    bgez v1, _L0013FD64
    slti at, v1, 0x65
    b _L0013FD94
    sw zero, 0x0(a0)
    _L0013FD64:
    bnez at, _L0013FD94
    addiu v1, zero, 0x64
    b _L0013FD94
    sw v1, 0x0(a0)
    _L0013FD74:
    lw v1, 0x0(a0)
    bgez v1, _L0013FD88
    slti at, v1, 0x31
    b _L0013FD94
    sw zero, 0x0(a0)
    _L0013FD88:
    bnez at, _L0013FD94
    addiu v1, zero, 0x30
    sw v1, 0x0(a0)
    _L0013FD94:
    jr ra
    nop
    .set reorder
    .set at
}

asm int func_0013FDA0(DiplomacyAI *self, int player) {
    .set noreorder
    .set noat
    blez a1, _L0013FDE4
    paddub v0, zero, zero
    lw v0, 0xAC(a0)
    lw v0, 0xAC(v0)
    lw v0, 0xB98(v0)
    lh v0, 0x50(v0)
    slt at, a1, v0
    beqz at, _L0013FDE0
    nop
    addu v0, a1, a0
    lbu v1, 0x100(v0)
    addiu v0, zero, 0x1
    bne v1, v0, _L0013FDE0
    nop
    b _L0013FDE4
    nop
    _L0013FDE0:
    paddub v0, zero, zero
    _L0013FDE4:
    jr ra
    nop
    .set reorder
    .set at
}

asm void func_0013FDF0(DiplomacyAI *self, int player, int val) {
    .set noreorder
    .set noat
    blez a1, _L0013FE1C
    nop
    lw v1, 0xAC(a0)
    lw v1, 0xAC(v1)
    lw v1, 0xB98(v1)
    lh v1, 0x50(v1)
    slt at, a1, v1
    beqz at, _L0013FE1C
    nop
    addu v1, a1, a0
    sb a2, 0x100(v1)
    _L0013FE1C:
    jr ra
    nop
    .set reorder
    .set at
}

asm void func_0013FE30(DiplomacyAI *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x50
    sq ra, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s3, a0, zero
    lw a0, 0xAC(a0)
    lw t9, 0x0(a0)
    lw t9, 0x50(t9)
    jalr ra, t9
    addiu a1, zero, 0x7C
    lw a0, 0xAC(s3)
    addiu a1, zero, 0x80
    lw t9, 0x0(a0)
    lw t9, 0x50(t9)
    jalr ra, t9
    paddub s2, v0, zero
    lw a0, 0xAC(s3)
    addiu a1, zero, 0xBC
    lw t9, 0x0(a0)
    lw t9, 0x50(t9)
    jalr ra, t9
    paddub s1, v0, zero
    lw a0, 0xAC(s3)
    addiu a1, zero, 0xC3
    lw t9, 0x0(a0)
    lw t9, 0x50(t9)
    jalr ra, t9
    paddub s0, v0, zero
    paddub a0, s3, zero
    paddub a1, s2, zero
    paddub a2, s1, zero
    paddub a3, s0, zero
    jal func_13FEF0
    paddub t0, v0, zero
    lq ra, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x50
    .set reorder
    .set at
}

int func_0013FEE0() {
    return -1;
}

}
