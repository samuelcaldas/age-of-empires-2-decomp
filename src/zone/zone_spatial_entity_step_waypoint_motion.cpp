#pragma exceptions off

#include "zone_spatial_entity_step_waypoint_motion.h"

extern "C" {
void func_267C20(void *self, void *target);

#if defined(__mips__)
asm void func_001DF2D0(SpatialEntity *self, void *target) {
    .word 0x27BDFFD0 /* 001DF2D0: addiu $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* 001DF2D4: sq $ra, 0x20($sp) */
    .word 0x7FB10010 /* 001DF2D8: sq $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001DF2DC: sq $s0, 0x0($sp) */
    .word 0x8C830004 /* 001DF2E0: lw $v1, 0x4($a0) */
    .word 0x70A08628 /* 001DF2E4: paddub $s0, $a1, $zero */
    .word 0x8C860010 /* 001DF2E8: lw $a2, 0x10($a0) */
    .word 0x70808E28 /* 001DF2EC: paddub $s1, $a0, $zero */
    .word 0x8C6200A8 /* 001DF2F0: lw $v0, 0xA8($v1) */
    .word 0x14C20003 /* 001DF2F4: bne $a2, $v0, lbl_1DF304 */
    .word 0x70002E28 /* 001DF2F8: paddub $a1, $zero, $zero */
    .word 0x10000006 /* 001DF2FC: b lbl_1DF318 */
    .word 0x8E0500A8 /* 001DF300: lw $a1, 0xA8($s0) */
lbl_1DF304:
    .word 0x8C6200AC /* 001DF304: lw $v0, 0xAC($v1) */
    .word 0x14C20003 /* 001DF308: bne $a2, $v0, lbl_1DF318 */
    .word 0x00000000 /* 001DF30C: nop */
    .word 0x8E0500AC /* 001DF310: lw $a1, 0xAC($s0) */
    .word 0x00000000 /* 001DF314: nop */
lbl_1DF318:
    .word 0x10A00006 /* 001DF318: beqz $a1, lbl_1DF334 */
    .word 0x72202628 /* 001DF31C: paddub $a0, $s1, $zero */
    .word 0x8E390000 /* 001DF320: lw $t9, 0x0($s1) */
    .word 0x8F39004C /* 001DF324: lw $t9, 0x4C($t9) */
    jalr $t9
    .word 0x72202628 /* 001DF32C: paddub $a0, $s1, $zero */
    .word 0x72202628 /* 001DF330: paddub $a0, $s1, $zero */
lbl_1DF334:
    jal func_267C20
    .word 0x72002E28 /* 001DF338: paddub $a1, $s0, $zero */
    .word 0x7BBD0020 /* 001DF33C: lq $ra, 0x20($sp) */
    .word 0x7BB10010 /* 001DF340: lq $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001DF344: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001DF348: jr $ra */
    .word 0x27BD0030 /* 001DF34C: addiu $sp, $sp, 0x30 */
}
#else
struct SubTypeObj {
    char pad[0xA8];
    void *field_A8;
    void *field_AC;
};

struct TargetObj {
    char pad[0xA8];
    void *field_A8;
    void *field_AC;
};

struct SpatialEntity {
    void **vtable;
    SubTypeObj *sub_type;
    char pad_08[0x8];
    void *field_10;
};

void func_001DF2D0(SpatialEntity *self, void *target) {
    TargetObj *t = (TargetObj *)target;
    void *arg = 0;
    if (self->sub_type != 0) {
        if (self->field_10 == self->sub_type->field_A8) {
            arg = t->field_A8;
        } else if (self->field_10 == self->sub_type->field_AC) {
            arg = t->field_AC;
        }
    }

    if (arg != 0) {
        typedef void (*Method4cFn)(SpatialEntity *, void *);
        Method4cFn m4c = (Method4cFn)self->vtable[0x4C / 4];
        m4c(self, arg);
    }

    func_267C20(self, target);
}
#endif
}
