/* Function: func_00128D30 (0x00128D30 - 0x00128D4C)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00128D30(void) {
    .word 0x27bdfff0
    .word 0xffbf0000
    .word 0x0c04a364
    .word 0x0000402d
    .word 0xdfbf0000
    .word 0x03e00008
    .word 0x27bd0010
}
#else
int func_00128D90(const char *name, void *buf, int size, int offset, int a4);

int func_00128D30(const char *name, void *buf, int size, int offset) {
    return func_00128D90(name, buf, size, offset, 0);
}
#endif

}
