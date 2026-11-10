#pragma exceptions off

#include "zone_spatial_entity_copy_waypoint_list.h"

extern "C" {
void *func_1FCE30(void *sub);
int func_1FCE00(void *sub);
void *func_3334A0(void *obj, int id);
void func_1FD910(void *p0, void *p1);
extern void *D_004E3180;

#if defined(__mips__)
asm float func_001DEFD0(SpatialEntity *self, void *src) {
    .word 0x27BDFFD0 /* 001DEFD0: addiu $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* 001DEFD4: sq $ra, 0x20($sp) */
    .word 0x7FB10010 /* 001DEFD8: sq $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001DEFDC: sq $s0, 0x0($sp) */
    .word 0x70808E28 /* 001DEFE0: paddub $s1, $a0, $zero */
    .word 0x8C8400B4 /* 001DEFE4: lw $a0, 0xB4($a0) */
    .word 0x14800004 /* 001DEFE8: bnez $a0, lbl_1DEFFC */
    .word 0x00000000 /* 001DEFEC: nop */
    .word 0x44800000 /* 001DEFF0: mtc1 $zero, $f0 */
    .word 0x10000015 /* 001DEFF4: b lbl_1DF04C */
    .word 0x7BBF0020 /* 001DEFF8: lq $ra, 0x20($sp) */
lbl_1DEFFC:
    jal func_1FCE30
    .word 0x00000000 /* 001DF000: nop */
    .word 0x14400008 /* 001DF004: bnez $v0, lbl_1DF028 */
    .word 0x00000000 /* 001DF008: nop */
    .word 0x8F8289C0 /* 001DF00C: lw $v0, -0x7640($gp) */
    .word 0x8C500404 /* 001DF010: lw $s0, 0x404($v0) */
    jal func_1FCE00
    .word 0x8E2400B4 /* 001DF018: lw $a0, 0xB4($s1) */
    .word 0x72002628 /* 001DF01C: paddub $a0, $s0, $zero */
    jal func_3334A0
    .word 0x70402E28 /* 001DF024: paddub $a1, $v0, $zero */
lbl_1DF028:
    .word 0x14400005 /* 001DF028: bnez $v0, lbl_1DF040 */
    .word 0x26250090 /* 001DF02C: addiu $a1, $s1, 0x90 */
    .word 0x44800000 /* 001DF030: mtc1 $zero, $f0 */
    .word 0x10000004 /* 001DF034: b lbl_1DF048 */
    .word 0x00000000 /* 001DF038: nop */
    .word 0x26250090 /* 001DF03C: addiu $a1, $s1, 0x90 */
lbl_1DF040:
    jal func_1FD910
    .word 0x70402628 /* 001DF044: paddub $a0, $v0, $zero */
lbl_1DF048:
    .word 0x7BBF0020 /* 001DF048: lq $ra, 0x20($sp) */
lbl_1DF04C:
    .word 0x7BB10010 /* 001DF04C: lq $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001DF050: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001DF054: jr $ra */
    .word 0x27BD0030 /* 001DF058: addiu $sp, $sp, 0x30 */
}
#else
struct SpatialEntity {
    char pad0[0x90];
    int field_90;
    char pad94[0x20];
    void *field_B4;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

float func_001DEFD0(SpatialEntity *self, void *src) {
    if (self->field_B4 != 0) {
        void *v0 = func_1FCE30(self->field_B4);
        if (v0 == 0) {
            GlobalContext *ctx = (GlobalContext *)D_004E3180;
            int id = func_1FCE00(self->field_B4);
            v0 = func_3334A0(ctx->field_404, id);
        }
        if (v0 != 0) {
            func_1FD910(v0, (char *)self + 0x90);
        }
    }
    return 0.0f;
}
#endif
}
