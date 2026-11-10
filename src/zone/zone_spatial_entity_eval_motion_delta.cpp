#pragma exceptions off

#include "zone_spatial_entity_eval_motion_delta.h"

extern "C" {
void *func_1FC3B0();

#if defined(__mips__)
asm int func_001DFD60(SpatialEntity *self, void *vec) {
    .word 0x27BDFFD0 /* 001DFD60: addiu $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* 001DFD64: sq $ra, 0x20($sp) */
    .word 0x7FB10010 /* 001DFD68: sq $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001DFD6C: sq $s0, 0x0($sp) */
    .word 0x8C8300BC /* 001DFD70: lw $v1, 0xBC($a0) */
    .word 0x70A08628 /* 001DFD74: paddub $s0, $a1, $zero */
    .word 0x14600014 /* 001DFD78: bnez $v1, lbl_1DFDCC */
    .word 0x70808E28 /* 001DFD7C: paddub $s1, $a0, $zero */
    .word 0xC6030004 /* 001DFD80: lwc1 $f3, 0x4($s0) */
    .word 0xC6020000 /* 001DFD84: lwc1 $f2, 0x0($s0) */
    .word 0xC6010008 /* 001DFD88: lwc1 $f1, 0x8($s0) */
    .word 0x44800000 /* 001DFD8C: mtc1 $zero, $f0 */
    .word 0x460318C2 /* 001DFD90: mul.s $f3, $f3, $f3 */
    .word 0x46021082 /* 001DFD94: mul.s $f2, $f2, $f2 */
    .word 0x46031018 /* 001DFD98: adda.s $f2, $f3 */
    .word 0x4601085C /* 001DFD9C: madd.s $f1, $f1, $f1 */
    .word 0x46010044 /* 001DFDA0: c1 0x10044 */
    .word 0x46010032 /* 001DFDA4: c.eq.s $f0, $f1 */
    .word 0x00000000 /* 001DFDA8: nop */
    .word 0x4501000E /* 001DFDAC: bc1t lbl_1DFDE8 */
    .word 0x00000000 /* 001DFDB0: nop */
    jal func_1FC3B0
    .word 0x00000000 /* 001DFDB8: nop */
    .word 0xAE2200BC /* 001DFDBC: sw $v0, 0xBC($s1) */
    .word 0x8E2300BC /* 001DFDC0: lw $v1, 0xBC($s1) */
    .word 0x10600008 /* 001DFDC4: beqz $v1, lbl_1DFDE8 */
    .word 0x00000000 /* 001DFDC8: nop */
lbl_1DFDCC:
    .word 0x8E2300BC /* 001DFDCC: lw $v1, 0xBC($s1) */
    .word 0xC6020000 /* 001DFDD0: lwc1 $f2, 0x0($s0) */
    .word 0xC6010004 /* 001DFDD4: lwc1 $f1, 0x4($s0) */
    .word 0xC6000008 /* 001DFDD8: lwc1 $f0, 0x8($s0) */
    .word 0xE4620000 /* 001DFDDC: swc1 $f2, 0x0($v1) */
    .word 0xE4610004 /* 001DFDE0: swc1 $f1, 0x4($v1) */
    .word 0xE4600008 /* 001DFDE4: swc1 $f0, 0x8($v1) */
lbl_1DFDE8:
    .word 0x7BBF0020 /* 001DFDE8: lq $ra, 0x20($sp) */
    .word 0x7BB10010 /* 001DFDEC: lq $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001DFDF0: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001DFDF4: jr $ra */
}
#else
struct Vec3f {
    float x;
    float y;
    float z;
};

struct MotionBlock {
    Vec3f delta;
};

struct SpatialEntity {
    char pad[0xBC];
    MotionBlock *motion;
};

int func_001DFD60(SpatialEntity *self, void *vec) {
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
    self->motion->delta = *v;
    return 0;
}
#endif
}
