#pragma exceptions off
#include "unit_action_los_wrapper.h"

extern "C" {
int func_00123350(float val);
void func_00268A60(ActionRebind *self, void *zone, int arg2, int arg3, int arg4);
void func_00268C30(ActionRebind *self, void *zone, int arg2, int arg3, int arg4);

#if defined(__mips__)
asm void func_0026D960(ActionRebind *self, void *zone, int arg2, int arg3, int arg4) {
    .word 0x27BDFFa0 /* addiu      $sp, $sp, -0x60 */
    .word 0x7FBF0050 /* sq         $ra, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x70A09E28 /* paddub     $s3, $a1, $zero */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x24054000 /* addiu      $a1, $zero, 0x4000 */
    .word 0x70C09628 /* paddub     $s2, $a2, $zero */
    .word 0x70E08E28 /* paddub     $s1, $a3, $zero */
    .word 0x71008628 /* paddub     $s0, $t0, $zero */
    jal func_26AD20
    .word 0x7080A628 /* paddub    $s4, $a0, $zero */
    .word 0x10400013 /* beqz       $v0, .L0026D9E8 */
    .word 0x24060001 /* addiu     $a2, $zero, 0x1 */
    .word 0x8E820004 /* lw         $v0, 0x4($s4) */
    .word 0xC4410020 /* lwc1       $f1, 0x20($v0) */
    .word 0xC4400024 /* lwc1       $f0, 0x24($v0) */
    jal func_00123350
    .word 0x46000B00 /* add.s     $f12, $f1, $f0 */
    .word 0x30420001 /* andi       $v0, $v0, 0x1 */
    .word 0x14400003 /* bnez       $v0, .L0026D9C8 */
    .word 0x72802628 /* paddub    $a0, $s4, $zero */
    .word 0x24100001 /* addiu      $s0, $zero, 0x1 */
    .word 0x72802628 /* paddub     $a0, $s4, $zero */
    .word 0x72602E28 /* paddub     $a1, $s3, $zero */
    .word 0x72403628 /* paddub     $a2, $s2, $zero */
    .word 0x72203E28 /* paddub     $a3, $s1, $zero */
    jal func_00268A60
    .word 0x72004628 /* paddub    $t0, $s0, $zero */
    .word 0x10000008 /* b          .L0026DA00 */
    .word 0x7BBF0050 /* lq        $ra, 0x50($sp) */
    .word 0x24060001 /* addiu      $a2, $zero, 0x1 */
    .word 0x72802628 /* paddub     $a0, $s4, $zero */
    .word 0x72602E28 /* paddub     $a1, $s3, $zero */
    .word 0x72203E28 /* paddub     $a3, $s1, $zero */
    jal func_00268A60
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

asm void func_0026DA20(ActionRebind *self, void *zone, int arg2, int arg3, int arg4) {
    .word 0x27BDFFa0 /* addiu      $sp, $sp, -0x60 */
    .word 0x7FBF0050 /* sq         $ra, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x70A09E28 /* paddub     $s3, $a1, $zero */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x24054000 /* addiu      $a1, $zero, 0x4000 */
    .word 0x70C09628 /* paddub     $s2, $a2, $zero */
    .word 0x70E08E28 /* paddub     $s1, $a3, $zero */
    .word 0x71008628 /* paddub     $s0, $t0, $zero */
    jal func_26AD20
    .word 0x7080A628 /* paddub    $s4, $a0, $zero */
    .word 0x5040000B /* beql       $v0, $zero, .L0026DA88 */
    .word 0x72802628 /* paddub    $a0, $s4, $zero */
    .word 0x8E820004 /* lw         $v0, 0x4($s4) */
    .word 0xC4410020 /* lwc1       $f1, 0x20($v0) */
    .word 0xC4400024 /* lwc1       $f0, 0x24($v0) */
    jal func_00123350
    .word 0x46000B00 /* add.s     $f12, $f1, $f0 */
    .word 0x30420001 /* andi       $v0, $v0, 0x1 */
    .word 0x14400002 /* bnez       $v0, .L0026DA84 */
    .word 0x00000000 /* nop */
    .word 0x24100001 /* addiu      $s0, $zero, 0x1 */
    .word 0x72802628 /* paddub     $a0, $s4, $zero */
    .word 0x72602E28 /* paddub     $a1, $s3, $zero */
    .word 0x72403628 /* paddub     $a2, $s2, $zero */
    .word 0x72203E28 /* paddub     $a3, $s1, $zero */
    jal func_00268C30
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
void func_0026D960(ActionRebind *self, void *zone, int arg2, int arg3, int arg4) {
    if (func_26AD20(self, 0x4000) == 0) {
        func_00268A60(self, zone, 1, arg3, arg4);
        return;
    }
    void *f4 = self->m_field4;
    float ext_x = *(float*)((char*)f4 + 0x20);
    float ext_y = *(float*)((char*)f4 + 0x24);
    int sum = func_123350(ext_x + ext_y);
    if ((sum & 1) == 0) {
        arg4 = 1;
    }
    func_00268A60(self, zone, arg2, arg3, arg4);
}

void func_0026DA20(ActionRebind *self, void *zone, int arg2, int arg3, int arg4) {
    if (func_26AD20(self, 0x4000) != 0) {
        void *f4 = self->m_field4;
        float ext_x = *(float*)((char*)f4 + 0x20);
        float ext_y = *(float*)((char*)f4 + 0x24);
        int sum = func_123350(ext_x + ext_y);
        if ((sum & 1) == 0) {
            arg4 = 1;
        }
    }
    func_00268C30(self, zone, arg2, arg3, arg4);
}
#endif
}
