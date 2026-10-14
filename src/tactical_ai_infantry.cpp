#include "sub_list.h"

extern "C" {

void *func_332e60(void *mgr, int id);
void func_001454C0(void *self, const char *format, ...);
extern const char D_490FC0[];
void *func_00100670(void *self);
void func_0011B170(void *destination, const char *source, int length);
void func_0011ABBC(void *destination, const char *source);
void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1);
void *func_100730(void);
void *func_00145350(void *self, int mode);

asm void func_001446EC(void) {
    .set noreorder
    .set noat
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_001446F0(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFD0 // addiu      $sp, $sp, -0x30
    .word 0x7FBF0020 // sq         $ra, 0x20($sp)
    .word 0x7FB10010 // sq         $s1, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0x70808E28 // paddub     $s1, $a0, $zero
    .word 0x1220000C // beqz       $s1, .L00144738
    .word 0x70A08628 // paddub    $s0, $a1, $zero
    .word 0x3C02004D // lui        $v0, %hi(D_4D7780)
    .word 0x24427780 // addiu      $v0, $v0, %lo(D_4D7780)
    .word 0xAE220000 // sw         $v0, 0x0($s1)
    jal func_00145350
    .word 0x70002E28 // paddub    $a1, $zero, $zero
    .word 0x0010143C // dsll32     $v0, $s0, 16
    .word 0x0002143F // dsra32     $v0, $v0, 16
    .word 0x18400004 // blez       $v0, .L0014473C
    .word 0x72201628 // paddub    $v0, $s1, $zero
    jal func_00100670
    .word 0x72202628 // paddub    $a0, $s1, $zero
  // .L00144738:
    .word 0x72201628 // paddub     $v0, $s1, $zero
  // .L0014473C:
    .word 0x7BBF0020 // lq         $ra, 0x20($sp)
    .word 0x7BB10010 // lq         $s1, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0030 // addiu     $sp, $sp, 0x30
    .set reorder
    .set at
}

asm void func_00144750(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFD0 // addiu      $sp, $sp, -0x30
    .word 0x7FBF0010 // sq         $ra, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0xAFA4002C // sw         $a0, 0x2C($sp)
    .word 0x8FA4002C // lw         $a0, 0x2C($sp)
    .word 0x70E08628 // paddub     $s0, $a3, $zero
    .word 0x70C03E28 // paddub     $a3, $a2, $zero
    .word 0x70A04628 // paddub     $t0, $a1, $zero
    .word 0x3C020049 // lui        $v0, %hi(D_490FA0)
    .word 0x24450FA0 // addiu      $a1, $v0, %lo(D_490FA0)
    jal func_001452B0
    .word 0x240603E8 // addiu     $a2, $zero, 0x3E8
    .word 0x3C02004D // lui        $v0, %hi(D_4D77D0)
    .word 0x244577D0 // addiu      $a1, $v0, %lo(D_4D77D0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0x2403012C // addiu      $v1, $zero, 0x12C
    .word 0x240404B0 // addiu      $a0, $zero, 0x4B0
    .word 0xAC450000 // sw         $a1, 0x0($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC5000AC // sw         $s0, 0xAC($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC4000B0 // sw         $zero, 0xB0($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC4000B4 // sw         $zero, 0xB4($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC4000B8 // sw         $zero, 0xB8($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    jal func_100730
    .word 0xAC4300BC // sw        $v1, 0xBC($v0)
    .word 0x8FA3002C // lw         $v1, 0x2C($sp)
    .word 0xAC6200B0 // sw         $v0, 0xB0($v1)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0x7BBF0010 // lq         $ra, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0030 // addiu     $sp, $sp, 0x30
    .set reorder
    .set at
}

asm void func_001447E0(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFC0 // addiu      $sp, $sp, -0x40
    .word 0x7FBF0020 // sq         $ra, 0x20($sp)
    .word 0x7FB10010 // sq         $s1, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0xAFA40034 // sw         $a0, 0x34($sp)
    .word 0x8FA40034 // lw         $a0, 0x34($sp)
    .word 0x70E08E28 // paddub     $s1, $a3, $zero
    .word 0x70C08628 // paddub     $s0, $a2, $zero
    .word 0x70A03E28 // paddub     $a3, $a1, $zero
    .word 0x3C020049 // lui        $v0, %hi(D_490FA0)
    .word 0x24450FA0 // addiu      $a1, $v0, %lo(D_490FA0)
    .word 0x240603E8 // addiu      $a2, $zero, 0x3E8
    .word 0x0C0514AC // jal        func_001452B0
    .word 0x70004628 // paddub    $t0, $zero, $zero
    .word 0x3C02004D // lui        $v0, %hi(D_4D77D0)
    .word 0x244577D0 // addiu      $a1, $v0, %lo(D_4D77D0)
    .word 0x8FA20034 // lw         $v0, 0x34($sp)
    .word 0x2403012C // addiu      $v1, $zero, 0x12C
    .word 0x240404B0 // addiu      $a0, $zero, 0x4B0
    .word 0xAC450000 // sw         $a1, 0x0($v0)
    .word 0x8FA20034 // lw         $v0, 0x34($sp)
    .word 0xAC5000AC // sw         $s0, 0xAC($v0)
    .word 0x8FA20034 // lw         $v0, 0x34($sp)
    .word 0xAC4000B0 // sw         $zero, 0xB0($v0)
    .word 0x8FA20034 // lw         $v0, 0x34($sp)
    .word 0xAC4000B4 // sw         $zero, 0xB4($v0)
    .word 0x8FA20034 // lw         $v0, 0x34($sp)
    .word 0xAC4000B8 // sw         $zero, 0xB8($v0)
    .word 0x8FA20034 // lw         $v0, 0x34($sp)
    .word 0x0C0401CC // jal        func_100730
    .word 0xAC4300BC // sw        $v1, 0xBC($v0)
    .word 0x8FA30034 // lw         $v1, 0x34($sp)
    .word 0x27A50038 // addiu      $a1, $sp, 0x38
    .word 0x24060004 // addiu      $a2, $zero, 0x4
    .word 0x72202628 // paddub     $a0, $s1, $zero
    .word 0x0C089B64 // jal        func_00226D90
    .word 0xAC6200B0 // sw        $v0, 0xB0($v1)
    .word 0x1000002C // b          .L00144928
    .word 0x70008628 // paddub    $s0, $zero, $zero
    .word 0x27A5003C // addiu      $a1, $sp, 0x3C
  // .L00144880:
    .word 0x24060004 // addiu      $a2, $zero, 0x4
    .word 0x0C089B64 // jal        func_00226D90
    .word 0x72202628 // paddub    $a0, $s1, $zero
    .word 0x8FA60034 // lw         $a2, 0x34($sp)
    .word 0x8FA4003C // lw         $a0, 0x3C($sp)
    .word 0x8CC700B4 // lw         $a3, 0xB4($a2)
    .word 0x1000000A // b          .L001448C4
    .word 0x70002E28 // paddub    $a1, $zero, $zero
  // .L001448A0:
    .word 0x8CC200B0 // lw         $v0, 0xB0($a2)
    .word 0x00051880 // sll        $v1, $a1, 2
    .word 0x00431021 // addu       $v0, $v0, $v1
    .word 0x8C420000 // lw         $v0, 0x0($v0)
    .word 0x54820004 // bnel       $a0, $v0, .L001448C4
    .word 0x24A50001 // addiu     $a1, $a1, 0x1
    .word 0x1000000A // b          .L001448E4
    .word 0x24030001 // addiu     $v1, $zero, 0x1
    .word 0x24A50001 // addiu      $a1, $a1, 0x1
  // .L001448C4:
    .word 0x00A7082A // slt        $at, $a1, $a3
    .word 0x10200006 // beqz       $at, .L001448E4
    .word 0x70001E28 // paddub    $v1, $zero, $zero
    .word 0x8CC200BC // lw         $v0, 0xBC($a2)
    .word 0x00A2102A // slt        $v0, $a1, $v0
    .word 0x1440FFF1 // bnez       $v0, .L001448A0
    .word 0x00000000 // nop
    .word 0x70001E28 // paddub     $v1, $zero, $zero
  // .L001448E4:
    .word 0x24020001 // addiu      $v0, $zero, 0x1
    .word 0x5062000F // beql       $v1, $v0, .L00144928
    .word 0x26100001 // addiu     $s0, $s0, 0x1
    .word 0x8CC200BC // lw         $v0, 0xBC($a2)
    .word 0x2442FFFF // addiu      $v0, $v0, -0x1
    .word 0x0047082A // slt        $at, $v0, $a3
    .word 0x14200009 // bnez       $at, .L00144924
    .word 0x00000000 // nop
    .word 0x8CC200B0 // lw         $v0, 0xB0($a2)
    .word 0x00071880 // sll        $v1, $a3, 2
    .word 0x00431021 // addu       $v0, $v0, $v1
    .word 0xAC440000 // sw         $a0, 0x0($v0)
    .word 0x8FA30034 // lw         $v1, 0x34($sp)
    .word 0x8C6200B4 // lw         $v0, 0xB4($v1)
    .word 0x24420001 // addiu      $v0, $v0, 0x1
    .word 0xAC6200B4 // sw         $v0, 0xB4($v1)
  // .L00144924:
    .word 0x26100001 // addiu      $s0, $s0, 0x1
  // .L00144928:
    .word 0x8FA20038 // lw         $v0, 0x38($sp)
    .word 0x0202102A // slt        $v0, $s0, $v0
    .word 0x1440FFD3 // bnez       $v0, .L00144880
    .word 0x27A5003C // addiu     $a1, $sp, 0x3C
    .word 0x8FA20034 // lw         $v0, 0x34($sp)
    .word 0x7BBF0020 // lq         $ra, 0x20($sp)
    .word 0x7BB10010 // lq         $s1, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0040 // addiu     $sp, $sp, 0x40
    .set reorder
    .set at
}

asm void func_00144950(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFD0 // addiu      $sp, $sp, -0x30
    .word 0x7FBF0020 // sq         $ra, 0x20($sp)
    .word 0x7FB10010 // sq         $s1, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0x70808E28 // paddub     $s1, $a0, $zero
    .word 0x12200019 // beqz       $s1, .L001449CC
    .word 0x70A08628 // paddub    $s0, $a1, $zero
    .word 0x3C02004D // lui        $v0, %hi(D_4D77D0)
    .word 0x244277D0 // addiu      $v0, $v0, %lo(D_4D77D0)
    .word 0xAE220000 // sw         $v0, 0x0($s1)
    .word 0x262200B0 // addiu      $v0, $s1, 0xB0
    .word 0x1040000A // beqz       $v0, .L001449A8
    .word 0xAE2000AC // sw        $zero, 0xAC($s1)
    .word 0x8E2400B0 // lw         $a0, 0xB0($s1)
    .word 0x10800004 // beqz       $a0, .L0014499C
    .word 0x00000000 // nop
    .word 0x0C04018C // jal        func_00100630
    .word 0x00000000 // nop
    .word 0xAE2000B0 // sw         $zero, 0xB0($s1)
  // .L0014499C:
    .word 0xAE2000B4 // sw         $zero, 0xB4($s1)
    .word 0xAE2000B8 // sw         $zero, 0xB8($s1)
    .word 0xAE2000BC // sw         $zero, 0xBC($s1)
  // .L001449A8:
    .word 0x72202628 // paddub     $a0, $s1, $zero
    .word 0x0C0514D4 // jal        func_00145350
    .word 0x70002E28 // paddub    $a1, $zero, $zero
    .word 0x0010143C // dsll32     $v0, $s0, 16
    .word 0x0002143F // dsra32     $v0, $v0, 16
    .word 0x18400004 // blez       $v0, .L001449D0
    .word 0x72201628 // paddub    $v0, $s1, $zero
    .word 0x0C04019C // jal        func_00100670
    .word 0x72202628 // paddub    $a0, $s1, $zero
  // .L001449CC:
    .word 0x72201628 // paddub     $v0, $s1, $zero
  // .L001449D0:
    .word 0x7BBF0020 // lq         $ra, 0x20($sp)
    .word 0x7BB10010 // lq         $s1, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0030 // addiu     $sp, $sp, 0x30
    .set reorder
    .set at
}

asm void func_001449F0(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00144A00(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFB0 // addiu      $sp, $sp, -0x50
    .word 0x7FBF0030 // sq         $ra, 0x30($sp)
    .word 0x7FB20020 // sq         $s2, 0x20($sp)
    .word 0x7FB10010 // sq         $s1, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0x8C8200B4 // lw         $v0, 0xB4($a0)
    .word 0x70A08E28 // paddub     $s1, $a1, $zero
    .word 0x70809628 // paddub     $s2, $a0, $zero
    .word 0x27A5004C // addiu      $a1, $sp, 0x4C
    .word 0x24060004 // addiu      $a2, $zero, 0x4
    .word 0xAFA2004C // sw         $v0, 0x4C($sp)
    .word 0x0C089BDC // jal        func_00226F70
    .word 0x72202628 // paddub    $a0, $s1, $zero
    .word 0x10000012 // b          .L00144A80
    .word 0x70008628 // paddub    $s0, $zero, $zero
  // .L00144A3C:
    .word 0x8E4200BC // lw         $v0, 0xBC($s2)
    .word 0x2442FFFF // addiu      $v0, $v0, -0x1
    .word 0x0050082A // slt        $at, $v0, $s0
    .word 0x10200003 // beqz       $at, .L00144A58
    .word 0x00000000 // nop
    .word 0x10000004 // b          .L00144A64
    .word 0x8E4200B0 // lw        $v0, 0xB0($s2)
  // .L00144A58:
    .word 0x8E4200B0 // lw         $v0, 0xB0($s2)
    .word 0x00101880 // sll        $v1, $s0, 2
    .word 0x00431021 // addu       $v0, $v0, $v1
  // .L00144A64:
    .word 0x8C420000 // lw         $v0, 0x0($v0)
    .word 0x27A5004C // addiu      $a1, $sp, 0x4C
    .word 0x24060004 // addiu      $a2, $zero, 0x4
    .word 0x72202628 // paddub     $a0, $s1, $zero
    .word 0x0C089BDC // jal        func_00226F70
    .word 0xAFA2004C // sw        $v0, 0x4C($sp)
    .word 0x26100001 // addiu      $s0, $s0, 0x1
  // .L00144A80:
    .word 0x8E4200B4 // lw         $v0, 0xB4($s2)
    .word 0x0202102A // slt        $v0, $s0, $v0
    .word 0x1440FFEC // bnez       $v0, .L00144A3C
    .word 0x00000000 // nop
    .word 0x7BBF0030 // lq         $ra, 0x30($sp)
    .word 0x7BB20020 // lq         $s2, 0x20($sp)
    .word 0x7BB10010 // lq         $s1, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x24020001 // addiu      $v0, $zero, 0x1
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0050 // addiu     $sp, $sp, 0x50
    .set reorder
    .set at
}

asm void func_00144AB0(void) {
    .set noreorder
    .set noat
    .word 0x14A00003 // bnez       $a1, .L00144AC0
    .word 0x00000000 // nop
    .word 0x10000026 // b          .L00144B54
    .word 0x70001628 // paddub    $v0, $zero, $zero
  // .L00144AC0:
    .word 0x84A50024 // lh         $a1, 0x24($a1)
    .word 0x8C8700B4 // lw         $a3, 0xB4($a0)
    .word 0x1000000A // b          .L00144AF4
    .word 0x70003628 // paddub    $a2, $zero, $zero
  // .L00144AD0:
    .word 0x8C8200B0 // lw         $v0, 0xB0($a0)
    .word 0x00061880 // sll        $v1, $a2, 2
    .word 0x00431021 // addu       $v0, $v0, $v1
    .word 0x8C420000 // lw         $v0, 0x0($v0)
    .word 0x54A20004 // bnel       $a1, $v0, .L00144AF4
    .word 0x24C60001 // addiu     $a2, $a2, 0x1
    .word 0x1000000A // b          .L00144B14
    .word 0x24030001 // addiu     $v1, $zero, 0x1
    .word 0x24C60001 // addiu      $a2, $a2, 0x1
  // .L00144AF4:
    .word 0x00C7082A // slt        $at, $a2, $a3
    .word 0x10200006 // beqz       $at, .L00144B14
    .word 0x70001E28 // paddub    $v1, $zero, $zero
    .word 0x8C8200BC // lw         $v0, 0xBC($a0)
    .word 0x00C2102A // slt        $v0, $a2, $v0
    .word 0x1440FFF1 // bnez       $v0, .L00144AD0
    .word 0x00000000 // nop
    .word 0x70001E28 // paddub     $v1, $zero, $zero
  // .L00144B14:
    .word 0x24020001 // addiu      $v0, $zero, 0x1
    .word 0x1062000E // beq        $v1, $v0, .L00144B54
    .word 0x24020001 // addiu     $v0, $zero, 0x1
    .word 0x8C8200BC // lw         $v0, 0xBC($a0)
    .word 0x2442FFFF // addiu      $v0, $v0, -0x1
    .word 0x0047082A // slt        $at, $v0, $a3
    .word 0x14200008 // bnez       $at, .L00144B50
    .word 0x00000000 // nop
    .word 0x8C8200B0 // lw         $v0, 0xB0($a0)
    .word 0x00071880 // sll        $v1, $a3, 2
    .word 0x00431021 // addu       $v0, $v0, $v1
    .word 0xAC450000 // sw         $a1, 0x0($v0)
    .word 0x8C8200B4 // lw         $v0, 0xB4($a0)
    .word 0x24420001 // addiu      $v0, $v0, 0x1
    .word 0xAC8200B4 // sw         $v0, 0xB4($a0)
  // .L00144B50:
    .word 0x24020001 // addiu      $v0, $zero, 0x1
  // .L00144B54:
    .word 0x03E00008 // jr         $ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00144B60(void) {
    .set noreorder
    .set noat
    .word 0x8C8700BC // lw         $a3, 0xBC($a0)
    .word 0x10000002 // b          .L00144B70
    .word 0x70003628 // paddub    $a2, $zero, $zero
    .word 0x24C60001 // addiu      $a2, $a2, 0x1
  // .L00144B70:
    .word 0x00C7082A // slt        $at, $a2, $a3
    .word 0x10200008 // beqz       $at, .L00144B98
    .word 0x00C7102A // slt       $v0, $a2, $a3
    .word 0x8C8200B0 // lw         $v0, 0xB0($a0)
    .word 0x00061880 // sll        $v1, $a2, 2
    .word 0x00431021 // addu       $v0, $v0, $v1
    .word 0x8C420000 // lw         $v0, 0x0($v0)
    .word 0x54A2FFF8 // bnel       $a1, $v0, .L00144B70
    .word 0x24C60001 // addiu     $a2, $a2, 0x1
    .word 0x00C7102A // slt        $v0, $a2, $a3
  // .L00144B98:
    .word 0x14400009 // bnez       $v0, .L00144BC0
    .word 0x00000000 // nop
    .word 0x10000014 // b          .L00144BF4
    .word 0x70001628 // paddub    $v0, $zero, $zero
  // .L00144BA8:
    .word 0x8C8200B0 // lw         $v0, 0xB0($a0)
    .word 0x00061880 // sll        $v1, $a2, 2
    .word 0x24C60001 // addiu      $a2, $a2, 0x1
    .word 0x00431821 // addu       $v1, $v0, $v1
    .word 0x8C620004 // lw         $v0, 0x4($v1)
    .word 0xAC620000 // sw         $v0, 0x0($v1)
  // .L00144BC0:
    .word 0x8C8200BC // lw         $v0, 0xBC($a0)
    .word 0x2442FFFF // addiu      $v0, $v0, -0x1
    .word 0x00C2102A // slt        $v0, $a2, $v0
    .word 0x1440FFF6 // bnez       $v0, .L00144BA8
    .word 0x00000000 // nop
    .word 0x8C8200B4 // lw         $v0, 0xB4($a0)
    .word 0x2442FFFF // addiu      $v0, $v0, -0x1
    .word 0xAC8200B4 // sw         $v0, 0xB4($a0)
    .word 0x8C8200B4 // lw         $v0, 0xB4($a0)
    .word 0x04410003 // bgez       $v0, .L00144BF4
    .word 0x24020001 // addiu     $v0, $zero, 0x1
    .word 0xAC8000B4 // sw         $zero, 0xB4($a0)
    .word 0x24020001 // addiu      $v0, $zero, 0x1
  // .L00144BF4:
    .word 0x03E00008 // jr         $ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00144C00(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFA0 // addiu      $sp, $sp, -0x60
    .word 0x7FBF0050 // sq         $ra, 0x50($sp)
    .word 0x7FB40040 // sq         $s4, 0x40($sp)
    .word 0x7FB30030 // sq         $s3, 0x30($sp)
    .word 0x7FB20020 // sq         $s2, 0x20($sp)
    .word 0x7FB10010 // sq         $s1, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0x70809E28 // paddub     $s3, $a0, $zero
    .word 0x70A09628 // paddub     $s2, $a1, $zero
    .word 0x70008628 // paddub     $s0, $zero, $zero
    .word 0x10000021 // b          .L00144CB0
    .word 0x70008E28 // paddub    $s1, $zero, $zero
  // .L00144C30:
    .word 0x8E6200BC // lw         $v0, 0xBC($s3)
    .word 0x2442FFFF // addiu      $v0, $v0, -0x1
    .word 0x0051082A // slt        $at, $v0, $s1
    .word 0x10200003 // beqz       $at, .L00144C4C
    .word 0x8E6400AC // lw        $a0, 0xAC($s3)
    .word 0x10000004 // b          .L00144C58
    .word 0x8E6200B0 // lw        $v0, 0xB0($s3)
  // .L00144C4C:
    .word 0x8E6200B0 // lw         $v0, 0xB0($s3)
    .word 0x00111880 // sll        $v1, $s1, 2
    .word 0x00431021 // addu       $v0, $v0, $v1
  // .L00144C58:
    .word 0x8C450000 // lw         $a1, 0x0($v0)
    .word 0x0C0CCB98 // jal        func_332e60
    .word 0x8C840B98 // lw        $a0, 0xB98($a0)
    .word 0x7040A628 // paddub     $s4, $v0, $zero
    .word 0x52800011 // beql       $s4, $zero, .L00144CB0
    .word 0x26310001 // addiu     $s1, $s1, 0x1
    .word 0x8E990000 // lw         $t9, 0x0($s4)
    .word 0x8F390164 // lw         $t9, 0x164($t9)
    .word 0x0320F809 // jalr       $t9
    .word 0x72802628 // paddub    $a0, $s4, $zero
    .word 0x1040000A // beqz       $v0, .L00144CAC
    .word 0x00000000 // nop
    .word 0x8E990000 // lw         $t9, 0x0($s4)
    .word 0x8F390164 // lw         $t9, 0x164($t9)
    .word 0x0320F809 // jalr       $t9
    .word 0x72802628 // paddub    $a0, $s4, $zero
    .word 0x0C051C68 // jal        func_1471A0
    .word 0x8C440000 // lw        $a0, 0x0($v0)
    .word 0x16420002 // bne        $s2, $v0, .L00144CAC
    .word 0x00000000 // nop
    .word 0x26100001 // addiu      $s0, $s0, 0x1
  // .L00144CAC:
    .word 0x26310001 // addiu      $s1, $s1, 0x1
  // .L00144CB0:
    .word 0x8E6200B4 // lw         $v0, 0xB4($s3)
    .word 0x0222102A // slt        $v0, $s1, $v0
    .word 0x1440FFDD // bnez       $v0, .L00144C30
    .word 0x00000000 // nop
    .word 0x72001628 // paddub     $v0, $s0, $zero
    .word 0x7BBF0050 // lq         $ra, 0x50($sp)
    .word 0x7BB40040 // lq         $s4, 0x40($sp)
    .word 0x7BB30030 // lq         $s3, 0x30($sp)
    .word 0x7BB20020 // lq         $s2, 0x20($sp)
    .word 0x7BB10010 // lq         $s1, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0060 // addiu     $sp, $sp, 0x60
    .set reorder
    .set at
}

asm void func_00144CF0(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x70001628 // paddub    $v0, $zero, $zero
    .set reorder
    .set at
}

asm void func_00144D00(void) {
    .set noreorder
    .set noat
    .word 0x8C8200AC // lw         $v0, 0xAC($a0)
    j func_332e60
    .word 0x8C440B98 // lw        $a0, 0xB98($v0)
    .set reorder
    .set at
}

asm void func_00144D10(void) {
    .set noreorder
    .set noat
    .word 0x27BDFF50 // addiu      $sp, $sp, -0xB0
    .word 0x7FBF0090 // sq         $ra, 0x90($sp)
    .word 0x7FBE0080 // sq         $fp, 0x80($sp)
    .word 0x7FB70070 // sq         $s7, 0x70($sp)
    .word 0x7FB60060 // sq         $s6, 0x60($sp)
    .word 0x7FB50050 // sq         $s5, 0x50($sp)
    .word 0x7FB40040 // sq         $s4, 0x40($sp)
    .word 0x7FB30030 // sq         $s3, 0x30($sp)
    .word 0x7FB20020 // sq         $s2, 0x20($sp)
    .word 0x7FB10010 // sq         $s1, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0x7080B628 // paddub     $s6, $a0, $zero
    .word 0x70A0AE28 // paddub     $s5, $a1, $zero
    .word 0x70C0A628 // paddub     $s4, $a2, $zero
    .word 0x70E09E28 // paddub     $s3, $a3, $zero
    .word 0x71009628 // paddub     $s2, $t0, $zero
    .word 0x7120BE28 // paddub     $s7, $t1, $zero
    .word 0x7140F628 // paddub     $fp, $t2, $zero
    .word 0xAFAB00AC // sw         $t3, 0xAC($sp)
    .word 0x10000079 // b          .L00144F44
    .word 0x70008628 // paddub    $s0, $zero, $zero
  // .L00144D64:
    .word 0x8EC200BC // lw         $v0, 0xBC($s6)
    .word 0x2442FFFF // addiu      $v0, $v0, -0x1
    .word 0x0050082A // slt        $at, $v0, $s0
    .word 0x10200003 // beqz       $at, .L00144D80
    .word 0x8EC400AC // lw        $a0, 0xAC($s6)
    .word 0x10000004 // b          .L00144D8C
    .word 0x8EC200B0 // lw        $v0, 0xB0($s6)
  // .L00144D80:
    .word 0x8EC200B0 // lw         $v0, 0xB0($s6)
    .word 0x00101880 // sll        $v1, $s0, 2
    .word 0x00431021 // addu       $v0, $v0, $v1
  // .L00144D8C:
    .word 0x8C450000 // lw         $a1, 0x0($v0)
    .word 0x0C0CCB98 // jal        func_332e60
    .word 0x8C840B98 // lw        $a0, 0xB98($a0)
    .word 0x70408E28 // paddub     $s1, $v0, $zero
    .word 0x52200069 // beql       $s1, $zero, .L00144F44
    .word 0x26100001 // addiu     $s0, $s0, 0x1
    .word 0x8E390000 // lw         $t9, 0x0($s1)
    .word 0x8F390164 // lw         $t9, 0x164($t9)
    .word 0x0320F809 // jalr       $t9
    .word 0x72202628 // paddub    $a0, $s1, $zero
    .word 0x10400062 // beqz       $v0, .L00144F40
    .word 0x00000000 // nop
    .word 0x2402FFFF // addiu      $v0, $zero, -0x1
    .word 0x12A20005 // beq        $s5, $v0, .L00144DD8
    .word 0x2402FFFF // addiu     $v0, $zero, -0x1
    .word 0x86220024 // lh         $v0, 0x24($s1)
    .word 0x1455005C // bne        $v0, $s5, .L00144F40
    .word 0x00000000 // nop
    .word 0x2402FFFF // addiu      $v0, $zero, -0x1
  // .L00144DD8:
    .word 0x12820006 // beq        $s4, $v0, .L00144DF4
    .word 0x2402FFFF // addiu     $v0, $zero, -0x1
    .word 0x8E220004 // lw         $v0, 0x4($s1)
    .word 0x84420008 // lh         $v0, 0x8($v0)
    .word 0x14540055 // bne        $v0, $s4, .L00144F40
    .word 0x00000000 // nop
    .word 0x2402FFFF // addiu      $v0, $zero, -0x1
  // .L00144DF4:
    .word 0x12620006 // beq        $s3, $v0, .L00144E10
    .word 0x2402FFFF // addiu     $v0, $zero, -0x1
    .word 0x8E220004 // lw         $v0, 0x4($s1)
    .word 0x8442000E // lh         $v0, 0xE($v0)
    .word 0x1453004E // bne        $v0, $s3, .L00144F40
    .word 0x00000000 // nop
    .word 0x2402FFFF // addiu      $v0, $zero, -0x1
  // .L00144E10:
    .word 0x1242000A // beq        $s2, $v0, .L00144E3C
    .word 0x2402FFFF // addiu     $v0, $zero, -0x1
    .word 0x8E390000 // lw         $t9, 0x0($s1)
    .word 0x8F390164 // lw         $t9, 0x164($t9)
    .word 0x0320F809 // jalr       $t9
    .word 0x72202628 // paddub    $a0, $s1, $zero
    .word 0x0C051C68 // jal        func_1471A0
    .word 0x8C440000 // lw        $a0, 0x0($v0)
    .word 0x16420043 // bne        $s2, $v0, .L00144F40
    .word 0x00000000 // nop
    .word 0x2402FFFF // addiu      $v0, $zero, -0x1
  // .L00144E3C:
    .word 0x12E20014 // beq        $s7, $v0, .L00144E90
    .word 0x2402FFFF // addiu     $v0, $zero, -0x1
    .word 0x8EC200BC // lw         $v0, 0xBC($s6)
    .word 0x2442FFFF // addiu      $v0, $v0, -0x1
    .word 0x0050082A // slt        $at, $v0, $s0
    .word 0x10200003 // beqz       $at, .L00144E60
    .word 0x00000000 // nop
    .word 0x10000004 // b          .L00144E6C
    .word 0x8EC200B0 // lw        $v0, 0xB0($s6)
  // .L00144E60:
    .word 0x8EC200B0 // lw         $v0, 0xB0($s6)
    .word 0x00101880 // sll        $v1, $s0, 2
    .word 0x00431021 // addu       $v0, $v0, $v1
  // .L00144E6C:
    .word 0x8ED90000 // lw         $t9, 0x0($s6)
    .word 0x8C450000 // lw         $a1, 0x0($v0)
    .word 0x72C02628 // paddub     $a0, $s6, $zero
    .word 0x8F390058 // lw         $t9, 0x58($t9)
    .word 0x0320F809 // jalr       $t9
    .word 0x72E03628 // paddub    $a2, $s7, $zero
    .word 0x1040002E // beqz       $v0, .L00144F40
    .word 0x00000000 // nop
    .word 0x2402FFFF // addiu      $v0, $zero, -0x1
  // .L00144E90:
    .word 0x13C20009 // beq        $fp, $v0, .L00144EB8
    .word 0x00000000 // nop
    .word 0x8E390000 // lw         $t9, 0x0($s1)
    .word 0x8F390164 // lw         $t9, 0x164($t9)
    .word 0x0320F809 // jalr       $t9
    .word 0x72202628 // paddub    $a0, $s1, $zero
    .word 0x0C051C70 // jal        func_1471C0
    .word 0x8C440000 // lw        $a0, 0x0($v0)
    .word 0x17C20023 // bne        $fp, $v0, .L00144F40
    .word 0x00000000 // nop
  // .L00144EB8:
    .word 0x8FA200AC // lw         $v0, 0xAC($sp)
    .word 0x2403FFFF // addiu      $v1, $zero, -0x1
    .word 0x1043000A // beq        $v0, $v1, .L00144EEC
    .word 0x00000000 // nop
    .word 0x8E390000 // lw         $t9, 0x0($s1)
    .word 0x8F390164 // lw         $t9, 0x164($t9)
    .word 0x0320F809 // jalr       $t9
    .word 0x72202628 // paddub    $a0, $s1, $zero
    .word 0x0C051C74 // jal        func_1471D0
    .word 0x8C440000 // lw        $a0, 0x0($v0)
    .word 0x8FA300AC // lw         $v1, 0xAC($sp)
    .word 0x14620016 // bne        $v1, $v0, .L00144F40
    .word 0x00000000 // nop
  // .L00144EEC:
    .word 0x8FA200B8 // lw         $v0, 0xB8($sp)
    .word 0x2403FFFF // addiu      $v1, $zero, -0x1
    .word 0x10430004 // beq        $v0, $v1, .L00144F08
    .word 0x00000000 // nop
    .word 0x92230039 // lbu        $v1, 0x39($s1)
    .word 0x1462000F // bne        $v1, $v0, .L00144F40
    .word 0x00000000 // nop
  // .L00144F08:
    .word 0x8FA200C0 // lw         $v0, 0xC0($sp)
    .word 0x2403FFFF // addiu      $v1, $zero, -0x1
    .word 0x50430009 // beql       $v0, $v1, .L00144F38
    .word 0x72201628 // paddub    $v0, $s1, $zero
    .word 0x44820000 // mtc1       $v0, $f0
    .word 0xC6210040 // lwc1       $f1, 0x40($s1)
    .word 0x46800020 // cvt.s.w    $f0, $f0
    .word 0x46000836 // c.le.s     $f1, $f0
    .word 0x00000000 // nop
    .word 0x45000004 // bc1f       .L00144F40
    .word 0x00000000 // nop
    .word 0x72201628 // paddub     $v0, $s1, $zero
  // .L00144F38:
    .word 0x10000008 // b          .L00144F5C
    .word 0x7BBF0090 // lq        $ra, 0x90($sp)
  // .L00144F40:
    .word 0x26100001 // addiu      $s0, $s0, 0x1
  // .L00144F44:
    .word 0x8EC200B4 // lw         $v0, 0xB4($s6)
    .word 0x0202102A // slt        $v0, $s0, $v0
    .word 0x1440FF85 // bnez       $v0, .L00144D64
    .word 0x00000000 // nop
    .word 0x70001628 // paddub     $v0, $zero, $zero
    .word 0x7BBF0090 // lq         $ra, 0x90($sp)
  // .L00144F5C:
    .word 0x7BBE0080 // lq         $fp, 0x80($sp)
    .word 0x7BB70070 // lq         $s7, 0x70($sp)
    .word 0x7BB60060 // lq         $s6, 0x60($sp)
    .word 0x7BB50050 // lq         $s5, 0x50($sp)
    .word 0x7BB40040 // lq         $s4, 0x40($sp)
    .word 0x7BB30030 // lq         $s3, 0x30($sp)
    .word 0x7BB20020 // lq         $s2, 0x20($sp)
    .word 0x7BB10010 // lq         $s1, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD00B0 // addiu     $sp, $sp, 0xB0
    .set reorder
    .set at
}

int func_00144F90(void *self, void *argument) {
    func_001454C0(self, D_490FC0, argument);
    return -1;
}

asm void func_00144FC0(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x70001628 // paddub    $v0, $zero, $zero
    .set reorder
    .set at
}

asm void func_00144FD0(void) {
    .set noreorder
    .set noat
    .word 0x27BDFF60 // addiu      $sp, $sp, -0xA0
    .word 0x7FBF0090 // sq         $ra, 0x90($sp)
    .word 0x7FBE0080 // sq         $fp, 0x80($sp)
    .word 0x7FB70070 // sq         $s7, 0x70($sp)
    .word 0x7FB60060 // sq         $s6, 0x60($sp)
    .word 0x7FB50050 // sq         $s5, 0x50($sp)
    .word 0x7FB40040 // sq         $s4, 0x40($sp)
    .word 0x7FB30030 // sq         $s3, 0x30($sp)
    .word 0x7FB20020 // sq         $s2, 0x20($sp)
    .word 0x7FB10010 // sq         $s1, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0x7080BE28 // paddub     $s7, $a0, $zero
    .word 0x70A0B628 // paddub     $s6, $a1, $zero
    .word 0x70C0AE28 // paddub     $s5, $a2, $zero
    .word 0x70E0F628 // paddub     $fp, $a3, $zero
    .word 0x70008628 // paddub     $s0, $zero, $zero
    .word 0x70008E28 // paddub     $s1, $zero, $zero
    .word 0x10000060 // b          .L00145198
    .word 0x70009628 // paddub    $s2, $zero, $zero
  // .L0014501C:
    .word 0x8EE200BC // lw         $v0, 0xBC($s7)
    .word 0x2442FFFF // addiu      $v0, $v0, -0x1
    .word 0x0052082A // slt        $at, $v0, $s2
    .word 0x10200003 // beqz       $at, .L00145038
    .word 0x8EE400AC // lw        $a0, 0xAC($s7)
    .word 0x10000004 // b          .L00145044
    .word 0x8EE200B0 // lw        $v0, 0xB0($s7)
  // .L00145038:
    .word 0x8EE200B0 // lw         $v0, 0xB0($s7)
    .word 0x00121880 // sll        $v1, $s2, 2
    .word 0x00431021 // addu       $v0, $v0, $v1
  // .L00145044:
    .word 0x8C450000 // lw         $a1, 0x0($v0)
    .word 0x0C0CCB98 // jal        func_332e60
    .word 0x8C840B98 // lw        $a0, 0xB98($a0)
    .word 0x70409E28 // paddub     $s3, $v0, $zero
    .word 0x52600050 // beql       $s3, $zero, .L00145198
    .word 0x26520001 // addiu     $s2, $s2, 0x1
    .word 0x8E790000 // lw         $t9, 0x0($s3)
    .word 0x8F390164 // lw         $t9, 0x164($t9)
    .word 0x0320F809 // jalr       $t9
    .word 0x72602628 // paddub    $a0, $s3, $zero
    .word 0x10400049 // beqz       $v0, .L00145194
    .word 0x00000000 // nop
    .word 0x92620039 // lbu        $v0, 0x39($s3)
    .word 0x10400046 // beqz       $v0, .L00145194
    .word 0x00000000 // nop
    .word 0x92630038 // lbu        $v1, 0x38($s3)
    .word 0x24020050 // addiu      $v0, $zero, 0x50
    .word 0x14620005 // bne        $v1, $v0, .L001450A0
    .word 0x00000000 // nop
    .word 0x8E620130 // lw         $v0, 0x130($s3)
    .word 0x10400002 // beqz       $v0, .L001450A0
    .word 0x00000000 // nop
    .word 0x70409E28 // paddub     $s3, $v0, $zero
  // .L001450A0:
    .word 0x17C00006 // bnez       $fp, .L001450BC
    .word 0x00000000 // nop
    .word 0x24050010 // addiu      $a1, $zero, 0x10
    .word 0x0C09AB48 // jal        func_26AD20
    .word 0x72602628 // paddub    $a0, $s3, $zero
    .word 0x14400037 // bnez       $v0, .L00145194
    .word 0x00000000 // nop
  // .L001450BC:
    .word 0x8E630004 // lw         $v1, 0x4($s3)
    .word 0x8462000E // lh         $v0, 0xE($v1)
    .word 0x14560033 // bne        $v0, $s6, .L00145194
    .word 0x00000000 // nop
    .word 0x8462003E // lh         $v0, 0x3E($v1)
    .word 0xC6610030 // lwc1       $f1, 0x30($s3)
    .word 0x44820000 // mtc1       $v0, $f0
    .word 0x00000000 // nop
    .word 0x46800020 // cvt.s.w    $f0, $f0
    .word 0x46000834 // c.lt.s     $f1, $f0
    .word 0x00000000 // nop
    .word 0x4500002A // bc1f       .L00145194
    .word 0x00000000 // nop
    .word 0x8E790000 // lw         $t9, 0x0($s3)
    .word 0x8F39009C // lw         $t9, 0x9C($t9)
    .word 0x0320F809 // jalr       $t9
    .word 0x72602628 // paddub    $a0, $s3, $zero
    .word 0x24030001 // addiu      $v1, $zero, 0x1
    .word 0x14430023 // bne        $v0, $v1, .L00145194
    .word 0x00000000 // nop
    .word 0x2402FFFF // addiu      $v0, $zero, -0x1
    .word 0x12A20005 // beq        $s5, $v0, .L00145128
    .word 0x00000000 // nop
    .word 0x8E620004 // lw         $v0, 0x4($s3)
    .word 0x84420008 // lh         $v0, 0x8($v0)
    .word 0x16A2001C // bne        $s5, $v0, .L00145194
    .word 0x00000000 // nop
  // .L00145128:
    .word 0x9262003B // lbu        $v0, 0x3B($s3)
    .word 0x14400019 // bnez       $v0, .L00145194
    .word 0x00000000 // nop
    .word 0x8E620004 // lw         $v0, 0x4($s3)
    .word 0xC6600030 // lwc1       $f0, 0x30($s3)
    .word 0x8454003E // lh         $s4, 0x3E($v0)
    .word 0x44940800 // mtc1       $s4, $f1
    .word 0x00000000 // nop
    .word 0x46800860 // cvt.s.w    $f1, $f1
    .word 0x0C048CD4 // jal        func_123350
    .word 0x46000B01 // sub.s     $f12, $f1, $f0
    .word 0x00022080 // sll        $a0, $v0, 2
    .word 0x00822021 // addu       $a0, $a0, $v0
    .word 0x00041080 // sll        $v0, $a0, 2
    .word 0x00821021 // addu       $v0, $a0, $v0
    .word 0x00141C3C // dsll32     $v1, $s4, 16
    .word 0x00031C3F // dsra32     $v1, $v1, 16
    .word 0x00021080 // sll        $v0, $v0, 2
    .word 0x14600002 // bnez       $v1, .L0014517C
    .word 0x0043001A // div       $zero, $v0, $v1
    .word 0x000001CD // break      0, 7
  // .L0014517C:
    .word 0x00001012 // mflo       $v0
    .word 0x0222082A // slt        $at, $s1, $v0
    .word 0x10200003 // beqz       $at, .L00145194
    .word 0x00000000 // nop
    .word 0x72608628 // paddub     $s0, $s3, $zero
    .word 0x70408E28 // paddub     $s1, $v0, $zero
  // .L00145194:
    .word 0x26520001 // addiu      $s2, $s2, 0x1
  // .L00145198:
    .word 0x8EE200B4 // lw         $v0, 0xB4($s7)
    .word 0x0242102A // slt        $v0, $s2, $v0
    .word 0x1440FF9E // bnez       $v0, .L0014501C
    .word 0x00000000 // nop
    .word 0x72001628 // paddub     $v0, $s0, $zero
    .word 0x7BBF0090 // lq         $ra, 0x90($sp)
    .word 0x7BBE0080 // lq         $fp, 0x80($sp)
    .word 0x7BB70070 // lq         $s7, 0x70($sp)
    .word 0x7BB60060 // lq         $s6, 0x60($sp)
    .word 0x7BB50050 // lq         $s5, 0x50($sp)
    .word 0x7BB40040 // lq         $s4, 0x40($sp)
    .word 0x7BB30030 // lq         $s3, 0x30($sp)
    .word 0x7BB20020 // lq         $s2, 0x20($sp)
    .word 0x7BB10010 // lq         $s1, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD00A0 // addiu     $sp, $sp, 0xA0
    .set reorder
    .set at
}

asm void func_001451E0(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x70001628 // paddub    $v0, $zero, $zero
    .set reorder
    .set at
}

asm void func_001451F0(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFE0 // addiu      $sp, $sp, -0x20
    .word 0x3C02004D // lui        $v0, (0x4D0000 >> 16)
    .word 0x7FBF0010 // sq         $ra, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .set reorder
    .set at
}

asm void func_00145200(void) {
    .set noreorder
    .set noat
    .word 0x24427888 // addiu      $v0, $v0, 0x7888
    .word 0xAC820000 // sw         $v0, 0x0($a0)
    .word 0x70808628 // paddub     $s0, $a0, $zero
    .word 0x10A00006 // beqz       $a1, .L00145228
    .word 0xAC860004 // sw        $a2, 0x4($a0)
    .word 0x26040008 // addiu      $a0, $s0, 0x8
    jal func_0011B170
    .word 0x2406003F // addiu     $a2, $zero, 0x3F
    .word 0x10000006 // b          .L0014523C
    .word 0x72001628 // paddub    $v0, $s0, $zero
  // .L00145228:
    .word 0x3C020049 // lui        $v0, %hi(D_490FEC)
    .word 0x26040008 // addiu      $a0, $s0, 0x8
    jal func_0011ABBC
    .word 0x24450FEC // addiu     $a1, $v0, %lo(D_490FEC)
    .word 0x72001628 // paddub     $v0, $s0, $zero
  // .L0014523C:
    .word 0x7BBF0010 // lq         $ra, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0020 // addiu     $sp, $sp, 0x20
    .set reorder
    .set at
}

asm void func_00145250(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFE0 // addiu      $sp, $sp, -0x20
    .word 0x7FBF0010 // sq         $ra, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0x70808628 // paddub     $s0, $a0, $zero
    .set reorder
    .set at
}

asm void func_00145260(void) {
    .set noreorder
    .set noat
    .word 0x1200000A // beqz       $s0, .L0014528C
    .word 0x72001628 // paddub    $v0, $s0, $zero
    .word 0x3C03004D // lui        $v1, %hi(D_4D7888)
    .word 0x0005143C // dsll32     $v0, $a1, 16
    .word 0x24637888 // addiu      $v1, $v1, %lo(D_4D7888)
    .word 0x0002143F // dsra32     $v0, $v0, 16
    .word 0x18400003 // blez       $v0, .L00145288
    .word 0xAE030000 // sw        $v1, 0x0($s0)
    jal func_00100670
    .word 0x00000000 // nop
  // .L00145288:
    .word 0x72001628 // paddub     $v0, $s0, $zero
  // .L0014528C:
    .word 0x7BBF0010 // lq         $ra, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0020 // addiu     $sp, $sp, 0x20
    .set reorder
    .set at
}

asm void func_001452A0(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFD0 // addiu      $sp, $sp, -0x30
    .word 0x7FBF0010 // sq         $ra, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0x3C02004D // lui        $v0, %hi(D_4D7840)
  // alabel func_001452B0
    .word 0x24437840 // addiu      $v1, $v0, %lo(D_4D7840)
    .word 0xAFA4002C // sw         $a0, 0x2C($sp)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0x70E08628 // paddub     $s0, $a3, $zero
    .word 0xAC430000 // sw         $v1, 0x0($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0x0C051480 // jal        func_00145200
    .word 0x24440004 // addiu     $a0, $v0, 0x4
    .word 0x8FA5002C // lw         $a1, 0x2C($sp)
    .word 0x3C020049 // lui        $v0, %hi(D_490FF0)
    .word 0x24040005 // addiu      $a0, $zero, 0x5
    .word 0x24030032 // addiu      $v1, $zero, 0x32
    .word 0xACB0004C // sw         $s0, 0x4C($a1)
    .word 0x24450FF0 // addiu      $a1, $v0, %lo(D_490FF0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC440050 // sw         $a0, 0x50($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC430054 // sw         $v1, 0x54($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC400058 // sw         $zero, 0x58($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC40005C // sw         $zero, 0x5C($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC400060 // sw         $zero, 0x60($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC400064 // sw         $zero, 0x64($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0xAC4000A8 // sw         $zero, 0xA8($v0)
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0x0C046AEF // jal        func_0011ABBC
    .word 0x24440068 // addiu     $a0, $v0, 0x68
    .word 0x8FA2002C // lw         $v0, 0x2C($sp)
    .word 0x7BBF0010 // lq         $ra, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0030 // addiu     $sp, $sp, 0x30
    .set reorder
    .set at
}

asm void func_00145340(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFD0 // addiu      $sp, $sp, -0x30
    .word 0x7FBF0020 // sq         $ra, 0x20($sp)
    .word 0x7FB10010 // sq         $s1, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
  // alabel func_00145350
    .word 0x70808E28 // paddub     $s1, $a0, $zero
    .word 0x1220000D // beqz       $s1, .L0014538C
    .word 0x70A08628 // paddub    $s0, $a1, $zero
    .word 0x3C02004D // lui        $v0, %hi(D_4D7840)
    .word 0x24427840 // addiu      $v0, $v0, %lo(D_4D7840)
    .word 0x26240004 // addiu      $a0, $s1, 0x4
    .word 0x2405FFFF // addiu      $a1, $zero, -0x1
    .word 0x0C051498 // jal        func_00145260
    .word 0xAE220000 // sw        $v0, 0x0($s1)
    .word 0x0010143C // dsll32     $v0, $s0, 16
    .word 0x0002143F // dsra32     $v0, $v0, 16
    .word 0x18400004 // blez       $v0, .L00145390
    .word 0x72201628 // paddub    $v0, $s1, $zero
    .word 0x0C04019C // jal        func_00100670
    .word 0x72202628 // paddub    $a0, $s1, $zero
  // .L0014538C:
    .word 0x72201628 // paddub     $v0, $s1, $zero
  // .L00145390:
    .word 0x7BBF0020 // lq         $ra, 0x20($sp)
    .word 0x7BB10010 // lq         $s1, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0030 // addiu     $sp, $sp, 0x30
    .set reorder
    .set at
}

asm void func_001453B0(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFF0 // addiu      $sp, $sp, -0x10
    .word 0x7FBF0000 // sq         $ra, 0x0($sp)
    .word 0x10C00007 // beqz       $a2, .L001453D8
    .word 0xAC85004C // sw        $a1, 0x4C($a0)
    .word 0x70C02E28 // paddub     $a1, $a2, $zero
    .word 0x24840068 // addiu      $a0, $a0, 0x68
    jal func_0011B170
    .word 0x2406003F // addiu     $a2, $zero, 0x3F
    .word 0x10000006 // b          .L001453EC
    .word 0x7BBF0000 // lq        $ra, 0x0($sp)
  // .L001453D8:
    .word 0x3C020049 // lui        $v0, %hi(D_490FF0)
    .word 0x24840068 // addiu      $a0, $a0, 0x68
    jal func_0011ABBC
    .word 0x24450FF0 // addiu     $a1, $v0, %lo(D_490FF0)
    .word 0x7BBF0000 // lq         $ra, 0x0($sp)
  // .L001453EC:
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0010 // addiu     $sp, $sp, 0x10
    .set reorder
    .set at
}

asm void func_00145400(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x8C820060 // lw        $v0, 0x60($a0)
    .set reorder
    .set at
}

asm void func_00145410(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00145420(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00145430(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x8C820064 // lw        $v0, 0x64($a0)
    .set reorder
    .set at
}

asm void func_00145440(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0xAC850064 // sw        $a1, 0x64($a0)
    .set reorder
    .set at
}

asm void func_00145450(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00145460(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00145470(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x70001628 // paddub    $v0, $zero, $zero
    .set reorder
    .set at
}

asm void func_00145480(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x70001628 // paddub    $v0, $zero, $zero
    .set reorder
    .set at
}

asm void func_00145490(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_001454A0(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x70001628 // paddub    $v0, $zero, $zero
    .set reorder
    .set at
}

asm void func_001454B0(void) {
    .set noreorder
    .set noat
    .word 0x8F858608 // lw         $a1, -0x79F8($gp)
    .word 0x27BDFFC0 // addiu      $sp, $sp, -0x40
    .word 0x2403FFFF // addiu      $v1, $zero, -0x1
    .word 0xFFA60010 // sd         $a2, 0x10($sp)
  // alabel func_001454C0
    .word 0xFFA70018 // sd         $a3, 0x18($sp)
    .word 0xFFA80020 // sd         $t0, 0x20($sp)
    .word 0xFFA90028 // sd         $t1, 0x28($sp)
    .word 0xFFAA0030 // sd         $t2, 0x30($sp)
    .word 0x10A30003 // beq        $a1, $v1, .L001454E0
    .word 0xFFAB0038 // sd        $t3, 0x38($sp)
    .word 0x8C83004C // lw         $v1, 0x4C($a0)
    .word 0x00000000 // nop
  // .L001454E0:
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0040 // addiu     $sp, $sp, 0x40
    .set reorder
    .set at
}

asm void func_001454F0(void) {
    .set noreorder
    .set noat
    .word 0x3C02004D // lui        $v0, %hi(D_4D7898)
    .word 0x24427898 // addiu      $v0, $v0, %lo(D_4D7898)
    .word 0xAC820000 // sw         $v0, 0x0($a0)
    .word 0xAC800004 // sw         $zero, 0x4($a0)
    .word 0xAC800008 // sw         $zero, 0x8($a0)
    .word 0xAC85006C // sw         $a1, 0x6C($a0)
    .word 0x2403FFFF // addiu      $v1, $zero, -0x1
    .word 0x10000007 // b          .L0014552C
    .word 0x70002E28 // paddub    $a1, $zero, $zero
    .word 0x00051080 // sll        $v0, $a1, 2
  // .L00145518:
    .word 0x00821021 // addu       $v0, $a0, $v0
    .word 0xAC40000C // sw         $zero, 0xC($v0)
    .word 0xAC43002C // sw         $v1, 0x2C($v0)
    .word 0x24A50001 // addiu      $a1, $a1, 0x1
    .word 0xAC43004C // sw         $v1, 0x4C($v0)
  // .L0014552C:
    .word 0x8C82006C // lw         $v0, 0x6C($a0)
    .word 0x00A2082A // slt        $at, $a1, $v0
    .word 0x1020000E // beqz       $at, .L00145570
    .word 0x28A20008 // slti      $v0, $a1, 0x8
    .word 0x28A20008 // slti       $v0, $a1, 0x8
    .word 0x1440FFF5 // bnez       $v0, .L00145518
    .word 0x00051080 // sll       $v0, $a1, 2
    .word 0x10000008 // b          .L0014556C
    .word 0x00000000 // nop
    .word 0x00051080 // sll        $v0, $a1, 2
  // .L00145554:
    .word 0x2403FFFF // addiu      $v1, $zero, -0x1
    .word 0x00821021 // addu       $v0, $a0, $v0
    .word 0xAC43000C // sw         $v1, 0xC($v0)
    .word 0xAC43002C // sw         $v1, 0x2C($v0)
    .word 0x24A50001 // addiu      $a1, $a1, 0x1
    .word 0xAC43004C // sw         $v1, 0x4C($v0)
  // .L0014556C:
    .word 0x28A20008 // slti       $v0, $a1, 0x8
  // .L00145570:
    .word 0x1440FFF8 // bnez       $v0, .L00145554
    .word 0x00051080 // sll       $v0, $a1, 2
    .word 0x03E00008 // jr         $ra
    .word 0x70801628 // paddub    $v0, $a0, $zero
    .set reorder
    .set at
}

asm void func_00145580(void) {
    .set noreorder
    .set noat
    .word 0x27BDFFE0 // addiu      $sp, $sp, -0x20
    .word 0x7FBF0010 // sq         $ra, 0x10($sp)
    .word 0x7FB00000 // sq         $s0, 0x0($sp)
    .word 0x70808628 // paddub     $s0, $a0, $zero
    .word 0x1200000C // beqz       $s0, .L001455C4
    .word 0x72001628 // paddub    $v0, $s0, $zero
    .word 0x3C03004D // lui        $v1, %hi(D_4D7898)
    .word 0x24637898 // addiu      $v1, $v1, %lo(D_4D7898)
    .word 0x0005143C // dsll32     $v0, $a1, 16
    .word 0xAE030000 // sw         $v1, 0x0($s0)
    .word 0xAE000008 // sw         $zero, 0x8($s0)
    .word 0x0002143F // dsra32     $v0, $v0, 16
    .word 0x18400003 // blez       $v0, .L001455C0
    .word 0xAE000004 // sw        $zero, 0x4($s0)
    jal func_00100670
    .word 0x00000000 // nop
  // .L001455C0:
    .word 0x72001628 // paddub     $v0, $s0, $zero
  // .L001455C4:
    .word 0x7BBF0010 // lq         $ra, 0x10($sp)
    .word 0x7BB00000 // lq         $s0, 0x0($sp)
    .word 0x03E00008 // jr         $ra
    .word 0x27BD0020 // addiu     $sp, $sp, 0x20
    .set reorder
    .set at
}

asm void func_001455E0(void) {
    .set noreorder
    .set noat
    .word 0x04A00006 // bltz       $a1, .L001455FC
    .word 0x2402FFFF // addiu     $v0, $zero, -0x1
    .word 0x8C82006C // lw         $v0, 0x6C($a0)
    .word 0x00A2102A // slt        $v0, $a1, $v0
    .word 0x14400005 // bnez       $v0, .L00145608
    .word 0x00051080 // sll       $v0, $a1, 2
    .word 0x2402FFFF // addiu      $v0, $zero, -0x1
  // .L001455FC:
    .word 0x10000005 // b          .L00145614
    .word 0x00000000 // nop
    .word 0x00051080 // sll        $v0, $a1, 2
  // .L00145608:
    .word 0x00441021 // addu       $v0, $v0, $a0
    .word 0x8C42000C // lw         $v0, 0xC($v0)
    .word 0x00000000 // nop
  // .L00145614:
    .word 0x03E00008 // jr         $ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00145620(void) {
    .set noreorder
    .set noat
    .word 0x04A0000B // bltz       $a1, .L00145650
    .word 0x00000000 // nop
    .word 0x8C83006C // lw         $v1, 0x6C($a0)
    .word 0x00A3182A // slt        $v1, $a1, $v1
    .word 0x14600003 // bnez       $v1, .L00145640
    .word 0x00051880 // sll       $v1, $a1, 2
    .word 0x10000005 // b          .L00145650
    .word 0x00000000 // nop
  // .L00145640:
    .word 0x00642021 // addu       $a0, $v1, $a0
    .word 0x8C83000C // lw         $v1, 0xC($a0)
    .word 0x00661821 // addu       $v1, $v1, $a2
    .word 0xAC83000C // sw         $v1, 0xC($a0)
  // .L00145650:
    .word 0x03E00008 // jr         $ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00145660(void) {
    .set noreorder
    .set noat
    .word 0x03E00008 // jr         $ra
    .word 0x8C82006C // lw        $v0, 0x6C($a0)
    .set reorder
    .set at
}

asm void func_00145670(void) {
    .set noreorder
    .set noat
    .word 0x2403FFFF // addiu      $v1, $zero, -0x1
    .word 0xA4830000 // sh         $v1, 0x0($a0)
    .word 0xA4830002 // sh         $v1, 0x2($a0)
    .word 0xA0800004 // sb         $zero, 0x4($a0)
  // alabel func_145680
    .word 0xA0800005 // sb         $zero, 0x5($a0)
    .word 0xA0800006 // sb         $zero, 0x6($a0)
    .word 0xA0800007 // sb         $zero, 0x7($a0)
    .word 0x1000000C // b          .L001456C0
    .word 0x70002E28 // paddub    $a1, $zero, $zero
    .word 0x00051080 // sll        $v0, $a1, 2
  // .L00145698:
    .word 0x00451021 // addu       $v0, $v0, $a1
    .word 0x00021080 // sll        $v0, $v0, 2
    .word 0x00821021 // addu       $v0, $a0, $v0
    .word 0xA4400008 // sh         $zero, 0x8($v0)
    .word 0xA443000A // sh         $v1, 0xA($v0)
    .word 0xAC40000C // sw         $zero, 0xC($v0)
    .word 0xAC400010 // sw         $zero, 0x10($v0)
    .word 0xAC400014 // sw         $zero, 0x14($v0)
    .word 0x24A50001 // addiu      $a1, $a1, 0x1
    .word 0xAC400018 // sw         $zero, 0x18($v0)
  // .L001456C0:
    .word 0x28A20010 // slti       $v0, $a1, 0x10
    .word 0x1440FFF4 // bnez       $v0, .L00145698
    .word 0x00051080 // sll       $v0, $a1, 2
    .set reorder
    .set at
}

}
