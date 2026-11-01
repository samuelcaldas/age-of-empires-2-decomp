#pragma once
#pragma exceptions off

#include "zone_spatial_view_update_matrices.h"

extern "C" {
void func_1D9430(void *self);
float func_333EB0(void *obj);
float func_1DAE20(void *self, void *field_4, float f12, float f13, float f14);
void func_1DAE30(void *self, float f12);
void func_1DAF50(void *self, float f12);
void func_1DAEC0(void *self, float f12);
extern void *D_004E3180;

#if defined(__mips__)
asm int func_001D92F0(SpatialViewObj *self) {
    .word 0x27BDFFE0 /* 001D92F0 addiu      $sp, $sp, -0x20 */
    .word 0x7FBF0010 /* 001D92F4 sq         $ra, 0x10($sp) */
    .word 0x7FB00000 /* 001D92F8 sq         $s0, 0x0($sp) */
    jal func_1D9430
    .word 0x70808628 /* 001D9300 paddub     $s0, $a0, $zero */
    .word 0x8F8289C0 /* 001D9304 lw         $v0, -0x7640($gp) */
    jal func_333EB0
    .word 0x8C440404 /* 001D930C lw         $a0, 0x404($v0) */
    .word 0xC60C006C /* 001D9310 lwc1       $f12, 0x6C($s0) */
    .word 0xC60D0078 /* 001D9314 lwc1       $f13, 0x78($s0) */
    .word 0x26050004 /* 001D9318 addiu      $a1, $s0, 0x4 */
    .word 0x46000386 /* 001D931C mov.s      $f14, $f0 */
    jal func_1DAE20
    .word 0x72002628 /* 001D9324 paddub     $a0, $s0, $zero */
    .word 0xE600006C /* 001D9328 swc1       $f0, 0x6C($s0) */
    .word 0x8F8289C0 /* 001D932C lw         $v0, -0x7640($gp) */
    jal func_333EB0
    .word 0x8C440404 /* 001D9334 lw         $a0, 0x404($v0) */
    .word 0xC601006C /* 001D9338 lwc1       $f1, 0x6C($s0) */
    .word 0x72002628 /* 001D933C paddub     $a0, $s0, $zero */
    jal func_1DAE30
    .word 0x46000B02 /* 001D9344 mul.s      $f12, $f1, $f0 */
    .word 0x8F8289C0 /* 001D9348 lw         $v0, -0x7640($gp) */
    jal func_333EB0
    .word 0x8C440404 /* 001D9350 lw         $a0, 0x404($v0) */
    .word 0xC6010064 /* 001D9354 lwc1       $f1, 0x64($s0) */
    .word 0x72002628 /* 001D9358 paddub     $a0, $s0, $zero */
    jal func_1DAF50
    .word 0x46000B02 /* 001D9360 mul.s      $f12, $f1, $f0 */
    .word 0x8F8289C0 /* 001D9364 lw         $v0, -0x7640($gp) */
    jal func_333EB0
    .word 0x8C440404 /* 001D936C lw         $a0, 0x404($v0) */
    .word 0xC6010068 /* 001D9370 lwc1       $f1, 0x68($s0) */
    .word 0x72002628 /* 001D9374 paddub     $a0, $s0, $zero */
    jal func_1DAEC0
    .word 0x46000B02 /* 001D937C mul.s      $f12, $f1, $f0 */
    .word 0x26060034 /* 001D9380 addiu      $a2, $s0, 0x34 */
    .word 0x26050004 /* 001D9384 addiu      $a1, $s0, 0x4 */
    .word 0x24040006 /* 001D9388 addiu      $a0, $zero, 0x6 */
lbl_1D938C:
    .word 0x8CC30000 /* 001D938C lw         $v1, 0x0($a2) */
    .word 0x8CC20004 /* 001D9390 lw         $v0, 0x4($a2) */
    .word 0x2484FFFF /* 001D9394 addiu      $a0, $a0, -0x1 */
    .word 0xACA30000 /* 001D9398 sw         $v1, 0x0($a1) */
    .word 0xACA20004 /* 001D939C sw         $v0, 0x4($a1) */
    .word 0x24C60008 /* 001D93A0 addiu      $a2, $a2, 0x8 */
    bgtz $a0, lbl_1D938C
    .word 0x24A50008 /* 001D93A8 addiu      $a1, $a1, 0x8 */
    .word 0x7BBF0010 /* 001D93AC lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* 001D93B0 lq         $s0, 0x0($sp) */
    .word 0x24020001 /* 001D93B4 addiu      $v0, $zero, 0x1 */
    jr $ra
    .word 0x27BD0020 /* 001D93BC addiu      $sp, $sp, 0x20 */
}
#endif
}

#if !defined(__mips__)
struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

struct Matrix3x4 {
    float m[12];
};

struct SpatialViewObj {
    char pad0[4];
    Matrix3x4 matrix;
    Matrix3x4 matrix_34;
    float field_64;
    float field_68;
    float field_6C;
    char pad1[0x78 - 0x70];
    float field_78;
};

extern "C" int func_001D92F0(SpatialViewObj *self) {
    func_1D9430(self);

    GlobalContext *ctx = (GlobalContext *)D_004E3180;
    float scale0 = func_333EB0(ctx->field_404);
    self->field_6C = func_1DAE20(self, &self->matrix, self->field_6C, self->field_78, scale0);

    float scale1 = func_333EB0(ctx->field_404);
    func_1DAE30(self, self->field_6C * scale1);

    float scale2 = func_333EB0(ctx->field_404);
    func_1DAF50(self, self->field_64 * scale2);

    float scale3 = func_333EB0(ctx->field_404);
    func_1DAEC0(self, self->field_68 * scale3);

    self->matrix = self->matrix_34;

    return 1;
}
#endif
