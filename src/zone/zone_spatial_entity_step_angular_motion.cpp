#pragma exceptions off

#include "zone_spatial_entity_step_angular_motion.h"

extern "C" {
void *func_1FC3B0();

#if defined(__mips__)
asm int func_001DFE40(SpatialEntity *self, void *vec) {
    .word 0x27BDFFD0 /* 001DFE40: addiu $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* 001DFE44: sq $ra, 0x20($sp) */
    .word 0x7FB10010 /* 001DFE48: sq $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001DFE4C: sq $s0, 0x0($sp) */
    .word 0x8C8300BC /* 001DFE50: lw $v1, 0xBC($a0) */
    .word 0x70A08628 /* 001DFE54: paddub $s0, $a1, $zero */
    .word 0x14600014 /* 001DFE58: bnez $v1, lbl_1DFEAC */
    .word 0x70808E28 /* 001DFE5C: paddub $s1, $a0, $zero */
    .word 0xC6030004 /* 001DFE60: lwc1 $f3, 0x4($s0) */
    .word 0xC6020000 /* 001DFE64: lwc1 $f2, 0x0($s0) */
    .word 0xC6010008 /* 001DFE68: lwc1 $f1, 0x8($s0) */
    .word 0x44800000 /* 001DFE6C: mtc1 $zero, $f0 */
    .word 0x460318C2 /* 001DFE70: mul.s $f3, $f3, $f3 */
    .word 0x46021082 /* 001DFE74: mul.s $f2, $f2, $f2 */
    .word 0x46031018 /* 001DFE78: adda.s $f2, $f3 */
    .word 0x4601085C /* 001DFE7C: madd.s $f1, $f1, $f1 */
    .word 0x46010044 /* 001DFE80: c1 0x10044 */
    .word 0x46010032 /* 001DFE84: c.eq.s $f0, $f1 */
    .word 0x00000000 /* 001DFE88: nop */
    .word 0x4501000E /* 001DFE8C: bc1t lbl_1DFEC8 */
    .word 0x00000000 /* 001DFE90: nop */
    jal func_1FC3B0
    .word 0x00000000 /* 001DFE98: nop */
    .word 0xAE2200BC /* 001DFE9C: sw $v0, 0xBC($s1) */
    .word 0x8E2300BC /* 001DFEA0: lw $v1, 0xBC($s1) */
    .word 0x10600008 /* 001DFEA4: beqz $v1, lbl_1DFEC8 */
    .word 0x00000000 /* 001DFEA8: nop */
lbl_1DFEAC:
    .word 0x8E2300BC /* 001DFEAC: lw $v1, 0xBC($s1) */
    .word 0xC6020000 /* 001DFEB0: lwc1 $f2, 0x0($s0) */
    .word 0xC6010004 /* 001DFEB4: lwc1 $f1, 0x4($s0) */
    .word 0xC6000008 /* 001DFEB8: lwc1 $f0, 0x8($s0) */
    .word 0xE462000C /* 001DFEBC: swc1 $f2, 0xC($v1) */
    .word 0xE4610010 /* 001DFEC0: swc1 $f1, 0x10($v1) */
    .word 0xE4600014 /* 001DFEC4: swc1 $f0, 0x14($v1) */
lbl_1DFEC8:
    .word 0x7BBF0020 /* 001DFEC8: lq $ra, 0x20($sp) */
    .word 0x7BB10010 /* 001DFECC: lq $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001DFED0: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001DFED4: jr $ra */
}
#else
struct Vec3f {
    float x;
    float y;
    float z;
};

struct MotionBlock {
    Vec3f delta;
    Vec3f angular_velocity;
};

struct SpatialEntity {
    char pad[0xBC];
    MotionBlock *motion;
};

int func_001DFE40(SpatialEntity *self, void *vec) {
    Vec3f *v = (Vec3f *)vec;
    if (self->motion == 0) {
        float sq = v->x * v->x + v->y * v->y + v->z * v->z;
        if (sq == 0.0f) {
            return 0;
        }
        self->motion = (MotionBlock *)func_1FC3B0();
        if (self->motion == 0) {
            return 0;
        }
    }
    self->motion->angular_velocity = *v;
    return 0;
}
#endif
}
