#pragma exceptions off

#include "zone_spatial_grid_scan_cross_occupants.h"

extern "C" {

#if defined(__mips__)
asm int func_001E5A00(SpatialGrid *self, void *p1, void *p2, void *p3) {
    .word 0xC4A00000 /* 001E5A00: lwc1 $f0, 0x0($a1) */
    .word 0xC7858048 /* 001E5A04: lwc1 $f5, -0x7FB8($gp) */
    .word 0x70001628 /* 001E5A08: paddub $v0, $zero, $zero */
    .word 0x70001E28 /* 001E5A0C: paddub $v1, $zero, $zero */
    .word 0xE4C00000 /* 001E5A10: swc1 $f0, 0x0($a2) */
    .word 0x8C880000 /* 001E5A14: lw $t0, 0x0($a0) */
    .word 0x10000065 /* 001E5A18: b lbl_1E5BB0 */
    .word 0x250BFFFF /* 001E5A1C: addiu $t3, $t0, -0x1 */
lbl_1E5A20:
    .word 0x8C8A0004 /* 001E5A20: lw $t2, 0x4($a0) */
    .word 0x000348C0 /* 001E5A24: sll $t1, $v1, 3 */
    .word 0x000B40C0 /* 001E5A28: sll $t0, $t3, 3 */
    .word 0x01494821 /* 001E5A2C: addu $t1, $t2, $t1 */
    .word 0x01484021 /* 001E5A30: addu $t0, $t2, $t0 */
    .word 0xC5200000 /* 001E5A34: lwc1 $f0, 0x0($t1) */
    .word 0xC5020000 /* 001E5A38: lwc1 $f2, 0x0($t0) */
    .word 0x46020034 /* 001E5A3C: c.lt.s $f0, $f2 */
    .word 0x00000000 /* 001E5A40: nop */
    .word 0x45000004 /* 001E5A44: bc1f lbl_1E5A58 */
    .word 0x46001046 /* 001E5A48: mov.s $f1, $f2 */
    .word 0x10000003 /* 001E5A4C: b lbl_1E5A5C */
    .word 0x46000046 /* 001E5A50: mov.s $f1, $f0 */
    .word 0x46001046 /* 001E5A54: mov.s $f1, $f2 */
lbl_1E5A58:
    .word 0x46000086 /* 001E5A58: mov.s $f2, $f0 */
lbl_1E5A5C:
    .word 0xC4A00000 /* 001E5A5C: lwc1 $f0, 0x0($a1) */
    .word 0x46010034 /* 001E5A60: c.lt.s $f0, $f1 */
    .word 0x00000000 /* 001E5A64: nop */
    .word 0x45030050 /* 001E5A68: bc1tl lbl_1E5BAC */
    .word 0x70605E28 /* 001E5A6C: paddub $t3, $v1, $zero */
    .word 0x46020036 /* 001E5A70: c.le.s $f0, $f2 */
    .word 0x00000000 /* 001E5A74: nop */
    .word 0x4500004B /* 001E5A78: bc1f lbl_1E5BA8 */
    .word 0x00000000 /* 001E5A7C: nop */
    .word 0x8C8A0004 /* 001E5A80: lw $t2, 0x4($a0) */
    .word 0x000348C0 /* 001E5A84: sll $t1, $v1, 3 */
    .word 0x000B40C0 /* 001E5A88: sll $t0, $t3, 3 */
    .word 0x012A4821 /* 001E5A8C: addu $t1, $t1, $t2 */
    .word 0x010A4021 /* 001E5A90: addu $t0, $t0, $t2 */
    .word 0xC5200004 /* 001E5A94: lwc1 $f0, 0x4($t1) */
    .word 0xC5060004 /* 001E5A98: lwc1 $f6, 0x4($t0) */
    .word 0x46060034 /* 001E5A9C: c.lt.s $f0, $f6 */
    .word 0x00000000 /* 001E5AA0: nop */
    .word 0x45000004 /* 001E5AA4: bc1f lbl_1E5AB8 */
    .word 0x46003086 /* 001E5AA8: mov.s $f2, $f6 */
    .word 0x10000003 /* 001E5AAC: b lbl_1E5ABC */
    .word 0x46000086 /* 001E5AB0: mov.s $f2, $f0 */
    .word 0x46003086 /* 001E5AB4: mov.s $f2, $f6 */
lbl_1E5AB8:
    .word 0x46000186 /* 001E5AB8: mov.s $f6, $f0 */
lbl_1E5ABC:
    .word 0xC4A40004 /* 001E5ABC: lwc1 $f4, 0x4($a1) */
    .word 0x46022034 /* 001E5AC0: c.lt.s $f4, $f2 */
    .word 0x00000000 /* 001E5AC4: nop */
    .word 0x45010037 /* 001E5AC8: bc1t lbl_1E5BA8 */
    .word 0x00000000 /* 001E5ACC: nop */
    .word 0x8C8A0004 /* 001E5AD0: lw $t2, 0x4($a0) */
    .word 0x000B48C0 /* 001E5AD4: sll $t1, $t3, 3 */
    .word 0x000340C0 /* 001E5AD8: sll $t0, $v1, 3 */
    .word 0xC7808064 /* 001E5ADC: lwc1 $f0, -0x7F9C($gp) */
    .word 0x44803800 /* 001E5AE0: mtc1 $zero, $f7 */
    .word 0x01494821 /* 001E5AE4: addu $t1, $t2, $t1 */
    .word 0x01484021 /* 001E5AE8: addu $t0, $t2, $t0 */
    .word 0xC5210000 /* 001E5AEC: lwc1 $f1, 0x0($t1) */
    .word 0xC5030000 /* 001E5AF0: lwc1 $f3, 0x0($t0) */
    .word 0x46030A01 /* 001E5AF4: sub.s $f8, $f1, $f3 */
    .word 0x46004045 /* 001E5AF8: abs.s $f1, $f8 */
    .word 0x46000834 /* 001E5AFC: c.lt.s $f1, $f0 */
    .word 0x00000000 /* 001E5B00: nop */
    .word 0x4500000F /* 001E5B04: bc1f lbl_1E5B44 */
    .word 0x70005E28 /* 001E5B08: paddub $t3, $zero, $zero */
    .word 0x46062034 /* 001E5B0C: c.lt.s $f4, $f6 */
    .word 0x00000000 /* 001E5B10: nop */
    .word 0x45010004 /* 001E5B14: bc1t lbl_1E5B28 */
    .word 0x00000000 /* 001E5B18: nop */
    .word 0x460031C6 /* 001E5B1C: mov.s $f7, $f6 */
    .word 0x10000015 /* 001E5B20: b lbl_1E5B78 */
    .word 0x640B0001 /* 001E5B24: daddiu $t3, $zero, 0x1 */
lbl_1E5B28:
    .word 0x46022034 /* 001E5B28: c.lt.s $f4, $f2 */
    .word 0x00000000 /* 001E5B2C: nop */
    .word 0x45010011 /* 001E5B30: bc1t lbl_1E5B78 */
    .word 0x00000000 /* 001E5B34: nop */
    .word 0x460021C6 /* 001E5B38: mov.s $f7, $f4 */
    .word 0x1000000E /* 001E5B3C: b lbl_1E5B78 */
    .word 0x640B0001 /* 001E5B40: daddiu $t3, $zero, 0x1 */
lbl_1E5B44:
    .word 0xC4A00000 /* 001E5B44: lwc1 $f0, 0x0($a1) */
    .word 0xC5220004 /* 001E5B48: lwc1 $f2, 0x4($t1) */
    .word 0xC5010004 /* 001E5B4C: lwc1 $f1, 0x4($t0) */
    .word 0x46030001 /* 001E5B50: sub.s $f0, $f0, $f3 */
    .word 0x46080003 /* 001E5B54: div.s $f0, $f0, $f8 */
    .word 0x46011081 /* 001E5B58: sub.s $f2, $f2, $f1 */
    .word 0x46001002 /* 001E5B5C: mul.s $f0, $f2, $f0 */
    .word 0x460009C0 /* 001E5B60: add.s $f7, $f1, $f0 */
    .word 0x46043836 /* 001E5B64: c.le.s $f7, $f4 */
    .word 0x00000000 /* 001E5B68: nop */
    .word 0x45000002 /* 001E5B6C: bc1f lbl_1E5B78 */
    .word 0x00000000 /* 001E5B70: nop */
    .word 0x640B0001 /* 001E5B74: daddiu $t3, $zero, 0x1 */
lbl_1E5B78:
    .word 0x1160000B /* 001E5B78: beqz $t3, lbl_1E5BA8 */
    .word 0x00000000 /* 001E5B7C: nop */
    .word 0xC4A00004 /* 001E5B80: lwc1 $f0, 0x4($a1) */
    .word 0x46070001 /* 001E5B84: sub.s $f0, $f0, $f7 */
    .word 0x46050034 /* 001E5B88: c.lt.s $f0, $f5 */
    .word 0x00000000 /* 001E5B8C: nop */
    .word 0x45000005 /* 001E5B90: bc1f lbl_1E5BA8 */
    .word 0x00000000 /* 001E5B94: nop */
    .word 0xACE30000 /* 001E5B98: sw $v1, 0x0($a3) */
    .word 0xE4C70004 /* 001E5B9C: swc1 $f7, 0x4($a2) */
    .word 0x46000146 /* 001E5BA0: mov.s $f5, $f0 */
    .word 0x64020001 /* 001E5BA4: daddiu $v0, $zero, 0x1 */
lbl_1E5BA8:
    .word 0x70605E28 /* 001E5BA8: paddub $t3, $v1, $zero */
lbl_1E5BAC:
    .word 0x24630001 /* 001E5BAC: addiu $v1, $v1, 0x1 */
lbl_1E5BB0:
    .word 0x8C880000 /* 001E5BB0: lw $t0, 0x0($a0) */
    .word 0x0068402A /* 001E5BB4: slt $t0, $v1, $t0 */
    .word 0x1500FF99 /* 001E5BB8: bnez $t0, lbl_1E5A20 */
    .word 0x00000000 /* 001E5BBC: nop */
    .word 0x03E00008 /* 001E5BC0: jr $ra */
    .word 0x00000000 /* 001E5BC4: nop */
}
#else
struct Vec2f {
    float x;
    float y;
};

struct SpatialGrid {
    int count;
    Vec2f *points;
};

int func_001E5A00(SpatialGrid *self, void *p1, void *p2, void *p3) {
    float *pt = (float *)p1;
    float *out_pt = (float *)p2;
    int *out_edge = (int *)p3;

    out_pt[0] = pt[0];
    float limit = 3.402823466e+38F;
    int matched = 0;
    int count = self->count;
    if (count <= 0) {
        return 1;
    }

    int t3 = count - 1;
    for (int v1 = 0; v1 < count; t3 = v1, v1++) {
        Vec2f p_v1 = self->points[v1];
        Vec2f p_t3 = self->points[t3];

        float min_x = p_v1.x < p_t3.x ? p_v1.x : p_t3.x;
        float max_x = p_v1.x < p_t3.x ? p_t3.x : p_v1.x;

        if (pt[0] < min_x) continue;
        if (!(pt[0] <= max_x)) continue;

        float min_y = p_v1.y < p_t3.y ? p_v1.y : p_t3.y;
        float max_y = p_v1.y < p_t3.y ? p_t3.y : p_v1.y;

        if (pt[1] < min_y) continue;

        float dx = p_t3.x - p_v1.x;
        float f7 = 0.0f;
        int flag = 0;

        float abs_dx = dx < 0.0f ? -dx : dx;
        if (abs_dx < 1.0e-7F) {
            if (pt[1] < min_y) {
                f7 = min_y;
                flag = 1;
            } else if (pt[1] < max_y) {
                f7 = pt[1];
                flag = 1;
            }
        } else {
            f7 = p_v1.y + (p_t3.y - p_v1.y) * ((pt[0] - p_v1.x) / dx);
            if (f7 <= pt[1]) {
                flag = 1;
            }
        }

        if (flag) {
            float diff = pt[1] - f7;
            if (diff < limit) {
                *out_edge = v1;
                out_pt[1] = f7;
                limit = diff;
                matched = 1;
            }
        }
    }
    return matched;
}
#endif

}
