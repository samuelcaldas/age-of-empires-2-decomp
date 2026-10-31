#pragma once
#pragma exceptions off

#include "zone_rect_update.h"

#if defined(__mips__)

extern "C" asm void func_001C9FA0(void *self, int x0, int y0, int x1, int y1) {
    .word 0x27BDFFC0 /* 9FA0: addiu      $sp, $sp, -0x40 */
    .word 0x7FBF0030 /* 9FA4: sq         $ra, 0x30($sp) */
    .word 0x7FB20020 /* 9FA8: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 9FAC: sq         $s1, 0x10($sp) */
    .word 0x04A10003 /* 9FB0: bgez       $a1, .L001C9FC0 */
    .word 0x7FB00000 /* 9FB4: sq        $s0, 0x0($sp) */
    .word 0x10000007 /* 9FB8: b          .L001C9FD8 */
    .word 0x70002E28 /* 9FBC: paddub    $a1, $zero, $zero */
    .word 0x8C830008 /* 9FC0: lw         $v1, 0x8($a0) */
    .word 0x2463FFFF /* 9FC4: addiu      $v1, $v1, -0x1 */
    .word 0x0065082A /* 9FC8: slt        $at, $v1, $a1 */
    .word 0x10200002 /* 9FCC: beqz       $at, .L001C9FD8 */
    .word 0x00000000 /* 9FD0: nop */
    .word 0x70602E28 /* 9FD4: paddub     $a1, $v1, $zero */
    .word 0x04C10003 /* 9FD8: bgez       $a2, .L001C9FE8 */
    .word 0x00000000 /* 9FDC: nop */
    .word 0x10000007 /* 9FE0: b          .L001CA000 */
    .word 0x70003628 /* 9FE4: paddub    $a2, $zero, $zero */
    .word 0x8C83000C /* 9FE8: lw         $v1, 0xC($a0) */
    .word 0x2463FFFF /* 9FEC: addiu      $v1, $v1, -0x1 */
    .word 0x0066082A /* 9FF0: slt        $at, $v1, $a2 */
    .word 0x10200002 /* 9FF4: beqz       $at, .L001CA000 */
    .word 0x00000000 /* 9FF8: nop */
    .word 0x70603628 /* 9FFC: paddub     $a2, $v1, $zero */
    .word 0x04E10003 /* A000: bgez       $a3, .L001CA010 */
    .word 0x00000000 /* A004: nop */
    .word 0x10000007 /* A008: b          .L001CA028 */
    .word 0x70003E28 /* A00C: paddub    $a3, $zero, $zero */
    .word 0x8C830008 /* A010: lw         $v1, 0x8($a0) */
    .word 0x2463FFFF /* A014: addiu      $v1, $v1, -0x1 */
    .word 0x0067082A /* A018: slt        $at, $v1, $a3 */
    .word 0x10200002 /* A01C: beqz       $at, .L001CA028 */
    .word 0x00000000 /* A020: nop */
    .word 0x70603E28 /* A024: paddub     $a3, $v1, $zero */
    .word 0x05010003 /* A028: bgez       $t0, .L001CA038 */
    .word 0x00000000 /* A02C: nop */
    .word 0x10000007 /* A030: b          .L001CA050 */
    .word 0x70004628 /* A034: paddub    $t0, $zero, $zero */
    .word 0x8C83000C /* A038: lw         $v1, 0xC($a0) */
    .word 0x2463FFFF /* A03C: addiu      $v1, $v1, -0x1 */
    .word 0x0068082A /* A040: slt        $at, $v1, $t0 */
    .word 0x50200003 /* A044: beql       $at, $zero, .L001CA054 */
    .word 0x000518C0 /* A048: sll       $v1, $a1, 3 */
    .word 0x70604628 /* A04C: paddub     $t0, $v1, $zero */
    .word 0x000518C0 /* A050: sll        $v1, $a1, 3 */
    .word 0x00651823 /* A054: subu       $v1, $v1, $a1 */
    .word 0x2410000F /* A058: addiu      $s0, $zero, 0xF */
    .word 0x241F0010 /* A05C: addiu      $ra, $zero, 0x10 */
    .word 0x2419000E /* A060: addiu      $t9, $zero, 0xE */
    .word 0x2418000A /* A064: addiu      $t8, $zero, 0xA */
    .word 0x240F0006 /* A068: addiu      $t7, $zero, 0x6 */
    .word 0x240E0008 /* A06C: addiu      $t6, $zero, 0x8 */
    .word 0x240D0002 /* A070: addiu      $t5, $zero, 0x2 */
    .word 0x10000039 /* A074: b          .L001CA15C */
    .word 0x00035080 /* A078: sll       $t2, $v1, 2 */
    .word 0x3C010001 /* A07C: lui        $at, (0x10000 >> 16) */
    .word 0x00810821 /* A080: addu       $at, $a0, $at */
    .word 0x8C298E8C /* A084: lw         $t1, -0x7174($at) */
    .word 0x00065880 /* A088: sll        $t3, $a2, 2 */
    .word 0x70A01E28 /* A08C: paddub     $v1, $a1, $zero */
    .word 0x012B4821 /* A090: addu       $t1, $t1, $t3 */
    .word 0x8D290000 /* A094: lw         $t1, 0x0($t1) */
    .word 0x1000002C /* A098: b          .L001CA14C */
    .word 0x012A4821 /* A09C: addu      $t1, $t1, $t2 */
    .word 0x3C010001 /* A0A0: lui        $at, (0x10000 >> 16) */
    .word 0x00810821 /* A0A4: addu       $at, $a0, $at */
    .word 0x842C8EB4 /* A0A8: lh         $t4, -0x714C($at) */
    .word 0x00665821 /* A0AC: addu       $t3, $v1, $a2 */
    .word 0x00C38823 /* A0B0: subu       $s1, $a2, $v1 */
    .word 0x018B5818 /* A0B4: mult       $t3, $t4, $t3 */
    .word 0x3C010001 /* A0B8: lui        $at, (0x10000 >> 16) */
    .word 0x00810821 /* A0BC: addu       $at, $a0, $at */
    .word 0xA52B0000 /* A0C0: sh         $t3, 0x0($t1) */
    .word 0x84328EB2 /* A0C4: lh         $s2, -0x714E($at) */
    .word 0x912C0006 /* A0C8: lbu        $t4, 0x6($t1) */
    .word 0x3C010001 /* A0CC: lui        $at, (0x10000 >> 16) */
    .word 0x00810821 /* A0D0: addu       $at, $a0, $at */
    .word 0x72518818 /* A0D4: mult1      $s1, $s2, $s1 */
    .word 0x842B8EB6 /* A0D8: lh         $t3, -0x714A($at) */
    .word 0x018B5818 /* A0DC: mult       $t3, $t4, $t3 */
    .word 0x022B5823 /* A0E0: subu       $t3, $s1, $t3 */
    .word 0xA52B0002 /* A0E4: sh         $t3, 0x2($t1) */
    .word 0x912B0004 /* A0E8: lbu        $t3, 0x4($t1) */
    .word 0x11700010 /* A0EC: beq        $t3, $s0, .L001CA130 */
    .word 0x3C010001 /* A0F0: lui       $at, (0x10000 >> 16) */
    .word 0x117F000D /* A0F4: beq        $t3, $ra, .L001CA12C */
    .word 0x00000000 /* A0F8: nop */
    .word 0x1179000B /* A0FC: beq        $t3, $t9, .L001CA12C */
    .word 0x00000000 /* A100: nop */
    .word 0x11780009 /* A104: beq        $t3, $t8, .L001CA12C */
    .word 0x00000000 /* A108: nop */
    .word 0x116F0007 /* A10C: beq        $t3, $t7, .L001CA12C */
    .word 0x00000000 /* A110: nop */
    .word 0x116E0005 /* A114: beq        $t3, $t6, .L001CA12C */
    .word 0x00000000 /* A118: nop */
    .word 0x116D0003 /* A11C: beq        $t3, $t5, .L001CA12C */
    .word 0x00000000 /* A120: nop */
    .word 0x10000008 /* A124: b          .L001CA148 */
    .word 0x2529001C /* A128: addiu     $t1, $t1, 0x1C */
    .word 0x3C010001 /* A12C: lui        $at, (0x10000 >> 16) */
    .word 0x00810821 /* A130: addu       $at, $a0, $at */
    .word 0x852B0002 /* A134: lh         $t3, 0x2($t1) */
    .word 0x842C8EB6 /* A138: lh         $t4, -0x714A($at) */
    .word 0x016C5823 /* A13C: subu       $t3, $t3, $t4 */
    .word 0xA52B0002 /* A140: sh         $t3, 0x2($t1) */
    .word 0x2529001C /* A144: addiu      $t1, $t1, 0x1C */
    .word 0x24630001 /* A148: addiu      $v1, $v1, 0x1 */
    .word 0x00E3082A /* A14C: slt        $at, $a3, $v1 */
    .word 0x1020FFD4 /* A150: beqz       $at, .L001CA0A4 */
    .word 0x3C010001 /* A154: lui       $at, (0x10000 >> 16) */
    .word 0x24C60001 /* A158: addiu      $a2, $a2, 0x1 */
    .word 0x0106082A /* A15C: slt        $at, $t0, $a2 */
    .word 0x1020FFC7 /* A160: beqz       $at, .L001CA080 */
    .word 0x3C010001 /* A164: lui       $at, (0x10000 >> 16) */
    .word 0x7BBF0030 /* A168: lq         $ra, 0x30($sp) */
    .word 0x7BB20020 /* A16C: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* A170: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* A174: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* A178: jr         $ra */
    .word 0x27BD0040 /* A17C: addiu     $sp, $sp, 0x40 */
}

#else

struct ZoneCell {
    short f_0;              // 0x0
    short f_2;              // 0x2
    unsigned char f_4;      // 0x4
    unsigned char f_5;      // 0x5
    unsigned char f_6;      // 0x6
    unsigned char f_7;      // 0x7
    char pad_8[20];         // to reach 0x1C (28 bytes)
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
    char pad_8E90[0x22];    // 0x8E90..0x8EB1
    short f_8EB2;           // 0x8EB2 (-0x714E)
    short f_8EB4;           // 0x8EB4 (-0x714C)
    short f_8EB6;           // 0x8EB6 (-0x714A)
};

extern "C" void func_001C9FA0(void *self, int x0, int y0, int x1, int y1) {
    ZoneLayout *zm = (ZoneLayout *)self;

    if (x0 < 0) {
        x0 = 0;
    } else {
        int max_x = zm->width - 1;
        if (max_x < x0) {
            x0 = max_x;
        }
    }

    if (y0 < 0) {
        y0 = 0;
    } else {
        int max_y = zm->height - 1;
        if (max_y < y0) {
            y0 = max_y;
        }
    }

    if (x1 < 0) {
        x1 = 0;
    } else {
        int max_x = zm->width - 1;
        if (max_x < x1) {
            x1 = max_x;
        }
    }

    if (y1 < 0) {
        y1 = 0;
    } else {
        int max_y = zm->height - 1;
        if (max_y < y1) {
            y1 = max_y;
        }
    }

    int x0_offset = (x0 * 8 - x0) * 4;

    int y = y0;
    while (y <= y1) {
        ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + x0_offset);
        int x = x0;
        while (x <= x1) {
            cell->f_0 = (short)((x + y) * zm->f_8EB4);
            cell->f_2 = (short)((y - x) * zm->f_8EB2 - cell->f_6 * zm->f_8EB6);
            unsigned char f4 = cell->f_4;
            if (f4 == 15 || f4 == 16 || f4 == 14 || f4 == 10 || f4 == 6 || f4 == 8 || f4 == 2) {
                cell->f_2 = (short)(cell->f_2 - zm->f_8EB6);
            }
            cell = (ZoneCell *)((char *)cell + 0x1C);
            x++;
        }
        y++;
    }
}

#endif
