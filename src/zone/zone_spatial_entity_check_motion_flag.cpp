#pragma once
#pragma exceptions off

#include "zone_spatial_entity_check_motion_flag.h"

struct SubEntity2 {
    char pad[0x18];
    unsigned int flags;
};

struct SubEntity {
    char pad[0x8];
    SubEntity2 *sub2;
};

struct SpatialEntity {
    char pad[0xB4];
    SubEntity *sub;
};

extern "C" {
extern unsigned int D_00492600;

#if defined(__mips__)
asm int func_001E3600(const SpatialEntity *self) {
    .word 0x8C8200B4 /* 001E3600 lw         $v0, 0xB4($a0) */
    .word 0x50400005 /* 001E3604 beql       $v0, $zero, .L001E361C */
    .word 0x70001628 /* 001E3608 paddub    $v0, $zero, $zero */
    .word 0x8C420008 /* 001E360C lw         $v0, 0x8($v0) */
    .word 0x14400004 /* 001E3610 bnez       $v0, .L001E3624 */
    .word 0x00000000 /* 001E3614 nop */
    .word 0x70001628 /* 001E3618 paddub     $v0, $zero, $zero */
    .word 0x1000000C /* 001E361C b          .L001E3650 */
    .word 0x00000000 /* 001E3620 nop */
    .word 0x8C440018 /* 001E3624 lw         $a0, 0x18($v0) */
    .word 0x3C010049 /* 001E3628 lui        $at, (0x492600 >> 16) */
    .word 0x8C232600 /* 001E362C lw         $v1, (0x492600 & 0xFFFF)($at) */
    .word 0x24020001 /* 001E3630 addiu      $v0, $zero, 0x1 */
    .word 0x00831824 /* 001E3634 and        $v1, $a0, $v1 */
    .word 0x0003100A /* 001E3638 movz       $v0, $zero, $v1 */
    .word 0x10400004 /* 001E363C beqz       $v0, .L001E3650 */
    .word 0x70001628 /* 001E3640 paddub    $v0, $zero, $zero */
    .word 0x10000002 /* 001E3644 b          .L001E3650 */
    .word 0x24020001 /* 001E3648 addiu     $v0, $zero, 0x1 */
    .word 0x70001628 /* 001E364C paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* 001E3650 jr         $ra */
    .word 0x00000000 /* 001E3654 nop */
}
#else
int func_001E3600(const SpatialEntity *self) {
    SubEntity *s = self->sub;
    if (s != 0) {
        SubEntity2 *s2 = s->sub2;
        if (s2 != 0) {
            if ((s2->flags & D_00492600) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
#endif
}
