#pragma exceptions off

#include "zone_spatial_pyramid_search_bounds.h"

extern "C" {
int func_1D40E0(void *self, int level, int x, int y, float f12, float f13, float f14, float f15);
}

#if defined(__mips__)

extern "C" asm int func_001D3EB0(
    void *self, int level, int x, int y, float f12, float f13, float f14, float f15, int op
) {
    .word 0x27BDFF60 /* 001D3EB0: addiu      $sp, $sp, -0xA0 */
    .word 0x7FBF0090 /* 001D3EB4: sq         $ra, 0x90($sp) */
    .word 0x7FB70080 /* 001D3EB8: sq         $s7, 0x80($sp) */
    .word 0x7FB60070 /* 001D3EBC: sq         $s6, 0x70($sp) */
    .word 0x7FB50060 /* 001D3EC0: sq         $s5, 0x60($sp) */
    .word 0x7FB40050 /* 001D3EC4: sq         $s4, 0x50($sp) */
    .word 0x7FB30040 /* 001D3EC8: sq         $s3, 0x40($sp) */
    .word 0x7FB20030 /* 001D3ECC: sq         $s2, 0x30($sp) */
    .word 0x7FB10020 /* 001D3ED0: sq         $s1, 0x20($sp) */
    .word 0x7FB00010 /* 001D3ED4: sq         $s0, 0x10($sp) */
    .word 0xE7B7000C /* 001D3ED8: swc1       $f23, 0xC($sp) */
    .word 0xE7B60008 /* 001D3EDC: swc1       $f22, 0x8($sp) */
    .word 0xE7B50004 /* 001D3EE0: swc1       $f21, 0x4($sp) */
    .word 0xE7B40000 /* 001D3EE4: swc1       $f20, 0x0($sp) */
    .word 0x8C8200F4 /* 001D3EE8: lw         $v0, 0xF4($a0) */
    .word 0x70A0A628 /* 001D3EEC: paddub     $s4, $a1, $zero */
    .word 0x7080AE28 /* 001D3EF0: paddub     $s5, $a0, $zero */
    .word 0x460065C6 /* 001D3EF4: mov.s      $f23, $f12 */
    .word 0x46006D86 /* 001D3EF8: mov.s      $f22, $f13 */
    .word 0x46007546 /* 001D3EFC: mov.s      $f21, $f14 */
    .word 0x02821007 /* 001D3F00: srav       $v0, $v0, $s4 */
    .word 0x00C2082A /* 001D3F04: slt        $at, $a2, $v0 */
    .word 0x46007D06 /* 001D3F08: mov.s      $f20, $f15 */
    .word 0x71009E28 /* 001D3F0C: paddub     $s3, $t0, $zero */
    .word 0x14200010 /* 001D3F10: bnez       $at, .L001D3F54 */
    .word 0x70008628 /* 001D3F14: paddub     $s0, $zero, $zero */
    .word 0x8EA200F8 /* 001D3F18: lw         $v0, 0xF8($s5) */
    .word 0x02821007 /* 001D3F1C: srav       $v0, $v0, $s4 */
    .word 0x00E2082A /* 001D3F20: slt        $at, $a3, $v0 */
    .word 0x1420000C /* 001D3F24: bnez       $at, .L001D3F58 */
    .word 0x70001628 /* 001D3F28: paddub     $v0, $zero, $zero */
    .word 0x8EA200FC /* 001D3F2C: lw         $v0, 0xFC($s5) */
    .word 0x02821007 /* 001D3F30: srav       $v0, $v0, $s4 */
    .word 0x0046102A /* 001D3F34: slt        $v0, $v0, $a2 */
    .word 0x14400006 /* 001D3F38: bnez       $v0, .L001D3F54 */
    .word 0x00000000 /* 001D3F3C: nop */
    .word 0x8EA20100 /* 001D3F40: lw         $v0, 0x100($s5) */
    .word 0x02821007 /* 001D3F44: srav       $v0, $v0, $s4 */
    .word 0x0047082A /* 001D3F48: slt        $at, $v0, $a3 */
    .word 0x10200004 /* 001D3F4C: beqz       $at, .L001D3F60 */
    .word 0x00000000 /* 001D3F50: nop */
    /* .L001D3F54: */
    .word 0x70001628 /* 001D3F54: paddub     $v0, $zero, $zero */
    /* .L001D3F58: */
    .word 0x10000051 /* 001D3F58: b          .L001D40A0 */
    .word 0x7BBF0090 /* 001D3F5C: lq         $ra, 0x90($sp) */
    /* .L001D3F60: */
    .word 0x8EA20000 /* 001D3F60: lw         $v0, 0x0($s5) */
    .word 0x00144880 /* 001D3F64: sll        $t1, $s4, 2 */
    .word 0x00061880 /* 001D3F68: sll        $v1, $a2, 2 */
    .word 0x00079040 /* 001D3F6C: sll        $s2, $a3, 1 */
    .word 0x00491021 /* 001D3F70: addu       $v0, $v0, $t1 */
    .word 0x8C420000 /* 001D3F74: lw         $v0, 0x0($v0) */
    .word 0x00431021 /* 001D3F78: addu       $v0, $v0, $v1 */
    .word 0x8C420000 /* 001D3F7C: lw         $v0, 0x0($v0) */
    .word 0x00528821 /* 001D3F80: addu       $s1, $v0, $s2 */
    .word 0x92220001 /* 001D3F84: lbu        $v0, 0x1($s1) */
    .word 0x30420020 /* 001D3F88: andi       $v0, $v0, 0x20 */
    .word 0x10400017 /* 001D3F8C: beqz       $v0, .L001D3FEC */
    .word 0x00000000 /* 001D3F90: nop */
    jal func_1D40E0  /* 001D3F94: jal        func_1D40E0 */
    .word 0x00000000 /* 001D3F98: nop */
    .word 0x1040003F /* 001D3F9C: beqz       $v0, .L001D409C */
    .word 0x72001628 /* 001D3FA0: paddub     $v0, $s0, $zero */
    .word 0x12600009 /* 001D3FA4: beqz       $s3, .L001D3FCC */
    .word 0x00000000 /* 001D3FA8: nop */
    .word 0x92230001 /* 001D3FAC: lbu        $v1, 0x1($s1) */
    .word 0x30620010 /* 001D3FB0: andi       $v0, $v1, 0x10 */
    .word 0x14400038 /* 001D3FB4: bnez       $v0, .L001D4098 */
    .word 0x00000000 /* 001D3FB8: nop */
    .word 0x24620010 /* 001D3FBC: addiu      $v0, $v1, 0x10 */
    .word 0x26100001 /* 001D3FC0: addiu      $s0, $s0, 0x1 */
    .word 0x10000034 /* 001D3FC4: b          .L001D4098 */
    .word 0xA2220001 /* 001D3FC8: sb         $v0, 0x1($s1) */
    /* .L001D3FCC: */
    .word 0x92230001 /* 001D3FCC: lbu        $v1, 0x1($s1) */
    .word 0x30620010 /* 001D3FD0: andi       $v0, $v1, 0x10 */
    .word 0x10400030 /* 001D3FD4: beqz       $v0, .L001D4098 */
    .word 0x00000000 /* 001D3FD8: nop */
    .word 0x2462FFF0 /* 001D3FDC: addiu      $v0, $v1, -0x10 */
    .word 0x26100001 /* 001D3FE0: addiu      $s0, $s0, 0x1 */
    .word 0x1000002C /* 001D3FE4: b          .L001D4098 */
    .word 0xA2220001 /* 001D3FE8: sb         $v0, 0x1($s1) */
    /* .L001D3FEC: */
    .word 0x1A80002A /* 001D3FEC: blez       $s4, .L001D4098 */
    .word 0x00000000 /* 001D3FF0: nop */
    .word 0x00068840 /* 001D3FF4: sll        $s1, $a2, 1 */
    .word 0x2685FFFF /* 001D3FF8: addiu      $a1, $s4, -0x1 */
    .word 0x26360001 /* 001D3FFC: addiu      $s6, $s1, 0x1 */
    .word 0x26570001 /* 001D4000: addiu      $s7, $s2, 0x1 */
    .word 0x72203628 /* 001D4004: paddub     $a2, $s1, $zero */
    jal func_001D3EB0 /* 001D4008: jal       func_001D3EB0 */
    .word 0x72403E28 /* 001D400C: paddub     $a3, $s2, $zero */
    .word 0x02028021 /* 001D4010: addu       $s0, $s0, $v0 */
    .word 0x4600BB06 /* 001D4014: mov.s      $f12, $f23 */
    .word 0x2685FFFF /* 001D4018: addiu      $a1, $s4, -0x1 */
    .word 0x4600B346 /* 001D401C: mov.s      $f13, $f22 */
    .word 0x72403E28 /* 001D4020: paddub     $a3, $s2, $zero */
    .word 0x72A02628 /* 001D4024: paddub     $a0, $s5, $zero */
    .word 0x72C03628 /* 001D4028: paddub     $a2, $s6, $zero */
    .word 0x4600AB86 /* 001D402C: mov.s      $f14, $f21 */
    .word 0x4600A3C6 /* 001D4030: mov.s      $f15, $f20 */
    jal func_001D3EB0 /* 001D4034: jal       func_001D3EB0 */
    .word 0x72604628 /* 001D4038: paddub     $t0, $s3, $zero */
    .word 0x02028021 /* 001D403C: addu       $s0, $s0, $v0 */
    .word 0x4600BB06 /* 001D4040: mov.s      $f12, $f23 */
    .word 0x2685FFFF /* 001D4044: addiu      $a1, $s4, -0x1 */
    .word 0x4600B346 /* 001D4048: mov.s      $f13, $f22 */
    .word 0x72203628 /* 001D404C: paddub     $a2, $s1, $zero */
    .word 0x72A02628 /* 001D4050: paddub     $a0, $s5, $zero */
    .word 0x72E03E28 /* 001D4054: paddub     $a3, $s7, $zero */
    .word 0x4600AB86 /* 001D4058: mov.s      $f14, $f21 */
    .word 0x4600A3C6 /* 001D405C: mov.s      $f15, $f20 */
    jal func_001D3EB0 /* 001D4060: jal       func_001D3EB0 */
    .word 0x72604628 /* 001D4064: paddub     $t0, $s3, $zero */
    .word 0x2685FFFF /* 001D4068: addiu      $a1, $s4, -0x1 */
    .word 0x4600BB06 /* 001D406C: mov.s      $f12, $f23 */
    .word 0x02028021 /* 001D4070: addu       $s0, $s0, $v0 */
    .word 0x4600B346 /* 001D4074: mov.s      $f13, $f22 */
    .word 0x72A02628 /* 001D4078: paddub     $a0, $s5, $zero */
    .word 0x72C03628 /* 001D407C: paddub     $a2, $s6, $zero */
    .word 0x72E03E28 /* 001D4080: paddub     $a3, $s7, $zero */
    .word 0x4600AB86 /* 001D4084: mov.s      $f14, $f21 */
    .word 0x4600A3C6 /* 001D4088: mov.s      $f15, $f20 */
    jal func_001D3EB0 /* 001D408C: jal       func_001D3EB0 */
    .word 0x72604628 /* 001D4090: paddub     $t0, $s3, $zero */
    .word 0x02028021 /* 001D4094: addu       $s0, $s0, $v0 */
    /* .L001D4098: */
    .word 0x72001628 /* 001D4098: paddub     $v0, $s0, $zero */
    /* .L001D409C: */
    .word 0x7BBF0090 /* 001D409C: lq         $ra, 0x90($sp) */
    /* .L001D40A0: */
    .word 0x7BB70080 /* 001D40A0: lq         $s7, 0x80($sp) */
    .word 0x7BB60070 /* 001D40A4: lq         $s6, 0x70($sp) */
    .word 0x7BB50060 /* 001D40A8: lq         $s5, 0x60($sp) */
    .word 0x7BB40050 /* 001D40AC: lq         $s4, 0x50($sp) */
    .word 0x7BB30040 /* 001D40B0: lq         $s3, 0x40($sp) */
    .word 0x7BB20030 /* 001D40B4: lq         $s2, 0x30($sp) */
    .word 0x7BB10020 /* 001D40B8: lq         $s1, 0x20($sp) */
    .word 0x7BB00010 /* 001D40BC: lq         $s0, 0x10($sp) */
    .word 0xC7B7000C /* 001D40C0: lwc1       $f23, 0xC($sp) */
    .word 0xC7B60008 /* 001D40C4: lwc1       $f22, 0x8($sp) */
    .word 0xC7B50004 /* 001D40C8: lwc1       $f21, 0x4($sp) */
    .word 0xC7B40000 /* 001D40CC: lwc1       $f20, 0x0($sp) */
    .word 0x03E00008 /* 001D40D0: jr         $ra */
    .word 0x27BD00A0 /* 001D40D4: addiu      $sp, $sp, 0xA0 */
}

#else

extern "C" int func_001D3EB0(
    void *self, int level, int x, int y, float minX, float minY, float maxX, float maxY, int op
) {
    char *zm = (char *)self;
    int min_x = *(int *)(zm + 0xF4) >> level;
    if (x < min_x) {
        return 0;
    }
    int min_y = *(int *)(zm + 0xF8) >> level;
    if (y < min_y) {
        return 0;
    }
    int max_x = *(int *)(zm + 0xFC) >> level;
    if (x > max_x) {
        return 0;
    }
    int max_y = *(int *)(zm + 0x100) >> level;
    if (y > max_y) {
        return 0;
    }

    void ***root = *(void ****)(zm + 0x0);
    void **level_ptr = (void **)root[level];
    char *col = (char *)level_ptr[x];
    char *cell_ptr = col + (y * 2);

    unsigned char flag = (unsigned char)cell_ptr[1];
    int count = 0;

    if (flag & 0x20) {
        if (!func_1D40E0(self, level, x, y, minX, minY, maxX, maxY)) {
            return 0;
        }
        if (op == 0) {
            unsigned char b = (unsigned char)cell_ptr[1];
            if (b & 0x10) {
                cell_ptr[1] = (char)(b - 0x10);
                count++;
            }
        } else {
            unsigned char b = (unsigned char)cell_ptr[1];
            if (!(b & 0x10)) {
                cell_ptr[1] = (char)(b + 0x10);
                count++;
            }
        }
        return count;
    }

    if (level <= 0) {
        return 0;
    }

    int c_x = x * 2;
    int c_y = y * 2;
    int next_level = level - 1;

    count += func_001D3EB0(self, next_level, c_x,     c_y,     minX, minY, maxX, maxY, op);
    count += func_001D3EB0(self, next_level, c_x + 1, c_y,     minX, minY, maxX, maxY, op);
    count += func_001D3EB0(self, next_level, c_x,     c_y + 1, minX, minY, maxX, maxY, op);
    count += func_001D3EB0(self, next_level, c_x + 1, c_y + 1, minX, minY, maxX, maxY, op);

    return count;
}

#endif
