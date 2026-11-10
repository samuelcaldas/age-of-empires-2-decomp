#pragma exceptions off

#include "zone_spatial_entity_free_waypoint_buffer.h"

extern "C" {
void *func_1FCE30(void *sub);
int func_1FCE00(void *sub);
void *func_3334A0(void *obj, int id);
void *func_1FC6C0(int arg);
void func_1FDAD0(void *sub, void *buf);
extern void *D_004E3180;

#if defined(__mips__)
asm void *func_001DEEE0(SpatialEntity *self, void **out_ptr) {
    .word 0x27BDFFB0 /* 001DEEE0: addiu $sp, $sp, -0x50 */
    .word 0x7FBF0040 /* 001DEEE4: sq $ra, 0x40($sp) */
    .word 0x7FB30030 /* 001DEEE8: sq $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001DEEEC: sq $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001DEEF0: sq $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001DEEF4: sq $s0, 0x0($sp) */
    .word 0xACA00000 /* 001DEEF8: sw $zero, 0x0($a1) */
    .word 0x70809E28 /* 001DEEFC: paddub $s3, $a0, $zero */
    .word 0x8C8400B4 /* 001DEF00: lw $a0, 0xB4($a0) */
    .word 0x14800003 /* 001DEF04: bnez $a0, lbl_1DEF14 */
    .word 0x70A08628 /* 001DEF08: paddub $s0, $a1, $zero */
    .word 0x10000026 /* 001DEF0C: b lbl_1DEFA8 */
    .word 0x70001628 /* 001DEF10: paddub $v0, $zero, $zero */
lbl_1DEF14:
    jal func_1FCE30
    .word 0x00000000 /* 001DEF18: nop */
    .word 0x70408E28 /* 001DEF1C: paddub $s1, $v0, $zero */
    .word 0x1620000E /* 001DEF20: bnez $s1, lbl_1DEF5C */
    .word 0x2404FFFF /* 001DEF24: addiu $a0, $zero, -0x1 */
    .word 0x8F8289C0 /* 001DEF28: lw $v0, -0x7640($gp) */
    .word 0x8C510404 /* 001DEF2C: lw $s1, 0x404($v0) */
    jal func_1FCE00
    .word 0x8E6400B4 /* 001DEF34: lw $a0, 0xB4($s3) */
    .word 0x72202628 /* 001DEF38: paddub $a0, $s1, $zero */
    jal func_3334A0
    .word 0x70402E28 /* 001DEF40: paddub $a1, $v0, $zero */
    .word 0x70408E28 /* 001DEF44: paddub $s1, $v0, $zero */
    .word 0x16200003 /* 001DEF48: bnez $s1, lbl_1DEF58 */
    .word 0x00000000 /* 001DEF4C: nop */
    .word 0x10000015 /* 001DEF50: b lbl_1DEFA8 */
    .word 0x70001628 /* 001DEF54: paddub $v0, $zero, $zero */
lbl_1DEF58:
    .word 0x2404FFFF /* 001DEF58: addiu $a0, $zero, -0x1 */
lbl_1DEF5C:
    jal func_1FC6C0
    .word 0x00000000 /* 001DEF60: nop */
    .word 0x70409628 /* 001DEF64: paddub $s2, $v0, $zero */
    .word 0x16400004 /* 001DEF68: bnez $s2, lbl_1DEF7C */
    .word 0x72202628 /* 001DEF6C: paddub $a0, $s1, $zero */
    .word 0x1000000D /* 001DEF70: b lbl_1DEFA8 */
    .word 0x70001628 /* 001DEF74: paddub $v0, $zero, $zero */
    .word 0x72202628 /* 001DEF78: paddub $a0, $s1, $zero */
lbl_1DEF7C:
    jal func_1FDAD0
    .word 0x72402E28 /* 001DEF80: paddub $a1, $s2, $zero */
    .word 0x10000002 /* 001DEF84: b lbl_1DEF90 */
    .word 0x8E6200B4 /* 001DEF88: lw $v0, 0xB4($s3) */
    .word 0x70601628 /* 001DEF8C: paddub $v0, $v1, $zero */
lbl_1DEF90:
    .word 0x8C430004 /* 001DEF90: lw $v1, 0x4($v0) */
    .word 0x5460FFFE /* 001DEF94: bnel $v1, $zero, lbl_1DEF90 */
    .word 0x70601628 /* 001DEF98: paddub $v0, $v1, $zero */
    .word 0x8C430010 /* 001DEF9C: lw $v1, 0x10($v0) */
    .word 0x72401628 /* 001DEFA0: paddub $v0, $s2, $zero */
    .word 0xAE030000 /* 001DEFA4: sw $v1, 0x0($s0) */
lbl_1DEFA8:
    .word 0x7BBD0040 /* 001DEFA8: lq $ra, 0x40($sp) */
    .word 0x7BB30030 /* 001DEFAC: lq $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001DEFB0: lq $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001DEFB4: lq $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001DEFB8: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001DEFBC: jr $ra */
    .word 0x27BD0050 /* 001DEFC0: addiu $sp, $sp, 0x50 */
}
#else
struct ListNode {
    void *pad0;
    ListNode *next;
    char pad_08[0x8];
    void *val_10;
};

struct SpatialEntity {
    char pad[0xB4];
    ListNode *field_B4;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

void *func_001DEEE0(SpatialEntity *self, void **out_ptr) {
    *out_ptr = 0;
    if (self->field_B4 == 0) {
        return 0;
    }

    void *s1 = func_1FCE30(self->field_B4);
    if (s1 == 0) {
        GlobalContext *ctx = (GlobalContext *)D_004E3180;
        int id = func_1FCE00(self->field_B4);
        s1 = func_3334A0(ctx->field_404, id);
        if (s1 == 0) {
            return 0;
        }
    }

    void *s2 = func_1FC6C0(-1);
    if (s2 == 0) {
        return 0;
    }

    func_1FDAD0(s1, s2);

    ListNode *node = self->field_B4;
    while (node->next != 0) {
        node = node->next;
    }

    *out_ptr = node->val_10;
    return s2;
}
#endif
}
