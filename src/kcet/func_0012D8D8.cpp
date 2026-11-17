/* Function: func_0012D8D8 (0x0012D8D8 - 0x0012D984)
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
asm s32 func_0012D8D8(s32 a0, s32 a1, s32 a2, s32 a3) {
    .word 0x27bdffb0 // 0012D8D8:  addiu $sp, $sp, -0x50
    .word 0xaf808850 // 0012D8DC:  sw $zero, -0x77b0($gp)
    .word 0xffb00000 // 0012D8E0:  sd $s0, ($sp)
    .word 0xffb30030 // 0012D8E4:  sd $s3, 0x30($sp)
    .word 0x0080802d // 0012D8E8:  move $s0, $a0
    .word 0xffb20020 // 0012D8EC:  sd $s2, 0x20($sp)
    .word 0x00e0982d // 0012D8F0:  move $s3, $a3
    .word 0xffb10010 // 0012D8F4:  sd $s1, 0x10($sp)
    .word 0x00c0902d // 0012D8F8:  move $s2, $a2
    .word 0xffbf0040 // 0012D8FC:  sd $ra, 0x40($sp)
    .word 0x00a0882d // 0012D900:  move $s1, $a1
    .word 0x0c043be0 // 0012D904:  jal 0x10ef80
    .word 0x24040001 // 0012D908:  addiu $a0, $zero, 1
    .word 0x24030002 // 0012D90C:  addiu $v1, $zero, 2
    .word 0x14430015 // 0012D910:  bne $v0, $v1, 0x12d968
    .word 0x8f828850 // 0012D914:  lw $v0, -0x77b0($gp)
    .word 0x0200202d // 0012D918:  move $a0, $s0
    .word 0x0220282d // 0012D91C:  move $a1, $s1
    .word 0x0240302d // 0012D920:  move $a2, $s2
    .word 0x0c043cda // 0012D924:  jal 0x10f368
    .word 0x0260382d // 0012D928:  move $a3, $s3
    .word 0x1440000c // 0012D92C:  bnez $v0, 0x12d960
    .word 0xaf828850 // 0012D930:  sw $v0, -0x77b0($gp)
    .word 0x978284f0 // 0012D934:  lhu $v0, -0x7b10($gp)
    .word 0x00021c00 // 0012D938:  sll $v1, $v0, 0x10
    .word 0x24420001 // 0012D93C:  addiu $v0, $v0, 1
    .word 0x00031c03 // 0012D940:  sra $v1, $v1, 0x10
    .word 0x28630400 // 0012D944:  slti $v1, $v1, 0x400
    .word 0x14600006 // 0012D948:  bnez $v1, 0x12d964
    .word 0xa78284f0 // 0012D94C:  sh $v0, -0x7b10($gp)
    .word 0x0c043f28 // 0012D950:  jal 0x10fca0
    .word 0x00000000 // 0012D954:  nop 
    .word 0x10400003 // 0012D958:  beqz $v0, 0x12d968
    .word 0x8f828850 // 0012D95C:  lw $v0, -0x77b0($gp)
    .word 0xa78084f0 // 0012D960:  sh $zero, -0x7b10($gp)
    .word 0x8f828850 // 0012D964:  lw $v0, -0x77b0($gp)
    .word 0xdfbf0040 // 0012D968:  ld $ra, 0x40($sp)
    .word 0xdfb30030 // 0012D96C:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012D970:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012D974:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012D978:  ld $s0, ($sp)
    .word 0x03e00008 // 0012D97C:  jr $ra
    .word 0x27bd0050 // 0012D980:  addiu $sp, $sp, 0x50
}
#else

extern s32 D_004F3010;
extern s16 D_004F2CB0;

s32 func_0010EF80(s32);
s32 func_0010F368(s32, s32, s32, s32);
s32 func_0010FCA0(void);

s32 func_0012D8D8(s32 a0, s32 a1, s32 a2, s32 a3) {
    D_004F3010 = 0;
    if (func_0010EF80(1) == 2) {
        s32 ret = func_0010F368(a0, a1, a2, a3);
        D_004F3010 = ret;
        if (ret != 0) {
            D_004F2CB0 = 0;
        } else {
            s16 counter = (s16)D_004F2CB0;
            D_004F2CB0 = counter + 1;
            if (counter < 0x400) {
                return D_004F3010;
            }
            if (func_0010FCA0() != 0) {
                D_004F2CB0 = 0;
            }
        }
    }
    return D_004F3010;
}

#endif

}
