#pragma once
#pragma exceptions off

#include "zone_perimeter_point.h"

extern "C" {
#if defined(__mips__)
asm void func_001CAC00(void *self, short *buffer, short dx, short dy) {
    .word 0x14C00003 /* 001CAC00 bnez       $a2, .L001CAC10 */
    .word 0x00000000 /* 001CAC04 nop */
    .word 0x10E0001C /* 001CAC08 beqz       $a3, .L001CAC7C */
    .word 0x00000000 /* 001CAC0C nop */
/* .L001CAC10: */
    .word 0x10A0001A /* 001CAC10 beqz       $a1, .L001CAC7C */
    .word 0x00000000 /* 001CAC14 nop */
    .word 0x84A40000 /* 001CAC18 lh         $a0, 0x0($a1) */
    .word 0x84A30002 /* 001CAC1C lh         $v1, 0x2($a1) */
    .word 0x0083082A /* 001CAC20 slt        $at, $a0, $v1 */
    .word 0x10200015 /* 001CAC24 beqz       $at, .L001CAC7C */
    .word 0x00000000 /* 001CAC28 nop */
    .word 0x1000000A /* 001CAC2C b          .L001CAC58 */
    .word 0x24080001 /* 001CAC30 addiu      $t0, $zero, 0x1 */
    .word 0x00081880 /* 001CAC34 sll        $v1, $t0, 2 */
/* .L001CAC38: */
    .word 0x00A34821 /* 001CAC38 addu       $t1, $a1, $v1 */
    .word 0x85230000 /* 001CAC3C lh         $v1, 0x0($t1) */
    .word 0x54C30005 /* 001CAC40 bnel       $a2, $v1, .L001CAC58 */
    .word 0x25080001 /* 001CAC44 addiu      $t0, $t0, 0x1 */
    .word 0x85230002 /* 001CAC48 lh         $v1, 0x2($t1) */
    .word 0x10E3000B /* 001CAC4C beq        $a3, $v1, .L001CAC7C */
    .word 0x00000000 /* 001CAC50 nop */
    .word 0x25080001 /* 001CAC54 addiu      $t0, $t0, 0x1 */
/* .L001CAC58: */
    .word 0x0088082A /* 001CAC58 slt        $at, $a0, $t0 */
    .word 0x1020FFF6 /* 001CAC5C beqz       $at, .L001CAC38 */
    .word 0x00081880 /* 001CAC60 sll        $v1, $t0, 2 */
    .word 0x24840001 /* 001CAC64 addiu      $a0, $a0, 0x1 */
    .word 0x00041880 /* 001CAC68 sll        $v1, $a0, 2 */
    .word 0x00A31821 /* 001CAC6C addu       $v1, $a1, $v1 */
    .word 0xA4660000 /* 001CAC70 sh         $a2, 0x0($v1) */
    .word 0xA4670002 /* 001CAC74 sh         $a3, 0x2($v1) */
    .word 0xA4A40000 /* 001CAC78 sh         $a0, 0x0($a1) */
/* .L001CAC7C: */
    .word 0x03E00008 /* 001CAC7C jr         $ra */
    .word 0x00000000 /* 001CAC80 nop */
}
#else
void func_001CAC00(void *self, short *buffer, short dx, short dy) {
    (void)self;
    if (dx == 0 && dy == 0) {
        return;
    }
    if (buffer == 0) {
        return;
    }

    short count = buffer[0];
    short capacity = buffer[1];
    if (!(count < capacity)) {
        return;
    }

    for (int i = 1; i <= count; i++) {
        if (buffer[i * 2] == dx && buffer[i * 2 + 1] == dy) {
            return;
        }
    }

    count++;
    buffer[count * 2] = dx;
    buffer[count * 2 + 1] = dy;
    buffer[0] = count;
}
#endif
}
