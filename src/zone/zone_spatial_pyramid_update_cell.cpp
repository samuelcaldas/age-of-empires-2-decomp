#pragma exceptions off

#include "zone_spatial_pyramid_update_cell.h"

#if defined(__mips__)

extern "C" asm int func_001D21B0(void *self, unsigned char level, int x, int y) {
    .word 0x27BDFFA0 /* 001D21B0: addiu      $sp, $sp, -0x60 */
    .word 0x7FBF0050 /* 001D21B4: sq         $ra, 0x50($sp) */
    .word 0x7FB40040 /* 001D21B8: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D21BC: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D21C0: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D21C4: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D21C8: sq         $s0, 0x0($sp) */
    .word 0x8C820000 /* 001D21CC: lw         $v0, 0x0($a0) */
    .word 0x30A800FF /* 001D21D0: andi       $t0, $a1, 0xFF */
    .word 0x00082880 /* 001D21D4: sll        $a1, $t0, 2 */
    .word 0x00061880 /* 001D21D8: sll        $v1, $a2, 2 */
    .word 0x00079040 /* 001D21DC: sll        $s2, $a3, 1 */
    .word 0x7080A628 /* 001D21E0: paddub     $s4, $a0, $zero */
    .word 0x00451021 /* 001D21E4: addu       $v0, $v0, $a1 */
    .word 0x8C420000 /* 001D21E8: lw         $v0, 0x0($v0) */
    .word 0x00431021 /* 001D21EC: addu       $v0, $v0, $v1 */
    .word 0x8C420000 /* 001D21F0: lw         $v0, 0x0($v0) */
    .word 0x00528021 /* 001D21F4: addu       $s0, $v0, $s2 */
    .word 0xA2000001 /* 001D21F8: sb         $zero, 0x1($s0) */
    .word 0x1900002B /* 001D21FC: blez       $t0, .L001D22AC */
    .word 0xA2000000 /* 001D2200: sb         $zero, 0x0($s0) */
    .word 0x2513FFFF /* 001D2204: addiu      $s3, $t0, -0x1 */
    .word 0x00068840 /* 001D2208: sll        $s1, $a2, 1 */
    .word 0x326500FF /* 001D220C: andi       $a1, $s3, 0xFF */
    .word 0x72203628 /* 001D2210: paddub     $a2, $s1, $zero */
    jal func_001D21B0
    .word 0x72403E28 /* 001D2218: paddub     $a3, $s2, $zero */
    .word 0x10400005 /* 001D221C: beqz       $v0, .L001D2234 */
    .word 0x26260001 /* 001D2220: addiu      $a2, $s1, 0x1 */
    .word 0x92020001 /* 001D2224: lbu        $v0, 0x1($s0) */
    .word 0x24420001 /* 001D2228: addiu      $v0, $v0, 0x1 */
    .word 0xA2020001 /* 001D222C: sb         $v0, 0x1($s0) */
    .word 0x26260001 /* 001D2230: addiu      $a2, $s1, 0x1 */
    /* .L001D2234: */
    .word 0x326500FF /* 001D2234: andi       $a1, $s3, 0xFF */
    .word 0x72802628 /* 001D2238: paddub     $a0, $s4, $zero */
    jal func_001D21B0
    .word 0x72403E28 /* 001D2240: paddub     $a3, $s2, $zero */
    .word 0x10400005 /* 001D2244: beqz       $v0, .L001D225C */
    .word 0x26470001 /* 001D2248: addiu      $a3, $s2, 0x1 */
    .word 0x92020001 /* 001D224C: lbu        $v0, 0x1($s0) */
    .word 0x24420002 /* 001D2250: addiu      $v0, $v0, 0x2 */
    .word 0xA2020001 /* 001D2254: sb         $v0, 0x1($s0) */
    .word 0x26470001 /* 001D2258: addiu      $a3, $s2, 0x1 */
    /* .L001D225C: */
    .word 0x326500FF /* 001D225C: andi       $a1, $s3, 0xFF */
    .word 0x72802628 /* 001D2260: paddub     $a0, $s4, $zero */
    jal func_001D21B0
    .word 0x72203628 /* 001D2268: paddub     $a2, $s1, $zero */
    .word 0x10400005 /* 001D226C: beqz       $v0, .L001D2284 */
    .word 0x26260001 /* 001D2270: addiu      $a2, $s1, 0x1 */
    .word 0x92020001 /* 001D2274: lbu        $v0, 0x1($s0) */
    .word 0x24420004 /* 001D2278: addiu      $v0, $v0, 0x4 */
    .word 0xA2020001 /* 001D227C: sb         $v0, 0x1($s0) */
    .word 0x26260001 /* 001D2280: addiu      $a2, $s1, 0x1 */
    /* .L001D2284: */
    .word 0x26470001 /* 001D2284: addiu      $a3, $s2, 0x1 */
    .word 0x326500FF /* 001D2288: andi       $a1, $s3, 0xFF */
    jal func_001D21B0
    .word 0x72802628 /* 001D2290: paddub     $a0, $s4, $zero */
    .word 0x10400010 /* 001D2294: beqz       $v0, .L001D22D8 */
    .word 0x00000000 /* 001D2298: nop */
    .word 0x92020001 /* 001D229C: lbu        $v0, 0x1($s0) */
    .word 0x24420008 /* 001D22A0: addiu      $v0, $v0, 0x8 */
    .word 0x1000000C /* 001D22A4: b          .L001D22D8 */
    .word 0xA2020001 /* 001D22A8: sb         $v0, 0x1($s0) */
    /* .L001D22AC: */
    .word 0x8E8200E4 /* 001D22AC: lw         $v0, 0xE4($s4) */
    .word 0x00C2082A /* 001D22B0: slt        $at, $a2, $v0 */
    .word 0x10200005 /* 001D22B4: beqz       $at, .L001D22CC */
    .word 0x00000000 /* 001D22B8: nop */
    .word 0x8E8200E8 /* 001D22BC: lw         $v0, 0xE8($s4) */
    .word 0x00E2102A /* 001D22C0: slt        $v0, $a3, $v0 */
    .word 0x14400004 /* 001D22C4: bnez       $v0, .L001D22D8 */
    .word 0x00000000 /* 001D22C8: nop */
    /* .L001D22CC: */
    .word 0x92020001 /* 001D22CC: lbu        $v0, 0x1($s0) */
    .word 0x2442000F /* 001D22D0: addiu      $v0, $v0, 0xF */
    .word 0xA2020001 /* 001D22D4: sb         $v0, 0x1($s0) */
    /* .L001D22D8: */
    .word 0x92030001 /* 001D22D8: lbu        $v1, 0x1($s0) */
    .word 0x2402000F /* 001D22DC: addiu      $v0, $zero, 0xF */
    .word 0x3063000F /* 001D22E0: andi       $v1, $v1, 0xF */
    .word 0x14620004 /* 001D22E4: bne        $v1, $v0, .L001D22F8 */
    .word 0x70001628 /* 001D22E8: paddub     $v0, $zero, $zero */
    .word 0x10000002 /* 001D22EC: b          .L001D22F8 */
    .word 0x24020001 /* 001D22F0: addiu      $v0, $zero, 0x1 */
    .word 0x70001628 /* 001D22F4: paddub     $v0, $zero, $zero */
    /* .L001D22F8: */
    .word 0x7BBF0050 /* 001D22F8: lq         $ra, 0x50($sp) */
    .word 0x7BB40040 /* 001D22FC: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D2300: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D2304: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D2308: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D230C: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D2310: jr         $ra */
    .word 0x27BD0060 /* 001D2314: addiu      $sp, $sp, 0x60 */
}

#else

extern "C" int func_001D21B0(void *self, unsigned char level, int x, int y) {
    char *zm = (char *)self;
    void ***root = *(void ****)zm;
    char *cell = (char *)root[level][x] + (y << 1);

    cell[1] = 0;

    if ((int)level > 0) {
        cell[0] = 0;
        unsigned char next_lvl = level - 1;
        int x2 = x << 1;
        int y2 = y << 1;

        if (func_001D21B0(self, next_lvl, x2, y2)) {
            cell[1] += 1;
        }
        if (func_001D21B0(self, next_lvl, x2 + 1, y2)) {
            cell[1] += 2;
        }
        if (func_001D21B0(self, next_lvl, x2, y2 + 1)) {
            cell[1] += 4;
        }
        if (func_001D21B0(self, next_lvl, x2 + 1, y2 + 1)) {
            cell[1] += 8;
        }
    } else {
        int max_x = *(int *)(zm + 0xE4);
        if (x >= max_x || y >= *(int *)(zm + 0xE8)) {
            cell[1] += 0xF;
        }
    }

    if ((cell[1] & 0xF) == 0xF) {
        return 1;
    }
    return 0;
}

#endif
