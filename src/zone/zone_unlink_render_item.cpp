#pragma once
#pragma exceptions off

#include "zone_unlink_render_item.h"

extern "C" {
#if defined(__mips__)
asm void func_001D1CC0(void *self, void *item) {
    .word 0x8CA80010 /* 001D1CC0 lw         $t0, 0x10($a1) */
    .word 0x11000025 /* 001D1CC4 beqz       $t0, .L001D1D5C */
    .word 0x90A30004 /* 001D1CC8 lbu       $v1, 0x4($a1) */
    .word 0x00035080 /* 001D1CCC sll        $t2, $v1, 2 */
    .word 0x01441821 /* 001D1CD0 addu       $v1, $t2, $a0 */
    .word 0x24691050 /* 001D1CD4 addiu      $t1, $v1, 0x1050 */
    .word 0x25297FF8 /* 001D1CD8 addiu      $t1, $t1, 0x7FF8 */
    .word 0x8D260000 /* 001D1CDC lw         $a2, 0x0($t1) */
    .word 0x10000007 /* 001D1CE0 b          .L001D1D00 */
    .word 0x70003E28 /* 001D1CE4 paddub    $a3, $zero, $zero */
    .word 0x8CC30000 /* 001D1CE8 lw         $v1, 0x0($a2) */
    .word 0x10650006 /* 001D1CEC beq        $v1, $a1, .L001D1D08 */
    .word 0x00000000 /* 001D1CF0 nop */
    .word 0x70C03E28 /* 001D1CF4 paddub     $a3, $a2, $zero */
    .word 0x8CC60004 /* 001D1CF8 lw         $a2, 0x4($a2) */
    .word 0x00000000 /* 001D1CFC nop */
    .word 0x14C0FFF9 /* 001D1D00 bnez       $a2, .L001D1CE8 */
    .word 0x00000000 /* 001D1D04 nop */
    .word 0xACC80000 /* 001D1D08 sw         $t0, 0x0($a2) */
    .word 0x14E00004 /* 001D1D0C bnez       $a3, .L001D1D20 */
    .word 0xACA00010 /* 001D1D10 sw        $zero, 0x10($a1) */
    .word 0x8CC30004 /* 001D1D14 lw         $v1, 0x4($a2) */
    .word 0x10000003 /* 001D1D18 b          .L001D1D28 */
    .word 0xAD230000 /* 001D1D1C sw        $v1, 0x0($t1) */
    .word 0x8CC30004 /* 001D1D20 lw         $v1, 0x4($a2) */
    .word 0xACE30004 /* 001D1D24 sw         $v1, 0x4($a3) */
    .word 0x01441821 /* 001D1D28 addu       $v1, $t2, $a0 */
    .word 0x24651094 /* 001D1D2C addiu      $a1, $v1, 0x1094 */
    .word 0x24A57FF8 /* 001D1D30 addiu      $a1, $a1, 0x7FF8 */
    .word 0x8CA30000 /* 001D1D34 lw         $v1, 0x0($a1) */
    .word 0x14660003 /* 001D1D38 bne        $v1, $a2, .L001D1D48 */
    .word 0x01441821 /* 001D1D3C addu      $v1, $t2, $a0 */
    .word 0xACA70000 /* 001D1D40 sw         $a3, 0x0($a1) */
    .word 0x01441821 /* 001D1D44 addu       $v1, $t2, $a0 */
    .word 0x246410D8 /* 001D1D48 addiu      $a0, $v1, 0x10D8 */
    .word 0x24847FF8 /* 001D1D4C addiu      $a0, $a0, 0x7FF8 */
    .word 0x8C830000 /* 001D1D50 lw         $v1, 0x0($a0) */
    .word 0xACC30004 /* 001D1D54 sw         $v1, 0x4($a2) */
    .word 0xAC860000 /* 001D1D58 sw         $a2, 0x0($a0) */
    .word 0x03E00008 /* 001D1D5C jr         $ra */
    .word 0x00000000 /* 001D1D60 nop */
}
#else
void func_001D1CC0(void *self, void *item) {
    char *item_ptr = (char *)item;
    void *t0 = *(void **)(item_ptr + 0x10);
    if (t0 == 0) {
        return;
    }

    unsigned char slot = *(unsigned char *)(item_ptr + 4);
    char *zm = (char *)self;
    int offset = slot * 4;

    void **head_ptr = (void **)(zm + offset + 0x9048);
    void **curr = (void **)*head_ptr;
    void **prev = 0;

    while (curr != 0) {
        if (curr[0] == item) {
            break;
        }
        prev = curr;
        curr = (void **)curr[1];
    }

    curr[0] = t0;
    if (prev != 0) {
        prev[1] = curr[1];
    } else {
        *head_ptr = curr[1];
    }
    *(void **)(item_ptr + 0x10) = 0;

    void **tail_ptr = (void **)(zm + offset + 0x908C);
    if (*tail_ptr == curr) {
        *tail_ptr = prev;
    }

    void **free_head_ptr = (void **)(zm + offset + 0x90D0);
    curr[1] = *free_head_ptr;
    *free_head_ptr = curr;
}
#endif
}
