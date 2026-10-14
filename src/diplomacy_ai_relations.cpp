
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

asm int func_1401C0(DiplomacyAI *self, int player) {
    .set noreorder
    .set noat
    blez a1, _L00140214
    paddub v0, zero, zero
    lw v0, 0xAC(a0)
    lw v1, 0xAC(v0)
    lw v0, 0xB98(v1)
    lh v0, 0x50(v0)
    slt at, v0, a1
    bnez at, _L00140210
    nop
    lw v0, 0xBA0(v1)
    beq a1, v0, _L00140210
    nop
    lw v1, 0xBD8(v1)
    addiu v0, zero, 0x3
    addu v1, v1, a1
    lbu v1, 0x0(v1)
    bne v1, v0, _L00140210
    nop
    b _L00140214
    addiu v0, zero, 0x1
    _L00140210:
    paddub v0, zero, zero
    _L00140214:
    jr ra
    nop
    .set reorder
    .set at
}

asm int func_140220(DiplomacyAI *self, int player) {
    .set noreorder
    .set noat
    blez a1, _L00140274
    paddub v0, zero, zero
    lw v0, 0xAC(a0)
    lw v1, 0xAC(v0)
    lw v0, 0xB98(v1)
    lh v0, 0x50(v0)
    slt at, v0, a1
    bnez at, _L00140270
    nop
    lw v0, 0xBA0(v1)
    beq a1, v0, _L00140270
    nop
    lw v1, 0xBD8(v1)
    addiu v0, zero, 0x1
    addu v1, v1, a1
    lbu v1, 0x0(v1)
    bne v1, v0, _L00140270
    nop
    b _L00140274
    nop
    _L00140270:
    paddub v0, zero, zero
    _L00140274:
    jr ra
    nop
    .set reorder
    .set at
}

asm int func_140280(DiplomacyAI *self, int player) {
    .set noreorder
    .set noat
    lw v0, 0xAC(a0)
    lw v1, 0xAC(v0)
    lw v0, 0xBA0(v1)
    bne a1, v0, _L0014029C
    nop
    b _L001402D8
    addiu v0, zero, 0x1
    _L0014029C:
    blez a1, _L001402D8
    paddub v0, zero, zero
    lw v0, 0xB98(v1)
    lh v0, 0x50(v0)
    slt at, v0, a1
    bnez at, _L001402D4
    nop
    lw v0, 0xBD8(v1)
    addu v0, v0, a1
    lbu v0, 0x0(v0)
    bnez v0, _L001402D4
    nop
    b _L001402D8
    addiu v0, zero, 0x1
    _L001402D4:
    paddub v0, zero, zero
    _L001402D8:
    jr ra
    nop
    .set reorder
    .set at
}

asm int func_1402E0(DiplomacyAI *self, int player) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x10
    blez a1, _L00140308
    sq ra, 0x0(sp)
    lw v0, 0xAC(a0)
    lw a2, 0xAC(v0)
    lw a0, 0xB98(a2)
    lh v0, 0x50(a0)
    slt v0, a1, v0
    bnez v0, _L00140310
    nop
    _L00140308:
    b _L0014034C
    paddub v0, zero, zero
    _L00140310:
    lw v0, 0x54(a0)
    sll v1, a1, 2
    addu v0, v0, v1
    lw a0, 0x0(v0)
    beqz a0, _L0014034C
    paddub v0, zero, zero
    lw t9, 0x1B30(a0)
    lw t9, 0x24(t9)
    jalr ra, t9
    lw a1, 0xBA0(a2)
    beqz v0, _L00140348
    nop
    b _L0014034C
    addiu v0, zero, 0x1
    _L00140348:
    paddub v0, zero, zero
    _L0014034C:
    lq ra, 0x0(sp)
    jr ra
    addiu sp, sp, 0x10
    .set reorder
    .set at
}

void func_00140360() {
}

}
