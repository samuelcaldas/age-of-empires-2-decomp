#include "sub_list.h"

struct InfantryAI {
    void *m_vtable;
};

extern "C" {

void *func_1452B0(void *self, const char *name, int id, void *p2, void *p1);

asm InfantryAI *func_1446A0(InfantryAI *self, void *p1, void *p2) {
    .set noreorder
    .set noat
    nop
    addiu sp, sp, -0x20
    sq ra, 0x10(sp)
    paddub a3, a2, zero
    sq s0, 0x0(sp)
    paddub t0, a1, zero
    .word 0x3C020049
    addiu a1, v0, 0x0F90
    addiu a2, zero, 0x3ED
    jal func_1452B0
    paddub s0, a0, zero
    .word 0x3C02004D
    addiu v0, v0, 0x7780
    sw v0, 0x0(s0)
    paddub v0, s0, zero
    lq ra, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x20
    nop
    .set reorder
    .set at
}

}
