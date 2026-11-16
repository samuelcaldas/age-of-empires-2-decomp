/* Function: func_0012A040 (0x0012A040 - 0x0012A054)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm int func_0012A040(void) {
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x8c62d31c // lw $v0, -0x2ce4($v1)
    .word 0x38420001 // xori $v0, $v0, 1
    .word 0x03e00008 // jr $ra
    .word 0x2c420001 // sltiu $v0, $v0, 1
}
#else
extern int D_004ED31C[];

int func_0012A040(void) {
    return D_004ED31C[0] == 1;
}
#endif

}
