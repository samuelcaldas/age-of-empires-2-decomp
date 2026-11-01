#include "unit_action_build_target_check4.h"

typedef void* (*TargetCheckFn)(void *world, void *target_ba0);

extern "C" {
#if defined(__mips__)
void func_002647C0(ActionRebind *self, int a1, int a2, int a3);

asm void func_00271150(ActionRebind *self, int a1, int a2, int a3) {
    .word 0x27BDFFB0 /* addiu      $sp, $sp, -0x50 */
    .word 0x7FBF0040 /* sq         $ra, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x90820039 /* lbu        $v0, 0x39($a0) */
    .word 0x70A09628 /* paddub     $s2, $a1, $zero */
    .word 0x70C08E28 /* paddub     $s1, $a2, $zero */
    .word 0x70E08628 /* paddub     $s0, $a3, $zero */
    .word 0x1440001D /* bnez       $v0, .L002711F0 */
    .word 0x70809E28 /* paddub    $s3, $a0, $zero */
    .word 0xC6610170 /* lwc1       $f1, 0x170($s3) */
    .word 0x44800000 /* mtc1       $zero, $f0 */
    .word 0x00000000 /* nop */
    .word 0x46010032 /* c.eq.s     $f0, $f1 */
    .word 0x00000000 /* nop */
    .word 0x45000017 /* bc1f       .L002711F4 */
    .word 0x72602628 /* paddub    $a0, $s3, $zero */
    jal func_00186010
    .word 0x8F8489C0 /* lw        $a0, -0x7640($gp) */
    .word 0x8E640008 /* lw         $a0, 0x8($s3) */
    .word 0x8C991B30 /* lw         $t9, 0x1B30($a0) */
    .word 0x8F390024 /* lw         $t9, 0x24($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x8C450BA0 /* lw        $a1, 0xBA0($v0) */
    .word 0x10400012 /* beqz       $v0, .L00271204 */
    .word 0x00000000 /* nop */
    jal func_00186010
    .word 0x8F8489C0 /* lw        $a0, -0x7640($gp) */
    .word 0x8E630008 /* lw         $v1, 0x8($s3) */
    .word 0x8C591B30 /* lw         $t9, 0x1B30($v0) */
    .word 0x8C650BA0 /* lw         $a1, 0xBA0($v1) */
    .word 0x8F390024 /* lw         $t9, 0x24($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x70402628 /* paddub    $a0, $v0, $zero */
    .word 0x14400003 /* bnez       $v0, .L002711F0 */
    .word 0x00000000 /* nop */
    .word 0x10000007 /* b          .L00271208 */
    .word 0x7BBF0040 /* lq        $ra, 0x40($sp) */
    .word 0x72602628 /* paddub     $a0, $s3, $zero */
    .word 0x72402E28 /* paddub     $a1, $s2, $zero */
    .word 0x72203628 /* paddub     $a2, $s1, $zero */
    jal func_002647C0
    .word 0x72003E28 /* paddub    $a3, $s0, $zero */
    .word 0x7BBF0040 /* lq         $ra, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0050 /* addiu     $sp, $sp, 0x50 */
}
#else
void func_00271150(ActionRebind *self, int a1, int a2, int a3) {
    if (self->m_field39 == 0) {
        if (*(float*)((char*)self + 0x170) == 0.0f) {
            void *res1 = func_00186010(D_004E3180);
            void *actor = self->m_world;
            TargetCheckFn m1 = (TargetCheckFn)(*(void***)((char*)actor + 0x1B30))[9];
            if (!m1(actor, *(void**)((char*)res1 + 0xBA0))) {
                return;
            }

            void *res2 = func_00186010(D_004E3180);
            void *actor2 = self->m_world;
            TargetCheckFn m2 = (TargetCheckFn)(*(void***)((char*)res2 + 0x1B30))[9];
            if (!m2(res2, *(void**)((char*)actor2 + 0xBA0))) {
                return;
            }
        }
    }

    func_2647C0(self, a1, a2, a3);
}
#endif
}
