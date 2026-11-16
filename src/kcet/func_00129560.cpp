/* Function: func_00129560 (0x00129560 - 0x00129588)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129560(void) {
    .word 0x27bdfff0
    .word 0x0080102d
    .word 0xffbf0000
    .word 0x10400003
    .word 0x00a0202d
    .word 0x0040f809
    .word 0x00000000
    .word 0xdfbf0000
    .word 0x03e00008
    .word 0x27bd0010
}
#else
typedef void (*callback_fn)(void *);

void func_00129560(callback_fn fn, void *arg) {
    if (fn != 0) {
        fn(arg);
    }
}
#endif

}
