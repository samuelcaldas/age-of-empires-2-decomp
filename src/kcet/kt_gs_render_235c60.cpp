#include "kt_gs_render_235c60.h"

extern "C" {
void func_00229C50(void);
}

// func_00235C60 (0x235C60, size 0x20)
asm int func_00235C60(void) {
    .word 0x27bdfff0
    .word 0x7fbf0000
    jal func_00229C50
    .word 0x00000000
    .word 0x7bbf0000
    .word 0x24020001
    .word 0x03e00008
    .word 0x27bd0010
}
