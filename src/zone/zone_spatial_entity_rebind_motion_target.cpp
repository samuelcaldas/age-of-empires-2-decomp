#pragma exceptions off

#include <cmath>
#include "zone_spatial_entity_rebind_motion_target.h"

extern "C" {
void func_26AA00(void *self, const void *dir, const void *up);
void func_3151E0(void *cross, const void *v1, const void *v2);

#if defined(__mips__)
asm void func_001DFC60(SpatialEntity *self, const void *dir, const void *up) {
    .word 0x27BDFFB0 /* 001DFC60: addiu $sp, $sp, -0x50 */
    .word 0x7FBF0030 /* 001DFC64: sq $ra, 0x30($sp) */
    .word 0x7FB20020 /* 001DFC68: sq $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001DFC6C: sq $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001DFC70: sq $s0, 0x0($sp) */
    .word 0x70809628 /* 001DFC74: paddub $s2, $a0, $zero */
    .word 0x70A08E28 /* 001DFC78: paddub $s1, $a1, $zero */
    jal func_26AA00
    .word 0x70C08628 /* 001DFC80: paddub $s0, $a2, $zero */
    .word 0xC6220000 /* 001DFC84: lwc1 $f2, 0x0($s1) */
    .word 0xC6210004 /* 001DFC88: lwc1 $f1, 0x4($s1) */
    .word 0xC6200008 /* 001DFC8C: lwc1 $f0, 0x8($s1) */
    .word 0x27A40040 /* 001DFC90: addiu $a0, $sp, 0x40 */
    .word 0x72002E28 /* 001DFC94: paddub $a1, $s0, $zero */
    .word 0x72203628 /* 001DFC98: paddub $a2, $s1, $zero */
    .word 0xE642009C /* 001DFC9C: swc1 $f2, 0x9C($s2) */
    .word 0xE64100A0 /* 001DFCA0: swc1 $f1, 0xA0($s2) */
    jal func_3151E0
    .word 0xE64000A4 /* 001DFCA8: swc1 $f0, 0xA4($s2) */
    .word 0x27A30040 /* 001DFCAC: addiu $v1, $sp, 0x40 */
    .word 0xC4620000 /* 001DFCB0: lwc1 $f2, 0x0($v1) */
    .word 0xC4610004 /* 001DFCB4: lwc1 $f1, 0x4($v1) */
    .word 0xC4600008 /* 001DFCB8: lwc1 $f0, 0x8($v1) */
    .word 0xE64200A8 /* 001DFCBC: swc1 $f2, 0xA8($s2) */
    .word 0xE64100AC /* 001DFCC0: swc1 $f1, 0xAC($s2) */
    .word 0xE64000B0 /* 001DFCC4: swc1 $f0, 0xB0($s2) */
    .word 0xC64300A8 /* 001DFCC8: lwc1 $f3, 0xA8($s2) */
    .word 0xC64100AC /* 001DFCCC: lwc1 $f1, 0xAC($s2) */
    .word 0xC64000B0 /* 001DFCD0: lwc1 $f0, 0xB0($s2) */
    .word 0x46031882 /* 001DFCD4: mul.s $f2, $f3, $f3 */
    .word 0x46010842 /* 001DFCD8: mul.s $f1, $f1, $f1 */
    .word 0x46011018 /* 001DFCDC: adda.s $f2, $f1 */
    .word 0x4600005C /* 001DFCE0: madd.s $f1, $f0, $f0 */
    .word 0x46010044 /* 001DFCE4: c1 0x10044 */
    .word 0x46011803 /* 001DFCE8: div.s $f0, $f3, $f1 */
    .word 0xE64000A8 /* 001DFCEC: swc1 $f0, 0xA8($s2) */
    .word 0xC64000AC /* 001DFCF0: lwc1 $f0, 0xAC($s2) */
    .word 0x46010003 /* 001DFCF4: div.s $f0, $f0, $f1 */
    .word 0xE64000AC /* 001DFCF8: swc1 $f0, 0xAC($s2) */
    .word 0xC64000B0 /* 001DFCFC: lwc1 $f0, 0xB0($s2) */
    .word 0x46010003 /* 001DFD00: div.s $f0, $f0, $f1 */
    .word 0xE64000B0 /* 001DFD04: swc1 $f0, 0xB0($s2) */
    .word 0x7BBD0030 /* 001DFD08: lq $ra, 0x30($sp) */
    .word 0x7BB20020 /* 001DFD0C: lq $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001DFD10: lq $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001DFD14: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001DFD18: jr $ra */
    .word 0x27BD0050 /* 001DFD1C: addiu $sp, $sp, 0x50 */
}
#else
struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad_00[0x9C];
    Vector3 vec_9c;
    Vector3 vec_a8;
};

void func_001DFC60(SpatialEntity *self, const void *dir, const void *up) {
    func_26AA00(self, dir, up);
    self->vec_9c = *(const Vector3 *)dir;

    Vector3 cross;
    func_3151E0(&cross, up, dir);
    self->vec_a8 = cross;

    float len = std::sqrt(self->vec_a8.x * self->vec_a8.x +
                          self->vec_a8.y * self->vec_a8.y +
                          self->vec_a8.z * self->vec_a8.z);
    self->vec_a8.x /= len;
    self->vec_a8.y /= len;
    self->vec_a8.z /= len;
}
#endif
}
