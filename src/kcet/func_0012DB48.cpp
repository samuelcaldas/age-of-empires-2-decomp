/* Function: func_0012DB48 (0x0012DB48 - 0x0012DB80)
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
asm s32 func_0012DB48(void) {
    .word 0x27bdfff0 // 0012DB48:  addiu $sp, $sp, -0x10
    .word 0x8f8284ec // 0012DB4C:  lw $v0, -0x7b14($gp)
    .word 0x10400007 // 0012DB50:  beqz $v0, 0x12db70
    .word 0xffbf0000 // 0012DB54:  sd $ra, ($sp)
    .word 0x0c043f28 // 0012DB58:  jal 0x10fca0
    .word 0x00000000 // 0012DB5C:  nop 
    .word 0x10400003 // 0012DB60:  beqz $v0, 0x12db70
    .word 0xaf82886c // 0012DB64:  sw $v0, -0x7794($gp)
    .word 0x24020001 // 0012DB68:  addiu $v0, $zero, 1
    .word 0xa38284f2 // 0012DB6C:  sb $v0, -0x7b0e($gp)
    .word 0x8f82886c // 0012DB70:  lw $v0, -0x7794($gp)
    .word 0xdfbf0000 // 0012DB74:  ld $ra, ($sp)
    .word 0x03e00008 // 0012DB78:  jr $ra
    .word 0x27bd0010 // 0012DB7C:  addiu $sp, $sp, 0x10
}
#else

extern s32 D_004F2CAC;
extern s32 D_004F302C;
extern s8 D_004F2CB2;

s32 func_0010FCA0(void);

s32 func_0012DB48(void) {
    if (D_004F2CAC != 0) {
        s32 ret = func_0010FCA0();
        if (ret != 0) {
            D_004F302C = ret;
            D_004F2CB2 = 1;
        }
    }
    return D_004F302C;
}

#endif

}
