#include "sub_list.h"

struct TacticalNode {
    int field_0;
    int field_4;
    int field_8;
    char field_C;
    int (*field_10)();
    char field_14;
    char field_15;
    char field_16;
    char field_17;
};

extern "C" {

void func_00100670(void *ptr);

asm TacticalNode *func_00144434(TacticalNode *self) {
    .set noreorder
    .set noat
    sw zero, 0x0(a0)
    sw zero, 0x4(a0)
    sw zero, 0x8(a0)
    sb zero, 0xC(a0)
    sw zero, 0x10(a0)
    sb zero, 0x14(a0)
    sb zero, 0x15(a0)
    sb zero, 0x16(a0)
    sb zero, 0x17(a0)
    jr ra
    paddub v0, a0, zero
    nop
    .set reorder
    .set at
}

asm TacticalNode *func_00144464(TacticalNode *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x20
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s0, a0, zero
    beqz s0, _L00144498
    paddub v0, s0, zero
    dsll32 v0, a1, 16
    dsra32 v0, v0, 16
    blez v0, _L00144494
    sw zero, 0x10(s0)
    jal func_00100670
    nop
_L00144494:
    paddub v0, s0, zero
_L00144498:
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    nop
    nop
    nop
    .set reorder
    .set at
}

asm void func_001444B4(TacticalNode *self, int a1) {
    .set noreorder
    .set noat
    sw a1, 0x0(a0)
    sw zero, 0x4(a0)
    sw zero, 0x8(a0)
    .set reorder
    .set at
}

asm void func_001444C0(TacticalNode *self, char a2, int (*a3)(), char t0, char t1, char t2, char t3) {
    .set noreorder
    .set noat
    sb a2, 0xC(a0)
    sw a3, 0x10(a0)
    sb t0, 0x14(a0)
    sb t1, 0x15(a0)
    sb t2, 0x16(a0)
    jr ra
    sb t3, 0x17(a0)
    nop
    nop
    .set reorder
    .set at
}

asm void func_001444E4(TacticalNode *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x20
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    .set reorder
    .set at
}

asm void func_001444F0(TacticalNode *self) {
    .set noreorder
    .set noat
    paddub s0, a0, zero
    lw a0, 0x0(a0)
    addiu v1, zero, 0x3
    bne a0, v1, _L00144514
    nop
    lw v0, 0x10(s0)
    jalr ra, v0
    nop
    sw v0, 0x8(s0)
_L00144514:
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    .set reorder
    .set at
}

asm void func_00144524(TacticalNode *self) {
    .set noreorder
    .set noat
    lw a1, 0x0(a0)
    addiu v1, zero, 0x2
    .word 0x14A30002 // bne a1, v1, +2 (to 0x144538)
    .set reorder
    .set at
}

asm void func_00144530(TacticalNode *self) {
    .set noreorder
    .set noat
    nop
    sw zero, 0x4(a0)
    jr ra
    nop
    nop
    .set reorder
    .set at
}

}
