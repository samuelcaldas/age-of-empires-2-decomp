#pragma exceptions off

#include "zone_spatial_pyramid_check_rect.h"

extern "C" {
int func_001D3440(void *self, int level, int x, int y, void *p1);
}

#if defined(__mips__)

extern "C" asm int func_001D3310(void *self, int x0, int y0, int x1, int y1, void *p1, void *p2) {
    .word 0x27BDFF80 /* 001D3310: addiu      $sp, $sp, -0x80 */
    .word 0x7FBF0070 /* 001D3314: sq         $ra, 0x70($sp) */
    .word 0x7FB60060 /* 001D3318: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 001D331C: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D3320: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D3324: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D3328: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D332C: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D3330: sq         $s0, 0x0($sp) */
    .word 0x00E5082A /* 001D3334: slt        $at, $a3, $a1 */
    .word 0x70808E28 /* 001D3338: paddub     $s1, $a0, $zero */
    .word 0x10200004 /* 001D333C: beqz       $at, .L001D3350 */
    .word 0x71208628 /* 001D3340: paddub     $s0, $t1, $zero */
    .word 0x70A01E28 /* 001D3344: paddub     $v1, $a1, $zero */
    .word 0x70E02E28 /* 001D3348: paddub     $a1, $a3, $zero */
    .word 0x70603E28 /* 001D334C: paddub     $a3, $v1, $zero */
    /* .L001D3350: */
    .word 0x0106082A /* 001D3350: slt        $at, $t0, $a2 */
    .word 0x10200004 /* 001D3354: beqz       $at, .L001D3368 */
    .word 0x00000000 /* 001D3358: nop */
    .word 0x70C01E28 /* 001D335C: paddub     $v1, $a2, $zero */
    .word 0x71003628 /* 001D3360: paddub     $a2, $t0, $zero */
    .word 0x70604628 /* 001D3364: paddub     $t0, $v1, $zero */
    /* .L001D3368: */
    .word 0x04A10002 /* 001D3368: bgez       $a1, .L001D3374 */
    .word 0x00000000 /* 001D336C: nop */
    .word 0x70002E28 /* 001D3370: paddub     $a1, $zero, $zero */
    /* .L001D3374: */
    .word 0x04C10002 /* 001D3374: bgez       $a2, .L001D3380 */
    .word 0x00000000 /* 001D3378: nop */
    .word 0x70003628 /* 001D337C: paddub     $a2, $zero, $zero */
    /* .L001D3380: */
    .word 0x8E2300E4 /* 001D3380: lw         $v1, 0xE4($s1) */
    .word 0x00E3182A /* 001D3384: slt        $v1, $a3, $v1 */
    .word 0x14600003 /* 001D3388: bnez       $v1, .L001D3398 */
    .word 0x00000000 /* 001D338C: nop */
    .word 0x8E2700EC /* 001D3390: lw         $a3, 0xEC($s1) */
    .word 0x00000000 /* 001D3394: nop */
    /* .L001D3398: */
    .word 0x8E2300E8 /* 001D3398: lw         $v1, 0xE8($s1) */
    .word 0x0103182A /* 001D339C: slt        $v1, $t0, $v1 */
    .word 0x14600003 /* 001D33A0: bnez       $v1, .L001D33B0 */
    .word 0x00000000 /* 001D33A4: nop */
    .word 0x8E2800F0 /* 001D33A8: lw         $t0, 0xF0($s1) */
    .word 0x00000000 /* 001D33AC: nop */
    /* .L001D33B0: */
    .word 0xAE2500F4 /* 001D33B0: sw         $a1, 0xF4($s1) */
    .word 0xAE2600F8 /* 001D33B4: sw         $a2, 0xF8($s1) */
    .word 0xAE2700FC /* 001D33B8: sw         $a3, 0xFC($s1) */
    .word 0xAE280100 /* 001D33BC: sw         $t0, 0x100($s1) */
    .word 0x000690C3 /* 001D33C0: sra        $s2, $a2, 3 */
    .word 0x000798C3 /* 001D33C4: sra        $s3, $a3, 3 */
    .word 0x0008A0C3 /* 001D33C8: sra        $s4, $t0, 3 */
    .word 0x1000000E /* 001D33CC: b          .L001D3408 */
    .word 0x0005A8C3 /* 001D33D0: sra        $s5, $a1, 3 */
    /* .L001D33D4: */
    .word 0x10000008 /* 001D33D4: b          .L001D33F8 */
    .word 0x7240B628 /* 001D33D8: paddub     $s6, $s2, $zero */
    .word 0x24050003 /* 001D33DC: addiu      $a1, $zero, 0x3 */
    /* .L001D33E0: */
    .word 0x72202628 /* 001D33E0: paddub     $a0, $s1, $zero */
    .word 0x72A03628 /* 001D33E4: paddub     $a2, $s5, $zero */
    .word 0x72C03E28 /* 001D33E8: paddub     $a3, $s6, $zero */
    jal func_001D3440 /* 001D33EC: jal        func_001D3440 */
    .word 0x72004628 /* 001D33F0: paddub     $t0, $s0, $zero */
    .word 0x26D60001 /* 001D33F4: addiu      $s6, $s6, 0x1 */
    /* .L001D33F8: */
    .word 0x0296082A /* 001D33F8: slt        $at, $s4, $s6 */
    .word 0x1020FFF8 /* 001D33FC: beqz       $at, .L001D33E0 */
    .word 0x24050003 /* 001D3400: addiu      $a1, $zero, 0x3 */
    .word 0x26B50001 /* 001D3404: addiu      $s5, $s5, 0x1 */
    /* .L001D3408: */
    .word 0x0275082A /* 001D3408: slt        $at, $s3, $s5 */
    .word 0x1020FFF1 /* 001D340C: beqz       $at, .L001D33D4 */
    .word 0x00000000 /* 001D3410: nop */
    .word 0x7BBF0070 /* 001D3414: lq         $ra, 0x70($sp) */
    .word 0x7BB60060 /* 001D3418: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 001D341C: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D3420: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D3424: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D3428: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D342C: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D3430: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D3434: jr         $ra */
    .word 0x27BD0080 /* 001D3438: addiu      $sp, $sp, 0x80 */
}

#else

extern "C" int func_001D3310(void *self, int x0, int y0, int x1, int y1, void *p1, void *p2) {
    char *zm = (char *)self;
    if (x1 < x0) {
        int t = x0; x0 = x1; x1 = t;
    }
    if (y1 < y0) {
        int t = y0; y0 = y1; y1 = t;
    }

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;

    int max_x = *(int *)(zm + 0xE4);
    if (x1 >= max_x) x1 = max_x - 1;
    int max_y = *(int *)(zm + 0xE8);
    if (y1 >= max_y) y1 = max_y - 1;

    int s4 = x0 >> 3;
    int s2 = x1 >> 3;
    int s5 = y0 >> 3;
    int s3 = y1 >> 3;

    for (int x = s4; x <= s2; x++) {
        for (int y = s5; y <= s3; y++) {
            if (func_001D3440(self, 3, x, y, p1) != 0) {
                return 1;
            }
        }
    }

    return 0;
}

#endif
