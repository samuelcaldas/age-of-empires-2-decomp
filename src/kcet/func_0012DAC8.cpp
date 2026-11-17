/* Function: func_0012DAC8 (0x0012DAC8 - 0x0012DB04)
 * Origin: SLES-50282, KCET kt_file module
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
asm s32 func_0012DAC8(void) {
    .word 0x27bdfff0 // 0012DAC8:  addiu $sp, $sp, -0x10
    .word 0x838284f4 // 0012DACC:  lb $v0, -0x7b0c($gp)
    .word 0xffbf0000 // 0012DAD0:  sd $ra, ($sp)
    .word 0x14400007 // 0012DAD4:  bnez $v0, 0x12daf4
    .word 0xaf808864 // 0012DAD8:  sw $zero, -0x779c($gp)
    .word 0x0c043e82 // 0012DADC:  jal 0x10fa08
    .word 0x00000000 // 0012DAE0:  nop 
    .word 0x10400003 // 0012DAE4:  beqz $v0, 0x12daf4
    .word 0xaf828864 // 0012DAE8:  sw $v0, -0x779c($gp)
    .word 0x24020001 // 0012DAEC:  addiu $v0, $zero, 1
    .word 0xa38284f4 // 0012DAF0:  sb $v0, -0x7b0c($gp)
    .word 0x8f828864 // 0012DAF4:  lw $v0, -0x779c($gp)
    .word 0xdfbf0000 // 0012DAF8:  ld $ra, ($sp)
    .word 0x03e00008 // 0012DAFC:  jr $ra
    .word 0x27bd0010 // 0012DB00:  addiu $sp, $sp, 0x10
}
#else

extern s8 D_004F2CB4;
extern s32 D_004F3024;

s32 func_0010FA08(void);

s32 func_0012DAC8(void) {
    if (D_004F2CB4 == 0) {
        D_004F3024 = 0;
        s32 ret = func_0010FA08();
        if (ret != 0) {
            D_004F3024 = ret;
            D_004F2CB4 = 1;
        }
    }
    return D_004F3024;
}

#endif

}
