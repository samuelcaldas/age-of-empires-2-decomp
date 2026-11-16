/* Function: func_00128D70 (0x00128D70 - 0x00128D8C)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00128D70(void) {
    .word 0x27bdfff0
    .word 0xffbf0000
    .word 0x0c04a364
    .word 0x24080001
    .word 0xdfbf0000
    .word 0x03e00008
    .word 0x27bd0010
}
#else
int func_00128D90(const char *name, void *buf, int size, int a3, int a4);

int func_00128D70(const char *name, void *buf, int size, int a3) {
    return func_00128D90(name, buf, size, a3, 1);
}
#endif

}
