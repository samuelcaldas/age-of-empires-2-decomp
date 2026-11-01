#pragma once
#pragma exceptions off

#include "zone_get_tile_terrain.h"

extern "C" {
#if defined(__mips__)
asm int func_001CF350(void *self, int x, int y) {
    .word 0x3C010001 /* 001CF350 lui        $at, (0x10000 >> 16) */
    .word 0x00810821 /* 001CF354 addu       $at, $a0, $at */
    .word 0x00051C3C /* 001CF358 dsll32     $v1, $a1, 16 */
    .word 0x0006143C /* 001CF35C dsll32     $v0, $a2, 16 */
    .word 0x0002143F /* 001CF360 dsra32     $v0, $v0, 16 */
    .word 0x8C258E8C /* 001CF364 lw         $a1, -0x7174($at) */
    .word 0x00023080 /* 001CF368 sll        $a2, $v0, 2 */
    .word 0x00031C3F /* 001CF36C dsra32     $v1, $v1, 16 */
    .word 0x000310C0 /* 001CF370 sll        $v0, $v1, 3 */
    .word 0x00431023 /* 001CF374 subu       $v0, $v0, $v1 */
    .word 0x00021080 /* 001CF378 sll        $v0, $v0, 2 */
    .word 0x00A61821 /* 001CF37C addu       $v1, $a1, $a2 */
    .word 0x8C630000 /* 001CF380 lw         $v1, 0x0($v1) */
    .word 0x00431021 /* 001CF384 addu       $v0, $v0, $v1 */
    .word 0x90420005 /* 001CF388 lbu        $v0, 0x5($v0) */
    .word 0x28410021 /* 001CF38C slti       $at, $v0, 0x21 */
    .word 0x14200004 /* 001CF390 bnez       $at, .L001CF3A4 */
    .word 0x304500FF /* 001CF394 andi       $a1, $v0, 0xFF */
    .word 0x1000000F /* 001CF398 b          .L001CF3D8 */
    .word 0x70001628 /* 001CF39C paddub     $v0, $zero, $zero */
    .word 0x304500FF /* 001CF3A0 andi       $a1, $v0, 0xFF */
/* .L001CF3A4: */
    .word 0x00051840 /* 001CF3A4 sll        $v1, $a1, 1 */
    .word 0x00651821 /* 001CF3A8 addu       $v1, $v1, $a1 */
    .word 0x00031880 /* 001CF3AC sll        $v1, $v1, 2 */
    .word 0x00651821 /* 001CF3B0 addu       $v1, $v1, $a1 */
    .word 0x00031940 /* 001CF3B4 sll        $v1, $v1, 5 */
    .word 0x00642021 /* 001CF3B8 addu       $a0, $v1, $a0 */
    .word 0x9083008C /* 001CF3BC lbu        $v1, 0x8C($a0) */
    .word 0x14600005 /* 001CF3C0 bnez       $v1, .L001CF3D8 */
    .word 0x00000000 /* 001CF3C4 nop */
    .word 0x8483014C /* 001CF3C8 lh         $v1, 0x14C($a0) */
    .word 0x04610002 /* 001CF3CC bgez       $v1, .L001CF3D8 */
    .word 0x00000000 /* 001CF3D0 nop */
    .word 0x70001628 /* 001CF3D4 paddub     $v0, $zero, $zero */
/* .L001CF3D8: */
    .word 0x03E00008 /* 001CF3D8 jr         $ra */
    .word 0x00000000 /* 001CF3DC nop */
}
#else
int func_001CF350(void *self, int x, int y) {
    char *cells_base = *(char **)((char *)self + 0x8E8C);
    char *cell = *(char **)(cells_base + y * 4) + x * 28;

    unsigned char terrain = *(unsigned char *)(cell + 5);
    if (terrain >= 33) {
        return 0;
    }

    char *entry = (char *)self + terrain * 416;
    if (*(unsigned char *)(entry + 0x8C) != 0) {
        return terrain;
    }

    if (*(short *)(entry + 0x14C) >= 0) {
        return terrain;
    }

    return 0;
}
#endif
}
