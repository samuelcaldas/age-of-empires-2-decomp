#pragma once
#pragma exceptions off

#include "zone_spatial_entity_has_positive_velocity.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad[0xBC];
    Vector3 *vel_vec;
};

extern "C" {
#if defined(__mips__)
asm int func_001E0280(const SpatialEntity *self) {
    .word 0x8C8200BC /* 001E0280 lw         $v0, 0xBC($a0) */
    .word 0x14400003 /* 001E0284 bnez       $v0, .L001E0294 */
    .word 0x00000000 /* 001E0288 nop */
    .word 0x10000011 /* 001E028C b          .L001E02D4 */
    .word 0x70001628 /* 001E0290 paddub    $v0, $zero, $zero */
    .word 0xC4430004 /* 001E0294 lwc1       $f3, 0x4($v0) */
    .word 0xC4420000 /* 001E0298 lwc1       $f2, 0x0($v0) */
    .word 0xC4410008 /* 001E029C lwc1       $f1, 0x8($v0) */
    .word 0x44800000 /* 001E02A0 mtc1       $zero, $f0 */
    .word 0x460318C2 /* 001E02A4 mul.s      $f3, $f3, $f3 */
    .word 0x46021082 /* 001E02A8 mul.s      $f2, $f2, $f2 */
    .word 0x46031018 /* 001E02AC adda.s     $f2, $f3 */
    .word 0x4601085C /* 001E02B0 madd.s     $f1, $f1, $f1 */
    .word 0x46010044 /* 001E02B4 c1         0x10044 */
    .word 0x46000836 /* 001E02B8 c.le.s     $f1, $f0 */
    .word 0x00000000 /* 001E02BC nop */
    .word 0x45010004 /* 001E02C0 bc1t       .L001E02D4 */
    .word 0x70001628 /* 001E02C4 paddub    $v0, $zero, $zero */
    .word 0x10000002 /* 001E02C8 b          .L001E02D4 */
    .word 0x24020001 /* 001E02CC addiu     $v0, $zero, 0x1 */
    .word 0x70001628 /* 001E02D0 paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* 001E02D4 jr         $ra */
    .word 0x00000000 /* 001E02D8 nop */
}
#else
int func_001E0280(const SpatialEntity *self) {
    Vector3 *v;
    if ((v = self->vel_vec) != 0) {
        float sq = v->y * v->y + v->x * v->x + v->z * v->z;
        if (sq > 0.0f) {
            return 1;
        }
    }
    return 0;
}
#endif
}
