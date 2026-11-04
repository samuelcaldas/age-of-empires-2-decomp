#pragma exceptions off

#include "zone_spatial_entity_query_status.h"

extern "C" {
float func_267380(void *self);
void func_26AD30(void *self, int flag, int val);
void func_26AD60(void *self, int flag);

#if defined(__mips__)
asm float func_001DD660(SpatialEntity *self, float val) {
    .word 0x27BDFFD0 /* 001DD660: addiu $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* 001DD664: sq $ra, 0x20($sp) */
    .word 0x7FB00010 /* 001DD668: sq $s0, 0x10($sp) */
    .word 0xE7B40000 /* 001DD66C: swc1 $f20, 0x0($sp) */
    .word 0x70808628 /* 001DD670: paddub $s0, $a0, $zero */
    jal func_267380
    .word 0x46006506 /* 001DD678: mov.s $f20, $f12 */
    .word 0x4600A032 /* 001DD67C: c.eq.s $f20, $f0 */
    .word 0x00000000 /* 001DD680: nop */
    .word 0x45000008 /* 001DD684: bc1f lbl_1DD6A8 */
    .word 0x24050020 /* 001DD688: addiu $a1, $zero, 0x20 */
    .word 0x24050020 /* 001DD68C: addiu $a1, $zero, 0x20 */
    .word 0x24060001 /* 001DD690: addiu $a2, $zero, 0x1 */
    jal func_26AD30
    .word 0x72002628 /* 001DD698: paddub $a0, $s0, $zero */
    .word 0x10000005 /* 001DD69C: b lbl_1DD6B4 */
    .word 0x8E020018 /* 001DD6A0: lw $v0, 0x18($s0) */
lbl_1DD6A8:
    jal func_26AD60
    .word 0x72002628 /* 001DD6AC: paddub $a0, $s0, $zero */
    .word 0x8E020018 /* 001DD6B0: lw $v0, 0x18($s0) */
lbl_1DD6B4:
    .word 0x14400004 /* 001DD6B4: bnez $v0, lbl_1DD6C8 */
    .word 0x00000000 /* 001DD6B8: nop */
    .word 0x24050020 /* 001DD6BC: addiu $a1, $zero, 0x20 */
    jal func_26AD60
    .word 0x72002628 /* 001DD6C4: paddub $a0, $s0, $zero */
lbl_1DD6C8:
    .word 0xC600004C /* 001DD6C8: lwc1 $f0, 0x4C($s0) */
    .word 0x7BBD0020 /* 001DD6CC: lq $ra, 0x20($sp) */
    .word 0xC7B40000 /* 001DD6D0: lwc1 $f20, 0x0($sp) */
    .word 0x7BB00010 /* 001DD6D4: lq $s0, 0x10($sp) */
    .word 0x03E00008 /* 001DD6D8: jr $ra */
    .word 0x27BD0030 /* 001DD6DC: addiu $sp, $sp, 0x30 */
}
#else
struct SpatialEntity {
    char pad_00[0x18];
    int field_18;
    char pad_1C[0x4C - 0x1C];
    float return_val;
};

float func_001DD660(SpatialEntity *self, float val) {
    float prop = func_267380(self);
    if (val == prop) {
        func_26AD30(self, 0x20, 1);
    } else {
        func_26AD60(self, 0x20);
    }

    if (self->field_18 == 0) {
        func_26AD60(self, 0x20);
    }

    return self->return_val;
}
#endif
}
