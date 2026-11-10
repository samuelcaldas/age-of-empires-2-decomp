#pragma exceptions off

#include "zone_spatial_grid_realloc_buffer.h"

extern "C" {
void *func_100730(unsigned int size);
void func_100630(void *ptr);
void *func_117AF8(void *dst, const void *src, int n);

#if defined(__mips__)
asm void func_001E5390(GridBuffer *self, int new_count) {
    .word 0x27BDFFC0 /* 001E5390: addiu $sp, $sp, -0x40 */
    .word 0x7FBF0030 /* 001E5394: sq $ra, 0x30($sp) */
    .word 0x7FB20020 /* 001E5398: sq $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001E539C: sq $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001E53A0: sq $s0, 0x0($sp) */
    .word 0xAC850000 /* 001E53A4: sw $a1, 0x0($a0) */
    .word 0x8C830008 /* 001E53A8: lw $v1, 0x8($a0) */
    .word 0x0065082A /* 001E53AC: slt $at, $v1, $a1 */
    .word 0x10200022 /* 001E53B0: beqz $at, lbl_1E543C */
    .word 0x70808628 /* 001E53B4: paddub $s0, $a0, $zero */
    .word 0x24620020 /* 001E53B8: addiu $v0, $v1, 0x20 */
    .word 0xAE020008 /* 001E53BC: sw $v0, 0x8($s0) */
    .word 0x8E020008 /* 001E53C0: lw $v0, 0x8($s0) */
    .word 0x000210F8 /* 001E53C4: dsll $v0, $v0, 3 */
    .word 0x0002203C /* 001E53C8: dsll32 $a0, $v0, 0 */
    jal func_100730
    .word 0x0004203F /* 001E53D0: dsra32 $a0, $a0, 0 */
    .word 0x70408E28 /* 001E53D4: paddub $s1, $v0, $zero */
    .word 0x8E020008 /* 001E53D8: lw $v0, 0x8($s0) */
    .word 0x000210B8 /* 001E53DC: dsll $v0, $v0, 2 */
    .word 0x0002203C /* 001E53E0: dsll32 $a0, $v0, 0 */
    jal func_100730
    .word 0x0004203F /* 001E53E8: dsra32 $a0, $a0, 0 */
    .word 0x8E050004 /* 001E53EC: lw $a1, 0x4($s0) */
    .word 0x10A00007 /* 001E53F0: beqz $a1, lbl_1E5410 */
    .word 0x70409628 /* 001E53F4: paddub $s2, $v0, $zero */
    .word 0x8E020000 /* 001E53F8: lw $v0, 0x0($s0) */
    .word 0x72202628 /* 001E53FC: paddub $a0, $s1, $zero */
    jal func_117AF8
    .word 0x000230C0 /* 001E5404: sll $a2, $v0, 3 */
    jal func_100630
    .word 0x8E040004 /* 001E540C: lw $a0, 0x4($s0) */
lbl_1E5410:
    .word 0xAE110004 /* 001E5410: sw $s1, 0x4($s0) */
    .word 0x8E05000C /* 001E5414: lw $a1, 0xC($s0) */
    .word 0x10A00007 /* 001E5418: beqz $a1, lbl_1E5438 */
    .word 0x00000000 /* 001E541C: nop */
    .word 0x8E020000 /* 001E5420: lw $v0, 0x0($s0) */
    .word 0x72402628 /* 001E5424: paddub $a0, $s2, $zero */
    jal func_117AF8
    .word 0x00023080 /* 001E542C: sll $a2, $v0, 2 */
    jal func_100630
    .word 0x8E04000C /* 001E5434: lw $a0, 0xC($s0) */
lbl_1E5438:
    .word 0xAE12000C /* 001E5438: sw $s2, 0xC($s0) */
lbl_1E543C:
    .word 0x7BBD0030 /* 001E543C: lq $ra, 0x30($sp) */
    .word 0x7BB20020 /* 001E5440: lq $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001E5444: lq $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001E5448: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001E544C: jr $ra */
    .word 0x27BD0040 /* 001E5450: addiu $sp, $sp, 0x40 */
}
#else
struct GridBuffer {
    int count;      // 0x00
    void *buf_8byte;// 0x04
    int capacity;   // 0x08
    void *buf_4byte;// 0x0C
};

void func_001E5390(GridBuffer *self, int new_count) {
    self->count = new_count;
    if (self->capacity < new_count) {
        self->capacity += 0x20;
        void *new_b8 = func_100730((unsigned int)(self->capacity * 8));
        void *new_b4 = func_100730((unsigned int)(self->capacity * 4));

        if (self->buf_8byte != 0) {
            func_117AF8(new_b8, self->buf_8byte, self->count * 8);
            func_100630(self->buf_8byte);
        }
        self->buf_8byte = new_b8;

        if (self->buf_4byte != 0) {
            func_117AF8(new_b4, self->buf_4byte, self->count * 4);
            func_100630(self->buf_4byte);
        }
        self->buf_4byte = new_b4;
    }
}
#endif
}
