#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012E5D8(void) {
    .word 0x24020003 // 0012E5D8:  addiu $v0, $zero, 3
    .word 0x10a2000e // 0012E5DC:  beq $a1, $v0, 0x12e618
    .word 0x28a20004 // 0012E5E0:  slti $v0, $a1, 4
    .word 0x10400005 // 0012E5E4:  beqz $v0, 0x12e5fc
    .word 0x24020002 // 0012E5E8:  addiu $v0, $zero, 2
    .word 0x10a20008 // 0012E5EC:  beq $a1, $v0, 0x12e610
    .word 0x24840104 // 0012E5F0:  addiu $a0, $a0, 0x104
    .word 0x03e00008 // 0012E5F4:  jr $ra
    .word 0x00000000 // 0012E5F8:  nop
    .word 0x24020004 // 0012E5FC:  addiu $v0, $zero, 4
    .word 0x10a20008 // 0012E600:  beq $a1, $v0, 0x12e624
    .word 0x24840184 // 0012E604:  addiu $a0, $a0, 0x184
    .word 0x03e00008 // 0012E608:  jr $ra
    .word 0x00000000 // 0012E60C:  nop
    .word 0x08046aef // 0012E610:  j 0x11abbc
    .word 0x00c0282d // 0012E614:  move $a1, $a2
    .word 0x24840144 // 0012E618:  addiu $a0, $a0, 0x144
    .word 0x08046aef // 0012E61C:  j 0x11abbc
    .word 0x00c0282d // 0012E620:  move $a1, $a2
    .word 0x08046aef // 0012E624:  j 0x11abbc
    .word 0x00c0282d // 0012E628:  move $a1, $a2
}
#else

char *strcpy(char *dest, const char *src);

void func_0012E5D8(char *dest, int type, const char *src) {
    switch (type) {
    case 2:
        strcpy(dest + 0x104, src);
        break;
    case 3:
        strcpy(dest + 0x144, src);
        break;
    case 4:
        strcpy(dest + 0x184, src);
        break;
    default:
        break;
    }
}

#endif

}
