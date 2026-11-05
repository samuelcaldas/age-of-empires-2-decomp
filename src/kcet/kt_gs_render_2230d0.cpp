#include "kt_gs_render_2230d0.h"

extern "C" {
void *func_00221C30(void *, void *);
void *func_00221B60(int);
void func_001046A8(void *, int, int);
void func_00104600(void *);

#if defined(__MWERKS__) && defined(__MIPS__)
asm void func_002230D0(void) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x70002628
    .word 0x70002E28
    jal func_00221C30
    .word 0x7FB00000
    .word 0x70408628
    .word 0x24050008
    .word 0x72002628
    jal func_001046A8
    .word 0x70003628
    .word 0x24050014
    .word 0x24060001
    jal func_001046A8
    .word 0x72002628
    jal func_00104600
    .word 0x72002628
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0020
}

asm void func_00223130(void) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x24040004
    jal func_00221B60
    .word 0x7FB00000
    .word 0x70408628
    .word 0x72002628
    jal func_00221C30
    .word 0x70002E28
    .word 0x24050009
    .word 0x72002628
    jal func_001046A8
    .word 0x70003628
    .word 0x24050015
    .word 0x24060001
    jal func_001046A8
    .word 0x72002628
    jal func_00104600
    .word 0x72002628
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0020
}
#else
void func_002230D0(void) {
}

void func_00223130(void) {
}
#endif
}
