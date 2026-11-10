#pragma exceptions off
#include "unit_action_build_7b810.h"

extern "C" {
#if defined(__mips__)
asm void *func_0027B810(void *self, int type) {
    .word 0x8C8201E0 /* 0027B810 lw         $v0, 0x1E0($a0) */
    .word 0x10000008 /* 0027B814 b          .L0027B838 */
    .word 0x30A400FF /* 0027B818 andi      $a0, $a1, 0xFF */
    .word 0x90430000 /* 0027B81C lbu        $v1, 0x0($v0) */
    .word 0x14640003 /* 0027B820 bne        $v1, $a0, .L0027B830 */
    .word 0x00000000 /* 0027B824 nop */
    .word 0x10000006 /* 0027B828 b          .L0027B844 */
    .word 0x00000000 /* 0027B82C nop */
    .word 0x8C420018 /* 0027B830 lw         $v0, 0x18($v0) */
    .word 0x00000000 /* 0027B834 nop */
    .word 0x1440FFF8 /* 0027B838 bnez       $v0, .L0027B81C */
    .word 0x00000000 /* 0027B83C nop */
    .word 0x70001628 /* 0027B840 paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* 0027B844 jr         $ra */
    .word 0x00000000 /* 0027B848 nop */
}

asm int func_0027B850(void *self, int target_index, void **out_entry) {
    .word 0x8C8201E0 /* 0027B850 lw         $v0, 0x1E0($a0) */
    .word 0x10000008 /* 0027B854 b          .L0027B878 */
    .word 0x24030001 /* 0027B858 addiu     $v1, $zero, 0x1 */
    .word 0x14650004 /* 0027B85C bne        $v1, $a1, .L0027B870 */
    .word 0x00000000 /* 0027B860 nop */
    .word 0xACC20000 /* 0027B864 sw         $v0, 0x0($a2) */
    .word 0x10000007 /* 0027B868 b          .L0027B888 */
    .word 0x24020001 /* 0027B86C addiu     $v0, $zero, 0x1 */
    .word 0x8C420018 /* 0027B870 lw         $v0, 0x18($v0) */
    .word 0x24630001 /* 0027B874 addiu      $v1, $v1, 0x1 */
    .word 0x1440FFF8 /* 0027B878 bnez       $v0, .L0027B85C */
    .word 0x00000000 /* 0027B87C nop */
    .word 0xACC00000 /* 0027B880 sw         $zero, 0x0($a2) */
    .word 0x70001628 /* 0027B884 paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* 0027B888 jr         $ra */
    .word 0x00000000 /* 0027B88C nop */
}

asm int func_0027B890(void *self, int target_count, void **out_entry) {
    .word 0x10000009 /* 0027B890 b          .L0027B8B8 */
    .word 0x8C8301E0 /* 0027B894 lw        $v1, 0x1E0($a0) */
    .word 0x8C620004 /* 0027B898 lw         $v0, 0x4($v1) */
    .word 0x14450004 /* 0027B89C bne        $v0, $a1, .L0027B8B0 */
    .word 0x00000000 /* 0027B8A0 nop */
    .word 0x24020001 /* 0027B8A4 addiu      $v0, $zero, 0x1 */
    .word 0x10000007 /* 0027B8A8 b          .L0027B8C8 */
    .word 0xACC30000 /* 0027B8AC sw        $v1, 0x0($a2) */
    .word 0x8C630018 /* 0027B8B0 lw         $v1, 0x18($v1) */
    .word 0x00000000 /* 0027B8B4 nop */
    .word 0x1460FFF7 /* 0027B8B8 bnez       $v1, .L0027B898 */
    .word 0x00000000 /* 0027B8BC nop */
    .word 0xACC00000 /* 0027B8C0 sw         $zero, 0x0($a2) */
    .word 0x70001628 /* 0027B8C4 paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* 0027B8C8 jr         $ra */
    .word 0x00000000 /* 0027B8CC nop */
}

asm int func_0027B8D0(void *self, int target_count, int *out_pos, char *out_match_count) {
    .word 0x8C8301E0 /* 0027B8D0 lw         $v1, 0x1E0($a0) */
    .word 0x24080001 /* 0027B8D4 addiu      $t0, $zero, 0x1 */
    .word 0x70004E28 /* 0027B8D8 paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 0027B8DC paddub     $t2, $zero, $zero */
    .word 0x1000000B /* 0027B8E0 b          .L0027B910 */
    .word 0x70002628 /* 0027B8E4 paddub    $a0, $zero, $zero */
    .word 0x8C620004 /* 0027B8E8 lw         $v0, 0x4($v1) */
    .word 0x14450006 /* 0027B8EC bne        $v0, $a1, .L0027B908 */
    .word 0x00000000 /* 0027B8F0 nop */
    .word 0x24090001 /* 0027B8F4 addiu      $t1, $zero, 0x1 */
    .word 0x11490003 /* 0027B8F8 beq        $t2, $t1, .L0027B908 */
    .word 0x24840001 /* 0027B8FC addiu     $a0, $a0, 0x1 */
    .word 0xACC80000 /* 0027B900 sw         $t0, 0x0($a2) */
    .word 0x71205628 /* 0027B904 paddub     $t2, $t1, $zero */
    .word 0x8C630018 /* 0027B908 lw         $v1, 0x18($v1) */
    .word 0x25080001 /* 0027B90C addiu      $t0, $t0, 0x1 */
    .word 0x1460FFF5 /* 0027B910 bnez       $v1, .L0027B8E8 */
    .word 0x00000000 /* 0027B914 nop */
    .word 0x24020001 /* 0027B818 addiu      $v0, $zero, 0x1 */
    .word 0x55220004 /* 0027B91C bnel       $t1, $v0, .L0027B930 */
    .word 0x2402FFFF /* 0027B920 addiu     $v0, $zero, -0x1 */
    .word 0x10000006 /* 0027B924 b          .L0027B940 */
    .word 0xA0E40000 /* 0027B928 sb        $a0, 0x0($a3) */
    .word 0x2402FFFF /* 0027B92C addiu      $v0, $zero, -0x1 */
    .word 0xACC20000 /* 0027B930 sw         $v0, 0x0($a2) */
    .word 0x240200FF /* 0027B934 addiu      $v0, $zero, 0xFF */
    .word 0xA0E20000 /* 0027B938 sb         $v0, 0x0($a3) */
    .word 0x70001628 /* 0027B93C paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* 0027B940 jr         $ra */
    .word 0x00000000 /* 0027B944 nop */
}
#else
void *func_0027B810(void *self, int type) {
    void *current = *(void **)((char *)self + 0x1E0);
    unsigned char target_type = (unsigned char)type;
    while (current != 0) {
        if (*(unsigned char *)((char *)current + 0x0) == target_type) {
            return current;
        }
        current = *(void **)((char *)current + 0x18);
    }
    return 0;
}

int func_0027B850(void *self, int target_index, void **out_entry) {
    void *current = *(void **)((char *)self + 0x1E0);
    int index = 1;
    while (current != 0) {
        if (index == target_index) {
            *out_entry = current;
            return 1;
        }
        current = *(void **)((char *)current + 0x18);
        index++;
    }
    *out_entry = 0;
    return 0;
}

int func_0027B890(void *self, int target_count, void **out_entry) {
    void *current = *(void **)((char *)self + 0x1E0);
    while (current != 0) {
        if (*(int *)((char *)current + 0x4) == target_count) {
            *out_entry = current;
            return 1;
        }
        current = *(void **)((char *)current + 0x18);
    }
    *out_entry = 0;
    return 0;
}

int func_0027B8D0(void *self, int target_count, int *out_pos, char *out_match_count) {
    void *current = *(void **)((char *)self + 0x1E0);
    int pos = 1;
    int match_found = 0;
    int first_recorded = 0;
    char match_count = 0;

    while (current != 0) {
        if (*(int *)((char *)current + 0x4) == target_count) {
            match_found = 1;
            if (first_recorded == 0) {
                *out_pos = pos;
                first_recorded = 1;
            }
            match_count++;
        }
        current = *(void **)((char *)current + 0x18);
        pos++;
    }

    if (match_found != 0) {
        *out_match_count = match_count;
    } else {
        *out_pos = -1;
        *out_match_count = -1;
    }
    return 0;
}
#endif
}
