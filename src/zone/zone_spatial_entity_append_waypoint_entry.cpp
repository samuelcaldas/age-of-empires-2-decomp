#pragma exceptions off

#include "zone_spatial_entity_append_waypoint_entry.h"

extern "C" {
void *func_1FCE30(void *sub);
int func_1FCE00(void *sub);
void *func_3334A0(void *obj, int id);
void func_1FD910(void *p0, void *p1);
extern void *D_004E3180;

#if defined(__mips__)
asm float func_001DF060(SpatialEntity *self, void *vec) {
    .word 0x27BDFFD0 /* 001DF060: addiu $sp, $sp, -0x30 */
    .word 0x7FBF0010 /* 001DF064: sq $ra, 0x10($sp) */
    .word 0x7FB00000 /* 001DF068: sq $s0, 0x0($sp) */
    .word 0xC4A20000 /* 001DF06C: lwc1 $f2, 0x0($a1) */
    .word 0xC4A10004 /* 001DF070: lwc1 $f1, 0x4($a1) */
    .word 0xC4A00008 /* 001DF074: lwc1 $f0, 0x8($a1) */
    .word 0x27A20020 /* 001DF078: addiu $v0, $sp, 0x20 */
    .word 0x70808628 /* 001DF07C: paddub $s0, $a0, $zero */
    .word 0xE4420000 /* 001DF080: swc1 $f2, 0x0($v0) */
    .word 0xE4410004 /* 001DF084: swc1 $f1, 0x4($v0) */
    .word 0xE4400008 /* 001DF088: swc1 $f0, 0x8($v0) */
    .word 0x8C8400B4 /* 001DF08C: lw $a0, 0xB4($a0) */
    .word 0x14800004 /* 001DF090: bnez $a0, lbl_1DF0A4 */
    .word 0x00000000 /* 001DF094: nop */
    .word 0x44800000 /* 001DF098: mtc1 $zero, $f0 */
    .word 0x10000015 /* 001DF09C: b lbl_1DF0F4 */
    .word 0x7BBD0010 /* 001DF0A0: lq $ra, 0x10($sp) */
lbl_1DF0A4:
    jal func_1FCE30
    .word 0x00000000 /* 001DF0A8: nop */
    .word 0x14400008 /* 001DF0AC: bnez $v0, lbl_1DF0D0 */
    .word 0x00000000 /* 001DF0B0: nop */
    .word 0x8E0400B4 /* 001DF0B4: lw $a0, 0xB4($s0) */
    .word 0x8F8289C0 /* 001DF0B8: lw $v0, -0x7640($gp) */
    jal func_1FCE00
    .word 0x8C500404 /* 001DF0C0: lw $s0, 0x404($v0) */
    .word 0x72002628 /* 001DF0C4: paddub $a0, $s0, $zero */
    jal func_3334A0
    .word 0x70402E28 /* 001DF0CC: paddub $a1, $v0, $zero */
lbl_1DF0D0:
    .word 0x14400005 /* 001DF0D0: bnez $v0, lbl_1DF0E8 */
    .word 0x27A50020 /* 001DF0D4: addiu $a1, $sp, 0x20 */
    .word 0x44800000 /* 001DF0D8: mtc1 $zero, $f0 */
    .word 0x10000004 /* 001DF0DC: b lbl_1DF0F0 */
    .word 0x00000000 /* 001DF0E0: nop */
    .word 0x27A50020 /* 001DF0E4: addiu $a1, $sp, 0x20 */
lbl_1DF0E8:
    jal func_1FD910
    .word 0x70402628 /* 001DF0EC: paddub $a0, $v0, $zero */
lbl_1DF0F0:
    .word 0x7BBD0010 /* 001DF0F0: lq $ra, 0x10($sp) */
lbl_1DF0F4:
    .word 0x7BB00000 /* 001DF0F4: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001DF0F8: jr $ra */
    .word 0x27BD0030 /* 001DF0FC: addiu $sp, $sp, 0x30 */
}
#else
struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad[0xB4];
    void *field_B4;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

float func_001DF060(SpatialEntity *self, void *vec) {
    Vector3 copy = *(Vector3 *)vec;
    if (self->field_B4 != 0) {
        void *v0 = func_1FCE30(self->field_B4);
        if (v0 == 0) {
            GlobalContext *ctx = (GlobalContext *)D_004E3180;
            int id = func_1FCE00(self->field_B4);
            v0 = func_3334A0(ctx->field_404, id);
        }
        if (v0 != 0) {
            func_1FD910(v0, &copy);
        }
    }
    return 0.0f;
}
#endif
}
