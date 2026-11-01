#pragma once
#pragma exceptions off

#include "zone_spatial_view_transform_point.h"

extern "C" {
float func_1DAE20(void *a0, void *a1, float f12, float f13, float f14);
void func_314FE0(void *dst, void *src, float f12);
void func_3150A0(void *dst, void *m, void *v);

struct SpatialViewObj {
    char pad[0x6C];
    float field_6C;
    char pad1[0x78 - 0x70];
    float field_78;
};

#if defined(__mips__)
asm void func_001DAAB0(void *a0, SpatialViewObj *view, void *a2, Vec3f *out, float scale) {
    .word 0x27BDFF90 /* 001DAAB0 addiu $sp, $sp, -0x70 */
    .word 0x7FBF0040 /* 001DAAB4 sq $ra, 0x40($sp) */
    .word 0x7FB20030 /* 001DAAB8 sq $s2, 0x30($sp) */
    .word 0x7FB10020 /* 001DAABC sq $s1, 0x20($sp) */
    .word 0x7FB00010 /* 001DAAC0 sq $s0, 0x10($sp) */
    .word 0xE7B40000 /* 001DAAC4 swc1 $f20, 0x0($sp) */
    .word 0x46006506 /* 001DAAC8 mov.s $f20, $f12 */
    .word 0xC4AC006C /* 001DAACC lwc1 $f12, 0x6C($a1) */
    .word 0xC4AD0078 /* 001DAAD0 lwc1 $f13, 0x78($a1) */
    .word 0x70809628 /* 001DAAD4 paddub $s2, $a0, $zero */
    .word 0x70C08E28 /* 001DAAD8 paddub $s1, $a2, $zero */
    .word 0x70A02628 /* 001DAADC paddub $a0, $a1, $zero */
    .word 0x70E08628 /* 001DAAE0 paddub $s0, $a3, $zero */
    .word 0x4600A386 /* 001DAAE4 mov.s $f14, $f20 */
    jal func_1DAE20
    .word 0x72202E28 /* 001DAAEC paddub $a1, $s1, $zero */
    .word 0x46140302 /* 001DAAF0 mul.s $f12, $f0, $f20 */
    .word 0x27A40060 /* 001DAAF4 addiu $a0, $sp, 0x60 */
    jal func_314FE0
    .word 0x72002E28 /* 001DAAFC paddub $a1, $s0, $zero */
    .word 0x27A40050 /* 001DAB00 addiu $a0, $sp, 0x50 */
    .word 0x27A60060 /* 001DAB04 addiu $a2, $sp, 0x60 */
    jal func_3150A0
    .word 0x72202E28 /* 001DAB0C paddub $a1, $s1, $zero */
    .word 0xC7A10054 /* 001DAB10 lwc1 $f1, 0x54($sp) */
    .word 0xC7A20058 /* 001DAB14 lwc1 $f2, 0x58($sp) */
    .word 0xC7A00050 /* 001DAB18 lwc1 $f0, 0x50($sp) */
    .word 0xE6400000 /* 001DAB1C swc1 $f0, 0x0($s2) */
    .word 0xE6410004 /* 001DAB20 swc1 $f1, 0x4($s2) */
    .word 0xE6420008 /* 001DAB24 swc1 $f2, 0x8($s2) */
    .word 0x7BBF0040 /* 001DAB28 lq $ra, 0x40($sp) */
    .word 0x7BB20030 /* 001DAB2C lq $s2, 0x30($sp) */
    .word 0x7BB10020 /* 001DAB30 lq $s1, 0x20($sp) */
    .word 0x7BB00010 /* 001DAB34 lq $s0, 0x10($sp) */
    .word 0xC7B40000 /* 001DAB38 lwc1 $f20, 0x0($sp) */
    jr $ra
    .word 0x27BD0070 /* 001DAB40 addiu $sp, $sp, 0x70 */
    .word 0x00000000 /* 001DAB44 nop */
    .word 0x00000000 /* 001DAB48 nop */
    .word 0x00000000 /* 001DAB4C nop */
}
#else
void func_001DAAB0(void *a0, SpatialViewObj *view, void *a2, Vec3f *out, float scale) {
    float scaled = func_1DAE20(a0, a2, view->field_6C, view->field_78, scale);
    Vec3f sp60;
    func_314FE0(&sp60, a2, scaled * scale);
    Vec3f sp50;
    func_3150A0(&sp50, a0, &sp60);
    out->x = sp50.x;
    out->y = sp50.y;
    out->z = sp50.z;
}
#endif
}
