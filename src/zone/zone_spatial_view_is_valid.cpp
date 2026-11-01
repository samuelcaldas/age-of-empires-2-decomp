#pragma once
#pragma exceptions off

#include "zone_spatial_view_is_valid.h"

struct SpatialViewObj {
    char pad[0x64];
    float x;
    float y;
    float z;
};

extern "C" {
#if defined(__mips__)
asm int func_001D8FD0(SpatialViewObj *self) {
    .word 0xC4830064 /* 001D8FD0 lwc1       $f3, 0x64($a0) */
    .word 0xC4820068 /* 001D8FD4 lwc1       $f2, 0x68($a0) */
    .word 0xC481006C /* 001D8FD8 lwc1       $f1, 0x6C($a0) */
    .word 0x44800000 /* 001D8FDC mtc1       $zero, $f0 */
    .word 0x460318C2 /* 001D8FE0 mul.s      $f3, $f3, $f3 */
    .word 0x46021082 /* 001D8FE4 mul.s      $f2, $f2, $f2 */
    .word 0x46021818 /* 001D8FE8 adda.s     $f3, $f2 */
    .word 0x4601085C /* 001D8FEC madd.s     $f1, $f1, $f1 */
    .word 0x46010044 /* 001D8FF0 c1         0x10044 */
    .word 0x46000836 /* 001D8FF4 c.le.s     $f1, $f0 */
    .word 0x00000000 /* 001D8FF8 nop */
    .word 0x45010004 /* 001D8FFC bc1t       .L001D9010 */
    .word 0x70001628 /* 001D9000 paddub    $v0, $zero, $zero */
    .word 0x10000002 /* 001D9004 b          .L001D9010 */
    .word 0x24020001 /* 001D9008 addiu     $v0, $zero, 0x1 */
    .word 0x70001628 /* 001D900C paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* 001D9010 jr         $ra */
    .word 0x00000000 /* 001D9014 nop */
}
#else
int func_001D8FD0(SpatialViewObj *self) {
    if ((self->x * self->x + self->y * self->y) + self->z * self->z <= 0.0f) {
        return 0;
    } else {
        return 1;
    }
}
#endif
}
