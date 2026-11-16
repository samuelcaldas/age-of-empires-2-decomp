/* Function: func_0012AB68 (0x0012AB68 - 0x0012AC74)
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
asm void func_0012AB68(void) {
    .word 0x27bdffa0 // addiu $sp, $sp, -0x60
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0x2454d334 // addiu $s4, $v0, -0x2ccc
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x3c130049 // lui $s3, 0x49
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x3c12004e // lui $s2, 0x4e
    .word 0xffbf0050 // sd $ra, 0x50($sp)
    .word 0x0000882d // move $s1, $zero
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0x00000000 // nop
    .word 0x0000282d // move $a1, $zero
    .word 0x0c04d084 // jal 0x134210
    .word 0x0000302d // move $a2, $zero
    .word 0x0040802d // move $s0, $v0
    .word 0x06010006 // bgez $s0, 0x12abcc
    .word 0x00111080 // sll $v0, $s1, 2
    .word 0x2664f500 // addiu $a0, $s3, -0xb00
    .word 0x24050782 // addiu $a1, $zero, 0x782
    .word 0x0c0450c8 // jal 0x114320
    .word 0x26462c68 // addiu $a2, $s2, 0x2c68
    .word 0x00111080 // sll $v0, $s1, 2
    .word 0x00541021 // addu $v0, $v0, $s4
    .word 0x26310001 // addiu $s1, $s1, 1
    .word 0xac500000 // sw $s0, ($v0)
    .word 0x0c04135c // jal 0x104d70
    .word 0x0200202d // move $a0, $s0
    .word 0x1050fffd // beq $v0, $s0, 0x12abd8
    .word 0x2e220002 // sltiu $v0, $s1, 2
    .word 0x1440ffed // bnez $v0, 0x12aba0
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0x3c050013 // lui $a1, 0x13
    .word 0x24040003 // addiu $a0, $zero, 3
    .word 0x24a5ab28 // addiu $a1, $a1, -0x54d8
    .word 0x0c041280 // jal 0x104a00
    .word 0x2406ffff // addiu $a2, $zero, -1
    .word 0x0040802d // move $s0, $v0
    .word 0x06010006 // bgez $s0, 0x12ac24
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c06004e // lui $a2, 0x4e
    .word 0x2484f500 // addiu $a0, $a0, -0xb00
    .word 0x24c62c68 // addiu $a2, $a2, 0x2c68
    .word 0x0c0450c8 // jal 0x114320
    .word 0x2405078e // addiu $a1, $zero, 0x78e
    .word 0x0c04d050 // jal 0x134140
    .word 0x00000000 // nop
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x2442ffff // addiu $v0, $v0, -1
    .word 0x2463d300 // addiu $v1, $v1, -0x2d00
    .word 0x24040003 // addiu $a0, $zero, 3
    .word 0xac700040 // sw $s0, 0x40($v1)
    .word 0xac62003c // sw $v0, 0x3c($v1)
    .word 0x0c0415ec // jal 0x1057b0
    .word 0x00000000 // nop
    .word 0x00101027 // nor $v0, $zero, $s0
    .word 0xdfbf0050 // ld $ra, 0x50($sp)
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0x0002102b // sltu $v0, $zero, $v0
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0060 // addiu $sp, $sp, 0x60
}
#else

extern s32 D_004ED334[];
extern char D_0048F500[];
extern char D_004E2C68[];

struct CdvdServerData {
    u8 pad[0x3c];
    s32 f_3c;
    s32 f_40;
};
extern CdvdServerData D_004ED300;

s32 func_134210(s32, s32, s32);
void func_114320(const char *, s32, const char *);
s32 func_104D70(s32);
s32 func_104A00(s32, void *, s32);
s32 func_134140(void);
void func_1057B0(s32);
void func_0012AB28(void);

u32 func_0012AB68(void) {
    u32 i = 0;
    s32 s0;

    do {
        s0 = func_134210(1, 0, 0);
        if (s0 < 0) {
            func_114320(D_0048F500, 0x782, D_004E2C68);
        }
        D_004ED334[i] = s0;
        i++;
        while (func_104D70(s0) == s0) {}
    } while (i < 2);

    s0 = func_104A00(3, (void *)func_0012AB28, -1);
    if (s0 < 0) {
        func_114320(D_0048F500, 0x78E, D_004E2C68);
    }
    D_004ED300.f_3c = func_134140() - 1;
    D_004ED300.f_40 = s0;
    func_1057B0(3);
    return ~s0 > 0;
}

#endif

}
