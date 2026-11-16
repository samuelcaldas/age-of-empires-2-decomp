/* Function: func_00129538 (0x00129538 - 0x00129544)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129538(void) {
    .word 0x3c02004f
    .word 0x03e00008
    .word 0xac44d358
}
#else
void func_00129538(int val) {
    *(volatile int *)0x004ED358 = val;
}
#endif

}
