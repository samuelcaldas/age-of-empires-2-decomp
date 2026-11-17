#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012F910(u8 *a0, s32 a1) {
    .word 0x00053203 // sra $a2, $a1, 8
    .word 0x24030007 // addiu $v1, $zero, 7
    .word 0x24820007 // addiu $v0, $a0, 7
    .word 0x00000000 // nop
    .word 0xa0400000 // sb $zero, ($v0)
    .word 0x2463ffff // addiu $v1, $v1, -1
    .word 0x2442ffff // addiu $v0, $v0, -1
    .word 0x00000000 // nop
    .word 0x00000000 // nop
    .word 0x0461fffa // bgez $v1, 0x12f920
    .word 0x00000000 // nop
    .word 0x24030007 // addiu $v1, $zero, 7
    .word 0x2482000f // addiu $v0, $a0, 0xf
    .word 0x00000000 // nop
    .word 0xa0400000 // sb $zero, ($v0)
    .word 0x2463ffff // addiu $v1, $v1, -1
    .word 0x2442ffff // addiu $v0, $v0, -1
    .word 0x00000000 // nop
    .word 0x00000000 // nop
    .word 0x0461fffa // bgez $v1, 0x12f948
    .word 0x00000000 // nop
    .word 0xa0860015 // sb $a2, 0x15($a0)
    .word 0x03e00008 // jr $ra
    .word 0xa0850014 // sb $a1, 0x14($a0)
}
#else
void func_0012F910(u8 *a0, s32 a1) {
    s32 a2 = a1 >> 8;
    for (s32 i = 7; i >= 0; i--) {
        a0[i] = 0;
    }
    for (s32 i = 7; i >= 0; i--) {
        a0[8 + i] = 0;
    }
    a0[0x15] = (u8)a2;
    a0[0x14] = (u8)a1;
}
#endif

}
