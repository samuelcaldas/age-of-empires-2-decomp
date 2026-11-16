/* Function: func_00128D10 (0x00128D10 - 0x00128D2C)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00128D10(void) {
    .word 0x27bdfff0
    .word 0xffbf0000
    .word 0x0c04a370
    .word 0x0000402d
    .word 0xdfbf0000
    .word 0x03e00008
    .word 0x27bd0010
}
#else
int func_00128DC0(const char *name, void *buf, int size, int offset, int a4);

int func_00128D10(const char *name, void *buf, int size, int offset) {
    return func_00128DC0(name, buf, size, offset, 0);
}
#endif

}
