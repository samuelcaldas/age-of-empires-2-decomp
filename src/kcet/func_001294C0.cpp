/* Function: func_001294C0 (0x001294C0 - 0x001294DC)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_001294C0(void) {
    .word 0x27bdfff0
    .word 0xffbf0000
    .word 0x0c04a50a
    .word 0x24040001
    .word 0xdfbf0000
    .word 0x03e00008
    .word 0x27bd0010
}
#else
void func_00129428(int a0);

void func_001294C0(void) {
    func_00129428(1);
}
#endif

}
