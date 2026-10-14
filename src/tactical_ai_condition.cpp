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

asm int func_144544(TacticalNode *self, int a1, int a2, int a3, int t0) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x20
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    lw v0, 0x0(a0)
    addiu t2, zero, 0x3
    beq v0, t2, _L00144670
    paddub s0, a0, zero
    addiu t1, zero, 0x2
    beq v0, t1, _L0014463C
    nop
    addiu a0, zero, 0x1
    beq v0, a0, _L00144580
    nop
    b _L0014467C
    lw v0, 0x8(s0)
_L00144580:
    lbu v1, 0xC(s0)
    addiu v0, zero, 0x4
    beq v1, v0, _L00144614
    nop
    beq v1, t2, _L001445F8
    nop
    beq v1, t1, _L001445E0
    nop
    beq v1, a0, _L001445CC
    nop
    beqz v1, _L001445B8
    nop
    b _L00144634
    lw v0, 0x8(s0)
_L001445B8:
    lw v0, 0x10(s0)
    jalr ra, v0
    nop
    b _L00144630
    sw v0, 0x8(s0)
_L001445CC:
    lw v0, 0x10(s0)
    jalr ra, v0
    paddub a0, a1, zero
    b _L00144630
    sw v0, 0x8(s0)
_L001445E0:
    lw v0, 0x10(s0)
    paddub a0, a1, zero
    jalr ra, v0
    paddub a1, a2, zero
    b _L00144630
    sw v0, 0x8(s0)
_L001445F8:
    lw v0, 0x10(s0)
    paddub a0, a1, zero
    paddub a1, a2, zero
    jalr ra, v0
    paddub a2, a3, zero
    b _L00144630
    sw v0, 0x8(s0)
_L00144614:
    lw v0, 0x10(s0)
    paddub a0, a1, zero
    paddub a1, a2, zero
    paddub a2, a3, zero
    jalr ra, v0
    paddub a3, t0, zero
    sw v0, 0x8(s0)
_L00144630:
    lw v0, 0x8(s0)
_L00144634:
    b _L00144684
    lq ra, 0x10(sp)
_L0014463C:
    lw v0, 0x4(s0)
    .word 0x10400003
    nop
    .word 0x1000000D
    lw v0, 0x8(s0)
    lw v0, 0x10(s0)
    jalr ra, v0
    nop
    sw v0, 0x8(s0)
    addiu v0, zero, 0x1
    sw v0, 0x4(s0)
    .word 0x10000005
    lw v0, 0x8(s0)
_L00144670:
    .word 0x10000003
    lw v0, 0x8(s0)
    .word 0x8E020008
_L0014467C:
    nop
_L00144680:
    lq ra, 0x10(sp)
_L00144684:
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    .set reorder
    .set at
}

asm int func_00144694(TacticalNode *self) {
    .set noreorder
    .set noat
    jr ra
    lbu v0, 0xC(a0)
    .set reorder
    .set at
}

}
