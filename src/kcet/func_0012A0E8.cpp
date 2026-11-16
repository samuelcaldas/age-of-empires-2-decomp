/* Function: func_0012A0E8 (0x0012A0E8 - 0x0012A0F8)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_0012A0E8(void) {
    .word 0x0004202b // sltu $a0, $zero, $a0
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0x03e00008 // jr $ra
    .word 0xac44d330 // sw $a0, -0x2cd0($v0)
}
#else
extern int D_004ED330;

void func_0012A0E8(int a0) {
    D_004ED330 = a0 > 0;
}
#endif

}
