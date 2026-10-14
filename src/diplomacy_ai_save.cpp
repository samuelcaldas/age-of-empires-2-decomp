
#include "sub_list.h"

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    char m_field100[10];

    int Save(void *stream);
};

extern "C" {
void func_00226F70(void *stream, void *src, int size);
int func_140280(void *self, int player);
int func_1402E0(void *self, int player);
void func_13FB50(void *self, int player, int a2, int a3);

asm int func_0013F910(DiplomacyAI *self) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x30
    sq ra, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    addiu s0, zero, 0x1
    b _L0013F9B4
    paddub s1, a0, zero
    _L0013F92C:
    lw v0, 0xBA0(v1)
    beql s0, v0, _L0013F9B4
    addiu s0, s0, 0x1
    paddub a0, s1, zero
    jal func_140280
    paddub a1, s0, zero
    beqz v0, _L0013F978
    paddub a0, s1, zero
    paddub a0, s1, zero
    jal func_1402E0
    paddub a1, s0, zero
    bnez v0, _L0013F974
    nop
    addiu a3, zero, 0x1
    paddub a0, s1, zero
    paddub a1, s0, zero
    jal func_13FB50
    paddub a2, zero, zero
    _L0013F974:
    paddub a0, s1, zero
    _L0013F978:
    jal func_140280
    paddub a1, s0, zero
    bnez v0, _L0013F9B0
    nop
    paddub a0, s1, zero
    jal func_1402E0
    paddub a1, s0, zero
    beqz v0, _L0013F9B0
    nop
    addiu a2, zero, 0x2
    addiu a3, zero, 0x1
    paddub a0, s1, zero
    jal func_13FB50
    paddub a1, s0, zero
    _L0013F9B0:
    addiu s0, s0, 0x1
    _L0013F9B4:
    lw v0, 0xAC(s1)
    lw v1, 0xAC(v0)
    lw v0, 0xB98(v1)
    lh v0, 0x50(v0)
    slt v0, s0, v0
    bnez v0, _L0013F92C
    nop
    lq ra, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    addiu v0, zero, 0x1
    jr ra
    addiu sp, sp, 0x30
    .set reorder
    .set at
}

int DiplomacyAI::Save(void *stream) {
    for (int i = 0; i <= 9; i++) {
        func_00226F70(stream, &this->m_fieldB0[i], 4);
        func_00226F70(stream, &this->m_fieldD8[i], 4);
        func_00226F70(stream, &this->m_field100[i], 1);
    }
    return 1;
}

}
