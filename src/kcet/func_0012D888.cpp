/* Function: func_0012D888 (0x0012D888 - 0x0012D8D8)
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
asm u8 func_0012D888(void) {
    .word 0x27bdffd0 // 0012D888:  addiu $sp, $sp, -0x30
    .word 0x3c04004f // 0012D88C:  lui $a0, 0x4f
    .word 0xffb00010 // 0012D890:  sd $s0, 0x10($sp)
    .word 0x24841680 // 0012D894:  addiu $a0, $a0, 0x1680
    .word 0x3c100039 // 0012D898:  lui $s0, 0x39
    .word 0xffbf0020 // 0012D89C:  sd $ra, 0x20($sp)
    .word 0x2609c880 // 0012D8A0:  addiu $t1, $s0, -0x3780
    .word 0xafa00000 // 0012D8A4:  sw $zero, ($sp)
    .word 0x24050003 // 0012D8A8:  addiu $a1, $zero, 3
    .word 0x0000302d // 0012D8AC:  move $a2, $zero
    .word 0x0000382d // 0012D8B0:  move $a3, $zero
    .word 0x0000402d // 0012D8B4:  move $t0, $zero
    .word 0x240a0001 // 0012D8B8:  addiu $t2, $zero, 1
    .word 0x0c041f82 // 0012D8BC:  jal 0x107e08
    .word 0x0000582d // 0012D8C0:  move $t3, $zero
    .word 0x9202c880 // 0012D8C4:  lbu $v0, -0x3780($s0)
    .word 0xdfbf0020 // 0012D8C8:  ld $ra, 0x20($sp)
    .word 0xdfb00010 // 0012D8CC:  ld $s0, 0x10($sp)
    .word 0x03e00008 // 0012D8D0:  jr $ra
    .word 0x27bd0030 // 0012D8D4:  addiu $sp, $sp, 0x30
}
#else

extern char D_4F1680[];
extern u8 D_38C880;

int func_00107E08(void *a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3);

u8 func_0012D888(void) {
    func_00107E08(D_4F1680, 3, 0, 0, 0, 0x38c880, 1, 0);
    return D_38C880;
}

#endif

}
