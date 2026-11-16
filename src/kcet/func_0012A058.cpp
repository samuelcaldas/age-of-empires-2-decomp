/* Function: func_0012A058 (0x0012A058 - 0x0012A084)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_0012A058(void) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x0c04a810 // jal 0x12a040
    .word 0x0080802d // move $s0, $a0
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xac70d31c // sw $s0, -0x2ce4($v1)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
}
#else

extern int D_004ED31C;
void func_0012A040(void);

void func_0012A058(int a0) {
    func_0012A040();
    D_004ED31C = a0;
}

#endif

}
