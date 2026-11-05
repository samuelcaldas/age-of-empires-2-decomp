#include "kt_gs_render_221b60.h"

extern "C" {
void func_00104558(void);
void func_001043D8(void);
void func_00221880(void);
void func_00221920(void);
void func_00221AC0(void);

#if defined(__MWERKS__) && defined(__MIPS__)
asm void func_00221B60(void) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x7FB00000
    .word 0x8F828B60
    .word 0x3C017000
    .word 0x00021100
    .word 0x00418021
    .word 0x3C017000
    .word 0x00410821
    .word 0x8E030000
    .word 0x8C220004
    .word 0x00621023
    .word 0x00021102
    .word 0x00441021
    .word 0x24420020
    .word 0x2C410101
    .word 0x1420000C
    .word 0x00000000
    .word 0x72002628
    .word 0x70002E28
    .word 0x70003628
    jal func_00104558
    .word 0x70003E28
    jal func_001043D8
    .word 0x72002628
    jal func_00221880
    .word 0x00000000
    jal func_00221920
    .word 0x00000000
    .word 0x8F828B60
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x3C017000
    .word 0x00021100
    .word 0x00411021
    .word 0x03E00008
    .word 0x27BD0020
}

asm void func_00221C00(void) {
    .word 0x27BDFFF0
    .word 0x7FBF0000
    jal func_00221B60
    .word 0x24040100
    jal func_00221AC0
    .word 0x00000000
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}
#else
void func_00221B60(void) {
}

void func_00221C00(void) {
    func_00221B60();
    func_00221AC0();
}
#endif
}
