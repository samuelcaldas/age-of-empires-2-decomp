#pragma exceptions off

#include "zone_spatial_pyramid_test_cell_bounds.h"

#if defined(__mips__)

extern "C" asm int func_001D40E0(void *self, int level, int x, int y, float f12, float f13, float f14, float f15) {
    .word 0x8C8200F4 /* 001D40E0: lw         $v0, 0xF4($a0) */
    .word 0x00A21007 /* 001D40E4: srav       $v0, $v0, $a1 */
    .word 0x00C2082A /* 001D40E8: slt        $at, $a2, $v0 */
    .word 0x14200011 /* 001D40EC: bnez       $at, .L001D4134 */
    .word 0x70001628 /* 001D40F0: paddub     $v0, $zero, $zero */
    .word 0x8C8200F8 /* 001D40F4: lw         $v0, 0xF8($a0) */
    .word 0x00A21007 /* 001D40F8: srav       $v0, $v0, $a1 */
    .word 0x00E2082A /* 001D40FC: slt        $at, $a3, $v0 */
    .word 0x1420000B /* 001D4100: bnez       $at, .L001D4130 */
    .word 0x00000000 /* 001D4104: nop */
    .word 0x8C8200FC /* 001D4108: lw         $v0, 0xFC($a0) */
    .word 0x00A21007 /* 001D410C: srav       $v0, $v0, $a1 */
    .word 0x0046102A /* 001D4110: slt        $v0, $v0, $a2 */
    .word 0x14400006 /* 001D4114: bnez       $v0, .L001D4130 */
    .word 0x00000000 /* 001D4118: nop */
    .word 0x8C820100 /* 001D411C: lw         $v0, 0x100($a0) */
    .word 0x00A21007 /* 001D4120: srav       $v0, $v0, $a1 */
    .word 0x0047082A /* 001D4124: slt        $at, $v0, $a3 */
    .word 0x10200005 /* 001D4128: beqz       $at, .L001D4140 */
    .word 0x24C20001 /* 001D412C: addiu      $v0, $a2, 0x1 */
    /* .L001D4130: */
    .word 0x70001628 /* 001D4130: paddub     $v0, $zero, $zero */
    /* .L001D4134: */
    .word 0x10000056 /* 001D4134: b          .L001D4290 */
    .word 0x00000000 /* 001D4138: nop */
    .word 0x24C20001 /* 001D413C: addiu      $v0, $a2, 0x1 */
    /* .L001D4140: */
    .word 0x44800800 /* 001D4140: mtc1       $zero, $f1 */
    .word 0x00A21004 /* 001D4144: sllv       $v0, $v0, $a1 */
    .word 0x2448FFFF /* 001D4148: addiu      $t0, $v0, -0x1 */
    .word 0x24E20001 /* 001D414C: addiu      $v0, $a3, 0x1 */
    .word 0x00A64804 /* 001D4150: sllv       $t1, $a2, $a1 */
    .word 0x00A73004 /* 001D4154: sllv       $a2, $a3, $a1 */
    .word 0x00A21004 /* 001D4158: sllv       $v0, $v0, $a1 */
    .word 0x2447FFFF /* 001D415C: addiu      $a3, $v0, -0x1 */
    .word 0x3C023F00 /* 001D4160: lui        $v0, (0x3F000000 >> 16) */
    .word 0x44820000 /* 001D4164: mtc1       $v0, $f0 */
    .word 0x00000000 /* 001D4168: nop */
    .word 0x46007BC0 /* 001D416C: add.s      $f15, $f15, $f0 */
    .word 0x46006301 /* 001D4170: sub.s      $f12, $f12, $f0 */
    .word 0x10000042 /* 001D4174: b          .L001D4280 */
    .word 0x46006B41 /* 001D4178: sub.s      $f13, $f13, $f0 */
    /* .L001D417C: */
    .word 0x44890000 /* 001D417C: mtc1       $t1, $f0 */
    .word 0x70C05628 /* 001D4180: paddub     $t2, $a2, $zero */
    .word 0x468000A0 /* 001D4184: cvt.s.w    $f2, $f0 */
    .word 0x10000039 /* 001D4188: b          .L001D4270 */
    .word 0x00092880 /* 001D418C: sll        $a1, $t1, 2 */
    /* .L001D4190: */
    .word 0x8C820000 /* 001D4190: lw         $v0, 0x0($a0) */
    .word 0x000A1840 /* 001D4194: sll        $v1, $t2, 1 */
    .word 0x8C420000 /* 001D4198: lw         $v0, 0x0($v0) */
    .word 0x00451021 /* 001D419C: addu       $v0, $v0, $a1 */
    .word 0x8C420000 /* 001D41A0: lw         $v0, 0x0($v0) */
    .word 0x00431021 /* 001D41A4: addu       $v0, $v0, $v1 */
    .word 0x90420000 /* 001D41A8: lbu        $v0, 0x0($v0) */
    .word 0x50400030 /* 001D41AC: beql       $v0, $zero, .L001D4270 */
    .word 0x254A0001 /* 001D41B0: addiu      $t2, $t2, 0x1 */
    .word 0x460C10C1 /* 001D41B4: sub.s      $f3, $f2, $f12 */
    .word 0x46011834 /* 001D41B8: c.lt.s     $f3, $f1 */
    .word 0x00000000 /* 001D41BC: nop */
    .word 0x45000002 /* 001D41C0: bc1f       .L001D41CC */
    .word 0x00000000 /* 001D41C4: nop */
    .word 0x460018C7 /* 001D41C8: neg.s      $f3, $f3 */
    /* .L001D41CC: */
    .word 0x460E1836 /* 001D41CC: c.le.s     $f3, $f14 */
    .word 0x00000000 /* 001D41D0: nop */
    .word 0x45010003 /* 001D41D4: bc1t       .L001D41E4 */
    .word 0x00000000 /* 001D41D8: nop */
    .word 0x10000002 /* 001D41DC: b          .L001D41E8 */
    .word 0x460E18C1 /* 001D41E0: sub.s      $f3, $f3, $f14 */
    /* .L001D41E4: */
    .word 0x44801800 /* 001D41E4: mtc1       $zero, $f3 */
    /* .L001D41E8: */
    .word 0x460F1836 /* 001D41E8: c.le.s     $f3, $f15 */
    .word 0x00000000 /* 001D41EC: nop */
    .word 0x4500001E /* 001D41F0: bc1f       .L001D426C */
    .word 0x00000000 /* 001D41F4: nop */
    .word 0x448A0000 /* 001D41F8: mtc1       $t2, $f0 */
    .word 0x00000000 /* 001D41FC: nop */
    .word 0x46800020 /* 001D4200: cvt.s.w    $f0, $f0 */
    .word 0x460D0001 /* 001D4204: sub.s      $f0, $f0, $f13 */
    .word 0x46010034 /* 001D4208: c.lt.s     $f0, $f1 */
    .word 0x00000000 /* 001D420C: nop */
    .word 0x45000002 /* 001D4210: bc1f       .L001D421C */
    .word 0x00000000 /* 001D4214: nop */
    .word 0x46000007 /* 001D4218: neg.s      $f0, $f0 */
    /* .L001D421C: */
    .word 0x460E0036 /* 001D421C: c.le.s     $f0, $f14 */
    .word 0x00000000 /* 001D4220: nop */
    .word 0x45010003 /* 001D4224: bc1t       .L001D4234 */
    .word 0x00000000 /* 001D4228: nop */
    .word 0x10000002 /* 001D422C: b          .L001D4238 */
    .word 0x460E0001 /* 001D4230: sub.s      $f0, $f0, $f14 */
    /* .L001D4234: */
    .word 0x44800000 /* 001D4234: mtc1       $zero, $f0 */
    /* .L001D4238: */
    .word 0x460F0036 /* 001D4238: c.le.s     $f0, $f15 */
    .word 0x00000000 /* 001D423C: nop */
    .word 0x4500000A /* 001D4240: bc1f       .L001D426C */
    .word 0x00000000 /* 001D4244: nop */
    .word 0x4603181A /* 001D4248: mula.s     $f3, $f3 */
    .word 0x4600001C /* 001D424C: madd.s     $f0, $f0, $f0 */
    .word 0x46000004 /* 001D4250: c1         0x4 */
    .word 0x460F0036 /* 001D4254: c.le.s     $f0, $f15 */
    .word 0x00000000 /* 001D4258: nop */
    .word 0x45000003 /* 001D425C: bc1f       .L001D426C */
    .word 0x00000000 /* 001D4260: nop */
    .word 0x1000000A /* 001D4264: b          .L001D4290 */
    .word 0x24020001 /* 001D4268: addiu      $v0, $zero, 0x1 */
    /* .L001D426C: */
    .word 0x254A0001 /* 001D426C: addiu      $t2, $t2, 0x1 */
    /* .L001D4270: */
    .word 0x00EA082A /* 001D4270: slt        $at, $a3, $t2 */
    .word 0x1020FFC6 /* 001D4274: beqz       $at, .L001D4190 */
    .word 0x00000000 /* 001D4278: nop */
    .word 0x25290001 /* 001D427C: addiu      $t1, $t1, 0x1 */
    /* .L001D4280: */
    .word 0x0109082A /* 001D4280: slt        $at, $t0, $t1 */
    .word 0x1020FFBD /* 001D4284: beqz       $at, .L001D417C */
    .word 0x00000000 /* 001D4288: nop */
    .word 0x70001628 /* 001D428C: paddub     $v0, $zero, $zero */
    /* .L001D4290: */
    .word 0x03E00008 /* 001D4290: jr         $ra */
    .word 0x00000000 /* 001D4294: nop */
}

#else

extern "C" int func_001D40E0(void *self, int level, int x, int y, float f12, float f13, float f14, float f15) {
    char *zm = (char *)self;
    int min_x = *(int *)(zm + 0xF4) >> level;
    if (x < min_x) {
        return 0;
    }
    int min_y = *(int *)(zm + 0xF8) >> level;
    if (y < min_y) {
        return 0;
    }
    int max_x = *(int *)(zm + 0xFC) >> level;
    if (x > max_x) {
        return 0;
    }
    int max_y = *(int *)(zm + 0x100) >> level;
    if (y > max_y) {
        return 0;
    }

    int tile_min_x = x << level;
    int tile_max_x = ((x + 1) << level) - 1;
    int tile_min_y = y << level;
    int tile_max_y = ((y + 1) << level) - 1;

    f15 += 0.5f;
    f12 -= 0.5f;
    f13 -= 0.5f;

    void ***root = *(void ****)(zm + 0x0);

    for (int tx = tile_min_x; tx <= tile_max_x; tx++) {
        float f2 = (float)tx;
        for (int ty = tile_min_y; ty <= tile_max_y; ty++) {
            char *cell = (char *)root[0][tx] + ty * 2;
            if (*(unsigned char *)cell == 0) {
                continue;
            }

            float dx = f2 - f12;
            if (dx < 0.0f) dx = -dx;
            if (dx <= f14) {
                dx = 0.0f;
            } else {
                dx -= f14;
            }
            if (dx > f15) {
                continue;
            }

            float dy = (float)ty - f13;
            if (dy < 0.0f) dy = -dy;
            if (dy <= f14) {
                dy = 0.0f;
            } else {
                dy -= f14;
            }
            if (dy > f15) {
                continue;
            }

            if (dx * dx + dy * dy <= f15) {
                return 1;
            }
        }
    }

    return 0;
}

#endif
