#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x0021DF50 */
extern "C" {
void func_123908();
void func_1046D0();
void func_0021C050();

asm void *func_0021DF50(void *ctx, short a0, short a1, short a2, void *t0, short t1, short t2, short t3, short arg_b0) {

    .word 0x27BDFF50 /* addiu      $sp, $sp, -0xB0 */
    .word 0x7FBF00A0 /* sq         $ra, 0xA0($sp) */
    .word 0x7FBE0090 /* sq         $fp, 0x90($sp) */
    .word 0x7FB70080 /* sq         $s7, 0x80($sp) */
    .word 0x7FB60070 /* sq         $s6, 0x70($sp) */
    .word 0x7FB50060 /* sq         $s5, 0x60($sp) */
    .word 0x7FB40050 /* sq         $s4, 0x50($sp) */
    .word 0x7FB30040 /* sq         $s3, 0x40($sp) */
    .word 0x7FB20030 /* sq         $s2, 0x30($sp) */
    .word 0x7FB10020 /* sq         $s1, 0x20($sp) */
    .word 0x7FB00010 /* sq         $s0, 0x10($sp) */
    .word 0x87BE00B0 /* lh         $fp, 0xB0($sp) */
    .word 0x7080B628 /* paddub     $s6, $a0, $zero */
    .word 0x70A0AE28 /* paddub     $s5, $a1, $zero */
    .word 0x70C0A628 /* paddub     $s4, $a2, $zero */
    .word 0x70E09E28 /* paddub     $s3, $a3, $zero */
    .word 0x71009628 /* paddub     $s2, $t0, $zero */
    .word 0x71208E28 /* paddub     $s1, $t1, $zero */
    .word 0x71408628 /* paddub     $s0, $t2, $zero */
    .word 0x16C00004 /* bnez       $s6, .L0021DFB0 */
    .word 0x7160BE28 /* paddub    $s7, $t3, $zero */
    jal func_123908
    .word 0x70002628 /* paddub    $a0, $zero, $zero */
    .word 0x7040B628 /* paddub     $s6, $v0, $zero */
    .word 0x00141C3C /* dsll32     $v1, $s4, 16 */
    .word 0x24020014 /* addiu      $v0, $zero, 0x14 */
    .word 0x00031C3F /* dsra32     $v1, $v1, 16 */
    .word 0x1062000B /* beq        $v1, $v0, .L0021DFEC */
    .word 0x24040200 /* addiu     $a0, $zero, 0x200 */
    .word 0x24020013 /* addiu      $v0, $zero, 0x13 */
    .word 0x10620008 /* beq        $v1, $v0, .L0021DFEC */
    .word 0x24040100 /* addiu     $a0, $zero, 0x100 */
    .word 0x24020002 /* addiu      $v0, $zero, 0x2 */
    .word 0x10620003 /* beq        $v1, $v0, .L0021DFE4 */
    .word 0x24040080 /* addiu     $a0, $zero, 0x80 */
    .word 0x10000003 /* b          .L0021DFEC */
    .word 0x24040040 /* addiu     $a0, $zero, 0x40 */
    .word 0x10000002 /* b          .L0021DFF0 */
    .word 0x00171C3C /* dsll32    $v1, $s7, 16 */
    .word 0x00171C3C /* dsll32     $v1, $s7, 16 */
    .word 0x00031C3F /* dsra32     $v1, $v1, 16 */
    .word 0x001E143C /* dsll32     $v0, $fp, 16 */
    .word 0xFFA30000 /* sd         $v1, 0x0($sp) */
    .word 0x0002143F /* dsra32     $v0, $v0, 16 */
    .word 0xFFA20008 /* sd         $v0, 0x8($sp) */
    .word 0x00621018 /* mult       $v0, $v1, $v0 */
    .word 0x32A5FFFF /* andi       $a1, $s5, 0xFFFF */
    .word 0x328600FF /* andi       $a2, $s4, 0xFF */
    .word 0x3267FFFF /* andi       $a3, $s3, 0xFFFF */
    .word 0x00021900 /* sll        $v1, $v0, 4 */
    .word 0x2482FFFF /* addiu      $v0, $a0, -0x1 */
    .word 0x00431021 /* addu       $v0, $v0, $v1 */
    .word 0x14800002 /* bnez       $a0, .L0021E02C */
    .word 0x0044001A /* div       $zero, $v0, $a0 */
    .word 0x000001CD /* break      0, 7 */
    .word 0x00004812 /* mflo       $t1 */
    .word 0x0011543C /* dsll32     $t2, $s1, 16 */
    .word 0x00105C3C /* dsll32     $t3, $s0, 16 */
    .word 0x000A543F /* dsra32     $t2, $t2, 16 */
    .word 0x000B5C3F /* dsra32     $t3, $t3, 16 */
    .word 0x72404628 /* paddub     $t0, $s2, $zero */
    jal func_1046D0
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    jal func_0021C050
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x7BBF00A0 /* lq         $ra, 0xA0($sp) */
    .word 0x7BBE0090 /* lq         $fp, 0x90($sp) */
    .word 0x7BB70080 /* lq         $s7, 0x80($sp) */
    .word 0x7BB60070 /* lq         $s6, 0x70($sp) */
    .word 0x7BB50060 /* lq         $s5, 0x60($sp) */
    .word 0x7BB40050 /* lq         $s4, 0x50($sp) */
    .word 0x7BB30040 /* lq         $s3, 0x40($sp) */
    .word 0x7BB20030 /* lq         $s2, 0x30($sp) */
    .word 0x7BB10020 /* lq         $s1, 0x20($sp) */
    .word 0x7BB00010 /* lq         $s0, 0x10($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD00B0 /* addiu     $sp, $sp, 0xB0 */
}
}


#else

/* 0x0021DF50 */
extern "C" {
void *func_123908(void *);
void func_1046D0(void *obj, unsigned short a1, unsigned char a2, unsigned short a3, void *t0, int t1, short t2,
                 short t3, long long stack_t3, long long stack_arg_b0);
void *func_0021C050(void *obj);

void *func_0021DF50(void *ctx, short a0, short a1, short a2, void *t0, short t1, short t2, short t3,
                    short arg_b0) {
    if (ctx == 0) {
        ctx = func_123908(0);
    }
    void *packet = ctx;

    int divisor = 0x40;
    if (a1 == 0x14) {
        divisor = 0x200;
    } else if (a1 == 0x13) {
        divisor = 0x100;
    } else if (a1 == 0x2) {
        divisor = 0x80;
    }

    int extent = ((t3 * arg_b0 << 4) + divisor - 1) / divisor;

    func_1046D0(packet, (unsigned short)a0, (unsigned char)a1, (unsigned short)a2, t0, extent, t1, t2,
                (long long)t3, (long long)arg_b0);
    func_0021C050(packet);
    return packet;
}
}


#endif
