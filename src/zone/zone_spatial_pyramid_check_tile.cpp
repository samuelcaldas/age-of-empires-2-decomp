#pragma exceptions off

#include "zone_spatial_pyramid_check_tile.h"

#if defined(__mips__)

extern "C" asm void func_001D29F0(void *self, int y, int x, void *out_flag) {
    .word 0x8C8A0098 /* 001D29F0: lw         $t2, 0x98($a0) */
    .word 0x00061880 /* 001D29F4: sll        $v1, $a2, 2 */
    .word 0x000540C0 /* 001D29F8: sll        $t0, $a1, 3 */
    .word 0x01054023 /* 001D29FC: subu       $t0, $t0, $a1 */
    .word 0x00084080 /* 001D2A00: sll        $t0, $t0, 2 */
    .word 0x8C89009C /* 001D2A04: lw         $t1, 0x9C($a0) */
    .word 0x01435021 /* 001D2A08: addu       $t2, $t2, $v1 */
    .word 0x44800800 /* 001D2A0C: mtc1       $zero, $f1 */
    .word 0x8D4A0000 /* 001D2A10: lw         $t2, 0x0($t2) */
    .word 0x010A5021 /* 001D2A14: addu       $t2, $t0, $t2 */
    .word 0x914A0005 /* 001D2A18: lbu        $t2, 0x5($t2) */
    .word 0x000A5080 /* 001D2A1C: sll        $t2, $t2, 2 */
    .word 0x012A4821 /* 001D2A20: addu       $t1, $t1, $t2 */
    .word 0xC5200000 /* 001D2A24: lwc1       $f0, 0x0($t1) */
    .word 0x46010036 /* 001D2A28: c.le.s     $f0, $f1 */
    .word 0x00000000 /* 001D2A2C: nop */
    .word 0x4501000D /* 001D2A30: bc1t       .L001D2A68 */
    .word 0x00000000 /* 001D2A34: nop */
    .word 0x8F8A8A84 /* 001D2A38: lw         $t2, -0x757C($gp) */
    .word 0x3C010013 /* 001D2A3C: lui        $at, 0x13 */
    .word 0x00054880 /* 001D2A40: sll        $t1, $a1, 2 */
    .word 0x01410821 /* 001D2A44: addu       $at, $t2, $at */
    .word 0x8C2AB438 /* 001D2A48: lw         $t2, -0x4BC8($at) */
    .word 0x01435021 /* 001D2A4C: addu       $t2, $t2, $v1 */
    .word 0x8D4A0000 /* 001D2A50: lw         $t2, 0x0($t2) */
    .word 0x01495021 /* 001D2A54: addu       $t2, $t2, $t1 */
    .word 0x8D4A0000 /* 001D2A58: lw         $t2, 0x0($t2) */
    .word 0x314A4000 /* 001D2A5C: andi       $t2, $t2, 0x4000 */
    .word 0x11400003 /* 001D2A60: beqz       $t2, .L001D2A70 */
    .word 0x00000000 /* 001D2A64: nop */
    /* .L001D2A68: */
    .word 0x1000007C /* 001D2A68: b          .L001D2C5C */
    .word 0xA0E00000 /* 001D2A6C: sb         $zero, 0x0($a3) */
    /* .L001D2A70: */
    .word 0x18A0001C /* 001D2A70: blez       $a1, .L001D2AE4 */
    .word 0xA0E00000 /* 001D2A74: sb         $zero, 0x0($a3) */
    .word 0x8C8B0098 /* 001D2A78: lw         $t3, 0x98($a0) */
    .word 0x8C8A009C /* 001D2A7C: lw         $t2, 0x9C($a0) */
    .word 0x01635821 /* 001D2A80: addu       $t3, $t3, $v1 */
    .word 0x8D6B0000 /* 001D2A84: lw         $t3, 0x0($t3) */
    .word 0x010B5821 /* 001D2A88: addu       $t3, $t0, $t3 */
    .word 0x916BFFE9 /* 001D2A8C: lbu        $t3, -0x17($t3) */
    .word 0x000B5880 /* 001D2A90: sll        $t3, $t3, 2 */
    .word 0x014B5021 /* 001D2A94: addu       $t2, $t2, $t3 */
    .word 0xC5400000 /* 001D2A98: lwc1       $f0, 0x0($t2) */
    .word 0x46010036 /* 001D2A9C: c.le.s     $f0, $f1 */
    .word 0x00000000 /* 001D2AA0: nop */
    .word 0x4501000F /* 001D2AA4: bc1t       .L001D2AE4 */
    .word 0x00000000 /* 001D2AA8: nop */
    .word 0x8F8A8A84 /* 001D2AAC: lw         $t2, -0x757C($gp) */
    .word 0x3C010013 /* 001D2AB0: lui        $at, 0x13 */
    .word 0x01410821 /* 001D2AB4: addu       $at, $t2, $at */
    .word 0x8C2AB438 /* 001D2AB8: lw         $t2, -0x4BC8($at) */
    .word 0x01435021 /* 001D2ABC: addu       $t2, $t2, $v1 */
    .word 0x8D4A0000 /* 001D2AC0: lw         $t2, 0x0($t2) */
    .word 0x012A5021 /* 001D2AC4: addu       $t2, $t1, $t2 */
    .word 0x8D4AFFFC /* 001D2AC8: lw         $t2, -0x4($t2) */
    .word 0x314A4000 /* 001D2ACC: andi       $t2, $t2, 0x4000 */
    .word 0x15400004 /* 001D2AD0: bnez       $t2, .L001D2AE4 */
    .word 0x00000000 /* 001D2AD4: nop */
    .word 0x90EA0000 /* 001D2AD8: lbu        $t2, 0x0($a3) */
    .word 0x254A0002 /* 001D2ADC: addiu      $t2, $t2, 0x2 */
    .word 0xA0EA0000 /* 001D2AE0: sb         $t2, 0x0($a3) */
    /* .L001D2AE4: */
    .word 0x18C0001D /* 001D2AE4: blez       $a2, .L001D2B5C */
    .word 0x00000000 /* 001D2AE8: nop */
    .word 0x8C8B0098 /* 001D2AEC: lw         $t3, 0x98($a0) */
    .word 0x8C8A009C /* 001D2AF0: lw         $t2, 0x9C($a0) */
    .word 0x44800000 /* 001D2AF4: mtc1       $zero, $f0 */
    .word 0x006B5821 /* 001D2AF8: addu       $t3, $v1, $t3 */
    .word 0x8D6BFFFC /* 001D2AFC: lw         $t3, -0x4($t3) */
    .word 0x010B5821 /* 001D2B00: addu       $t3, $t0, $t3 */
    .word 0x916B0005 /* 001D2B04: lbu        $t3, 0x5($t3) */
    .word 0x000B5880 /* 001D2B08: sll        $t3, $t3, 2 */
    .word 0x014B5021 /* 001D2B0C: addu       $t2, $t2, $t3 */
    .word 0xC5410000 /* 001D2B10: lwc1       $f1, 0x0($t2) */
    .word 0x46000836 /* 001D2B14: c.le.s     $f1, $f0 */
    .word 0x00000000 /* 001D2B18: nop */
    .word 0x4501000F /* 001D2B1C: bc1t       .L001D2B5C */
    .word 0x00000000 /* 001D2B20: nop */
    .word 0x8F8A8A84 /* 001D2B24: lw         $t2, -0x757C($gp) */
    .word 0x3C010013 /* 001D2B28: lui        $at, 0x13 */
    .word 0x01410821 /* 001D2B2C: addu       $at, $t2, $at */
    .word 0x8C2AB438 /* 001D2B30: lw         $t2, -0x4BC8($at) */
    .word 0x006A5021 /* 001D2B34: addu       $t2, $v1, $t2 */
    .word 0x8D4AFFFC /* 001D2B38: lw         $t2, -0x4($t2) */
    .word 0x01495021 /* 001D2B3C: addu       $t2, $t2, $t1 */
    .word 0x8D4A0000 /* 001D2B40: lw         $t2, 0x0($t2) */
    .word 0x314A4000 /* 001D2B44: andi       $t2, $t2, 0x4000 */
    .word 0x15400004 /* 001D2B48: bnez       $t2, .L001D2B5C */
    .word 0x00000000 /* 001D2B4C: nop */
    .word 0x90EA0000 /* 001D2B50: lbu        $t2, 0x0($a3) */
    .word 0x254A0001 /* 001D2B54: addiu      $t2, $t2, 0x1 */
    .word 0xA0EA0000 /* 001D2B58: sb         $t2, 0x0($a3) */
    /* .L001D2B5C: */
    .word 0x8C8A00EC /* 001D2B5C: lw         $t2, 0xEC($a0) */
    .word 0x00AA082A /* 001D2B60: slt        $at, $a1, $t2 */
    .word 0x1020001D /* 001D2B64: beqz       $at, .L001D2BDC */
    .word 0x00000000 /* 001D2B68: nop */
    .word 0x8C8A0098 /* 001D2B6C: lw         $t2, 0x98($a0) */
    .word 0x8C85009C /* 001D2B70: lw         $a1, 0x9C($a0) */
    .word 0x44800000 /* 001D2B74: mtc1       $zero, $f0 */
    .word 0x01435021 /* 001D2B78: addu       $t2, $t2, $v1 */
    .word 0x8D4A0000 /* 001D2B7C: lw         $t2, 0x0($t2) */
    .word 0x010A5021 /* 001D2B80: addu       $t2, $t0, $t2 */
    .word 0x914A0021 /* 001D2B84: lbu        $t2, 0x21($t2) */
    .word 0x000A5080 /* 001D2B88: sll        $t2, $t2, 2 */
    .word 0x00AA2821 /* 001D2B8C: addu       $a1, $a1, $t2 */
    .word 0xC4A10000 /* 001D2B90: lwc1       $f1, 0x0($a1) */
    .word 0x46000836 /* 001D2B94: c.le.s     $f1, $f0 */
    .word 0x00000000 /* 001D2B98: nop */
    .word 0x4501000F /* 001D2B9C: bc1t       .L001D2BDC */
    .word 0x00000000 /* 001D2BA0: nop */
    .word 0x8F858A84 /* 001D2BA4: lw         $a1, -0x757C($gp) */
    .word 0x3C010013 /* 001D2BA8: lui        $at, 0x13 */
    .word 0x00A10821 /* 001D2BAC: addu       $at, $a1, $at */
    .word 0x8C25B438 /* 001D2BB0: lw         $a1, -0x4BC8($at) */
    .word 0x00A32821 /* 001D2BB4: addu       $a1, $a1, $v1 */
    .word 0x8CA50000 /* 001D2BB8: lw         $a1, 0x0($a1) */
    .word 0x01252821 /* 001D2BBC: addu       $a1, $t1, $a1 */
    .word 0x8CA50004 /* 001D2BC0: lw         $a1, 0x4($a1) */
    .word 0x30A54000 /* 001D2BC4: andi       $a1, $a1, 0x4000 */
    .word 0x14A00004 /* 001D2BC8: bnez       $a1, .L001D2BDC */
    .word 0x00000000 /* 001D2BCC: nop */
    .word 0x90E50000 /* 001D2BD0: lbu        $a1, 0x0($a3) */
    .word 0x24A50004 /* 001D2BD4: addiu      $a1, $a1, 0x4 */
    .word 0xA0E50000 /* 001D2BD8: sb         $a1, 0x0($a3) */
    /* .L001D2BDC: */
    .word 0x8C8500F0 /* 001D2BDC: lw         $a1, 0xF0($a0) */
    .word 0x00C5082A /* 001D2BE0: slt        $at, $a2, $a1 */
    .word 0x1020001D /* 001D2BE4: beqz       $at, .L001D2C5C */
    .word 0x00000000 /* 001D2BE8: nop */
    .word 0x8C850098 /* 001D2BEC: lw         $a1, 0x98($a0) */
    .word 0x44800000 /* 001D2BF0: mtc1       $zero, $f0 */
    .word 0x00652821 /* 001D2BF4: addu       $a1, $v1, $a1 */
    .word 0x8C84009C /* 001D2BF8: lw         $a0, 0x9C($a0) */
    .word 0x8CA50004 /* 001D2BFC: lw         $a1, 0x4($a1) */
    .word 0x01052821 /* 001D2C00: addu       $a1, $t0, $a1 */
    .word 0x90A50005 /* 001D2C04: lbu        $a1, 0x5($a1) */
    .word 0x00052880 /* 001D2C08: sll        $a1, $a1, 2 */
    .word 0x00852021 /* 001D2C0C: addu       $a0, $a0, $a1 */
    .word 0xC4810000 /* 001D2C10: lwc1       $f1, 0x0($a0) */
    .word 0x46000836 /* 001D2C14: c.le.s     $f1, $f0 */
    .word 0x00000000 /* 001D2C18: nop */
    .word 0x4501000F /* 001D2C1C: bc1t       .L001D2C5C */
    .word 0x00000000 /* 001D2C20: nop */
    .word 0x8F848A84 /* 001D2C24: lw         $a0, -0x757C($gp) */
    .word 0x3C010013 /* 001D2C28: lui        $at, 0x13 */
    .word 0x00810821 /* 001D2C2C: addu       $at, $a0, $at */
    .word 0x8C24B438 /* 001D2C30: lw         $a0, -0x4BC8($at) */
    .word 0x00641821 /* 001D2C34: addu       $v1, $v1, $a0 */
    .word 0x8C630004 /* 001D2C38: lw         $v1, 0x4($v1) */
    .word 0x00691821 /* 001D2C3C: addu       $v1, $v1, $t1 */
    .word 0x8C630000 /* 001D2C40: lw         $v1, 0x0($v1) */
    .word 0x30634000 /* 001D2C44: andi       $v1, $v1, 0x4000 */
    .word 0x14600004 /* 001D2C48: bnez       $v1, .L001D2C5C */
    .word 0x00000000 /* 001D2C4C: nop */
    .word 0x90E30000 /* 001D2C50: lbu        $v1, 0x0($a3) */
    .word 0x24630008 /* 001D2C54: addiu      $v1, $v1, 0x8 */
    .word 0xA0E30000 /* 001D2C58: sb         $v1, 0x0($a3) */
    /* .L001D2C5C: */
    .word 0x03E00008 /* 001D2C5C: jr         $ra */
    .word 0x00000000 /* 001D2C60: nop */
}

#else

extern "C" void func_001D29F0(void *self, int y, int x, void *out_flag) {
    char *zm = (char *)self;
    char **cols = *(char ***)(zm + 0x98);
    char *col = cols[x];
    char *tile = col + y * 28;
    unsigned char terrain = *(unsigned char *)(tile + 5);

    float *thresholds = *(float **)(zm + 0x9C);
    if (thresholds[terrain] <= 0.0f) {
        *(unsigned char *)out_flag = 0;
        return;
    }

    *(unsigned char *)out_flag = 0;

    // North neighbor (y - 1)
    if (y > 0) {
        char *n_tile = col + (y - 1) * 28;
        unsigned char n_terrain = *(unsigned char *)(n_tile + 5);
        if (thresholds[n_terrain] > 0.0f) {
            *(unsigned char *)out_flag = (unsigned char)(*(unsigned char *)out_flag + 0x2);
        }
    }

    // West neighbor (x - 1)
    if (x > 0) {
        char *w_col = cols[x - 1];
        char *w_tile = w_col + y * 28;
        unsigned char w_terrain = *(unsigned char *)(w_tile + 5);
        if (thresholds[w_terrain] > 0.0f) {
            *(unsigned char *)out_flag = (unsigned char)(*(unsigned char *)out_flag + 0x1);
        }
    }

    // South neighbor (y + 1)
    int max_y = *(int *)(zm + 0xEC);
    if (y < max_y) {
        char *s_tile = col + (y + 1) * 28;
        unsigned char s_terrain = *(unsigned char *)(s_tile + 5);
        if (thresholds[s_terrain] > 0.0f) {
            *(unsigned char *)out_flag = (unsigned char)(*(unsigned char *)out_flag + 0x4);
        }
    }

    // East neighbor (x + 1)
    int max_x = *(int *)(zm + 0xF0);
    if (x < max_x) {
        char *e_col = cols[x + 1];
        char *e_tile = e_col + y * 28;
        unsigned char e_terrain = *(unsigned char *)(e_tile + 5);
        if (thresholds[e_terrain] > 0.0f) {
            *(unsigned char *)out_flag = (unsigned char)(*(unsigned char *)out_flag + 0x8);
        }
    }
}

#endif
