#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x0021A680 */
extern "C" {
void func_0021E350();

asm void func_0021A680(void *self) {

    .word 0x27BDFFB0 /* addiu      $sp, $sp, -0x50 */
    .word 0x7FBF0040 /* sq         $ra, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x9C820098 /* lwu        $v0, 0x98($a0) */
    .word 0x8C92003C /* lw         $s2, 0x3C($a0) */
    .word 0x8C930054 /* lw         $s3, 0x54($a0) */
    .word 0x70808E28 /* paddub     $s1, $a0, $zero */
    .word 0x30420800 /* andi       $v0, $v0, 0x800 */
    .word 0x10400004 /* beqz       $v0, .L0021A6C0 */
    .word 0x70008628 /* paddub    $s0, $zero, $zero */
    .word 0x3C02000A /* lui        $v0, (0xA3000 >> 16) */
    .word 0x24120280 /* addiu      $s2, $zero, 0x280 */
    .word 0x34533000 /* ori        $s3, $v0, (0xA3000 & 0xFFFF) */
    .word 0x8E220014 /* lw         $v0, 0x14($s1) */
    .word 0x10400004 /* beqz       $v0, .L0021A6D8 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x94500002 /* lhu        $s0, 0x2($v0) */
    .word 0x00000000 /* nop */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    jal func_0021E350
    .word 0x00000000 /* nop */
    .word 0x00131983 /* sra        $v1, $s3, 6 */
    .word 0x0003203C /* dsll32     $a0, $v1, 0 */
    .word 0x00121983 /* sra        $v1, $s2, 6 */
    .word 0x0003183C /* dsll32     $v1, $v1, 0 */
    .word 0x0003183F /* dsra32     $v1, $v1, 0 */
    .word 0x0004203F /* dsra32     $a0, $a0, 0 */
    .word 0x00031BB8 /* dsll       $v1, $v1, 14 */
    .word 0x00833825 /* or         $a3, $a0, $v1 */
    .word 0x24040006 /* addiu      $a0, $zero, 0x6 */
    .word 0x8E26001C /* lw         $a2, 0x1C($s1) */
    .word 0x0004283C /* dsll32     $a1, $a0, 0 */
    .word 0x3404A800 /* ori        $a0, $zero, 0xA800 */
    .word 0x00042438 /* dsll       $a0, $a0, 16 */
    .word 0x00852025 /* or         $a0, $a0, $a1 */
    .word 0x3203000F /* andi       $v1, $s0, 0xF */
    .word 0x00062D38 /* dsll       $a1, $a2, 20 */
    .word 0x00A72825 /* or         $a1, $a1, $a3 */
    .word 0x00A42825 /* or         $a1, $a1, $a0 */
    .word 0x00022183 /* sra        $a0, $v0, 6 */
    .word 0x0004203C /* dsll32     $a0, $a0, 0 */
    .word 0x0003183C /* dsll32     $v1, $v1, 0 */
    .word 0x0004203F /* dsra32     $a0, $a0, 0 */
    .word 0x0003183F /* dsra32     $v1, $v1, 0 */
    .word 0x0004217C /* dsll32     $a0, $a0, 5 */
    .word 0x00031E3C /* dsll32     $v1, $v1, 24 */
    .word 0x00852025 /* or         $a0, $a0, $a1 */
    .word 0x00642025 /* or         $a0, $v1, $a0 */
    .word 0x3C032000 /* lui        $v1, (0x20000000 >> 16) */
    .word 0x0003183C /* dsll32     $v1, $v1, 0 */
    .word 0x00831825 /* or         $v1, $a0, $v1 */
    .word 0xFE230020 /* sd         $v1, 0x20($s1) */
    .word 0x7BBF0040 /* lq         $ra, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0050 /* addiu     $sp, $sp, 0x50 */
}
}


#else

/* 0x0021A680 */
extern "C" {
int func_0021E350(unsigned short val);

void func_0021A680(void *self) {
    char *s1 = (char *)self;
    unsigned int flags = *(unsigned int *)(s1 + 0x98);
    int s2 = *(int *)(s1 + 0x3C);
    int s3 = *(int *)(s1 + 0x54);
    unsigned short s0 = 0;

    if ((flags & 0x800) != 0) {
        s2 = 640;
        s3 = 0xA3000;
    }

    void *ptr14 = *(void **)(s1 + 0x14);
    if (ptr14 != 0) {
        s0 = *(unsigned short *)((char *)ptr14 + 2);
    }

    int v0_res = func_0021E350(s0);
    int f1c = *(int *)(s1 + 0x1C);

    unsigned long long val = 0;
    val |= (unsigned long long)(unsigned int)(s3 >> 6);
    val |= ((unsigned long long)(unsigned int)(s2 >> 6)) << 14;
    val |= ((unsigned long long)(unsigned int)f1c) << 20;
    val |= 0xA8000000ULL;
    val |= 6ULL << 32;
    val |= ((unsigned long long)(unsigned int)(v0_res >> 6)) << 37;
    val |= 0x200000000000ULL;
    val |= ((unsigned long long)(s0 & 0xF)) << 56;

    *(unsigned long long *)(s1 + 0x20) = val;
}
}


#endif
