#include "sub_list.h"

struct TacticalAI {
    void *m_vtable;
    char pad_04[0x30];
};

extern "C" {

asm int func_001418E0(TacticalAI *self, int a1) {
    .set noreorder
    .set noat
    lw v1, 0x30(a0)
    bnez v1, _L001418F4
    nop
    b _L00141974
    paddub v0, zero, zero
_L001418F4:
    bltz a1, _L00141910
    paddub v0, zero, zero
    lh v0, 0x2(v1)
    slt v0, a1, v0
    bnez v0, _L00141918
    nop
    paddub v0, zero, zero
_L00141910:
    b _L00141974
    nop
_L00141918:
    lw v1, 0x4(v1)
    sll a1, a1, 1
    addu v1, v1, a1
    lh a1, 0x0(v1)
    .word 0x1000000F
    addiu v0, zero, -0x1
    sll v1, a1, 2
_L00141934:
    addu v1, v1, a1
    lw a2, 0x2C(a0)
    sll v1, v1, 3
    addu a1, v1, a1
    sll a1, a1, 3
    lw v1, 0xC(a2)
    addu v1, v1, a1
    sb zero, 0x5(v1)
    lw v1, 0x2C(a0)
    lw v1, 0xC(v1)
    addu v1, v1, a1
    lh a1, 0x2(v1)
    nop
_L00141968:
    bne a1, v0, _L00141934
    sll v1, a1, 2
    addiu v0, zero, 0x1
_L00141974:
    jr ra
    nop
    nop
    .set reorder
    .set at
}

asm int func_00141980(TacticalAI *self, int a1) {
    .set noreorder
    .set noat
    lw v1, 0x30(a0)
    bnez v1, _L00141994
    nop
    b _L00141A18
    paddub v0, zero, zero
_L00141994:
    bltz a1, _L001419B0
    paddub v0, zero, zero
    lh v0, 0x2(v1)
    slt v0, a1, v0
    bnez v0, _L001419B8
    nop
    paddub v0, zero, zero
_L001419B0:
    b _L00141A18
    nop
_L001419B8:
    lw v1, 0x4(v1)
    sll a1, a1, 1
    addiu a3, zero, 0x1
    addu v1, v1, a1
    lh a1, 0x0(v1)
    .word 0x1000000F
    addiu v0, zero, -0x1
    sll v1, a1, 2
_L001419D8:
    addu v1, v1, a1
    lw a2, 0x2C(a0)
    sll v1, v1, 3
    addu a1, v1, a1
    sll a1, a1, 3
    lw v1, 0xC(a2)
    addu v1, v1, a1
    sb a3, 0x5(v1)
    lw v1, 0x2C(a0)
    lw v1, 0xC(v1)
    addu v1, v1, a1
    lh a1, 0x2(v1)
    nop
_L00141A0C:
    bne a1, v0, _L001419D8
    sll v1, a1, 2
    addiu v0, zero, 0x1
_L00141A18:
    jr ra
    nop
    .set reorder
    .set at
}

asm int func_00141A20(TacticalAI *self, int a1) {
    .set noreorder
    .set noat
    bltz a1, _L00141A3C
    paddub v0, zero, zero
    lh v0, 0x1C(a0)
    slt v0, a1, v0
    bnez v0, _L00141A44
    nop
    paddub v0, zero, zero
_L00141A3C:
    b _L00141A5C
    nop
_L00141A44:
    lw v1, 0x20(a0)
    sll a1, a1, 4
    addiu v0, zero, 0x1
    addu v1, v1, a1
    lw v1, 0x0(v1)
    movz v0, zero, v1
_L00141A5C:
    jr ra
    nop
    .set reorder
    .set at
}

}
