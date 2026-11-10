#pragma exceptions off
#include "unit_action_sub_actions.h"

#if defined(__mips__)

asm void func_0026CF30(ActionRebind *self) {
    .word 0x27BDFFC0 /* 30: addiu      $sp, $sp, -0x40 */
    .word 0x7FBF0030 /* 34: sq         $ra, 0x30($sp) */
    .word 0x7FB20020 /* 38: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 3C: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 40: sq         $s0, 0x0($sp) */
    jal Action__7SubListFv /* 44 */
    .word 0x70808628 /* 48: paddub    $s0, $a0, $zero */
    jal func_001880b0 /* 4C */
    .word 0x8F8489C0 /* 50: lw        $a0, -0x7640($gp) */
    .word 0x10400022 /* 54: beqz       $v0, .L0026CFE0 */
    .word 0x00000000 /* 58: nop */
    .word 0x8E020130 /* 5C: lw         $v0, 0x130($s0) */
    .word 0x1040000F /* 60: beqz       $v0, .L0026CFA0 */
    .word 0x70008E28 /* 64: paddub    $s1, $zero, $zero */
    .word 0x2445FFFF /* 68: addiu      $a1, $v0, -0x1 */
    jal func_002668C0 /* 6C */
    .word 0x72002628 /* 70: paddub    $a0, $s0, $zero */
    .word 0xAE020130 /* 74: sw         $v0, 0x130($s0) */
    .word 0x8E030004 /* 78: lw         $v1, 0x4($s0) */
    .word 0x24020027 /* 7C: addiu      $v0, $zero, 0x27 */
    .word 0x8463000E /* 80: lh         $v1, 0xE($v1) */
    .word 0x10620005 /* 84: beq        $v1, $v0, .L0026CF9C */
    .word 0x00000000 /* 88: nop */
    .word 0x8E020008 /* 8C: lw         $v0, 0x8($s0) */
    .word 0x72002E28 /* 90: paddub     $a1, $s0, $zero */
    jal func_001ECD00 /* 94 */
    .word 0x24440098 /* 98: addiu     $a0, $v0, 0x98 */
    .word 0x70008E28 /* 9C: paddub     $s1, $zero, $zero */
    .word 0x1000000D /* A0: b          .L0026CFD8 */
    .word 0x2A220004 /* A4: slti      $v0, $s1, 0x4 */
    .word 0x00111080 /* A8: sll        $v0, $s1, 2 */
    .word 0x02021021 /* AC: addu       $v0, $s0, $v0 */
    .word 0x24520134 /* B0: addiu      $s2, $v0, 0x134 */
    .word 0x8C420134 /* B4: lw         $v0, 0x134($v0) */
    .word 0x50400006 /* B8: beql       $v0, $zero, .L0026CFD4 */
    .word 0x26310001 /* BC: addiu     $s1, $s1, 0x1 */
    .word 0x2445FFFF /* C0: addiu      $a1, $v0, -0x1 */
    jal func_002668C0 /* C4 */
    .word 0x72002628 /* C8: paddub    $a0, $s0, $zero */
    .word 0xAE420000 /* CC: sw         $v0, 0x0($s2) */
    .word 0x26310001 /* D0: addiu      $s1, $s1, 0x1 */
    .word 0x2A220004 /* D4: slti       $v0, $s1, 0x4 */
    .word 0x1440FFF4 /* D8: bnez       $v0, .L0026CFAC */
    .word 0x00111080 /* DC: sll       $v0, $s1, 2 */
    jal Action__8BaseListFv /* E0 */
    .word 0x8E040128 /* E4: lw        $a0, 0x128($s0) */
    jal Action__8BaseListFv /* E8 */
    .word 0x8E04012C /* EC: lw        $a0, 0x12C($s0) */
    jal Action__8BaseListFv /* F0 */
    .word 0x8E04014C /* F4: lw        $a0, 0x14C($s0) */
    .word 0x7BBF0030 /* F8: lq         $ra, 0x30($sp) */
    .word 0x7BB20020 /* FC: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 00: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 04: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 08: jr         $ra */
    .word 0x27BD0040 /* 0C: addiu     $sp, $sp, 0x40 */
}

#else

void func_0026CF30(ActionRebind *self) {
    Action__7SubListFv(self);
    if (func_1880B0(D_004E3180) != 0) {
        int sub0 = *(int*)((char*)self + 0x130);
        if (sub0 != 0) {
            *(int*)((char*)self + 0x130) = (int)func_2668c0(self, sub0 - 1);
            if (*(short*)((char*)*(void**)((char*)self + 0x4) + 0xE) != 39) {
                func_1ECD00((char*)*(void**)((char*)self + 0x8) + 0x98, self);
            }
        }
        for (int i = 0; i < 4; ++i) {
            int sub_val = *(int*)((char*)self + 0x134 + i * 4);
            if (sub_val != 0) {
                *(int*)((char*)self + 0x134 + i * 4) = (int)func_2668c0(self, sub_val - 1);
            }
        }
    }
    Action__8BaseListFv(*(void**)((char*)self + 0x128));
    Action__8BaseListFv(*(void**)((char*)self + 0x12C));
    Action__8BaseListFv(*(void**)((char*)self + 0x14C));
}

#endif
