#pragma exceptions off

#include "zone_spatial_entity_update_motion_step.h"

extern "C" {
void *func_333B30(void *p0, int id);
int func_1B8C80(void *obj, short val);
int func_1B94D0(void *obj, short val);

#if defined(__mips__)
asm float func_001E0350(SpatialEntity *self, float f12, float f13, float f14) {
    .word 0x27BDFFC0 /* 001E0350: addiu $sp, $sp, -0x40 */
    .word 0x460D7002 /* 001E0354: mul.s $f0, $f14, $f13 */
    .word 0x7FBF0030 /* 001E0358: sq $ra, 0x30($sp) */
    .word 0x7FB10020 /* 001E035C: sq $s1, 0x20($sp) */
    .word 0x7FB00010 /* 001E0360: sq $s0, 0x10($sp) */
    .word 0xE7B40000 /* 001E0364: swc1 $f20, 0x0($sp) */
    .word 0x8C820008 /* 001E0368: lw $v0, 0x8($a0) */
    .word 0x70808E28 /* 001E036C: paddub $s1, $a0, $zero */
    .word 0x8E250064 /* 001E0370: lw $a1, 0x64($s1) */
    .word 0x8C440B98 /* 001E0374: lw $a0, 0xB98($v0) */
    jal func_333B30
    .word 0x46006500 /* 001E037C: add.s $f20, $f12, $f0 */
    .word 0x70408628 /* 001E0380: paddub $s0, $v0, $zero */
    .word 0x1200002D /* 001E0384: beqz $s0, lbl_1E043C */
    .word 0x00000000 /* 001E0388: nop */
    .word 0x8E190000 /* 001E038C: lw $t9, 0x0($s0) */
    .word 0x8F390070 /* 001E0390: lw $t9, 0x70($t9) */
    jalr $t9
    .word 0x72002628 /* 001E0398: paddub $a0, $s0, $zero */
    .word 0x14400006 /* 001E039C: bnez $v0, lbl_1E03B8 */
    .word 0x00000000 /* 001E03A0: nop */
    .word 0x8E250024 /* 001E03A4: lh $a1, 0x24($s1) */
    jal func_1B8C80
    .word 0x72002628 /* 001E03AC: paddub $a0, $s0, $zero */
    .word 0x14400022 /* 001E03B0: bnez $v0, lbl_1E043C */
    .word 0x00000000 /* 001E03B4: nop */
lbl_1E03B8:
    .word 0x8E250024 /* 001E03B8: lh $a1, 0x24($s1) */
    jal func_1B94D0
    .word 0x72002628 /* 001E03C0: paddub $a0, $s0, $zero */
    .word 0x24030002 /* 001E03C4: addiu $v1, $zero, 0x2 */
    .word 0x14430004 /* 001E03C8: bne $v0, $v1, lbl_1E03DC */
    .word 0x00000000 /* 001E03CC: nop */
    .word 0x44800000 /* 001E03D0: mtc1 $zero, $f0 */
    .word 0x10000039 /* 001E03D4: b lbl_1E04BC */
    .word 0x7BBD0030 /* 001E03D8: lq $ra, 0x30($sp) */
lbl_1E03DC:
    .word 0x8E250024 /* 001E03DC: lh $a1, 0x24($s1) */
    jal func_1B94D0
    .word 0x72002628 /* 001E03E4: paddub $a0, $s0, $zero */
    .word 0x2403FFFF /* 001E03E8: addiu $v1, $zero, -0x1 */
    .word 0x10430004 /* 001E03EC: beq $v0, $v1, lbl_1E0400 */
    .word 0x3C024120 /* 001E03F0: lui $v0, 0x4120 */
    .word 0x10000030 /* 001E03F4: b lbl_1E04B8 */
    .word 0xC60000B0 /* 001E03F8: lwc1 $f0, 0xB0($s0) */
    .word 0x3C024120 /* 001E03FC: lui $v0, 0x4120 */
lbl_1E0400:
    .word 0x44820000 /* 001E0400: mtc1 $v0, $f0 */
    .word 0x00000000 /* 001E0404: nop */
    .word 0x4600A034 /* 001E0408: c.lt.s $f20, $f0 */
    .word 0x00000000 /* 001E040C: nop */
    .word 0x4500000A /* 001E0410: bc1f lbl_1E043C */
    .word 0x00000000 /* 001E0414: nop */
    .word 0x44800000 /* 001E0418: mtc1 $zero, $f0 */
    .word 0x00000000 /* 001E041C: nop */
    .word 0x4600A034 /* 001E0420: c.lt.s $f20, $f0 */
    .word 0x00000000 /* 001E0424: nop */
    .word 0x45000002 /* 001E0428: bc1f lbl_1E0434 */
    .word 0x00000000 /* 001E042C: nop */
    .word 0x46000506 /* 001E0430: mov.s $f20, $f0 */
lbl_1E0434:
    .word 0x10000020 /* 001E0434: b lbl_1E04B8 */
    .word 0x4600A006 /* 001E0438: mov.s $f0, $f20 */
lbl_1E043C:
    .word 0x8E220010 /* 001E043C: lw $v0, 0x10($s1) */
    .word 0x1040000C /* 001E0440: beqz $v0, lbl_1E0474 */
    .word 0x00000000 /* 001E0444: nop */
    .word 0xC441001C /* 001E0448: lwc1 $f1, 0x1C($v0) */
    .word 0x44800000 /* 001E044C: mtc1 $zero, $f0 */
    .word 0x00000000 /* 001E0450: nop */
    .word 0x46000836 /* 001E0454: c.le.s $f1, $f0 */
    .word 0x00000000 /* 001E0458: nop */
    .word 0x45010005 /* 001E045C: bc1t lbl_1E0474 */
    .word 0x00000000 /* 001E0460: nop */
    .word 0x8E220004 /* 001E0464: lw $v0, 0x4($s1) */
    .word 0xC44000A4 /* 001E0468: lwc1 $f0, 0xA4($v0) */
    .word 0x10000004 /* 001E046C: b lbl_1E0480 */
    .word 0x46010002 /* 001E0470: mul.s $f0, $f0, $f1 */
lbl_1E0474:
    .word 0x8E220004 /* 001E0474: lw $v0, 0x4($s1) */
    .word 0xC44000A4 /* 001E0478: lwc1 $f0, 0xA4($v0) */
    .word 0x00000000 /* 001E047C: nop */
lbl_1E0480:
    .word 0x4600A036 /* 001E0480: c.le.s $f20, $f0 */
    .word 0x00000000 /* 001E0484: nop */
    .word 0x45010003 /* 001E0488: bc1t lbl_1E0498 */
    .word 0x00000000 /* 001E048C: nop */
    .word 0x10000009 /* 001E0490: b lbl_1E04B8 */
    .word 0x00000000 /* 001E0494: nop */
lbl_1E0498:
    .word 0x44800000 /* 001E0498: mtc1 $zero, $f0 */
    .word 0x00000000 /* 001E049C: nop */
    .word 0x4600A034 /* 001E04A0: c.lt.s $f20, $f0 */
    .word 0x00000000 /* 001E04A4: nop */
    .word 0x45000002 /* 001E04A8: bc1f lbl_1E04B4 */
    .word 0x00000000 /* 001E04AC: nop */
    .word 0x46000506 /* 001E04B0: mov.s $f20, $f0 */
lbl_1E04B4:
    .word 0x4600A006 /* 001E04B4: mov.s $f0, $f20 */
lbl_1E04B8:
    .word 0x7BBD0030 /* 001E04B8: lq $ra, 0x30($sp) */
lbl_1E04BC:
    .word 0x7BB10020 /* 001E04BC: lq $s1, 0x20($sp) */
    .word 0x7BB00010 /* 001E04C0: lq $s0, 0x10($sp) */
    .word 0xC7B40000 /* 001E04C4: lwc1 $f20, 0x0($sp) */
    .word 0x03E00008 /* 001E04C8: jr $ra */
    .word 0x27BD0040 /* 001E04CC: addiu $sp, $sp, 0x40 */
}
#else
struct TargetObj {
    void **vtable;
    char pad_after_vtable[0xB0 - 4];
    float fixed_speed;
};

struct SubTypeObj {
    char pad[0xA4];
    float max_speed;
};

struct Field10Obj {
    char pad[0x1C];
    float speed_multiplier;
};

struct Field08Obj {
    char pad[0xB98];
    void *field_B98;
};

struct SpatialEntity {
    void **vtable;
    SubTypeObj *sub_type;
    Field08Obj *field_08;
    char pad_0C[0x4];
    Field10Obj *field_10;
    char pad_14[0x24 - 0x14];
    short field_24;
    char pad_26[0x64 - 0x26];
    int field_64;
};

float func_001E0350(SpatialEntity *self, float f12, float f13, float f14) {
    float f20 = f12 + f14 * f13;
    void *target = 0;
    if (self->field_08 != 0) {
        target = func_333B30(self->field_08->field_B98, self->field_64);
    }
    if (target != 0) {
        typedef int (*Method70Fn)(void *);
        Method70Fn m70 = (Method70Fn)(*(void ***)target)[0x70 / 4];
        if (m70(target) == 0) {
            if (func_1B8C80(target, self->field_24) != 0) {
                goto lbl_fallback;
            }
        }
        int action = func_1B94D0(target, self->field_24);
        if (action == 2) {
            return 0.0f;
        }
        action = func_1B94D0(target, self->field_24);
        if (action != -1) {
            return *(float *)((char *)target + 0xB0);
        }
        if (f20 < 10.0f) {
            if (f20 < 0.0f) {
                f20 = 0.0f;
            }
            return f20;
        }
    }
lbl_fallback:
    float max_speed = 0.0f;
    if (self->sub_type != 0) {
        max_speed = self->sub_type->max_speed;
    }
    if (self->field_10 != 0 && self->field_10->speed_multiplier > 0.0f) {
        max_speed *= self->field_10->speed_multiplier;
    }
    if (f20 <= max_speed) {
        if (f20 < 0.0f) {
            f20 = 0.0f;
        }
        return f20;
    }
    return f20;
}
#endif
}
