#pragma once
#pragma exceptions off

#include "zone_raster_untag.h"

#if defined(__mips__)

extern "C" asm int func_001CA430(void *self, int x0, int y0, int x1, int y1) {
    .word 0x14A70006 /* 00: bne $a1, $a3, 0x1c */
    .word 0x00E5082A /* 04: slt $at, $a3, $a1 */
    .word 0x14C80003 /* 08: bne $a2, $a4, 0x18 */
    .word 0x00000000 /* 0C: nop  */
    .word 0x10000044 /* 10: b 0x124 */
    .word 0x24020001 /* 14: addiu $v0, $zero, 0x1 */
    .word 0x00E5082A /* 18: slt $at, $a3, $a1 */
    .word 0x10200005 /* 1C: beqz $at, 0x34 */
    .word 0x0106082A /* 20: slt $at, $a4, $a2 */
    .word 0x70A01628 /* 24: paddub $v0, $a1, $zero */
    .word 0x70E02E28 /* 28: paddub $a1, $a3, $zero */
    .word 0x70403E28 /* 2C: paddub $a3, $v0, $zero */
    .word 0x0106082A /* 30: slt $at, $a4, $a2 */
    .word 0x10200004 /* 34: beqz $at, 0x48 */
    .word 0x00000000 /* 38: nop  */
    .word 0x70C01628 /* 3C: paddub $v0, $a2, $zero */
    .word 0x71003628 /* 40: paddub $a2, $a4, $zero */
    .word 0x70404628 /* 44: paddub $a4, $v0, $zero */
    .word 0x8C830008 /* 48: lw $v1, 0x8($a0) */
    .word 0x00A3082A /* 4C: slt $at, $a1, $v1 */
    .word 0x1020000A /* 50: beqz $at, 0x7c */
    .word 0x70001628 /* 54: paddub $v0, $zero, $zero */
    .word 0x8C89000C /* 58: lw $t1, 0xc($a0) */
    .word 0x00C9082A /* 5C: slt $at, $a2, $t1 */
    .word 0x10200005 /* 60: beqz $at, 0x78 */
    .word 0x00000000 /* 64: nop  */
    .word 0x04E00003 /* 68: bltz $a3, 0x78 */
    .word 0x00000000 /* 6C: nop  */
    .word 0x05010004 /* 70: bgez $a4, 0x84 */
    .word 0x00000000 /* 74: nop  */
    .word 0x70001628 /* 78: paddub $v0, $zero, $zero */
    .word 0x10000029 /* 7C: b 0x124 */
    .word 0x00000000 /* 80: nop  */
    .word 0x04A10002 /* 84: bgez $a1, 0x90 */
    .word 0x00000000 /* 88: nop  */
    .word 0x70002E28 /* 8C: paddub $a1, $zero, $zero */
    .word 0x04C10003 /* 90: bgez $a2, 0xa0 */
    .word 0x00E3102A /* 94: slt $v0, $a3, $v1 */
    .word 0x70003628 /* 98: paddub $a2, $zero, $zero */
    .word 0x00E3102A /* 9C: slt $v0, $a3, $v1 */
    .word 0x14400003 /* A0: bnez $v0, 0xb0 */
    .word 0x0109102A /* A4: slt $v0, $a4, $t1 */
    .word 0x2467FFFF /* A8: addiu $a3, $v1, -0x1 */
    .word 0x0109102A /* AC: slt $v0, $a4, $t1 */
    .word 0x14400003 /* B0: bnez $v0, 0xc0 */
    .word 0x000510C0 /* B4: sll $v0, $a1, 3 */
    .word 0x2528FFFF /* B8: addiu $a4, $t1, -0x1 */
    .word 0x000510C0 /* BC: sll $v0, $a1, 3 */
    .word 0x00451023 /* C0: subu $v0, $v0, $a1 */
    .word 0x10000013 /* C4: b 0x114 */
    .word 0x00025080 /* C8: sll $t2, $v0, 2 */
    .word 0x3C010001 /* CC: lui $at, 0x1 */
    .word 0x00810821 /* D0: addu $at, $a0, $at */
    .word 0x8C228E8C /* D4: lw $v0, -0x7174($at) */
    .word 0x00061880 /* D8: sll $v1, $a2, 2 */
    .word 0x70A04E28 /* DC: paddub $t1, $a1, $zero */
    .word 0x00431021 /* E0: addu $v0, $v0, $v1 */
    .word 0x8C420000 /* E4: lw $v0, 0x0($v0) */
    .word 0x10000006 /* E8: b 0x104 */
    .word 0x004A1821 /* EC: addu $v1, $v0, $t2 */
    .word 0xA060000C /* F0: sb $zero, 0xc($v1) */
    .word 0x9062000B /* F4: lbu $v0, 0xb($v1) */
    .word 0x25290001 /* F8: addiu $t1, $t1, 0x1 */
    .word 0x3042009F /* FC: andi $v0, $v0, 0x9f */
    .word 0xA062000B /* 100: sb $v0, 0xb($v1) */
    .word 0x00E9082A /* 104: slt $at, $a3, $t1 */
    .word 0x1020FFF9 /* 108: beqz $at, 0xf0 */
    .word 0x00000000 /* 10C: nop  */
    .word 0x24C60001 /* 110: addiu $a2, $a2, 0x1 */
    .word 0x0106082A /* 114: slt $at, $a4, $a2 */
    .word 0x1020FFED /* 118: beqz $at, 0xd0 */
    .word 0x3C010001 /* 11C: lui $at, 0x1 */
    .word 0x24020001 /* 120: addiu $v0, $zero, 0x1 */
    .word 0x03E00008 /* 124: jr $ra */
    .word 0x00000000 /* 128: nop  */
}

#else

struct ZoneCell {
    char pad_0[11];         // 0x0..0xA
    unsigned char f_B;      // 0xB (11)
    unsigned char f_C;      // 0xC (12)
    char pad_D[15];         // to reach 0x1C (28 bytes)
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
};

extern "C" int func_001CA430(void *self, int x0, int y0, int x1, int y1) {
    if (x0 == x1 && y0 == y1) {
        return 1;
    }

    if (x1 < x0) {
        int tmp = x0; x0 = x1; x1 = tmp;
    }
    if (y1 < y0) {
        int tmp = y0; y0 = y1; y1 = tmp;
    }

    ZoneLayout *zm = (ZoneLayout *)self;

    if (!(x0 < zm->width && y0 < zm->height && x1 >= 0 && y1 >= 0)) {
        return 0;
    }

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= zm->width) x1 = zm->width - 1;
    if (y1 >= zm->height) y1 = zm->height - 1;

    int x0_offset = (x0 * 7) << 2;

    for (int y = y0; y <= y1; y++) {
        char *cell = (char *)zm->cells_ptr[y] + x0_offset;
        for (int x = x0; x <= x1; x++, cell += 0x1C) {
            cell[0xC] = 0;
            cell[0xB] = (unsigned char)(cell[0xB] & 0x9F);
        }
    }

    return 1;
}

#endif
