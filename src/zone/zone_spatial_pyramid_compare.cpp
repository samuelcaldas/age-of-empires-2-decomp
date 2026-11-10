#pragma exceptions off

#include "zone_spatial_pyramid_compare.h"

#if defined(__mips__)

extern "C" asm int func_001D20D0(void *self, const float *values, int count) {
    .word 0x8C8800A0 /* 001D20D0: lw         $t0, 0xA0($a0) */
    .word 0x15060017 /* 001D20D4: bne        $t0, $a2, .L001D2134 */
    .word 0x24020001 /* 001D20D8: addiu      $v0, $zero, 0x1 */
    .word 0x10000011 /* 001D20DC: b          .L001D2124 */
    .word 0x70003E28 /* 001D20E0: paddub     $a3, $zero, $zero */
    .word 0x00074880 /* 001D20E4: sll        $t1, $a3, 2 */
    /* .L001D20E8: */
    .word 0x00A91021 /* 001D20E8: addu       $v0, $a1, $t1 */
    .word 0x8C83009C /* 001D20EC: lw         $v1, 0x9C($a0) */
    .word 0xC4400000 /* 001D20F0: lwc1       $f0, 0x0($v0) */
    .word 0x00691021 /* 001D20F4: addu       $v0, $v1, $t1 */
    .word 0xC4410000 /* 001D20F8: lwc1       $f1, 0x0($v0) */
    .word 0x46000832 /* 001D20FC: c.eq.s     $f1, $f0 */
    .word 0x00000000 /* 001D2100: nop */
    .word 0x45000002 /* 001D2104: bc1f       .L001D2110 */
    .word 0x24060001 /* 001D2108: addiu      $a2, $zero, 0x1 */
    .word 0x70003628 /* 001D210C: paddub     $a2, $zero, $zero */
    /* .L001D2110: */
    .word 0x50C00004 /* 001D2110: beql       $a2, $zero, .L001D2124 */
    .word 0x24E70001 /* 001D2114: addiu      $a3, $a3, 0x1 */
    .word 0x10000006 /* 001D2118: b          .L001D2134 */
    .word 0x70001628 /* 001D211C: paddub     $v0, $zero, $zero */
    .word 0x24E70001 /* 001D2120: addiu      $a3, $a3, 0x1 */
    /* .L001D2124: */
    .word 0x00E8102A /* 001D2124: slt        $v0, $a3, $t0 */
    .word 0x1440FFEF /* 001D2128: bnez       $v0, .L001D20E8 */
    .word 0x00074880 /* 001D212C: sll        $t1, $a3, 2 */
    .word 0x24020001 /* 001D2130: addiu      $v0, $zero, 0x1 */
    /* .L001D2134: */
    .word 0x03E00008 /* 001D2134: jr         $ra */
    .word 0x00000000 /* 001D2138: nop */
}

#else

extern "C" int func_001D20D0(void *self, const float *values, int count) {
    char *zm = (char *)self;
    int self_count = *(int *)(zm + 0xA0);
    if (self_count != count) {
        return 1;
    }

    float *arr = *(float **)(zm + 0x9C);
    int i = 0;
    while (i < self_count) {
        if (!(arr[i] == values[i])) {
            return 0;
        }
        i++;
    }

    return 1;
}

#endif
