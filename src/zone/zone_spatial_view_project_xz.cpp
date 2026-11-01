#pragma exceptions off

#include "zone_spatial_view_project_xz.h"

extern "C" {
void func_315110(void *dst, void *a1, void *a2, void *a3);
float sqrtf(float f);
}

#pragma exceptions off

#include "zone_spatial_view_project_xz.h"

extern "C" {
void func_315110(void *dst, void *a1, void *a2, void *a3);
float sqrtf(float f);

#if defined(__mips__)
asm int func_001DAB50(Vec3f *out, void *a1, void *a2, void *a3) {
    addiu $sp, $sp, -0x40
    sq $ra, 0x10($sp)
    paddub $v0, $a1, $zero
    sq $s0, 0x0($sp)
    paddub $a1, $a2, $zero
    addiu $a0, $sp, 0x30
    paddub $s0, $a3, $zero
    jal func_315110
    paddub $a2, $v0, $zero
    lwc1 $f2, 0x30($sp)
    lwc1 $f1, 0x34($sp)
    lwc1 $f0, 0x38($sp)
    addiu $v1, $sp, 0x20
    mtc1 $zero, $f3
    addiu $v0, $zero, 0x1
    swc1 $f2, 0x20($sp)
    swc1 $f1, 0x24($sp)
    swc1 $f0, 0x28($sp)
    .word 0xC4620000 /* lwc1 $f2, 0x0($v1) */
    .word 0xC4610004 /* lwc1 $f1, 0x4($v1) */
    .word 0xC4600008 /* lwc1 $f0, 0x8($v1) */
    swc1 $f2, 0x0($s0)
    swc1 $f1, 0x4($s0)
    swc1 $f0, 0x8($s0)
    sw $zero, 0x4($s0)
    lwc1 $f1, 0x4($s0)
    lwc1 $f2, 0x0($s0)
    lwc1 $f0, 0x8($s0)
    mul.s $f3, $f3, $f1
    mul.s $f1, $f2, $f2
    .word 0x46030818 /* adda.s $f1, $f3 */
    .word 0x4600005C /* madd.s $f1, $f0, $f0 */
    .word 0x46010044 /* c1 0x10044 / sqrt.s $f1, $f1 */
    div.s $f0, $f2, $f1
    swc1 $f0, 0x0($s0)
    lwc1 $f0, 0x4($s0)
    div.s $f0, $f0, $f1
    swc1 $f0, 0x4($s0)
    lwc1 $f0, 0x8($s0)
    div.s $f0, $f0, $f1
    swc1 $f0, 0x8($s0)
    lq $ra, 0x10($sp)
    lq $s0, 0x0($sp)
    jr $ra
    addiu $sp, $sp, 0x40
    nop
    nop
    nop
}
#else
int func_001DAB50(Vec3f *out, void *a1, void *a2, void *a3) {
    Vec3f sp30;
    func_315110(&sp30, a1, a2, a3);
    Vec3f sp20 = sp30;
    *out = sp20;
    out->y = 0.0f;
    float len = sqrtf(out->x * out->x + out->y * out->y + out->z * out->z);
    out->x /= len;
    out->y /= len;
    out->z /= len;
    return 1;
}
#endif
}
