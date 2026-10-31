#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x0021ACD0 */
extern "C" {
void func_00221B60();
void func_0021DF50();
void func_00223F50();
void func_0021E370();

asm int func_0021ACD0(void *arg0, void *arg1) {
    .word 0x27BDFFC0 /* addiu      $sp, $sp, -0x40 */
    .word 0x7FBF0030 /* sq         $ra, 0x30($sp) */
    .word 0x7FB10020 /* sq         $s1, 0x20($sp) */
    .word 0x7FB00010 /* sq         $s0, 0x10($sp) */
    .word 0x9C830098 /* lwu        $v1, 0x98($a0) */
    .word 0x70808628 /* paddub     $s0, $a0, $zero */
    .word 0x30630800 /* andi       $v1, $v1, 0x800 */
    .word 0x10600017 /* beqz       $v1, .L0021AD4C */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x9CA30098 /* lwu        $v1, 0x98($a1) */
    .word 0x30630200 /* andi       $v1, $v1, 0x200 */
    .word 0x14600003 /* bnez       $v1, .L0021AD0C */
    .word 0x8E110054 /* lw        $s1, 0x54($s0) */
    jal func_00221B60
    .word 0x2404000C /* addiu     $a0, $zero, 0xC */
    .word 0x86030038 /* lh         $v1, 0x38($s0) */
    .word 0x70402628 /* paddub     $a0, $v0, $zero */
    .word 0x2402FFFC /* addiu      $v0, $zero, -0x4 */
    .word 0x240528C0 /* addiu      $a1, $zero, 0x28C0 */
    .word 0xFFA30000 /* sd         $v1, 0x0($sp) */
    .word 0x8E03003C /* lw         $v1, 0x3C($s0) */
    .word 0x8606001C /* lh         $a2, 0x1C($s0) */
    .word 0x2407000A /* addiu      $a3, $zero, 0xA */
    .word 0x72204628 /* paddub     $t0, $s1, $zero */
    .word 0x70004E28 /* paddub     $t1, $zero, $zero */
    .word 0x24630003 /* addiu      $v1, $v1, 0x3 */
    .word 0x00621024 /* and        $v0, $v1, $v0 */
    .word 0x00025C3C /* dsll32     $t3, $v0, 16 */
    .word 0x70005628 /* paddub     $t2, $zero, $zero */
    jal func_0021DF50
    .word 0x000B5C3F /* dsra32    $t3, $t3, 16 */
    .word 0x7BBF0030 /* lq         $ra, 0x30($sp) */
    .word 0x7BB10020 /* lq         $s1, 0x20($sp) */
    .word 0x7BB00010 /* lq         $s0, 0x10($sp) */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0040 /* addiu     $sp, $sp, 0x40 */
}

asm int func_0021AD70(void *self) {
    .word 0x27BDFFE0 /* addiu      $sp, $sp, -0x20 */
    .word 0x7FBF0010 /* sq         $ra, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x9C830098 /* lwu        $v1, 0x98($a0) */
    .word 0x8C820054 /* lw         $v0, 0x54($a0) */
    .word 0x70808628 /* paddub     $s0, $a0, $zero */
    .word 0x70005628 /* paddub     $t2, $zero, $zero */
    .word 0x30630200 /* andi       $v1, $v1, 0x200 */
    .word 0x10600005 /* beqz       $v1, .L0021ADA8 */
    .word 0x70005E28 /* paddub    $t3, $zero, $zero */
    jal func_00223F50
    .word 0x00000000 /* nop */
    .word 0x240A0002 /* addiu      $t2, $zero, 0x2 */
    .word 0x71405E28 /* paddub     $t3, $t2, $zero */
    .word 0x9E040098 /* lwu        $a0, 0x98($s0) */
    .word 0x30830800 /* andi       $v1, $a0, 0x800 */
    .word 0x10600006 /* beqz       $v1, .L0021ADCC */
    .word 0x30830200 /* andi      $v1, $a0, 0x200 */
    .word 0x3C02000A /* lui        $v0, (0xA3000 >> 16) */
    .word 0x34423000 /* ori        $v0, $v0, (0xA3000 & 0xFFFF) */
    .word 0x70005628 /* paddub     $t2, $zero, $zero */
    .word 0x70005E28 /* paddub     $t3, $zero, $zero */
    .word 0x30830200 /* andi       $v1, $a0, 0x200 */
    .word 0x10600008 /* beqz       $v1, .L0021ADF0 */
    .word 0x00000000 /* nop */
    .word 0x8E07003C /* lw         $a3, 0x3C($s0) */
    .word 0x8E080038 /* lw         $t0, 0x38($s0) */
    .word 0x8E06001C /* lw         $a2, 0x1C($s0) */
    .word 0x70402E28 /* paddub     $a1, $v0, $zero */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    jal func_0021E370
    .word 0x3C090005 /* lui       $t1, (0x50000 >> 16) */
    .word 0x7BBF0010 /* lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0020 /* addiu     $sp, $sp, 0x20 */
}

asm int func_0021AE10(void *self) {
    .word 0x27BDFFE0 /* addiu      $sp, $sp, -0x20 */
    .word 0x7FBF0010 /* sq         $ra, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x9C820098 /* lwu        $v0, 0x98($a0) */
    .word 0x30420200 /* andi       $v0, $v0, 0x200 */
    .word 0x10400003 /* beqz       $v0, .L0021AE34 */
    .word 0x70808628 /* paddub    $s0, $a0, $zero */
    .word 0x10000011 /* b          .L0021AE74 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    jal func_00223F50
    .word 0x00000000 /* nop */
    .word 0x9E030098 /* lwu        $v1, 0x98($s0) */
    .word 0x30630200 /* andi       $v1, $v1, 0x200 */
    .word 0x5060000B /* beql       $v1, $zero, .L0021AE74 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x8E06001C /* lw         $a2, 0x1C($s0) */
    .word 0x240A0002 /* addiu      $t2, $zero, 0x2 */
    .word 0x24070280 /* addiu      $a3, $zero, 0x280 */
    .word 0x24080200 /* addiu      $t0, $zero, 0x200 */
    .word 0x70402E28 /* paddub     $a1, $v0, $zero */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    .word 0x3C090005 /* lui        $t1, (0x50000 >> 16) */
    jal func_0021E370
    .word 0x71405E28 /* paddub    $t3, $t2, $zero */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x7BBF0010 /* lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0020 /* addiu     $sp, $sp, 0x20 */
}
}

#else

extern "C" {
void *func_00221B60(int type);
void func_0021DF50(void *ctx, int a1, int f1c, int a3, int s1, int a5, int a6, int aligned_3c, long long f38);
void func_00223F50(void);
void func_0021E370(int a0, int v0, int f1c, int a3, int t0, int t1, int t2, int t3);

int func_0021ACD0(void *arg0, void *arg1) {
    char *s0 = (char *)arg0;
    unsigned int flags0 = *(unsigned int *)(s0 + 0x98);

    if ((flags0 & 0x800) == 0) {
        return 0;
    }

    char *s1 = (char *)arg1;
    unsigned int flags1 = *(unsigned int *)(s1 + 0x98);
    if ((flags1 & 0x200) != 0) {
        return 0;
    }

    int s1_54 = *(int *)(s0 + 0x54);
    void *ctx = func_00221B60(0xC);
    short f38 = *(short *)(s0 + 0x38);
    short f1c = *(short *)(s0 + 0x1C);
    int f3c = *(int *)(s0 + 0x3C);
    int aligned_3c = (f3c + 3) & ~3;

    func_0021DF50(ctx, 0x28C0, f1c, 0xA, s1_54, 0, 0, aligned_3c, f38);
    return 0;
}

int func_0021AD70(void *self) {
    char *self_bytes = (char *)self;
    unsigned int flags = *(unsigned int *)(self_bytes + 0x98);
    int v0 = *(int *)(self_bytes + 0x54);
    int t2 = 0;
    int t3 = 0;

    if ((flags & 0x200) != 0) {
        func_00223F50();
        t2 = 2;
        t3 = 2;
    }

    flags = *(unsigned int *)(self_bytes + 0x98);
    if ((flags & 0x800) != 0) {
        v0 = 0xA3000;
        t2 = 0;
        t3 = 0;
    }

    if ((flags & 0x200) == 0) {
        return 0;
    }

    int a3 = *(int *)(self_bytes + 0x3C);
    int t0 = *(int *)(self_bytes + 0x38);
    int f1c = *(int *)(self_bytes + 0x1C);
    func_0021E370(0, v0, f1c, a3, t0, 0x50000, t2, t3);
    return 0;
}

int func_0021AE10(void *self) {
    char *self_bytes = (char *)self;
    unsigned int flags = *(unsigned int *)(self_bytes + 0x98);

    if ((flags & 0x200) == 0) {
        return 0;
    }

    func_00223F50();

    flags = *(unsigned int *)(self_bytes + 0x98);
    if ((flags & 0x200) == 0) {
        return 0;
    }

    int f1c = *(int *)(self_bytes + 0x1C);
    func_0021E370(0, 0, f1c, 640, 512, 0x50000, 2, 2);
    return 0;
}
}
#endif
