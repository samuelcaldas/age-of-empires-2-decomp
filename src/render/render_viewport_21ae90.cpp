#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x0021AE90 */
extern "C" {
void func_0021B130();

asm int func_0021AE90(void *self, const int *rect1, void *target, const int *rect3, int arg4, int arg5) {
    .word 0x27BDFFD0 /* addiu      $sp, $sp, -0x30 */
    .word 0x10C00007 /* beqz       $a2, .L0021AEB4 */
    .word 0x7FBF0000 /* sq        $ra, 0x0($sp) */
    .word 0x9CC20098 /* lwu        $v0, 0x98($a2) */
    .word 0x30424000 /* andi       $v0, $v0, 0x4000 */
    .word 0x10400003 /* beqz       $v0, .L0021AEB4 */
    .word 0x00000000 /* nop */
    .word 0x1000009A /* b          .L0021B118 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x10C0000F /* beqz       $a2, .L0021AEF4 */
    .word 0x00000000 /* nop */
    .word 0x8C8B001C /* lw         $t3, 0x1C($a0) */
    .word 0x8CCC001C /* lw         $t4, 0x1C($a2) */
    .word 0x116C0004 /* beq        $t3, $t4, .L0021AED8 */
    .word 0x24020014 /* addiu     $v0, $zero, 0x14 */
    .word 0x10000092 /* b          .L0021B118 */
    .word 0x24020001 /* addiu     $v0, $zero, 0x1 */
    .word 0x24020014 /* addiu      $v0, $zero, 0x14 */
    .word 0x51620004 /* beql       $t3, $v0, .L0021AEEC */
    .word 0x24020001 /* addiu     $v0, $zero, 0x1 */
    .word 0x15820004 /* bne        $t4, $v0, .L0021AEF4 */
    .word 0x00000000 /* nop */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x1000008B /* b          .L0021B11C */
    .word 0x7BBF0000 /* lq        $ra, 0x0($sp) */
    .word 0x8C820038 /* lw         $v0, 0x38($a0) */
    .word 0x10C00004 /* beqz       $a2, .L0021AF0C */
    .word 0x8C8C003C /* lw        $t4, 0x3C($a0) */
    .word 0x8CC3003C /* lw         $v1, 0x3C($a2) */
    .word 0x8CCA0038 /* lw         $t2, 0x38($a2) */
    .word 0x00000000 /* nop */
    .word 0x10A0000B /* beqz       $a1, .L0021AF3C */
    .word 0x00000000 /* nop */
    .word 0xC4A30000 /* lwc1       $f3, 0x0($a1) */
    .word 0xC4A20004 /* lwc1       $f2, 0x4($a1) */
    .word 0xC4A10008 /* lwc1       $f1, 0x8($a1) */
    .word 0xC4A0000C /* lwc1       $f0, 0xC($a1) */
    .word 0x27AB0020 /* addiu      $t3, $sp, 0x20 */
    .word 0xE5630000 /* swc1       $f3, 0x0($t3) */
    .word 0xE5620004 /* swc1       $f2, 0x4($t3) */
    .word 0xE5610008 /* swc1       $f1, 0x8($t3) */
    .word 0x10000005 /* b          .L0021AF4C */
    .word 0xE560000C /* swc1      $f0, 0xC($t3) */
    .word 0xAFA00024 /* sw         $zero, 0x24($sp) */
    .word 0xAFA00020 /* sw         $zero, 0x20($sp) */
    .word 0xAFAC0028 /* sw         $t4, 0x28($sp) */
    .word 0xAFA2002C /* sw         $v0, 0x2C($sp) */
    .word 0x10E0000B /* beqz       $a3, .L0021AF7C */
    .word 0x00000000 /* nop */
    .word 0xC4E30000 /* lwc1       $f3, 0x0($a3) */
    .word 0xC4E20004 /* lwc1       $f2, 0x4($a3) */
    .word 0xC4E10008 /* lwc1       $f1, 0x8($a3) */
    .word 0xC4E0000C /* lwc1       $f0, 0xC($a3) */
    .word 0x27A50010 /* addiu      $a1, $sp, 0x10 */
    .word 0xE4A30000 /* swc1       $f3, 0x0($a1) */
    .word 0xE4A20004 /* swc1       $f2, 0x4($a1) */
    .word 0xE4A10008 /* swc1       $f1, 0x8($a1) */
    .word 0x10000005 /* b          .L0021AF8C */
    .word 0xE4A0000C /* swc1      $f0, 0xC($a1) */
    .word 0xAFA00014 /* sw         $zero, 0x14($sp) */
    .word 0xAFA00010 /* sw         $zero, 0x10($sp) */
    .word 0xAFA30018 /* sw         $v1, 0x18($sp) */
    .word 0xAFAA001C /* sw         $t2, 0x1C($sp) */
    .word 0x8FA70020 /* lw         $a3, 0x20($sp) */
    .word 0x00EC282A /* slt        $a1, $a3, $t4 */
    .word 0x14A00004 /* bnez       $a1, .L0021AFA8 */
    .word 0x27AB0028 /* addiu     $t3, $sp, 0x28 */
    .word 0x1000005E /* b          .L0021B118 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x27AB0028 /* addiu      $t3, $sp, 0x28 */
    .word 0x8D650000 /* lw         $a1, 0x0($t3) */
    .word 0x04A10004 /* bgez       $a1, .L0021AFC0 */
    .word 0x27AD0024 /* addiu     $t5, $sp, 0x24 */
    .word 0x10000058 /* b          .L0021B118 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x27AD0024 /* addiu      $t5, $sp, 0x24 */
    .word 0x8DA50000 /* lw         $a1, 0x0($t5) */
    .word 0x00A2282A /* slt        $a1, $a1, $v0 */
    .word 0x14A00004 /* bnez       $a1, .L0021AFDC */
    .word 0x27AE002C /* addiu     $t6, $sp, 0x2C */
    .word 0x10000051 /* b          .L0021B118 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x27AE002C /* addiu      $t6, $sp, 0x2C */
    .word 0x8DC50000 /* lw         $a1, 0x0($t6) */
    .word 0x04A10003 /* bgez       $a1, .L0021AFF0 */
    .word 0x00000000 /* nop */
    .word 0x1000004B /* b          .L0021B118 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x10C00017 /* beqz       $a2, .L0021B050 */
    .word 0x00000000 /* nop */
    .word 0x8FA50010 /* lw         $a1, 0x10($sp) */
    .word 0x00A3282A /* slt        $a1, $a1, $v1 */
    .word 0x14A00003 /* bnez       $a1, .L0021B010 */
    .word 0x00000000 /* nop */
    .word 0x10000043 /* b          .L0021B118 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x8FA50018 /* lw         $a1, 0x18($sp) */
    .word 0x04A10003 /* bgez       $a1, .L0021B024 */
    .word 0x00000000 /* nop */
    .word 0x1000003E /* b          .L0021B118 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x8FA50014 /* lw         $a1, 0x14($sp) */
    .word 0x00AA282A /* slt        $a1, $a1, $t2 */
    .word 0x14A00003 /* bnez       $a1, .L0021B03C */
    .word 0x00000000 /* nop */
    .word 0x10000038 /* b          .L0021B118 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x8FA5001C /* lw         $a1, 0x1C($sp) */
    .word 0x04A10003 /* bgez       $a1, .L0021B050 */
    .word 0x00000000 /* nop */
    .word 0x10000033 /* b          .L0021B118 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x04E10002 /* bgez       $a3, .L0021B05C */
    .word 0x00000000 /* nop */
    .word 0xAFA00020 /* sw         $zero, 0x20($sp) */
    .word 0x8D650000 /* lw         $a1, 0x0($t3) */
    .word 0x0185082A /* slt        $at, $t4, $a1 */
    .word 0x10200002 /* beqz       $at, .L0021B070 */
    .word 0x00000000 /* nop */
    .word 0xAD6C0000 /* sw         $t4, 0x0($t3) */
    .word 0x8DA50000 /* lw         $a1, 0x0($t5) */
    .word 0x04A10002 /* bgez       $a1, .L0021B080 */
    .word 0x00000000 /* nop */
    .word 0xADA00000 /* sw         $zero, 0x0($t5) */
    .word 0x8DC50000 /* lw         $a1, 0x0($t6) */
    .word 0x0045082A /* slt        $at, $v0, $a1 */
    .word 0x10200002 /* beqz       $at, .L0021B094 */
    .word 0x00000000 /* nop */
    .word 0xADC20000 /* sw         $v0, 0x0($t6) */
    .word 0x10C00016 /* beqz       $a2, .L0021B0F0 */
    .word 0x00000000 /* nop */
    .word 0x8FA20010 /* lw         $v0, 0x10($sp) */
    .word 0x04410003 /* bgez       $v0, .L0021B0B0 */
    .word 0x27A50018 /* addiu     $a1, $sp, 0x18 */
    .word 0xAFA00010 /* sw         $zero, 0x10($sp) */
    .word 0x27A50018 /* addiu      $a1, $sp, 0x18 */
    .word 0x8CA20000 /* lw         $v0, 0x0($a1) */
    .word 0x0062082A /* slt        $at, $v1, $v0 */
    .word 0x50200003 /* beql       $at, $zero, .L0021B0C8 */
    .word 0x27A30014 /* addiu     $v1, $sp, 0x14 */
    .word 0xACA30000 /* sw         $v1, 0x0($a1) */
    .word 0x27A30014 /* addiu      $v1, $sp, 0x14 */
    .word 0x8C620000 /* lw         $v0, 0x0($v1) */
    .word 0x04430003 /* bgezl      $v0, .L0021B0DC */
    .word 0x27A3001C /* addiu     $v1, $sp, 0x1C */
    .word 0xAC600000 /* sw         $zero, 0x0($v1) */
    .word 0x27A3001C /* addiu      $v1, $sp, 0x1C */
    .word 0x8C620000 /* lw         $v0, 0x0($v1) */
    .word 0x0142082A /* slt        $at, $t2, $v0 */
    .word 0x10200002 /* beqz       $at, .L0021B0F0 */
    .word 0x00000000 /* nop */
    .word 0xAC6A0000 /* sw         $t2, 0x0($v1) */
    .word 0x8C83001C /* lw         $v1, 0x1C($a0) */
    .word 0x24020013 /* addiu      $v0, $zero, 0x13 */
    .word 0x10620004 /* beq        $v1, $v0, .L0021B10C */
    .word 0x27A50020 /* addiu     $a1, $sp, 0x20 */
    .word 0x10000005 /* b          .L0021B118 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x27A50020 /* addiu      $a1, $sp, 0x20 */
    jal func_0021B130
    .word 0x27A70010 /* addiu     $a3, $sp, 0x10 */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x7BBF0000 /* lq         $ra, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0030 /* addiu     $sp, $sp, 0x30 */
}
}

#else

extern "C" {
void func_0021B130(void *self, const int *rect1, void *target, const int *rect3);

static void init_rect(const int *src, int w, int h, int *dst) {
    if (src != 0) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        return;
    }
    dst[0] = 0;
    dst[1] = 0;
    dst[2] = w;
    dst[3] = h;
}

static bool check_overlap(const int *r, int w, int h) {
    if (r[0] >= w || r[2] < 0) {
        return false;
    }
    if (r[1] >= h || r[3] < 0) {
        return false;
    }
    return true;
}

static void clip_rect(int *r, int w, int h) {
    if (r[0] < 0) {
        r[0] = 0;
    }
    if (r[2] > w) {
        r[2] = w;
    }
    if (r[1] < 0) {
        r[1] = 0;
    }
    if (r[3] > h) {
        r[3] = h;
    }
}

int func_0021AE90(void *self, const int *rect1, void *target, const int *rect3, int arg4, int arg5) {
    char *self_bytes = (char *)self;
    char *target_bytes = (char *)target;

    if (target != 0) {
        unsigned int target_flags = *(unsigned int *)(target_bytes + 0x98);
        if ((target_flags & 0x4000) != 0) {
            return 0;
        }

        int self_1c = *(int *)(self_bytes + 0x1C);
        int target_1c = *(int *)(target_bytes + 0x1C);
        if (self_1c != target_1c) {
            return 1;
        }
        if (self_1c == 0x14 || target_1c == 0x14) {
            return 1;
        }
    }

    int self_h = *(int *)(self_bytes + 0x38);
    int self_w = *(int *)(self_bytes + 0x3C);
    int target_w = 0;
    int target_h = 0;
    if (target != 0) {
        target_w = *(int *)(target_bytes + 0x3C);
        target_h = *(int *)(target_bytes + 0x38);
    }

    int local_rect1[4];
    init_rect(rect1, self_w, self_h, local_rect1);

    int local_rect3[4];
    init_rect(rect3, target_w, target_h, local_rect3);

    if (!check_overlap(local_rect1, self_w, self_h)) {
        return 0;
    }

    if (target != 0 && !check_overlap(local_rect3, target_w, target_h)) {
        return 0;
    }

    clip_rect(local_rect1, self_w, self_h);
    if (target != 0) {
        clip_rect(local_rect3, target_w, target_h);
    }

    int self_1c = *(int *)(self_bytes + 0x1C);
    if (self_1c == 0x13) {
        func_0021B130(self, local_rect1, target, local_rect3);
    }

    return 0;
}
}
#endif
