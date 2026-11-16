/* Function: func_0012A510 (0x0012A510 - 0x0012A544)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm int func_0012A510(void) {
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0xffbf0000 // sd $ra, ($sp)
    .word 0x0c04b6e8 // jal 0x12dba0
    .word 0x00000000 // nop
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x0040302d // move $a2, $v0
    .word 0x2484fa28 // addiu $a0, $a0, -0x5d8
    .word 0x24050008 // addiu $a1, $zero, 8
    .word 0x0c04a562 // jal 0x129588
    .word 0x24070002 // addiu $a3, $zero, 2
    .word 0xdfbf0000 // ld $ra, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
}
#else
int func_0012DBA0(void);
int func_00129588(void *a0, int a1, int a2, int a3);

extern char D_0048FA28[];

int func_0012A510(void) {
    int v0 = func_0012DBA0();
    return func_00129588(D_0048FA28, 8, v0, 2);
}
#endif

}
