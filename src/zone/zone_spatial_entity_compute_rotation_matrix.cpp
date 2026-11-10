#pragma exceptions off

#include <cmath>
#include "zone_spatial_entity_compute_rotation_matrix.h"

extern "C" {
extern void *D_938FC0;
void func_1D7ED0(void *out_matrix, const void *axis, float angle);
void func_1D8000(void *out_vec, const void *matrix, const void *in_vec);

#if defined(__mips__)
asm void func_001E00F0(SpatialEntity *self) {
    .word 0x27BDFF90 /* 001E00F0: addiu $sp, $sp, -0x70 */
    .word 0x7FBF0010 /* 001E00F4: sq $ra, 0x10($sp) */
    .word 0x7FB00000 /* 001E00F8: sq $s0, 0x0($sp) */
    .word 0x70808628 /* 001E00FC: paddub $s0, $a0, $zero */
    .word 0x3C020000 /* 001E0100: lui $v0, %hi(D_938FC0) */
    .word 0x27A40020 /* 001E0104: addiu $a0, $sp, 0x20 */
    jal func_1D7ED0
    .word 0x24450000 /* 001E010C: addiu $a1, $v0, %lo(D_938FC0) */
    .word 0x27A40050 /* 001E0110: addiu $a0, $sp, 0x50 */
    .word 0x27A50020 /* 001E0114: addiu $a1, $sp, 0x20 */
    jal func_1D8000
    .word 0x2606009C /* 001E011C: addiu $a2, $s0, 0x9C */
    .word 0x27A20050 /* 001E0120: addiu $v0, $sp, 0x50 */
    .word 0xC4420000 /* 001E0124: lwc1 $f2, 0x0($v0) */
    .word 0xC4410004 /* 001E0128: lwc1 $f1, 0x4($v0) */
    .word 0xC4400008 /* 001E012C: lwc1 $f0, 0x8($v0) */
    .word 0x27A40060 /* 001E0130: addiu $a0, $sp, 0x60 */
    .word 0x27A50020 /* 001E0134: addiu $a1, $sp, 0x20 */
    .word 0x260600A8 /* 001E0138: addiu $a2, $s0, 0xA8 */
    .word 0xE602009C /* 001E013C: swc1 $f2, 0x9C($s0) */
    .word 0xE60100A0 /* 001E0140: swc1 $f1, 0xA0($s0) */
    jal func_1D8000
    .word 0xE60000A4 /* 001E0148: swc1 $f0, 0xA4($s0) */
    .word 0x27A20060 /* 001E014C: addiu $v0, $sp, 0x60 */
    .word 0xC4420000 /* 001E0150: lwc1 $f2, 0x0($v0) */
    .word 0xC4410004 /* 001E0154: lwc1 $f1, 0x4($v0) */
    .word 0xC4400008 /* 001E0158: lwc1 $f0, 0x8($v0) */
    .word 0x2605009C /* 001E015C: addiu $a1, $s0, 0x9C */
    .word 0x72002628 /* 001E0160: paddub $a0, $s0, $zero */
    .word 0xE60200A8 /* 001E0164: swc1 $f2, 0xA8($s0) */
    .word 0xE60100AC /* 001E0168: swc1 $f1, 0xAC($s0) */
    .word 0xE60000B0 /* 001E016C: swc1 $f0, 0xB0($s0) */
    .word 0xC603009C /* 001E0170: lwc1 $f3, 0x9C($s0) */
    .word 0xC60100A0 /* 001E0174: lwc1 $f1, 0xA0($s0) */
    .word 0x3C020000 /* 001E0178: lui $v0, %hi(D_938FC0) */
    .word 0xC60000A4 /* 001E017C: lwc1 $f0, 0xA4($s0) */
    .word 0x46031882 /* 001E0180: mul.s $f2, $f3, $f3 */
    .word 0x46010842 /* 001E0184: mul.s $f1, $f1, $f1 */
    .word 0x46011018 /* 001E0188: adda.s $f2, $f1 */
    .word 0x4600005C /* 001E018C: madd.s $f1, $f0, $f0 */
    .word 0x46010044 /* 001E0190: c1 0x10044 */
    .word 0x46011803 /* 001E0194: div.s $f0, $f3, $f1 */
    .word 0xE600009C /* 001E0198: swc1 $f0, 0x9C($s0) */
    .word 0xC60000A0 /* 001E019C: lwc1 $f0, 0xA0($s0) */
    .word 0x46010003 /* 001E01A0: div.s $f0, $f0, $f1 */
    .word 0xE60000A0 /* 001E01A4: swc1 $f0, 0xA0($s0) */
    .word 0xC60000A4 /* 001E01A8: lwc1 $f0, 0xA4($s0) */
    .word 0x46010003 /* 001E01AC: div.s $f0, $f0, $f1 */
    .word 0xE60000A4 /* 001E01B0: swc1 $f0, 0xA4($s0) */
    .word 0xC60300A8 /* 001E01B4: lwc1 $f3, 0xA8($s0) */
    .word 0xC60100AC /* 001E01B8: lwc1 $f1, 0xAC($s0) */
    .word 0xC60000B0 /* 001E01BC: lwc1 $f0, 0xB0($s0) */
    .word 0x46031882 /* 001E01C0: mul.s $f2, $f3, $f3 */
    .word 0x46010842 /* 001E01C4: mul.s $f1, $f1, $f1 */
    .word 0x46011018 /* 001E01C8: adda.s $f2, $f1 */
    .word 0x4600005C /* 001E01CC: madd.s $f1, $f0, $f0 */
    .word 0x46010044 /* 001E01D0: c1 0x10044 */
    .word 0x46011803 /* 001E01D4: div.s $f0, $f3, $f1 */
    .word 0xE60000A8 /* 001E01D8: swc1 $f0, 0xA8($s0) */
    .word 0xC60000AC /* 001E01DC: lwc1 $f0, 0xAC($s0) */
    .word 0x46010003 /* 001E01E0: div.s $f0, $f0, $f1 */
    .word 0xE60000AC /* 001E01E4: swc1 $f0, 0xAC($s0) */
    .word 0xC60000B0 /* 001E01E8: lwc1 $f0, 0xB0($s0) */
    .word 0x46010003 /* 001E01EC: div.s $f0, $f0, $f1 */
    .word 0xE60000B0 /* 001E01F0: swc1 $f0, 0xB0($s0) */
    .word 0x8E190000 /* 001E01F4: lw $t9, 0x0($s0) */
    .word 0x8F390240 /* 001E01F8: lw $t9, 0x240($t9) */
    jalr $t9
    .word 0x24460000 /* 001E0200: addiu $a2, $v0, %lo(D_938FC0) */
    .word 0x8E030010 /* 001E0204: lw $v1, 0x10($s0) */
    .word 0x50600008 /* 001E0208: beql $v1, $zero, lbl_1E022C */
    .word 0x24030008 /* 001E020C: addiu $v1, $zero, 0x8 */
    .word 0x9063003A /* 001E0210: lbu $v1, 0x3A($v1) */
    .word 0x28610009 /* 001E0214: slti $at, $v1, 0x9 */
    .word 0x14200003 /* 001E0218: bnez $at, lbl_1E0228 */
    .word 0x00000000 /* 001E021C: nop */
    .word 0x10000002 /* 001E0220: b lbl_1E022C */
    .word 0x00000000 /* 001E0224: nop */
lbl_1E0228:
    .word 0x24030008 /* 001E0228: addiu $v1, $zero, 0x8 */
lbl_1E022C:
    .word 0x44830800 /* 001E022C: mtc1 $v1, $f1 */
    .word 0x92040035 /* 001E0230: lbu $a0, 0x35($s0) */
    .word 0xC780803C /* 001E0234: lwc1 $f0, -0x7FC4($gp) */
    .word 0x46800860 /* 001E0238: cvt.s.w $f1, $f1 */
    .word 0x0083182A /* 001E023C: slt $v1, $a0, $v1 */
    .word 0x14600003 /* 001E0240: bnez $v1, lbl_1E0250 */
    .word 0x46010043 /* 001E0244: div.s $f1, $f0, $f1 */
    .word 0x10000007 /* 001E0248: b lbl_1E0268 */
    .word 0xAE00007C /* 001E024C: sw $zero, 0x7C($s0) */
lbl_1E0250:
    .word 0x24830001 /* 001E0250: addiu $v1, $a0, 0x1 */
    .word 0x44830000 /* 001E0254: mtc1 $v1, $f0 */
    .word 0x00000000 /* 001E0258: nop */
    .word 0x46800020 /* 001E025C: cvt.s.w $f0, $f0 */
    .word 0x46000802 /* 001E0260: mul.s $f0, $f1, $f0 */
    .word 0xE600007C /* 001E0264: swc1 $f0, 0x7C($s0) */
lbl_1E0268:
    .word 0x7BBD0010 /* 001E0268: lq $ra, 0x10($sp) */
    .word 0x7BB00000 /* 001E026C: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001E0270: jr $ra */
    .word 0x27BD0070 /* 001E0274: addiu $sp, $sp, 0x70 */
}
#else
struct Vector3 {
    float x;
    float y;
    float z;
};

struct SubObj {
    char pad[0x3A];
    unsigned char count;
};

struct SpatialEntity {
    void **vtable;
    char pad_after_vtable[0x10 - 4];
    SubObj *sub_obj;
    char pad_14[0x35 - 0x14];
    unsigned char frame_index;
    char pad_36[0x7C - 0x36];
    float heading;
    char pad_80[0x9C - 0x80];
    Vector3 vec_9c;
    Vector3 vec_a8;
};

void func_001E00F0(SpatialEntity *self) {
    float rot_matrix[9];
    func_1D7ED0(rot_matrix, D_938FC0, 0.0f);

    Vector3 res_9c;
    func_1D8000(&res_9c, rot_matrix, &self->vec_9c);
    self->vec_9c = res_9c;

    Vector3 res_a8;
    func_1D8000(&res_a8, rot_matrix, &self->vec_a8);
    self->vec_a8 = res_a8;

    float len_9c = std::sqrt(self->vec_9c.x * self->vec_9c.x +
                             self->vec_9c.y * self->vec_9c.y +
                             self->vec_9c.z * self->vec_9c.z);
    self->vec_9c.x /= len_9c;
    self->vec_9c.y /= len_9c;
    self->vec_9c.z /= len_9c;

    float len_a8 = std::sqrt(self->vec_a8.x * self->vec_a8.x +
                             self->vec_a8.y * self->vec_a8.y +
                             self->vec_a8.z * self->vec_a8.z);
    self->vec_a8.x /= len_a8;
    self->vec_a8.y /= len_a8;
    self->vec_a8.z /= len_a8;

    typedef void (*Method240Fn)(SpatialEntity *, const void *, const void *);
    Method240Fn method240 = (Method240Fn)self->vtable[0x240 / 4];
    method240(self, &self->vec_9c, D_938FC0);

    int count = 8;
    if (self->sub_obj != 0) {
        count = self->sub_obj->count;
        if (count < 9) {
            count = 8;
        }
    }

    const float two_pi = 6.2831853f;
    float step = two_pi / (float)count;

    if (self->frame_index < count) {
        self->heading = step * (float)(self->frame_index + 1);
    } else {
        self->heading = 0.0f;
    }
}
#endif
}
