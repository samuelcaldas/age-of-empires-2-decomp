
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

int func_140280(void*, int);
int func_140220(void*, int);
void* func_318280(void*);
int func_1401C0(void*, int);

asm int func_13FEF0(DiplomacyAI *self, int a1, int a2, int a3, int t0) {
    .set noreorder
    .set noat
    addiu sp, sp, -0xA0
    sq ra, 0x90(sp)
    sq fp, 0x80(sp)
    sq s7, 0x70(sp)
    sq s6, 0x60(sp)
    sq s5, 0x50(sp)
    sq s4, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    addiu s0, zero, -0x1
    addiu s2, zero, 0x1
    paddub s7, a0, zero
    paddub s6, a1, zero
    paddub s5, a2, zero
    paddub fp, a3, zero
    paddub s4, t0, zero
    b _L00140060
    paddub s1, s0, zero
    _L0013FF40:
    lw v0, 0xBA0(v1)
    beql s2, v0, _L00140060
    addiu s2, s2, 0x1
    lw v1, 0x54(a0)
    sll s3, s2, 2
    addiu v0, zero, 0x2
    addu v1, v1, s3
    lw v1, 0x0(v1)
    lbu v1, 0xBA6(v1)
    beq v1, v0, _L0014005C
    nop
    blez s6, _L0013FF94
    paddub a0, s7, zero
    bne s5, s2, _L0013FF90
    nop
    paddub a0, s7, zero
    jal func_140280
    paddub a1, s2, zero
    bnez v0, _L0014005C
    nop
    _L0013FF90:
    paddub a0, s7, zero
    _L0013FF94:
    jal func_140280
    paddub a1, s2, zero
    addiu v1, zero, 0x1
    beq v0, v1, _L0014005C
    nop
    paddub a0, s7, zero
    jal func_140220
    paddub a1, s2, zero
    addiu v1, zero, 0x1
    beq v0, v1, _L0014005C
    nop
    lw a0, 0xAC(s7)
    lw t9, 0x0(a0)
    lw t9, 0x60(t9)
    jalr ra, t9
    paddub a1, s2, zero
    beqz v0, _L0014005C
    nop
    lw v0, 0xAC(s7)
    lw v0, 0xAC(v0)
    lw v0, 0xB98(v0)
    lw v0, 0x54(v0)
    addu v0, v0, s3
    lw v0, 0x0(v0)
    jal func_318280
    lw a0, 0xB90(v0)
    addu v1, s7, s3
    slti at, s4, 0x2
    bnez at, _L00140048
    lw a0, 0xB0(v1)
    addiu v1, zero, 0x1
    bnel fp, v1, _L00140030
    .word 0x0054001A
    bnez s4, _L00140024
    .word 0x0054001A
    .word 0x000001CD
    _L00140024:
    mflo v0
    b _L00140048
    addu a0, a0, v0
    _L00140030:
    .word 0x0054001A
    _L00140034:
    bnez s4, _L00140040
    nop
    .word 0x000001CD
    _L00140040:
    mflo v0
    subu a0, a0, v0
    _L00140048:
    slt at, s1, a0
    beqz at, _L0014005C
    nop
    paddub s1, a0, zero
    paddub s0, s2, zero
    _L0014005C:
    addiu s2, s2, 0x1
    _L00140060:
    lw v0, 0xAC(s7)
    lw v1, 0xAC(v0)
    lw a0, 0xB98(v1)
    lh v0, 0x50(a0)
    slt v0, s2, v0
    bnez v0, _L0013FF40
    nop
    paddub v0, s0, zero
    lq ra, 0x90(sp)
    lq fp, 0x80(sp)
    lq s7, 0x70(sp)
    lq s6, 0x60(sp)
    lq s5, 0x50(sp)
    lq s4, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0xA0
    .set reorder
    .set at
}

int func_001400B0() {
    return 0;
}

asm int func_001400C0(DiplomacyAI *self, int a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x80
    sq ra, 0x70(sp)
    sq s6, 0x60(sp)
    sq s5, 0x50(sp)
    sq s4, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    addiu s0, zero, -0x1
    addiu s2, zero, 0x1
    paddub s6, a0, zero
    paddub s5, a1, zero
    paddub s4, a2, zero
    b _L00140170
    paddub s1, s0, zero
    _L00140100:
    lw v0, 0xBA0(v1)
    beql s2, v0, _L00140170
    addiu s2, s2, 0x1
    lw v1, 0x54(a0)
    sll s3, s2, 2
    addiu v0, zero, 0x2
    addu v1, v1, s3
    lw v1, 0x0(v1)
    lbu v1, 0xBA6(v1)
    beq v1, v0, _L0014016C
    nop
    blez s5, _L00140154
    addu v0, s6, s3
    bne s4, s2, _L00140150
    nop
    paddub a0, s6, zero
    jal func_1401C0
    paddub a1, s2, zero
    bnez v0, _L0014016C
    nop
    _L00140150:
    addu v0, s6, s3
    _L00140154:
    lw v0, 0xD8(v0)
    slt at, s1, v0
    beqz at, _L0014016C
    nop
    paddub s1, v0, zero
    paddub s0, s2, zero
    _L0014016C:
    addiu s2, s2, 0x1
    _L00140170:
    lw v0, 0xAC(s6)
    lw v1, 0xAC(v0)
    lw a0, 0xB98(v1)
    lh v0, 0x50(a0)
    slt v0, s2, v0
    bnez v0, _L00140100
    nop
    paddub v0, s0, zero
    lq ra, 0x70(sp)
    lq s6, 0x60(sp)
    lq s5, 0x50(sp)
    lq s4, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x80
    .set reorder
    .set at
}

}
