#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
};

extern "C" {

int func_1AAB30(void);
int func_142980(void *ptr);
void func_144340(void *ptr, int a1, int a2);
int func_114378(const char *str);
char *func_0011ABBC(char *dst, const char *src);
int func_001427A0(void *self);
void func_1441B0(void);
int func_00142560(TacticalAI2 *self, void *buf);
void func_144050(void *self);

asm int func_143AD0(TacticalAI2 *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x3A0
    sq ra, 0x60(sp)
    sq s5, 0x50(sp)
    sq s4, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s5, a0, zero
    jal func_1AAB30
    paddub s0, zero, zero
    addiu v1, zero, 0x64
    .word 0x0043001A
    paddub s2, zero, zero
    .word 0x70009E28
    .word 0x7000A628
    mfhi v0
    addiu s1, v0, 0x1
_L00143B18:
    jal func_142980
    paddub a0, s5, zero
    addiu v1, zero, 0x2
    beq v0, v1, _L00143B54
    nop
    addiu v1, zero, 0x1
    bne v0, v1, _L00143B4C
    paddub v0, zero, zero
    addiu a1, zero, 0x1A
    paddub a0, s5, zero
    jal func_144340
    .word 0x70003628
    paddub v0, zero, zero
_L00143B4C:
    .word 0x100000A3
    lq ra, 0x60(sp)
_L00143B54:
    lw a1, 0x19C(s5)
    addiu v0, zero, 0x1
    bne a1, v0, _L00143BA8
    addiu v0, zero, 0x4
    lb v1, 0x1A0(s5)
    .word 0x3C020048
    addiu v0, v0, -0x1F00
    addu v0, v0, v1
    lb v0, 0x1(v0)
    andi v0, v0, 0x4
    bnez v0, _L00143B9C
    addiu a0, zero, 0x1
    dsll32 v1, v1, 24
    addiu v0, zero, 0x2B
    dsra32 v1, v1, 24
    bne v1, v0, _L00143BA4
    nop
    addiu a0, zero, 0x1
_L00143B9C:
    .word 0x10000012
    addiu v1, zero, 0x2
_L00143BA4:
    addiu v0, zero, 0x4
_L00143BA8:
    bne a1, v0, _L00143BBC
    addiu a0, zero, 0x3
    .word 0x1000000C
    addiu a0, zero, 0x2
    addiu a0, zero, 0x3
_L00143BBC:
    bne a1, a0, _L00143BD0
    addiu a1, zero, 0xC
    .word 0x10000007
    nop
    addiu a1, zero, 0xC
_L00143BD0:
    paddub a0, s5, zero
    jal func_144340
    .word 0x70003628
    .word 0x1000007E
    paddub v0, zero, zero
_L00143BE4:
    addiu v1, zero, 0x2
_L00143BE8:
    beq s0, v1, _L00143D38
    addiu v0, zero, 0x3
    addiu v0, zero, 0x1
    beq s0, v0, _L00143CA4
    nop
    beqz s0, _L00143C0C
    nop
    .word 0x1000FFC4
    nop
_L00143C0C:
    beql a0, v1, _L00143C40
    addiu a0, sp, 0x70
    beq a0, v0, _L00143C28
    addiu a0, s5, 0x1A0
    .word 0x1000001C
    addiu a1, zero, 0xC
    addiu a0, s5, 0x1A0
_L00143C28:
    jal func_114378
    nop
    addiu s0, zero, 0x1
    .word 0x1000FFB8
    paddub s3, v0, zero
    addiu a0, sp, 0x70
_L00143C40:
    jal func_0011ABBC
    addiu a1, s5, 0x1A0
    jal func_001427A0
    paddub a0, s5, zero
    bnez v0, _L00143C64
    paddub a0, s5, zero
    .word 0x1000005F
    paddub v0, zero, zero
    paddub a0, s5, zero
_L00143C64:
    jal func_1441B0
    nop
    addiu a1, sp, 0x70
    jal func_00142560
    paddub a0, s5, zero
    paddub s0, v0, zero
    jal func_144050
    paddub a0, s5, zero
    .word 0x10000054
    paddub v0, s0, zero
    addiu a1, zero, 0xC
_L00143C90:
    paddub a0, s5, zero
    jal func_144340
    .word 0x70003628
    .word 0x1000004E
    paddub v0, zero, zero
_L00143CA4:
    beq a0, v1, _L00143CC8
    paddub v0, s2, zero
    addiu a1, zero, 0xC
    paddub a0, s5, zero
    jal func_144340
    .word 0x70003628
    .word 0x10000046
    paddub v0, zero, zero
    paddub v0, s2, zero
_L00143CC8:
    addu s2, s2, s3
    bnez s4, _L00143B18
    paddub s0, v1, zero
    slt at, v0, s1
    beqz at, _L00143B18
    nop
    slt at, s2, s1
    bnez at, _L00143B18
    nop
    addiu a0, sp, 0x180
    jal func_0011ABBC
    addiu a1, s5, 0x1A0
    jal func_1441B0
    paddub a0, s5, zero
    addiu a1, sp, 0x180
    jal func_00142560
    paddub a0, s5, zero
    paddub s4, v0, zero
    jal func_144050
    paddub a0, s5, zero
    bnez s4, _L00143D2C
    addiu s4, zero, 0x1
    .word 0x1000002D
    paddub v0, zero, zero
    addiu s4, zero, 0x1
_L00143D2C:
    .word 0x1000FF7A
    nop
    addiu v0, zero, 0x3
_L00143D38:
    beq a0, v0, _L00143DD8
    addiu v0, zero, 0x1
    beql a0, v1, _L00143D78
    addiu a0, sp, 0x290
    addiu v0, zero, 0x1
    beq a0, v0, _L00143D60
    addiu a0, s5, 0x1A0
    .word 0x1000FF70
    nop
    addiu a0, s5, 0x1A0
_L00143D60:
    jal func_114378
    nop
    addiu s0, zero, 0x1
    .word 0x1000FF6A
    paddub s3, v0, zero
    addiu a0, sp, 0x290
_L00143D78:
    jal func_0011ABBC
    addiu a1, s5, 0x1A0
    jal func_001427A0
    paddub a0, s5, zero
    bnez v0, _L00143D98
    nop
    .word 0x10000011
    paddub v0, zero, zero
_L00143D98:
    beqz s4, _L00143DAC
    paddub a0, s5, zero
    .word 0x1000000D
    addiu v0, zero, 0x1
    paddub a0, s5, zero
_L00143DAC:
    jal func_1441B0
    nop
    addiu a1, sp, 0x290
    jal func_00142560
    paddub a0, s5, zero
    paddub s0, v0, zero
    jal func_144050
    paddub a0, s5, zero
    .word 0x10000002
    paddub v0, s0, zero
    addiu v0, zero, 0x1
_L00143DD8:
    lq ra, 0x60(sp)
_L00143DDC:
    lq s5, 0x50(sp)
    lq s4, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x3A0
    nop
    .set reorder
    .set at
}

}
