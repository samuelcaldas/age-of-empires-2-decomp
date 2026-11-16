/* Function: func_001294E0 (0x001294E0 - 0x001294E8)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_001294E0(void) {
    .word 0x0804a528
    .word 0x00000000
}
#else
void func_001294A0(void);

void func_001294E0(void) {
    func_001294A0();
}
#endif

}
