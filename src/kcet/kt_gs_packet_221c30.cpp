#include "kt_gs_packet_221c30.h"

extern "C" {
void func_00123908(void);
void func_00104448(void);
void func_001045E8(void);

#if defined(__MWERKS__) && defined(__MIPS__)
asm void func_00221C30(void) {
    .word 0x24060001
    .word 0x70A04628
    .word 0x70002E28
    .word 0x70C03E28
    .word 0x70004E28
    .word 0x08088714
    .word 0x70C05628
    .word 0x00000000
    .word 0x000613F8
    .word 0x00A21825
    .word 0x000713BC
    .word 0x00431825
    .word 0x000813FC
    .word 0x00431825
    .word 0x000916BC
    .word 0x00431825
    .word 0x000A173C
    .word 0x27BDFFD0
    .word 0x00431025
    .word 0x3C030039
    .word 0x7FBF0010
    .word 0x7FB00000
    .word 0x24632CC0
    .word 0x70808628
    .word 0x78630000
    .word 0x27A40020
    .word 0x7C830000
    .word 0x16000004
    .word 0xFFA20020
    jal func_00123908
    .word 0x70002628
    .word 0x70408628
    .word 0x72002628
    .word 0x70002E28
    .word 0x70003628
    jal func_00104448
    .word 0x70003E28
    .word 0x27A20020
    .word 0x78450000
    jal func_001045E8
    .word 0x72002628
    .word 0x72001628
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0030
}

asm void func_00221CF0(void) {
    .word 0x2403FFFF
    .word 0xAF808B84
    .word 0xAF838B80
    .word 0x03E00008
    .word 0xFF838B78
}
#else
void func_00221C30(void) {
}

void func_00221CF0(void) {
}
#endif
}
