#pragma exceptions off

#include "zone_spatial_view_serialize.h"

extern "C" {
void func_226F70(void *stream, const void *buf, int size);
void func_1FD120(void *node, void *stream);
}

#if defined(__mips__)

extern "C" asm void func_001DB120(SpatialViewObj *self, void *stream) {
    .word 0x27BDFFB0 /* addiu      $sp, $sp, -0x50 */
    .word 0x7FBF0030 /* sq         $ra, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x70808E28 /* paddub     $s1, $a0, $zero */
    .word 0x70A08628 /* paddub     $s0, $a1, $zero */
    .word 0x26250004 /* addiu      $a1, $s1, 0x4 */
    .word 0x24060030 /* addiu      $a2, $zero, 0x30 */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250034 /* addiu      $a1, $s1, 0x34 */
    .word 0x24060030 /* addiu      $a2, $zero, 0x30 */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250064 /* addiu      $a1, $s1, 0x64 */
    .word 0x2406000C /* addiu      $a2, $zero, 0xC */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250070 /* addiu      $a1, $s1, 0x70 */
    .word 0x2406000C /* addiu      $a2, $zero, 0xC */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x2625007C /* addiu      $a1, $s1, 0x7C */
    .word 0x2406000C /* addiu      $a2, $zero, 0xC */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250088 /* addiu      $a1, $s1, 0x88 */
    .word 0x2406000C /* addiu      $a2, $zero, 0xC */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250094 /* addiu      $a1, $s1, 0x94 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250098 /* addiu      $a1, $s1, 0x98 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x2625009C /* addiu      $a1, $s1, 0x9C */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x262500A0 /* addiu      $a1, $s1, 0xA0 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x262500A4 /* addiu      $a1, $s1, 0xA4 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0xAFA00048 /* sw         $zero, 0x48($sp) */
    .word 0x10000005 /* b          .L001DB208 */
    .word 0x8E2300A8 /* lw        $v1, 0xA8($s1) */
    .word 0x8FA20048 /* lw         $v0, 0x48($sp) */
    .word 0x8C630004 /* lw         $v1, 0x4($v1) */
    .word 0x24420001 /* addiu      $v0, $v0, 0x1 */
    .word 0xAFA20048 /* sw         $v0, 0x48($sp) */
    .word 0x1460FFFB /* bnez       $v1, .L001DB1F8 */
    .word 0x00000000 /* nop */
    .word 0x27A50048 /* addiu      $a1, $sp, 0x48 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x1000000E /* b          .L001DB25C */
    .word 0x70009628 /* paddub    $s2, $zero, $zero */
    .word 0x8E2400A8 /* lw         $a0, 0xA8($s1) */
    .word 0x00721023 /* subu       $v0, $v1, $s2 */
    .word 0x2445FFFF /* addiu      $a1, $v0, -0x1 */
    .word 0x10000003 /* b          .L001DB244 */
    .word 0x70001E28 /* paddub    $v1, $zero, $zero */
    .word 0x8C840004 /* lw         $a0, 0x4($a0) */
    .word 0x24630001 /* addiu      $v1, $v1, 0x1 */
    .word 0x0065102A /* slt        $v0, $v1, $a1 */
    .word 0x1440FFFC /* bnez       $v0, .L001DB23C */
    .word 0x00000000 /* nop */
    jal        func_1FD120 /* jal        func_1FD120 */
    .word 0x72002E28 /* paddub    $a1, $s0, $zero */
    .word 0x26520001 /* addiu      $s2, $s2, 0x1 */
    .word 0x8FA30048 /* lw         $v1, 0x48($sp) */
    .word 0x0243102A /* slt        $v0, $s2, $v1 */
    .word 0x1440FFF0 /* bnez       $v0, .L001DB228 */
    .word 0x00000000 /* nop */
    .word 0x8E2200AC /* lw         $v0, 0xAC($s1) */
    .word 0x27A5004C /* addiu      $a1, $sp, 0x4C */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0xAFA2004C /* sw        $v0, 0x4C($sp) */
    .word 0x262500B0 /* addiu      $a1, $s1, 0xB0 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x262500B4 /* addiu      $a1, $s1, 0xB4 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226F70 /* jal        func_226F70 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x7BBF0030 /* lq         $ra, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0050 /* addiu     $sp, $sp, 0x50 */
}

#else

struct Node {
    char pad[0x4];
    Node *next;
};

struct SpatialViewObj {
    char pad_0[0x4];
    char f4[0x30];
    char f34[0x30];
    char f64[0xC];
    char f70[0xC];
    char f7C[0xC];
    char f88[0xC];
    int f94;
    int f98;
    int f9C;
    int fA0;
    int fA4;
    Node *head_A8;
    int fAC;
    int fB0;
    int fB4;
};

extern "C" void func_001DB120(SpatialViewObj *self, void *stream) {
    func_226F70(stream, self->f4, 0x30);
    func_226F70(stream, self->f34, 0x30);
    func_226F70(stream, self->f64, 0xC);
    func_226F70(stream, self->f70, 0xC);
    func_226F70(stream, self->f7C, 0xC);
    func_226F70(stream, self->f88, 0xC);
    func_226F70(stream, &self->f94, 0x4);
    func_226F70(stream, &self->f98, 0x4);
    func_226F70(stream, &self->f9C, 0x4);
    func_226F70(stream, &self->fA0, 0x4);
    func_226F70(stream, &self->fA4, 0x4);

    int count = 0;
    for (Node *curr = self->head_A8; curr != 0; curr = curr->next) {
        count++;
    }
    func_226F70(stream, &count, 0x4);

    for (int i = 0; i < count; i++) {
        Node *target = self->head_A8;
        for (int j = 0; j < (count - i - 1); j++) {
            target = target->next;
        }
        func_1FD120(target, stream);
    }

    int vAC = self->fAC;
    func_226F70(stream, &vAC, 0x4);
    func_226F70(stream, &self->fB0, 0x4);
    func_226F70(stream, &self->fB4, 0x4);
}


#endif