#pragma exceptions off

#include "zone_spatial_pyramid_step_path.h"

extern "C" {
void *func_1D4330(void *self, int x, int y, int level, float g_score, float h_score, void *parent, int dir, void *t2, void *t3);
void func_001D42A0(void *self, void *list_head, void *node, int flag);
void func_001D5B00(void *self, int x, int y, void *node, int dir, int flag);
}

#if defined(__mips__)

extern "C" asm void func_001D5610(void *self, int min_x, int min_y, int max_x, int max_y, int dir, int flag, int level) {
    .word 0x27BDFF70 /* 001D5610: addiu      $sp, $sp, -0x90 */
    .word 0x7FBF0080 /* 001D5614: sq         $ra, 0x80($sp) */
    .word 0x7FB70070 /* 001D5618: sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* 001D561C: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 001D5620: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D5624: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D5628: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D562C: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D5630: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D5634: sq         $s0, 0x0($sp) */
    .word 0x8C8300E4 /* 001D5638: lw         $v1, 0xE4($a0) */
    .word 0x70E0B628 /* 001D563C: paddub     $s6, $a3, $zero */
    .word 0x7100AE28 /* 001D5640: paddub     $s5, $t0, $zero */
    .word 0x7140A628 /* 001D5644: paddub     $s4, $t2, $zero */
    .word 0x71609E28 /* 001D5648: paddub     $s3, $t3, $zero */
    .word 0x00A3082A /* 001D564C: slt        $at, $a1, $v1 */
    .word 0x102000EC /* 001D5650: beqz       $at, .L001D5A04 */
    .word 0x7080BE28 /* 001D5654: paddub    $s7, $a0, $zero */
    .word 0x06C000EA /* 001D5658: bltz       $s6, .L001D5A04 */
    .word 0x00000000 /* 001D565C: nop */
    .word 0x8EE300E8 /* 001D5660: lw         $v1, 0xE8($s7) */
    .word 0x00C3082A /* 001D5664: slt        $at, $a2, $v1 */
    .word 0x102000E6 /* 001D5668: beqz       $at, .L001D5A04 */
    .word 0x00000000 /* 001D566C: nop */
    .word 0x1EA00003 /* 001D5670: bgtz       $s5, .L001D5680 */
    .word 0x00000000 /* 001D5674: nop */
    .word 0x100000E3 /* 001D5678: b          .L001D5A08 */
    .word 0x7BBF0080 /* 001D567C: lq        $ra, 0x80($sp) */
/* .L001D5680: */
    .word 0x04A10002 /* 001D5680: bgez       $a1, .L001D568C */
    .word 0x00000000 /* 001D5684: nop */
    .word 0x70002E28 /* 001D5688: paddub     $a1, $zero, $zero */
/* .L001D568C: */
    .word 0x8EE200EC /* 001D568C: lw         $v0, 0xEC($s7) */
    .word 0x0056082A /* 001D5690: slt        $at, $v0, $s6 */
    .word 0x10200002 /* 001D5694: beqz       $at, .L001D56A0 */
    .word 0x00000000 /* 001D5698: nop */
    .word 0x7040B628 /* 001D569C: paddub     $s6, $v0, $zero */
/* .L001D56A0: */
    .word 0x04C10002 /* 001D56A0: bgez       $a2, .L001D56AC */
    .word 0x0055082A /* 001D56A4: slt       $at, $v0, $s5 */
    .word 0x70003628 /* 001D56A8: paddub     $a2, $zero, $zero */
/* .L001D56AC: */
    .word 0x10200002 /* 001D56AC: beqz       $at, .L001D56B8 */
    .word 0x00000000 /* 001D56B0: nop */
    .word 0x7040AE28 /* 001D56B4: paddub     $s5, $v0, $zero */
/* .L001D56B8: */
    .word 0xAEE500F4 /* 001D56B8: sw         $a1, 0xF4($s7) */
    .word 0xAEF600FC /* 001D56BC: sw         $s6, 0xFC($s7) */
    .word 0xAEE600F8 /* 001D56C0: sw         $a2, 0xF8($s7) */
    .word 0x24020008 /* 001D56C4: addiu      $v0, $zero, 0x8 */
    .word 0x329100FF /* 001D56C8: andi       $s1, $s4, 0xFF */
    .word 0xAEF50100 /* 001D56CC: sw         $s5, 0x100($s7) */
    .word 0x70001E28 /* 001D56D0: paddub     $v1, $zero, $zero */
    .word 0x12220012 /* 001D56D4: beq        $s1, $v0, .L001D5720 */
    .word 0x70002628 /* 001D56D8: paddub    $a0, $zero, $zero */
    .word 0x24020001 /* 001D56DC: addiu      $v0, $zero, 0x1 */
    .word 0x5222000D /* 001D56E0: beql       $s1, $v0, .L001D5718 */
    .word 0x70A01E28 /* 001D56E4: paddub    $v1, $a1, $zero */
    .word 0x24020004 /* 001D56E8: addiu      $v0, $zero, 0x4 */
    .word 0x52220008 /* 001D56EC: beql       $s1, $v0, .L001D5710 */
    .word 0x70A01E28 /* 001D56F0: paddub    $v1, $a1, $zero */
    .word 0x24020002 /* 001D56F4: addiu      $v0, $zero, 0x2 */
    .word 0x52220003 /* 001D56F8: beql       $s1, $v0, .L001D5708 */
    .word 0x70C02628 /* 001D56FC: paddub    $a0, $a2, $zero */
    .word 0x10000009 /* 001D5700: b          .L001D5728 */
    .word 0x00000000 /* 001D5704: nop */
/* .L001D5708: */
    .word 0x10000007 /* 001D5708: b          .L001D5728 */
    .word 0x72C01E28 /* 001D570C: paddub    $v1, $s6, $zero */
/* .L001D5710: */
    .word 0x10000005 /* 001D5710: b          .L001D5728 */
    .word 0x70C02628 /* 001D5714: paddub    $a0, $a2, $zero */
/* .L001D5718: */
    .word 0x10000003 /* 001D5718: b          .L001D5728 */
    .word 0x72A02628 /* 001D571C: paddub    $a0, $s5, $zero */
/* .L001D5720: */
    .word 0x70A01E28 /* 001D5720: paddub     $v1, $a1, $zero */
    .word 0x70C02628 /* 001D5724: paddub     $a0, $a2, $zero */
/* .L001D5728: */
    .word 0x44806000 /* 001D5728: mtc1       $zero, $f12 */
    .word 0x70803628 /* 001D572C: paddub     $a2, $a0, $zero */
    .word 0x70602E28 /* 001D5730: paddub     $a1, $v1, $zero */
    .word 0x72E02628 /* 001D5734: paddub     $a0, $s7, $zero */
    .word 0x46006346 /* 001D5738: mov.s      $f13, $f12 */
    .word 0x70003E28 /* 001D573C: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D5740: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D5744: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D5748: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D574C: jal        func_1D4330 */
    .word 0x70005E28 /* 001D5750: paddub    $t3, $zero, $zero */
    .word 0x8C430000 /* 001D5754: lw         $v1, 0x0($v0) */
    .word 0x70403628 /* 001D5758: paddub     $a2, $v0, $zero */
    .word 0x26E50008 /* 001D575C: addiu      $a1, $s7, 0x8 */
    .word 0x72E02628 /* 001D5760: paddub     $a0, $s7, $zero */
    .word 0x70003E28 /* 001D5764: paddub     $a3, $zero, $zero */
    .word 0x90620000 /* 001D5768: lbu        $v0, 0x0($v1) */
    .word 0x24420010 /* 001D576C: addiu      $v0, $v0, 0x10 */
    jal        func_001D42A0 /* 001D5770: jal        func_001D42A0 */
    .word 0xA0620000 /* 001D5774: sb        $v0, 0x0($v1) */
    .word 0x1000006B /* 001D5778: b          .L001D5928 */
    .word 0x70008628 /* 001D577C: paddub    $s0, $zero, $zero */
/* .L001D5780: */
    .word 0x12230018 /* 001D5780: beq        $s1, $v1, .L001D57E4 */
    .word 0x24030001 /* 001D5784: addiu     $v1, $zero, 0x1 */
    .word 0x12230011 /* 001D5788: beq        $s1, $v1, .L001D57D0 */
    .word 0x24030004 /* 001D578C: addiu     $v1, $zero, 0x4 */
    .word 0x1223000A /* 001D5790: beq        $s1, $v1, .L001D57BC */
    .word 0x24030002 /* 001D5794: addiu     $v1, $zero, 0x2 */
    .word 0x12230003 /* 001D5798: beq        $s1, $v1, .L001D57A8 */
    .word 0x00000000 /* 001D579C: nop */
    .word 0x10000014 /* 001D57A0: b          .L001D57F4 */
    .word 0x00000000 /* 001D57A4: nop */
/* .L001D57A8: */
    .word 0x8E430008 /* 001D57A8: lw         $v1, 0x8($s2) */
    .word 0x14750011 /* 001D57AC: bne        $v1, $s5, .L001D57F4 */
    .word 0x00000000 /* 001D57B0: nop */
    .word 0x1000000F /* 001D57B4: b          .L001D57F4 */
    .word 0x64100001 /* 001D57B8: daddiu    $s0, $zero, 0x1 */
/* .L001D57BC: */
    .word 0x8E430008 /* 001D57BC: lw         $v1, 0x8($s2) */
    .word 0x1475000C /* 001D57C0: bne        $v1, $s5, .L001D57F4 */
    .word 0x00000000 /* 001D57C4: nop */
    .word 0x1000000A /* 001D57C8: b          .L001D57F4 */
    .word 0x64100001 /* 001D57CC: daddiu    $s0, $zero, 0x1 */
/* .L001D57D0: */
    .word 0x8E430004 /* 001D57D0: lw         $v1, 0x4($s2) */
    .word 0x14760007 /* 001D57D4: bne        $v1, $s6, .L001D57F4 */
    .word 0x00000000 /* 001D57D8: nop */
    .word 0x10000005 /* 001D57DC: b          .L001D57F4 */
    .word 0x64100001 /* 001D57E0: daddiu    $s0, $zero, 0x1 */
/* .L001D57E4: */
    .word 0x8E430004 /* 001D57E4: lw         $v1, 0x4($s2) */
    .word 0x14760002 /* 001D57E8: bne        $v1, $s6, .L001D57F4 */
    .word 0x00000000 /* 001D57EC: nop */
    .word 0x64100001 /* 001D57F0: daddiu     $s0, $zero, 0x1 */
/* .L001D57F4: */
    .word 0x1600004F /* 001D57F4: bnez       $s0, .L001D5934 */
    .word 0x00000000 /* 001D57F8: nop */
    .word 0x8E420020 /* 001D57FC: lw         $v0, 0x20($s2) */
    .word 0x26E50034 /* 001D5800: addiu      $a1, $s7, 0x34 */
    .word 0x24070001 /* 001D5804: addiu      $a3, $zero, 0x1 */
    .word 0x72E02628 /* 001D5808: paddub     $a0, $s7, $zero */
    .word 0x72403628 /* 001D580C: paddub     $a2, $s2, $zero */
    jal        func_001D42A0 /* 001D5810: jal        func_001D42A0 */
    .word 0xAEE20028 /* 001D5814: sw        $v0, 0x28($s7) */
    .word 0x8E430004 /* 001D5818: lw         $v1, 0x4($s2) */
    .word 0x8E420008 /* 001D581C: lw         $v0, 0x8($s2) */
    .word 0x24090001 /* 001D5820: addiu      $t1, $zero, 0x1 */
    .word 0x72E02628 /* 001D5824: paddub     $a0, $s7, $zero */
    .word 0x72403E28 /* 001D5828: paddub     $a3, $s2, $zero */
    .word 0x24650001 /* 001D582C: addiu      $a1, $v1, 0x1 */
    .word 0x24460001 /* 001D5830: addiu      $a2, $v0, 0x1 */
    jal        func_001D5B00 /* 001D5834: jal        func_001D5B00 */
    .word 0x72804628 /* 001D5838: paddub    $t0, $s4, $zero */
    .word 0x8E430004 /* 001D583C: lw         $v1, 0x4($s2) */
    .word 0x8E420008 /* 001D5840: lw         $v0, 0x8($s2) */
    .word 0x24090001 /* 001D5844: addiu      $t1, $zero, 0x1 */
    .word 0x72E02628 /* 001D5848: paddub     $a0, $s7, $zero */
    .word 0x72403E28 /* 001D584C: paddub     $a3, $s2, $zero */
    .word 0x2465FFFF /* 001D5850: addiu      $a1, $v1, -0x1 */
    .word 0x24460001 /* 001D5854: addiu      $a2, $v0, 0x1 */
    jal        func_001D5B00 /* 001D5858: jal        func_001D5B00 */
    .word 0x72804628 /* 001D585C: paddub    $t0, $s4, $zero */
    .word 0x8E430004 /* 001D5860: lw         $v1, 0x4($s2) */
    .word 0x8E420008 /* 001D5864: lw         $v0, 0x8($s2) */
    .word 0x24090001 /* 001D5868: addiu      $t1, $zero, 0x1 */
    .word 0x72E02628 /* 001D586C: paddub     $a0, $s7, $zero */
    .word 0x72403E28 /* 001D5870: paddub     $a3, $s2, $zero */
    .word 0x24650001 /* 001D5874: addiu      $a1, $v1, 0x1 */
    .word 0x2446FFFF /* 001D5878: addiu      $a2, $v0, -0x1 */
    jal        func_001D5B00 /* 001D587C: jal        func_001D5B00 */
    .word 0x72804628 /* 001D5880: paddub    $t0, $s4, $zero */
    .word 0x8E430004 /* 001D5884: lw         $v1, 0x4($s2) */
    .word 0x8E420008 /* 001D5888: lw         $v0, 0x8($s2) */
    .word 0x24090001 /* 001D588C: addiu      $t1, $zero, 0x1 */
    .word 0x72E02628 /* 001D5890: paddub     $a0, $s7, $zero */
    .word 0x72403E28 /* 001D5894: paddub     $a3, $s2, $zero */
    .word 0x2465FFFF /* 001D5898: addiu      $a1, $v1, -0x1 */
    .word 0x2446FFFF /* 001D589C: addiu      $a2, $v0, -0x1 */
    jal        func_001D5B00 /* 001D58A0: jal        func_001D5B00 */
    .word 0x72804628 /* 001D58A4: paddub    $t0, $s4, $zero */
    .word 0x8E420004 /* 001D58A8: lw         $v0, 0x4($s2) */
    .word 0x8E460008 /* 001D58AC: lw         $a2, 0x8($s2) */
    .word 0x72E02628 /* 001D58B0: paddub     $a0, $s7, $zero */
    .word 0x72403E28 /* 001D58B4: paddub     $a3, $s2, $zero */
    .word 0x72804628 /* 001D58B8: paddub     $t0, $s4, $zero */
    .word 0x70004E28 /* 001D58BC: paddub     $t1, $zero, $zero */
    jal        func_001D5B00 /* 001D58C0: jal        func_001D5B00 */
    .word 0x24450001 /* 001D58C4: addiu     $a1, $v0, 0x1 */
    .word 0x8E420004 /* 001D58C8: lw         $v0, 0x4($s2) */
    .word 0x8E460008 /* 001D58CC: lw         $a2, 0x8($s2) */
    .word 0x72E02628 /* 001D58D0: paddub     $a0, $s7, $zero */
    .word 0x72403E28 /* 001D58D4: paddub     $a3, $s2, $zero */
    .word 0x72804628 /* 001D58D8: paddub     $t0, $s4, $zero */
    .word 0x70004E28 /* 001D58DC: paddub     $t1, $zero, $zero */
    jal        func_001D5B00 /* 001D58E0: jal        func_001D5B00 */
    .word 0x2445FFFF /* 001D58E4: addiu     $a1, $v0, -0x1 */
    .word 0x8E420008 /* 001D58E8: lw         $v0, 0x8($s2) */
    .word 0x8E450004 /* 001D58EC: lw         $a1, 0x4($s2) */
    .word 0x72E02628 /* 001D58F0: paddub     $a0, $s7, $zero */
    .word 0x72403E28 /* 001D58F4: paddub     $a3, $s2, $zero */
    .word 0x72804628 /* 001D58F8: paddub     $t0, $s4, $zero */
    .word 0x70004E28 /* 001D58FC: paddub     $t1, $zero, $zero */
    jal        func_001D5B00 /* 001D5900: jal        func_001D5B00 */
    .word 0x24460001 /* 001D5904: addiu     $a2, $v0, 0x1 */
    .word 0x8E420008 /* 001D5908: lw         $v0, 0x8($s2) */
    .word 0x8E450004 /* 001D590C: lw         $a1, 0x4($s2) */
    .word 0x72E02628 /* 001D5910: paddub     $a0, $s7, $zero */
    .word 0x72403E28 /* 001D5914: paddub     $a3, $s2, $zero */
    .word 0x72804628 /* 001D5918: paddub     $t0, $s4, $zero */
    .word 0x70004E28 /* 001D591C: paddub     $t1, $zero, $zero */
    jal        func_001D5B00 /* 001D5920: jal        func_001D5B00 */
    .word 0x2446FFFF /* 001D5924: addiu     $a2, $v0, -0x1 */
/* .L001D5928: */
    .word 0x8EF20028 /* 001D5928: lw         $s2, 0x28($s7) */
    .word 0x1640FF94 /* 001D592C: bnez       $s2, .L001D5780 */
    .word 0x24030008 /* 001D5930: addiu     $v1, $zero, 0x8 */
/* .L001D5934: */
    .word 0x12000020 /* 001D5934: beqz       $s0, .L001D59B8 */
    .word 0x326600FF /* 001D5938: andi      $a2, $s3, 0xFF */
    .word 0x1000000F /* 001D593C: b          .L001D597C */
    .word 0x00000000 /* 001D5940: nop */
/* .L001D5944: */
    .word 0x8E450004 /* 001D5944: lw         $a1, 0x4($s2) */
    .word 0x8EE40120 /* 001D5948: lw         $a0, 0x120($s7) */
    .word 0x8E430008 /* 001D594C: lw         $v1, 0x8($s2) */
    .word 0x00052880 /* 001D5950: sll        $a1, $a1, 2 */
    .word 0x00852021 /* 001D5954: addu       $a0, $a0, $a1 */
    .word 0x8C840000 /* 001D5958: lw         $a0, 0x0($a0) */
    .word 0x00832821 /* 001D595C: addu       $a1, $a0, $v1 */
    .word 0x90A40000 /* 001D5960: lbu        $a0, 0x0($a1) */
    .word 0x00C41824 /* 001D5964: and        $v1, $a2, $a0 */
    .word 0x14600002 /* 001D5968: bnez       $v1, .L001D5974 */
    .word 0x00931821 /* 001D596C: addu      $v1, $a0, $s3 */
    .word 0xA0A30000 /* 001D5970: sb         $v1, 0x0($a1) */
/* .L001D5974: */
    .word 0x8E520024 /* 001D5974: lw         $s2, 0x24($s2) */
    .word 0x00000000 /* 001D5978: nop */
/* .L001D597C: */
    .word 0x1640FFF1 /* 001D597C: bnez       $s2, .L001D5944 */
    .word 0x00000000 /* 001D5980: nop */
    .word 0x1000000D /* 001D5984: b          .L001D59BC */
    .word 0x8EE30028 /* 001D5988: lw        $v1, 0x28($s7) */
/* .L001D598C: */
    .word 0x8C700020 /* 001D598C: lw         $s0, 0x20($v1) */
    .word 0x26E50060 /* 001D5990: addiu      $a1, $s7, 0x60 */
    .word 0x24070001 /* 001D5994: addiu      $a3, $zero, 0x1 */
    .word 0x8C630000 /* 001D5998: lw         $v1, 0x0($v1) */
    .word 0x90620000 /* 001D599C: lbu        $v0, 0x0($v1) */
    .word 0x2442FFF0 /* 001D59A0: addiu      $v0, $v0, -0x10 */
    .word 0xA0620000 /* 001D59A4: sb         $v0, 0x0($v1) */
    .word 0x8EE60028 /* 001D59A8: lw         $a2, 0x28($s7) */
    jal        func_001D42A0 /* 001D59AC: jal        func_001D42A0 */
    .word 0x72E02628 /* 001D59B0: paddub    $a0, $s7, $zero */
    .word 0xAEF00028 /* 001D59B4: sw         $s0, 0x28($s7) */
/* .L001D59B8: */
    .word 0x8EE30028 /* 001D59B8: lw         $v1, 0x28($s7) */
/* .L001D59BC: */
    .word 0x1460FFF3 /* 001D59BC: bnez       $v1, .L001D598C */
    .word 0x00000000 /* 001D59C0: nop */
    .word 0x1000000D /* 001D59C4: b          .L001D59FC */
    .word 0x8EE30054 /* 001D59C8: lw        $v1, 0x54($s7) */
/* .L001D59CC: */
    .word 0x8C700020 /* 001D59CC: lw         $s0, 0x20($v1) */
    .word 0x26E50060 /* 001D59D0: addiu      $a1, $s7, 0x60 */
    .word 0x24070001 /* 001D59D4: addiu      $a3, $zero, 0x1 */
    .word 0x8C630000 /* 001D59D8: lw         $v1, 0x0($v1) */
    .word 0x90620000 /* 001D59DC: lbu        $v0, 0x0($v1) */
    .word 0x2442FFF0 /* 001D59E0: addiu      $v0, $v0, -0x10 */
    .word 0xA0620000 /* 001D59E4: sb         $v0, 0x0($v1) */
    .word 0x8EE60054 /* 001D59E8: lw         $a2, 0x54($s7) */
    jal        func_001D42A0 /* 001D59EC: jal        func_001D42A0 */
    .word 0x72E02628 /* 001D59F0: paddub    $a0, $s7, $zero */
    .word 0xAEF00054 /* 001D59F4: sw         $s0, 0x54($s7) */
    .word 0x8EE30054 /* 001D59F8: lw         $v1, 0x54($s7) */
/* .L001D59FC: */
    .word 0x1460FFF3 /* 001D59FC: bnez       $v1, .L001D59CC */
    .word 0x00000000 /* 001D5A00: nop */
/* .L001D5A04: */
    .word 0x7BBF0080 /* 001D5A04: lq         $ra, 0x80($sp) */
/* .L001D5A08: */
    .word 0x7BB70070 /* 001D5A08: lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* 001D5A0C: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 001D5A10: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D5A14: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D5A18: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D5A1C: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D5A20: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D5A24: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D5A28: jr         $ra */
    .word 0x27BD0090 /* 001D5A2C: addiu     $sp, $sp, 0x90 */
}

#else

typedef unsigned char u8;
typedef unsigned short u16;

extern "C" void func_001D5610(void *self, int min_x, int min_y, int max_x, int max_y, int dir, int flag, int level) {
    char *zm = (char *)self;
    int map_w = *(int *)(zm + 0xE4);
    int map_h = *(int *)(zm + 0xE8);
    int max_coord_w = *(int *)(zm + 0xEC);

    if (min_x >= map_w || max_x < 0 || min_y >= map_h || max_y <= 0) {
        return;
    }

    if (min_x < 0) min_x = 0;
    if (max_x > max_coord_w) max_x = max_coord_w;
    if (min_y < 0) min_y = 0;
    if (max_y > max_coord_w) max_y = max_coord_w;

    *(int *)(zm + 0xF4) = min_x;
    *(int *)(zm + 0xF8) = min_y;
    *(int *)(zm + 0xFC) = max_x;
    *(int *)(zm + 0x100) = max_y;

    int start_x = 0;
    int start_y = 0;
    int d = flag & 0xFF;
    if (d == 8) {
        start_x = min_x;
        start_y = min_y;
    } else if (d == 1) {
        start_x = min_x;
        start_y = max_y;
    } else if (d == 4) {
        start_x = min_x;
        start_y = min_y;
    } else if (d == 2) {
        start_x = max_x;
        start_y = min_y;
    } else {
        start_x = min_x;
        start_y = min_y;
    }

    void *root = func_1D4330(self, start_x, start_y, 0, 0.0f, 0.0f, 0, 0, 0, 0);
    func_001D42A0(self, zm + 8, root, 0);
}

#endif
