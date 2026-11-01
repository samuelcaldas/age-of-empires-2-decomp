#pragma once
#pragma exceptions off
#include "unit_action_build_7b700.h"

extern "C" {
    extern void *D_004E3180;
    void *func_0027B6D0(void *self);
    void *func_117CAC(void *dest, int val, unsigned int size);
    void func_27B950(void *self, void *entry);

#if defined(__mips__)
asm void func_0027B700(void *self, int type, int param, float val1, float val2) {
    .word 0x27BDFFA0 /* 0027B700 addiu $sp, $sp, -0x60 */
    .word 0x7FBF0050 /* 0027B704 sq $ra, 0x50($sp) */
    .word 0x7FB30040 /* 0027B708 sq $s3, 0x40($sp) */
    .word 0x7FB20030 /* 0027B70C sq $s2, 0x30($sp) */
    .word 0x7FB10020 /* 0027B710 sq $s1, 0x20($sp) */
    .word 0x7FB00010 /* 0027B714 sq $s0, 0x10($sp) */
    .word 0xE7B50004 /* 0027B718 swc1 $f21, 0x4($sp) */
    .word 0xE7B40000 /* 0027B71C swc1 $f20, 0x0($sp) */
    .word 0x8C8305DC /* 0027B720 lw $v1, 0x5DC($a0) */
    .word 0x70A09628 /* 0027B724 paddub $s2, $a1, $zero */
    .word 0x46006546 /* 0027B728 mov.s $f21, $f12 */
    .word 0x46006D06 /* 0027B72C mov.s $f20, $f13 */
    .word 0x70C08E28 /* 0027B730 paddub $s1, $a2, $zero */
    blez $v1, lbl_27B7EC
    .word 0x70809E28 /* 0027B738 paddub $s3, $a0, $zero */
    jal func_0027B6D0
    .word 0x00000000 /* 0027B740 nop */
    .word 0x70408628 /* 0027B744 paddub $s0, $v0, $zero */
    beqz $s0, lbl_27B7EC
    .word 0x00000000 /* 0027B74C nop */
    .word 0x2406001C /* 0027B750 addiu $a2, $zero, 0x1C */
    .word 0x72002628 /* 0027B754 paddub $a0, $s0, $zero */
    jal func_117CAC
    .word 0x70002E28 /* 0027B75C paddub $a1, $zero, $zero */
    .word 0x8E6301E0 /* 0027B760 lw $v1, 0x1E0($s3) */
    .word 0xAE030018 /* 0027B764 sw $v1, 0x18($s0) */
    .word 0x8E6305DC /* 0027B768 lw $v1, 0x5DC($s3) */
    .word 0xAE030004 /* 0027B76C sw $v1, 0x4($s0) */
    .word 0x8F8389C0 /* 0027B770 lw $v1, -0x7640($gp) */
    .word 0x8C630404 /* 0027B774 lw $v1, 0x404($v1) */
    .word 0x8C630018 /* 0027B778 lw $v1, 0x18($v1) */
    .word 0xAE030008 /* 0027B77C sw $v1, 0x8($s0) */
    .word 0xA2120000 /* 0027B780 sb $s2, 0x0($s0) */
    .word 0xE615000C /* 0027B784 swc1 $f21, 0xC($s0) */
    bltz $s1, lbl_27B79C
    .word 0xE6140010 /* 0027B78C swc1 $f20, 0x10($s0) */
    .word 0x44910000 /* 0027B790 mtc1 $s1, $f0 */
    b lbl_27B7B8
    .word 0x46800020 /* 0027B798 cvt.s.w $f0, $f0 */
lbl_27B79C:
    .word 0x00112042 /* 0027B79C srl $a0, $s1, 1 */
    .word 0x32230001 /* 0027B7A0 andi $v1, $s1, 0x1 */
    .word 0x00832025 /* 0027B7A4 or $a0, $a0, $v1 */
    .word 0x44840000 /* 0027B7A8 mtc1 $a0, $f0 */
    .word 0x00000000 /* 0027B7AC nop */
    .word 0x46800020 /* 0027B7B0 cvt.s.w $f0, $f0 */
    .word 0x46000000 /* 0027B7B4 add.s $f0, $f0, $f0 */
lbl_27B7B8:
    .word 0x2403000C /* 0027B7B8 addiu $v1, $zero, 0xC */
    .word 0xE6000014 /* 0027B7BC swc1 $f0, 0x14($s0) */
    .word 0x324400FF /* 0027B7C0 andi $a0, $s2, 0xFF */
    beq $a0, $v1, lbl_27B7EC
    .word 0xAE7001E0 /* 0027B7C8 sw $s0, 0x1E0($s3) */
    .word 0x2403000B /* 0027B7CC addiu $v1, $zero, 0xB */
    beq $a0, $v1, lbl_27B7E4
    .word 0x72602628 /* 0027B7D4 paddub $a0, $s3, $zero */
    .word 0x10000005 /* 0027B7D8 b 0x0027B7F0 */
    .word 0x7BBF0050 /* 0027B7DC lq $ra, 0x50($sp) */
    .word 0x72602628 /* 0027B7E0 paddub $a0, $s3, $zero */
lbl_27B7E4:
    jal func_27B950
    .word 0x72002E28 /* 0027B7E8 paddub $a1, $s0, $zero */
lbl_27B7EC:
    .word 0x7BBF0050 /* 0027B7EC lq $ra, 0x50($sp) */
lbl_27B7F0:
    .word 0x7BB30040 /* 0027B7F0 lq $s3, 0x40($sp) */
    .word 0x7BB20030 /* 0027B7F4 lq $s2, 0x30($sp) */
    .word 0x7BB10020 /* 0027B7F8 lq $s1, 0x20($sp) */
    .word 0x7BB00010 /* 0027B7FC lq $s0, 0x10($sp) */
    .word 0xC7B50004 /* 0027B800 lwc1 $f21, 0x4($sp) */
    .word 0xC7B40000 /* 0027B804 lwc1 $f20, 0x0($sp) */
    jr $ra
    .word 0x27BD0060 /* 0027B80C addiu $sp, $sp, 0x60 */
}
#endif
}

#if !defined(__mips__)
void func_0027B700(void *self, int type, int param, float val1, float val2) {
    int count = *(int *)((char *)self + 0x5DC);
    if (count <= 0) {
        return;
    }

    void *entry = func_0027B6D0(self);
    if (entry == 0) {
        return;
    }

    func_117CAC(entry, 0, 0x1C);

    *(void **)((char *)entry + 0x18) = *(void **)((char *)self + 0x1E0);
    *(int *)((char *)entry + 0x4) = count;

    void *global_ptr = *(void **)&D_004E3180;
    void *sub_ptr = *(void **)((char *)global_ptr + 0x404);
    *(void **)((char *)entry + 0x8) = *(void **)((char *)sub_ptr + 0x18);

    *(char *)((char *)entry + 0x0) = (char)type;
    *(float *)((char *)entry + 0xC) = val1;
    *(float *)((char *)entry + 0x10) = val2;

    float p_float;
    if (param < 0) {
        unsigned int u = (unsigned int)param;
        p_float = (float)(u >> 1 | (u & 1)) + (float)(u >> 1 | (u & 1));
    } else {
        p_float = (float)param;
    }
    *(float *)((char *)entry + 0x14) = p_float;

    int type_byte = type & 0xFF;
    if (type_byte == 0xC) {
        *(void **)((char *)self + 0x1E0) = entry;
        return;
    }

    *(void **)((char *)self + 0x1E0) = entry;
    if (type_byte == 0xB) {
        func_27B950(self, entry);
    }
}
#endif
