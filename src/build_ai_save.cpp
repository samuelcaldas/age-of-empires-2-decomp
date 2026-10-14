
#include "sub_list.h"
extern "C" {
void func_00226F70(void*, void*, int);
char* func_0011ABBC(char*, const char*);
int func_0011ACD0(const char*);
int func_0013C7C0(void*);
int func_0013C7D0(void*);
int func_0013C7E0(void*);
char* func_0013C7F0(void*);
float func_0013C800(void*);
float func_0013C810(void*);
float func_0013C820(void*);
float func_0013C830(void*);
float func_0013C840(void*);
float func_0013C850(void*);
int func_0013C860(void*);
int func_0013CAB0(void*);
int func_0013CAC0(void*);
int func_0013CAD0(void*);
int func_0013CAE0(void*);
int func_0013CAF0(void*);
int func_0013CB00(void*);
int func_0013CB10(void*, int);
int func_0013CB50(void*);
int func_0013CBD0(void*);
int func_0013CC00(void*);
int func_0013CC20(void*);
unsigned char func_0013CC40(void*);
}
struct BuildAIBuffer { void *m_data; int m_size, m_cap, m_flags; };
struct BuildAI {
    void *m_vtable; char m_pad4[0xA8]; char m_buildItem[0xB4]; int m_field160;
    char m_buf1[257]; char m_buf2[257]; char m_buf3[257]; char m_buf4[257];
    int m_field568; BuildAIBuffer m_buffer; char m_items[50 * 0xB4];
    int Save(void *stream);
};
asm int BuildAI::Save(void *stream) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x160
    sq ra, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    paddub s1, a0, zero
    paddub s0, a1, zero
    addiu a1, s1, 0x160
    addiu a2, zero, 0x4
    jal func_00226F70
    paddub a0, s0, zero
    addiu a0, sp, 0x40
    jal func_0011ABBC
    addiu a1, s1, 0x164
    jal func_0011ACD0
    addiu a0, sp, 0x40
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0011ACD0
    addiu a0, sp, 0x40
    addiu a1, sp, 0x40
    paddub a2, v0, zero
    jal func_00226F70
    paddub a0, s0, zero
    addiu a0, sp, 0x40
    jal func_0011ABBC
    addiu a1, s1, 0x265
    jal func_0011ACD0
    addiu a0, sp, 0x40
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0011ACD0
    addiu a0, sp, 0x40
    addiu a1, sp, 0x40
    paddub a2, v0, zero
    jal func_00226F70
    paddub a0, s0, zero
    addiu a0, sp, 0x40
    jal func_0011ABBC
    addiu a1, s1, 0x366
    jal func_0011ACD0
    addiu a0, sp, 0x40
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0011ACD0
    addiu a0, sp, 0x40
    addiu a1, sp, 0x40
    paddub a2, v0, zero
    jal func_00226F70
    paddub a0, s0, zero
    addiu a0, sp, 0x40
    jal func_0011ABBC
    addiu a1, s1, 0x467
    jal func_0011ACD0
    addiu a0, sp, 0x40
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0011ACD0
    addiu a0, sp, 0x40
    addiu a1, sp, 0x40
    paddub a2, v0, zero
    jal func_00226F70
    paddub a0, s0, zero
    addiu a1, s1, 0x568
    addiu a2, zero, 0x4
    jal func_00226F70
    paddub a0, s0, zero
    lw a0, 0x118(s1)
    addiu v0, s1, 0xAC
    b _L0013D4D0
    sw zero, 0x150(sp)
    _L0013D4BC:
    lw v1, 0x150(sp)
    addiu v1, v1, 0x1
    sw v1, 0x150(sp)
    lw a0, 0x6C(a0)
    nop
    _L0013D4D0:
    bne a0, v0, _L0013D4BC
    nop
    addiu a1, sp, 0x150
    addiu a2, zero, 0x4
    jal func_00226F70
    paddub a0, s0, zero
    b _L0013D7E4
    lw s2, 0x118(s1)
    _L0013D4F0:
    jal func_0013C7F0
    paddub a0, s2, zero
    addiu a0, sp, 0x40
    jal func_0011ABBC
    paddub a1, v0, zero
    jal func_0011ACD0
    addiu a0, sp, 0x40
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0011ACD0
    addiu a0, sp, 0x40
    addiu a1, sp, 0x40
    paddub a2, v0, zero
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013C7C0
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013C7D0
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013C7E0
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013C800
    paddub a0, s2, zero
    addiu a1, sp, 0x154
    addiu a2, zero, 0x4
    swc1 f0, 0x154(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013C810
    paddub a0, s2, zero
    addiu a1, sp, 0x154
    addiu a2, zero, 0x4
    swc1 f0, 0x154(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013C820
    paddub a0, s2, zero
    addiu a1, sp, 0x154
    addiu a2, zero, 0x4
    swc1 f0, 0x154(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013C830
    paddub a0, s2, zero
    addiu a1, sp, 0x154
    addiu a2, zero, 0x4
    swc1 f0, 0x154(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013C840
    paddub a0, s2, zero
    addiu a1, sp, 0x154
    addiu a2, zero, 0x4
    swc1 f0, 0x154(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013C850
    paddub a0, s2, zero
    addiu a1, sp, 0x154
    addiu a2, zero, 0x4
    swc1 f0, 0x154(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013C860
    paddub a0, s2, zero
    addiu a1, sp, 0x158
    addiu a2, zero, 0x4
    sw v0, 0x158(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CAB0
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CAC0
    paddub a0, s2, zero
    addiu a1, sp, 0x158
    addiu a2, zero, 0x4
    sw v0, 0x158(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CAD0
    paddub a0, s2, zero
    addiu a1, sp, 0x158
    addiu a2, zero, 0x4
    sw v0, 0x158(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CAE0
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CAF0
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CB00
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    addiu a1, zero, 0x1
    jal func_0013CB10
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    addiu a1, zero, 0x2
    jal func_0013CB10
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CB50
    paddub a0, s2, zero
    addiu a1, sp, 0x158
    addiu a2, zero, 0x4
    sw v0, 0x158(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CBD0
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CC00
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CC20
    paddub a0, s2, zero
    addiu a1, sp, 0x14C
    addiu a2, zero, 0x4
    sw v0, 0x14C(sp)
    jal func_00226F70
    paddub a0, s0, zero
    jal func_0013CC40
    paddub a0, s2, zero
    addiu a1, sp, 0x15F
    addiu a2, zero, 0x1
    sb v0, 0x15F(sp)
    jal func_00226F70
    paddub a0, s0, zero
    lw v0, 0xAC(s2)
    addiu a1, sp, 0x158
    addiu a2, zero, 0x4
    paddub a0, s0, zero
    jal func_00226F70
    sw v0, 0x158(sp)
    lw s2, 0x6C(s2)
    nop
    _L0013D7E4:
    addiu v0, s1, 0xAC
    beq s2, v0, _L0013D7F8
    nop
    bnez s2, _L0013D4F0
    nop
    _L0013D7F8:
    lq ra, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    addiu v0, zero, 0x1
    jr ra
    addiu sp, sp, 0x160
    .set reorder
    .set at
}
