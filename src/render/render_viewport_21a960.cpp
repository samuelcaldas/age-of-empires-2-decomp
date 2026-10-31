#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x0021A960 */
extern "C" {
void func_00221B60();
void func_0021C610();
void func_0021C4A0();
void func_0021D2C0();
void func_0021C410();
void func_0021A680();
void func_0021C1D0();
void func_0021CFB0();
void func_0021C710();
void func_0021BFD0();
void func_0021C0D0();

asm int func_0021A960(void *self, const int *rect1, void *arg2, const int *rect2, int flags_t0, int arg5) {
    .word 0x27BDFF80 /* addiu      $sp, $sp, -0x80 */
    .word 0x7FBF0050 /* sq         $ra, 0x50($sp) */
    .word 0x7FB30040 /* sq         $s3, 0x40($sp) */
    .word 0x7FB20030 /* sq         $s2, 0x30($sp) */
    .word 0x7FB10020 /* sq         $s1, 0x20($sp) */
    .word 0x7FB00010 /* sq         $s0, 0x10($sp) */
    .word 0x70809628 /* paddub     $s2, $a0, $zero */
    .word 0x10A0000B /* beqz       $a1, .L0021A9AC */
    .word 0x70C08E28 /* paddub    $s1, $a2, $zero */
    .word 0xC4A30000 /* lwc1       $f3, 0x0($a1) */
    .word 0xC4A20004 /* lwc1       $f2, 0x4($a1) */
    .word 0xC4A10008 /* lwc1       $f1, 0x8($a1) */
    .word 0xC4A0000C /* lwc1       $f0, 0xC($a1) */
    .word 0x27A20060 /* addiu      $v0, $sp, 0x60 */
    .word 0xE4430000 /* swc1       $f3, 0x0($v0) */
    .word 0xE4420004 /* swc1       $f2, 0x4($v0) */
    .word 0xE4410008 /* swc1       $f1, 0x8($v0) */
    .word 0x1000000A /* b          .L0021A9D0 */
    .word 0xE440000C /* swc1      $f0, 0xC($v0) */
    .word 0xC6430004 /* lwc1       $f3, 0x4($s2) */
    .word 0xC6420008 /* lwc1       $f2, 0x8($s2) */
    .word 0xC641000C /* lwc1       $f1, 0xC($s2) */
    .word 0xC6400010 /* lwc1       $f0, 0x10($s2) */
    .word 0x27A20060 /* addiu      $v0, $sp, 0x60 */
    .word 0xE4430000 /* swc1       $f3, 0x0($v0) */
    .word 0xE4420004 /* swc1       $f2, 0x4($v0) */
    .word 0xE4410008 /* swc1       $f1, 0x8($v0) */
    .word 0xE440000C /* swc1       $f0, 0xC($v0) */
    .word 0x0008103C /* dsll32     $v0, $t0, 0 */
    .word 0x0002103E /* dsrl32     $v0, $v0, 0 */
    .word 0x30420400 /* andi       $v0, $v0, 0x400 */
    .word 0x10400035 /* beqz       $v0, .L0021AAB4 */
    .word 0x00000000 /* nop */
    .word 0x8FA20068 /* lw         $v0, 0x68($sp) */
    .word 0x24420001 /* addiu      $v0, $v0, 0x1 */
    .word 0xAFA20068 /* sw         $v0, 0x68($sp) */
    .word 0x8FA2006C /* lw         $v0, 0x6C($sp) */
    .word 0x24420001 /* addiu      $v0, $v0, 0x1 */
    .word 0xAFA2006C /* sw         $v0, 0x6C($sp) */
    .word 0x9E420098 /* lwu        $v0, 0x98($s2) */
    .word 0x30420200 /* andi       $v0, $v0, 0x200 */
    .word 0x1440001B /* bnez       $v0, .L0021AA74 */
    .word 0x70002628 /* paddub    $a0, $zero, $zero */
    jal func_00221B60
    .word 0x24040013 /* addiu     $a0, $zero, 0x13 */
    .word 0x70408628 /* paddub     $s0, $v0, $zero */
    .word 0x24050003 /* addiu      $a1, $zero, 0x3 */
    jal func_0021C610
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    jal func_0021C4A0
    .word 0x70002E28 /* paddub    $a1, $zero, $zero */
    .word 0x24090001 /* addiu      $t1, $zero, 0x1 */
    .word 0x27A70060 /* addiu      $a3, $sp, 0x60 */
    .word 0x24084000 /* addiu      $t0, $zero, 0x4000 */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    .word 0x70003628 /* paddub     $a2, $zero, $zero */
    jal func_0021D2C0
    .word 0x71205628 /* paddub    $t2, $t1, $zero */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    jal func_0021C4A0
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x2405000D /* addiu      $a1, $zero, 0xD */
    jal func_0021C610
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x10000010 /* b          .L0021AAAC */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    jal func_0021C410
    .word 0x70002E28 /* paddub    $a1, $zero, $zero */
    .word 0x27A70060 /* addiu      $a3, $sp, 0x60 */
    .word 0x24084000 /* addiu      $t0, $zero, 0x4000 */
    .word 0x240A0001 /* addiu      $t2, $zero, 0x1 */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    .word 0x3C068000 /* lui        $a2, (0x80000000 >> 16) */
    jal func_0021D2C0
    .word 0x70004E28 /* paddub    $t1, $zero, $zero */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    jal func_0021C410
    .word 0x70002628 /* paddub    $a0, $zero, $zero */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x10000081 /* b          .L0021ACB4 */
    .word 0x7BBF0050 /* lq        $ra, 0x50($sp) */
    .word 0x10E0000B /* beqz       $a3, .L0021AAE4 */
    .word 0x00000000 /* nop */
    .word 0xC4E30000 /* lwc1       $f3, 0x0($a3) */
    .word 0xC4E20004 /* lwc1       $f2, 0x4($a3) */
    .word 0xC4E10008 /* lwc1       $f1, 0x8($a3) */
    .word 0xC4E0000C /* lwc1       $f0, 0xC($a3) */
    .word 0x27A20070 /* addiu      $v0, $sp, 0x70 */
    .word 0xE4430000 /* swc1       $f3, 0x0($v0) */
    .word 0xE4420004 /* swc1       $f2, 0x4($v0) */
    .word 0xE4410008 /* swc1       $f1, 0x8($v0) */
    .word 0x10000010 /* b          .L0021AB20 */
    .word 0xE440000C /* swc1      $f0, 0xC($v0) */
    .word 0x1220000C /* beqz       $s1, .L0021AB18 */
    .word 0x24020001 /* addiu     $v0, $zero, 0x1 */
    .word 0xC6230004 /* lwc1       $f3, 0x4($s1) */
    .word 0xC6220008 /* lwc1       $f2, 0x8($s1) */
    .word 0xC621000C /* lwc1       $f1, 0xC($s1) */
    .word 0xC6200010 /* lwc1       $f0, 0x10($s1) */
    .word 0x27A20070 /* addiu      $v0, $sp, 0x70 */
    .word 0xE4430000 /* swc1       $f3, 0x0($v0) */
    .word 0xE4420004 /* swc1       $f2, 0x4($v0) */
    .word 0xE4410008 /* swc1       $f1, 0x8($v0) */
    .word 0x10000004 /* b          .L0021AB20 */
    .word 0xE440000C /* swc1      $f0, 0xC($v0) */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x10000065 /* b          .L0021ACB0 */
    .word 0x00000000 /* nop */
    .word 0x1220000A /* beqz       $s1, .L0021AB4C */
    .word 0x00000000 /* nop */
    .word 0x8E220014 /* lw         $v0, 0x14($s1) */
    .word 0x14400007 /* bnez       $v0, .L0021AB4C */
    .word 0x00000000 /* nop */
    .word 0x8E220084 /* lw         $v0, 0x84($s1) */
    .word 0x2C410009 /* sltiu      $at, $v0, 0x9 */
    .word 0x10200003 /* beqz       $at, .L0021AB4C */
    .word 0x00000000 /* nop */
    .word 0x1000005A /* b          .L0021ACB0 */
    .word 0x24020001 /* addiu     $v0, $zero, 0x1 */
    .word 0x8E23001C /* lw         $v1, 0x1C($s1) */
    .word 0x24020002 /* addiu      $v0, $zero, 0x2 */
    .word 0x10620005 /* beq        $v1, $v0, .L0021AB6C */
    .word 0x24100001 /* addiu     $s0, $zero, 0x1 */
    .word 0x50600004 /* beql       $v1, $zero, .L0021AB70 */
    .word 0x70008628 /* paddub    $s0, $zero, $zero */
    .word 0x15000003 /* bnez       $t0, .L0021AB74 */
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x70008628 /* paddub     $s0, $zero, $zero */
    .word 0x72202628 /* paddub     $a0, $s1, $zero */
    jal func_0021A680
    .word 0x00000000 /* nop */
    .word 0x9E420098 /* lwu        $v0, 0x98($s2) */
    .word 0x30420200 /* andi       $v0, $v0, 0x200 */
    .word 0x14400018 /* bnez       $v0, .L0021ABE8 */
    .word 0x24020001 /* addiu     $v0, $zero, 0x1 */
    jal func_00221B60
    .word 0x2404000F /* addiu     $a0, $zero, 0xF */
    .word 0x24060001 /* addiu      $a2, $zero, 0x1 */
    .word 0x70409E28 /* paddub     $s3, $v0, $zero */
    .word 0x24090080 /* addiu      $t1, $zero, 0x80 */
    .word 0x72602628 /* paddub     $a0, $s3, $zero */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    .word 0x70003E28 /* paddub     $a3, $zero, $zero */
    jal func_0021C1D0
    .word 0x70C04628 /* paddub    $t0, $a2, $zero */
    .word 0x240B0001 /* addiu      $t3, $zero, 0x1 */
    .word 0xFFAB0000 /* sd         $t3, 0x0($sp) */
    .word 0x8E470028 /* lw         $a3, 0x28($s2) */
    .word 0xDE250020 /* ld         $a1, 0x20($s1) */
    .word 0x27A80060 /* addiu      $t0, $sp, 0x60 */
    .word 0x27A90070 /* addiu      $t1, $sp, 0x70 */
    .word 0x240A4000 /* addiu      $t2, $zero, 0x4000 */
    .word 0x72602628 /* paddub     $a0, $s3, $zero */
    jal func_0021CFB0
    .word 0x72003628 /* paddub    $a2, $s0, $zero */
    .word 0x10000034 /* b          .L0021ACB0 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x0002183C /* dsll32     $v1, $v0, 0 */
    .word 0x24020061 /* addiu      $v0, $zero, 0x61 */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    jal func_0021C710
    .word 0x00432825 /* or        $a1, $v0, $v1 */
    .word 0x8FA50078 /* lw         $a1, 0x78($sp) */
    .word 0x8FA2007C /* lw         $v0, 0x7C($sp) */
    .word 0x8FA60070 /* lw         $a2, 0x70($sp) */
    .word 0x8FA30074 /* lw         $v1, 0x74($sp) */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    .word 0x24A5FFFF /* addiu      $a1, $a1, -0x1 */
    .word 0x0005283C /* dsll32     $a1, $a1, 0 */
    .word 0x2442FFFF /* addiu      $v0, $v0, -0x1 */
    .word 0x00063138 /* dsll       $a2, $a2, 4 */
    .word 0x0005283F /* dsra32     $a1, $a1, 0 */
    .word 0x0002103C /* dsll32     $v0, $v0, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x34C6000A /* ori        $a2, $a2, 0xA */
    .word 0x00052BB8 /* dsll       $a1, $a1, 14 */
    .word 0x00C52825 /* or         $a1, $a2, $a1 */
    .word 0x00031E38 /* dsll       $v1, $v1, 24 */
    .word 0x00651825 /* or         $v1, $v1, $a1 */
    .word 0x000210BC /* dsll32     $v0, $v0, 2 */
    jal func_0021BFD0
    .word 0x00432825 /* or        $a1, $v0, $v1 */
    .word 0x24060001 /* addiu      $a2, $zero, 0x1 */
    .word 0x24090080 /* addiu      $t1, $zero, 0x80 */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    .word 0x70003E28 /* paddub     $a3, $zero, $zero */
    jal func_0021C0D0
    .word 0x70C04628 /* paddub    $t0, $a2, $zero */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0xFFA20000 /* sd         $v0, 0x0($sp) */
    .word 0x8E470028 /* lw         $a3, 0x28($s2) */
    .word 0xDE250020 /* ld         $a1, 0x20($s1) */
    .word 0x27A80060 /* addiu      $t0, $sp, 0x60 */
    .word 0x27A90070 /* addiu      $t1, $sp, 0x70 */
    .word 0x240A4000 /* addiu      $t2, $zero, 0x4000 */
    .word 0x72003628 /* paddub     $a2, $s0, $zero */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    jal func_0021CFB0
    .word 0x70005E28 /* paddub    $t3, $zero, $zero */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    jal func_0021C710
    .word 0x70002628 /* paddub    $a0, $zero, $zero */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    jal func_0021BFD0
    .word 0x70002E28 /* paddub    $a1, $zero, $zero */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x7BBF0050 /* lq         $ra, 0x50($sp) */
    .word 0x7BB30040 /* lq         $s3, 0x40($sp) */
    .word 0x7BB20030 /* lq         $s2, 0x30($sp) */
    .word 0x7BB10020 /* lq         $s1, 0x20($sp) */
    .word 0x7BB00010 /* lq         $s0, 0x10($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0080 /* addiu     $sp, $sp, 0x80 */
}
}

#else

extern "C" {
void *func_00221B60(int type);
void func_0021C610(void *ctx, int mode);
void func_0021C4A0(void *ctx, int mode);
void func_0021D2C0(void *ctx, int a1, unsigned long long a2, const int *rect, int a4, int a5);
void func_0021C410(void *ctx, int mode);
void func_0021A680(void *arg);
void func_0021C1D0(void *ctx, int a1, int a2, int a3, int a4, int a5);
void func_0021CFB0(void *ctx, unsigned long long val_20, int s0, int self_28, const int *rect1, const int *rect2, int a6, int a7);
void func_0021C710(void *ctx, unsigned long long val);
void func_0021BFD0(void *ctx, unsigned long long val);
void func_0021C0D0(void *ctx, int a1, int a2, int a3, int a4, int a5);

static void setup_rect1(void *self, const int *rect1, int *local_rect1) {
    if (rect1 != 0) {
        local_rect1[0] = rect1[0];
        local_rect1[1] = rect1[1];
        local_rect1[2] = rect1[2];
        local_rect1[3] = rect1[3];
        return;
    }
    const int *self_rect = (const int *)((char *)self + 4);
    local_rect1[0] = self_rect[0];
    local_rect1[1] = self_rect[1];
    local_rect1[2] = self_rect[2];
    local_rect1[3] = self_rect[3];
}

static int render_scissor_rect(void *self, const int *local_rect1) {
    char *self_bytes = (char *)self;
    unsigned int flags = *(unsigned int *)(self_bytes + 0x98);

    if ((flags & 0x200) == 0) {
        void *ctx = func_00221B60(0x13);
        func_0021C610(ctx, 3);
        func_0021C4A0(ctx, 0);
        func_0021D2C0(ctx, 0, 0, local_rect1, 0x4000, 1);
        func_0021C4A0(ctx, 1);
        func_0021C610(ctx, 0xD);
        return 0;
    }

    func_0021C410(0, 0);
    func_0021D2C0(0, 0, 0x80000000ULL, local_rect1, 0x4000, 1);
    func_0021C410(0, 1);
    return 0;
}

static void render_context_path(void *self, void *arg2, int s0, const int *local_rect1, const int *local_rect2) {
    void *ctx = func_00221B60(0xF);
    func_0021C1D0(ctx, 0, 1, 0, 1, 0x80);

    unsigned long long val_20 = *(unsigned long long *)((char *)arg2 + 0x20);
    int self_28 = *(int *)((char *)self + 0x28);
    func_0021CFB0(ctx, val_20, s0, self_28, local_rect1, local_rect2, 0x4000, 1);
}

static void render_direct_path(void *self, void *arg2, int s0, const int *local_rect1, const int *local_rect2) {
    unsigned long long v1_or = (1ULL << 32) | 0x61ULL;
    func_0021C710(0, v1_or);

    int r2 = local_rect2[2] - 1;
    int r3 = local_rect2[3] - 1;
    int r0 = local_rect2[0];
    int r1 = local_rect2[1];

    unsigned long long packed_coords = 0;
    packed_coords |= (unsigned long long)(r0 << 4) | 0xAULL;
    packed_coords |= ((unsigned long long)(r2)) << 14;
    packed_coords |= ((unsigned long long)(r1)) << 24;
    packed_coords |= ((unsigned long long)(r3)) << 34;

    func_0021BFD0(0, packed_coords);
    func_0021C0D0(0, 0, 1, 0, 1, 0x80);

    unsigned long long val_20 = *(unsigned long long *)((char *)arg2 + 0x20);
    int self_28 = *(int *)((char *)self + 0x28);
    func_0021CFB0(0, val_20, s0, self_28, local_rect1, local_rect2, 0x4000, 0);
    func_0021C710(0, 1);
    func_0021BFD0(0, 0);
}

int func_0021A960(void *self, const int *rect1, void *arg2, const int *rect2, int flags_t0, int arg5) {
    int local_rect1[4];
    setup_rect1(self, rect1, local_rect1);

    if ((flags_t0 & 0x400) != 0) {
        local_rect1[2]++;
        local_rect1[3]++;
        return render_scissor_rect(self, local_rect1);
    }

    if (rect2 == 0 && arg2 == 0) {
        return 1;
    }

    int local_rect2[4];
    if (rect2 != 0) {
        local_rect2[0] = rect2[0];
        local_rect2[1] = rect2[1];
        local_rect2[2] = rect2[2];
        local_rect2[3] = rect2[3];
    }
    if (rect2 == 0) {
        const int *arg2_rect = (const int *)((char *)arg2 + 4);
        local_rect2[0] = arg2_rect[0];
        local_rect2[1] = arg2_rect[1];
        local_rect2[2] = arg2_rect[2];
        local_rect2[3] = arg2_rect[3];
    }

    if (arg2 != 0) {
        void *field14 = *(void **)((char *)arg2 + 0x14);
        unsigned int field84 = *(unsigned int *)((char *)arg2 + 0x84);
        if (field14 == 0 && field84 < 9) {
            return 1;
        }
    }

    int s0 = 0;
    if (arg2 != 0) {
        int mode = *(int *)((char *)arg2 + 0x1C);
        if (mode == 2) {
            s0 = 1;
        }
        if (mode == 0 || flags_t0 == 0) {
            s0 = 0;
        }
        func_0021A680(arg2);
    }

    char *self_bytes = (char *)self;
    unsigned int flags = *(unsigned int *)(self_bytes + 0x98);

    if ((flags & 0x200) == 0) {
        render_context_path(self, arg2, s0, local_rect1, local_rect2);
        return 0;
    }

    render_direct_path(self, arg2, s0, local_rect1, local_rect2);
    return 0;
}
}
#endif
