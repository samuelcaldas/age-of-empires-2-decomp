#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x0021B130 */
extern "C" {

asm int func_0021B130(void *self, const int *rect1, void *target, const int *rect3, int flags_t0, void *arg5) {
    .word 0x10C00006 /* beqz       $a2, .L0021B14C */
    .word 0x00000000 /* nop */
    .word 0x8CC30040 /* lw         $v1, 0x40($a2) */
    .word 0x8CE20004 /* lw         $v0, 0x4($a3) */
    .word 0x8CCE0054 /* lw         $t6, 0x54($a2) */
    .word 0x00621018 /* mult       $v0, $v1, $v0 */
    .word 0x01C27021 /* addu       $t6, $t6, $v0 */
    .word 0x8C8C0040 /* lw         $t4, 0x40($a0) */
    .word 0x8CE20000 /* lw         $v0, 0x0($a3) */
    .word 0x8CAD0004 /* lw         $t5, 0x4($a1) */
    .word 0x8C830054 /* lw         $v1, 0x54($a0) */
    .word 0x8CAB0000 /* lw         $t3, 0x0($a1) */
    .word 0x8CAA0008 /* lw         $t2, 0x8($a1) */
    .word 0x8CA7000C /* lw         $a3, 0xC($a1) */
    .word 0x018D6018 /* mult       $t4, $t4, $t5 */
    .word 0x01C27021 /* addu       $t6, $t6, $v0 */
    .word 0x71C01628 /* paddub     $v0, $t6, $zero */
    .word 0x006C1821 /* addu       $v1, $v1, $t4 */
    .word 0x006B1821 /* addu       $v1, $v1, $t3 */
    .word 0x014B2823 /* subu       $a1, $t2, $t3 */
    .word 0x11200003 /* beqz       $t1, .L0021B190 */
    .word 0x00ED3823 /* subu      $a3, $a3, $t5 */
    .word 0x10000003 /* b          .L0021B198 */
    .word 0x8D2B005C /* lw        $t3, 0x5C($t1) */
    .word 0x8C8B0070 /* lw         $t3, 0x70($a0) */
    .word 0x00000000 /* nop */
    .word 0x0008603C /* dsll32     $t4, $t0, 0 */
    .word 0x000C603E /* dsrl32     $t4, $t4, 0 */
    .word 0x318A0400 /* andi       $t2, $t4, 0x400 */
    .word 0x51400016 /* beql       $t2, $zero, .L0021B200 */
    .word 0x31898000 /* andi      $t1, $t4, 0x8000 */
    .word 0x1000000E /* b          .L0021B1E8 */
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x70605628 /* paddub     $t2, $v1, $zero */
    .word 0x10000005 /* b          .L0021B1D0 */
    .word 0x70004628 /* paddub    $t0, $zero, $zero */
    .word 0x91220050 /* lbu        $v0, 0x50($t1) */
    .word 0x25080001 /* addiu      $t0, $t0, 0x1 */
    .word 0xA1420000 /* sb         $v0, 0x0($t2) */
    .word 0x254A0001 /* addiu      $t2, $t2, 0x1 */
    .word 0x0105102B /* sltu       $v0, $t0, $a1 */
    .word 0x1440FFFA /* bnez       $v0, .L0021B1C0 */
    .word 0x00000000 /* nop */
    .word 0x8C820040 /* lw         $v0, 0x40($a0) */
    .word 0x24C60001 /* addiu      $a2, $a2, 0x1 */
    .word 0x00621821 /* addu       $v1, $v1, $v0 */
    .word 0x00C7102B /* sltu       $v0, $a2, $a3 */
    .word 0x1440FFF2 /* bnez       $v0, .L0021B1B8 */
    .word 0x70605628 /* paddub    $t2, $v1, $zero */
    .word 0x1000003D /* b          .L0021B2EC */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x31898000 /* andi       $t1, $t4, 0x8000 */
    .word 0x15200005 /* bnez       $t1, .L0021B218 */
    .word 0x70005628 /* paddub    $t2, $zero, $zero */
    .word 0x31080001 /* andi       $t0, $t0, 0x1 */
    .word 0x51000020 /* beql       $t0, $zero, .L0021B290 */
    .word 0x70005E28 /* paddub    $t3, $zero, $zero */
    .word 0x70005628 /* paddub     $t2, $zero, $zero */
    .word 0x10000018 /* b          .L0021B27C */
    .word 0x0147402B /* sltu      $t0, $t2, $a3 */
    .word 0x70407628 /* paddub     $t6, $v0, $zero */
    .word 0x70604E28 /* paddub     $t1, $v1, $zero */
    .word 0x1000000B /* b          .L0021B258 */
    .word 0x70006628 /* paddub    $t4, $zero, $zero */
    .word 0x91C80000 /* lbu        $t0, 0x0($t6) */
    .word 0x510B0006 /* beql       $t0, $t3, .L0021B250 */
    .word 0x25290001 /* addiu     $t1, $t1, 0x1 */
    .word 0xA1280000 /* sb         $t0, 0x0($t1) */
    .word 0x25CE0001 /* addiu      $t6, $t6, 0x1 */
    .word 0x10000003 /* b          .L0021B254 */
    .word 0x25290001 /* addiu     $t1, $t1, 0x1 */
    .word 0x25290001 /* addiu      $t1, $t1, 0x1 */
    .word 0x25CE0001 /* addiu      $t6, $t6, 0x1 */
    .word 0x258C0001 /* addiu      $t4, $t4, 0x1 */
    .word 0x0185402B /* sltu       $t0, $t4, $a1 */
    .word 0x1500FFF4 /* bnez       $t0, .L0021B230 */
    .word 0x00000000 /* nop */
    .word 0x8CC90040 /* lw         $t1, 0x40($a2) */
    .word 0x8C880040 /* lw         $t0, 0x40($a0) */
    .word 0x254A0001 /* addiu      $t2, $t2, 0x1 */
    .word 0x00491021 /* addu       $v0, $v0, $t1 */
    .word 0x00681821 /* addu       $v1, $v1, $t0 */
    .word 0x0147402B /* sltu       $t0, $t2, $a3 */
    .word 0x1500FFE9 /* bnez       $t0, .L0021B224 */
    .word 0x70407628 /* paddub    $t6, $v0, $zero */
    .word 0x10000019 /* b          .L0021B2EC */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x70005E28 /* paddub     $t3, $zero, $zero */
    .word 0x10000013 /* b          .L0021B2E0 */
    .word 0x0167402B /* sltu      $t0, $t3, $a3 */
    .word 0x70404E28 /* paddub     $t1, $v0, $zero */
    .word 0x70605628 /* paddub     $t2, $v1, $zero */
    .word 0x10000006 /* b          .L0021B2BC */
    .word 0x70006628 /* paddub    $t4, $zero, $zero */
    .word 0x91280000 /* lbu        $t0, 0x0($t1) */
    .word 0x258C0001 /* addiu      $t4, $t4, 0x1 */
    .word 0xA1480000 /* sb         $t0, 0x0($t2) */
    .word 0x25290001 /* addiu      $t1, $t1, 0x1 */
    .word 0x254A0001 /* addiu      $t2, $t2, 0x1 */
    .word 0x0185402B /* sltu       $t0, $t4, $a1 */
    .word 0x1500FFF9 /* bnez       $t0, .L0021B2A8 */
    .word 0x00000000 /* nop */
    .word 0x8CC90040 /* lw         $t1, 0x40($a2) */
    .word 0x8C880040 /* lw         $t0, 0x40($a0) */
    .word 0x256B0001 /* addiu      $t3, $t3, 0x1 */
    .word 0x00491021 /* addu       $v0, $v0, $t1 */
    .word 0x00681821 /* addu       $v1, $v1, $t0 */
    .word 0x0167402B /* sltu       $t0, $t3, $a3 */
    .word 0x1500FFEE /* bnez       $t0, .L0021B29C */
    .word 0x70404E28 /* paddub    $t1, $v0, $zero */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* jr         $ra */
    .word 0x00000000 /* nop */
}
}

#else

extern "C" {
static void fill_rect(char *dst, int pitch, int width, int height, unsigned char val) {
    for (int y = 0; y < height; y++) {
        char *row = dst + y * pitch;
        for (int x = 0; x < width; x++) {
            row[x] = (char)val;
        }
    }
}

static void blit_transparent(char *dst, int dst_pitch, const char *src, int src_pitch, int width, int height, int trans_color) {
    for (int y = 0; y < height; y++) {
        const char *src_row = src + y * src_pitch;
        char *dst_row = dst + y * dst_pitch;
        for (int x = 0; x < width; x++) {
            unsigned char pixel = (unsigned char)src_row[x];
            if (pixel != (unsigned char)trans_color) {
                dst_row[x] = (char)pixel;
            }
        }
    }
}

static void blit_opaque(char *dst, int dst_pitch, const char *src, int src_pitch, int width, int height) {
    for (int y = 0; y < height; y++) {
        const char *src_row = src + y * src_pitch;
        char *dst_row = dst + y * dst_pitch;
        for (int x = 0; x < width; x++) {
            dst_row[x] = src_row[x];
        }
    }
}

int func_0021B130(void *self, const int *rect1, void *target, const int *rect3, int flags_t0, void *arg5) {
    char *self_bytes = (char *)self;
    int self_pitch = *(int *)(self_bytes + 0x40);
    char *self_base = *(char **)(self_bytes + 0x54);

    char *target_base = 0;
    int target_pitch = 0;
    if (target != 0) {
        char *target_bytes = (char *)target;
        target_pitch = *(int *)(target_bytes + 0x40);
        target_base = *(char **)(target_bytes + 0x54);
    }

    char *dst = self_base + self_pitch * rect1[1] + rect1[0];
    char *src = 0;
    if (target != 0) {
        src = target_base + target_pitch * rect3[1] + rect3[0];
    }

    int width = rect1[2] - rect1[0];
    int height = rect1[3] - rect1[1];

    if ((flags_t0 & 0x400) != 0) {
        unsigned char fill_val = *(unsigned char *)((char *)arg5 + 0x50);
        fill_rect(dst, self_pitch, width, height, fill_val);
        return 0;
    }

    int trans_color = 0;
    if (arg5 != 0) {
        trans_color = *(int *)((char *)arg5 + 0x5C);
    }
    if (arg5 == 0) {
        trans_color = *(int *)(self_bytes + 0x70);
    }

    if ((flags_t0 & 0x8000) != 0) {
        blit_transparent(dst, self_pitch, src, target_pitch, width, height, trans_color);
        return 0;
    }

    if ((flags_t0 & 1) != 0) {
        blit_transparent(dst, self_pitch, src, target_pitch, width, height, 0);
        return 0;
    }

    blit_opaque(dst, self_pitch, src, target_pitch, width, height);
    return 0;
}
}
#endif
