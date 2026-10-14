#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

void *memset(void *dst, int val, unsigned int size);
void func_144310(void *ptr);
void func_144340(void *ptr, int a1, int a2);
int func_21A3F0(int a0);
int func_142980(void *ptr);
int func_143860(void *ptr);
int func_143440(void *ptr);
int func_00142560(TacticalAI2 *self, int a1);

asm int func_001424A0(TacticalAI2 *self, int a1, int a2, int a3, int t0) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    sw a1, 0x190(a0)
    sw t0, 0x6B4(a0)
    sw a3, 0x3080(a0)
    addiu v0, zero, 0x1
    sw zero, 0x194(a0)
    sw v0, 0x198(a0)
    sw zero, 0x6C0(a0)
    paddub s0, a2, zero
    paddub s1, a0, zero
    sw zero, 0x2FB4(a0)
    addiu a0, s1, 0x6C4
    addiu a2, zero, 0x28F0
    jal memset
    paddub a1, zero, zero
    addiu a0, s1, 0x2FB8
    addiu a2, zero, 0xC8
    jal memset
    paddub a1, zero, zero
    jal func_144310
    paddub a0, s1, zero
    paddub a1, s0, zero
    jal func_00142560
    paddub a0, s1, zero
    bnez v0, _L0014251C
    nop
    .word 0x1000000B
    paddub v0, zero, zero
_L0014251C:
    lw v0, 0x194(s1)
    bnez v0, _L00142544
    addiu v0, zero, 0x1
    addiu a1, zero, 0x12
    paddub a0, s1, zero
    jal func_144340
    paddub a2, zero, zero
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L00142544:
    lq ra, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    nop
    nop
    .set reorder
    .set at
}

asm int func_00142560(TacticalAI2 *self, int a1) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    sw a1, 0x6AC(a0)
    lw s0, 0x2FB4(a0)
    paddub s1, a0, zero
    addiu v0, s1, 0x2A8
    sb zero, 0x2A8(a0)
    sw v0, 0x6A8(a0)
    sw zero, 0x6B0(a0)
    jal func_21A3F0
    paddub a0, a1, zero
    sw v0, 0x6B8(s1)
    paddub a0, s1, zero
    jal func_142980
    sw zero, 0x6BC(s1)
    .word 0x1000001F
    addiu v1, zero, 0x2
_L001425AC:
    lw v1, 0x19C(s1)
    addiu v0, zero, 0x1
    bne v1, v0, _L001425D8
    addiu v0, zero, 0x2
    jal func_143860
    paddub a0, s1, zero
    bnez v0, _L00142618
    paddub a0, s1, zero
    .word 0x10000025
    paddub v0, zero, zero
    addiu v0, zero, 0x2
_L001425D8:
    beq v1, v0, _L001425FC
    paddub a0, s1, zero
    addiu a1, zero, 0xF
    paddub a0, s1, zero
    jal func_144340
    paddub a2, zero, zero
    .word 0x1000001C
    paddub v0, zero, zero
    paddub a0, s1, zero
_L001425FC:
    jal func_143440
    nop
    bnez v0, _L00142614
    nop
    .word 0x10000015
    paddub v0, zero, zero
_L00142614:
    paddub a0, s1, zero
_L00142618:
    jal func_142980
    nop
    addiu v1, zero, 0x2
_L00142624:
    beq v0, v1, _L001425AC
    nop
    bnez v0, _L0014263C
    nop
    .word 0x1000000B
    paddub v0, zero, zero
_L0014263C:
    lw v0, 0x2FB4(s1)
    beq s0, v0, _L00142664
    addiu v0, zero, 0x1
    addiu a1, zero, 0xA
    paddub a0, s1, zero
    jal func_144340
    paddub a2, zero, zero
    .word 0x10000002
    paddub v0, zero, zero
    addiu v0, zero, 0x1
_L00142664:
    lq ra, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x30
    nop
    nop
    .set reorder
    .set at
}

}
