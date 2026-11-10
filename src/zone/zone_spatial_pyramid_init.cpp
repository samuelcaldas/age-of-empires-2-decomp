#pragma exceptions off

#include "zone_spatial_pyramid_init.h"

extern "C" {
void *func_100730(int size);
void func_117AF8(void *dst, const void *src, int size);
void func_001D2140(void *self);
void func_001D2320(void *self, int x0, int y0, int x1, int y1);
}

#if defined(__mips__)

extern "C" asm void *func_001D1D70(void *self, void *zone, const void *values, int count) {
    .word 0x27BDFF80 /* 001D1D70: addiu      $sp, $sp, -0x80 */
    .word 0x7FBF0070 /* 001D1D74: sq         $ra, 0x70($sp) */
    .word 0x7FB60060 /* 001D1D78: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 001D1D7C: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D1D80: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D1D84: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D1D88: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D1D8C: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D1D90: sq         $s0, 0x0($sp) */
    .word 0xAC850094 /* 001D1D94: sw         $a1, 0x94($a0) */
    .word 0x8CA2003C /* 001D1D98: lw         $v0, 0x3C($a1) */
    .word 0x3C010001 /* 001D1D9C: lui        $at, (0x10000 >> 16) */
    .word 0x70C08628 /* 001D1DA0: paddub     $s0, $a2, $zero */
    .word 0x00410821 /* 001D1DA4: addu       $at, $v0, $at */
    .word 0x8C228E8C /* 001D1DA8: lw         $v0, -0x7174($at) */
    .word 0xAC820098 /* 001D1DAC: sw         $v0, 0x98($a0) */
    .word 0xAC800028 /* 001D1DB0: sw         $zero, 0x28($a0) */
    .word 0xAC800054 /* 001D1DB4: sw         $zero, 0x54($a0) */
    .word 0xAC800080 /* 001D1DB8: sw         $zero, 0x80($a0) */
    .word 0xAC8700A0 /* 001D1DBC: sw         $a3, 0xA0($a0) */
    .word 0x8C8200A0 /* 001D1DC0: lw         $v0, 0xA0($a0) */
    .word 0x1840000F /* 001D1DC4: blez       $v0, .L001D1E04 */
    .word 0x7080B628 /* 001D1DC8: paddub     $s6, $a0, $zero */
    .word 0x0002103C /* 001D1DCC: dsll32     $v0, $v0, 0 */
    .word 0x0002103F /* 001D1DD0: dsra32     $v0, $v0, 0 */
    .word 0x000210B8 /* 001D1DD4: dsll       $v0, $v0, 2 */
    .word 0x0002203C /* 001D1DD8: dsll32     $a0, $v0, 0 */
    jal func_100730  /* 001D1DDC: jal        func_100730 */
    .word 0x0004203F /* 001D1DE0: dsra32     $a0, $a0, 0 */
    .word 0xAEC2009C /* 001D1DE4: sw         $v0, 0x9C($s6) */
    .word 0x8EC200A0 /* 001D1DE8: lw         $v0, 0xA0($s6) */
    .word 0x8EC4009C /* 001D1DEC: lw         $a0, 0x9C($s6) */
    .word 0x72002E28 /* 001D1DF0: paddub     $a1, $s0, $zero */
    jal func_117AF8  /* 001D1DF4: jal        func_117AF8 */
    .word 0x00023080 /* 001D1DF8: sll        $a2, $v0, 2 */
    .word 0x10000003 /* 001D1DFC: b          .L001D1E0C */
    .word 0x24020008 /* 001D1E00: addiu      $v0, $zero, 0x8 */
    /* .L001D1E04: */
    .word 0xAEC0009C /* 001D1E04: sw         $zero, 0x9C($s6) */
    .word 0x24020008 /* 001D1E08: addiu      $v0, $zero, 0x8 */
    /* .L001D1E0C: */
    .word 0xAEC20004 /* 001D1E0C: sw         $v0, 0x4($s6) */
    .word 0x8EC20094 /* 001D1E10: lw         $v0, 0x94($s6) */
    .word 0x8C42003C /* 001D1E14: lw         $v0, 0x3C($v0) */
    .word 0x8C420008 /* 001D1E18: lw         $v0, 0x8($v0) */
    .word 0xAEC200E4 /* 001D1E1C: sw         $v0, 0xE4($s6) */
    .word 0x8EC20094 /* 001D1E20: lw         $v0, 0x94($s6) */
    .word 0x8C42003C /* 001D1E24: lw         $v0, 0x3C($v0) */
    .word 0x8C42000C /* 001D1E28: lw         $v0, 0xC($v0) */
    .word 0xAEC200E8 /* 001D1E2C: sw         $v0, 0xE8($s6) */
    .word 0x8EC200E4 /* 001D1E30: lw         $v0, 0xE4($s6) */
    .word 0x2442FFFF /* 001D1E34: addiu      $v0, $v0, -0x1 */
    .word 0xAEC200EC /* 001D1E38: sw         $v0, 0xEC($s6) */
    .word 0x8EC200E8 /* 001D1E3C: lw         $v0, 0xE8($s6) */
    .word 0x2442FFFF /* 001D1E40: addiu      $v0, $v0, -0x1 */
    .word 0xAEC200F0 /* 001D1E44: sw         $v0, 0xF0($s6) */
    .word 0x8EC40004 /* 001D1E48: lw         $a0, 0x4($s6) */
    .word 0x8EC200E4 /* 001D1E4C: lw         $v0, 0xE4($s6) */
    .word 0x00441021 /* 001D1E50: addu       $v0, $v0, $a0 */
    .word 0x2442FFFF /* 001D1E54: addiu      $v0, $v0, -0x1 */
    .word 0x14800002 /* 001D1E58: bnez       $a0, .L001D1E64 */
    .word 0x0044001A /* 001D1E5C: div        $zero, $v0, $a0 */
    .word 0x000001CD /* 001D1E60: break      0, 7 */
    /* .L001D1E64: */
    .word 0x8EC200E8 /* 001D1E64: lw         $v0, 0xE8($s6) */
    .word 0x00001812 /* 001D1E68: mflo       $v1 */
    .word 0x00838018 /* 001D1E6C: mult       $s0, $a0, $v1 */
    .word 0x00441021 /* 001D1E70: addu       $v0, $v0, $a0 */
    .word 0x2442FFFF /* 001D1E74: addiu      $v0, $v0, -0x1 */
    .word 0x14800002 /* 001D1E78: bnez       $a0, .L001D1E84 */
    .word 0x0044001A /* 001D1E7C: div        $zero, $v0, $a0 */
    .word 0x000001CD /* 001D1E80: break      0, 7 */
    /* .L001D1E84: */
    .word 0x00001012 /* 001D1E84: mflo       $v0 */
    .word 0x1A000033 /* 001D1E88: blez       $s0, .L001D1F58 */
    .word 0x00828818 /* 001D1E8C: mult       $s1, $a0, $v0 */
    .word 0x1A200031 /* 001D1E90: blez       $s1, .L001D1F58 */
    .word 0x00000000 /* 001D1E94: nop */
    jal func_100730  /* 001D1E98: jal        func_100730 */
    .word 0x24040010 /* 001D1E9C: addiu      $a0, $zero, 0x10 */
    .word 0xAEC20000 /* 001D1EA0: sw         $v0, 0x0($s6) */
    .word 0x10000027 /* 001D1EA4: b          .L001D1F44 */
    .word 0x70009628 /* 001D1EA8: paddub     $s2, $zero, $zero */
    .word 0x0012A880 /* 001D1EAC: sll        $s5, $s2, 2 */
    /* .L001D1EB0: */
    .word 0x02D51821 /* 001D1EB0: addu       $v1, $s6, $s5 */
    .word 0xAC7000A4 /* 001D1EB4: sw         $s0, 0xA4($v1) */
    .word 0x2602FFFF /* 001D1EB8: addiu      $v0, $s0, -0x1 */
    .word 0xAC7100B4 /* 001D1EBC: sw         $s1, 0xB4($v1) */
    .word 0xAC6200C4 /* 001D1EC0: sw         $v0, 0xC4($v1) */
    .word 0x2622FFFF /* 001D1EC4: addiu      $v0, $s1, -0x1 */
    .word 0xAC6200D4 /* 001D1EC8: sw         $v0, 0xD4($v1) */
    .word 0x0010103C /* 001D1ECC: dsll32     $v0, $s0, 0 */
    .word 0x0002103F /* 001D1ED0: dsra32     $v0, $v0, 0 */
    .word 0x000210B8 /* 001D1ED4: dsll       $v0, $v0, 2 */
    .word 0x0002203C /* 001D1ED8: dsll32     $a0, $v0, 0 */
    jal func_100730  /* 001D1EDC: jal        func_100730 */
    .word 0x0004203F /* 001D1EE0: dsra32     $a0, $a0, 0 */
    .word 0x8EC40000 /* 001D1EE4: lw         $a0, 0x0($s6) */
    .word 0x0011183C /* 001D1EE8: dsll32     $v1, $s1, 0 */
    .word 0x0003183F /* 001D1EEC: dsra32     $v1, $v1, 0 */
    .word 0x0003A078 /* 001D1EF0: dsll       $s4, $v1, 1 */
    .word 0x70009E28 /* 001D1EF4: paddub     $s3, $zero, $zero */
    .word 0x00951821 /* 001D1EF8: addu       $v1, $a0, $s5 */
    .word 0x1000000B /* 001D1EFC: b          .L001D1F2C */
    .word 0xAC620000 /* 001D1F00: sw         $v0, 0x0($v1) */
    .word 0x0014203C /* 001D1F04: dsll32     $a0, $s4, 0 */
    /* .L001D1F08: */
    jal func_100730  /* 001D1F08: jal        func_100730 */
    .word 0x0004203F /* 001D1F0C: dsra32     $a0, $a0, 0 */
    .word 0x8EC30000 /* 001D1F10: lw         $v1, 0x0($s6) */
    .word 0x00132080 /* 001D1F14: sll        $a0, $s3, 2 */
    .word 0x26730001 /* 001D1F18: addiu      $s3, $s3, 0x1 */
    .word 0x02A31821 /* 001D1F1C: addu       $v1, $s5, $v1 */
    .word 0x8C630000 /* 001D1F20: lw         $v1, 0x0($v1) */
    .word 0x00641821 /* 001D1F24: addu       $v1, $v1, $a0 */
    .word 0xAC620000 /* 001D1F28: sw         $v0, 0x0($v1) */
    /* .L001D1F2C: */
    .word 0x0271102A /* 001D1F2C: slt        $v0, $s3, $s1 */
    .word 0x1440FFF5 /* 001D1F30: bnez       $v0, .L001D1F08 */
    .word 0x0014203C /* 001D1F34: dsll32     $a0, $s4, 0 */
    .word 0x26520001 /* 001D1F38: addiu      $s2, $s2, 0x1 */
    .word 0x00108043 /* 001D1F3C: sra        $s0, $s0, 1 */
    .word 0x00118843 /* 001D1F40: sra        $s1, $s1, 1 */
    /* .L001D1F44: */
    .word 0x2A420004 /* 001D1F44: slti       $v0, $s2, 0x4 */
    .word 0x1440FFD9 /* 001D1F48: bnez       $v0, .L001D1EB0 */
    .word 0x0012A880 /* 001D1F4C: sll        $s5, $s2, 2 */
    .word 0x10000003 /* 001D1F50: b          .L001D1F60 */
    .word 0x72C02628 /* 001D1F54: paddub     $a0, $s6, $zero */
    /* .L001D1F58: */
    .word 0xAEC00000 /* 001D1F58: sw         $zero, 0x0($s6) */
    .word 0x72C02628 /* 001D1F5C: paddub     $a0, $s6, $zero */
    /* .L001D1F60: */
    jal func_001D2140 /* 001D1F60: jal        func_001D2140 */
    .word 0x00000000 /* 001D1F64: nop */
    .word 0x8EC700E4 /* 001D1F68: lw         $a3, 0xE4($s6) */
    .word 0x8EC800E8 /* 001D1F6C: lw         $t0, 0xE8($s6) */
    .word 0x72C02628 /* 001D1F70: paddub     $a0, $s6, $zero */
    .word 0x70002E28 /* 001D1F74: paddub     $a1, $zero, $zero */
    jal func_001D2320 /* 001D1F78: jal        func_001D2320 */
    .word 0x70003628 /* 001D1F7C: paddub     $a2, $zero, $zero */
    .word 0x72C01628 /* 001D1F80: paddub     $v0, $s6, $zero */
    .word 0x7BBF0070 /* 001D1F84: lq         $ra, 0x70($sp) */
    .word 0x7BB60060 /* 001D1F88: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 001D1F8C: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D1F90: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D1F94: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D1F98: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D1F9C: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D1FA0: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D1FA4: jr         $ra */
    .word 0x27BD0080 /* 001D1FA8: addiu      $sp, $sp, 0x80 */
}

#else

extern "C" void *func_001D1D70(void *self, void *zone, const void *values, int count) {
    char *zm = (char *)self;
    *(void **)(zm + 0x94) = zone;

    char *v0 = *(char **)((char *)zone + 0x3C);
    *(void **)(zm + 0x98) = *(void **)(v0 + 0x8E8C);

    *(int *)(zm + 0x28) = 0;
    *(int *)(zm + 0x54) = 0;
    *(int *)(zm + 0x80) = 0;
    *(int *)(zm + 0xA0) = count;

    if (count > 0) {
        void *arr = func_100730(count * 4);
        *(void **)(zm + 0x9C) = arr;
        func_117AF8(arr, values, count * 4);
    } else {
        *(void **)(zm + 0x9C) = 0;
    }

    *(int *)(zm + 4) = 8;
    int e4 = *(int *)(v0 + 8);
    *(int *)(zm + 0xE4) = e4;
    int e8 = *(int *)(v0 + 0xC);
    *(int *)(zm + 0xE8) = e8;
    *(int *)(zm + 0xEC) = e4 - 1;
    *(int *)(zm + 0xF0) = e8 - 1;

    int stride = *(int *)(zm + 4);
    int s0 = (e4 + stride - 1) / stride;
    s0 = stride * s0;
    int s1 = (e8 + stride - 1) / stride;
    s1 = stride * s1;

    if (s0 > 0 && s1 > 0) {
        void ***root = (void ***)func_100730(0x10);
        *(void ****)(zm + 0) = root;

        for (int i = 0; i < 4; i++) {
            *(int *)(zm + 0xA4 + i * 4) = s0;
            *(int *)(zm + 0xB4 + i * 4) = s1;
            *(int *)(zm + 0xC4 + i * 4) = s0 - 1;
            *(int *)(zm + 0xD4 + i * 4) = s1 - 1;

            void **level_array = (void **)func_100730(s0 * 4);
            root[i] = level_array;

            int s4 = s1 * 2;
            for (int j = 0; j < s0; j++) {
                void *sub_buf = func_100730(s4);
                level_array[j] = sub_buf;
            }
            s0 >>= 1;
            s1 >>= 1;
        }
    } else {
        *(void **)(zm + 0) = 0;
    }

    func_001D2140(self);
    func_001D2320(self, 0, 0, *(int *)(zm + 0xE4), *(int *)(zm + 0xE8));

    return self;
}

#endif
