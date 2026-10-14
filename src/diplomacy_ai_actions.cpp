
#include "sub_list.h"

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    char m_field100[10];
};

extern "C" {

int func_140280(void*, int);
int func_140220(void*, int);
void* func_318280(void*);
int func_1401C0(void*, int);

asm int func_13FEF0(DiplomacyAI *self, int a1, int a2, int a3, int t0) {
    .word 0x27BDFF60
    .word 0x7FBF0090
    .word 0x7FBE0080
    .word 0x7FB70070
    .word 0x7FB60060
    .word 0x7FB50050
    .word 0x7FB40040
    .word 0x7FB30030
    .word 0x7FB20020
    .word 0x7FB10010
    .word 0x7FB00000
    .word 0x2410FFFF
    .word 0x24120001
    .word 0x7080BE28
    .word 0x70A0B628
    .word 0x70C0AE28
    .word 0x70E0F628
    .word 0x7100A628
    .word 0x10000049
    .word 0x72008E28
    .word 0x8C620BA0
    .word 0x52420046
    .word 0x26520001
    .word 0x8C830054
    .word 0x00129880
    .word 0x24020002
    .word 0x00731821
    .word 0x8C630000
    .word 0x90630BA6
    .word 0x1062003D
    .word 0x00000000
    .word 0x1AC00009
    .word 0x72E02628
    .word 0x16B20006
    .word 0x00000000
    .word 0x72E02628
    .word 0x0C0500A0
    .word 0x72402E28
    .word 0x14400034
    .word 0x00000000
    .word 0x72E02628
    .word 0x0C0500A0
    .word 0x72402E28
    .word 0x24030001
    .word 0x1043002E
    .word 0x00000000
    .word 0x72E02628
    .word 0x0C050088
    .word 0x72402E28
    .word 0x24030001
    .word 0x10430028
    .word 0x00000000
    .word 0x8EE400AC
    .word 0x8C990000
    .word 0x8F390060
    .word 0x0320F809
    .word 0x72402E28
    .word 0x10400021
    .word 0x00000000
    .word 0x8EE200AC
    .word 0x8C4200AC
    .word 0x8C420B98
    .word 0x8C420054
    .word 0x00531021
    .word 0x8C420000
    .word 0x0C0C60A0
    .word 0x8C440B90
    .word 0x02F31821
    .word 0x2A810002
    .word 0x14200010
    .word 0x8C6400B0
    .word 0x24030001
    .word 0x57C30008
    .word 0x0054001A
    .word 0x16800002
    .word 0x0054001A
    .word 0x000001CD
    .word 0x00001012
    .word 0x10000007
    .word 0x00822021
    .word 0x0054001A
    .word 0x16800002
    .word 0x00000000
    .word 0x000001CD
    .word 0x00001012
    .word 0x00822023
    .word 0x0224082A
    .word 0x10200003
    .word 0x00000000
    .word 0x70808E28
    .word 0x72408628
    .word 0x26520001
    .word 0x8EE200AC
    .word 0x8C4300AC
    .word 0x8C640B98
    .word 0x84820050
    .word 0x0242102A
    .word 0x1440FFB2
    .word 0x00000000
    .word 0x72001628
    .word 0x7BBF0090
    .word 0x7BBE0080
    .word 0x7BB70070
    .word 0x7BB60060
    .word 0x7BB50050
    .word 0x7BB40040
    .word 0x7BB30030
    .word 0x7BB20020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD00A0
}

int func_001400B0() {
    return 0;
}

asm int func_001400C0(DiplomacyAI *self, int a1, int a2) {
    .set noreorder
    .set noat
    addiu sp, sp, -0x80
    sq ra, 0x70(sp)
    sq s6, 0x60(sp)
    sq s5, 0x50(sp)
    sq s4, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    sq s0, 0x0(sp)
    addiu s0, zero, -0x1
    addiu s2, zero, 0x1
    paddub s6, a0, zero
    paddub s5, a1, zero
    paddub s4, a2, zero
    b _L00140170
    paddub s1, s0, zero
    _L00140100:
    lw v0, 0xBA0(v1)
    beql s2, v0, _L00140170
    addiu s2, s2, 0x1
    lw v1, 0x54(a0)
    sll s3, s2, 2
    addiu v0, zero, 0x2
    addu v1, v1, s3
    lw v1, 0x0(v1)
    lbu v1, 0xBA6(v1)
    beq v1, v0, _L0014016C
    nop
    blez s5, _L00140154
    addu v0, s6, s3
    bne s4, s2, _L00140150
    nop
    paddub a0, s6, zero
    jal func_1401C0
    paddub a1, s2, zero
    bnez v0, _L0014016C
    nop
    _L00140150:
    addu v0, s6, s3
    _L00140154:
    lw v0, 0xD8(v0)
    slt at, s1, v0
    beqz at, _L0014016C
    nop
    paddub s1, v0, zero
    paddub s0, s2, zero
    _L0014016C:
    addiu s2, s2, 0x1
    _L00140170:
    lw v0, 0xAC(s6)
    lw v1, 0xAC(v0)
    lw a0, 0xB98(v1)
    lh v0, 0x50(a0)
    slt v0, s2, v0
    bnez v0, _L00140100
    nop
    paddub v0, s0, zero
    lq ra, 0x70(sp)
    lq s6, 0x60(sp)
    lq s5, 0x50(sp)
    lq s4, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x80
    .set reorder
    .set at
}

}
