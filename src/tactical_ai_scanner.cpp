#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

int func_001428B0(void *self, char *buf);
void func_144340(void *self, int a1, int a2);

asm int func_142980(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    paddub s1, a0, zero
    addiu v0, s1, 0x1A0
    sq s0, 0x0(sp)
    sw v0, 0x2A0(a0)
    lw v0, 0x2A0(a0)
    paddub s0, zero, zero
    sb zero, 0x0(v0)
    .word 0x10000058
    sw zero, 0x19C(a0)
_L001429B0:
    lw a0, 0x6A8(s1)
    addiu v0, zero, 0x22
    lb v1, 0x0(a0)
    beq v1, v0, _L00142AD4
    addiu v0, a0, 0x1
    beqz v1, _L00142A9C
    nop
    addiu v0, zero, 0x3B
    beq v1, v0, _L00142A9C
    nop
    addiu v0, zero, 0x29
    beq v1, v0, _L00142A6C
    addiu v0, a0, 0x1
    addiu v0, zero, 0x28
    beq v1, v0, _L00142A3C
    addiu v0, a0, 0x1
    addiu v0, zero, 0xD
    beq v1, v0, _L00142A28
    nop
    addiu v0, zero, 0xA
    beq v1, v0, _L00142A28
    nop
    addiu v0, zero, 0x9
    beq v1, v0, _L00142A28
    nop
    addiu v0, zero, 0x20
    beq v1, v0, _L00142A28
    nop
    .word 0x10000032
    addiu v0, a0, 0x1
_L00142A28:
    lw v0, 0x6A8(s1)
    addiu v0, v0, 0x1
    .word 0x10000036
    sw v0, 0x6A8(s1)
    addiu v0, a0, 0x1
_L00142A3C:
    sw v0, 0x6A8(s1)
    lb a1, 0x0(a0)
    addiu v0, zero, 0x2
    lw a0, 0x2A0(s1)
    addiu v1, a0, 0x1
    sw v1, 0x2A0(s1)
    sb a1, 0x0(a0)
    lw v1, 0x2A0(s1)
    sb zero, 0x0(v1)
    .word 0x10000081
    sw v0, 0x19C(s1)
    addiu v0, a0, 0x1
_L00142A6C:
    sw v0, 0x6A8(s1)
    lb a2, 0x0(a0)
    lw a1, 0x2A0(s1)
    addiu v1, zero, 0x3
    addiu v0, zero, 0x2
    addiu a0, a1, 0x1
    sw a0, 0x2A0(s1)
    sb a2, 0x0(a1)
    lw a0, 0x2A0(s1)
    sb zero, 0x0(a0)
    .word 0x10000074
    sw v1, 0x19C(s1)
_L00142A9C:
    lw v0, 0x6B0(s1)
    addiu a1, s1, 0x2A8
    paddub a0, s1, zero
    addiu v0, v0, 0x1
    jal func_001428B0
    sw v0, 0x6B0(s1)
    bnez v0, _L00142AC8
    addiu v0, s1, 0x2A8
    .word 0x1000006A
    addiu v0, zero, 0x1
    addiu v0, s1, 0x2A8
_L00142AC8:
    .word 0x10000010
    sw v0, 0x6A8(s1)
    addiu v0, a0, 0x1
_L00142AD4:
    sw v0, 0x6A8(s1)
    addiu v0, zero, 0x4
    addiu s0, zero, 0x1
    .word 0x1000000A
    sw v0, 0x19C(s1)
    addiu v0, a0, 0x1
_L00142AEC:
    sw v0, 0x6A8(s1)
    lw v1, 0x2A0(s1)
    lb a0, 0x0(a0)
    .word 0x24100001
    addiu v0, v1, 0x1
    sw v0, 0x2A0(s1)
    sb a0, 0x0(v1)
    sw s0, 0x19C(s1)
_L00142B0C:
    beqz s0, _L001429B0
    nop
    lw a0, 0x19C(s1)
    .word 0x24030001
    bne a0, v1, _L00142C54
    paddub v0, zero, zero
    addiu t4, zero, 0x3B
    addiu t3, zero, 0x29
    addiu t2, zero, 0x28
    addiu t1, zero, 0xD
    addiu t0, zero, 0xA
    addiu a3, zero, 0x9
    .word 0x10000024
    addiu a2, zero, 0x20
_L00142B44:
    lw a0, 0x6A8(s1)
    lb v1, 0x0(a0)
    beql v1, t4, _L00142BAC
    addiu v0, zero, 0x1
    beqz v1, _L00142BA8
    nop
    beq v1, t3, _L00142BA8
    nop
    beq v1, t2, _L00142BA8
    nop
    beq v1, t1, _L00142B94
    nop
    beq v1, t0, _L00142B94
    nop
    beq v1, a3, _L00142B94
    nop
    beq v1, a2, _L00142B94
    nop
    .word 0x1000000A
    addiu v1, a0, 0x1
_L00142B94:
    lw v1, 0x6A8(s1)
    addiu v0, zero, 0x1
    addiu v1, v1, 0x1
    .word 0x1000000B
    sw v1, 0x6A8(s1)
_L00142BA8:
    addiu v0, zero, 0x1
_L00142BAC:
    .word 0x10000008
    nop
    addiu v1, a0, 0x1
_L00142BB8:
    sw v1, 0x6A8(s1)
    lb a1, 0x0(a0)
    lw a0, 0x2A0(s1)
    addiu v1, a0, 0x1
    sw v1, 0x2A0(s1)
    sb a1, 0x0(a0)
_L00142BD0:
    beqz v0, _L00142B44
    nop
    .word 0x10000021
    lw v1, 0x2A0(s1)
_L00142BE0:
    lw a1, 0x6A8(s1)
    addiu v1, zero, 0x22
    lb a0, 0x0(a1)
    beql a0, v1, _L00142C2C
    addiu v0, a1, 0x1
    beql a0, zero, _L00142C14
    addiu a1, zero, 0x9
    addiu v1, zero, 0xA
    beq a0, v1, _L00142C10
    nop
    .word 0x1000000C
    addiu v1, a1, 0x1
_L00142C10:
    addiu a1, zero, 0x9
_L00142C14:
    paddub a0, s1, zero
    jal func_144340
    .word 0x70003628
    .word 0x10000011
    paddub v0, zero, zero
    addiu v0, a1, 0x1
_L00142C2C:
    sw v0, 0x6A8(s1)
    .word 0x10000008
    addiu v0, zero, 0x1
    addiu v1, a1, 0x1
_L00142C3C:
    sw v1, 0x6A8(s1)
    lw a0, 0x2A0(s1)
    lb a1, 0x0(a1)
    addiu v1, a0, 0x1
    sw v1, 0x2A0(s1)
    sb a1, 0x0(a0)
_L00142C54:
    beqz v0, _L00142BE0
    nop
    lw v1, 0x2A0(s1)
_L00142C60:
    addiu v0, zero, 0x2
    sb zero, 0x0(v1)
_L00142C68:
    lq ra, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    nop
    .set reorder
    .set at
}

}
