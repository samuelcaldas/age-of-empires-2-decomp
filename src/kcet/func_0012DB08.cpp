/* Function: func_0012DB08 (0x0012DB08 - 0x0012DB44)
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
asm s32 func_0012DB08(void) {
    .word 0x27bdfff0 // 0012DB08:  addiu $sp, $sp, -0x10
    .word 0x838284f5 // 0012DB0C:  lb $v0, -0x7b0b($gp)
    .word 0xffbf0000 // 0012DB10:  sd $ra, ($sp)
    .word 0x14400007 // 0012DB14:  bnez $v0, 0x12db34
    .word 0xaf808868 // 0012DB18:  sw $zero, -0x7798($gp)
    .word 0x0c043e2a // 0012DB1C:  jal 0x10f8a8
    .word 0x00000000 // 0012DB20:  nop 
    .word 0x10400003 // 0012DB24:  beqz $v0, 0x12db34
    .word 0xaf828868 // 0012DB28:  sw $v0, -0x7798($gp)
    .word 0x24020001 // 0012DB2C:  addiu $v0, $zero, 1
    .word 0xa38284f5 // 0012DB30:  sb $v0, -0x7b0b($gp)
    .word 0x8f828868 // 0012DB34:  lw $v0, -0x7798($gp)
    .word 0xdfbf0000 // 0012DB38:  ld $ra, ($sp)
    .word 0x03e00008 // 0012DB3C:  jr $ra
    .word 0x27bd0010 // 0012DB40:  addiu $sp, $sp, 0x10
}
#else

extern s8 D_004F2CB5;
extern s32 D_004F3028;

s32 func_0010F8A8(void);

s32 func_0012DB08(void) {
    if (D_004F2CB5 == 0) {
        D_004F3028 = 0;
        s32 ret = func_0010F8A8();
        if (ret != 0) {
            D_004F3028 = ret;
            D_004F2CB5 = 1;
        }
    }
    return D_004F3028;
}

#endif

}
