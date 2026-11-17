/* Function: func_0012DC20 (0x0012DC20 - 0x0012DC5C)
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
asm s32 func_0012DC20(void) {
    .word 0x27bdfff0 // 0012DC20:  addiu $sp, $sp, -0x10
    .word 0x838284f6 // 0012DC24:  lb $v0, -0x7b0a($gp)
    .word 0xffbf0000 // 0012DC28:  sd $ra, ($sp)
    .word 0x14400007 // 0012DC2C:  bnez $v0, 0x12dc4c
    .word 0xaf808870 // 0012DC30:  sw $zero, -0x7790($gp)
    .word 0x0c043df6 // 0012DC34:  jal 0x10f7d8
    .word 0x00000000 // 0012DC38:  nop 
    .word 0x10400003 // 0012DC3C:  beqz $v0, 0x12dc4c
    .word 0xaf828870 // 0012DC40:  sw $v0, -0x7790($gp)
    .word 0x24020001 // 0012DC44:  addiu $v0, $zero, 1
    .word 0xa38284f6 // 0012DC48:  sb $v0, -0x7b0a($gp)
    .word 0x8f828870 // 0012DC4C:  lw $v0, -0x7790($gp)
    .word 0xdfbf0000 // 0012DC50:  ld $ra, ($sp)
    .word 0x03e00008 // 0012DC54:  jr $ra
    .word 0x27bd0010 // 0012DC58:  addiu $sp, $sp, 0x10
}
#else

extern s8 D_004F2CB6;
extern s32 D_004F3030;

s32 func_0010F7D8(void);

s32 func_0012DC20(void) {
    if (D_004F2CB6 == 0) {
        D_004F3030 = 0;
        s32 ret = func_0010F7D8();
        if (ret != 0) {
            D_004F3030 = ret;
            D_004F2CB6 = 1;
        }
    }
    return D_004F3030;
}

#endif

}
