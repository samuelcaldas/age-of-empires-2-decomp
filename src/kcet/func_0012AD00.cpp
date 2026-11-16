/* Function: func_0012AD00 (0x0012AD00 - 0x0012AD58)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012AD00(void) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x0000282d // move $a1, $zero
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x0c04d084 // jal 0x134210
    .word 0x0000302d // move $a2, $zero
    .word 0x0040802d // move $s0, $v0
    .word 0x06010008 // bgez $s0, 0x12ad44
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c060049 // lui $a2, 0x49
    .word 0x2484f500 // addiu $a0, $a0, -0xb00
    .word 0x24c6fbf8 // addiu $a2, $a2, -0x408
    .word 0x0c0450c8 // jal 0x114320
    .word 0x240507f8 // addiu $a1, $zero, 0x7f8
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xac50d344 // sw $s0, -0x2cbc($v0)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
}
#else

extern s32 D_004ED344;
extern const char D_0048F500[];
extern const char D_0048FBF8[];

s32 func_134210(s32, s32, s32);
void func_114320(const char *, s32, const char *);

void func_0012AD00(void) {
    s32 s0 = func_134210(1, 0, 0);
    if (s0 < 0) {
        func_114320(D_0048F500, 0x7F8, D_0048FBF8);
    }
    D_004ED344 = s0;
}

#endif

}
