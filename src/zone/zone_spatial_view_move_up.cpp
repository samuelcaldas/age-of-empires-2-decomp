#pragma once
#pragma exceptions off

#include "zone_spatial_view_move_up.h"

extern "C" {
void func_314FE0(void *out, const void *in, float scale);
extern float D_004E2824;

#if defined(__mips__)
asm void func_001DAEC0(SpatialViewObj *self, float val) {
    .word 0x27BDFFD0 /* 001DAEC0 addiu      $sp, $sp, -0x30 */
    .word 0x46006046 /* 001DAEC4 mov.s      $f1, $f12 */
    .word 0x7FBF0010 /* 001DAEC8 sq         $ra, 0x10($sp) */
    .word 0x7FB00000 /* 001DAECC sq         $s0, 0x0($sp) */
    .word 0xC7808064 /* 001DAED0 lwc1       $f0, -0x7F9C($gp) */
    .word 0x46000845 /* 001DAED4 abs.s      $f1, $f1 */
    .word 0x46000836 /* 001DAED8 c.le.s     $f1, $f0 */
    .word 0x00000000 /* 001DAEDC nop */
    .word 0x45010016 /* 001DAEE0 bc1t       .L001DAF3C */
    .word 0x70808628 /* 001DAEE4 paddub     $s0, $a0, $zero */
    .word 0x27A40020 /* 001DAEE8 addiu      $a0, $sp, 0x20 */
    jal func_314FE0
    .word 0x2605004C /* 001DAEF0 addiu      $a1, $s0, 0x4C */
    .word 0xC6010034 /* 001DAEF4 lwc1       $f1, 0x34($s0) */
    .word 0xC7A00020 /* 001DAEF8 lwc1       $f0, 0x20($sp) */
    .word 0x24060001 /* 001DAEFC addiu      $a2, $zero, 0x1 */
    .word 0x72002628 /* 001DAF00 paddub     $a0, $s0, $zero */
    .word 0x46000800 /* 001DAF04 add.s      $f0, $f1, $f0 */
    .word 0xE6000034 /* 001DAF08 swc1       $f0, 0x34($s0) */
    .word 0xC6010038 /* 001DAF0C lwc1       $f1, 0x38($s0) */
    .word 0xC7A00024 /* 001DAF10 lwc1       $f0, 0x24($sp) */
    .word 0x46000800 /* 001DAF14 add.s      $f0, $f1, $f0 */
    .word 0xE6000038 /* 001DAF18 swc1       $f0, 0x38($s0) */
    .word 0xC601003C /* 001DAF1C lwc1       $f1, 0x3C($s0) */
    .word 0xC7A00028 /* 001DAF20 lwc1       $f0, 0x28($sp) */
    .word 0x46000800 /* 001DAF24 add.s      $f0, $f1, $f0 */
    .word 0xE600003C /* 001DAF28 swc1       $f0, 0x3C($s0) */
    .word 0x8E190000 /* 001DAF2C lw         $t9, 0x0($s0) */
    .word 0x8F390090 /* 001DAF30 lw         $t9, 0x90($t9) */
    .word 0x0320F809 /* 001DAF34 jalr       $t9 */
    .word 0x70002E28 /* 001DAF38 paddub     $a1, $zero, $zero */
/* .L001DAF3C: */
    .word 0x7BBF0010 /* 001DAF3C lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* 001DAF40 lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001DAF44 jr         $ra */
    .word 0x27BD0030 /* 001DAF48 addiu      $sp, $sp, 0x30 */
}
#else
struct Vector3 {
    float x;
    float y;
    float z;
};

class SpatialViewObj {
public:
    virtual void m0();
    virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8();
    virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12();
    virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16();
    virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20();
    virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28();
    virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32();
    virtual void m33();
    virtual void Method90(int p1, int p2);

    char pad_vtable_to_pos[0x34 - 4];
    Vector3 pos;
    Vector3 basis[3];
};

float __s_abs(float);

void func_001DAEC0(SpatialViewObj *self, float val) {
    if (__s_abs(val) <= D_004E2824) {
        return;
    }
    Vector3 delta;
    func_314FE0(&delta, &self->basis[1], val);
    self->pos.x += delta.x;
    self->pos.y += delta.y;
    self->pos.z += delta.z;
    self->Method90(0, 1);
}
#endif
}
