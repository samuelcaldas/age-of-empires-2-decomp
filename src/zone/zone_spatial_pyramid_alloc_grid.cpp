#pragma exceptions off

#include "zone_spatial_pyramid_alloc_grid.h"

extern "C" {
void *func_100730(int size);
void *func_117CAC(void *dest, int c, int n);
void func_2E6CD0(void *p);
void func_2E6D40(void *p);
void func_1D5610(void *self, ...);
void func_001D5EB0(void *self, int p);
void func_1D66E0(void *self, int p);
void func_1D6F10(void *self);
void func_1D51B0(void *self, void *res);
void func_100630(void *ptr);
}

#if defined(__mips__)

extern "C" asm void *func_001D4E70(void *self, int p1, int p2, int p3) {
    .word 0x27BDFF40 /* 001D4E70: addiu      $sp, $sp, -0xC0 */
    .word 0x7FBF0090 /* 001D4E74: sq         $ra, 0x90($sp) */
    .word 0x7FBE0080 /* 001D4E78: sq         $fp, 0x80($sp) */
    .word 0x7FB70070 /* 001D4E7C: sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* 001D4E80: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 001D4E84: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D4E88: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D4E8C: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D4E90: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D4E94: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D4E98: sq         $s0, 0x0($sp) */
    .word 0x8C8200E4 /* 001D4E9C: lw         $v0, 0xE4($a0) */
    .word 0x70809E28 /* 001D4EA0: paddub     $s3, $a0, $zero */
    .word 0x70A09628 /* 001D4EA4: paddub     $s2, $a1, $zero */
    .word 0x70C08E28 /* 001D4EA8: paddub     $s1, $a2, $zero */
    .word 0x70E08628 /* 001D4EAC: paddub     $s0, $a3, $zero */
    .word 0x000210B8 /* 001D4EB0: dsll       $v0, $v0, 2 */
    .word 0x0002203C /* 001D4EB4: dsll32     $a0, $v0, 0 */
    jal func_100730 /* 001D4EB8: jal        func_100730 */
    .word 0x0004203F /* 001D4EBC: dsra32    $a0, $a0, 0 */
    .word 0xAE62011C /* 001D4EC0: sw         $v0, 0x11C($s3) */
    .word 0x1000000E /* 001D4EC4: b          .L001D4F00 */
    .word 0x7000A628 /* 001D4EC8: paddub    $s4, $zero, $zero */
    jal func_100730 /* 001D4ECC: jal        func_100730 */
    .word 0x8E6400E8 /* 001D4ED0: lw        $a0, 0xE8($s3) */
    .word 0x8E63011C /* 001D4ED4: lw         $v1, 0x11C($s3) */
    .word 0x00142080 /* 001D4ED8: sll        $a0, $s4, 2 */
    .word 0x00641821 /* 001D4EDC: addu       $v1, $v1, $a0 */
    .word 0xAC620000 /* 001D4EE0: sw         $v0, 0x0($v1) */
    .word 0x8E62011C /* 001D4EE4: lw         $v0, 0x11C($s3) */
    .word 0x8E6600E8 /* 001D4EE8: lw         $a2, 0xE8($s3) */
    .word 0x00441021 /* 001D4EEC: addu       $v0, $v0, $a0 */
    .word 0x8C440000 /* 001D4EF0: lw         $a0, 0x0($v0) */
    jal func_117CAC /* 001D4EF4: jal        func_117CAC */
    .word 0x70002E28 /* 001D4EF8: paddub    $a1, $zero, $zero */
    .word 0x26940001 /* 001D4EFC: addiu      $s4, $s4, 0x1 */
    .word 0x8E6300E4 /* 001D4F00: lw         $v1, 0xE4($s3) */
    .word 0x0283102A /* 001D4F04: slt        $v0, $s4, $v1 */
    .word 0x1440FFF0 /* 001D4F08: bnez       $v0, .L001D4ECC */
    .word 0x00000000 /* 001D4F0C: nop */
    .word 0x0003103C /* 001D4F10: dsll32     $v0, $v1, 0 */
    .word 0x0002103F /* 001D4F14: dsra32     $v0, $v0, 0 */
    .word 0x000210B8 /* 001D4F18: dsll       $v0, $v0, 2 */
    .word 0x0002203C /* 001D4F1C: dsll32     $a0, $v0, 0 */
    jal func_100730 /* 001D4F20: jal        func_100730 */
    .word 0x0004203F /* 001D4F24: dsra32    $a0, $a0, 0 */
    .word 0xAE620120 /* 001D4F28: sw         $v0, 0x120($s3) */
    .word 0x1000000E /* 001D4F2C: b          .L001D4F68 */
    .word 0x7000A628 /* 001D4F30: paddub    $s4, $zero, $zero */
    jal func_100730 /* 001D4F34: jal        func_100730 */
    .word 0x8E6400E8 /* 001D4F38: lw        $a0, 0xE8($s3) */
    .word 0x8E630120 /* 001D4F3C: lw         $v1, 0x120($s3) */
    .word 0x00142080 /* 001D4F40: sll        $a0, $s4, 2 */
    .word 0x00641821 /* 001D4F44: addu       $v1, $v1, $a0 */
    .word 0xAC620000 /* 001D4F48: sw         $v0, 0x0($v1) */
    .word 0x8E620120 /* 001D4F4C: lw         $v0, 0x120($s3) */
    .word 0x8E6600E8 /* 001D4F50: lw         $a2, 0xE8($s3) */
    .word 0x00441021 /* 001D4F54: addu       $v0, $v0, $a0 */
    .word 0x8C440000 /* 001D4F58: lw         $a0, 0x0($v0) */
    jal func_117CAC /* 001D4F5C: jal        func_117CAC */
    .word 0x70002E28 /* 001D4F60: paddub    $a1, $zero, $zero */
    .word 0x26940001 /* 001D4F64: addiu      $s4, $s4, 0x1 */
    .word 0x8E6200E4 /* 001D4F68: lw         $v0, 0xE4($s3) */
    .word 0x0282102A /* 001D4F6C: slt        $v0, $s4, $v0 */
    .word 0x1440FFF0 /* 001D4F70: bnez       $v0, .L001D4F34 */
    .word 0x00000000 /* 001D4F74: nop */
    .word 0x1000003E /* 001D4F78: b          .L001D5074 */
    .word 0x24140001 /* 001D4F7C: addiu     $s4, $zero, 0x1 */
    .word 0x8C620054 /* 001D4F80: lw         $v0, 0x54($v1) */
    .word 0x0014B880 /* 001D4F84: sll        $s7, $s4, 2 */
    .word 0x2684FFFF /* 001D4F88: addiu      $a0, $s4, -0x1 */
    .word 0x24030001 /* 001D4F8C: addiu      $v1, $zero, 0x1 */
    .word 0x00831804 /* 001D4F90: sllv       $v1, $v1, $a0 */
    .word 0x00571021 /* 001D4F94: addu       $v0, $v0, $s7 */
    .word 0x8C440000 /* 001D4F98: lw         $a0, 0x0($v0) */
    jal func_2E6CD0 /* 001D4F9C: jal        func_2E6CD0 */
    .word 0x307500FF /* 001D4FA0: andi      $s5, $v1, 0xFF */
    .word 0x7040B628 /* 001D4FA4: paddub     $s6, $v0, $zero */
    .word 0x8E620094 /* 001D4FA8: lw         $v0, 0x94($s3) */
    .word 0x8C420054 /* 001D4FAC: lw         $v0, 0x54($v0) */
    .word 0x00571021 /* 001D4FB0: addu       $v0, $v0, $s7 */
    jal func_2E6D40 /* 001D4FB4: jal        func_2E6D40 */
    .word 0x8C440000 /* 001D4FB8: lw        $a0, 0x0($v0) */
    .word 0xAFA200AC /* 001D4FBC: sw         $v0, 0xAC($sp) */
    .word 0x00511021 /* 001D4FC0: addu       $v0, $v0, $s1 */
    .word 0xAFA200B0 /* 001D4FC4: sw         $v0, 0xB0($sp) */
    .word 0x8FA200AC /* 001D4FC8: lw         $v0, 0xAC($sp) */
    .word 0x02D1B823 /* 001D4FCC: subu       $s7, $s6, $s1 */
    .word 0x8FA800B0 /* 001D4FD0: lw         $t0, 0xB0($sp) */
    .word 0x240A0002 /* 001D4FD4: addiu      $t2, $zero, 0x2 */
    .word 0x02D23823 /* 001D4FD8: subu       $a3, $s6, $s2 */
    .word 0x0051F023 /* 001D4FDC: subu       $fp, $v0, $s1 */
    .word 0x72602628 /* 001D4FE0: paddub     $a0, $s3, $zero */
    .word 0x72E02E28 /* 001D4FE4: paddub     $a1, $s7, $zero */
    .word 0x73C03628 /* 001D4FE8: paddub     $a2, $fp, $zero */
    .word 0x72804E28 /* 001D4FEC: paddub     $t1, $s4, $zero */
    jal func_1D5610 /* 001D4FF0: jal        func_1D5610 */
    .word 0x72A05E28 /* 001D4FF4: paddub    $t3, $s5, $zero */
    .word 0x8FA800B0 /* 001D4FF8: lw         $t0, 0xB0($sp) */
    .word 0x02D22821 /* 001D4FFC: addu       $a1, $s6, $s2 */
    .word 0x02D1B021 /* 001D5000: addu       $s6, $s6, $s1 */
    .word 0x240A0004 /* 001D5004: addiu      $t2, $zero, 0x4 */
    .word 0x72602628 /* 001D5008: paddub     $a0, $s3, $zero */
    .word 0x73C03628 /* 001D500C: paddub     $a2, $fp, $zero */
    .word 0x72C03E28 /* 001D5010: paddub     $a3, $s6, $zero */
    .word 0x72804E28 /* 001D5014: paddub     $t1, $s4, $zero */
    jal func_1D5610 /* 001D5018: jal        func_1D5610 */
    .word 0x72A05E28 /* 001D501C: paddub    $t3, $s5, $zero */
    .word 0x8FA200AC /* 001D5020: lw         $v0, 0xAC($sp) */
    .word 0x240A0001 /* 001D5024: addiu      $t2, $zero, 0x1 */
    .word 0x73C03628 /* 001D5028: paddub     $a2, $fp, $zero */
    .word 0x72602628 /* 001D502C: paddub     $a0, $s3, $zero */
    .word 0x72E02E28 /* 001D5030: paddub     $a1, $s7, $zero */
    .word 0x00524023 /* 001D5034: subu       $t0, $v0, $s2 */
    .word 0x72C03E28 /* 001D5038: paddub     $a3, $s6, $zero */
    .word 0x72804E28 /* 001D503C: paddub     $t1, $s4, $zero */
    jal func_1D5610 /* 001D5040: jal        func_1D5610 */
    .word 0x72A05E28 /* 001D5044: paddub    $t3, $s5, $zero */
    .word 0x8FA200AC /* 001D5048: lw         $v0, 0xAC($sp) */
    .word 0x8FA800B0 /* 001D504C: lw         $t0, 0xB0($sp) */
    .word 0x240A0008 /* 001D5050: addiu      $t2, $zero, 0x8 */
    .word 0x72E02E28 /* 001D5054: paddub     $a1, $s7, $zero */
    .word 0x72C03E28 /* 001D5058: paddub     $a3, $s6, $zero */
    .word 0x00523021 /* 001D505C: addu       $a2, $v0, $s2 */
    .word 0x72A05E28 /* 001D5060: paddub     $t3, $s5, $zero */
    .word 0x72602628 /* 001D5064: paddub     $a0, $s3, $zero */
    jal func_1D5610 /* 001D5068: jal        func_1D5610 */
    .word 0x72804E28 /* 001D506C: paddub    $t1, $s4, $zero */
    .word 0x26940001 /* 001D5070: addiu      $s4, $s4, 0x1 */
    .word 0x8E630094 /* 001D5074: lw         $v1, 0x94($s3) */
    .word 0x84620050 /* 001D5078: lh         $v0, 0x50($v1) */
    .word 0x0282102A /* 001D507C: slt        $v0, $s4, $v0 */
    .word 0x1440FFBF /* 001D5080: bnez       $v0, .L001D4F80 */
    .word 0x00000000 /* 001D5084: nop */
    .word 0x72602628 /* 001D5088: paddub     $a0, $s3, $zero */
    jal func_001D5EB0 /* 001D508C: jal        func_001D5EB0 */
    .word 0x72002E28 /* 001D5090: paddub    $a1, $s0, $zero */
    .word 0x72602628 /* 001D5094: paddub     $a0, $s3, $zero */
    jal func_1D66E0 /* 001D5098: jal        func_1D66E0 */
    .word 0x72002E28 /* 001D509C: paddub    $a1, $s0, $zero */
    .word 0x12000003 /* 001D50A0: beqz       $s0, .L001D50B0 */
    .word 0x00000000 /* 001D50A4: nop */
    jal func_1D6F10 /* 001D50A8: jal        func_1D6F10 */
    .word 0x72602628 /* 001D50AC: paddub    $a0, $s3, $zero */
    .word 0x8E620094 /* 001D50B0: lw         $v0, 0x94($s3) */
    .word 0x84420050 /* 001D50B4: lh         $v0, 0x50($v0) */
    .word 0x000210F8 /* 001D50B8: dsll       $v0, $v0, 3 */
    .word 0x0002203C /* 001D50BC: dsll32     $a0, $v0, 0 */
    jal func_100730 /* 001D50C0: jal        func_100730 */
    .word 0x0004203F /* 001D50C4: dsra32    $a0, $a0, 0 */
    .word 0x70408628 /* 001D50C8: paddub     $s0, $v0, $zero */
    .word 0x10000006 /* 001D50CC: b          .L001D50E8 */
    .word 0x70001E28 /* 001D50D0: paddub    $v1, $zero, $zero */
    .word 0x000310C0 /* 001D50D4: sll        $v0, $v1, 3 */
    .word 0x02021021 /* 001D50D8: addu       $v0, $s0, $v0 */
    .word 0xAC400000 /* 001D50DC: sw         $zero, 0x0($v0) */
    .word 0x24630001 /* 001D50E0: addiu      $v1, $v1, 0x1 */
    .word 0xAC400004 /* 001D50E4: sw         $zero, 0x4($v0) */
    .word 0x8E620094 /* 001D50E8: lw         $v0, 0x94($s3) */
    .word 0x84420050 /* 001D50EC: lh         $v0, 0x50($v0) */
    .word 0x0062102A /* 001D50F0: slt        $v0, $v1, $v0 */
    .word 0x1440FFF8 /* 001D50F4: bnez       $v0, .L001D50D8 */
    .word 0x000310C0 /* 001D50F8: sll       $v0, $v1, 3 */
    .word 0x72602628 /* 001D50FC: paddub     $a0, $s3, $zero */
    jal func_1D51B0 /* 001D5100: jal        func_1D51B0 */
    .word 0x72002E28 /* 001D5104: paddub    $a1, $s0, $zero */
    .word 0x10000007 /* 001D5108: b          .L001D5128 */
    .word 0x70008E28 /* 001D510C: paddub    $s1, $zero, $zero */
    .word 0x8E62011C /* 001D5110: lw         $v0, 0x11C($s3) */
    .word 0x00111880 /* 001D5114: sll        $v1, $s1, 2 */
    .word 0x00431021 /* 001D5118: addu       $v0, $v0, $v1 */
    jal func_100630 /* 001D511C: jal        func_100630 */
    .word 0x8C440000 /* 001D5120: lw        $a0, 0x0($v0) */
    .word 0x26310001 /* 001D5124: addiu      $s1, $s1, 0x1 */
    .word 0x8E6200E4 /* 001D5128: lw         $v0, 0xE4($s3) */
    .word 0x0222102A /* 001D512C: slt        $v0, $s1, $v0 */
    .word 0x1440FFF7 /* 001D5130: bnez       $v0, .L001D5110 */
    .word 0x00000000 /* 001D5134: nop */
    jal func_100630 /* 001D5138: jal        func_100630 */
    .word 0x8E64011C /* 001D513C: lw        $a0, 0x11C($s3) */
    .word 0x10000007 /* 001D5140: b          .L001D5160 */
    .word 0x70008E28 /* 001D5144: paddub    $s1, $zero, $zero */
    .word 0x8E620120 /* 001D5148: lw         $v0, 0x120($s3) */
    .word 0x00111880 /* 001D514C: sll        $v1, $s1, 2 */
    .word 0x00431021 /* 001D5150: addu       $v0, $v0, $v1 */
    jal func_100630 /* 001D5154: jal        func_100630 */
    .word 0x8C440000 /* 001D5158: lw        $a0, 0x0($v0) */
    .word 0x26310001 /* 001D515C: addiu      $s1, $s1, 0x1 */
    .word 0x8E6200E4 /* 001D5160: lw         $v0, 0xE4($s3) */
    .word 0x0222102A /* 001D5164: slt        $v0, $s1, $v0 */
    .word 0x1440FFF7 /* 001D5168: bnez       $v0, .L001D5148 */
    .word 0x00000000 /* 001D516C: nop */
    jal func_100630 /* 001D5170: jal        func_100630 */
    .word 0x8E640120 /* 001D5174: lw        $a0, 0x120($s3) */
    .word 0x72001628 /* 001D5178: paddub     $v0, $s0, $zero */
    .word 0x7BBF0090 /* 001D517C: lq         $ra, 0x90($sp) */
    .word 0x7BBE0080 /* 001D5180: lq         $fp, 0x80($sp) */
    .word 0x7BB70070 /* 001D5184: lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* 001D5188: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 001D518C: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D5190: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D5194: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D5198: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D519C: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D51A0: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D51A4: jr         $ra */
    .word 0x27BD00C0 /* 001D51A8: addiu     $sp, $sp, 0xC0 */
}

#else

extern "C" void *func_001D4E70(void *self, int p1, int p2, int p3) {
    char *zm = (char *)self;
    int width = *(int *)(zm + 0xE4);
    int height = *(int *)(zm + 0xE8);

    void **rows1 = (void **)func_100730(width * 4);
    *(void ***)(zm + 0x11C) = rows1;
    for (int i = 0; i < width; ++i) {
        rows1[i] = func_100730(height);
        func_117CAC(rows1[i], 0, height);
    }

    void **rows2 = (void **)func_100730(width * 4);
    *(void ***)(zm + 0x120) = rows2;
    for (int i = 0; i < width; ++i) {
        rows2[i] = func_100730(height);
        func_117CAC(rows2[i], 0, height);
    }

    char *f94 = *(char **)(zm + 0x94);
    short count = *(short *)(f94 + 0x50);
    for (int s4 = 1; s4 < count; ++s4) {
        void **level_ptrs = *(void ***)(f94 + 0x54);
        void *node = level_ptrs[s4];
        int s5 = (1 << (s4 - 1)) & 0xFF;
        func_2E6CD0(node);
        void *q = level_ptrs[s4];
        func_2E6D40(q);

        func_1D5610(self, (char *)node - p2, (char *)q - p2, (char *)node - p1, s4, 2, s5);
        func_1D5610(self, (char *)node + p1, (char *)q - p2, (char *)node + p2, s4, 4, s5);
        func_1D5610(self, (char *)node - p2, (char *)q - p1, (char *)node + p2, s4, 1, s5);
        func_1D5610(self, (char *)node - p2, (char *)q + p1, (char *)node + p2, s4, 8, s5);
    }

    func_001D5EB0(self, p3);
    func_1D66E0(self, p3);
    if (p3 != 0) {
        func_1D6F10(self);
    }

    count = *(short *)(*(char **)(zm + 0x94) + 0x50);
    int *res = (int *)func_100730(count * 8);
    for (int i = 0; i < count; ++i) {
        res[i * 2] = 0;
        res[i * 2 + 1] = 0;
    }

    func_1D51B0(self, res);

    for (int i = 0; i < width; ++i) {
        func_100630(rows1[i]);
    }
    func_100630(rows1);

    for (int i = 0; i < width; ++i) {
        func_100630(rows2[i]);
    }
    func_100630(rows2);

    return res;
}

#endif
