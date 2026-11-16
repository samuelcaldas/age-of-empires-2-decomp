/* Function: func_0012A088 (0x0012A088 - 0x0012A09C)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_0012A088(void) {
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0x2442d300 // addiu $v0, $v0, -0x2d00
    .word 0xac450024 // sw $a1, 0x24($v0)
    .word 0x03e00008 // jr $ra
    .word 0xac440020 // sw $a0, 0x20($v0)
}
#else
struct LibCdvdServerState {
    char pad[0x20];
    int field_20;
    int field_24;
};

void func_0012A088(int a0, int a1) {
    LibCdvdServerState *v0 = (LibCdvdServerState *)0x4ED300;
    v0->field_24 = a1;
    v0->field_20 = a0;
}
#endif

}
