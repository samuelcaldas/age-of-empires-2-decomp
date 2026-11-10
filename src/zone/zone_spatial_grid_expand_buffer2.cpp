#pragma once
#pragma exceptions off

#include "zone_spatial_grid_expand_buffer2.h"

extern "C" {
void *func_117CAC(void *dst, int val, unsigned int size);

#if defined(__mips__)
asm void func_001E6F60(SpatialGrid *self, int needed) {
    .word 0x27BDFFD0 /* 001E6F60 addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* 001E6F64 sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* 001E6F68 sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001E6F6C sq         $s0, 0x0($sp) */
    .word 0x70808E28 /* 001E6F70 paddub     $s1, $a0, $zero */
    .word 0x8C840008 /* 001E6F74 lw         $a0, 0x8($a0) */
    .word 0x00A4182A /* 001E6F78 slt        $v1, $a1, $a0 */
    .word 0x1460000C /* 001E6F7C bnez       $v1, .L001E6FB0 */
    .word 0x24830100 /* 001E6F80 addiu      $v1, $a0, 0x100 */
    .word 0x0065082A /* 001E6F84 slt        $at, $v1, $a1 */
    .word 0x0061280A /* 001E6F88 movz       $a1, $v1, $at */
    .word 0x24030100 /* 001E6F8C addiu      $v1, $zero, 0x100 */
    .word 0x70A08628 /* 001E6F90 paddub     $s0, $a1, $zero */
    .word 0x16030004 /* 001E6F94 bne        $s0, $v1, .L001E6FA8 */
    .word 0x262401CC /* 001E6F98 addiu      $a0, $s1, 0x1CC */
    .word 0x24060400 /* 001E6F9C addiu      $a2, $zero, 0x400 */
    jal func_117CAC
    .word 0x70002E28 /* 001E6FA4 paddub     $a1, $zero, $zero */
/* .L001E6FA8: */
    .word 0xAE22000C /* 001E6FA8 sw         $v0, 0xC($s1) */
    .word 0xAE300008 /* 001E6FAC sw         $s0, 0x8($s1) */
/* .L001E6FB0: */
    .word 0x7BBF0020 /* 001E6FB0 lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* 001E6FB4 lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001E6FB8 lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001E6FBC jr         $ra */
    .word 0x27BD0030 /* 001E6FC0 addiu      $sp, $sp, 0x30 */
}
#else
struct SpatialGrid {
    char pad_8[0x8];
    int cap8;
    void **bufC;
    char pad_1CC[0x1BC];
    char embedded_buffer2[0x400];
};

void func_001E6F60(SpatialGrid *self, int needed) {
    if (needed < self->cap8) {
        return;
    }
    int extra = self->cap8 + 0x100;
    if (extra >= needed) {
        needed = extra;
    }
    int final_needed = needed;
    void *buf;
    if (final_needed == 0x100) {
        buf = func_117CAC(&self->embedded_buffer2[0], 0, 0x400);
        self->bufC = (void **)buf;
    }
    self->cap8 = final_needed;
}
#endif
}
