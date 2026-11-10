#pragma exceptions off

#include "zone_spatial_view_check_bitmask.h"

extern "C" {
extern const unsigned int D_492570[];

#if defined(__mips__)
asm int func_001DAA60(const unsigned int *self, int idx) {
    bltz $a1, lbl_1DAAA4
    .word 0x70001628 /* 001DAA64 paddub $v0, $zero, $zero */
    .word 0x28A10020 /* 001DAA68 slti $at, $a1, 0x20 */
    beqz $at, lbl_1DAAA0
    .word 0x00000000 /* 001DAA70 nop */
    la $v0, D_492570
    .word 0x8C840000 /* 001DAA7C lw $a0, 0x0($a0) */
    .word 0x00051880 /* 001DAA80 sll $v1, $a1, 2 */
    .word 0x00431021 /* 001DAA84 addu $v0, $v0, $v1 */
    .word 0x8C420000 /* 001DAA88 lw $v0, 0x0($v0) */
    .word 0x00821024 /* 001DAA8C and $v0, $a0, $v0 */
    beqz $v0, lbl_1DAAA0
    .word 0x00000000 /* 001DAA94 nop */
    b lbl_1DAAA4
    .word 0x24020001 /* 001DAA9C addiu $v0, $zero, 0x1 */
lbl_1DAAA0:
    .word 0x70001628 /* 001DAAA0 paddub $v0, $zero, $zero */
lbl_1DAAA4:
    jr $ra
    .word 0x00000000 /* 001DAAA8 nop */
    .word 0x00000000 /* 001DAAAC nop */
}
#else
int func_001DAA60(const unsigned int *self, int idx) {
    if (idx < 0) {
        return 0;
    }
    if (idx >= 32) {
        return 0;
    }
    if (*self & D_492570[idx]) {
        return 1;
    }
    return 0;
}
#endif
}
