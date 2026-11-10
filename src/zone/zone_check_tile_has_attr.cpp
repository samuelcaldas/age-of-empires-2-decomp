#pragma exceptions off

#include "zone_check_tile_has_attr.h"

#if defined(__mips__)

extern "C" asm int func_001D5A30(void *self, int x, int y) {
    .word 0x04A0000C /* 001D5A30: bltz       $a1, .L001D5A64 */
    .word 0x70001628 /* 001D5A34: paddub    $v0, $zero, $zero */
    .word 0x8C8200E4 /* 001D5A38: lw         $v0, 0xE4($a0) */
    .word 0x00A2082A /* 001D5A3C: slt        $at, $a1, $v0 */
    .word 0x10200007 /* 001D5A40: beqz       $at, .L001D5A60 */
    .word 0x00000000 /* 001D5A44: nop */
    .word 0x04C00005 /* 001D5A48: bltz       $a2, .L001D5A60 */
    .word 0x00000000 /* 001D5A4C: nop */
    .word 0x8C8200E8 /* 001D5A50: lw         $v0, 0xE8($a0) */
    .word 0x00C2102A /* 001D5A54: slt        $v0, $a2, $v0 */
    .word 0x14400004 /* 001D5A58: bnez       $v0, .L001D5A6C */
    .word 0x00000000 /* 001D5A5C: nop */
    .word 0x70001628 /* 001D5A60: paddub     $v0, $zero, $zero */
    .word 0x10000024 /* 001D5A64: b          .L001D5AF8 */
    .word 0x00000000 /* 001D5A68: nop */
    .word 0x8C840098 /* 001D5A6C: lw         $a0, 0x98($a0) */
    .word 0x00061880 /* 001D5A70: sll        $v1, $a2, 2 */
    .word 0x000510C0 /* 001D5A74: sll        $v0, $a1, 3 */
    .word 0x00451023 /* 001D5A78: subu       $v0, $v0, $a1 */
    .word 0x00024880 /* 001D5A7C: sll        $t1, $v0, 2 */
    .word 0x00833021 /* 001D5A80: addu       $a2, $a0, $v1 */
    .word 0x8CC20000 /* 001D5A84: lw         $v0, 0x0($a2) */
    .word 0x01221021 /* 001D5A88: addu       $v0, $t1, $v0 */
    .word 0x9048000D /* 001D5A8C: lbu        $t0, 0xD($v0) */
    .word 0x11000019 /* 001D5A90: beqz       $t0, .L001D5AF8 */
    .word 0x70001628 /* 001D5A94: paddub    $v0, $zero, $zero */
    .word 0x24040008 /* 001D5A98: addiu      $a0, $zero, 0x8 */
    .word 0x24030020 /* 001D5A9C: addiu      $v1, $zero, 0x20 */
    .word 0x10000011 /* 001D5AA0: b          .L001D5AE8 */
    .word 0x70003E28 /* 001D5AA4: paddub    $a3, $zero, $zero */
    .word 0x8CC20000 /* 001D5AA8: lw         $v0, 0x0($a2) */
    .word 0x00072880 /* 001D5AAC: sll        $a1, $a3, 2 */
    .word 0x00491021 /* 001D5AB0: addu       $v0, $v0, $t1 */
    .word 0x8C420014 /* 001D5AB4: lw         $v0, 0x14($v0) */
    .word 0x00451021 /* 001D5AB8: addu       $v0, $v0, $a1 */
    .word 0x8C420000 /* 001D5ABC: lw         $v0, 0x0($v0) */
    .word 0x8C420004 /* 001D5AC0: lw         $v0, 0x4($v0) */
    .word 0x8442000E /* 001D5AC4: lh         $v0, 0xE($v0) */
    .word 0x50440004 /* 001D5AC8: beql       $v0, $a0, .L001D5ADC */
    .word 0x24020001 /* 001D5ACC: addiu     $v0, $zero, 0x1 */
    .word 0x54430005 /* 001D5AD0: bnel       $v0, $v1, .L001D5AE8 */
    .word 0x24E70001 /* 001D5AD4: addiu     $a3, $a3, 0x1 */
    .word 0x24020001 /* 001D5AD8: addiu      $v0, $zero, 0x1 */
    .word 0x10000006 /* 001D5ADC: b          .L001D5AF8 */
    .word 0x00000000 /* 001D5AE0: nop */
    .word 0x24E70001 /* 001D5AE4: addiu      $a3, $a3, 0x1 */
    .word 0x00E8102A /* 001D5AE8: slt        $v0, $a3, $t0 */
    .word 0x1440FFEE /* 001D5AEC: bnez       $v0, .L001D5AA8 */
    .word 0x00000000 /* 001D5AF0: nop */
    .word 0x70001628 /* 001D5AF4: paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* 001D5AF8: jr         $ra */
    .word 0x00000000 /* 001D5AFC: nop */
}

#else

extern "C" int func_001D5A30(void *self, int x, int y) {
    char *zm = (char *)self;
    if (x < 0 || !(x < *(int *)(zm + 0xE4)) || y < 0 || !(y < *(int *)(zm + 0xE8))) {
        return 0;
    }

    char **rows = *(char ***)(zm + 0x98);
    int x_offset = (x * 7) << 2;
    char *cell = rows[y] + x_offset;

    unsigned char count = *(unsigned char *)(cell + 0xD);
    if (!count) {
        return 0;
    }

    int i = 0;
    while (i < (int)count) {
        void **items = *(void ***)(rows[y] + x_offset + 0x14);
        char *item = (char *)items[i];
        char *info = *(char **)(item + 4);
        short attr = *(short *)(info + 0xE);
        if (attr == 8 || attr == 0x20) {
            return 1;
        }
        i++;
    }

    return 0;
}

#endif
