#pragma exceptions off

#include "zone_spatial_pyramid_check_cell_step.h"

#if defined(__mips__)

extern "C" asm int func_001D4E00(void *self, int x, int y, int level, int min_x, int min_y) {
    .word 0x00A81023 /* 001D4E00: subu       $v0, $a1, $t0 */
    .word 0x04410002 /* 001D4E04: bgez       $v0, .L001D4E10 */
    .word 0x00C91823 /* 001D4E08: subu       $v1, $a2, $t1 */
    .word 0x70001628 /* 001D4E0C: paddub     $v0, $zero, $zero */
    /* .L001D4E10: */
    .word 0x04610002 /* 001D4E10: bgez       $v1, .L001D4E1C */
    .word 0x00000000 /* 001D4E14: nop */
    .word 0x70001E28 /* 001D4E18: paddub     $v1, $zero, $zero */
    /* .L001D4E1C: */
    .word 0x8C840000 /* 001D4E1C: lw         $a0, 0x0($a0) */
    .word 0x00073880 /* 001D4E20: sll        $a3, $a3, 2 */
    .word 0x00431021 /* 001D4E24: addu       $v0, $v0, $v1 */
    .word 0x00083080 /* 001D4E28: sll        $a2, $t0, 2 */
    .word 0x00092840 /* 001D4E2C: sll        $a1, $t1, 1 */
    .word 0x00872021 /* 001D4E30: addu       $a0, $a0, $a3 */
    .word 0x8C840000 /* 001D4E34: lw         $a0, 0x0($a0) */
    .word 0x2403000F /* 001D4E38: addiu      $v1, $zero, 0xF */
    .word 0x00862021 /* 001D4E3C: addu       $a0, $a0, $a2 */
    .word 0x8C840000 /* 001D4E40: lw         $a0, 0x0($a0) */
    .word 0x00852821 /* 001D4E44: addu       $a1, $a0, $a1 */
    .word 0x90A40001 /* 001D4E48: lbu        $a0, 0x1($a1) */
    .word 0x3084000F /* 001D4E4C: andi       $a0, $a0, 0xF */
    .word 0x50830005 /* 001D4E50: beql       $a0, $v1, .L001D4E68 */
    .word 0x2402FFFF /* 001D4E54: addiu      $v0, $zero, -0x1 */
    .word 0x90A30000 /* 001D4E58: lbu        $v1, 0x0($a1) */
    .word 0x14600002 /* 001D4E5C: bnez       $v1, .L001D4E68 */
    .word 0x00000000 /* 001D4E60: nop */
    .word 0x2402FFFF /* 001D4E64: addiu      $v0, $zero, -0x1 */
    /* .L001D4E68: */
    .word 0x03E00008 /* 001D4E68: jr         $ra */
    .word 0x00000000 /* 001D4E6C: nop */
}

#else

extern "C" int func_001D4E00(void *self, int x, int y, int level, int min_x, int min_y) {
    int dx = x - min_x;
    int dy = y - min_y;
    if (dx < 0) {
        dx = 0;
    }
    if (dy < 0) {
        dy = 0;
    }

    int dist = dx + dy;

    void ***root = *(void ****)self;
    unsigned char *cell = (unsigned char *)root[level][min_x] + (min_y << 1);

    if ((cell[1] & 0xF) == 0xF) {
        return -1;
    }

    if (cell[0]) {
        return -1;
    }

    return dist;
}

#endif
