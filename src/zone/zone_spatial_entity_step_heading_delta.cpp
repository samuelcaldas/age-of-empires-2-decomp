#pragma exceptions off

#include "zone_spatial_entity_step_heading_delta.h"

extern "C" {
void func_314FE0(void *out, const void *in, float scale);

#if defined(__mips__)
asm void func_001E0000(SpatialEntity *self, float val) {
    .word 0xC7808064 /* 001E0000: lwc1 $f0, -0x7F9C($gp) */
    .word 0x27BDFFC0 /* 001E0004: addiu $sp, $sp, -0x40 */
    .word 0x46006046 /* 001E0008: mov.s $f1, $f12 */
    .word 0x46000845 /* 001E000C: abs.s $f1, $f1 */
    .word 0x7FBF0010 /* 001E0010: sq $ra, 0x10($sp) */
    .word 0x7FB00000 /* 001E0014: sq $s0, 0x0($sp) */
    .word 0x46000834 /* 001E0018: c.lt.s $f1, $f0 */
    .word 0x00000000 /* 001E001C: nop */
    .word 0x4501001D /* 001E0020: bc1t lbl_1E0098 */
    .word 0x70808628 /* 001E0024: paddub $s0, $a0, $zero */
    .word 0xC6000090 /* 001E0028: lwc1 $f0, 0x90($s0) */
    .word 0x27A40030 /* 001E002C: addiu $a0, $sp, 0x30 */
    .word 0x2605009C /* 001E0030: addiu $a1, $s0, 0x9C */
    .word 0xE7A00020 /* 001E0034: swc1 $f0, 0x20($sp) */
    .word 0xC6000094 /* 001E0038: lwc1 $f0, 0x94($s0) */
    .word 0xE7A00024 /* 001E003C: swc1 $f0, 0x24($sp) */
    .word 0xC6000098 /* 001E0040: lwc1 $f0, 0x98($s0) */
    jal func_314FE0
    .word 0xE7A00028 /* 001E0048: swc1 $f0, 0x28($sp) */
    .word 0xC7A30020 /* 001E004C: lwc1 $f3, 0x20($sp) */
    .word 0xC7A20030 /* 001E0050: lwc1 $f2, 0x30($sp) */
    .word 0xC7A10034 /* 001E0054: lwc1 $f1, 0x34($sp) */
    .word 0xC7A00038 /* 001E0058: lwc1 $f0, 0x38($sp) */
    .word 0x46021880 /* 001E005C: add.s $f2, $f3, $f2 */
    .word 0xE7A20020 /* 001E0060: swc1 $f2, 0x20($sp) */
    .word 0xC7A20024 /* 001E0064: lwc1 $f2, 0x24($sp) */
    .word 0x46011040 /* 001E0068: add.s $f1, $f2, $f1 */
    .word 0xE7A10024 /* 001E006C: swc1 $f1, 0x24($sp) */
    .word 0xC7A10028 /* 001E0070: lwc1 $f1, 0x28($sp) */
    .word 0x46000800 /* 001E0074: add.s $f0, $f1, $f0 */
    .word 0xE7A00028 /* 001E0078: swc1 $f0, 0x28($sp) */
    .word 0x8E190000 /* 001E007C: lw $t9, 0x0($s0) */
    .word 0xC7AC0020 /* 001E0080: lwc1 $f12, 0x20($sp) */
    .word 0xC7AD0028 /* 001E0084: lwc1 $f13, 0x28($sp) */
    .word 0xC7AE0024 /* 001E0088: lwc1 $f14, 0x24($sp) */
    .word 0x8F390044 /* 001E008C: lw $t9, 0x44($t9) */
    .word 0x0320F809 /* 001E0090: jalr $t9 */
    .word 0x72002628 /* 001E0094: paddub $a0, $s0, $zero */
lbl_1E0098:
    .word 0x7BBD0010 /* 001E0098: lq $ra, 0x10($sp) */
    .word 0x7BB00000 /* 001E009C: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001E00A0: jr $ra */
    .word 0x27BD0040 /* 001E00A4: addiu $sp, $sp, 0x40 */
}
#else
struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    virtual void m00();
    virtual void m04();
    virtual void m08();
    virtual void m0c();
    virtual void m10();
    virtual void m14();
    virtual void m18();
    virtual void m1c();
    virtual void m20();
    virtual void m24();
    virtual void m28();
    virtual void m2c();
    virtual void m30();
    virtual void m34();
    virtual void m38();
    virtual void m3c();
    virtual void m40();
    virtual void method44(float x, float z, float y);

    char pad0[0x90 - 4];
    Vector3 pos;
    Vector3 direction;
};

void func_001E0000(SpatialEntity *self, float val) {
    float abs_val = (val < 0.0f) ? -val : val;
    if (abs_val < 0.00001f) {
        return;
    }

    Vector3 delta;
    func_314FE0(&delta, &self->direction, val);

    Vector3 new_pos;
    new_pos.x = self->pos.x + delta.x;
    new_pos.y = self->pos.y + delta.y;
    new_pos.z = self->pos.z + delta.z;

    self->method44(new_pos.x, new_pos.z, new_pos.y);
}
#endif
}
