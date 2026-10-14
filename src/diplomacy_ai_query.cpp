
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

asm int func_0013FA90(DiplomacyAI *self, int player, int mode) {
    .set noreorder
    .set noat
    blez a1, _L0013FAB8
    addiu v0, zero, -0x1
    lw v0, 0xAC(a0)
    lw v0, 0xAC(v0)
    lw v0, 0xB98(v0)
    lh v0, 0x50(v0)
    slt v0, a1, v0
    bnez v0, _L0013FAC0
    addiu v0, zero, 0x2
    addiu v0, zero, -0x1
    _L0013FAB8:
    b _L0013FB48
    nop
    _L0013FAC0:
    beq a2, v0, _L0013FB3C
    sll v0, a1, 2
    addiu v0, zero, 0x1
    beql a2, v0, _L0013FAF0
    .word 0x00053080
    beq a2, zero, _L0013FAE4
    sll v0, a1, 2
    b _L0013FB48
    addiu v0, zero, -0x1
    _L0013FAE4:
    addu v0, v0, a0
    b _L0013FB48
    lw v0, 0xB0(v0)
    _L0013FAF0:
    addu v0, a2, a0
    lw v1, 0xB0(v0)
    addiu v0, zero, 0x31
    subu a1, v0, v1
    bgez a1, _L0013FB0C
    addu v0, a2, a0
    negu a1, a1
    _L0013FB0C:
    lw v1, 0xD8(v0)
    addiu v0, zero, 0x31
    subu v1, v0, v1
    bgez v1, _L0013FB24
    addiu v0, zero, 0x64
    negu v1, v1
    _L0013FB24:
    subu v0, v0, a1
    subu v0, v0, v1
    bgez v0, _L0013FB48
    nop
    b _L0013FB48
    paddub v0, zero, zero
    _L0013FB3C:
    addu v0, v0, a0
    lw v0, 0xD8(v0)
    nop
    _L0013FB48:
    jr ra
    nop
    .set reorder
    .set at
}

asm void func_13FB50(DiplomacyAI *self, int player, int a2, int a3) {
    .set noreorder
    .set noat
    blez a1, _L0013FC74
    nop
    lw v1, 0xAC(a0)
    lw v1, 0xAC(v1)
    lw v1, 0xB98(v1)
    lh v1, 0x50(v1)
    slt v1, a1, v1
    bnez v1, _L0013FB7C
    addiu v1, zero, 0x2
    b _L0013FC74
    nop
    _L0013FB7C:
    beq a2, v1, _L0013FC10
    sll v1, a1, 2
    addiu v1, zero, 0x1
    beq a2, v1, _L0013FC74
    nop
    beqz a2, _L0013FBA0
    sll v1, a1, 2
    b _L0013FC74
    nop
    _L0013FBA0:
    addu a2, v1, a0
    addu v1, a1, a0
    lw a0, 0xB0(a2)
    addu a0, a0, a3
    sw a0, 0xB0(a2)
    lbu v1, 0x100(v1)
    beqz v1, _L0013FBE4
    addiu a1, a2, 0xB0
    lw v1, 0x0(a1)
    bgez v1, _L0013FBD4
    slti at, v1, 0x65
    b _L0013FC74
    sw zero, 0x0(a1)
    _L0013FBD4:
    bnez at, _L0013FC74
    addiu v1, zero, 0x64
    b _L0013FC74
    sw v1, 0x0(a1)
    _L0013FBE4:
    lw v1, 0x0(a1)
    slti at, v1, 0x32
    beqz at, _L0013FC00
    slti at, v1, 0x65
    addiu v1, zero, 0x32
    b _L0013FC74
    sw v1, 0x0(a1)
    _L0013FC00:
    bnez at, _L0013FC74
    addiu v1, zero, 0x64
    b _L0013FC74
    sw v1, 0x0(a1)
    _L0013FC10:
    addu a2, v1, a0
    addu v1, a1, a0
    lw a0, 0xD8(a2)
    addu a0, a0, a3
    sw a0, 0xD8(a2)
    lbu v1, 0x100(v1)
    beqz v1, _L0013FC54
    addiu a1, a2, 0xD8
    lw v1, 0x0(a1)
    bgez v1, _L0013FC44
    slti at, v1, 0x65
    b _L0013FC74
    sw zero, 0x0(a1)
    _L0013FC44:
    bnez at, _L0013FC74
    addiu v1, zero, 0x64
    b _L0013FC74
    sw v1, 0x0(a1)
    _L0013FC54:
    lw v1, 0x0(a1)
    bgez v1, _L0013FC68
    slti at, v1, 0x31
    b _L0013FC74
    sw zero, 0x0(a1)
    _L0013FC68:
    bnez at, _L0013FC74
    addiu v1, zero, 0x30
    sw v1, 0x0(a1)
    _L0013FC74:
    jr ra
    nop
    .set reorder
    .set at
}

}
