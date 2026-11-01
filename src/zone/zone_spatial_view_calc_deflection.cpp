#pragma once
#pragma exceptions off

#include "zone_spatial_view_calc_deflection.h"

extern "C" {
float func_3154A0(void *v1);
void func_3151E0(void *cross, void *v1, void *v2);
}

#if defined(__mips__)

extern "C" asm float func_001DAC10(SpatialViewObj *self, void *v1, void *v2, int flag, float scale) {
    addiu      $sp, $sp, -0x70
    sq         $ra, 0x50($sp)
    sq         $s3, 0x40($sp)
    sq         $s2, 0x30($sp)
    sq         $s1, 0x20($sp)
    sq         $s0, 0x10($sp)
    swc1       $f21, 0x4($sp)
    paddub     $s1, $a2, $zero
    paddub     $s3, $a0, $zero
    mov.s      $f21, $f12
    paddub     $s0, $a3, $zero
    paddub     $s2, $a1, $zero
    paddub     $a0, $s1, $zero
    jal        func_3154A0
    swc1       $f20, 0x0($sp)
    mov.s      $f20, $f0
    lwc1       $f0, 0x9C($s3)
    addiu      $v0, $zero, 0x1
    bne        $s0, $v0, lbl_1DAC74
    mul.s      $f0, $f0, $f21
    c.le.s     $f20, $f0
    nop
    bc1t       lbl_1DAC78
    addiu      $a0, $sp, 0x60
    mov.s      $f20, $f0
lbl_1DAC74:
    addiu      $a0, $sp, 0x60
lbl_1DAC78:
    paddub     $a1, $s1, $zero
    jal        func_3151E0
    paddub     $a2, $s2, $zero
    lwc1       $f1, 0x64($sp)
    mtc1       $zero, $f0
    nop
    c.le.s     $f1, $f0
    nop
    bc1t       lbl_1DACA8
    mov.s      $f0, $f20
    neg.s      $f20, $f20
    mov.s      $f0, $f20
lbl_1DACA8:
    lq         $ra, 0x50($sp)
    lq         $s3, 0x40($sp)
    lq         $s2, 0x30($sp)
    lq         $s1, 0x20($sp)
    lq         $s0, 0x10($sp)
    lwc1       $f21, 0x4($sp)
    lwc1       $f20, 0x0($sp)
    jr         $ra
    addiu      $sp, $sp, 0x70
}

#else

struct Vec3f {
    float x, y, z;
};

struct SpatialViewObj {
    char pad[0x9C];
    float field_9C;
};

extern "C" float func_001DAC10(SpatialViewObj *self, void *v1, void *v2, int flag, float scale) {
    float val = func_3154A0(v2);
    float limit = self->field_9C;
    if (flag == 1) {
        limit = limit * scale;
        if (val > limit) {
            val = limit;
        }
    }
    Vec3f cross;
    func_3151E0(&cross, v2, v1);
    if (!(cross.y <= 0.0f)) {
        val = -val;
    }
    return val;
}

#endif
