#pragma exceptions off
#include "kt_loop_event_220f70.h"

extern "C" {
int func_103358(int a0);
int func_12D888(void);

#ifdef __MWERKS__
asm void func_00220F70(void) {
    .word 0x27BDFFF0
    .word 0x7FBF0000
    jal func_103358
    .word 0x70002628
    jal func_12D888
    .word 0x00000000
    .word 0x24030001
    .word 0x304400FF
    .word 0x10830005
    .word 0x70002E28
    .word 0x24030004
    .word 0x1483000E
    .word 0x00000000
    .word 0x70002E28
    .word 0x70002628
    .word 0x10000003
    .word 0x3C030100
    .word 0x24A50001
    .word 0x24840001
    .word 0x0083102A
    .word 0x5440FFFD
    .word 0x24A50001
    jal func_103358
    .word 0x70002628
    .word 0x1000FFEB
    .word 0x00000000
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}
#else
void func_00220F70(void) {
    func_103358(0);
    func_12D888();
}
#endif
}
