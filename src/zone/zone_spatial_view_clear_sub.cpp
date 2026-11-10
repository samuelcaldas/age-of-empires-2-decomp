#pragma once
#pragma exceptions off

#include "zone_spatial_view_clear_sub.h"

extern "C" {
void func_1FC610(void *ptr);
void func_1FCD90(void *ptr);

#if defined(__mips__)
asm void func_001D9110(SpatialViewObj *self) {
    .word 0x27BDFFD0 /* 001D9110 addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* 001D9114 sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* 001D9118 sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D911C sq         $s0, 0x0($sp) */
    .word 0x70808628 /* 001D9120 paddub     $s0, $a0, $zero */
    .word 0x8C8400A8 /* 001D9124 lw         $a0, 0xA8($a0) */
    .word 0x10800023 /* 001D9128 beqz       $a0, .L001D91B8 */
    .word 0x00000000 /* 001D912C nop */
    .word 0x8C830004 /* 001D9130 lw         $v1, 0x4($a0) */
    .word 0x14600009 /* 001D9134 bnez       $v1, .L001D915C */
    .word 0x00000000 /* 001D9138 nop */
    .word 0x1000001F /* 001D913C b          .L001D91BC */
    .word 0x7BBF0020 /* 001D9140 lq         $ra, 0x20($sp) */
lbl_1D9144:
    .word 0x8C910004 /* 001D9144 lw         $s1, 0x4($a0) */
    .word 0x1220000A /* 001D9148 beqz       $s1, .L001D9174 */
    .word 0x00000000 /* 001D914C nop */
    jal func_1FC610
    .word 0xAC800004 /* 001D9154 sw         $zero, 0x4($a0) */
    .word 0x72202628 /* 001D9158 paddub     $a0, $s1, $zero */
lbl_1D915C:
    .word 0x10800005 /* 001D915C beqz       $a0, .L001D9174 */
    .word 0x00000000 /* 001D9160 nop */
    .word 0x80850025 /* 001D9164 lb         $a1, 0x25($a0) */
    .word 0x24030002 /* 001D9168 addiu      $v1, $zero, 0x2 */
    .word 0x14A3FFF5 /* 001D916C bne        $a1, $v1, .L001D9144 */
    .word 0x00000000 /* 001D9170 nop */
lbl_1D9174:
    .word 0xAE0400A8 /* 001D9174 sw         $a0, 0xA8($s0) */
    .word 0x8E0400A8 /* 001D9178 lw         $a0, 0xA8($s0) */
    .word 0x1080000E /* 001D917C beqz       $a0, .L001D91B8 */
    .word 0x00000000 /* 001D9180 nop */
    .word 0x80830025 /* 001D9184 lb         $v1, 0x25($a0) */
    .word 0x24050002 /* 001D9188 addiu      $a1, $zero, 0x2 */
    .word 0x14650008 /* 001D918C bne        $v1, $a1, .L001D91B0 */
    .word 0x24030001 /* 001D9190 addiu      $v1, $zero, 0x1 */
    .word 0xAC830010 /* 001D9194 sw         $v1, 0x10($a0) */
    .word 0x8E0300A8 /* 001D9198 lw         $v1, 0xA8($s0) */
    .word 0x2404000A /* 001D919C addiu      $a0, $zero, 0xA */
    .word 0xA0650026 /* 001D91A0 sb         $a1, 0x26($v1) */
    .word 0x8E0300A8 /* 001D91A4 lw         $v1, 0xA8($s0) */
    .word 0x10000003 /* 001D91A8 b          .L001D91B8 */
    .word 0xA0640027 /* 001D91AC sb         $a0, 0x27($v1) */
lbl_1D91B0:
    jal func_1FCD90
    .word 0x00000000 /* 001D91B4 nop */
lbl_1D91B8:
    .word 0x7BBF0020 /* 001D91B8 lq         $ra, 0x20($sp) */
lbl_1D91BC:
    .word 0x7BB10010 /* 001D91BC lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D91C0 lq         $s0, 0x0($sp) */
    jr $ra
    .word 0x27BD0030 /* 001D91C8 addiu      $sp, $sp, 0x30 */
}
#endif
}

#if !defined(__mips__)
struct SubObj {
    char pad0[4];
    SubObj *next;
    char pad1[0x10 - 8];
    int field_10;
    char pad2[0x25 - 0x14];
    char field_25;
    char field_26;
    char field_27;
};

struct SpatialViewObj {
    char pad[0xA8];
    SubObj *sub;
};

extern "C" void func_001D9110(SpatialViewObj *self) {
    SubObj *cur = self->sub;
    if (!cur) {
        return;
    }
    if (cur->next != 0) {
        do {
            SubObj *next = cur->next;
            if (!next) {
                break;
            }
            func_1FC610(cur);
            cur->next = 0;
            cur = next;
            if (!cur) {
                break;
            }
        } while (cur->field_25 != 2);
        self->sub = cur;
    }
    cur = self->sub;
    if (!cur) {
        return;
    }
    if (cur->field_25 == 2) {
        cur->field_10 = 1;
        self->sub->field_26 = 2;
        self->sub->field_27 = 10;
        return;
    }
    func_1FCD90(cur);
}
#endif
