/* Function: func_0012DA88 (0x0012DA88 - 0x0012DAC4)
 * Origin: SLES-50282, KCET kt_file module (originally compiled with ee-gcc -O2 -G0)
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
asm s32 func_0012DA88(void) {
    .word 0x27bdfff0 // 0012DA88:  addiu $sp, $sp, -0x10
    .word 0x838284f3 // 0012DA8C:  lb $v0, -0x7b0d($gp)
    .word 0xffbf0000 // 0012DA90:  sd $ra, ($sp)
    .word 0x14400007 // 0012DA94:  bnez $v0, 0x12dab4
    .word 0xaf808860 // 0012DA98:  sw $zero, -0x77a0($gp)
    .word 0x0c043e56 // 0012DA9C:  jal 0x10f958
    .word 0x00000000 // 0012DAA0:  nop 
    .word 0x10400003 // 0012DAA4:  beqz $v0, 0x12dab4
    .word 0xaf828860 // 0012DAA8:  sw $v0, -0x77a0($gp)
    .word 0x24020001 // 0012DAAC:  addiu $v0, $zero, 1
    .word 0xa38284f3 // 0012DAB0:  sb $v0, -0x7b0d($gp)
    .word 0x8f828860 // 0012DAB4:  lw $v0, -0x77a0($gp)
    .word 0xdfbf0000 // 0012DAB8:  ld $ra, ($sp)
    .word 0x03e00008 // 0012DABC:  jr $ra
    .word 0x27bd0010 // 0012DAC0:  addiu $sp, $sp, 0x10
}
#else

extern s8 D_004F2CB3;
extern s32 D_004F3020;

s32 func_0010F958(void);

s32 func_0012DA88(void) {
    if (D_004F2CB3 == 0) {
        D_004F3020 = 0;
        s32 ret = func_0010F958();
        if (ret != 0) {
            D_004F3020 = ret;
            D_004F2CB3 = 1;
        }
    }
    return D_004F3020;
}

#endif

}
