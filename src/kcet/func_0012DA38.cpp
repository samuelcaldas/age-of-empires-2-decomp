/* Function: func_0012DA38 (0x0012DA38 - 0x0012DA84)
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
asm s32 func_0012DA38(void) {
    .word 0x27bdfff0 // 0012DA38:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012DA3C:  sd $ra, ($sp)
    .word 0x0c043efa // 0012DA40:  jal 0x10fbe8
    .word 0x00000000 // 0012DA44:  nop 
    .word 0x0040182d // 0012DA48:  move $v1, $v0
    .word 0x8f8284ec // 0012DA4C:  lw $v0, -0x7b14($gp)
    .word 0x10400008 // 0012DA50:  beqz $v0, 0x12da74
    .word 0xaf83885c // 0012DA54:  sw $v1, -0x77a4($gp)
    .word 0x2402ffff // 0012DA58:  addiu $v0, $zero, -1
    .word 0x10620005 // 0012DA5C:  beq $v1, $v0, 0x12da74
    .word 0x30620006 // 0012DA60:  andi $v0, $v1, 6
    .word 0x14400004 // 0012DA64:  bnez $v0, 0x12da78
    .word 0x8f82885c // 0012DA68:  lw $v0, -0x77a4($gp)
    .word 0x34620006 // 0012DA6C:  ori $v0, $v1, 6
    .word 0xaf82885c // 0012DA70:  sw $v0, -0x77a4($gp)
    .word 0x8f82885c // 0012DA74:  lw $v0, -0x77a4($gp)
    .word 0xdfbf0000 // 0012DA78:  ld $ra, ($sp)
    .word 0x03e00008 // 0012DA7C:  jr $ra
    .word 0x27bd0010 // 0012DA80:  addiu $sp, $sp, 0x10
}
#else

extern s32 D_004F2CAC;
extern s32 D_004F301C;

s32 func_0010FBE8(void);

s32 func_0012DA38(void) {
    s32 res = func_0010FBE8();
    if (D_004F2CAC != 0) {
        D_004F301C = res;
        if (res != -1) {
            if ((res & 6) == 0) {
                D_004F301C = res | 6;
                return D_004F301C;
            }
            return res;
        }
    }
    return D_004F301C;
}

#endif

}
