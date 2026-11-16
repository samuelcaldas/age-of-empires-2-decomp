/* Function: func_001294E8 (0x001294E8 - 0x00129534)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_001294E8(void) {
    .word 0x27bdffe0
    .word 0xffb00000
    .word 0xffbf0010
    .word 0x10000006
    .word 0x0080802d
    .word 0x00000000
    .word 0x0c04b662
    .word 0x00000000
    .word 0x0c040cd6
    .word 0x0000202d
    .word 0x0c04b664
    .word 0x00000000
    .word 0x10400003
    .word 0xdfbf0010
    .word 0x1200fff7
    .word 0x00000000
    .word 0xdfb00000
    .word 0x03e00008
    .word 0x27bd0020
}
#else
void func_12D988(void);
int func_12D990(void);
void func_103358(int);

void func_001294E8(int flag) {
    while (func_12D990() != 0) {
        if (flag != 0) {
            break;
        }
        func_12D988();
        func_103358(0);
    }
}
#endif

}
