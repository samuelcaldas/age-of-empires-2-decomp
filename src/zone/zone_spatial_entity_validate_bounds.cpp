#pragma exceptions off

#include "zone_spatial_entity_validate_bounds.h"

extern "C" {
void *func_332e60(void *mgr, int id);
void func_1FE340(void *p0, void *p1, void *p2, void *p3, int p4, int p5, int p6, int p7);

#if defined(__mips__)
asm int func_001DDBF0(SpatialEntity *self, int target_id, void *p2, void *p3, void *p4, void *p5, float f12) {
    .word 0x27BDFF60 /* 001DDBF0: addiu $sp, $sp, -0xA0 */
    .word 0x7FBF0080 /* 001DDBF4: sq $ra, 0x80($sp) */
    .word 0x7FB50070 /* 001DDBF8: sq $s5, 0x70($sp) */
    .word 0x7FB40060 /* 001DDBFC: sq $s4, 0x60($sp) */
    .word 0x7FB30050 /* 001DDC00: sq $s3, 0x50($sp) */
    .word 0x7FB20040 /* 001DDC04: sq $s2, 0x40($sp) */
    .word 0x7FB10030 /* 001DDC08: sq $s1, 0x30($sp) */
    .word 0x7FB00020 /* 001DDC0C: sq $s0, 0x20($sp) */
    .word 0xE7B40010 /* 001DDC10: swc1 $f20, 0x10($sp) */
    .word 0x2402FFFF /* 001DDC14: addiu $v0, $zero, -0x1 */
    .word 0x46006506 /* 001DDC18: mov.s $f20, $f12 */
    .word 0x70A0A628 /* 001DDC1C: paddub $s4, $a1, $zero */
    .word 0x7080AE28 /* 001DDC20: paddub $s5, $a0, $zero */
    .word 0x70C09E28 /* 001DDC24: paddub $s3, $a2, $zero */
    .word 0x70E09628 /* 001DDC28: paddub $s2, $a3, $zero */
    .word 0x71008E28 /* 001DDC2C: paddub $s1, $t0, $zero */
    .word 0x16820003 /* 001DDC30: bne $s4, $v0, lbl_1DDC40 */
    .word 0x71208628 /* 001DDC34: paddub $s0, $t1, $zero */
    .word 0x10000019 /* 001DDC38: b lbl_1DDCA0 */
    .word 0x70001628 /* 001DDC3C: paddub $v0, $zero, $zero */
lbl_1DDC40:
    .word 0x8EA20008 /* 001DDC40: lw $v0, 0x8($s5) */
    jal func_332e60
    .word 0x8C440B98 /* 001DDC48: lw $a0, 0xB98($v0) */
    .word 0x14400003 /* 001DDC4C: bnez $v0, lbl_1DDC5C */
    .word 0x00000000 /* 001DDC50: nop */
    .word 0x10000012 /* 001DDC54: b lbl_1DDCA0 */
    .word 0x70001628 /* 001DDC58: paddub $v0, $zero, $zero */
lbl_1DDC5C:
    .word 0x8C590000 /* 001DDC5C: lw $t9, 0x0($v0) */
    .word 0x27A40090 /* 001DDC60: addiu $a0, $sp, 0x90 */
    .word 0x8F390220 /* 001DDC64: lw $t9, 0x220($t9) */
    jalr $t9
    .word 0x70402E28 /* 001DDC6C: paddub $a1, $v0, $zero */
    .word 0x26A60090 /* 001DDC70: addiu $a2, $s5, 0x90 */
    .word 0x4600A306 /* 001DDC74: mov.s $f12, $f20 */
    .word 0xFFA00000 /* 001DDC78: sd $zero, 0x0($sp) */
    .word 0x27A70090 /* 001DDC7C: addiu $a3, $sp, 0x90 */
    .word 0x240B0001 /* 001DDC80: addiu $t3, $zero, 0x1 */
    .word 0x72802E28 /* 001DDC84: paddub $a1, $s4, $zero */
    .word 0x72604628 /* 001DDC88: paddub $t0, $s3, $zero */
    .word 0x72404E28 /* 001DDC8C: paddub $t1, $s2, $zero */
    .word 0x72205628 /* 001DDC90: paddub $t2, $s1, $zero */
    .word 0x72A02628 /* 001DDC94: paddub $a0, $s5, $zero */
    jal func_1FE340
    .word 0xFFB00008 /* 001DDC9C: sd $s0, 0x8($sp) */
lbl_1DDCA0:
    .word 0x7BBF0080 /* 001DDCA0: lq $ra, 0x80($sp) */
    .word 0x7BB50070 /* 001DDCA4: lq $s5, 0x70($sp) */
    .word 0x7BB40060 /* 001DDCA8: lq $s4, 0x60($sp) */
    .word 0x7BB30050 /* 001DDCAC: lq $s3, 0x50($sp) */
    .word 0x7BB20040 /* 001DDCB0: lq $s2, 0x40($sp) */
    .word 0x7BB10030 /* 001DDCB4: lq $s1, 0x30($sp) */
    .word 0x7BB00020 /* 001DDCB8: lq $s0, 0x20($sp) */
    .word 0xC7B40010 /* 001DDCBC: lwc1 $f20, 0x10($sp) */
    .word 0x03E00008 /* 001DDCC0: jr $ra */
    .word 0x27BD00A0 /* 001DDCC4: addiu $sp, $sp, 0xA0 */
}
#else
struct Vector3 {
    float x;
    float y;
    float z;
};

struct WorldObj {
    char pad[0xB98];
    void *m_b98;
};

struct SpatialEntity {
    char pad[0x8];
    WorldObj *world;
    char pad_0c[0x84];
    Vector3 pos; // 0x90
};

int func_001DDBF0(SpatialEntity *self, int target_id, void *p2, void *p3, void *p4, void *p5, float f12) {
    if (target_id == -1) {
        return 0;
    }
    void *target = 0;
    if (self->world != 0) {
        target = func_332e60(self->world->m_b98, target_id);
    }
    if (target == 0) {
        return 0;
    }

    typedef void (*Method220Fn)(void *, void *);
    Method220Fn m220 = (Method220Fn)(*(void ***)target)[0x220 / 4];
    Vector3 target_pos;
    m220(target, &target_pos);

    func_1FE340(self, (void *)target_id, &self->pos, &target_pos, 0, 0, 0, 0);
    return 0;
}
#endif
}
