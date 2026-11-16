/* Function: func_00128F68 (0x00128F68 - 0x00128F70)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm int func_00128F68(void) {
    .word 0x03e00008
    .word 0x8f828838
}
#else
extern int D_004E2FF8;

int func_00128F68(void) {
    return D_004E2FF8;
}
#endif

}
