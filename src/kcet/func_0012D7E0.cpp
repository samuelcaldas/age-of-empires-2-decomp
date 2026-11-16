/* Function: func_0012D7E0 (0x0012D7E0 - 0x0012D83C)
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
asm int func_0012D7E0(const char *name) {
    .word 0x27bdffd0 // 0012D7E0:  addiu $sp, $sp, -0x30
    .word 0x0080282d // 0012D7E4:  move $a1, $a0
    .word 0xffb00010 // 0012D7E8:  sd $s0, 0x10($sp)
    .word 0x3c10004f // 0012D7EC:  lui $s0, 0x4f
    .word 0xffbf0020 // 0012D7F0:  sd $ra, 0x20($sp)
    .word 0x26101540 // 0012D7F4:  addiu $s0, $s0, 0x1540
    .word 0x0c046aef // 0012D7F8:  jal 0x11abbc
    .word 0x0200202d // 0012D7FC:  move $a0, $s0
    .word 0x3c04004f // 0012D800:  lui $a0, 0x4f
    .word 0x0200382d // 0012D804:  move $a3, $s0
    .word 0x24841640 // 0012D808:  addiu $a0, $a0, 0x1640
    .word 0xafa00000 // 0012D80C:  sw $zero, ($sp)
    .word 0x24050010 // 0012D810:  addiu $a1, $zero, 0x10
    .word 0x0000302d // 0012D814:  move $a2, $zero
    .word 0x24080100 // 0012D818:  addiu $t0, $zero, 0x100
    .word 0x0000482d // 0012D81C:  move $t1, $zero
    .word 0x0000502d // 0012D820:  move $t2, $zero
    .word 0x0c041f82 // 0012D824:  jal 0x107e08
    .word 0x0000582d // 0012D828:  move $t3, $zero
    .word 0xdfbf0020 // 0012D82C:  ld $ra, 0x20($sp)
    .word 0xdfb00010 // 0012D830:  ld $s0, 0x10($sp)
    .word 0x03e00008 // 0012D834:  jr $ra
    .word 0x27bd0030 // 0012D838:  addiu $sp, $sp, 0x30
}
#else

extern char D_4F1540[];
extern char D_4F1640[];

char *func_0011ABBC(char *dst, const char *src);
int func_00107E08(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);

int func_0012D7E0(const char *name) {
    func_0011ABBC(D_4F1540, name);
    return func_00107E08(D_4F1640, 0x10, 0, D_4F1540, 0x100, 0, 0, 0);
}

#endif

}
