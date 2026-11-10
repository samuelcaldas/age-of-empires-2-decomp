#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x0021A590 */
extern "C" {

asm int func_0021A590(void *self, void *arg1, void *arg2) {

    .word 0x14A0000A /* bnez       $a1, .L0021A5BC */
    .word 0x27BDFFF0 /* addiu     $sp, $sp, -0x10 */
    .word 0xAFA00004 /* sw         $zero, 0x4($sp) */
    .word 0xAFA00000 /* sw         $zero, 0x0($sp) */
    .word 0x8C82003C /* lw         $v0, 0x3C($a0) */
    .word 0x2442FFFF /* addiu      $v0, $v0, -0x1 */
    .word 0xAFA20008 /* sw         $v0, 0x8($sp) */
    .word 0x8C820038 /* lw         $v0, 0x38($a0) */
    .word 0x2442FFFF /* addiu      $v0, $v0, -0x1 */
    .word 0x1000000A /* b          .L0021A5E0 */
    .word 0xAFA2000C /* sw        $v0, 0xC($sp) */
    .word 0xC4A30000 /* lwc1       $f3, 0x0($a1) */
    .word 0xC4A20004 /* lwc1       $f2, 0x4($a1) */
    .word 0xC4A10008 /* lwc1       $f1, 0x8($a1) */
    .word 0xC4A0000C /* lwc1       $f0, 0xC($a1) */
    .word 0x27A20000 /* addiu      $v0, $sp, 0x0 */
    .word 0xE4430000 /* swc1       $f3, 0x0($v0) */
    .word 0xE4420004 /* swc1       $f2, 0x4($v0) */
    .word 0xE4410008 /* swc1       $f1, 0x8($v0) */
    .word 0xE440000C /* swc1       $f0, 0xC($v0) */
    .word 0x27A30008 /* addiu      $v1, $sp, 0x8 */
    .word 0x8C620000 /* lw         $v0, 0x0($v1) */
    .word 0x04410003 /* bgez       $v0, .L0021A5F8 */
    .word 0x27A80004 /* addiu     $t0, $sp, 0x4 */
    .word 0xAC600000 /* sw         $zero, 0x0($v1) */
    .word 0x27A80004 /* addiu      $t0, $sp, 0x4 */
    .word 0x8D020000 /* lw         $v0, 0x0($t0) */
    .word 0x04410003 /* bgez       $v0, .L0021A60C */
    .word 0x24870030 /* addiu     $a3, $a0, 0x30 */
    .word 0xAD000000 /* sw         $zero, 0x0($t0) */
    .word 0x24870030 /* addiu      $a3, $a0, 0x30 */
    .word 0x2403001B /* addiu      $v1, $zero, 0x1B */
    .word 0x70C02E28 /* paddub     $a1, $a2, $zero */
    .word 0x8CE20000 /* lw         $v0, 0x0($a3) */
    .word 0x2463FFFF /* addiu      $v1, $v1, -0x1 */
    .word 0xACA20000 /* sw         $v0, 0x0($a1) */
    .word 0x24E70004 /* addiu      $a3, $a3, 0x4 */
    .word 0x1C60FFFB /* bgtz       $v1, .L0021A614 */
    .word 0x24A50004 /* addiu     $a1, $a1, 0x4 */
    .word 0x8D070000 /* lw         $a3, 0x0($t0) */
    .word 0x9C820098 /* lwu        $v0, 0x98($a0) */
    .word 0x8C830084 /* lw         $v1, 0x84($a0) */
    .word 0x8FA50000 /* lw         $a1, 0x0($sp) */
    .word 0x8CC90024 /* lw         $t1, 0x24($a2) */
    .word 0x8C880040 /* lw         $t0, 0x40($a0) */
    .word 0x30424000 /* andi       $v0, $v0, 0x4000 */
    .word 0x70A31818 /* mult1      $v1, $a1, $v1 */
    .word 0x000318C2 /* srl        $v1, $v1, 3 */
    .word 0x01072018 /* mult       $a0, $t0, $a3 */
    .word 0x01244821 /* addu       $t1, $t1, $a0 */
    .word 0x10400002 /* beqz       $v0, .L0021A664 */
    .word 0x01234821 /* addu      $t1, $t1, $v1 */
    .word 0x2409FFFF /* addiu      $t1, $zero, -0x1 */
    .word 0x27BD0010 /* addiu      $sp, $sp, 0x10 */
    .word 0xACC90024 /* sw         $t1, 0x24($a2) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
}
}


#else

/* 0x0021A590 */
extern "C" {
int func_0021A590(void *self, const int *in_rect, void *out_view) {
    char *self_bytes = (char *)self;
    int local_rect[4];

    if (in_rect == 0) {
        local_rect[0] = 0;
        local_rect[1] = 0;
        local_rect[2] = *(int *)(self_bytes + 0x3C) - 1;
        local_rect[3] = *(int *)(self_bytes + 0x38) - 1;
    }
    if (in_rect != 0) {
        local_rect[0] = in_rect[0];
        local_rect[1] = in_rect[1];
        local_rect[2] = in_rect[2];
        local_rect[3] = in_rect[3];
    }

    if (local_rect[2] < 0) {
        local_rect[2] = 0;
    }
    if (local_rect[1] < 0) {
        local_rect[1] = 0;
    }

    int *src = (int *)(self_bytes + 0x30);
    int *dst = (int *)out_view;
    for (int i = 0; i < 27; i++) {
        dst[i] = src[i];
    }

    int flags = *(int *)(self_bytes + 0x98);
    if ((flags & 0x4000) != 0) {
        *(int *)((char *)out_view + 0x24) = -1;
        return 0;
    }

    int pitch = *(int *)(self_bytes + 0x40);
    int f84 = *(int *)(self_bytes + 0x84);
    int offset = pitch * local_rect[1] + ((local_rect[0] * f84) >> 3);

    *(int *)((char *)out_view + 0x24) += offset;
    return 0;
}
}


#endif
