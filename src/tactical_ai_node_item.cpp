#include "sub_list.h"

#pragma exceptions off

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

TacticalNode *func_00144434(TacticalNode *self) {
    self->field_0 = 0;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_C = 0;
    self->field_10 = 0;
    self->field_14 = 0;
    self->field_15 = 0;
    self->field_16 = 0;
    self->field_17 = 0;
    return self;
}

TacticalNode *func_00144464(TacticalNode *self, int a1) {
    if (self) {
        self->field_10 = 0;
        if ((short)a1 > 0) {
            func_00100670(self);
        }
    }
    return self;
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

void func_001444C0(TacticalNode *self, int unused, char a2, int (*a3)(), char t0, char t1, char t2, char t3) {
    self->field_C = a2;
    self->field_10 = a3;
    self->field_14 = t0;
    self->field_15 = t1;
    self->field_16 = t2;
    self->field_17 = t3;
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
