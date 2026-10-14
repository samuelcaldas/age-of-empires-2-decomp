
#include "sub_list.h"

struct TacticalAI {
    void *m_vtable;
    char pad_04[0x30];
};

extern "C" {
void *func_100730(int size);
void func_00100630(void *ptr);
int func_141A20(void *self, int a1);
void func_117AF8(void*, void*, int);
void func_1444F0(void*, void*, int);

asm int func_00141250(TacticalAI *self, int a1, int a2, void *a3) {
    .set noreorder
    .set noat
    lw v0, 0x20(a0)
    sll v1, a1, 4
    addu v1, v0, v1
    lh t1, 0xA(v1)
    lh v0, 0x8(v1)
    slt v0, t1, v0
    bnez v0, _L0014127C
    sll v0, t1, 2
    b _L00141360
    addiu v0, zero, -0x1
    _L0014127C:
    sll v0, t1, 2
    addu t0, v0, t1
    lw v0, 0xC(v1)
    sll t0, t0, 3
    addu t0, t0, t1
    sll t0, t0, 3
    addiu t1, zero, 0x29
    addu t2, v0, t0
    _L00141298:
    lw t0, 0x0(a3)
    lw v0, 0x4(a3)
    addiu t1, t1, -0x1
    sw t0, 0x0(t2)
    sw v0, 0x4(t2)
    addiu a3, a3, 0x8
    bgtz t1, _L00141298
    addiu t2, t2, 0x8
    lh t0, 0xA(v1)
    lw t1, 0xC(v1)
    addiu t2, zero, 0x1
    addiu v0, zero, -0x1
    sll a3, t0, 2
    addu a3, a3, t0
    sll a3, a3, 3
    addu a3, a3, t0
    sll a3, a3, 3
    addu a3, a3, t1
    sb t2, 0x4(a3)
    lh t1, 0xA(v1)
    lw a3, 0xC(v1)
    sll t0, t1, 2
    addu t0, t0, t1
    sll t0, t0, 3
    addu t0, t0, t1
    sll t0, t0, 3
    addu a3, a3, t0
    beq a2, v0, _L00141354
    sh t1, 0x0(a3)
    lw t0, 0x24(a0)
    sll v0, a1, 3
    sll a3, a2, 1
    lw a1, 0xC(v1)
    addu v0, v0, t0
    lh a0, 0xA(v1)
    lw a2, 0x4(v0)
    sll v0, a0, 2
    addu v0, v0, a0
    sll v0, v0, 3
    addu v0, v0, a0
    addu a2, a2, a3
    lh a0, 0x0(a2)
    sll v0, v0, 3
    addu v0, v0, a1
    sh a0, 0x2(v0)
    lh v0, 0xA(v1)
    sh v0, 0x0(a2)
    _L00141354:
    lh v0, 0xA(v1)
    addiu a0, v0, 0x1
    sh a0, 0xA(v1)
    _L00141360:
    jr ra
    nop
    .set reorder
    .set at
}

asm int func_00141370(TacticalAI *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s1, a0, zero
    jal func_141A20
    paddub s0, a1, zero
    bnez v0, _L0014139C
    nop
    b _L00141454
    addiu v0, zero, -0x1
    _L0014139C:
    lw v0, 0x24(s1)
    sll v1, s0, 3
    addu s0, v0, v1
    lh v0, 0x2(s0)
    lh v1, 0x0(s0)
    slt v0, v0, v1
    bnez v0, _L00141448
    nop
    lw s1, 0x4(s0)
    addiu v0, v1, 0x64
    sh v0, 0x0(s0)
    lh v0, 0x0(s0)
    slti at, v0, 0x7D1
    bnel at, zero, _L001413E4
    dsll32 v0, v0, 16
    b _L00141454
    addiu v0, zero, -0x1
    _L001413E4:
    dsll32 v0, v0, 16
    dsra32 v0, v0, 16
    dsll v0, v0, 1
    dsll32 a0, v0, 0
    jal func_100730
    dsra32 a0, a0, 0
    sw v0, 0x4(s0)
    lh v0, 0x2(s0)
    lw a0, 0x4(s0)
    paddub a1, s1, zero
    jal func_117AF8
    sll a2, v0, 1
    lh a1, 0x2(s0)
    b _L00141430
    addiu a0, zero, -0x1
    _L0014141C:
    lw v0, 0x4(s0)
    sll v1, a1, 1
    addiu a1, a1, 0x1
    addu v0, v0, v1
    sh a0, 0x0(v0)
    _L00141430:
    lh v0, 0x0(s0)
    slt v0, a1, v0
    bnez v0, _L0014141C
    nop
    jal func_00100630
    paddub a0, s1, zero
    _L00141448:
    lh v0, 0x2(s0)
    addiu v1, v0, 0x1
    sh v1, 0x2(s0)
    _L00141454:
    lq ra, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    .set reorder
    .set at
}

asm int func_00141470(TacticalAI *self, int a1) {
    .set noreorder
    .set noat
    lw v0, 0x28(a0)
    bnez v0, _L00141484
    nop
    b _L0014148C
    addiu v0, zero, -0x1
    _L00141484:
    lh v0, 0x0(v0)
    nop
    _L0014148C:
    jr ra
    nop
    .set reorder
    .set at
}

asm int func_001414A0(TacticalAI *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s1, a0, zero
    b _L001414D8
    paddub s0, zero, zero
    _L001414C0:
    sll v0, s0, 1
    addu v1, v0, s0
    lw v0, 0x10(s1)
    sll v1, v1, 3
    jal func_1444F0
    addu a0, v0, v1
    addiu s0, s0, 0x1
    _L001414D8:
    lh v1, 0xE(s1)
    slt v1, s0, v1
    bnel v1, zero, _L001414C0
    sll v0, s0, 1
    lq ra, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    .set reorder
    .set at
}

}
