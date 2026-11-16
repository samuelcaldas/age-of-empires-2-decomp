/* Function: func_00129548 (0x00129548 - 0x0012955C)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129548(void) {
    .word 0x3c03004f
    .word 0x2463d300
    .word 0x8c620058
    .word 0x03e00008
    .word 0xac600058
}
#else
int func_00129548(void) {
    volatile int *ptr = (volatile int *)0x004ED358;
    int val = *ptr;
    *ptr = 0;
    return val;
}
#endif

}
