#pragma once
#pragma exceptions off

#include "zone_spatial_grid_check_point_in_aabb_list.h"

#if defined(__mips__)
extern "C" asm int func_001E6140(const AABBList *self, const Point2D *pt) {
    .word 0x8C870020 /* 001E6140 lw         $a3, 0x20($a0) */
    .word 0x1000001F /* 001E6144 b          .L001E61C4 */
    .word 0x70003628 /* 001E6148 paddub     $a2, $zero, $zero */
    .word 0x00061080 /* 001E614C sll        $v0, $a2, 2 */
    .word 0x00461821 /* 001E6150 addu       $v1, $v0, $a2 */
    .word 0xC4A10000 /* 001E6154 lwc1       $f1, 0x0($a1) */
    .word 0x8C820028 /* 001E6158 lw         $v0, 0x28($a0) */
    .word 0x00031880 /* 001E615C sll        $v1, $v1, 2 */
    .word 0x00431021 /* 001E6160 addu       $v0, $v0, $v1 */
    .word 0xC4400000 /* 001E6164 lwc1       $f0, 0x0($v0) */
    .word 0x46000836 /* 001E6168 c.le.s     $f1, $f0 */
    .word 0x00000000 /* 001E616C nop */
    .word 0x45030014 /* 001E6170 bc1tl      .L001E61C4 */
    .word 0x24C60001 /* 001E6174 addiu      $a2, $a2, 0x1 */
    .word 0xC4400008 /* 001E6178 lwc1       $f0, 0x8($v0) */
    .word 0x46000834 /* 001E617C c.lt.s     $f1, $f0 */
    .word 0x00000000 /* 001E6180 nop */
    .word 0x4500000E /* 001E6184 bc1f       .L001E61C0 */
    .word 0x00000000 /* 001E6188 nop */
    .word 0xC4A10004 /* 001E618C lwc1       $f1, 0x4($a1) */
    .word 0xC4400004 /* 001E6190 lwc1       $f0, 0x4($v0) */
    .word 0x46000836 /* 001E6194 c.le.s     $f1, $f0 */
    .word 0x00000000 /* 001E6198 nop */
    .word 0x45010008 /* 001E619C bc1t       .L001E61C0 */
    .word 0x00000000 /* 001E61A0 nop */
    .word 0xC440000C /* 001E61A4 lwc1       $f0, 0xC($v0) */
    .word 0x46000834 /* 001E61A8 c.lt.s     $f1, $f0 */
    .word 0x00000000 /* 001E61AC nop */
    .word 0x45000003 /* 001E61B0 bc1f       .L001E61C0 */
    .word 0x00000000 /* 001E61B4 nop */
    .word 0x10000006 /* 001E61B8 b          func_001E61D4 */
    .word 0x24020001 /* 001E61BC addiu      $v0, $zero, 0x1 */
    .word 0x24C60001 /* 001E61C0 addiu      $a2, $a2, 0x1 */
    .word 0x00C7102A /* 001E61C4 slt        $v0, $a2, $a3 */
    .word 0x1440FFE1 /* 001E61C8 bnez       $v0, .L001E6150 */
    .word 0x00061080 /* 001E61CC sll        $v0, $a2, 2 */
    .word 0x70001628 /* 001E61D0 paddub     $v0, $zero, $zero */
    jr $ra
    .word 0x00000000 /* 001E61D8 nop */
}
#else
struct AABB {
    float min_x;
    float min_y;
    float max_x;
    float max_y;
    float z;
};

struct Point2D {
    float x;
    float y;
};

struct AABBList {
    char pad[0x20];
    int count;
    char pad2[0x4];
    AABB *items;
};

extern "C" int func_001E6140(const AABBList *self, const Point2D *pt) {
    int n = self->count;
    for (int i = 0; i < n; i++) {
        const AABB *b = &self->items[i];
        if (pt->x <= b->min_x) continue;
        if (pt->x >= b->max_x) continue;
        if (pt->y <= b->min_y) continue;
        if (pt->y < b->max_y) {
            return 1;
        }
    }
    return 0;
}
#endif
