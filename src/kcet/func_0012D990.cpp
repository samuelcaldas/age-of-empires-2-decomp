/* Function: func_0012D990 (0x0012D990 - 0x0012D9FC)
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
asm s32 func_0012D990(void) {
    .word 0x27bdfff0 // 0012D990:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012D994:  sd $ra, ($sp)
    .word 0x0c043a88 // 0012D998:  jal 0x10ea20
    .word 0x24040001 // 0012D99C:  addiu $a0, $zero, 1
    .word 0x0040182d // 0012D9A0:  move $v1, $v0
    .word 0x838284f3 // 0012D9A4:  lb $v0, -0x7b0d($gp)
    .word 0x1440000a // 0012D9A8:  bnez $v0, 0x12d9d4
    .word 0xaf838854 // 0012D9AC:  sw $v1, -0x77ac($gp)
    .word 0x838284f4 // 0012D9B0:  lb $v0, -0x7b0c($gp)
    .word 0x54400008 // 0012D9B4:  bnel $v0, $zero, 0x12d9d8
    .word 0x8f838854 // 0012D9B8:  lw $v1, -0x77ac($gp)
    .word 0x838284f5 // 0012D9BC:  lb $v0, -0x7b0b($gp)
    .word 0x54400005 // 0012D9C0:  bnel $v0, $zero, 0x12d9d8
    .word 0x8f838854 // 0012D9C4:  lw $v1, -0x77ac($gp)
    .word 0x838284f6 // 0012D9C8:  lb $v0, -0x7b0a($gp)
    .word 0x10400008 // 0012D9CC:  beqz $v0, 0x12d9f0
    .word 0xdfbf0000 // 0012D9D0:  ld $ra, ($sp)
    .word 0x8f838854 // 0012D9D4:  lw $v1, -0x77ac($gp)
    .word 0x14600005 // 0012D9D8:  bnez $v1, 0x12d9f0
    .word 0xdfbf0000 // 0012D9DC:  ld $ra, ($sp)
    .word 0xa38084f6 // 0012D9E0:  sb $zero, -0x7b0a($gp)
    .word 0xa38084f5 // 0012D9E4:  sb $zero, -0x7b0b($gp)
    .word 0xa38084f4 // 0012D9E8:  sb $zero, -0x7b0c($gp)
    .word 0xa38084f3 // 0012D9EC:  sb $zero, -0x7b0d($gp)
    .word 0x0060102d // 0012D9F0:  move $v0, $v1
    .word 0x03e00008 // 0012D9F4:  jr $ra
    .word 0x27bd0010 // 0012D9F8:  addiu $sp, $sp, 0x10
}
#else

extern s32 D_004F3014;
extern s8 D_004F2CB3;
extern s8 D_004F2CB4;
extern s8 D_004F2CB5;
extern s8 D_004F2CB6;

s32 func_0010EA20(s32);

s32 func_0012D990(void) {
    s32 ret = func_0010EA20(1);
    if (!D_004F2CB3) {
        D_004F3014 = ret;
        if (!D_004F2CB4 && !D_004F2CB5 && !D_004F2CB6) {
            return ret;
        }
    }
    if (ret != 0) {
        return ret;
    }
    D_004F2CB6 = 0;
    D_004F2CB5 = 0;
    D_004F2CB4 = 0;
    D_004F2CB3 = 0;
    return 0;
}

#endif

}
