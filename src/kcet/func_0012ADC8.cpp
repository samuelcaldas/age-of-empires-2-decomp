/* Function: func_0012ADC8 (0x0012ADC8 - 0x0012AE60)
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
asm void func_0012ADC8(void) {
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0x3c04004f // lui $a0, 0x4f
    .word 0xffbf0000 // sd $ra, ($sp)
    .word 0x24050070 // addiu $a1, $zero, 0x70
    .word 0x0c0450f0 // jal 0x1143c0
    .word 0x2484d370 // addiu $a0, $a0, -0x2c90
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0xdfbf0000 // ld $ra, ($sp)
    .word 0x8c44d354 // lw $a0, -0x2cac($v0)
    .word 0x0804d110 // j 0x134440
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
    .word 0x00000000 // nop
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0x3c04004f // lui $a0, 0x4f
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x24050070 // addiu $a1, $zero, 0x70
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x0c0450f0 // jal 0x1143c0
    .word 0x2484d370 // addiu $a0, $a0, -0x2c90
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0x24050001 // addiu $a1, $zero, 1
    .word 0x0c04d084 // jal 0x134210
    .word 0x0000302d // move $a2, $zero
    .word 0x0040802d // move $s0, $v0
    .word 0x06010008 // bgez $s0, 0x12ae4c
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c060049 // lui $a2, 0x49
    .word 0x2484f500 // addiu $a0, $a0, -0xb00
    .word 0x24c6fbf8 // addiu $a2, $a2, -0x408
    .word 0x0c0450c8 // jal 0x114320
    .word 0x2405081d // addiu $a1, $zero, 0x81d
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xac50d354 // sw $s0, -0x2cac($v0)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
}
#else

extern s32 D_004ED354;
extern u8 D_004ED370[];
extern const char D_0048F500[];
extern const char D_0048FBF8[];

void func_001143C0(void *, s32);
void func_00134440(s32);
s32 func_134210(s32, s32, s32);
void func_114320(const char *, s32, const char *);

void func_0012ADC8(void) {
    func_001143C0(D_004ED370, 0x70);
    func_00134440(D_004ED354);
}

void func_0012ADF8(void) {
    func_001143C0(D_004ED370, 0x70);
    s32 s0 = func_134210(1, 1, 0);
    if (s0 < 0) {
        func_114320(D_0048F500, 0x81D, D_0048FBF8);
    }
    D_004ED354 = s0;
}

#endif

}
