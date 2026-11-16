/* Function: func_00129F68 (0x00129F68 - 0x00129FCC)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129F68(void) {
    .word 0x27bdffd0 // addiu $sp, $sp, -0x30
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0xffbf0020 // sd $ra, 0x20($sp)
    .word 0x0c04a7d6 // jal 0x129f58
    .word 0x0080802d // move $s0, $a0
    .word 0x0040882d // move $s1, $v0
    .word 0x2602ffff // addiu $v0, $s0, -1
    .word 0x2c420002 // sltiu $v0, $v0, 2
    .word 0x14400008 // bnez $v0, 0x129fb0
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c060049 // lui $a2, 0x49
    .word 0x2484f500 // addiu $a0, $a0, -0xb00
    .word 0x24c6f930 // addiu $a2, $a2, -0x6d0
    .word 0x0c0450c8 // jal 0x114320
    .word 0x24050318 // addiu $a1, $zero, 0x318
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x0220102d // move $v0, $s1
    .word 0xac70d310 // sw $s0, -0x2cf0($v1)
    .word 0xdfbf0020 // ld $ra, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0030 // addiu $sp, $sp, 0x30
}
#else

void func_114320(const char *file, int line, const char *assertion);
int func_00129F58(void);

extern const char D_0048F500[];
extern const char D_0048F930[];
extern int D_004ED310;

int func_00129F68(int a0) {
    int old = func_00129F58();
    if ((unsigned int)(a0 - 1) >= 2) {
        func_114320(D_0048F500, 0x318, D_0048F930);
    }
    D_004ED310 = a0;
    return old;
}

#endif

}
