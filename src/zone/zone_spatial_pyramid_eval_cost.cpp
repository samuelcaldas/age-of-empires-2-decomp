#pragma exceptions off

#include "zone_spatial_pyramid_eval_cost.h"

extern "C" {
float func_122690(int dist_sq);
float func_1228E8(float val);
void *func_1D4330(
    void *self, int x, int y, int level, int p4, int p5, float f12, float f13, int cur_x, int cur_y
);
void func_001D42A0(void *self, void *list, void *node, int flag);
int func_001D3880(void *self, void *node, int next_x, int next_y, float cost, int dir);
}

#if defined(__mips__)

extern "C" asm int func_001D35C0(void *self, int level, int x, int y, int cur_x, int cur_y) {
    .word 0x27BDFF90 /* 001D35C0: addiu      $sp, $sp, -0x70 */
    .word 0x7FBF0060 /* 001D35C4: sq         $ra, 0x60($sp) */
    .word 0x7FB50050 /* 001D35C8: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D35CC: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D35D0: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D35D4: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D35D8: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D35DC: sq         $s0, 0x0($sp) */
    .word 0x8C820000 /* 001D35E0: lw         $v0, 0x0($a0) */
    .word 0x70808628 /* 001D35E4: paddub     $s0, $a0, $zero */
    .word 0x70C0A628 /* 001D35E8: paddub     $s4, $a2, $zero */
    .word 0x00071840 /* 001D35EC: sll        $v1, $a3, 1 */
    .word 0x71009628 /* 001D35F0: paddub     $s2, $t0, $zero */
    .word 0x71208E28 /* 001D35F4: paddub     $s1, $t1, $zero */
    .word 0x00062080 /* 001D35F8: sll        $a0, $a2, 2 */
    .word 0x00053080 /* 001D35FC: sll        $a2, $a1, 2 */
    .word 0x00461021 /* 001D3600: addu       $v0, $v0, $a2 */
    .word 0x8C420000 /* 001D3604: lw         $v0, 0x0($v0) */
    .word 0x70A0AE28 /* 001D3608: paddub     $s5, $a1, $zero */
    .word 0x00441021 /* 001D360C: addu       $v0, $v0, $a0 */
    .word 0x8C420000 /* 001D3610: lw         $v0, 0x0($v0) */
    .word 0x00431021 /* 001D3614: addu       $v0, $v0, $v1 */
    .word 0x90420000 /* 001D3618: lbu        $v0, 0x0($v0) */
    .word 0x14400003 /* 001D361C: bnez       $v0, .L001D362C */
    .word 0x70E09E28 /* 001D3620: paddub     $s3, $a3, $zero */
    .word 0x1000008A /* 001D3624: b          .L001D3850 */
    .word 0x70001628 /* 001D3628: paddub     $v0, $zero, $zero */
    /* .L001D362C: */
    .word 0x8E030104 /* 001D362C: lw         $v1, 0x104($s0) */
    .word 0x8E020108 /* 001D3630: lw         $v0, 0x108($s0) */
    .word 0x00721823 /* 001D3634: subu       $v1, $v1, $s2 */
    .word 0x00631818 /* 001D3638: mult       $v1, $v1, $v1 */
    .word 0x00511023 /* 001D363C: subu       $v0, $v0, $s1 */
    .word 0x70421018 /* 001D3640: mult1      $v0, $v0, $v0 */
    jal func_122690  /* 001D3644: jal        func_122690 */
    .word 0x00622021 /* 001D3648: addu       $a0, $v1, $v0 */
    jal func_1228E8  /* 001D364C: jal        func_1228E8 */
    .word 0x70402628 /* 001D3650: paddub     $a0, $v0, $zero */
    .word 0x46000004 /* 001D3654: c1         0x4 */
    .word 0x72802E28 /* 001D3658: paddub     $a1, $s4, $zero */
    .word 0x72603628 /* 001D365C: paddub     $a2, $s3, $zero */
    .word 0x72A03E28 /* 001D3660: paddub     $a3, $s5, $zero */
    .word 0x72405628 /* 001D3664: paddub     $t2, $s2, $zero */
    .word 0x72205E28 /* 001D3668: paddub     $t3, $s1, $zero */
    .word 0x72002628 /* 001D366C: paddub     $a0, $s0, $zero */
    .word 0x70004628 /* 001D3670: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D3674: paddub     $t1, $zero, $zero */
    .word 0x44806000 /* 001D3678: mtc1       $zero, $f12 */
    jal func_1D4330  /* 001D367C: jal        func_1D4330 */
    .word 0x46000346 /* 001D3680: mov.s      $f13, $f0 */
    .word 0x70408E28 /* 001D3684: paddub     $s1, $v0, $zero */
    .word 0x26050008 /* 001D3688: addiu      $a1, $s0, 0x8 */
    .word 0x72002628 /* 001D368C: paddub     $a0, $s0, $zero */
    .word 0x72203628 /* 001D3690: paddub     $a2, $s1, $zero */
    jal func_001D42A0 /* 001D3694: jal       func_001D42A0 */
    .word 0x70003E28 /* 001D3698: paddub     $a3, $zero, $zero */
    .word 0x8E240000 /* 001D369C: lw         $a0, 0x0($s1) */
    .word 0x90820001 /* 001D36A0: lbu        $v0, 0x1($a0) */
    .word 0x30420010 /* 001D36A4: andi       $v0, $v0, 0x10 */
    .word 0x10400004 /* 001D36A8: beqz       $v0, .L001D36BC */
    .word 0x3C02000F /* 001D36AC: lui        $v0, (0xF423F >> 16) */
    .word 0x10000067 /* 001D36B0: b          .L001D3850 */
    .word 0x72201628 /* 001D36B4: paddub     $v0, $s1, $zero */
    .word 0x3C02000F /* 001D36B8: lui        $v0, (0xF423F >> 16) */
    /* .L001D36BC: */
    .word 0x3442423F /* 001D36BC: ori        $v0, $v0, (0xF423F & 0xFFFF) */
    .word 0x44820000 /* 001D36C0: mtc1       $v0, $f0 */
    .word 0x90830000 /* 001D36C4: lbu        $v1, 0x0($a0) */
    .word 0x46800020 /* 001D36C8: cvt.s.w    $f0, $f0 */
    .word 0x70008E28 /* 001D36CC: paddub     $s1, $zero, $zero */
    .word 0x24620010 /* 001D36D0: addiu      $v0, $v1, 0x10 */
    .word 0xA0820000 /* 001D36D4: sb         $v0, 0x0($a0) */
    .word 0xE6000090 /* 001D36D8: swc1       $f0, 0x90($s0) */
    .word 0x10000058 /* 001D36DC: b          .L001D3840 */
    .word 0xAE00008C /* 001D36E0: sw         $zero, 0x8C($s0) */
    /* .L001D36E4: */
    .word 0x8E120028 /* 001D36E4: lw         $s2, 0x28($s0) */
    .word 0x26050034 /* 001D36E8: addiu      $a1, $s0, 0x34 */
    .word 0x24070001 /* 001D36EC: addiu      $a3, $zero, 0x1 */
    .word 0x72002628 /* 001D36F0: paddub     $a0, $s0, $zero */
    .word 0x8E530000 /* 001D36F4: lw         $s3, 0x0($s2) */
    .word 0x8E420020 /* 001D36F8: lw         $v0, 0x20($s2) */
    .word 0x72403628 /* 001D36FC: paddub     $a2, $s2, $zero */
    .word 0x92740000 /* 001D3700: lbu        $s4, 0x0($s3) */
    jal func_001D42A0 /* 001D3704: jal       func_001D42A0 */
    .word 0xAE020028 /* 001D3708: sw         $v0, 0x28($s0) */
    .word 0x328200FF /* 001D370C: andi       $v0, $s4, 0xFF */
    .word 0x30420020 /* 001D3710: andi       $v0, $v0, 0x20 */
    .word 0x1440004A /* 001D3714: bnez       $v0, .L001D3840 */
    .word 0x00000000 /* 001D3718: nop */
    .word 0x92620000 /* 001D371C: lbu        $v0, 0x0($s3) */
    .word 0x24420020 /* 001D3720: addiu      $v0, $v0, 0x20 */
    .word 0xA2620000 /* 001D3724: sb         $v0, 0x0($s3) */
    .word 0xC6420018 /* 001D3728: lwc1       $f2, 0x18($s2) */
    .word 0xC641001C /* 001D372C: lwc1       $f1, 0x1C($s2) */
    .word 0xC6000090 /* 001D3730: lwc1       $f0, 0x90($s0) */
    .word 0x46011041 /* 001D3734: sub.s      $f1, $f2, $f1 */
    .word 0x46000834 /* 001D3738: c.lt.s     $f1, $f0 */
    .word 0x00000000 /* 001D373C: nop */
    .word 0x45000004 /* 001D3740: bc1f       .L001D3754 */
    .word 0x328200FF /* 001D3744: andi       $v0, $s4, 0xFF */
    .word 0xAE12008C /* 001D3748: sw         $s2, 0x8C($s0) */
    .word 0xE6010090 /* 001D374C: swc1       $f1, 0x90($s0) */
    .word 0x328200FF /* 001D3750: andi       $v0, $s4, 0xFF */
    /* .L001D3754: */
    .word 0x30420002 /* 001D3754: andi       $v0, $v0, 0x2 */
    .word 0x1040000D /* 001D3758: beqz       $v0, .L001D3790 */
    .word 0x328200FF /* 001D375C: andi       $v0, $s4, 0xFF */
    .word 0x8E420004 /* 001D3760: lw         $v0, 0x4($s2) */
    .word 0x8E45000C /* 001D3764: lw         $a1, 0xC($s2) */
    .word 0x8E470008 /* 001D3768: lw         $a3, 0x8($s2) */
    .word 0xC64C001C /* 001D376C: lwc1       $f12, 0x1C($s2) */
    .word 0x24090004 /* 001D3770: addiu      $t1, $zero, 0x4 */
    .word 0x2446FFFF /* 001D3774: addiu      $a2, $v0, -0x1 */
    .word 0x72002628 /* 001D3778: paddub     $a0, $s0, $zero */
    jal func_001D3880 /* 001D377C: jal       func_001D3880 */
    .word 0x72404628 /* 001D3780: paddub     $t0, $s2, $zero */
    .word 0x14400031 /* 001D3784: bnez       $v0, .L001D384C */
    .word 0x70408E28 /* 001D3788: paddub     $s1, $v0, $zero */
    .word 0x328200FF /* 001D378C: andi       $v0, $s4, 0xFF */
    /* .L001D3790: */
    .word 0x30420004 /* 001D3790: andi       $v0, $v0, 0x4 */
    .word 0x1040000D /* 001D3794: beqz       $v0, .L001D37CC */
    .word 0x328200FF /* 001D3798: andi       $v0, $s4, 0xFF */
    .word 0x8E420004 /* 001D379C: lw         $v0, 0x4($s2) */
    .word 0x8E45000C /* 001D37A0: lw         $a1, 0xC($s2) */
    .word 0x8E470008 /* 001D37A4: lw         $a3, 0x8($s2) */
    .word 0xC64C001C /* 001D37A8: lwc1       $f12, 0x1C($s2) */
    .word 0x24090002 /* 001D37AC: addiu      $t1, $zero, 0x2 */
    .word 0x24460001 /* 001D37B0: addiu      $a2, $v0, 0x1 */
    .word 0x72002628 /* 001D37B4: paddub     $a0, $s0, $zero */
    jal func_001D3880 /* 001D37B8: jal       func_001D3880 */
    .word 0x72404628 /* 001D37BC: paddub     $t0, $s2, $zero */
    .word 0x14400022 /* 001D37C0: bnez       $v0, .L001D384C */
    .word 0x70408E28 /* 001D37C4: paddub     $s1, $v0, $zero */
    .word 0x328200FF /* 001D37C8: andi       $v0, $s4, 0xFF */
    /* .L001D37CC: */
    .word 0x30420001 /* 001D37CC: andi       $v0, $v0, 0x1 */
    .word 0x1040000D /* 001D37D0: beqz       $v0, .L001D3808 */
    .word 0x328200FF /* 001D37D4: andi       $v0, $s4, 0xFF */
    .word 0x8E420008 /* 001D37D8: lw         $v0, 0x8($s2) */
    .word 0x8E45000C /* 001D37DC: lw         $a1, 0xC($s2) */
    .word 0x8E460004 /* 001D37E0: lw         $a2, 0x4($s2) */
    .word 0xC64C001C /* 001D37E4: lwc1       $f12, 0x1C($s2) */
    .word 0x24090008 /* 001D37E8: addiu      $t1, $zero, 0x8 */
    .word 0x2447FFFF /* 001D37EC: addiu      $a3, $v0, -0x1 */
    .word 0x72002628 /* 001D37F0: paddub     $a0, $s0, $zero */
    jal func_001D3880 /* 001D37F4: jal       func_001D3880 */
    .word 0x72404628 /* 001D37F8: paddub     $t0, $s2, $zero */
    .word 0x14400013 /* 001D37FC: bnez       $v0, .L001D384C */
    .word 0x70408E28 /* 001D3800: paddub     $s1, $v0, $zero */
    .word 0x328200FF /* 001D3804: andi       $v0, $s4, 0xFF */
    /* .L001D3808: */
    .word 0x30420008 /* 001D3808: andi       $v0, $v0, 0x8 */
    .word 0x1040000C /* 001D380C: beqz       $v0, .L001D3840 */
    .word 0x00000000 /* 001D3810: nop */
    .word 0x8E420008 /* 001D3814: lw         $v0, 0x8($s2) */
    .word 0x8E45000C /* 001D3818: lw         $a1, 0xC($s2) */
    .word 0x8E460004 /* 001D381C: lw         $a2, 0x4($s2) */
    .word 0xC64C001C /* 001D3820: lwc1       $f12, 0x1C($s2) */
    .word 0x24090001 /* 001D3824: addiu      $t1, $zero, 0x1 */
    .word 0x24470001 /* 001D3828: addiu      $a3, $v0, 0x1 */
    .word 0x72002628 /* 001D382C: paddub     $a0, $s0, $zero */
    jal func_001D3880 /* 001D3830: jal       func_001D3880 */
    .word 0x72404628 /* 001D3834: paddub     $t0, $s2, $zero */
    .word 0x14400004 /* 001D3838: bnez       $v0, .L001D384C */
    .word 0x70408E28 /* 001D383C: paddub     $s1, $v0, $zero */
    /* .L001D3840: */
    .word 0x8E020028 /* 001D3840: lw         $v0, 0x28($s0) */
    .word 0x1440FFA7 /* 001D3844: bnez       $v0, .L001D36E4 */
    .word 0x00000000 /* 001D3848: nop */
    /* .L001D384C: */
    .word 0x72201628 /* 001D384C: paddub     $v0, $s1, $zero */
    /* .L001D3850: */
    .word 0x7BBF0060 /* 001D3850: lq         $ra, 0x60($sp) */
    .word 0x7BB50050 /* 001D3854: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D3858: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D385C: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D3860: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D3864: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D3868: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D386C: jr         $ra */
    .word 0x27BD0070 /* 001D3870: addiu      $sp, $sp, 0x70 */
}

#else

extern "C" int func_001D35C0(void *self, int level, int x, int y, int cur_x, int cur_y) {
    char *zm = (char *)self;
    void ***root = *(void ****)(zm + 0x0);
    char *cell = (char *)root[level][x] + y * 2;

    if (cell[0] == 0) {
        return 0;
    }

    int target_x = *(int *)(zm + 0x104);
    int target_y = *(int *)(zm + 0x108);

    int dx = target_x - cur_x;
    int dy = target_y - cur_y;

    int dist_sq = dx * dx + dy * dy;
    float fdist = func_122690(dist_sq);
    float h_cost = func_1228E8(fdist);

    void *start_node = func_1D4330(self, x, y, level, 0, 0, 0.0f, h_cost, cur_x, cur_y);
    func_001D42A0(self, zm + 0x8, start_node, 0);

    char *start_cell = *(char **)start_node;
    if (start_cell[1] & 0x10) {
        return (int)start_node;
    }

    start_cell[0] = (char)(start_cell[0] + 0x10);
    *(float *)(zm + 0x90) = 1000000.0f - 1.0f;
    *(void **)(zm + 0x8C) = 0;

    while (*(void **)(zm + 0x28) != 0) {
        void *node = *(void **)(zm + 0x28);
        void *cell_ptr = *(void **)node;
        void *next = *(void **)((char *)node + 0x20);
        unsigned char flags = *(unsigned char *)cell_ptr;

        func_001D42A0(self, zm + 0x34, node, 1);
        *(void **)(zm + 0x28) = next;

        if (flags & 0x20) {
            continue;
        }

        *(unsigned char *)cell_ptr = (unsigned char)(*(unsigned char *)cell_ptr + 0x20);

        float cost_f2 = *(float *)((char *)node + 0x18);
        float cost_f1 = *(float *)((char *)node + 0x1C);
        float diff = cost_f2 - cost_f1;
        if (diff < *(float *)(zm + 0x90)) {
            *(void **)(zm + 0x8C) = node;
            *(float *)(zm + 0x90) = diff;
        }

        if (flags & 0x2) {
            int nx = *(int *)((char *)node + 0x4) - 1;
            int nlvl = *(int *)((char *)node + 0xC);
            int ny = *(int *)((char *)node + 0x8);
            float ncost = *(float *)((char *)node + 0x1C);
            int res = func_001D3880(self, node, nx, ny, ncost, 4);
            if (res != 0) {
                return res;
            }
        }

        if (flags & 0x4) {
            int nx = *(int *)((char *)node + 0x4) + 1;
            int nlvl = *(int *)((char *)node + 0xC);
            int ny = *(int *)((char *)node + 0x8);
            float ncost = *(float *)((char *)node + 0x1C);
            int res = func_001D3880(self, node, nx, ny, ncost, 2);
            if (res != 0) {
                return res;
            }
        }

        if (flags & 0x1) {
            int nx = *(int *)((char *)node + 0x4);
            int nlvl = *(int *)((char *)node + 0xC);
            int ny = *(int *)((char *)node + 0x8) - 1;
            float ncost = *(float *)((char *)node + 0x1C);
            int res = func_001D3880(self, node, nx, ny, ncost, 8);
            if (res != 0) {
                return res;
            }
        }

        if (flags & 0x8) {
            int nx = *(int *)((char *)node + 0x4);
            int nlvl = *(int *)((char *)node + 0xC);
            int ny = *(int *)((char *)node + 0x8) + 1;
            float ncost = *(float *)((char *)node + 0x1C);
            int res = func_001D3880(self, node, nx, ny, ncost, 1);
            if (res != 0) {
                return res;
            }
        }
    }

    return 0;
}

#endif
