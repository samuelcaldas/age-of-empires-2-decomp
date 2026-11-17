#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012E9D8(void) {
    .word 0x27bdffd0 // 0012E9D8:  addiu $sp, $sp, -0x30
    .word 0xffb10010 // 0012E9DC:  sd $s1, 0x10($sp)
    .word 0xffb00000 // 0012E9E0:  sd $s0, ($sp)
    .word 0x0080882d // 0012E9E4:  move $s1, $a0
    .word 0xffbf0020 // 0012E9E8:  sd $ra, 0x20($sp)
    .word 0x12200016 // 0012E9EC:  beqz $s1, 0x12ea48
    .word 0x00a0802d // 0012E9F0:  move $s0, $a1
    .word 0x0c046b34 // 0012E9F4:  jal 0x11acd0
    .word 0x0200202d // 0012E9F8:  move $a0, $s0
    .word 0x2c420018 // 0012E9FC:  sltiu $v0, $v0, 0x18
    .word 0x10400008 // 0012EA00:  beqz $v0, 0x12ea24
    .word 0x3c040049 // 0012EA04:  lui $a0, 0x49
    .word 0x3c050049 // 0012EA08:  lui $a1, 0x49
    .word 0x3c070049 // 0012EA0C:  lui $a3, 0x49
    .word 0x248401c8 // 0012EA10:  addiu $a0, $a0, 0x1c8
    .word 0x24a50068 // 0012EA14:  addiu $a1, $a1, 0x68
    .word 0x24e701f8 // 0012EA18:  addiu $a3, $a3, 0x1f8
    .word 0x0c048de4 // 0012EA1C:  jal 0x123790
    .word 0x240603f8 // 0012EA20:  addiu $a2, $zero, 0x3f8
    .word 0x52000008 // 0012EA24:  beql $s0, $zero, 0x12ea48
    .word 0xa2200000 // 0012EA28:  sb $zero, ($s1)
    .word 0x0220202d // 0012EA2C:  move $a0, $s1
    .word 0x0200282d // 0012EA30:  move $a1, $s0
    .word 0xdfbf0020 // 0012EA34:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012EA38:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012EA3C:  ld $s0, ($sp)
    .word 0x08046aef // 0012EA40:  j 0x11abbc
    .word 0x27bd0030 // 0012EA44:  addiu $sp, $sp, 0x30
    .word 0xdfbf0020 // 0012EA48:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012EA4C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012EA50:  ld $s0, ($sp)
    .word 0x03e00008 // 0012EA54:  jr $ra
    .word 0x27bd0030 // 0012EA58:  addiu $sp, $sp, 0x30
}
#else

extern const char D_4901C8[];
extern const char D_490068[];
extern const char D_4901F8[];

int func_0011ACD0(const char *s);
void func_123790(const char *a0, const char *a1, s32 a2, const char *a3);
char *strcpy(char *dest, const char *src);

void func_0012E9D8(char *dest, const char *src) {
    if (!dest) {
        return;
    }
    if ((u32)func_0011ACD0(src) < 0x18) {
        func_123790(D_4901C8, D_490068, 0x3F8, D_4901F8);
    }
    *dest = '\0';
    if (src != 0) {
        strcpy(dest, src);
    }
}

#endif

}
