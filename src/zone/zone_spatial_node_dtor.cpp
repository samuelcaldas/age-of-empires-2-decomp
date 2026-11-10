#pragma exceptions off

#include "zone_spatial_node_dtor.h"

extern "C" {
void func_1D7B20(void *self);
void func_100670(void *ptr);
}

#if defined(__mips__)

extern "C" asm void *func_001D7AC0(void *self, int flag) {
    .word 0x27BDFFD0 /* 001D7AC0: addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* 001D7AC4: sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* 001D7AC8: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D7ACC: sq         $s0, 0x0($sp) */
    .word 0x70808E28 /* 001D7AD0: paddub     $s1, $a0, $zero */
    .word 0x12200009 /* 001D7AD4: beqz       $s1, .L001D7AFC */
    .word 0x70A08628 /* 001D7AD8: paddub    $s0, $a1, $zero */
    jal        func_1D7B20 /* 001D7ADC: jal        func_1D7B20 */
    .word 0x00000000 /* 001D7AE0: nop */
    .word 0x0010143C /* 001D7AE4: dsll32     $v0, $s0, 16 */
    .word 0x0002143F /* 001D7AE8: dsra32     $v0, $v0, 16 */
    .word 0x18400004 /* 001D7AEC: blez       $v0, .L001D7B00 */
    .word 0x72201628 /* 001D7AF0: paddub    $v0, $s1, $zero */
    jal        func_100670 /* 001D7AF4: jal        func_100670 */
    .word 0x72202628 /* 001D7AF8: paddub    $a0, $s1, $zero */
/* .L001D7AFC: */
    .word 0x72201628 /* 001D7AFC: paddub     $v0, $s1, $zero */
/* .L001D7B00: */
    .word 0x7BBF0020 /* 001D7B00: lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* 001D7B04: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D7B08: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D7B0C: jr         $ra */
    .word 0x27BD0030 /* 001D7B10: addiu     $sp, $sp, 0x30 */
}

#else

extern "C" void *func_001D7AC0(void *self, int flag) {
    if (self == 0) {
        return 0;
    }

    func_1D7B20(self);

    if ((short)flag > 0) {
        func_100670(self);
    }

    return self;
}

#endif
