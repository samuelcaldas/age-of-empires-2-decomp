/* Function: func_00129620 (0x00129620 - 0x00129670)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129620(void) {
    .word 0x27bdffd0 // addiu $sp, $sp, -0x30
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x0080882d // move $s1, $a0
    .word 0xffbf0020 // sd $ra, 0x20($sp)
    .word 0x8e220000 // lw $v0, ($s1)
    .word 0x10400007 // beqz $v0, 0x129658
    .word 0x00a0802d // move $s0, $a1
    .word 0x00501024 // and $v0, $v0, $s0
    .word 0x54400005 // bnel $v0, $zero, 0x12965c
    .word 0xae300000 // sw $s0, ($s1)
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484f4e0 // addiu $a0, $a0, -0xb20
    .word 0xae300000 // sw $s0, ($s1)
    .word 0xdfbf0020 // ld $ra, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0030 // addiu $sp, $sp, 0x30
}
#else
void func_118de0(const char *fmt, ...);
extern const char D_48F4E0[];

void func_00129620(int *p, int val) {
    int v = *p;
    if (v == 0) {
        *p = val;
        return;
    }
    if ((v & val) != 0) {
        *p = val;
        return;
    }
    *p = val;
    func_118de0(D_48F4E0);
}
#endif

}
