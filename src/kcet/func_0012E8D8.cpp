#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012E8D8(void) {
    .word 0x27bdffc0 // 0012E8D8:  addiu $sp, $sp, -0x40
    .word 0xffb20020 // 0012E8DC:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012E8E0:  sd $s1, 0x10($sp)
    .word 0x00c0902d // 0012E8E4:  move $s2, $a2
    .word 0xffb00000 // 0012E8E8:  sd $s0, ($sp)
    .word 0x00e0882d // 0012E8EC:  move $s1, $a3
    .word 0x0080802d // 0012E8F0:  move $s0, $a0
    .word 0x12000005 // 0012E8F4:  beqz $s0, 0x12e90c
    .word 0xffbf0030 // 0012E8F8:  sd $ra, 0x30($sp)
    .word 0x0c046aef // 0012E8FC:  jal 0x11abbc
    .word 0x00000000 // 0012E900:  nop 
    .word 0xae11001c // 0012E904:  sw $s1, 0x1c($s0)
    .word 0xae120018 // 0012E908:  sw $s2, 0x18($s0)
    .word 0xdfbf0030 // 0012E90C:  ld $ra, 0x30($sp)
    .word 0xdfb20020 // 0012E910:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012E914:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012E918:  ld $s0, ($sp)
    .word 0x03e00008 // 0012E91C:  jr $ra
    .word 0x27bd0040 // 0012E920:  addiu $sp, $sp, 0x40
}
#else

char *strcpy(char *dest, const char *src);

struct TargetStruct {
    char name[24];
    s32 field_18;
    s32 field_1C;
};

void func_0012E8D8(TargetStruct *s, const char *name, s32 f18, s32 f1C) {
    if (s != 0) {
        strcpy(s->name, name);
        s->field_1C = f1C;
        s->field_18 = f18;
    }
}

#endif

}
