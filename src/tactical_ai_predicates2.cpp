#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

int func_0011AA78(const char *s1, const char *s2);
void func_144340(void *ptr, int a1, int a2);
int func_00142C90(void *self);
int func_00142830(void *self);
void func_1442E0(void *self);
void *func_00142730(void *self, void *buf, int a2);
int func_00142C80(void *self);
int func_00142CA0(void *self);
void func_144180(void *self);

asm int func_143860(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x40
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s0, a0, zero
    .word 0x3C020049
    addiu a0, s0, 0x1A0
    jal func_0011AA78
    addiu a1, v0, 0x0ED0
    bnez v0, _L00143898
    nop
    .word 0x1000001F
    addiu s1, zero, 0x1
_L00143898:
    .word 0x3C020049
    addiu a0, s0, 0x1A0
    jal func_0011AA78
    addiu a1, v0, 0x0EF0
    bnez v0, _L001438B8
    nop
    .word 0x10000017
    addiu s1, zero, 0x2
_L001438B8:
    .word 0x3C020049
    addiu a0, s0, 0x1A0
    jal func_0011AA78
    addiu a1, v0, 0x0F08
    bnez v0, _L001438D8
    nop
    .word 0x1000000F
    addiu s1, zero, 0x3
_L001438D8:
    .word 0x3C020049
    addiu a0, s0, 0x1A0
    jal func_0011AA78
    addiu a1, v0, 0x0F10
    bnez v0, _L001438FC
    addiu a2, s0, 0x1A0
    .word 0x10000007
    addiu s1, zero, 0x4
    addiu a2, s0, 0x1A0
_L001438FC:
    addiu a1, zero, 0x5
    jal func_144340
    paddub a0, s0, zero
    .word 0x10000068
    paddub v0, zero, zero
_L00143910:
    addiu v0, zero, 0x4
    beq s1, v0, _L00143A74
    .word 0x72002628
    addiu v0, zero, 0x3
    beq s1, v0, _L00143A10
    .word 0x72002628
    addiu v0, zero, 0x2
    beq s1, v0, _L0014394C
    .word 0x72002628
    addiu v0, zero, 0x1
    beq s1, v0, _L00143948
    nop
    .word 0x1000005A
    .word 0x24020001
_L00143948:
    paddub a0, s0, zero
_L0014394C:
    jal func_00142C90
    nop
    beqz v0, _L00143978
    paddub a0, s0, zero
    addiu a1, zero, 0x13
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    .word 0x1000004F
    paddub v0, zero, zero
    paddub a0, s0, zero
_L00143978:
    jal func_00142830
    nop
    bnez v0, _L00143994
    paddub a0, s0, zero
    .word 0x10000048
    paddub v0, zero, zero
    paddub a0, s0, zero
_L00143994:
    jal func_1442E0
    nop
    addiu a1, s0, 0x1A0
    addiu a2, zero, 0x5
    paddub a0, s0, zero
    jal func_00142730
    paddub s2, zero, zero
    beqz v0, _L001439C0
    addiu v0, zero, 0x1
    addiu s2, zero, 0x1
    .word 0x24020001
_L001439C0:
    bne s1, v0, _L001439E8
    nop
    lw v0, 0x198(s0)
    sltu v0, zero, v0
    beql v0, zero, _L001439E0
    andi v0, v0, 0xFF
    sltu v0, zero, s2
    andi v0, v0, 0xFF
_L001439E0:
    .word 0x10000031
    sw v0, 0x198(s0)
_L001439E8:
    lw v0, 0x198(s0)
    sltu v0, zero, v0
    beql v0, zero, _L00143A04
    andi v0, v0, 0xFF
    sltu v0, zero, s2
    xori v0, v0, 0x1
    andi v0, v0, 0xFF
_L00143A04:
    .word 0x10000028
    sw v0, 0x198(s0)
    paddub a0, s0, zero
_L00143A10:
    jal func_00142C80
    nop
    beqz v0, _L00143A3C
    paddub a0, s0, zero
    addiu a1, zero, 0x17
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    .word 0x1000001E
    paddub v0, zero, zero
    paddub a0, s0, zero
_L00143A3C:
    jal func_00142CA0
    paddub s1, zero, zero
    beqz v0, _L00143A68
    andi v0, s1, 0xFF
    lw v0, 0x198(s0)
    sltu v0, zero, v0
    xori v0, v0, 0x1
    beqz v0, _L00143A64
    nop
    daddiu s1, zero, 0x1
_L00143A64:
    andi v0, s1, 0xFF
_L00143A68:
    .word 0x1000000F
    sw v0, 0x198(s0)
    paddub a0, s0, zero
_L00143A74:
    jal func_00142C80
    nop
    beqz v0, _L00143AA0
    paddub a0, s0, zero
    addiu a1, zero, 0x18
    paddub a0, s0, zero
    jal func_144340
    .word 0x70003628
    .word 0x10000005
    paddub v0, zero, zero
    paddub a0, s0, zero
_L00143AA0:
    jal func_144180
    nop
_L00143AA8:
    addiu v0, zero, 0x1
_L00143AAC:
    lq ra, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x40
    nop
    nop
    nop
    .set reorder
    .set at
}

}
