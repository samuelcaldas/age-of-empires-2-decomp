#pragma once
#pragma exceptions off

#include "zone_init_bucket_arrays.h"

extern "C" {
void func_1D07D0(void *self, void *bucket, int capacity);
void *func_100730(int bytes);

#if defined(__mips__)
asm void func_001D08E0(void *self, void *bucket, int size) {
    .word 0x27BDFFB0 /* 001D08E0 addiu $sp, $sp, -0x50 */
    .word 0x7FBF0040 /* 001D08E4 sq $ra, 0x40($sp) */
    .word 0x7FB30030 /* 001D08E8 sq $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D08EC sq $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D08F0 sq $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D08F4 sq $s0, 0x0($sp) */
    .word 0x8CA30010 /* 001D08F8 lw $v1, 0x10($a1) */
    .word 0x8CA20014 /* 001D08FC lw $v0, 0x14($a1) */
    .word 0x70C09628 /* 001D0900 paddub $s2, $a2, $zero */
    bne $v1, $v0, lbl_1D0914
    .word 0x70A09E28 /* 001D0908 paddub $s3, $a1, $zero */
    jal func_1D07D0
    .word 0x24660004 /* 001D0910 addiu $a2, $v1, 0x4 */
lbl_1D0914:
    .word 0x8E700010 /* 001D0914 lw $s0, 0x10($s3) */
    .word 0x26020001 /* 001D0918 addiu $v0, $s0, 0x1 */
    .word 0xAE620010 /* 001D091C sw $v0, 0x10($s3) */
    .word 0x8E630030 /* 001D0920 lw $v1, 0x30($s3) */
    .word 0x8E620008 /* 001D0924 lw $v0, 0x8($s3) */
    .word 0x00108880 /* 001D0928 sll $s1, $s0, 2 */
    .word 0x02431818 /* 001D092C mult $v1, $s2, $v1 */
    .word 0x00511021 /* 001D0930 addu $v0, $v0, $s1 */
    .word 0xAC520000 /* 001D0934 sw $s2, 0x0($v0) */
    .word 0x0003103C /* 001D0938 dsll32 $v0, $v1, 0 */
    .word 0x0002103F /* 001D093C dsra32 $v0, $v0, 0 */
    .word 0x000210B8 /* 001D0940 dsll $v0, $v0, 2 */
    .word 0x0002203C /* 001D0944 dsll32 $a0, $v0, 0 */
    jal func_100730
    .word 0x0004203F /* 001D094C dsra32 $a0, $a0, 0 */
    .word 0x8E640000 /* 001D0950 lw $a0, 0x0($s3) */
    .word 0x2403FFFF /* 001D0954 addiu $v1, $zero, -0x1 */
    .word 0x00912021 /* 001D0958 addu $a0, $a0, $s1 */
    .word 0xAC820000 /* 001D095C sw $v0, 0x0($a0) */
    .word 0x8E64003C /* 001D0960 lw $a0, 0x3C($s3) */
    .word 0x24840001 /* 001D0964 addiu $a0, $a0, 0x1 */
    .word 0xAE64003C /* 001D0968 sw $a0, 0x3C($s3) */
    .word 0x8E640024 /* 001D096C lw $a0, 0x24($s3) */
    .word 0x00922021 /* 001D0970 addu $a0, $a0, $s2 */
    .word 0xAE640024 /* 001D0974 sw $a0, 0x24($s3) */
    .word 0x8E640028 /* 001D0978 lw $a0, 0x28($s3) */
    .word 0x00922021 /* 001D097C addu $a0, $a0, $s2 */
    .word 0xAE640028 /* 001D0980 sw $a0, 0x28($s3) */
    .word 0x8E64001C /* 001D0984 lw $a0, 0x1C($s3) */
    bne $a0, $v1, lbl_1D0998
    .word 0x00000000 /* 001D098C nop */
    .word 0xAE70001C /* 001D0990 sw $s0, 0x1C($s3) */
    .word 0xAE600020 /* 001D0994 sw $zero, 0x20($s3) */
lbl_1D0998:
    .word 0x7BBF0040 /* 001D0998 lq $ra, 0x40($sp) */
    .word 0x7BB30030 /* 001D099C lq $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D09A0 lq $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D09A4 lq $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D09A8 lq $s0, 0x0($sp) */
    jr $ra
    .word 0x27BD0050 /* 001D09B0 addiu $sp, $sp, 0x50 */
    .word 0x00000000 /* 001D09B4 nop */
    .word 0x00000000 /* 001D09B8 nop */
    .word 0x00000000 /* 001D09BC nop */
}
#else
void func_001D08E0(void *self, void *bucket, int size) {
    char *b = (char *)bucket;
    int count = *(int *)(b + 0x10);
    int capacity = *(int *)(b + 0x14);

    if (count == capacity) {
        func_1D07D0(self, bucket, count + 4);
    }

    int idx = *(int *)(b + 0x10);
    *(int *)(b + 0x10) = idx + 1;

    *(int *)(*(char **)(b + 0x8) + idx * 4) = size;

    int factor = *(int *)(b + 0x30);
    int total_words = size * factor;
    void *buf = func_100730(total_words * 4);

    *(void **)(*(char **)(b + 0x0) + idx * 4) = buf;

    *(int *)(b + 0x3C) += 1;
    *(int *)(b + 0x24) += size;
    *(int *)(b + 0x28) += size;

    if (*(int *)(b + 0x1C) == -1) {
        *(int *)(b + 0x1C) = idx;
        *(int *)(b + 0x20) = 0;
    }
}
#endif
}
