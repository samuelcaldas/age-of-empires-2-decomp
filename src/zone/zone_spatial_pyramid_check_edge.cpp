#pragma exceptions off

#include "zone_spatial_pyramid_check_edge.h"

#if defined(__mips__)

extern "C" asm int func_001D4440(void *self, void *node, int *out_x, int *out_y) {
    .word 0x27BDFFE0 /* 001D4440: addiu      $sp, $sp, -0x20 */
    .word 0x7FBF0010 /* 001D4444: sq         $ra, 0x10($sp) */
    .word 0x7FB00000 /* 001D4448: sq         $s0, 0x0($sp) */
    .word 0x8CA30024 /* 001D444C: lw         $v1, 0x24($a1) */
    .word 0x14600003 /* 001D4450: bnez       $v1, .L001D4460 */
    .word 0x70001628 /* 001D4454: paddub    $v0, $zero, $zero */
    .word 0x10000112 /* 001D4458: b          .L001D48A4 */
    .word 0x7BBF0010 /* 001D445C: lq        $ra, 0x10($sp) */
    .word 0x8CAF000C /* 001D4460: lw         $t7, 0xC($a1) */
    .word 0x8C6E000C /* 001D4464: lw         $t6, 0xC($v1) */
    .word 0x90AC0028 /* 001D4468: lbu        $t4, 0x28($a1) */
    .word 0x2419FFFF /* 001D446C: addiu      $t9, $zero, -0x1 */
    .word 0x01CF082A /* 001D4470: slt        $at, $t6, $t7 */
    .word 0x14200005 /* 001D4474: bnez       $at, .L001D448C */
    .word 0x7320FE28 /* 001D4478: paddub    $ra, $t9, $zero */
    .word 0x8CA20004 /* 001D447C: lw         $v0, 0x4($a1) */
    .word 0x8CA30008 /* 001D4480: lw         $v1, 0x8($a1) */
    .word 0x10000004 /* 001D4484: b          .L001D4498 */
    .word 0x71E07628 /* 001D4488: paddub    $t6, $t7, $zero */
    .word 0x8C620004 /* 001D448C: lw         $v0, 0x4($v1) */
    .word 0x8C630008 /* 001D4490: lw         $v1, 0x8($v1) */
    .word 0x00000000 /* 001D4494: nop */
    .word 0x319800FF /* 001D4498: andi       $t8, $t4, 0xFF */
    .word 0x240C0001 /* 001D449C: addiu      $t4, $zero, 0x1 */
    .word 0x010A4023 /* 001D44A0: subu       $t0, $t0, $t2 */
    .word 0x130C0004 /* 001D44A4: beq        $t8, $t4, .L001D44B8 */
    .word 0x012B4823 /* 001D44A8: subu      $t1, $t1, $t3 */
    .word 0x240C0008 /* 001D44AC: addiu      $t4, $zero, 0x8 */
    .word 0x170C002A /* 001D44B0: bne        $t8, $t4, .L001D455C */
    .word 0x00000000 /* 001D44B4: nop */
    .word 0x8CB90008 /* 001D44B8: lw         $t9, 0x8($a1) */
    .word 0x24430001 /* 001D44BC: addiu      $v1, $v0, 0x1 */
    .word 0x8C9000EC /* 001D44C0: lw         $s0, 0xEC($a0) */
    .word 0x01C31804 /* 001D44C4: sllv       $v1, $v1, $t6 */
    .word 0x246CFFFF /* 001D44C8: addiu      $t4, $v1, -0x1 */
    .word 0x27230001 /* 001D44CC: addiu      $v1, $t9, 0x1 */
    .word 0x01C22804 /* 001D44D0: sllv       $a1, $v0, $t6 */
    .word 0x01E31804 /* 001D44D4: sllv       $v1, $v1, $t7 */
    .word 0x246EFFFF /* 001D44D8: addiu      $t6, $v1, -0x1 */
    .word 0x020C082A /* 001D44DC: slt        $at, $s0, $t4 */
    .word 0x10200002 /* 001D44E0: beqz       $at, .L001D44EC */
    .word 0x01F96804 /* 001D44E4: sllv      $t5, $t9, $t7 */
    .word 0x72006628 /* 001D44E8: paddub     $t4, $s0, $zero */
    .word 0x8C8300F0 /* 001D44EC: lw         $v1, 0xF0($a0) */
    .word 0x006E082A /* 001D44F0: slt        $at, $v1, $t6 */
    .word 0x50200003 /* 001D44F4: beql       $at, $zero, .L001D4504 */
    .word 0x24030001 /* 001D44F8: addiu     $v1, $zero, 0x1 */
    .word 0x70607628 /* 001D44FC: paddub     $t6, $v1, $zero */
    .word 0x24030001 /* 001D4500: addiu      $v1, $zero, 0x1 */
    .word 0x17030006 /* 001D4504: bne        $t8, $v1, .L001D4520 */
    .word 0x01CB082A /* 001D4508: slt       $at, $t6, $t3 */
    .word 0x016D082A /* 001D450C: slt        $at, $t3, $t5 */
    .word 0x01AB5823 /* 001D4510: subu       $t3, $t5, $t3 */
    .word 0x71A01E28 /* 001D4514: paddub     $v1, $t5, $zero */
    .word 0x10000004 /* 001D4518: b          .L001D452C */
    .word 0x0001580B /* 001D451C: movn      $t3, $zero, $at */
    .word 0x01CB5823 /* 001D4520: subu       $t3, $t6, $t3 */
    .word 0x71C01E28 /* 001D4524: paddub     $v1, $t6, $zero */
    .word 0x0001580B /* 001D4528: movn       $t3, $zero, $at */
    .word 0x11600003 /* 001D452C: beqz       $t3, .L001D453C */
    .word 0x7140CE28 /* 001D4530: paddub    $t9, $t2, $zero */
    .word 0x55200003 /* 001D4534: bnel       $t1, $zero, .L001D4544 */
    .word 0x010B4018 /* 001D4538: mult      $t0, $t0, $t3 */
    .word 0x10000027 /* 001D453C: b          .L001D45DC */
    .word 0x24080001 /* 001D4540: addiu     $t0, $zero, 0x1 */
    .word 0x15200002 /* 001D4544: bnez       $t1, .L001D4550 */
    .word 0x0109001A /* 001D4548: div       $zero, $t0, $t1 */
    .word 0x000001CD /* 001D454C: break      0, 7 */
    .word 0x00004012 /* 001D4550: mflo       $t0 */
    .word 0x10000020 /* 001D4554: b          .L001D45D8 */
    .word 0x0148C821 /* 001D4558: addu      $t9, $t2, $t0 */
    .word 0x8CAC0004 /* 001D455C: lw         $t4, 0x4($a1) */
    .word 0x24620001 /* 001D4560: addiu      $v0, $v1, 0x1 */
    .word 0x01C36804 /* 001D4564: sllv       $t5, $v1, $t6 */
    .word 0x01C21004 /* 001D4568: sllv       $v0, $v0, $t6 */
    .word 0x244EFFFF /* 001D456C: addiu      $t6, $v0, -0x1 */
    .word 0x25820001 /* 001D4570: addiu      $v0, $t4, 0x1 */
    .word 0x01EC2804 /* 001D4574: sllv       $a1, $t4, $t7 */
    .word 0x01E21004 /* 001D4578: sllv       $v0, $v0, $t7 */
    .word 0x244CFFFF /* 001D457C: addiu      $t4, $v0, -0x1 */
    .word 0x24020002 /* 001D4580: addiu      $v0, $zero, 0x2 */
    .word 0x17020006 /* 001D4584: bne        $t8, $v0, .L001D45A0 */
    .word 0x018A082A /* 001D4588: slt       $at, $t4, $t2 */
    .word 0x0145082A /* 001D458C: slt        $at, $t2, $a1 */
    .word 0x00AA5023 /* 001D4590: subu       $t2, $a1, $t2 */
    .word 0x70A01628 /* 001D4594: paddub     $v0, $a1, $zero */
    .word 0x10000004 /* 001D4598: b          .L001D45AC */
    .word 0x0001500B /* 001D459C: movn      $t2, $zero, $at */
    .word 0x018A5023 /* 001D45A0: subu       $t2, $t4, $t2 */
    .word 0x71801628 /* 001D45A4: paddub     $v0, $t4, $zero */
    .word 0x0001500B /* 001D45A8: movn       $t2, $zero, $at */
    .word 0x11400003 /* 001D45AC: beqz       $t2, .L001D45BC */
    .word 0x7160FE28 /* 001D45B0: paddub    $ra, $t3, $zero */
    .word 0x55000003 /* 001D45B4: bnel       $t0, $zero, .L001D45C4 */
    .word 0x012A4818 /* 001D45B8: mult      $t1, $t1, $t2 */
    .word 0x10000006 /* 001D45BC: b          .L001D45D8 */
    .word 0x00000000 /* 001D45C0: nop */
    .word 0x15000002 /* 001D45C4: bnez       $t0, .L001D45D0 */
    .word 0x0128001A /* 001D45C8: div       $zero, $t1, $t0 */
    .word 0x000001CD /* 001D45CC: break      0, 7 */
    .word 0x00004012 /* 001D45D0: mflo       $t0 */
    .word 0x0168F821 /* 001D45D4: addu       $ra, $t3, $t0 */
    .word 0x24080001 /* 001D45D8: addiu      $t0, $zero, 0x1 */
    .word 0x53080005 /* 001D45DC: beql       $t8, $t0, .L001D45F4 */
    .word 0x2402FFFF /* 001D45E0: addiu     $v0, $zero, -0x1 */
    .word 0x24080008 /* 001D45E4: addiu      $t0, $zero, 0x8 */
    .word 0x57080057 /* 001D45E8: bnel       $t8, $t0, .L001D4748 */
    .word 0x2403FFFF /* 001D45EC: addiu     $v1, $zero, -0x1 */
    .word 0x2402FFFF /* 001D45F0: addiu      $v0, $zero, -0x1 */
    .word 0x00B9082A /* 001D45F4: slt        $at, $a1, $t9 */
    .word 0x14200014 /* 001D45F8: bnez       $at, .L001D464C */
    .word 0x032C402A /* 001D45FC: slt       $t0, $t9, $t4 */
    .word 0x1000000D /* 001D4600: b          .L001D4638 */
    .word 0x00035040 /* 001D4604: sll       $t2, $v1, 1 */
    .word 0x8C880000 /* 001D4608: lw         $t0, 0x0($a0) */
    .word 0x00054880 /* 001D460C: sll        $t1, $a1, 2 */
    .word 0x8D080000 /* 001D4610: lw         $t0, 0x0($t0) */
    .word 0x01094021 /* 001D4614: addu       $t0, $t0, $t1 */
    .word 0x8D080000 /* 001D4618: lw         $t0, 0x0($t0) */
    .word 0x01484021 /* 001D461C: addu       $t0, $t2, $t0 */
    .word 0x91080000 /* 001D4620: lbu        $t0, 0x0($t0) */
    .word 0x03084024 /* 001D4624: and        $t0, $t8, $t0 */
    .word 0x51000003 /* 001D4628: beql       $t0, $zero, .L001D4638 */
    .word 0x24A50001 /* 001D462C: addiu     $a1, $a1, 0x1 */
    .word 0x10000098 /* 001D4630: b          .L001D4894 */
    .word 0x70A01628 /* 001D4634: paddub    $v0, $a1, $zero */
    .word 0x0185082A /* 001D4638: slt        $at, $t4, $a1 */
    .word 0x1020FFF2 /* 001D463C: beqz       $at, .L001D4608 */
    .word 0x00000000 /* 001D4640: nop */
    .word 0x10000094 /* 001D4644: b          .L001D4898 */
    .word 0xACC20000 /* 001D4648: sw        $v0, 0x0($a2) */
    .word 0x15000014 /* 001D464C: bnez       $t0, .L001D46A0 */
    .word 0x3C080001 /* 001D4650: lui       $t0, (0x1869F >> 16) */
    .word 0x1000000D /* 001D4654: b          .L001D468C */
    .word 0x00035040 /* 001D4658: sll       $t2, $v1, 1 */
    .word 0x8C880000 /* 001D465C: lw         $t0, 0x0($a0) */
    .word 0x000C4880 /* 001D4660: sll        $t1, $t4, 2 */
    .word 0x8D080000 /* 001D4664: lw         $t0, 0x0($t0) */
    .word 0x01094021 /* 001D4668: addu       $t0, $t0, $t1 */
    .word 0x8D080000 /* 001D466C: lw         $t0, 0x0($t0) */
    .word 0x01484021 /* 001D4670: addu       $t0, $t2, $t0 */
    .word 0x91080000 /* 001D4674: lbu        $t0, 0x0($t0) */
    .word 0x03084024 /* 001D4678: and        $t0, $t8, $t0 */
    .word 0x51000003 /* 001D467C: beql       $t0, $zero, .L001D468C */
    .word 0x258CFFFF /* 001D4680: addiu     $t4, $t4, -0x1 */
    .word 0x10000083 /* 001D4684: b          .L001D4894 */
    .word 0x71801628 /* 001D4688: paddub    $v0, $t4, $zero */
    .word 0x0185082A /* 001D468C: slt        $at, $t4, $a1 */
    .word 0x1020FFF2 /* 001D4690: beqz       $at, .L001D465C */
    .word 0x00000000 /* 001D4694: nop */
    .word 0x1000007E /* 001D4698: b          .L001D4894 */
    .word 0x00000000 /* 001D469C: nop */
    .word 0x3508869F /* 001D46A0: ori        $t0, $t0, (0x1869F & 0xFFFF) */
    .word 0x73206E28 /* 001D46A4: paddub     $t5, $t9, $zero */
    .word 0x1000000E /* 001D46A8: b          .L001D46E4 */
    .word 0x00034840 /* 001D46AC: sll       $t1, $v1, 1 */
    .word 0x8C8A0000 /* 001D46B0: lw         $t2, 0x0($a0) */
    .word 0x000D5880 /* 001D46B4: sll        $t3, $t5, 2 */
    .word 0x8D4A0000 /* 001D46B8: lw         $t2, 0x0($t2) */
    .word 0x014B5021 /* 001D46BC: addu       $t2, $t2, $t3 */
    .word 0x8D4A0000 /* 001D46C0: lw         $t2, 0x0($t2) */
    .word 0x012A5021 /* 001D46C4: addu       $t2, $t1, $t2 */
    .word 0x914A0000 /* 001D46C8: lbu        $t2, 0x0($t2) */
    .word 0x030A5024 /* 001D46CC: and        $t2, $t8, $t2 */
    .word 0x51400004 /* 001D46D0: beql       $t2, $zero, .L001D46E4 */
    .word 0x25AD0001 /* 001D46D4: addiu     $t5, $t5, 0x1 */
    .word 0x71A01628 /* 001D46D8: paddub     $v0, $t5, $zero */
    .word 0x10000004 /* 001D46DC: b          .L001D46F0 */
    .word 0x01B94023 /* 001D46E0: subu      $t0, $t5, $t9 */
    .word 0x018D082A /* 001D46E4: slt        $at, $t4, $t5 */
    .word 0x1020FFF1 /* 001D46E8: beqz       $at, .L001D46B0 */
    .word 0x00000000 /* 001D46EC: nop */
    .word 0x1000000F /* 001D46F0: b          .L001D4730 */
    .word 0x0325502A /* 001D46F4: slt       $t2, $t9, $a1 */
    .word 0x8C8A0000 /* 001D46F8: lw         $t2, 0x0($a0) */
    .word 0x00195880 /* 001D46FC: sll        $t3, $t9, 2 */
    .word 0x8D4A0000 /* 001D4700: lw         $t2, 0x0($t2) */
    .word 0x014B5021 /* 001D4704: addu       $t2, $t2, $t3 */
    .word 0x8D4A0000 /* 001D4708: lw         $t2, 0x0($t2) */
    .word 0x012A5021 /* 001D470C: addu       $t2, $t1, $t2 */
    .word 0x914A0000 /* 001D4710: lbu        $t2, 0x0($t2) */
    .word 0x030A5024 /* 001D4714: and        $t2, $t8, $t2 */
    .word 0x51400003 /* 001D4718: beql       $t2, $zero, .L001D4728 */
    .word 0x2739FFFF /* 001D471C: addiu     $t9, $t9, -0x1 */
    .word 0x1000005C /* 001D4720: b          .L001D4894 */
    .word 0x73201628 /* 001D4724: paddub    $v0, $t9, $zero */
    .word 0x2508FFFF /* 001D4728: addiu      $t0, $t0, -0x1 */
    .word 0x0325502A /* 001D472C: slt        $t2, $t9, $a1 */
    .word 0x15400058 /* 001D4730: bnez       $t2, .L001D4894 */
    .word 0x00000000 /* 001D4734: nop */
    .word 0x1D00FFEF /* 001D4738: bgtz       $t0, .L001D46F8 */
    .word 0x00000000 /* 001D473C: nop */
    .word 0x10000054 /* 001D4740: b          .L001D4894 */
    .word 0x00000000 /* 001D4744: nop */
    .word 0x01BF082A /* 001D4748: slt        $at, $t5, $ra */
    .word 0x14200014 /* 001D474C: bnez       $at, .L001D47A0 */
    .word 0x03EE282A /* 001D4750: slt       $a1, $ra, $t6 */
    .word 0x1000000D /* 001D4754: b          .L001D478C */
    .word 0x00024880 /* 001D4758: sll       $t1, $v0, 2 */
    .word 0x8C850000 /* 001D475C: lw         $a1, 0x0($a0) */
    .word 0x000D4040 /* 001D4760: sll        $t0, $t5, 1 */
    .word 0x8CA50000 /* 001D4764: lw         $a1, 0x0($a1) */
    .word 0x00A92821 /* 001D4768: addu       $a1, $a1, $t1 */
    .word 0x8CA50000 /* 001D476C: lw         $a1, 0x0($a1) */
    .word 0x00A82821 /* 001D4770: addu       $a1, $a1, $t0 */
    .word 0x90A50000 /* 001D4774: lbu        $a1, 0x0($a1) */
    .word 0x03052824 /* 001D4778: and        $a1, $t8, $a1 */
    .word 0x50A00003 /* 001D477C: beql       $a1, $zero, .L001D478C */
    .word 0x25AD0001 /* 001D4780: addiu     $t5, $t5, 0x1 */
    .word 0x10000043 /* 001D4784: b          .L001D4894 */
    .word 0x71A01E28 /* 001D4788: paddub    $v1, $t5, $zero */
    .word 0x01CD082A /* 001D478C: slt        $at, $t6, $t5 */
    .word 0x1020FFF2 /* 001D4790: beqz       $at, .L001D475C */
    .word 0x00000000 /* 001D4794: nop */
    .word 0x1000003E /* 001D4798: b          .L001D4894 */
    .word 0x00000000 /* 001D479C: nop */
    .word 0x14A00014 /* 001D47A0: bnez       $a1, .L001D47F4 */
    .word 0x3C050001 /* 001D47A4: lui       $a1, (0x1869F >> 16) */
    .word 0x1000000D /* 001D47A8: b          .L001D47E0 */
    .word 0x00024880 /* 001D47AC: sll       $t1, $v0, 2 */
    .word 0x8C850000 /* 001D47B0: lw         $a1, 0x0($a0) */
    .word 0x000E4040 /* 001D47B4: sll        $t0, $t6, 1 */
    .word 0x8CA50000 /* 001D47B8: lw         $a1, 0x0($a1) */
    .word 0x00A92821 /* 001D47BC: addu       $a1, $a1, $t1 */
    .word 0x8CA50000 /* 001D47C0: lw         $a1, 0x0($a1) */
    .word 0x00A82821 /* 001D47C4: addu       $a1, $a1, $t0 */
    .word 0x90A50000 /* 001D47C8: lbu        $a1, 0x0($a1) */
    .word 0x03052824 /* 001D47CC: and        $a1, $t8, $a1 */
    .word 0x50A00003 /* 001D47D0: beql       $a1, $zero, .L001D47E0 */
    .word 0x25CEFFFF /* 001D47D4: addiu     $t6, $t6, -0x1 */
    .word 0x1000002E /* 001D47D8: b          .L001D4894 */
    .word 0x71C01E28 /* 001D47DC: paddub    $v1, $t6, $zero */
    .word 0x01CD082A /* 001D47E0: slt        $at, $t6, $t5 */
    .word 0x1020FFF2 /* 001D47E4: beqz       $at, .L001D47B0 */
    .word 0x00000000 /* 001D47E8: nop */
    .word 0x10000029 /* 001D47EC: b          .L001D4894 */
    .word 0x00000000 /* 001D47F0: nop */
    .word 0x34A5869F /* 001D47F4: ori        $a1, $a1, (0x1869F & 0xFFFF) */
    .word 0x73E05E28 /* 001D47F8: paddub     $t3, $ra, $zero */
    .word 0x1000000E /* 001D47FC: b          .L001D4838 */
    .word 0x00024080 /* 001D4800: sll       $t0, $v0, 2 */
    .word 0x8C890000 /* 001D4804: lw         $t1, 0x0($a0) */
    .word 0x000B5040 /* 001D4808: sll        $t2, $t3, 1 */
    .word 0x8D290000 /* 001D480C: lw         $t1, 0x0($t1) */
    .word 0x01284821 /* 001D4810: addu       $t1, $t1, $t0 */
    .word 0x8D290000 /* 001D4814: lw         $t1, 0x0($t1) */
    .word 0x012A4821 /* 001D4818: addu       $t1, $t1, $t2 */
    .word 0x91290000 /* 001D481C: lbu        $t1, 0x0($t1) */
    .word 0x03094824 /* 001D4820: and        $t1, $t8, $t1 */
    .word 0x51200004 /* 001D4824: beql       $t1, $zero, .L001D4838 */
    .word 0x256B0001 /* 001D4828: addiu     $t3, $t3, 0x1 */
    .word 0x71601E28 /* 001D482C: paddub     $v1, $t3, $zero */
    .word 0x10000004 /* 001D4830: b          .L001D4844 */
    .word 0x017F2823 /* 001D4834: subu      $a1, $t3, $ra */
    .word 0x01CB082A /* 001D4838: slt        $at, $t6, $t3 */
    .word 0x1020FFF1 /* 001D483C: beqz       $at, .L001D4804 */
    .word 0x00000000 /* 001D4840: nop */
    .word 0x1000000F /* 001D4844: b          .L001D4884 */
    .word 0x03ED482A /* 001D4848: slt       $t1, $ra, $t5 */
    .word 0x8C890000 /* 001D484C: lw         $t1, 0x0($a0) */
    .word 0x001F5040 /* 001D4850: sll        $t2, $ra, 1 */
    .word 0x8D290000 /* 001D4854: lw         $t1, 0x0($t1) */
    .word 0x01284821 /* 001D4858: addu       $t1, $t1, $t0 */
    .word 0x8D290000 /* 001D485C: lw         $t1, 0x0($t1) */
    .word 0x012A4821 /* 001D4860: addu       $t1, $t1, $t2 */
    .word 0x91290000 /* 001D4864: lbu        $t1, 0x0($t1) */
    .word 0x03094824 /* 001D4868: and        $t1, $t8, $t1 */
    .word 0x51200003 /* 001D486C: beql       $t1, $zero, .L001D487C */
    .word 0x27FFFFFF /* 001D4870: addiu     $ra, $ra, -0x1 */
    .word 0x10000007 /* 001D4874: b          .L001D4894 */
    .word 0x73E01E28 /* 001D4878: paddub    $v1, $ra, $zero */
    .word 0x24A5FFFF /* 001D487C: addiu      $a1, $a1, -0x1 */
    .word 0x03ED482A /* 001D4880: slt        $t1, $ra, $t5 */
    .word 0x15200003 /* 001D4884: bnez       $t1, .L001D4894 */
    .word 0x00000000 /* 001D4888: nop */
    .word 0x1CA0FFEF /* 001D488C: bgtz       $a1, .L001D484C */
    .word 0x00000000 /* 001D4890: nop */
    .word 0xACC20000 /* 001D4894: sw         $v0, 0x0($a2) */
    .word 0x24020001 /* 001D4898: addiu      $v0, $zero, 0x1 */
    .word 0xACE30000 /* 001D489C: sw         $v1, 0x0($a3) */
    .word 0x7BBF0010 /* 001D48A0: lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* 001D48A4: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D48A8: jr         $ra */
    .word 0x27BD0020 /* 001D48AC: addiu     $sp, $sp, 0x20 */
}

#else

extern "C" int func_001D4440(void *self, void *node, int *out_x, int *out_y) {
    char *n = (char *)node;
    void *parent = *(void **)(n + 0x24);
    if (!parent) {
        return 0;
    }

    char *p = (char *)parent;
    int n_lvl = *(int *)(n + 0xC);
    int p_lvl = *(int *)(p + 0xC);
    unsigned char dir = *(unsigned char *)(n + 0x28);

    int vx;
    int vy;
    int lvl;
    if (p_lvl < n_lvl) {
        vx = *(int *)(p + 0x4);
        vy = *(int *)(p + 0x8);
        lvl = p_lvl;
    } else {
        vx = *(int *)(n + 0x4);
        vy = *(int *)(n + 0x8);
        lvl = n_lvl;
    }

    int res_x = 0;
    int res_y = 0;

    int max_x = *(int *)((char *)self + 0xEC);
    int max_y = *(int *)((char *)self + 0xF0);

    if (dir == 1 || dir == 8) {
        int ny = *(int *)(n + 0x8);
        int t4 = ((vx + 1) << lvl) - 1;
        int t6 = ((ny + 1) << n_lvl) - 1;
        int a1_x = vx << lvl;
        int t5_y = ny << n_lvl;
        if (max_x < t4) t4 = max_x;
        if (max_y < t6) t6 = max_y;

        int search_y = (dir == 1) ? t5_y : t6;
        res_y = search_y;

        unsigned char ***grid_ptr = *(unsigned char ****)self;
        unsigned char **cols = grid_ptr ? *grid_ptr : 0;

        int found = 0;
        for (int x = a1_x; x <= t4; ++x) {
            if (cols && cols[x] && (cols[x][search_y * 2] & dir)) {
                res_x = x;
                found = 1;
                break;
            }
        }
        if (!found) {
            res_x = a1_x;
        }
    } else {
        int nx = *(int *)(n + 0x4);
        int t6 = ((vy + 1) << lvl) - 1;
        int t4 = ((nx + 1) << n_lvl) - 1;
        int a1_x = nx << n_lvl;
        int t5_y = vy << lvl;
        if (max_x < t4) t4 = max_x;
        if (max_y < t6) t6 = max_y;

        int search_x = (dir == 2) ? a1_x : t4;
        res_x = search_x;

        unsigned char ***grid_ptr = *(unsigned char ****)self;
        unsigned char **cols = grid_ptr ? *grid_ptr : 0;

        int found = 0;
        for (int y = t5_y; y <= t6; ++y) {
            if (cols && cols[search_x] && (cols[search_x][y * 2] & dir)) {
                res_y = y;
                found = 1;
                break;
            }
        }
        if (!found) {
            res_y = t5_y;
        }
    }

    if (out_x) *out_x = res_x;
    if (out_y) *out_y = res_y;
    return 1;
}

#endif
