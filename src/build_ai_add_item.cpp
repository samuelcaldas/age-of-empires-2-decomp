
#include "sub_list.h"
extern "C" {
char* func_0011ABBC(char *dest, const char *src);
char* func_0011B170(char *dest, const char *src, int count);
void func_0013C960(void *item, int p74, int a1, int a3,
                   int p78, int p7C, int p84, const char *str,
                   float f15, float f16, float f17,
                   int p88, int p8C, int p90, int pA8);
void func_0013CB70(void *item, int val);
void func_0013CB60(void *item, int val);
void func_0013CB80(void *item, int val);
void func_0013C8D0(void *item, int val);
void func_0013C880(void *item, int val);
void func_0013C8A0(void *item, float val);
void func_0013C8B0(void *item, float val);
void func_0013C8C0(void *item, float val);
void func_0013CBF0(void *item, int val);
void func_0013CC10(void *item, int val);
void func_0013CC30(void *item, int val);
void func_0013CC50(void *item, int val);
void* func_0013DAC0(void *self, int type);
}

struct BuildAIItem {
    void *m_vtable;
    char m_pad4[0xA8];
    int m_fieldAC;
    BuildAIItem *m_prev;
    BuildAIItem *m_next;
};

struct BuildAI {
    void *m_vtable;
    char pad_00[0x11C];
    BuildAIItem *m_buildItemPrev;
    char pad_120[0x160 - 0x120];
    int m_field160;

    BuildAIItem *AllocItem(int type);
    int AddItem(void *world, int type, int category,
                int arg5, int arg6, int arg7);
};

asm int BuildAI::AddItem(void *world, int type, int category,
                         int arg5, int arg6, int arg7) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x100
    sq ra, 0xB0(sp)
    sq s7, 0xA0(sp)
    sq s6, 0x90(sp)
    sq s5, 0x80(sp)
    sq s4, 0x70(sp)
    sq s3, 0x60(sp)
    sq s2, 0x50(sp)
    sq s1, 0x40(sp)
    sq s0, 0x30(sp)
    swc1 f21, 0x24(sp)
    addiu v0, zero, 0x6
    paddub s3, a3, zero
    swc1 f20, 0x20(sp)
    paddub s6, a0, zero
    paddub s5, a1, zero
    paddub s4, a2, zero
    paddub s2, t0, zero
    paddub s1, t1, zero
    beq s3, v0, _L0013DBE8
    paddub s7, t2, zero
    lw v0, 0x70(s5)
    sll s0, s4, 2
    addu v0, v0, s0
    lw v0, 0x0(v0)
    beqz v0, _L0013DBC4
    nop
    lui v0, 0x49
    addiu a0, sp, 0xC0
    jal func_0011ABBC
    addiu a1, v0, 0x0D50
    lw v1, 0x70(s5)
    lui v0, (0x40000000 >> 16)
    mtc1 v0, f2
    addu v0, v1, s0
    lw v0, 0x0(v0)
    lwc1 f1, 0x20(v0)
    lwc1 f0, 0x24(v0)
    mul.s f20, f2, f1
    b _L0013DC0C
    mul.s f21, f2, f0
_L0013DBC4:
    lui v0, 0x49
    addiu a0, sp, 0xC0
    addiu a1, v0, 0x0D60
    jal func_0011B170
    addiu a2, zero, 0x3F
    lui v0, (0x40400000 >> 16)
    mtc1 v0, f20
    b _L0013DC0C
    mov.s f21, f20
_L0013DBE8:
    lui v0, 0x49
    addiu a0, sp, 0xC0
    addiu a1, v0, 0x0D80
    jal func_0011B170
    addiu a2, zero, 0x3F
    lui v0, (0x40400000 >> 16)
    mtc1 v0, f20
    nop
    mov.s f21, f20
_L0013DC0C:
    paddub a0, s6, zero
    jal func_0013DAC0
    paddub a1, s4, zero
    paddub s0, v0, zero
    bnez s0, _L0013DC2C
    addiu v0, zero, -0x1
    b _L0013DD40
    paddub v0, zero, zero
_L0013DC2C:
    addiu v0, zero, -0x1
_L0013DC30:
    mov.s f12, f20
    sd v0, 0x0(sp)
    sd v0, 0x8(sp)
    sd v0, 0x10(sp)
    sd zero, 0x18(sp)
    lw a3, 0x160(s6)
    lui v0, (0x3F800000 >> 16)
    mtc1 v0, f14
    addiu t0, zero, 0x1
    mov.s f13, f21
    addiu t3, sp, 0xC0
    paddub a1, s3, zero
    paddub a2, s4, zero
    paddub t2, s2, zero
    paddub a0, s0, zero
    jal func_0013C960
    paddub t1, zero, zero
    paddub a0, s0, zero
    jal func_0013CB70
    paddub a1, zero, zero
    paddub a0, s0, zero
    jal func_0013CB60
    paddub a1, zero, zero
    paddub a0, s0, zero
    jal func_0013CB80
    paddub a1, zero, zero
    paddub a0, s0, zero
    jal func_0013C8D0
    paddub a1, zero, zero
    addiu a1, zero, -1
    jal func_0013C880
    paddub a0, s0, zero
    lui v0, (0xBF800000 >> 16)
    mtc1 v0, f12
    jal func_0013C8A0
    paddub a0, s0, zero
    lui v0, (0xBF800000 >> 16)
    mtc1 v0, f12
    jal func_0013C8B0
    paddub a0, s0, zero
    lui v0, (0xBF800000 >> 16)
    mtc1 v0, f12
    jal func_0013C8C0
    paddub a0, s0, zero
    paddub a0, s0, zero
    jal func_0013CBF0
    paddub a1, zero, zero
    paddub a1, s1, zero
    jal func_0013CC10
    paddub a0, s0, zero
    paddub a0, s0, zero
    jal func_0013CC30
    paddub a1, zero, zero
    paddub a0, s0, zero
    jal func_0013CC50
    paddub a1, zero, zero
    sw s7, 0xAC(s0)
    lw a0, 0x11C(s6)
    addiu v0, zero, 0x1
    sw a0, 0x70(s0)
    lw v1, 0x6C(a0)
    sw v1, 0x6C(s0)
    lw v1, 0x6C(s0)
    sw s0, 0x70(v1)
    sw s0, 0x6C(a0)
    lw v1, 0x160(s6)
    addiu v1, v1, 0x1
    sw v1, 0x160(s6)
_L0013DD40:
    lq ra, 0xB0(sp)
    lq s7, 0xA0(sp)
    lq s6, 0x90(sp)
    lq s5, 0x80(sp)
    lq s4, 0x70(sp)
    lq s3, 0x60(sp)
    lq s2, 0x50(sp)
    lq s1, 0x40(sp)
    lq s0, 0x30(sp)
    lwc1 f21, 0x24(sp)
    lwc1 f20, 0x20(sp)
    jr ra
    addiu sp, sp, 0x100
    .set reorder
    .set at
}
