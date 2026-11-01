#pragma once
#pragma exceptions off
#pragma inline_intrinsics on

#include "zone_spatial_view_yaw.h"

extern "C" {
extern float D_004E2824;
void func_1D7ED0(void *out_matrix, const void *axis, float angle);
void func_1D8000(void *out_vec, const void *matrix, const void *in_vec);
float __s_abs(float);
float sqrtf(float);

#if defined(__mips__)
asm void func_001DAFE0(SpatialViewObj *self, float val) {
    .word 0x27BDFF90 /* 001DAFE0 addiu      $sp, $sp, -0x70 */
    .word 0x46006046 /* 001DAFE4 mov.s      $f1, $f12 */
    .word 0x7FBF0010 /* 001DAFE8 sq         $ra, 0x10($sp) */
    .word 0x7FB00000 /* 001DAFEC sq         $s0, 0x0($sp) */
    .word 0xC7808064 /* 001DAFF0 lwc1       $f0, -0x7F9C($gp) */
    .word 0x46000845 /* 001DAFF4 abs.s      $f1, $f1 */
    .word 0x46000836 /* 001DAFF8 c.le.s     $f1, $f0 */
    .word 0x00000000 /* 001DAFFC nop */
    bc1t lbl_1DB104
    .word 0x70808628 /* 001DB004 paddub     $s0, $a0, $zero */
    .word 0x27A40020 /* 001DB008 addiu      $a0, $sp, 0x20 */
    jal func_1D7ED0
    .word 0x2605004C /* 001DB010 addiu      $a1, $s0, 0x4C */
    .word 0x27A40050 /* 001DB014 addiu      $a0, $sp, 0x50 */
    .word 0x27A50020 /* 001DB018 addiu      $a1, $sp, 0x20 */
    jal func_1D8000
    .word 0x26060040 /* 001DB020 addiu      $a2, $s0, 0x40 */
    .word 0x27A20050 /* 001DB024 addiu      $v0, $sp, 0x50 */
    .word 0xC4420000 /* 001DB028 lwc1       $f2, 0x0($v0) */
    .word 0xC4410004 /* 001DB02C lwc1       $f1, 0x4($v0) */
    .word 0xC4400008 /* 001DB030 lwc1       $f0, 0x8($v0) */
    .word 0x27A40060 /* 001DB034 addiu      $a0, $sp, 0x60 */
    .word 0x27A50020 /* 001DB038 addiu      $a1, $sp, 0x20 */
    .word 0x26060058 /* 001DB03C addiu      $a2, $s0, 0x58 */
    .word 0xE6020040 /* 001DB040 swc1       $f2, 0x40($s0) */
    .word 0xE6010044 /* 001DB044 swc1       $f1, 0x44($s0) */
    jal func_1D8000
    .word 0xE6000048 /* 001DB04C swc1       $f0, 0x48($s0) */
    .word 0x27A20060 /* 001DB050 addiu      $v0, $sp, 0x60 */
    .word 0xC4420000 /* 001DB054 lwc1       $f2, 0x0($v0) */
    .word 0xC4410004 /* 001DB058 lwc1       $f1, 0x4($v0) */
    .word 0xC4400008 /* 001DB05C lwc1       $f0, 0x8($v0) */
    .word 0x24060001 /* 001DB060 addiu      $a2, $zero, 0x1 */
    .word 0x72002628 /* 001DB064 paddub     $a0, $s0, $zero */
    .word 0xE6020058 /* 001DB068 swc1       $f2, 0x58($s0) */
    .word 0xE601005C /* 001DB06C swc1       $f1, 0x5C($s0) */
    .word 0xE6000060 /* 001DB070 swc1       $f0, 0x60($s0) */
    .word 0xC6030040 /* 001DB074 lwc1       $f3, 0x40($s0) */
    .word 0xC6010044 /* 001DB078 lwc1       $f1, 0x44($s0) */
    .word 0xC6000048 /* 001DB07C lwc1       $f0, 0x48($s0) */
    .word 0x46031882 /* 001DB080 mul.s      $f2, $f3, $f3 */
    .word 0x46010842 /* 001DB084 mul.s      $f1, $f1, $f1 */
    .word 0x46011018 /* 001DB088 adda.s     $f2, $f1 */
    .word 0x4600005C /* 001DB08C madd.s     $f1, $f0, $f0 */
    .word 0x46010044 /* 001DB090 c1         0x10044 */
    .word 0x46011803 /* 001DB094 div.s      $f0, $f3, $f1 */
    .word 0xE6000040 /* 001DB098 swc1       $f0, 0x40($s0) */
    .word 0xC6000044 /* 001DB09C lwc1       $f0, 0x44($s0) */
    .word 0x46010003 /* 001DB0A0 div.s      $f0, $f0, $f1 */
    .word 0xE6000044 /* 001DB0A4 swc1       $f0, 0x44($s0) */
    .word 0xC6000048 /* 001DB0A8 lwc1       $f0, 0x48($s0) */
    .word 0x46010003 /* 001DB0AC div.s      $f0, $f0, $f1 */
    .word 0xE6000048 /* 001DB0B0 swc1       $f0, 0x48($s0) */
    .word 0xC6030058 /* 001DB0B4 lwc1       $f3, 0x58($s0) */
    .word 0xC601005C /* 001DB0B8 lwc1       $f1, 0x5C($s0) */
    .word 0xC6000060 /* 001DB0BC lwc1       $f0, 0x60($s0) */
    .word 0x46031882 /* 001DB0C0 mul.s      $f2, $f3, $f3 */
    .word 0x46010842 /* 001DB0C4 mul.s      $f1, $f1, $f1 */
    .word 0x46011018 /* 001DB0C8 adda.s     $f2, $f1 */
    .word 0x4600005C /* 001DB0CC madd.s     $f1, $f0, $f0 */
    .word 0x46010044 /* 001DB0D0 c1         0x10044 */
    .word 0x46011803 /* 001DB0D4 div.s      $f0, $f3, $f1 */
    .word 0xE6000058 /* 001DB0D8 swc1       $f0, 0x58($s0) */
    .word 0xC600005C /* 001DB0DC lwc1       $f0, 0x5C($s0) */
    .word 0x46010003 /* 001DB0E0 div.s      $f0, $f0, $f1 */
    .word 0xE600005C /* 001DB0E4 swc1       $f0, 0x5C($s0) */
    .word 0xC6000060 /* 001DB0E8 lwc1       $f0, 0x60($s0) */
    .word 0x46010003 /* 001DB0EC div.s      $f0, $f0, $f1 */
    .word 0xE6000060 /* 001DB0F0 swc1       $f0, 0x60($s0) */
    .word 0x8E190000 /* 001DB0F4 lw         $t9, 0x0($s0) */
    .word 0x8F390090 /* 001DB0F8 lw         $t9, 0x90($t9) */
    .word 0x0320F809 /* jalr $t9 */
    .word 0x70002E28 /* 001DB100 paddub     $a1, $zero, $zero */
lbl_1DB104:
    .word 0x7BBF0010 /* 001DB104 lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* 001DB108 lq         $s0, 0x0($sp) */
    jr $ra
    .word 0x27BD0070 /* 001DB110 addiu      $sp, $sp, 0x70 */
}
#endif
}

#if !defined(__mips__)
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

extern "C" void func_001DAFE0(SpatialViewObj *self, float val) {
    if (__s_abs(val) <= D_004E2824) {
        return;
    }
    float rot_matrix[9];
    func_1D7ED0(rot_matrix, &self->basis[1], val);

    Vector3 rotated_right;
    func_1D8000(&rotated_right, rot_matrix, &self->basis[0]);
    self->basis[0] = rotated_right;

    Vector3 rotated_forward;
    func_1D8000(&rotated_forward, rot_matrix, &self->basis[2]);
    self->basis[2] = rotated_forward;

    float len0 = sqrtf(self->basis[0].x * self->basis[0].x +
                       self->basis[0].y * self->basis[0].y +
                       self->basis[0].z * self->basis[0].z);
    self->basis[0].x /= len0;
    self->basis[0].y /= len0;
    self->basis[0].z /= len0;

    float len2 = sqrtf(self->basis[2].x * self->basis[2].x +
                       self->basis[2].y * self->basis[2].y +
                       self->basis[2].z * self->basis[2].z);
    self->basis[2].x /= len2;
    self->basis[2].y /= len2;
    self->basis[2].z /= len2;

    self->Method90(0, 0);
}
#endif
