#pragma exceptions off

#include "zone_spatial_view_deserialize.h"

extern "C" {
void func_226D90(void *stream, void *buf, int size);
void *func_1FC4F0();
void func_1FD230(void *node, void *stream);
extern float D_004E2F24;
extern float D_004E281C;
}

#if defined(__mips__)

extern "C" asm void func_001DB2C0(SpatialViewObj *self, void *stream) {
    .word 0x27BDFF90 /* addiu      $sp, $sp, -0x70 */
    .word 0x7FBF0050 /* sq         $ra, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x70808E28 /* paddub     $s1, $a0, $zero */
    .word 0x70A08628 /* paddub     $s0, $a1, $zero */
    .word 0x26250004 /* addiu      $a1, $s1, 0x4 */
    .word 0x24060030 /* addiu      $a2, $zero, 0x30 */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250034 /* addiu      $a1, $s1, 0x34 */
    .word 0x24060030 /* addiu      $a2, $zero, 0x30 */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250064 /* addiu      $a1, $s1, 0x64 */
    .word 0x2406000C /* addiu      $a2, $zero, 0xC */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250070 /* addiu      $a1, $s1, 0x70 */
    .word 0x2406000C /* addiu      $a2, $zero, 0xC */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x2625007C /* addiu      $a1, $s1, 0x7C */
    .word 0x2406000C /* addiu      $a2, $zero, 0xC */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250088 /* addiu      $a1, $s1, 0x88 */
    .word 0x2406000C /* addiu      $a2, $zero, 0xC */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250094 /* addiu      $a1, $s1, 0x94 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x26250098 /* addiu      $a1, $s1, 0x98 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x2625009C /* addiu      $a1, $s1, 0x9C */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x262500A0 /* addiu      $a1, $s1, 0xA0 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x262500A4 /* addiu      $a1, $s1, 0xA4 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x27A50068 /* addiu      $a1, $sp, 0x68 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x70009628 /* paddub    $s2, $zero, $zero */
    .word 0x1000000C /* b          .L001DB3DC */
    .word 0x70009E28 /* paddub    $s3, $zero, $zero */
    jal        func_1FC4F0 /* jal        func_1FC4F0 */
    .word 0x00000000 /* nop */
    .word 0x7040A628 /* paddub     $s4, $v0, $zero */
    .word 0x1280000C /* beqz       $s4, .L001DB3F0 */
    .word 0x27A5006C /* addiu     $a1, $sp, 0x6C */
    .word 0x72802628 /* paddub     $a0, $s4, $zero */
    jal        func_1FD230 /* jal        func_1FD230 */
    .word 0x72002E28 /* paddub    $a1, $s0, $zero */
    .word 0xAE920004 /* sw         $s2, 0x4($s4) */
    .word 0x26730001 /* addiu      $s3, $s3, 0x1 */
    .word 0x72809628 /* paddub     $s2, $s4, $zero */
    .word 0x8FA20068 /* lw         $v0, 0x68($sp) */
    .word 0x0262102A /* slt        $v0, $s3, $v0 */
    .word 0x1440FFF2 /* bnez       $v0, .L001DB3B0 */
    .word 0x00000000 /* nop */
    .word 0x27A5006C /* addiu      $a1, $sp, 0x6C */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0xAE3200A8 /* sw        $s2, 0xA8($s1) */
    .word 0x8FA2006C /* lw         $v0, 0x6C($sp) */
    .word 0x262500B0 /* addiu      $a1, $s1, 0xB0 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0xAE2200AC /* sw        $v0, 0xAC($s1) */
    .word 0xC7818764 /* lwc1       $f1, -0x789C($gp) */
    .word 0xC780805C /* lwc1       $f0, -0x7FA4($gp) */
    .word 0x46000834 /* c.lt.s     $f1, $f0 */
    .word 0x00000000 /* nop */
    .word 0x45010005 /* bc1t       .L001DB440 */
    .word 0x00000000 /* nop */
    .word 0x262500B4 /* addiu      $a1, $s1, 0xB4 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal        func_226D90 /* jal        func_226D90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x7BBF0050 /* lq         $ra, 0x50($sp) */
    .word 0x7BB40040 /* lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0070 /* addiu     $sp, $sp, 0x70 */
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

extern "C" void func_001DB2C0(SpatialViewObj *self, void *stream) {
    func_226D90(stream, self->f4, 0x30);
    func_226D90(stream, self->f34, 0x30);
    func_226D90(stream, self->f64, 0xC);
    func_226D90(stream, self->f70, 0xC);
    func_226D90(stream, self->f7C, 0xC);
    func_226D90(stream, self->f88, 0xC);
    func_226D90(stream, &self->f94, 0x4);
    func_226D90(stream, &self->f98, 0x4);
    func_226D90(stream, &self->f9C, 0x4);
    func_226D90(stream, &self->fA0, 0x4);
    func_226D90(stream, &self->fA4, 0x4);

    int count = 0;
    func_226D90(stream, &count, 0x4);

    Node *head = 0;
    for (int i = 0; i < count; i++) {
        Node *node = (Node *)func_1FC4F0();
        if (node != 0) {
            func_1FD230(node, stream);
            node->next = head;
            head = node;
        }
    }
    self->head_A8 = head;

    int vAC = 0;
    func_226D90(stream, &vAC, 0x4);
    self->fAC = vAC;

    func_226D90(stream, &self->fB0, 0x4);

    if (D_004E2F24 >= D_004E281C) {
        func_226D90(stream, &self->fB4, 0x4);
    }
}


#endif