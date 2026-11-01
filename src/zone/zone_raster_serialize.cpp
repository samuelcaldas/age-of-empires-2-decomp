#pragma once
#pragma exceptions off

#include "zone_raster_serialize.h"

extern "C" {
int func_226F70(void *stream, void *src, int size);

#if defined(__mips__)
asm void func_001CAC90(void *self, void *stream) {
    .word 0x27BDFFA0 /* 001CAC90 addiu      $sp, $sp, -0x60 */
    .word 0x7FBF0040 /* 001CAC94 sq         $ra, 0x40($sp) */
    .word 0x7FB30030 /* 001CAC98 sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001CAC9C sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001CACA0 sq         $s1, 0x10($sp) */
    .word 0x70809628 /* 001CACA4 paddub     $s2, $a0, $zero */
    .word 0x70A08E28 /* 001CACA8 paddub     $s1, $a1, $zero */
    .word 0x26450ED8 /* 001CACAC addiu      $a1, $s2, 0xED8 */
    .word 0x24A57FF8 /* 001CACB0 addiu      $a1, $a1, 0x7FF8 */
    .word 0x24060004 /* 001CACB4 addiu      $a2, $zero, 0x4 */
    .word 0x72202628 /* 001CACB8 paddub     $a0, $s1, $zero */
    jal func_226F70
    .word 0x7FB00000 /* 001CACC0 sq         $s0, 0x0($sp) */
    .word 0x26450EDC /* 001CACC4 addiu      $a1, $s2, 0xEDC */
    .word 0x24A57FF8 /* 001CACC8 addiu      $a1, $a1, 0x7FF8 */
    .word 0x24060004 /* 001CACCC addiu      $a2, $zero, 0x4 */
    jal func_226F70
    .word 0x72202628 /* 001CACD4 paddub     $a0, $s1, $zero */
    .word 0x3C010001 /* 001CACD8 lui        $at, (0x10000 >> 16) */
    .word 0x02410821 /* 001CACDC addu       $at, $s2, $at */
    .word 0x8C238ED0 /* 001CACE0 lw         $v1, -0x7130($at) */
    .word 0x18600021 /* 001CACE4 blez       $v1, .L001CAD6C */
    .word 0x00000000 /* 001CACE8 nop */
    .word 0x3C010001 /* 001CACEC lui        $at, (0x10000 >> 16) */
    .word 0x02410821 /* 001CACF0 addu       $at, $s2, $at */
    .word 0x8C258ED8 /* 001CACF4 lw         $a1, -0x7128($at) */
    .word 0x00033080 /* 001CACF8 sll        $a2, $v1, 2 */
    jal func_226F70
    .word 0x72202628 /* 001CAD00 paddub     $a0, $s1, $zero */
    .word 0x10000013 /* 001CAD04 b          .L001CAD54 */
    .word 0x70008628 /* 001CAD08 paddub     $s0, $zero, $zero */
    .word 0x3C010001 /* 001CAD0C lui        $at, (0x10000 >> 16) */
/* .L001CAD10: */
    .word 0x02410821 /* 001CAD10 addu       $at, $s2, $at */
    .word 0x8C228EDC /* 001CAD14 lw         $v0, -0x7124($at) */
    .word 0x00101880 /* 001CAD18 sll        $v1, $s0, 2 */
    .word 0x27A5005C /* 001CAD1C addiu      $a1, $sp, 0x5C */
    .word 0x24060004 /* 001CAD20 addiu      $a2, $zero, 0x4 */
    .word 0x00431021 /* 001CAD24 addu       $v0, $v0, $v1 */
    .word 0x8C530000 /* 001CAD28 lw         $s3, 0x0($v0) */
    .word 0x72202628 /* 001CAD2C paddub     $a0, $s1, $zero */
    .word 0x86620000 /* 001CAD30 lh         $v0, 0x0($s3) */
    jal func_226F70
    .word 0xAFA2005C /* 001CAD38 sw         $v0, 0x5C($sp) */
    .word 0x8FA2005C /* 001CAD3C lw         $v0, 0x5C($sp) */
    .word 0x26650004 /* 001CAD40 addiu      $a1, $s3, 0x4 */
    .word 0x72202628 /* 001CAD44 paddub     $a0, $s1, $zero */
    jal func_226F70
    .word 0x00023080 /* 001CAD4C sll        $a2, $v0, 2 */
    .word 0x26100001 /* 001CAD50 addiu      $s0, $s0, 0x1 */
/* .L001CAD54: */
    .word 0x3C010001 /* 001CAD54 lui        $at, (0x10000 >> 16) */
    .word 0x02410821 /* 001CAD58 addu       $at, $s2, $at */
    .word 0x8C238ED0 /* 001CAD5C lw         $v1, -0x7130($at) */
    .word 0x0203182A /* 001CAD60 slt        $v1, $s0, $v1 */
    .word 0x1460FFEA /* 001CAD64 bnez       $v1, .L001CAD10 */
    .word 0x3C010001 /* 001CAD68 lui        $at, (0x10000 >> 16) */
/* .L001CAD6C: */
    .word 0x7BBF0040 /* 001CAD6C lq         $ra, 0x40($sp) */
    .word 0x7BB30030 /* 001CAD70 lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001CAD74 lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001CAD78 lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001CAD7C lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001CAD80 jr         $ra */
    .word 0x27BD0060 /* 001CAD84 addiu      $sp, $sp, 0x60 */
}
#else
struct ZoneLayout {
    char pad_0[0x8ED0];
    int f_8ED0;
    int f_8ED4;
    int *f_8ED8;
    short **f_8EDC;
};

void func_001CAC90(void *self, void *stream) {
    ZoneLayout *zm = (ZoneLayout *)self;

    func_226F70(stream, &zm->f_8ED0, 4);
    func_226F70(stream, &zm->f_8ED4, 4);

    int count = zm->f_8ED0;
    if (count > 0) {
        func_226F70(stream, zm->f_8ED8, count * 4);

        for (int i = 0; i < count; i++) {
            short *buf = zm->f_8EDC[i];
            int pt_count = (int)buf[0];
            func_226F70(stream, &pt_count, 4);
            func_226F70(stream, &buf[2], pt_count * 4);
        }
    }
}
#endif
}
