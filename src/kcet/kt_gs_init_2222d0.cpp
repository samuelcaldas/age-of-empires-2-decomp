#include "kt_gs_init_2222d0.h"

extern "C" {
void func_001143C0(void);

#if defined(__MWERKS__) && defined(__MIPS__)
asm void func_002222D0(void) {
    .word 0x3C0200C9
    .word 0x24422D50
    .word 0x3C0100C9
    .word 0xAC222D48
    .word 0x3C0200C9
    .word 0x24425550
    .word 0x3C0100C9
    .word 0xAC222D44
    .word 0x24020200
    .word 0x3C0100C9
    .word 0xA4222D42
    .word 0x24021000
    .word 0x3C0100C9
    j func_00222310
    .word 0xA4222D40
}

asm void func_00222310(void) {
    .word 0x27BDFFF0
    .word 0x7FBF0000
    .word 0x3C0100C9
    .word 0x8C242D44
    .word 0x3C0100C9
    .word 0x94232D40
    .word 0x00031040
    .word 0x00431021
    jal func_001143C0
    .word 0x00022880
    .word 0x3C0100C9
    .word 0x8C242D48
    .word 0x3C0100C9
    .word 0x94232D42
    .word 0x00031080
    .word 0x00431021
    jal func_001143C0
    .word 0x00022880
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}
#else
void func_002222D0(void) {
}

void func_00222310(void) {
}
#endif
}
