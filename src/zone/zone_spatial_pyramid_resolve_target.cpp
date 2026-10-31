#pragma exceptions off

#include "zone_spatial_pyramid_resolve_target.h"

extern "C" {
int func_1D4E00(void *self, int target_x, int target_y, int level, int child_x, int child_y);
}

#if defined(__mips__)

extern "C" asm void func_001D4C20(void *self, void *node, int *out_x, int *out_y, int tx, int ty) {
    .word 0x27BDFF40 /* 001D4C20: addiu      $sp, $sp, -0xC0 */
    .word 0x7FBF0090 /* 001D4C24: sq         $ra, 0x90($sp) */
    .word 0x7FBE0080 /* 001D4C28: sq         $fp, 0x80($sp) */
    .word 0x7FB70070 /* 001D4C2C: sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* 001D4C30: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 001D4C34: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D4C38: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D4C3C: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D4C40: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D4C44: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D4C48: sq         $s0, 0x0($sp) */
    .word 0x8CB4000C /* 001D4C4C: lw         $s4, 0xC($a1) */
    .word 0x7080B628 /* 001D4C50: paddub     $s6, $a0, $zero */
    .word 0x70C0AE28 /* 001D4C54: paddub     $s5, $a2, $zero */
    .word 0x70E0BE28 /* 001D4C58: paddub     $s7, $a3, $zero */
    .word 0x7100F628 /* 001D4C5C: paddub     $fp, $t0, $zero */
    .word 0x16800006 /* 001D4C60: bnez       $s4, .L001D4C7C */
    .word 0xAFA900AC /* 001D4C64: sw         $t1, 0xAC($sp) */
    .word 0x8CA30004 /* 001D4C68: lw         $v1, 0x4($a1) */
    .word 0xAEA30000 /* 001D4C6C: sw         $v1, 0x0($s5) */
    .word 0x8CA30008 /* 001D4C70: lw         $v1, 0x8($a1) */
    .word 0x10000056 /* 001D4C74: b          .L001D4DD0 */
    .word 0xAEE30000 /* 001D4C78: sw         $v1, 0x0($s7) */
    /* .L001D4C7C: */
    .word 0x8CB30008 /* 001D4C7C: lw         $s3, 0x8($a1) */
    .word 0x1000004F /* 001D4C80: b          .L001D4DC0 */
    .word 0x8CB20004 /* 001D4C84: lw         $s2, 0x4($a1) */
    /* .L001D4C88: */
    .word 0x8FA200AC /* 001D4C88: lw         $v0, 0xAC($sp) */
    .word 0x2687FFFF /* 001D4C8C: addiu      $a3, $s4, -0x1 */
    .word 0x00FE8007 /* 001D4C90: srav       $s0, $fp, $a3 */
    .word 0x00129040 /* 001D4C94: sll        $s2, $s2, 1 */
    .word 0x00139840 /* 001D4C98: sll        $s3, $s3, 1 */
    .word 0x00E28807 /* 001D4C9C: srav       $s1, $v0, $a3 */
    .word 0x72C02628 /* 001D4CA0: paddub     $a0, $s6, $zero */
    .word 0x72002E28 /* 001D4CA4: paddub     $a1, $s0, $zero */
    .word 0x72203628 /* 001D4CA8: paddub     $a2, $s1, $zero */
    .word 0x72404628 /* 001D4CAC: paddub     $t0, $s2, $zero */
    jal func_1D4E00  /* 001D4CB0: jal        func_1D4E00 */
    .word 0x72604E28 /* 001D4CB4: paddub     $t1, $s3, $zero */
    .word 0x2687FFFF /* 001D4CB8: addiu      $a3, $s4, -0x1 */
    .word 0x26690001 /* 001D4CBC: addiu      $t1, $s3, 0x1 */
    .word 0xAFA200B0 /* 001D4CC0: sw         $v0, 0xB0($sp) */
    .word 0x72C02628 /* 001D4CC4: paddub     $a0, $s6, $zero */
    .word 0x72002E28 /* 001D4CC8: paddub     $a1, $s0, $zero */
    .word 0x72203628 /* 001D4CCC: paddub     $a2, $s1, $zero */
    jal func_1D4E00  /* 001D4CD0: jal        func_1D4E00 */
    .word 0x72404628 /* 001D4CD4: paddub     $t0, $s2, $zero */
    .word 0x2687FFFF /* 001D4CD8: addiu      $a3, $s4, -0x1 */
    .word 0x26480001 /* 001D4CDC: addiu      $t0, $s2, 0x1 */
    .word 0xAFA200B4 /* 001D4CE0: sw         $v0, 0xB4($sp) */
    .word 0x72C02628 /* 001D4CE4: paddub     $a0, $s6, $zero */
    .word 0x72002E28 /* 001D4CE8: paddub     $a1, $s0, $zero */
    .word 0x72203628 /* 001D4CEC: paddub     $a2, $s1, $zero */
    jal func_1D4E00  /* 001D4CF0: jal        func_1D4E00 */
    .word 0x72604E28 /* 001D4CF4: paddub     $t1, $s3, $zero */
    .word 0x2687FFFF /* 001D4CF8: addiu      $a3, $s4, -0x1 */
    .word 0x26480001 /* 001D4CFC: addiu      $t0, $s2, 0x1 */
    .word 0x26690001 /* 001D4D00: addiu      $t1, $s3, 0x1 */
    .word 0xAFA200B8 /* 001D4D04: sw         $v0, 0xB8($sp) */
    .word 0x72002E28 /* 001D4D08: paddub     $a1, $s0, $zero */
    .word 0x72203628 /* 001D4D0C: paddub     $a2, $s1, $zero */
    jal func_1D4E00  /* 001D4D10: jal        func_1D4E00 */
    .word 0x72C02628 /* 001D4D14: paddub     $a0, $s6, $zero */
    .word 0x3C030001 /* 001D4D18: lui        $v1, (0x1869F >> 16) */
    .word 0x2405FFFF /* 001D4D1C: addiu      $a1, $zero, -0x1 */
    .word 0xAFA200BC /* 001D4D20: sw         $v0, 0xBC($sp) */
    .word 0x3466869F /* 001D4D24: ori        $a2, $v1, (0x1869F & 0xFFFF) */
    .word 0x1000000C /* 001D4D28: b          .L001D4D5C */
    .word 0x70002628 /* 001D4D2C: paddub     $a0, $zero, $zero */
    .word 0x00041880 /* 001D4D30: sll        $v1, $a0, 2 */
    /* .L001D4D34: */
    .word 0x007D1821 /* 001D4D34: addu       $v1, $v1, $sp */
    .word 0x8C6300B0 /* 001D4D38: lw         $v1, 0xB0($v1) */
    .word 0x04620007 /* 001D4D3C: bltzl      $v1, .L001D4D5C */
    .word 0x24840001 /* 001D4D40: addiu      $a0, $a0, 0x1 */
    .word 0x0066082A /* 001D4D44: slt        $at, $v1, $a2 */
    .word 0x10200003 /* 001D4D48: beqz       $at, .L001D4D58 */
    .word 0x00000000 /* 001D4D4C: nop */
    .word 0x70603628 /* 001D4D50: paddub     $a2, $v1, $zero */
    .word 0x70802E28 /* 001D4D54: paddub     $a1, $a0, $zero */
    /* .L001D4D58: */
    .word 0x24840001 /* 001D4D58: addiu      $a0, $a0, 0x1 */
    /* .L001D4D5C: */
    .word 0x28830004 /* 001D4D5C: slti       $v1, $a0, 0x4 */
    .word 0x1460FFF4 /* 001D4D60: bnez       $v1, .L001D4D34 */
    .word 0x00041880 /* 001D4D64: sll        $v1, $a0, 2 */
    .word 0x24030003 /* 001D4D68: addiu      $v1, $zero, 0x3 */
    .word 0x50A30012 /* 001D4D6C: beql       $a1, $v1, .L001D4DB8 */
    .word 0x26520001 /* 001D4D70: addiu      $s2, $s2, 0x1 */
    .word 0x24030002 /* 001D4D74: addiu      $v1, $zero, 0x2 */
    .word 0x50A3000C /* 001D4D78: beql       $a1, $v1, .L001D4DAC */
    .word 0x26520001 /* 001D4D7C: addiu      $s2, $s2, 0x1 */
    .word 0x24030001 /* 001D4D80: addiu      $v1, $zero, 0x1 */
    .word 0x50A30006 /* 001D4D84: beql       $a1, $v1, .L001D4DA0 */
    .word 0x26730001 /* 001D4D88: addiu      $s3, $s3, 0x1 */
    .word 0x50A0000C /* 001D4D8C: beql       $a1, $zero, .L001D4DC0 */
    .word 0x2694FFFF /* 001D4D90: addiu      $s4, $s4, -0x1 */
    .word 0x10000009 /* 001D4D94: b          .L001D4DBC */
    .word 0x00000000 /* 001D4D98: nop */
    .word 0x26730001 /* 001D4D9C: addiu      $s3, $s3, 0x1 */
    /* .L001D4DA0: */
    .word 0x10000006 /* 001D4DA0: b          .L001D4DBC */
    .word 0x00000000 /* 001D4DA4: nop */
    .word 0x26520001 /* 001D4DA8: addiu      $s2, $s2, 0x1 */
    /* .L001D4DAC: */
    .word 0x10000003 /* 001D4DAC: b          .L001D4DBC */
    .word 0x00000000 /* 001D4DB0: nop */
    .word 0x26520001 /* 001D4DB4: addiu      $s2, $s2, 0x1 */
    /* .L001D4DB8: */
    .word 0x26730001 /* 001D4DB8: addiu      $s3, $s3, 0x1 */
    /* .L001D4DBC: */
    .word 0x2694FFFF /* 001D4DBC: addiu      $s4, $s4, -0x1 */
    /* .L001D4DC0: */
    .word 0x1E80FFB1 /* 001D4DC0: bgtz       $s4, .L001D4C88 */
    .word 0x00000000 /* 001D4DC4: nop */
    .word 0xAEB20000 /* 001D4DC8: sw         $s2, 0x0($s5) */
    .word 0xAEF30000 /* 001D4DCC: sw         $s3, 0x0($s7) */
    /* .L001D4DD0: */
    .word 0x7BBF0090 /* 001D4DD0: lq         $ra, 0x90($sp) */
    .word 0x7BBE0080 /* 001D4DD4: lq         $fp, 0x80($sp) */
    .word 0x7BB70070 /* 001D4DD8: lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* 001D4DDC: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 001D4DE0: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D4DE4: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D4DE8: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D4DEC: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D4DF0: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D4DF4: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D4DF8: jr         $ra */
    .word 0x27BD00C0 /* 001D4DFC: addiu      $sp, $sp, 0xC0 */
}

#else

extern "C" void func_001D4C20(void *self, void *node, int *out_x, int *out_y, int tx, int ty) {
    char *n = (char *)node;
    int level = *(int *)(n + 0xC);

    if (level == 0) {
        *out_x = *(int *)(n + 0x4);
        *out_y = *(int *)(n + 0x8);
        return;
    }

    int cur_x = *(int *)(n + 0x4);
    int cur_y = *(int *)(n + 0x8);

    while (level > 0) {
        int next_level = level - 1;
        int s0 = tx >> next_level;
        int s1 = ty >> next_level;
        cur_x <<= 1;
        cur_y <<= 1;

        int costs[4];
        costs[0] = func_1D4E00(self, s0, s1, next_level, cur_x, cur_y);
        costs[1] = func_1D4E00(self, s0, s1, next_level, cur_x, cur_y + 1);
        costs[2] = func_1D4E00(self, s0, s1, next_level, cur_x + 1, cur_y);
        costs[3] = func_1D4E00(self, s0, s1, next_level, cur_x + 1, cur_y + 1);

        int best_child = -1;
        int min_cost = 99999;
        for (int i = 0; i < 4; i++) {
            if (costs[i] < 0) continue;
            if (costs[i] < min_cost) {
                min_cost = costs[i];
                best_child = i;
            }
        }

        if (best_child == 3) {
            cur_x += 1;
            cur_y += 1;
        } else if (best_child == 2) {
            cur_x += 1;
        } else if (best_child == 1) {
            cur_y += 1;
        }

        level--;
    }

    *out_x = cur_x;
    *out_y = cur_y;
}

#endif
