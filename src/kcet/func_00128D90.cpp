/* Function: func_00128D90 (0x00128D90 - 0x00128DBC)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00128D90(void) {
    .word 0x27bdffe0
    .word 0xffb00000
    .word 0xffbf0010
    .word 0x0c04a370
    .word 0x00a0802d
    .word 0x0002800a
    .word 0xdfbf0010
    .word 0x0200102d
    .word 0xdfb00000
    .word 0x03e00008
    .word 0x27bd0020
}
#else
int func_00128DC0(const char *name, void *buf, int size, int offset, int a4);

int func_00128D90(const char *name, void *buf, int size, int offset, int a4) {
    int res = (int)buf;
    if (!func_00128DC0(name, buf, size, offset, a4)) {
        res = 0;
    }
    return res;
}
#endif

}
