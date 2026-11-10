#pragma exceptions off

#include "zone_spatial_pyramid_search_cell.h"

#if defined(__mips__)

extern "C" asm int func_001D3440(void *self, int level, int x, int y, void *p1, void *p2) {
    .word 0x27BDFFA0 /* 001D3440: addiu      $sp, $sp, -0x60 */
    .word 0x7FBF0050 /* 001D3444: sq         $ra, 0x50($sp) */
    .word 0x7FB40040 /* 001D3448: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D344C: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D3450: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D3454: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D3458: sq         $s0, 0x0($sp) */
    .word 0x8C830000 /* 001D345C: lw         $v1, 0x0($a0) */
    .word 0x00054880 /* 001D3460: sll        $t1, $a1, 2 */
    .word 0x70C09628 /* 001D3464: paddub     $s2, $a2, $zero */
    .word 0x70A09E28 /* 001D3468: paddub     $s3, $a1, $zero */
    .word 0x00063080 /* 001D346C: sll        $a2, $a2, 2 */
    .word 0x70E08E28 /* 001D3470: paddub     $s1, $a3, $zero */
    .word 0x00691821 /* 001D3474: addu       $v1, $v1, $t1 */
    .word 0x8C630000 /* 001D3478: lw         $v1, 0x0($v1) */
    .word 0x00072840 /* 001D347C: sll        $a1, $a3, 1 */
    .word 0x7080A628 /* 001D3480: paddub     $s4, $a0, $zero */
    .word 0x00661821 /* 001D3484: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D3488: lw         $v1, 0x0($v1) */
    .word 0x00653821 /* 001D348C: addu       $a3, $v1, $a1 */
    .word 0x90E30001 /* 001D3490: lbu        $v1, 0x1($a3) */
    .word 0x30630020 /* 001D3494: andi       $v1, $v1, 0x20 */
    .word 0x10600024 /* 001D3498: beqz       $v1, .L001D352C */
    .word 0x71008628 /* 001D349C: paddub     $s0, $t0, $zero */
    .word 0x8E8300F4 /* 001D34A0: lw         $v1, 0xF4($s4) */
    .word 0x8E8600FC /* 001D34A4: lw         $a2, 0xFC($s4) */
    .word 0x8E8500F8 /* 001D34A8: lw         $a1, 0xF8($s4) */
    .word 0x8E840100 /* 001D34AC: lw         $a0, 0x100($s4) */
    .word 0x02631807 /* 001D34B0: srav       $v1, $v1, $s3 */
    .word 0x0243182A /* 001D34B4: slt        $v1, $s2, $v1 */
    .word 0x02663007 /* 001D34B8: srav       $a2, $a2, $s3 */
    .word 0x02652807 /* 001D34BC: srav       $a1, $a1, $s3 */
    .word 0x14600034 /* 001D34C0: bnez       $v1, .L001D3594 */
    .word 0x02642007 /* 001D34C4: srav       $a0, $a0, $s3 */
    .word 0x00D2082A /* 001D34C8: slt        $at, $a2, $s2 */
    .word 0x14200031 /* 001D34CC: bnez       $at, .L001D3594 */
    .word 0x00000000 /* 001D34D0: nop */
    .word 0x0225182A /* 001D34D4: slt        $v1, $s1, $a1 */
    .word 0x1460002E /* 001D34D8: bnez       $v1, .L001D3594 */
    .word 0x00000000 /* 001D34DC: nop */
    .word 0x0091082A /* 001D34E0: slt        $at, $a0, $s1 */
    .word 0x1420002B /* 001D34E4: bnez       $at, .L001D3594 */
    .word 0x00000000 /* 001D34E8: nop */
    .word 0x12000008 /* 001D34EC: beqz       $s0, .L001D3510 */
    .word 0x00000000 /* 001D34F0: nop */
    .word 0x90E40000 /* 001D34F4: lbu        $a0, 0x0($a3) */
    .word 0x30830020 /* 001D34F8: andi       $v1, $a0, 0x20 */
    .word 0x14600025 /* 001D34FC: bnez       $v1, .L001D3594 */
    .word 0x00000000 /* 001D3500: nop */
    .word 0x24830020 /* 001D3504: addiu      $v1, $a0, 0x20 */
    .word 0x10000022 /* 001D3508: b          .L001D3594 */
    .word 0xA0E30000 /* 001D350C: sb         $v1, 0x0($a3) */
    /* .L001D3510: */
    .word 0x90E40000 /* 001D3510: lbu        $a0, 0x0($a3) */
    .word 0x30830020 /* 001D3514: andi       $v1, $a0, 0x20 */
    .word 0x1060001E /* 001D3518: beqz       $v1, .L001D3594 */
    .word 0x00000000 /* 001D351C: nop */
    .word 0x2483FFE0 /* 001D3520: addiu      $v1, $a0, -0x20 */
    .word 0x1000001B /* 001D3524: b          .L001D3594 */
    .word 0xA0E30000 /* 001D3528: sb         $v1, 0x0($a3) */
    /* .L001D352C: */
    .word 0x1A600019 /* 001D352C: blez       $s3, .L001D3594 */
    .word 0x00000000 /* 001D3530: nop */
    .word 0x00129040 /* 001D3534: sll        $s2, $s2, 1 */
    .word 0x00118840 /* 001D3538: sll        $s1, $s1, 1 */
    .word 0x2665FFFF /* 001D353C: addiu      $a1, $s3, -0x1 */
    .word 0x72403628 /* 001D3540: paddub     $a2, $s2, $zero */
    jal func_001D3440 /* 001D3544: jal        func_001D3440 */
    .word 0x72203E28 /* 001D3548: paddub     $a3, $s1, $zero */
    .word 0x2665FFFF /* 001D354C: addiu      $a1, $s3, -0x1 */
    .word 0x26460001 /* 001D3550: addiu      $a2, $s2, 0x1 */
    .word 0x72802628 /* 001D3554: paddub     $a0, $s4, $zero */
    .word 0x72203E28 /* 001D3558: paddub     $a3, $s1, $zero */
    jal func_001D3440 /* 001D355C: jal        func_001D3440 */
    .word 0x72004628 /* 001D3560: paddub     $t0, $s0, $zero */
    .word 0x2665FFFF /* 001D3564: addiu      $a1, $s3, -0x1 */
    .word 0x26460001 /* 001D3568: addiu      $a2, $s2, 0x1 */
    .word 0x26270001 /* 001D356C: addiu      $a3, $s1, 0x1 */
    .word 0x72802628 /* 001D3570: paddub     $a0, $s4, $zero */
    jal func_001D3440 /* 001D3574: jal        func_001D3440 */
    .word 0x72004628 /* 001D3578: paddub     $t0, $s0, $zero */
    .word 0x2665FFFF /* 001D357C: addiu      $a1, $s3, -0x1 */
    .word 0x26270001 /* 001D3580: addiu      $a3, $s1, 0x1 */
    .word 0x72802628 /* 001D3584: paddub     $a0, $s4, $zero */
    .word 0x72403628 /* 001D3588: paddub     $a2, $s2, $zero */
    jal func_001D3440 /* 001D358C: jal        func_001D3440 */
    .word 0x72004628 /* 001D3590: paddub     $t0, $s0, $zero */
    /* .L001D3594: */
    .word 0x7BBF0050 /* 001D3594: lq         $ra, 0x50($sp) */
    .word 0x7BB40040 /* 001D3598: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D359C: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D35A0: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D35A4: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D35A8: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D35AC: jr         $ra */
    .word 0x27BD0060 /* 001D35B0: addiu      $sp, $sp, 0x60 */
}

#else

extern "C" int func_001D3440(void *self, int level, int x, int y, void *p1, void *p2) {
    char *zm = (char *)self;
    void ***root = *(void ****)(zm + 0x0);
    char *cell = (char *)root[level][x] + y * 2;

    if ((cell[1] & 0x20) != 0) {
        int min_x = *(int *)(zm + 0xF4) >> level;
        int max_x = *(int *)(zm + 0xFC) >> level;
        int min_y = *(int *)(zm + 0xF8) >> level;
        int max_y = *(int *)(zm + 0x100) >> level;

        if (x < min_x || x > max_x || y < min_y || y > max_y) {
            return 0;
        }

        if (p1 != 0) {
            if ((cell[0] & 0x20) == 0) {
                cell[0] += 0x20;
            }
        } else {
            if ((cell[0] & 0x20) != 0) {
                cell[0] -= 0x20;
            }
        }
        return 0;
    }

    if (level <= 0) {
        return 0;
    }

    int next_lvl = level - 1;
    int x2 = x * 2;
    int y2 = y * 2;

    func_001D3440(self, next_lvl, x2, y2, p1, p2);
    func_001D3440(self, next_lvl, x2 + 1, y2, p1, p2);
    func_001D3440(self, next_lvl, x2 + 1, y2 + 1, p1, p2);
    func_001D3440(self, next_lvl, x2, y2 + 1, p1, p2);

    return 0;
}

#endif
