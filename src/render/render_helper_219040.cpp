#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x00219040 */
extern "C" {
void func_00219C90();
void func_225200();
void func_0011ACD0();
void func_225DB0();
void func_117CAC();
void func_2252E0();

asm void func_00219040(void *self, void *arg1, short arg2, short arg3, void *loc100, void *arg5, int arg6) {

    .word 0x27BDFE60 /* addiu      $sp, $sp, -0x1A0 */
    .word 0x7FBF0080 /* sq         $ra, 0x80($sp) */
    .word 0x7FB70070 /* sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x7080B628 /* paddub     $s6, $a0, $zero */
    .word 0x70A0AE28 /* paddub     $s5, $a1, $zero */
    .word 0x70C0A628 /* paddub     $s4, $a2, $zero */
    .word 0x71009E28 /* paddub     $s3, $t0, $zero */
    .word 0x11400003 /* beqz       $t2, .L00219088 */
    .word 0x7120BE28 /* paddub    $s7, $t1, $zero */
    .word 0x10000003 /* b          .L00219090 */
    .word 0x8ED1014C /* lw        $s1, 0x14C($s6) */
    .word 0x8ED10148 /* lw         $s1, 0x148($s6) */
    .word 0x00000000 /* nop */
    .word 0x11400006 /* beqz       $t2, .L002190AC */
    .word 0x00072C3C /* dsll32    $a1, $a3, 16 */
    .word 0x00052C3F /* dsra32     $a1, $a1, 16 */
    jal func_00219C90
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x10000008 /* b          .L002190C8 */
    .word 0x70409628 /* paddub    $s2, $v0, $zero */
    .word 0x8ED90000 /* lw         $t9, 0x0($s6) */
    .word 0x00072C3C /* dsll32     $a1, $a3, 16 */
    .word 0x00052C3F /* dsra32     $a1, $a1, 16 */
    .word 0x8F390128 /* lw         $t9, 0x128($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x70409628 /* paddub     $s2, $v0, $zero */
    .word 0x12400035 /* beqz       $s2, .L002191A0 */
    .word 0x00000000 /* nop */
    .word 0x86C2012A /* lh         $v0, 0x12A($s6) */
    .word 0x14400003 /* bnez       $v0, .L002190E4 */
    .word 0x72402628 /* paddub    $a0, $s2, $zero */
    .word 0x10000024 /* b          .L00219170 */
    .word 0x70008628 /* paddub    $s0, $zero, $zero */
    jal func_225200
    .word 0x00000000 /* nop */
    .word 0x00021C3C /* dsll32     $v1, $v0, 16 */
    .word 0x86C2012A /* lh         $v0, 0x12A($s6) */
    .word 0x00031C3F /* dsra32     $v1, $v1, 16 */
    .word 0x0062082A /* slt        $at, $v1, $v0 */
    .word 0x1020000B /* beqz       $at, .L0021912C */
    .word 0x27A40090 /* addiu     $a0, $sp, 0x90 */
    jal func_0011ACD0
    .word 0x72402628 /* paddub    $a0, $s2, $zero */
    .word 0x0002343C /* dsll32     $a2, $v0, 16 */
    .word 0x27A70198 /* addiu      $a3, $sp, 0x198 */
    .word 0x0006343F /* dsra32     $a2, $a2, 16 */
    .word 0x72A02628 /* paddub     $a0, $s5, $zero */
    jal func_225DB0
    .word 0x72402E28 /* paddub    $a1, $s2, $zero */
    .word 0x10000011 /* b          .L0021916C */
    .word 0x8FB00198 /* lw        $s0, 0x198($sp) */
    .word 0x24060100 /* addiu      $a2, $zero, 0x100 */
    jal func_117CAC
    .word 0x70002E28 /* paddub    $a1, $zero, $zero */
    .word 0x86C6012A /* lh         $a2, 0x12A($s6) */
    .word 0x27A40090 /* addiu      $a0, $sp, 0x90 */
    jal func_2252E0
    .word 0x72402E28 /* paddub    $a1, $s2, $zero */
    jal func_0011ACD0
    .word 0x27A40090 /* addiu     $a0, $sp, 0x90 */
    .word 0x0002343C /* dsll32     $a2, $v0, 16 */
    .word 0x27A70198 /* addiu      $a3, $sp, 0x198 */
    .word 0x0006343F /* dsra32     $a2, $a2, 16 */
    .word 0x72A02628 /* paddub     $a0, $s5, $zero */
    jal func_225DB0
    .word 0x72402E28 /* paddub    $a1, $s2, $zero */
    .word 0x8FB00198 /* lw         $s0, 0x198($sp) */
    .word 0x00000000 /* nop */
    jal func_225200
    .word 0x72402628 /* paddub    $a0, $s2, $zero */
    jal func_0011ACD0
    .word 0x72402628 /* paddub    $a0, $s2, $zero */
    .word 0x0002343C /* dsll32     $a2, $v0, 16 */
    .word 0x27A70198 /* addiu      $a3, $sp, 0x198 */
    .word 0x72A02628 /* paddub     $a0, $s5, $zero */
    .word 0x72402E28 /* paddub     $a1, $s2, $zero */
    jal func_225DB0
    .word 0x0006343F /* dsra32    $a2, $a2, 16 */
    .word 0x10000004 /* b          .L002191AC */
    .word 0x00000000 /* nop */
    .word 0xAFA00198 /* sw         $zero, 0x198($sp) */
    .word 0xAFA0019C /* sw         $zero, 0x19C($sp) */
    .word 0x70008628 /* paddub     $s0, $zero, $zero */
    .word 0x12200006 /* beqz       $s1, .L002191C8 */
    .word 0x24030005 /* addiu     $v1, $zero, 0x5 */
    .word 0x24030006 /* addiu      $v1, $zero, 0x6 */
    .word 0x12230002 /* beq        $s1, $v1, .L002191C4 */
    .word 0x00000000 /* nop */
    .word 0x26100005 /* addiu      $s0, $s0, 0x5 */
    .word 0x24030005 /* addiu      $v1, $zero, 0x5 */
    .word 0x1223001C /* beq        $s1, $v1, .L0021923C */
    .word 0x24030002 /* addiu     $v1, $zero, 0x2 */
    .word 0x12230011 /* beq        $s1, $v1, .L00219218 */
    .word 0x24030001 /* addiu     $v1, $zero, 0x1 */
    .word 0x1223000B /* beq        $s1, $v1, .L00219208 */
    .word 0x24030006 /* addiu     $v1, $zero, 0x6 */
    .word 0x12230001 /* beq        $s1, $v1, .L002191E8 */
    .word 0x00000000 /* nop */
    .word 0x8EC50014 /* lw         $a1, 0x14($s6) */
    .word 0x8EC4000C /* lw         $a0, 0xC($s6) */
    .word 0x8FA30198 /* lw         $v1, 0x198($sp) */
    .word 0x00052843 /* sra        $a1, $a1, 1 */
    .word 0x00852021 /* addu       $a0, $a0, $a1 */
    .word 0x00031843 /* sra        $v1, $v1, 1 */
    .word 0x10000018 /* b          .L00219264 */
    .word 0x00831823 /* subu      $v1, $a0, $v1 */
    .word 0x8EC4000C /* lw         $a0, 0xC($s6) */
    .word 0x8EC301BC /* lw         $v1, 0x1BC($s6) */
    .word 0x10000014 /* b          .L00219264 */
    .word 0x00831821 /* addu      $v1, $a0, $v1 */
    .word 0x8EC6000C /* lw         $a2, 0xC($s6) */
    .word 0x8EC50014 /* lw         $a1, 0x14($s6) */
    .word 0x8FA40198 /* lw         $a0, 0x198($sp) */
    .word 0x8EC301BC /* lw         $v1, 0x1BC($s6) */
    .word 0x00C52821 /* addu       $a1, $a2, $a1 */
    .word 0x24A5FFF9 /* addiu      $a1, $a1, -0x7 */
    .word 0x00A42023 /* subu       $a0, $a1, $a0 */
    .word 0x1000000B /* b          .L00219264 */
    .word 0x00831823 /* subu      $v1, $a0, $v1 */
    .word 0x8EC5000C /* lw         $a1, 0xC($s6) */
    .word 0x8EC301BC /* lw         $v1, 0x1BC($s6) */
    .word 0x8EC60014 /* lw         $a2, 0x14($s6) */
    .word 0x26040001 /* addiu      $a0, $s0, 0x1 */
    .word 0x0086202A /* slt        $a0, $a0, $a2 */
    .word 0x14800004 /* bnez       $a0, .L00219264 */
    .word 0x00A31821 /* addu      $v1, $a1, $v1 */
    .word 0x02062023 /* subu       $a0, $s0, $a2 */
    .word 0x24840002 /* addiu      $a0, $a0, 0x2 */
    .word 0x00641823 /* subu       $v1, $v1, $a0 */
    .word 0x8EC401C0 /* lw         $a0, 0x1C0($s6) */
    .word 0x14800003 /* bnez       $a0, .L00219278 */
    .word 0x00042840 /* sll       $a1, $a0, 1 */
    .word 0x10000004 /* b          .L00219284 */
    .word 0x8EC4017C /* lw        $a0, 0x17C($s6) */
    .word 0x8EC4017C /* lw         $a0, 0x17C($s6) */
    .word 0x00852021 /* addu       $a0, $a0, $a1 */
    .word 0x2484FFFF /* addiu      $a0, $a0, -0x1 */
    .word 0x8EC60144 /* lw         $a2, 0x144($s6) */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x10C50017 /* beq        $a2, $a1, .L002192EC */
    .word 0x24050003 /* addiu     $a1, $zero, 0x3 */
    .word 0x10C5000E /* beq        $a2, $a1, .L002192D0 */
    .word 0x00142C3C /* dsll32    $a1, $s4, 16 */
    .word 0x86C60120 /* lh         $a2, 0x120($s6) */
    .word 0x8EC80018 /* lw         $t0, 0x18($s6) */
    .word 0x00142C3C /* dsll32     $a1, $s4, 16 */
    .word 0x8EC70010 /* lw         $a3, 0x10($s6) */
    .word 0x00052C3F /* dsra32     $a1, $a1, 16 */
    .word 0x70852818 /* mult1      $a1, $a0, $a1 */
    .word 0x00862018 /* mult       $a0, $a0, $a2 */
    .word 0x00084043 /* sra        $t0, $t0, 1 */
    .word 0x00E83821 /* addu       $a3, $a3, $t0 */
    .word 0x00042043 /* sra        $a0, $a0, 1 */
    .word 0x00E42023 /* subu       $a0, $a3, $a0 */
    .word 0x10000014 /* b          .L0021931C */
    .word 0x00852821 /* addu      $a1, $a0, $a1 */
    .word 0x00052C3F /* dsra32     $a1, $a1, 16 */
    .word 0x00852018 /* mult       $a0, $a0, $a1 */
    .word 0x8EC60010 /* lw         $a2, 0x10($s6) */
    .word 0x8EC501BC /* lw         $a1, 0x1BC($s6) */
    .word 0x00C52821 /* addu       $a1, $a2, $a1 */
    .word 0x1000000D /* b          .L0021931C */
    .word 0x00A42821 /* addu      $a1, $a1, $a0 */
    .word 0x86C60120 /* lh         $a2, 0x120($s6) */
    .word 0x00142C3C /* dsll32     $a1, $s4, 16 */
    .word 0x00052C3F /* dsra32     $a1, $a1, 16 */
    .word 0x8EC90010 /* lw         $t1, 0x10($s6) */
    .word 0x8EC80018 /* lw         $t0, 0x18($s6) */
    .word 0x8EC701BC /* lw         $a3, 0x1BC($s6) */
    .word 0x00C52823 /* subu       $a1, $a2, $a1 */
    .word 0x00852018 /* mult       $a0, $a0, $a1 */
    .word 0x01284021 /* addu       $t0, $t1, $t0 */
    .word 0x2505FFFF /* addiu      $a1, $t0, -0x1 */
    .word 0x00A72823 /* subu       $a1, $a1, $a3 */
    .word 0x00A42823 /* subu       $a1, $a1, $a0 */
    .word 0xAE630000 /* sw         $v1, 0x0($s3) */
    .word 0xAE650004 /* sw         $a1, 0x4($s3) */
    .word 0x8FA40198 /* lw         $a0, 0x198($sp) */
    .word 0x00641821 /* addu       $v1, $v1, $a0 */
    .word 0x2463FFFF /* addiu      $v1, $v1, -0x1 */
    .word 0xAE630008 /* sw         $v1, 0x8($s3) */
    .word 0x8EC3017C /* lw         $v1, 0x17C($s6) */
    .word 0x00A31821 /* addu       $v1, $a1, $v1 */
    .word 0x12E00002 /* beqz       $s7, .L00219348 */
    .word 0xAE63000C /* sw        $v1, 0xC($s3) */
    .word 0xAEF00000 /* sw         $s0, 0x0($s7) */
    .word 0x7BBF0080 /* lq         $ra, 0x80($sp) */
    .word 0x7BB70070 /* lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD01A0 /* addiu     $sp, $sp, 0x1A0 */
}
}


#else

/* 0x00219040 */
extern "C" {
#define func_225DB0 func_00225DB0
void *memset(void *dest, int val, unsigned int size);
void *func_00219C90(void *self, int arg1);
int func_00225200(void *arg0);
int func_0011ACD0(void *arg0);
int func_002252E0(void *buf, void *s2, short arg2);
int func_00225DB0(void *arg0, void *arg1, short arg2, void *loc198);

typedef void *(*VirtualFn128)(void *, int);

void func_00219040(void *self, void *arg1, short arg2, short arg3, void *loc100, void *arg5, int arg6) {
    char *s6 = (char *)self;
    int s1 = (arg6 != 0) ? *(int *)(s6 + 0x14C) : *(int *)(s6 + 0x148);

    void *s2;
    if (arg6 != 0) {
        s2 = func_00219C90(self, (int)arg3);
    } else {
        void **vtable = *(void ***)self;
        VirtualFn128 fn128 = (VirtualFn128)*(void **)((char *)vtable + 0x128);
        s2 = fn128(self, (int)arg3);
    }

    int loc198[2] = {0, 0};
    int s0 = 0;

    if (s2 != 0) {
        short field12A = *(short *)(s6 + 0x12A);
        if (field12A == 0) {
            func_00225200(s2);
            int v0 = func_0011ACD0(s2);
            func_225DB0(arg1, s2, (short)v0, loc198);
        } else {
            int count = func_00225200(s2);
            if ((short)count < field12A) {
                int v0 = func_0011ACD0(s2);
                func_225DB0(arg1, s2, (short)v0, loc198);
                s0 = loc198[0];
            } else {
                char buf90[256];
                memset(buf90, 0, 256);
                func_002252E0(buf90, s2, field12A);
                int v0 = func_0011ACD0(buf90);
                func_225DB0(arg1, s2, (short)v0, loc198);
                s0 = loc198[0];
            }
        }
    }

    if (s1 != 0 && s1 != 6) {
        s0 += 5;
    }

    int v1;
    if (s1 == 1) {
        v1 = *(int *)(s6 + 0xC) + *(int *)(s6 + 0x1BC);
    } else if (s1 == 2) {
        int a1 = *(int *)(s6 + 0xC) + *(int *)(s6 + 0x14) - 7 - loc198[0];
        v1 = a1 - *(int *)(s6 + 0x1BC);
    } else if (s1 == 5) {
        v1 = *(int *)(s6 + 0xC) + *(int *)(s6 + 0x1BC);
        int f14 = *(int *)(s6 + 0x14);
        if (s0 + 1 >= f14) {
            v1 -= (s0 - f14 + 2);
        }
    } else {
        int f14_half = *(int *)(s6 + 0x14) >> 1;
        int loc198_half = loc198[0] >> 1;
        v1 = (*(int *)(s6 + 0xC) + f14_half) - loc198_half;
    }

    int a0_step = *(int *)(s6 + 0x17C);
    int f1c0 = *(int *)(s6 + 0x1C0);
    if (f1c0 != 0) {
        a0_step += 2 * f1c0 - 1;
    }

    int f144 = *(int *)(s6 + 0x144);
    int a1_pos;
    if (f144 == 4) {
        short f120 = *(short *)(s6 + 0x120);
        int diff = (int)f120 - (int)arg2;
        int mult = a0_step * diff;
        int sum = *(int *)(s6 + 0x10) + *(int *)(s6 + 0x18) - 1;
        a1_pos = sum - *(int *)(s6 + 0x1BC) - mult;
    } else if (f144 == 3) {
        int base = *(int *)(s6 + 0x10) + *(int *)(s6 + 0x1BC);
        a1_pos = base + a0_step * (int)arg2;
    } else {
        short f120 = *(short *)(s6 + 0x120);
        int term1 = *(int *)(s6 + 0x10) + (*(int *)(s6 + 0x18) >> 1);
        int term2 = (a0_step * (int)f120) >> 1;
        a1_pos = term1 - term2 + a0_step * (int)arg2;
    }

    int *out_rect = (int *)loc100;
    out_rect[0] = v1;
    out_rect[1] = a1_pos;
    out_rect[2] = v1 + loc198[0] - 1;
    out_rect[3] = a1_pos + *(int *)(s6 + 0x17C);

    if (arg5 != 0) {
        *(int *)arg5 = s0;
    }
}
}


#endif
