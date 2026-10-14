
#include "sub_list.h"

struct TacticalAI {
    void *m_vtable;
    char pad_04[0x30];

    int Save(void *stream);
};

extern "C" {
void func_00226F70(void *stream, void *src, int size);
int func_0011ACD0(const char *str);
char *func_0011ABBC(char *dst, const char *src);
void func_0013C560(void *item, void *stream);
void func_1444C0(void *item, void *stream);
void func_116F40(void*, void*, int);

asm int TacticalAI::Save(void *stream) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x70
    sq ra, 0x50(sp)
    sq s4, 0x40(sp)
    sq s3, 0x30(sp)
    paddub s4, a0, zero
    paddub s3, a1, zero
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    addiu a1, s4, 0x4
    addiu a2, zero, 0x8
    paddub a0, s3, zero
    jal func_00226F70
    sq s0, 0x0(sp)
    b _L00140F70
    paddub s0, zero, zero
    _L00140F2C:
    lw v0, 0x8(s4)
    sll s1, s0, 2
    addu v0, v0, s1
    jal func_0011ACD0
    lw a0, 0x0(v0)
    addiu a1, sp, 0x6C
    addiu a2, zero, 0x4
    sw v0, 0x6C(sp)
    jal func_00226F70
    paddub a0, s3, zero
    lw v0, 0x8(s4)
    lw a2, 0x6C(sp)
    addu v0, v0, s1
    lw a1, 0x0(v0)
    jal func_00226F70
    paddub a0, s3, zero
    addiu s0, s0, 0x1
    _L00140F70:
    lh v0, 0x6(s4)
    slt v0, s0, v0
    bnez v0, _L00140F2C
    nop
    addiu a1, s4, 0xC
    addiu a2, zero, 0x2
    jal func_00226F70
    paddub a0, s3, zero
    addiu a1, s4, 0x14
    addiu a2, zero, 0x2
    jal func_00226F70
    paddub a0, s3, zero
    addiu a1, s4, 0x1C
    addiu a2, zero, 0x2
    jal func_00226F70
    paddub a0, s3, zero
    b _L00141034
    paddub s0, zero, zero
    _L00140FB8:
    lw v0, 0x20(s4)
    sll v1, s0, 4
    addiu a2, zero, 0x10
    paddub a0, s3, zero
    addu s1, v0, v1
    jal func_00226F70
    paddub a1, s1, zero
    lw v0, 0x0(s1)
    beql v0, zero, _L00141034
    addiu s0, s0, 0x1
    lw v0, 0xC(s1)
    beqz v0, _L00141030
    nop
    b _L00141020
    paddub s2, zero, zero
    _L00140FF8:
    sll v0, s2, 2
    addu v1, v0, s2
    lw v0, 0xC(s1)
    sll v1, v1, 3
    addu v1, v1, s2
    sll v1, v1, 3
    addiu a2, zero, 0x148
    addu a1, v0, v1
    jal func_00226F70
    paddub a0, s3, zero
    addiu s2, s2, 0x1
    _L00141020:
    lh v0, 0xA(s1)
    slt v0, s2, v0
    bnez v0, _L00140FF8
    sll v0, s2, 2
    _L00141030:
    addiu s0, s0, 0x1
    _L00141034:
    lh v0, 0x1C(s4)
    slt v0, s0, v0
    bnez v0, _L00140FB8
    nop
    b _L001410A0
    paddub s0, zero, zero
    _L0014104C:
    lw v0, 0x24(s4)
    sll v1, s0, 3
    addiu a2, zero, 0x8
    paddub a0, s3, zero
    addu s1, v0, v1
    jal func_00226F70
    paddub a1, s1, zero
    lw v0, 0x20(s4)
    sll v1, s0, 4
    addu v0, v0, v1
    lw v0, 0x0(v0)
    beql v0, zero, _L001410A0
    addiu s0, s0, 0x1
    lw a1, 0x4(s1)
    beqz a1, _L0014109C
    nop
    lh v0, 0x2(s1)
    paddub a0, s3, zero
    jal func_00226F70
    sll a2, v0, 1
    _L0014109C:
    addiu s0, s0, 0x1
    _L001410A0:
    lh v0, 0x1C(s4)
    slt v0, s0, v0
    bnez v0, _L0014104C
    nop
    lq ra, 0x50(sp)
    lq s4, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    addiu v0, zero, 0x1
    jr ra
    addiu sp, sp, 0x70
    .set reorder
    .set at
}

asm int func_001410E0(TacticalAI *self, int a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    lh v1, 0x6(a0)
    lh v0, 0x4(a0)
    paddub s1, a1, zero
    slt v0, v1, v0
    bnez v0, _L00141110
    paddub s0, a0, zero
    b _L0014115C
    addiu v0, zero, -0x1
    _L00141110:
    jal func_0011ACD0
    paddub a0, s1, zero
    jal func_116F40
    addiu a0, v0, 0x1
    lh a0, 0x6(s0)
    lw v1, 0x8(s0)
    sll a0, a0, 2
    addu v1, v1, a0
    sw v0, 0x0(v1)
    lh v1, 0x6(s0)
    lw v0, 0x8(s0)
    sll v1, v1, 2
    addu v0, v0, v1
    lw a0, 0x0(v0)
    jal func_0011ABBC
    paddub a1, s1, zero
    lh v0, 0x6(s0)
    addiu v1, v0, 0x1
    sh v1, 0x6(s0)
    _L0014115C:
    lq ra, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    .set reorder
    .set at
}

asm int func_00141170(TacticalAI *self, int a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x20
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    lh v1, 0xE(a0)
    lh v0, 0xC(a0)
    slt v0, v1, v0
    bnez v0, _L00141198
    paddub s0, a0, zero
    b _L001411CC
    addiu v0, zero, -0x1
    _L00141198:
    sll v0, v1, 1
    addu v1, v0, v1
    lw v0, 0x10(s0)
    sll v1, v1, 3
    .word 0x70004628
    .word 0x70004E28
    .word 0x70005628
    .word 0x70005E28
    jal func_1444C0
    addu a0, v0, v1
    lh v0, 0xE(s0)
    addiu v1, v0, 0x1
    sh v1, 0xE(s0)
    _L001411CC:
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    .set reorder
    .set at
}

asm int func_001411E0(TacticalAI *self, int a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x20
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    lh v1, 0x16(a0)
    lh v0, 0x14(a0)
    slt v0, v1, v0
    bnez v0, _L00141208
    paddub s0, a0, zero
    b _L0014123C
    addiu v0, zero, -0x1
    _L00141208:
    sll v0, v1, 1
    addu v1, v0, v1
    lw v0, 0x18(s0)
    sll v1, v1, 2
    .word 0x70003E28
    .word 0x70004628
    .word 0x70004E28
    .word 0x70005628
    jal func_0013C560
    addu a0, v0, v1
    lh v0, 0x16(s0)
    addiu v1, v0, 0x1
    sh v1, 0x16(s0)
    _L0014123C:
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    .set reorder
    .set at
}

}
