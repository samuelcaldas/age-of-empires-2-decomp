#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

void func_144340(void *ptr, int a1, int a2);

asm int func_00142C80(TacticalAI2 *self) {
    .set noreorder
    .set noat
    lw v0, 0x2FB4(a0)
    xor v0, v0, zero
    jr ra
    sltiu v0, v0, 0x1
    .set reorder
    .set at
}

asm int func_00142C90(TacticalAI2 *self) {
    .set noreorder
    .set noat
    lw v0, 0x2FB4(a0)
    xori v0, v0, 0x32
    jr ra
    sltiu v0, v0, 0x1
    .set reorder
    .set at
}

asm int func_00142CA0(TacticalAI2 *self) {
    .set noreorder
    .set noat
    lw v0, 0x2FB4(a0)
    sll v0, v0, 2
    addu v0, v0, a0
    jr ra
    lw v0, 0x2FB4(v0)
    nop
    nop
    nop
    .set reorder
    .set at
}

asm int func_00142CC0(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x10
    sq ra, 0x0(sp)
    lw v0, 0x40(a0)
    addiu v0, v0, 0x1
    sw v0, 0x40(a0)
    lw v0, 0x40(a0)
    slti v0, v0, 0x10
    bnez v0, _L00142CFC
    addiu v0, zero, 0x1
    addiu a1, zero, 0x14
    jal func_144340
    .word 0x70003628
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L00142CFC:
    lq ra, 0x0(sp)
    jr ra
    addiu sp, sp, 0x10
    nop
    nop
    .set reorder
    .set at
}

}
