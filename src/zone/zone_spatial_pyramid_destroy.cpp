#pragma exceptions off

#include "zone_spatial_pyramid_destroy.h"

extern "C" {
void func_100630(void *ptr);
void func_100670(void *ptr);
}

#if defined(__mips__)

extern "C" asm void *func_001D1FB0(void *self, int flag) {
    .word 0x27BDFF90 /* 001D1FB0: addiu      $sp, $sp, -0x70 */
    .word 0x7FBF0060 /* 001D1FB4: sq         $ra, 0x60($sp) */
    .word 0x7FB50050 /* 001D1FB8: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D1FBC: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D1FC0: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D1FC4: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D1FC8: sq         $s1, 0x10($sp) */
    .word 0x7080AE28 /* 001D1FCC: paddub     $s5, $a0, $zero */
    .word 0x7FB00000 /* 001D1FD0: sq         $s0, 0x0($sp) */
    .word 0x12A00033 /* 001D1FD4: beqz       $s5, .L001D20A4 */
    .word 0x70A0A628 /* 001D1FD8: paddub     $s4, $a1, $zero */
    .word 0x8EA4009C /* 001D1FDC: lw         $a0, 0x9C($s5) */
    .word 0x10800003 /* 001D1FE0: beqz       $a0, .L001D1FF0 */
    .word 0x00000000 /* 001D1FE4: nop */
    jal func_100630  /* 001D1FE8: jal        func_100630 */
    .word 0x00000000 /* 001D1FEC: nop */
    /* .L001D1FF0: */
    .word 0x8EA20000 /* 001D1FF0: lw         $v0, 0x0($s5) */
    .word 0x10400022 /* 001D1FF4: beqz       $v0, .L001D2080 */
    .word 0x00000000 /* 001D1FF8: nop */
    .word 0x10000016 /* 001D1FFC: b          .L001D2058 */
    .word 0x70008628 /* 001D2000: paddub     $s0, $zero, $zero */
    .word 0x00109880 /* 001D2004: sll        $s3, $s0, 2 */
    /* .L001D2008: */
    .word 0x02B39021 /* 001D2008: addu       $s2, $s5, $s3 */
    .word 0x10000009 /* 001D200C: b          .L001D2034 */
    .word 0x70008E28 /* 001D2010: paddub     $s1, $zero, $zero */
    /* .L001D2014: */
    .word 0x8EA20000 /* 001D2014: lw         $v0, 0x0($s5) */
    .word 0x00111880 /* 001D2018: sll        $v1, $s1, 2 */
    .word 0x02621021 /* 001D201C: addu       $v0, $s3, $v0 */
    .word 0x8C420000 /* 001D2020: lw         $v0, 0x0($v0) */
    .word 0x00431021 /* 001D2024: addu       $v0, $v0, $v1 */
    jal func_100630  /* 001D2028: jal        func_100630 */
    .word 0x8C440000 /* 001D202C: lw         $a0, 0x0($v0) */
    .word 0x26310001 /* 001D2030: addiu      $s1, $s1, 0x1 */
    /* .L001D2034: */
    .word 0x8E4200A4 /* 001D2034: lw         $v0, 0xA4($s2) */
    .word 0x0222102A /* 001D2038: slt        $v0, $s1, $v0 */
    .word 0x1440FFF5 /* 001D203C: bnez       $v0, .L001D2014 */
    .word 0x00000000 /* 001D2040: nop */
    .word 0x8EA20000 /* 001D2044: lw         $v0, 0x0($s5) */
    .word 0x00531021 /* 001D2048: addu       $v0, $v0, $s3 */
    jal func_100630  /* 001D204C: jal        func_100630 */
    .word 0x8C440000 /* 001D2050: lw         $a0, 0x0($v0) */
    .word 0x26100001 /* 001D2054: addiu      $s0, $s0, 0x1 */
    /* .L001D2058: */
    .word 0x2A020004 /* 001D2058: slti       $v0, $s0, 0x4 */
    .word 0x1440FFEA /* 001D205C: bnez       $v0, .L001D2008 */
    .word 0x00109880 /* 001D2060: sll        $s3, $s0, 2 */
    jal func_100630  /* 001D2064: jal        func_100630 */
    .word 0x8EA40000 /* 001D2068: lw         $a0, 0x0($s5) */
    .word 0x10000005 /* 001D206C: b          .L001D2084 */
    .word 0x8EA40080 /* 001D2070: lw         $a0, 0x80($s5) */
    /* .L001D2074: */
    jal func_100670  /* 001D2074: jal        func_100670 */
    .word 0x8C900020 /* 001D2078: lw         $s0, 0x20($a0) */
    .word 0xAEB00080 /* 001D207C: sw         $s0, 0x80($s5) */
    /* .L001D2080: */
    .word 0x8EA40080 /* 001D2080: lw         $a0, 0x80($s5) */
    /* .L001D2084: */
    .word 0x1480FFFB /* 001D2084: bnez       $a0, .L001D2074 */
    .word 0x00000000 /* 001D2088: nop */
    .word 0x0014143C /* 001D208C: dsll32     $v0, $s4, 16 */
    .word 0x0002143F /* 001D2090: dsra32     $v0, $v0, 16 */
    .word 0x18400004 /* 001D2094: blez       $v0, .L001D20A8 */
    .word 0x72A01628 /* 001D2098: paddub     $v0, $s5, $zero */
    jal func_100670  /* 001D209C: jal        func_100670 */
    .word 0x72A02628 /* 001D20A0: paddub     $a0, $s5, $zero */
    /* .L001D20A4: */
    .word 0x72A01628 /* 001D20A4: paddub     $v0, $s5, $zero */
    /* .L001D20A8: */
    .word 0x7BBF0060 /* 001D20A8: lq         $ra, 0x60($sp) */
    .word 0x7BB50050 /* 001D20AC: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D20B0: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D20B4: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D20B8: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D20BC: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D20C0: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D20C4: jr         $ra */
    .word 0x27BD0070 /* 001D20C8: addiu      $sp, $sp, 0x70 */
}

#else

extern "C" void *func_001D1FB0(void *self, int flag) {
    char *zm = (char *)self;
    if (zm == 0) {
        return 0;
    }

    void *ptr_9c = *(void **)(zm + 0x9C);
    if (ptr_9c != 0) {
        func_100630(ptr_9c);
    }

    void ***root = *(void ****)(zm + 0x0);
    if (root != 0) {
        for (int i = 0; i < 4; i++) {
            int level_count = *(int *)(zm + 0xA4 + i * 4);
            void **level_array = root[i];
            for (int j = 0; j < level_count; j++) {
                func_100630(level_array[j]);
            }
            func_100630(level_array);
        }
        func_100630(root);
    }

    while (*(void **)(zm + 0x80) != 0) {
        void *node = *(void **)(zm + 0x80);
        *(void **)(zm + 0x80) = *(void **)((char *)node + 0x20);
        func_100670(node);
    }

    if ((short)flag > 0) {
        func_100670(zm);
    }

    return zm;
}

#endif
