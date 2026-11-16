/* Function: func_0012D840 (0x0012D840 - 0x0012D884)
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
asm int func_0012D840(u32 a0) {
    .word 0x308500ff // 0012D840:  andi $a1, $a0, 0xff
    .word 0x27bdffe0 // 0012D844:  addiu $sp, $sp, -0x20
    .word 0x3c04004f // 0012D848:  lui $a0, 0x4f
    .word 0x3c090039 // 0012D84C:  lui $t1, 0x39
    .word 0xffbf0010 // 0012D850:  sd $ra, 0x10($sp)
    .word 0x24841680 // 0012D854:  addiu $a0, $a0, 0x1680
    .word 0x2529c880 // 0012D858:  addiu $t1, $t1, -0x3780
    .word 0xafa00000 // 0012D85C:  sw $zero, ($sp)
    .word 0x0000302d // 0012D860:  move $a2, $zero
    .word 0x0000382d // 0012D864:  move $a3, $zero
    .word 0x0000402d // 0012D868:  move $t0, $zero
    .word 0x240a0030 // 0012D86C:  addiu $t2, $zero, 0x30
    .word 0x0c041f82 // 0012D870:  jal 0x107e08
    .word 0x0000582d // 0012D874:  move $t3, $zero
    .word 0xdfbf0010 // 0012D878:  ld $ra, 0x10($sp)
    .word 0x03e00008 // 0012D87C:  jr $ra
    .word 0x27bd0020 // 0012D880:  addiu $sp, $sp, 0x20
}
#else

extern char D_4F1680[];

int func_00107E08(void *a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3);

int func_0012D840(u32 a0) {
    return func_00107E08(D_4F1680, a0 & 0xff, 0, 0, 0, 0x38c880, 0x30, 0);
}

#endif

}
