/* Function: func_00129AE0 (0x00129AE0 - 0x00129B10)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129AE0(void) {
    .word 0x0080302d // move $a2, $a0
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c07004e // lui $a3, 0x4e
    .word 0xffbf0000 // sd $ra, ($sp)
    .word 0x2484f7e8 // addiu $a0, $a0, -0x818
    .word 0x24e72c40 // addiu $a3, $a3, 0x2c40
    .word 0x0c04a562 // jal 0x129588
    .word 0x24050004 // addiu $a1, $zero, 4
    .word 0xdfbf0000 // ld $ra, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
}
#else
int func_00129588(void *a0, int a1, int a2, void *a3);

extern char D_0048F7E8[];
extern char D_004E2C40[];

int func_00129AE0(int key) {
    return func_00129588(D_0048F7E8, 4, key, D_004E2C40);
}
#endif

}
