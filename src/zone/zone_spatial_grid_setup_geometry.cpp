#pragma exceptions off

#include "zone_spatial_grid_setup_geometry.h"

extern "C" {
int func_1E5380(void *self, int index);

#if defined(__mips__)
asm int func_001E4150(SpatialGrid *self, void *p1, void *p2) {
    .word 0x27BDFFE0 /* 001E4150: addiu $sp, $sp, -0x20 */
    .word 0x7FBF0010 /* 001E4154: sq $ra, 0x10($sp) */
    .word 0x7FB00000 /* 001E4158: sq $s0, 0x0($sp) */
    .word 0xAC800000 /* 001E415C: sw $zero, 0x0($a0) */
    .word 0xAC800020 /* 001E4160: sw $zero, 0x20($a0) */
    .word 0xC4A00000 /* 001E4164: lwc1 $f0, 0x0($a1) */
    .word 0x70808628 /* 001E4168: paddub $s0, $a0, $zero */
    .word 0xE4800010 /* 001E416C: swc1 $f0, 0x10($a0) */
    .word 0xC4A00004 /* 001E4170: lwc1 $f0, 0x4($a1) */
    .word 0xE4800014 /* 001E4174: swc1 $f0, 0x14($a0) */
    .word 0xC4C00000 /* 001E4178: lwc1 $f0, 0x0($a2) */
    .word 0x24050004 /* 001E417C: addiu $a1, $zero, 0x4 */
    .word 0xE4800018 /* 001E4180: swc1 $f0, 0x18($a0) */
    .word 0xC4C00004 /* 001E4184: lwc1 $f0, 0x4($a2) */
    jal func_1E5380
    .word 0xE480001C /* 001E418C: swc1 $f0, 0x1C($a0) */
    .word 0xC6000018 /* 001E4190: lwc1 $f0, 0x18($s0) */
    .word 0x8E030004 /* 001E4194: lw $v1, 0x4($s0) */
    .word 0x24020001 /* 001E4198: addiu $v0, $zero, 0x1 */
    .word 0xE4600000 /* 001E419C: swc1 $f0, 0x0($v1) */
    .word 0xC600001C /* 001E41A0: lwc1 $f0, 0x1C($s0) */
    .word 0x8E030004 /* 001E41A4: lw $v1, 0x4($s0) */
    .word 0xE4600004 /* 001E41A8: swc1 $f0, 0x4($v1) */
    .word 0xC6000018 /* 001E41AC: lwc1 $f0, 0x18($s0) */
    .word 0x8E030004 /* 001E41B0: lw $v1, 0x4($s0) */
    .word 0xE4600008 /* 001E41B4: swc1 $f0, 0x8($v1) */
    .word 0xC6000014 /* 001E41B8: lwc1 $f0, 0x14($s0) */
    .word 0x8E030004 /* 001E41BC: lw $v1, 0x4($s0) */
    .word 0xE460000C /* 001E41C0: swc1 $f0, 0xC($v1) */
    .word 0xC6000010 /* 001E41C4: lwc1 $f0, 0x10($s0) */
    .word 0x8E030004 /* 001E41C8: lw $v1, 0x4($s0) */
    .word 0xE4600010 /* 001E41CC: swc1 $f0, 0x10($v1) */
    .word 0xC6000014 /* 001E41D0: lwc1 $f0, 0x14($s0) */
    .word 0x8E030004 /* 001E41D4: lw $v1, 0x4($s0) */
    .word 0xE4600014 /* 001E41D8: swc1 $f0, 0x14($v1) */
    .word 0xC6000010 /* 001E41DC: lwc1 $f0, 0x10($s0) */
    .word 0x8E030004 /* 001E41E0: lw $v1, 0x4($s0) */
    .word 0xE4600018 /* 001E41E4: swc1 $f0, 0x18($v1) */
    .word 0xC600001C /* 001E41E8: lwc1 $f0, 0x1C($s0) */
    .word 0x8E030004 /* 001E41EC: lw $v1, 0x4($s0) */
    .word 0xE460001C /* 001E41F0: swc1 $f0, 0x1C($v1) */
    .word 0x7BBD0010 /* 001E41F4: lq $ra, 0x10($sp) */
    .word 0x7BB00000 /* 001E41F8: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001E41FC: jr $ra */
    .word 0x27BD0020 /* 001E4200: addiu $sp, $sp, 0x20 */
}
#else
struct Vec2f {
    float x;
    float y;
};

struct SpatialGrid {
    int f0;
    float *f4;
    char pad_08[0x8];
    Vec2f f10;
    Vec2f f18;
    int f20;
};

int func_001E4150(SpatialGrid *self, void *p1, void *p2) {
    self->f0 = 0;
    self->f20 = 0;

    Vec2f *v1 = (Vec2f *)p1;
    Vec2f *v2 = (Vec2f *)p2;

    self->f10 = *v1;
    self->f18 = *v2;

    func_1E5380(self, 4);

    float *f4 = self->f4;
    f4[0] = self->f18.x;
    f4[1] = self->f18.y;
    f4[2] = self->f18.x;
    f4[3] = self->f10.y;
    f4[4] = self->f10.x;
    f4[5] = self->f10.y;
    f4[6] = self->f10.x;
    f4[7] = self->f18.y;

    return 1;
}
#endif
}
