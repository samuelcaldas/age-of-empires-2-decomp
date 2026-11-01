#pragma exceptions off

#include "zone_spatial_pyramid_search_radius.h"

extern "C" {
int func_00123350(float f);
int func_001D3EB0(
    void *self, int level, int x, int y, float minX, float minY, float maxX, float maxY, int op
);
}

#if defined(__mips__)

extern "C" asm void func_001D3C70(void *self, int op, float centerX, float centerY, float extent, float radius) {
    .word 0x27BDFF50 /* 001D3C70: addiu      $sp, $sp, -0xB0 */
    .word 0x7FBF00A0 /* 001D3C74: sq         $ra, 0xA0($sp) */
    .word 0x7FB70090 /* 001D3C78: sq         $s7, 0x90($sp) */
    .word 0x7FB60080 /* 001D3C7C: sq         $s6, 0x80($sp) */
    .word 0x7FB50070 /* 001D3C80: sq         $s5, 0x70($sp) */
    .word 0x7FB40060 /* 001D3C84: sq         $s4, 0x60($sp) */
    .word 0x7FB30050 /* 001D3C88: sq         $s3, 0x50($sp) */
    .word 0x7FB20040 /* 001D3C8C: sq         $s2, 0x40($sp) */
    .word 0x7FB10030 /* 001D3C90: sq         $s1, 0x30($sp) */
    .word 0x7FB00020 /* 001D3C94: sq         $s0, 0x20($sp) */
    .word 0xE7B80010 /* 001D3C98: swc1       $f24, 0x10($sp) */
    .word 0xE7B7000C /* 001D3C9C: swc1       $f23, 0xC($sp) */
    .word 0xE7B60008 /* 001D3CA0: swc1       $f22, 0x8($sp) */
    .word 0xE7B50004 /* 001D3CA4: swc1       $f21, 0x4($sp) */
    .word 0xE7B40000 /* 001D3CA8: swc1       $f20, 0x0($sp) */
    .word 0x460E7D00 /* 001D3CAC: add.s      $f20, $f15, $f14 */
    .word 0x7080A628 /* 001D3CB0: paddub     $s4, $a0, $zero */
    .word 0x70A09E28 /* 001D3CB4: paddub     $s3, $a1, $zero */
    .word 0x46006606 /* 001D3CB8: mov.s      $f24, $f12 */
    .word 0x46146301 /* 001D3CBC: sub.s      $f12, $f12, $f20 */
    .word 0x46006DC6 /* 001D3CC0: mov.s      $f23, $f13 */
    .word 0x46007586 /* 001D3CC4: mov.s      $f22, $f14 */
    jal func_00123350 /* 001D3CC8: jal       func_00123350 */
    .word 0x46007D46 /* 001D3CCC: mov.s      $f21, $f15 */
    .word 0x4614BB01 /* 001D3CD0: sub.s      $f12, $f23, $f20 */
    jal func_00123350 /* 001D3CD4: jal       func_00123350 */
    .word 0x70408628 /* 001D3CD8: paddub     $s0, $v0, $zero */
    .word 0x4614C300 /* 001D3CDC: add.s      $f12, $f24, $f20 */
    jal func_00123350 /* 001D3CE0: jal       func_00123350 */
    .word 0x70408E28 /* 001D3CE4: paddub     $s1, $v0, $zero */
    .word 0x4614BB00 /* 001D3CE8: add.s      $f12, $f23, $f20 */
    jal func_00123350 /* 001D3CEC: jal       func_00123350 */
    .word 0x70409628 /* 001D3CF0: paddub     $s2, $v0, $zero */
    .word 0x06010002 /* 001D3CF4: bgez       $s0, .L001D3D00 */
    .word 0x00000000 /* 001D3CF8: nop */
    .word 0x70008628 /* 001D3CFC: paddub     $s0, $zero, $zero */
    /* .L001D3D00: */
    .word 0x06210002 /* 001D3D00: bgez       $s1, .L001D3D0C */
    .word 0x00000000 /* 001D3D04: nop */
    .word 0x70008E28 /* 001D3D08: paddub     $s1, $zero, $zero */
    /* .L001D3D0C: */
    .word 0x8E8300E4 /* 001D3D0C: lw         $v1, 0xE4($s4) */
    .word 0x0243182A /* 001D3D10: slt        $v1, $s2, $v1 */
    .word 0x14600003 /* 001D3D14: bnez       $v1, .L001D3D24 */
    .word 0x00000000 /* 001D3D18: nop */
    .word 0x8E9200EC /* 001D3D1C: lw         $s2, 0xEC($s4) */
    .word 0x00000000 /* 001D3D20: nop */
    /* .L001D3D24: */
    .word 0x8E8300E8 /* 001D3D24: lw         $v1, 0xE8($s4) */
    .word 0x0043182A /* 001D3D28: slt        $v1, $v0, $v1 */
    .word 0x14600003 /* 001D3D2C: bnez       $v1, .L001D3D3C */
    .word 0x00000000 /* 001D3D30: nop */
    .word 0x8E8200F0 /* 001D3D34: lw         $v0, 0xF0($s4) */
    .word 0x00000000 /* 001D3D38: nop */
    /* .L001D3D3C: */
    .word 0xAE9000F4 /* 001D3D3C: sw         $s0, 0xF4($s4) */
    .word 0xAE9100F8 /* 001D3D40: sw         $s1, 0xF8($s4) */
    .word 0xAE9200FC /* 001D3D44: sw         $s2, 0xFC($s4) */
    .word 0xAE820100 /* 001D3D48: sw         $v0, 0x100($s4) */
    .word 0x0002A8C3 /* 001D3D4C: sra        $s5, $v0, 3 */
    .word 0x4600C306 /* 001D3D50: mov.s      $f12, $f24 */
    .word 0x001188C3 /* 001D3D54: sra        $s1, $s1, 3 */
    jal func_00123350 /* 001D3D58: jal       func_00123350 */
    .word 0x001290C3 /* 001D3D5C: sra        $s2, $s2, 3 */
    .word 0xAE820104 /* 001D3D60: sw         $v0, 0x104($s4) */
    jal func_00123350 /* 001D3D64: jal       func_00123350 */
    .word 0x4600BB06 /* 001D3D68: mov.s      $f12, $f23 */
    .word 0x0010B0C3 /* 001D3D6C: sra        $s6, $s0, 3 */
    .word 0xAE820108 /* 001D3D70: sw         $v0, 0x108($s4) */
    .word 0x10000013 /* 001D3D74: b          .L001D3DC4 */
    .word 0x70008628 /* 001D3D78: paddub     $s0, $zero, $zero */
    /* .L001D3D7C: */
    .word 0x1000000D /* 001D3D7C: b          .L001D3DB4 */
    .word 0x7220BE28 /* 001D3D80: paddub     $s7, $s1, $zero */
    .word 0x24050003 /* 001D3D84: addiu      $a1, $zero, 0x3 */
    /* .L001D3D88: */
    .word 0x4600C306 /* 001D3D88: mov.s      $f12, $f24 */
    .word 0x72802628 /* 001D3D8C: paddub     $a0, $s4, $zero */
    .word 0x72C03628 /* 001D3D90: paddub     $a2, $s6, $zero */
    .word 0x72E03E28 /* 001D3D94: paddub     $a3, $s7, $zero */
    .word 0x4600BB46 /* 001D3D98: mov.s      $f13, $f23 */
    .word 0x4600B386 /* 001D3D9C: mov.s      $f14, $f22 */
    .word 0x4600ABC6 /* 001D3DA0: mov.s      $f15, $f21 */
    jal func_001D3EB0 /* 001D3DA4: jal       func_001D3EB0 */
    .word 0x72604628 /* 001D3DA8: paddub     $t0, $s3, $zero */
    .word 0x02028021 /* 001D3DAC: addu       $s0, $s0, $v0 */
    .word 0x26F70001 /* 001D3DB0: addiu      $s7, $s7, 0x1 */
    /* .L001D3DB4: */
    .word 0x02B7082A /* 001D3DB4: slt        $at, $s5, $s7 */
    .word 0x1020FFF3 /* 001D3DB8: beqz       $at, .L001D3D88 */
    .word 0x24050003 /* 001D3DBC: addiu      $a1, $zero, 0x3 */
    .word 0x26D60001 /* 001D3DC0: addiu      $s6, $s6, 0x1 */
    /* .L001D3DC4: */
    .word 0x0256082A /* 001D3DC4: slt        $at, $s2, $s6 */
    .word 0x1020FFEC /* 001D3DC8: beqz       $at, .L001D3D7C */
    .word 0x00000000 /* 001D3DCC: nop */
    .word 0x16000025 /* 001D3DD0: bnez       $s0, .L001D3E68 */
    .word 0x00000000 /* 001D3DD4: nop */
    .word 0x10000021 /* 001D3DD8: b          .L001D3E60 */
    .word 0x24070003 /* 001D3DDC: addiu      $a3, $zero, 0x3 */
    /* .L001D3DE0: */
    .word 0x8E850000 /* 001D3DE0: lw         $a1, 0x0($s4) */
    .word 0x00073080 /* 001D3DE4: sll        $a2, $a3, 2 */
    .word 0x8E840104 /* 001D3DE8: lw         $a0, 0x104($s4) */
    .word 0x8E830108 /* 001D3DEC: lw         $v1, 0x108($s4) */
    .word 0x00A62821 /* 001D3DF0: addu       $a1, $a1, $a2 */
    .word 0x8CA50000 /* 001D3DF4: lw         $a1, 0x0($a1) */
    .word 0x00E42007 /* 001D3DF8: srav       $a0, $a0, $a3 */
    .word 0x00043080 /* 001D3DFC: sll        $a2, $a0, 2 */
    .word 0x00E31807 /* 001D3E00: srav       $v1, $v1, $a3 */
    .word 0x00032040 /* 001D3E04: sll        $a0, $v1, 1 */
    .word 0x00A61821 /* 001D3E08: addu       $v1, $a1, $a2 */
    .word 0x8C630000 /* 001D3E0C: lw         $v1, 0x0($v1) */
    .word 0x00642821 /* 001D3E10: addu       $a1, $v1, $a0 */
    .word 0x90A40001 /* 001D3E14: lbu        $a0, 0x1($a1) */
    .word 0x30830020 /* 001D3E18: andi       $v1, $a0, 0x20 */
    .word 0x50600010 /* 001D3E1C: beql       $v1, $zero, .L001D3E60 */
    .word 0x24E7FFFF /* 001D3E20: addiu      $a3, $a3, -0x1 */
    .word 0x12600008 /* 001D3E24: beqz       $s3, .L001D3E48 */
    .word 0x30830010 /* 001D3E28: andi       $v1, $a0, 0x10 */
    .word 0x30830010 /* 001D3E2C: andi       $v1, $a0, 0x10 */
    .word 0x1460000D /* 001D3E30: bnez       $v1, .L001D3E68 */
    .word 0x00000000 /* 001D3E34: nop */
    .word 0x24830010 /* 001D3E38: addiu      $v1, $a0, 0x10 */
    .word 0x1000000A /* 001D3E3C: b          .L001D3E68 */
    .word 0xA0A30001 /* 001D3E40: sb         $v1, 0x1($a1) */
    .word 0x30830010 /* 001D3E44: andi       $v1, $a0, 0x10 */
    /* .L001D3E48: */
    .word 0x10600007 /* 001D3E48: beqz       $v1, .L001D3E68 */
    .word 0x00000000 /* 001D3E4C: nop */
    .word 0x2483FFF0 /* 001D3E50: addiu      $v1, $a0, -0x10 */
    .word 0x10000004 /* 001D3E54: b          .L001D3E68 */
    .word 0xA0A30001 /* 001D3E58: sb         $v1, 0x1($a1) */
    .word 0x24E7FFFF /* 001D3E5C: addiu      $a3, $a3, -0x1 */
    /* .L001D3E60: */
    .word 0x04E1FFDF /* 001D3E60: bgez       $a3, .L001D3DE0 */
    .word 0x00000000 /* 001D3E64: nop */
    /* .L001D3E68: */
    .word 0x7BBF00A0 /* 001D3E68: lq         $ra, 0xA0($sp) */
    .word 0x7BB70090 /* 001D3E6C: lq         $s7, 0x90($sp) */
    .word 0x7BB60080 /* 001D3E70: lq         $s6, 0x80($sp) */
    .word 0x7BB50070 /* 001D3E74: lq         $s5, 0x70($sp) */
    .word 0x7BB40060 /* 001D3E78: lq         $s4, 0x60($sp) */
    .word 0x7BB30050 /* 001D3E7C: lq         $s3, 0x50($sp) */
    .word 0x7BB20040 /* 001D3E80: lq         $s2, 0x40($sp) */
    .word 0x7BB10030 /* 001D3E84: lq         $s1, 0x30($sp) */
    .word 0x7BB00020 /* 001D3E88: lq         $s0, 0x20($sp) */
    .word 0xC7B80010 /* 001D3E8C: lwc1       $f24, 0x10($sp) */
    .word 0xC7B7000C /* 001D3E90: lwc1       $f23, 0xC($sp) */
    .word 0xC7B60008 /* 001D3E94: lwc1       $f22, 0x8($sp) */
    .word 0xC7B50004 /* 001D3E98: lwc1       $f21, 0x4($sp) */
    .word 0xC7B40000 /* 001D3E9C: lwc1       $f20, 0x0($sp) */
    .word 0x03E00008 /* 001D3EA0: jr         $ra */
    .word 0x27BD00B0 /* 001D3EA4: addiu      $sp, $sp, 0xB0 */
}

#else

extern "C" void func_001D3C70(void *self, int op, float centerX, float centerY, float extent, float radius) {
    char *zm = (char *)self;
    float sum_r = radius + extent;

    int min_x = func_00123350(centerX - sum_r);
    int min_y = func_00123350(centerY - sum_r);
    int max_x = func_00123350(centerX + sum_r);
    int max_y = func_00123350(centerY + sum_r);

    if (min_x < 0) {
        min_x = 0;
    }
    if (min_y < 0) {
        min_y = 0;
    }
    int limit_x = *(int *)(zm + 0xE4);
    if (max_x >= limit_x) {
        max_x = *(int *)(zm + 0xEC);
    }
    int limit_y = *(int *)(zm + 0xE8);
    if (max_y >= limit_y) {
        max_y = *(int *)(zm + 0xF0);
    }

    *(int *)(zm + 0xF4) = min_x;
    *(int *)(zm + 0xF8) = min_y;
    *(int *)(zm + 0xFC) = max_x;
    *(int *)(zm + 0x100) = max_y;

    int center_ix = func_00123350(centerX);
    *(int *)(zm + 0x104) = center_ix;
    int center_iy = func_00123350(centerY);
    *(int *)(zm + 0x108) = center_iy;

    int s_max_y = max_y >> 3;
    int s_min_y = min_y >> 3;
    int s_max_x = max_x >> 3;
    int s_min_x = min_x >> 3;

    int count = 0;

    for (int gx = s_min_x; gx <= s_max_x; gx++) {
        for (int gy = s_min_y; gy <= s_max_y; gy++) {
            count += func_001D3EB0(self, 3, gx, gy, centerX, centerY, extent, radius, op);
        }
    }

    if (count != 0) {
        return;
    }

    void ***root = *(void ****)(zm + 0x0);
    for (int lvl = 3; lvl >= 0; lvl--) {
        void **level_ptr = (void **)root[lvl];
        int col_idx = center_ix >> lvl;
        char *col = (char *)level_ptr[col_idx];
        int row_idx = center_iy >> lvl;
        char *cell = col + (row_idx * 2);

        unsigned char flag = (unsigned char)cell[1];
        if (flag & 0x20) {
            if (op != 0) {
                if (!(flag & 0x10)) {
                    cell[1] = (char)(flag + 0x10);
                }
            } else {
                if (flag & 0x10) {
                    cell[1] = (char)(flag - 0x10);
                }
            }
            break;
        }
    }
}

#endif
