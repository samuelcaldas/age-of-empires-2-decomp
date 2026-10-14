#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

char *func_0011ABBC(char *dst, const char *src);

asm void func_144050(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x20
    sq ra, 0x10(sp)
    sq s0, 0x0(sp)
    lw v0, 0x6C0(a0)
    paddub s0, a0, zero
    addiu v0, v0, -0x1
    sw v0, 0x6C0(a0)
    lw v1, 0x6C0(a0)
    sll v0, v1, 6
    addu v0, v0, v1
    sll v0, v0, 1
    addu v0, v0, v1
    sll v0, v0, 3
    addu v0, v0, a0
    lw v0, 0x6C4(v0)
    sw v0, 0x2A4(a0)
    lw v1, 0x6C0(a0)
    sll v0, v1, 6
    addu v0, v0, v1
    sll v0, v0, 1
    addu v0, v0, v1
    sll v0, v0, 3
    addu v0, v0, a0
    lw v0, 0xACC(v0)
    sw v0, 0x6AC(a0)
    lw v1, 0x6C0(a0)
    sll v0, v1, 6
    addu v0, v0, v1
    sll v0, v0, 1
    addu v0, v0, v1
    sll v0, v0, 3
    addu v0, v0, a0
    lw v0, 0xAC8(v0)
    sw v0, 0x6A8(a0)
    lw v1, 0x6C0(a0)
    sll v0, v1, 6
    addu v0, v0, v1
    sll v0, v0, 1
    addu v0, v0, v1
    sll v0, v0, 3
    addu v0, v0, a0
    lw v0, 0xAD0(v0)
    sw v0, 0x6B0(a0)
    lw v1, 0x6C0(a0)
    sll v0, v1, 6
    addu v0, v0, v1
    sll v0, v0, 1
    addu v0, v0, v1
    sll v0, v0, 3
    addu v0, a0, v0
    addiu a1, v0, 0x6C8
    jal func_0011ABBC
    addiu a0, s0, 0x2A8
    lw a0, 0x6C0(s0)
    sll v1, a0, 6
    addu v1, v1, a0
    sll v1, v1, 1
    addu v1, v1, a0
    sll v1, v1, 3
    addu v1, v1, s0
    lw v1, 0xAD4(v1)
    sw v1, 0x6B8(s0)
    lw a0, 0x6C0(s0)
    sll v1, a0, 6
    addu v1, v1, a0
    sll v1, v1, 1
    addu v1, v1, a0
    sll v1, v1, 3
    addu v1, v1, s0
    lw v1, 0xAD8(v1)
    sw v1, 0x6BC(s0)
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    nop
    .set reorder
    .set at
}

asm void func_144180(TacticalAI2 *self) {
    .set noreorder
    .set noat
    lw v1, 0x2FB4(a0)
    addiu v1, v1, -0x1
    sw v1, 0x2FB4(a0)
    lw v1, 0x2FB4(a0)
    sll v1, v1, 2
    addu v1, v1, a0
    lw v1, 0x2FB8(v1)
    jr ra
    sw v1, 0x198(a0)
    nop
    nop
    nop
    .set reorder
    .set at
}

}
