#include "unit_action_build_target_check.h"

typedef int (*TargetCheckFn)(void *world, void *target_ba0);

struct TargetChecker {
    char pad[0x1B30];
    void **vtable;
};

extern "C" {
#if defined(__mips__)
void func_00264450(ActionRebind *self, int a1, int a2, int a3, int a4);

asm void func_00270F80(ActionRebind *self, int a1, int a2, int a3, int a4) {
    .word 0x27BDFFA0 /* addiu      $sp, $sp, -0x60 */
    .word 0x7FBF0050 /* sq         $ra, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x90820039 /* lbu        $v0, 0x39($a0) */
    .word 0x70A09E28 /* paddub     $s3, $a1, $zero */
    .word 0x70C09628 /* paddub     $s2, $a2, $zero */
    .word 0x70E08E28 /* paddub     $s1, $a3, $zero */
    .word 0x71008628 /* paddub     $s0, $t0, $zero */
    .word 0x1440001D /* bnez       $v0, .L00271028 */
    .word 0x7080A628 /* paddub    $s4, $a0, $zero */
    .word 0xC6810170 /* lwc1       $f1, 0x170($s4) */
    .word 0x44800000 /* mtc1       $zero, $f0 */
    .word 0x00000000 /* nop */
    .word 0x46010032 /* c.eq.s     $f0, $f1 */
    .word 0x00000000 /* nop */
    .word 0x45000017 /* bc1f       .L0027102C */
    .word 0x72802628 /* paddub    $a0, $s4, $zero */
    jal func_00186010
    .word 0x8F8489C0 /* lw        $a0, -0x7640($gp) */
    .word 0x8E840008 /* lw         $a0, 0x8($s4) */
    .word 0x8C991B30 /* lw         $t9, 0x1B30($a0) */
    .word 0x8F390024 /* lw         $t9, 0x24($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x8C450BA0 /* lw        $a1, 0xBA0($v0) */
    .word 0x10400016 /* beqz       $v0, .L0027104C */
    .word 0x00000000 /* nop */
    jal func_00186010
    .word 0x8F8489C0 /* lw        $a0, -0x7640($gp) */
    .word 0x8E830008 /* lw         $v1, 0x8($s4) */
    .word 0x8C591B30 /* lw         $t9, 0x1B30($v0) */
    .word 0x8C650BA0 /* lw         $a1, 0xBA0($v1) */
    .word 0x8F390024 /* lw         $t9, 0x24($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x70402628 /* paddub    $a0, $v0, $zero */
    .word 0x14400003 /* bnez       $v0, .L00271028 */
    .word 0x00000000 /* nop */
    .word 0x1000000B /* b          .L00271050 */
    .word 0x7BBF0050 /* lq        $ra, 0x50($sp) */
    .word 0x72802628 /* paddub     $a0, $s4, $zero */
    jal func_270E30
    .word 0x00000000 /* nop */
    .word 0x72802628 /* paddub     $a0, $s4, $zero */
    .word 0x72602E28 /* paddub     $a1, $s3, $zero */
    .word 0x72403628 /* paddub     $a2, $s2, $zero */
    .word 0x72203E28 /* paddub     $a3, $s1, $zero */
    jal func_00264450
    .word 0x72004628 /* paddub    $t0, $s0, $zero */
    .word 0x7BBF0050 /* lq         $ra, 0x50($sp) */
    .word 0x7BB40040 /* lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0060 /* addiu     $sp, $sp, 0x60 */
}
#else
void func_00270F80(ActionRebind *self, int a1, int a2, int a3, int a4) {
    if (self->m_field39 == 0) {
        if (*(float*)((char*)self + 0x170) == 0.0f) {
            void *res1 = func_00186010(D_004E3180);
            if (!((TargetCheckFn)((TargetChecker*)self->m_world)->vtable[9])(
                    self->m_world, *(void**)((char*)res1 + 0xBA0))) {
                return;
            }

            void *res2 = func_00186010(D_004E3180);
            if (!((TargetCheckFn)((TargetChecker*)res2)->vtable[9])(
                    res2, *(void**)((char*)self->m_world + 0xBA0))) {
                return;
            }
        }
    }

    func_270E30(self);
    func_264450(self, a1, a2, a3, a4);
}
#endif
}
