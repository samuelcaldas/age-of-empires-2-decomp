/* Function: func_0012A548 (0x0012A548 - 0x0012A578)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_0012A548(void) {
    .word 0x0080302d // move $a2, $a0
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c070049 // lui $a3, 0x49
    .word 0xffbf0000 // sd $ra, ($sp)
    .word 0x2484fa68 // addiu $a0, $a0, -0x598
    .word 0x24e7fab0 // addiu $a3, $a3, -0x550
    .word 0x0c04a562 // jal 0x129588
    .word 0x24050009 // addiu $a1, $zero, 9
    .word 0xdfbf0000 // ld $ra, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
}
#else
int func_00129588(void *a0, int a1, int a2, void *a3);

extern char D_0048FA68[];
extern char D_0048FAB0[];

int func_0012A548(int key) {
    return func_00129588(D_0048FA68, 9, key, D_0048FAB0);
}
#endif

}
