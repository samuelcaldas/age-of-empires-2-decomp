#include "kt_gs_render_22cf30.h"

extern "C" {
void func_002273A0(void);
void func_00100670(void);
}

// func_0022CF30 (0x22CF30, size 0x60)
asm void func_0022CF30(void* a0) {
    .word 0x27bdffd0
    .word 0x7fbf0020
    .word 0x7fb10010
    .word 0x7fb00000
    .word 0x70808e28
    .word 0x1220000c
    .word 0x70a08628
    .word 0x3c02004e
    .word 0x2442aed0
    .word 0xae220034
    jal func_002273A0
    .word 0x70002e28
    .word 0x0010143c
    .word 0x0002143f
    .word 0x18400004
    .word 0x72201628
    jal func_00100670
    .word 0x72202628
    .word 0x72201628
    .word 0x7bbf0020
    .word 0x7bb10010
    .word 0x7bb00000
    .word 0x03e00008
    .word 0x27bd0030
}
