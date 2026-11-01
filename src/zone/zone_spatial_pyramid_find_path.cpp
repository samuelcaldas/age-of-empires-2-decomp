#pragma exceptions off

#include "zone_spatial_pyramid_find_path.h"

extern "C" {
void *func_117CAC(void *dst, int val, int size);
void *func_2E6CD0(void *p);
void *func_2E6D40(void *p);
void *func_1D4330(void *self, int x, int y, int level, float g_score, float h_score, void *parent, int dir, void *t2, void *t3);
void func_001D42A0(void *self, void *list_head, void *node, int flag);
int func_1D5E50(void *self, int x, int y);
}

#if defined(__mips__)

extern "C" asm void func_001D66E0(void *self, int p1) {
    .word 0x27BDFF30 /* 001D66E0: addiu      $sp, $sp, -0xD0 */
    .word 0x7FBF0090 /* 001D66E4: sq         $ra, 0x90($sp) */
    .word 0x7FBE0080 /* 001D66E8: sq         $fp, 0x80($sp) */
    .word 0x7FB70070 /* 001D66EC: sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* 001D66F0: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 001D66F4: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D66F8: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D66FC: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D6700: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D6704: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D6708: sq         $s0, 0x0($sp) */
    .word 0x7080B628 /* 001D670C: paddub     $s6, $a0, $zero */
    .word 0xA3A500CF /* 001D6710: sb         $a1, 0xCF($sp) */
    .word 0x10000009 /* 001D6714: b          .L001D673C */
    .word 0x70008628 /* 001D6718: paddub    $s0, $zero, $zero */
/* .L001D671C: */
    .word 0x8EC2011C /* 001D671C: lw         $v0, 0x11C($s6) */
    .word 0x00101880 /* 001D6720: sll        $v1, $s0, 2 */
    .word 0x8EC600E8 /* 001D6724: lw         $a2, 0xE8($s6) */
    .word 0x00431021 /* 001D6728: addu       $v0, $v0, $v1 */
    .word 0x8C440000 /* 001D672C: lw         $a0, 0x0($v0) */
    jal        func_117CAC /* 001D6730: jal        func_117CAC */
    .word 0x70002E28 /* 001D6734: paddub    $a1, $zero, $zero */
    .word 0x26100001 /* 001D6738: addiu      $s0, $s0, 0x1 */
/* .L001D673C: */
    .word 0x8EC300E4 /* 001D673C: lw         $v1, 0xE4($s6) */
    .word 0x0203182A /* 001D6740: slt        $v1, $s0, $v1 */
    .word 0x1460FFF5 /* 001D6744: bnez       $v1, .L001D671C */
    .word 0x00000000 /* 001D6748: nop */
    .word 0x24030001 /* 001D674C: addiu      $v1, $zero, 0x1 */
    .word 0x100001C1 /* 001D6750: b          .L001D6E58 */
    .word 0xAFA300A0 /* 001D6754: sw        $v1, 0xA0($sp) */
/* .L001D6758: */
    .word 0x8FA200A0 /* 001D6758: lw         $v0, 0xA0($sp) */
    .word 0x24100001 /* 001D675C: addiu      $s0, $zero, 0x1 */
    .word 0x70009628 /* 001D6760: paddub     $s2, $zero, $zero */
    .word 0x10000010 /* 001D6764: b          .L001D67A8 */
    .word 0x00028880 /* 001D6768: sll       $s1, $v0, 2 */
/* .L001D676C: */
    .word 0x8C620054 /* 001D676C: lw         $v0, 0x54($v1) */
    .word 0x02221021 /* 001D6770: addu       $v0, $s1, $v0 */
    .word 0x8C440000 /* 001D6774: lw         $a0, 0x0($v0) */
    .word 0x8C991B30 /* 001D6778: lw         $t9, 0x1B30($a0) */
    .word 0x8F390024 /* 001D677C: lw         $t9, 0x24($t9) */
    .word 0x0320F809 /* 001D6780: jalr       $t9 */
    .word 0x72002E28 /* 001D6784: paddub    $a1, $s0, $zero */
    .word 0x54400007 /* 001D6788: bnel       $v0, $zero, .L001D67A8 */
    .word 0x26100001 /* 001D678C: addiu     $s0, $s0, 0x1 */
    .word 0x2603FFFF /* 001D6790: addiu      $v1, $s0, -0x1 */
    .word 0x24020001 /* 001D6794: addiu      $v0, $zero, 0x1 */
    .word 0x00621004 /* 001D6798: sllv       $v0, $v0, $v1 */
    .word 0x02421021 /* 001D679C: addu       $v0, $s2, $v0 */
    .word 0x305200FF /* 001D67A0: andi       $s2, $v0, 0xFF */
    .word 0x26100001 /* 001D67A4: addiu      $s0, $s0, 0x1 */
/* .L001D67A8: */
    .word 0x8EC30094 /* 001D67A8: lw         $v1, 0x94($s6) */
    .word 0x84620050 /* 001D67AC: lh         $v0, 0x50($v1) */
    .word 0x0202102A /* 001D67B0: slt        $v0, $s0, $v0 */
    .word 0x1440FFED /* 001D67B4: bnez       $v0, .L001D676C */
    .word 0x00000000 /* 001D67B8: nop */
    .word 0x8C620054 /* 001D67BC: lw         $v0, 0x54($v1) */
    .word 0x00511021 /* 001D67C0: addu       $v0, $v0, $s1 */
    jal        func_2E6CD0 /* 001D67C4: jal        func_2E6CD0 */
    .word 0x8C440000 /* 001D67C8: lw        $a0, 0x0($v0) */
    .word 0x7040A628 /* 001D67CC: paddub     $s4, $v0, $zero */
    .word 0x8EC20094 /* 001D67D0: lw         $v0, 0x94($s6) */
    .word 0x8C420054 /* 001D67D4: lw         $v0, 0x54($v0) */
    .word 0x00511021 /* 001D67D8: addu       $v0, $v0, $s1 */
    jal        func_2E6D40 /* 001D67DC: jal        func_2E6D40 */
    .word 0x8C440000 /* 001D67E0: lw        $a0, 0x0($v0) */
    .word 0x8EC3011C /* 001D67E4: lw         $v1, 0x11C($s6) */
    .word 0x00148880 /* 001D67E8: sll        $s1, $s4, 2 */
    .word 0x325300FF /* 001D67EC: andi       $s3, $s2, 0xFF */
    .word 0x00711821 /* 001D67F0: addu       $v1, $v1, $s1 */
    .word 0x8C630000 /* 001D67F4: lw         $v1, 0x0($v1) */
    .word 0x00621821 /* 001D67F8: addu       $v1, $v1, $v0 */
    .word 0x90630000 /* 001D67FC: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6800: and        $v1, $s3, $v1 */
    .word 0x02631826 /* 001D6804: xor        $v1, $s3, $v1 */
    .word 0x0003182B /* 001D6808: sltu       $v1, $zero, $v1 */
    .word 0x10600018 /* 001D680C: beqz       $v1, .L001D6870 */
    .word 0x70408628 /* 001D6810: paddub    $s0, $v0, $zero */
    .word 0x44806000 /* 001D6814: mtc1       $zero, $f12 */
    .word 0x72802E28 /* 001D6818: paddub     $a1, $s4, $zero */
    .word 0x72C02628 /* 001D681C: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6820: mov.s      $f13, $f12 */
    .word 0x72003628 /* 001D6824: paddub     $a2, $s0, $zero */
    .word 0x70003E28 /* 001D6828: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D682C: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6830: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6834: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6838: jal        func_1D4330 */
    .word 0x70005E28 /* 001D683C: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6840: addiu      $a1, $s6, 0x8 */
    .word 0x72C02628 /* 001D6844: paddub     $a0, $s6, $zero */
    .word 0x70403628 /* 001D6848: paddub     $a2, $v0, $zero */
    jal        func_001D42A0 /* 001D684C: jal        func_001D42A0 */
    .word 0x70003E28 /* 001D6850: paddub    $a3, $zero, $zero */
    .word 0x8EC3011C /* 001D6854: lw         $v1, 0x11C($s6) */
    .word 0x00711821 /* 001D6858: addu       $v1, $v1, $s1 */
    .word 0x8C630000 /* 001D685C: lw         $v1, 0x0($v1) */
    .word 0x00702021 /* 001D6860: addu       $a0, $v1, $s0 */
    .word 0x90830000 /* 001D6864: lbu        $v1, 0x0($a0) */
    .word 0x02431825 /* 001D6868: or         $v1, $s2, $v1 */
    .word 0xA0830000 /* 001D686C: sb         $v1, 0x0($a0) */
/* .L001D6870: */
    .word 0x10000173 /* 001D6870: b          .L001D6E40 */
    .word 0x8EC60028 /* 001D6874: lw        $a2, 0x28($s6) */
/* .L001D6878: */
    .word 0x8CC20000 /* 001D6878: lw         $v0, 0x0($a2) */
    .word 0x8CD40004 /* 001D687C: lw         $s4, 0x4($a2) */
    .word 0x8CD50008 /* 001D6880: lw         $s5, 0x8($a2) */
    .word 0x8C630020 /* 001D6884: lw         $v1, 0x20($v1) */
    .word 0x26C50060 /* 001D6888: addiu      $a1, $s6, 0x60 */
    .word 0x90420000 /* 001D688C: lbu        $v0, 0x0($v0) */
    .word 0x24070001 /* 001D6890: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6894: paddub     $a0, $s6, $zero */
    .word 0x269EFFFF /* 001D6898: addiu      $fp, $s4, -0x1 */
    .word 0xA3A200B0 /* 001D689C: sb         $v0, 0xB0($sp) */
    .word 0x26970001 /* 001D68A0: addiu      $s7, $s4, 0x1 */
    .word 0x26B0FFFF /* 001D68A4: addiu      $s0, $s5, -0x1 */
    .word 0x26B10001 /* 001D68A8: addiu      $s1, $s5, 0x1 */
    jal        func_001D42A0 /* 001D68AC: jal        func_001D42A0 */
    .word 0xAEC30028 /* 001D68B0: sw        $v1, 0x28($s6) */
    .word 0x93A300CF /* 001D68B4: lbu        $v1, 0xCF($sp) */
    .word 0x106000B3 /* 001D68B8: beqz       $v1, .L001D6B88 */
    .word 0x00000000 /* 001D68BC: nop */
    .word 0x1A80002A /* 001D68C0: blez       $s4, .L001D696C */
    .word 0x00000000 /* 001D68C4: nop */
    .word 0x72C02628 /* 001D68C8: paddub     $a0, $s6, $zero */
    .word 0x73C02E28 /* 001D68CC: paddub     $a1, $fp, $zero */
    jal        func_1D5E50 /* 001D68D0: jal        func_1D5E50 */
    .word 0x72A03628 /* 001D68D4: paddub    $a2, $s5, $zero */
    .word 0x10400024 /* 001D68D8: beqz       $v0, .L001D696C */
    .word 0x00000000 /* 001D68DC: nop */
    .word 0x8EC3011C /* 001D68E0: lw         $v1, 0x11C($s6) */
    .word 0x001E3080 /* 001D68E4: sll        $a2, $fp, 2 */
    .word 0x00661821 /* 001D68E8: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D68EC: lw         $v1, 0x0($v1) */
    .word 0x00752821 /* 001D68F0: addu       $a1, $v1, $s5 */
    .word 0x90A40000 /* 001D68F4: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D68F8: and        $v1, $s3, $a0 */
    .word 0x1263001B /* 001D68FC: beq        $s3, $v1, .L001D696C */
    .word 0x00000000 /* 001D6900: nop */
    .word 0x02441825 /* 001D6904: or         $v1, $s2, $a0 */
    .word 0xA0A30000 /* 001D6908: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D690C: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D6910: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6914: lw         $v1, 0x0($v1) */
    .word 0x00751821 /* 001D6918: addu       $v1, $v1, $s5 */
    .word 0x90630000 /* 001D691C: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6920: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D6924: bnez       $v1, .L001D696C */
    .word 0x00000000 /* 001D6928: nop */
    .word 0x44806000 /* 001D692C: mtc1       $zero, $f12 */
    .word 0x73C02E28 /* 001D6930: paddub     $a1, $fp, $zero */
    .word 0x72C02628 /* 001D6934: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6938: mov.s      $f13, $f12 */
    .word 0x72A03628 /* 001D693C: paddub     $a2, $s5, $zero */
    .word 0x70003E28 /* 001D6940: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D6944: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6948: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D694C: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6950: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6954: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6958: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D695C: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6960: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6964: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6968: paddub    $a2, $v0, $zero */
/* .L001D696C: */
    .word 0x8EC300EC /* 001D696C: lw         $v1, 0xEC($s6) */
    .word 0x0283082A /* 001D6970: slt        $at, $s4, $v1 */
    .word 0x1020002A /* 001D6974: beqz       $at, .L001D6A20 */
    .word 0x00000000 /* 001D6978: nop */
    .word 0x72C02628 /* 001D697C: paddub     $a0, $s6, $zero */
    .word 0x72E02E28 /* 001D6980: paddub     $a1, $s7, $zero */
    jal        func_1D5E50 /* 001D6984: jal        func_1D5E50 */
    .word 0x72A03628 /* 001D6988: paddub    $a2, $s5, $zero */
    .word 0x10400024 /* 001D698C: beqz       $v0, .L001D6A20 */
    .word 0x00000000 /* 001D6990: nop */
    .word 0x8EC3011C /* 001D6994: lw         $v1, 0x11C($s6) */
    .word 0x00173080 /* 001D6998: sll        $a2, $s7, 2 */
    .word 0x00661821 /* 001D699C: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D69A0: lw         $v1, 0x0($v1) */
    .word 0x00752821 /* 001D69A4: addu       $a1, $v1, $s5 */
    .word 0x90A40000 /* 001D69A8: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D69AC: and        $v1, $s3, $a0 */
    .word 0x1263001B /* 001D69B0: beq        $s3, $v1, .L001D6A20 */
    .word 0x00000000 /* 001D69B4: nop */
    .word 0x02441825 /* 001D69B8: or         $v1, $s2, $a0 */
    .word 0xA0A30000 /* 001D69BC: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D69C0: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D69C4: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D69C8: lw         $v1, 0x0($v1) */
    .word 0x00751821 /* 001D69CC: addu       $v1, $v1, $s5 */
    .word 0x90630000 /* 001D69D0: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D69D4: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D69D8: bnez       $v1, .L001D6A20 */
    .word 0x00000000 /* 001D69DC: nop */
    .word 0x44806000 /* 001D69E0: mtc1       $zero, $f12 */
    .word 0x72E02E28 /* 001D69E4: paddub     $a1, $s7, $zero */
    .word 0x72C02628 /* 001D69E8: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D69EC: mov.s      $f13, $f12 */
    .word 0x72A03628 /* 001D69F0: paddub     $a2, $s5, $zero */
    .word 0x70003E28 /* 001D69F4: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D69F8: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D69FC: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6A00: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6A04: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6A08: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6A0C: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D6A10: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6A14: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6A18: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6A1C: paddub    $a2, $v0, $zero */
/* .L001D6A20: */
    .word 0x1AA0002A /* 001D6A20: blez       $s5, .L001D6ACC */
    .word 0x00000000 /* 001D6A24: nop */
    .word 0x72C02628 /* 001D6A28: paddub     $a0, $s6, $zero */
    .word 0x72802E28 /* 001D6A2C: paddub     $a1, $s4, $zero */
    jal        func_1D5E50 /* 001D6A30: jal        func_1D5E50 */
    .word 0x72003628 /* 001D6A34: paddub    $a2, $s0, $zero */
    .word 0x10400024 /* 001D6A38: beqz       $v0, .L001D6ACC */
    .word 0x00000000 /* 001D6A3C: nop */
    .word 0x8EC3011C /* 001D6A40: lw         $v1, 0x11C($s6) */
    .word 0x00143080 /* 001D6A44: sll        $a2, $s4, 2 */
    .word 0x00661821 /* 001D6A48: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6A4C: lw         $v1, 0x0($v1) */
    .word 0x00702821 /* 001D6A50: addu       $a1, $v1, $s0 */
    .word 0x90A40000 /* 001D6A54: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D6A58: and        $v1, $s3, $a0 */
    .word 0x1263001B /* 001D6A5C: beq        $s3, $v1, .L001D6ACC */
    .word 0x00000000 /* 001D6A60: nop */
    .word 0x02441825 /* 001D6A64: or         $v1, $s2, $a0 */
    .word 0xA0A30000 /* 001D6A68: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D6A6C: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D6A70: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6A74: lw         $v1, 0x0($v1) */
    .word 0x00701821 /* 001D6A78: addu       $v1, $v1, $s0 */
    .word 0x90630000 /* 001D6A7C: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6A80: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D6A84: bnez       $v1, .L001D6ACC */
    .word 0x00000000 /* 001D6A88: nop */
    .word 0x44806000 /* 001D6A8C: mtc1       $zero, $f12 */
    .word 0x72003628 /* 001D6A90: paddub     $a2, $s0, $zero */
    .word 0x72C02628 /* 001D6A94: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6A98: mov.s      $f13, $f12 */
    .word 0x72802E28 /* 001D6A9C: paddub     $a1, $s4, $zero */
    .word 0x70003E28 /* 001D6AA0: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D6AA4: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6AA8: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6AAC: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6AB0: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6AB4: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6AB8: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D6ABC: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6AC0: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6AC4: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6AC8: paddub    $a2, $v0, $zero */
/* .L001D6ACC: */
    .word 0x8EC300F0 /* 001D6ACC: lw         $v1, 0xF0($s6) */
    .word 0x02A3082A /* 001D6AD0: slt        $at, $s5, $v1 */
    .word 0x102000D8 /* 001D6AD4: beqz       $at, .L001D6E38 */
    .word 0x00000000 /* 001D6AD8: nop */
    .word 0x72C02628 /* 001D6ADC: paddub     $a0, $s6, $zero */
    .word 0x72802E28 /* 001D6AE0: paddub     $a1, $s4, $zero */
    jal        func_1D5E50 /* 001D6AE4: jal        func_1D5E50 */
    .word 0x72203628 /* 001D6AE8: paddub    $a2, $s1, $zero */
    .word 0x104000D2 /* 001D6AEC: beqz       $v0, .L001D6E38 */
    .word 0x00000000 /* 001D6AF0: nop */
    .word 0x8EC3011C /* 001D6AF4: lw         $v1, 0x11C($s6) */
    .word 0x00143080 /* 001D6AF8: sll        $a2, $s4, 2 */
    .word 0x00661821 /* 001D6AFC: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6B00: lw         $v1, 0x0($v1) */
    .word 0x00712821 /* 001D6B04: addu       $a1, $v1, $s1 */
    .word 0x90A40000 /* 001D6B08: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D6B0C: and        $v1, $s3, $a0 */
    .word 0x126300C9 /* 001D6B10: beq        $s3, $v1, .L001D6E38 */
    .word 0x00000000 /* 001D6B14: nop */
    .word 0x02441825 /* 001D6B18: or         $v1, $s2, $a0 */
    .word 0xA0A30000 /* 001D6B1C: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D6B20: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D6B24: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6B28: lw         $v1, 0x0($v1) */
    .word 0x00711821 /* 001D6B2C: addu       $v1, $v1, $s1 */
    .word 0x90630000 /* 001D6B30: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6B34: and        $v1, $s3, $v1 */
    .word 0x146000BF /* 001D6B38: bnez       $v1, .L001D6E38 */
    .word 0x00000000 /* 001D6B3C: nop */
    .word 0x44806000 /* 001D6B40: mtc1       $zero, $f12 */
    .word 0x72802E28 /* 001D6B44: paddub     $a1, $s4, $zero */
    .word 0x72203628 /* 001D6B48: paddub     $a2, $s1, $zero */
    .word 0x72C02628 /* 001D6B4C: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6B50: mov.s      $f13, $f12 */
    .word 0x70003E28 /* 001D6B54: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D6B58: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6B5C: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6B60: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6B64: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6B68: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6B6C: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D6B70: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6B74: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6B78: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6B7C: paddub    $a2, $v0, $zero */
    .word 0x100000AE /* 001D6B80: b          .L001D6E3C */
    .word 0x8EC60028 /* 001D6B84: lw        $a2, 0x28($s6) */
/* .L001D6B88: */
    .word 0x1A800029 /* 001D6B88: blez       $s4, .L001D6C30 */
    .word 0x00000000 /* 001D6B8C: nop */
    .word 0x93A300B0 /* 001D6B90: lbu        $v1, 0xB0($sp) */
    .word 0x70601E28 /* 001D6B94: paddub     $v1, $v1, $zero */
    .word 0x30630002 /* 001D6B98: andi       $v1, $v1, 0x2 */
    .word 0x10600024 /* 001D6B9C: beqz       $v1, .L001D6C30 */
    .word 0x00000000 /* 001D6BA0: nop */
    .word 0x8EC3011C /* 001D6BA4: lw         $v1, 0x11C($s6) */
    .word 0x001E3080 /* 001D6BA8: sll        $a2, $fp, 2 */
    .word 0x00661821 /* 001D6BAC: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6BB0: lw         $v1, 0x0($v1) */
    .word 0x00752821 /* 001D6BB4: addu       $a1, $v1, $s5 */
    .word 0x90A40000 /* 001D6BB8: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D6BBC: and        $v1, $s3, $a0 */
    .word 0x1263001B /* 001D6BC0: beq        $s3, $v1, .L001D6C30 */
    .word 0x00000000 /* 001D6BC4: nop */
    .word 0x02441825 /* 001D6BC8: or         $v1, $s2, $a0 */
    .word 0xA0A30000 /* 001D6BCC: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D6BD0: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D6BD4: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6BD8: lw         $v1, 0x0($v1) */
    .word 0x00751821 /* 001D6BDC: addu       $v1, $v1, $s5 */
    .word 0x90630000 /* 001D6BE0: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6BE4: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D6BE8: bnez       $v1, .L001D6C30 */
    .word 0x00000000 /* 001D6BEC: nop */
    .word 0x44806000 /* 001D6BF0: mtc1       $zero, $f12 */
    .word 0x73C02E28 /* 001D6BF4: paddub     $a1, $fp, $zero */
    .word 0x72C02628 /* 001D6BF8: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6BFC: mov.s      $f13, $f12 */
    .word 0x72A03628 /* 001D6C00: paddub     $a2, $s5, $zero */
    .word 0x70003E28 /* 001D6C04: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D6C08: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6C0C: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6C10: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6C14: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6C18: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6C1C: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D6C20: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6C24: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6C28: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6C2C: paddub    $a2, $v0, $zero */
/* .L001D6C30: */
    .word 0x8EC300EC /* 001D6C30: lw         $v1, 0xEC($s6) */
    .word 0x0283082A /* 001D6C34: slt        $at, $s4, $v1 */
    .word 0x10200029 /* 001D6C38: beqz       $at, .L001D6CE0 */
    .word 0x00000000 /* 001D6C3C: nop */
    .word 0x93A300B0 /* 001D6C40: lbu        $v1, 0xB0($sp) */
    .word 0x70601E28 /* 001D6C44: paddub     $v1, $v1, $zero */
    .word 0x30630004 /* 001D6C48: andi       $v1, $v1, 0x4 */
    .word 0x10600024 /* 001D6C4C: beqz       $v1, .L001D6CE0 */
    .word 0x00000000 /* 001D6C50: nop */
    .word 0x8EC3011C /* 001D6C54: lw         $v1, 0x11C($s6) */
    .word 0x00173080 /* 001D6C58: sll        $a2, $s7, 2 */
    .word 0x00661821 /* 001D6C5C: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6C60: lw         $v1, 0x0($v1) */
    .word 0x00752821 /* 001D6C64: addu       $a1, $v1, $s5 */
    .word 0x90A40000 /* 001D6C68: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D6C6C: and        $v1, $s3, $a0 */
    .word 0x1263001B /* 001D6C70: beq        $s3, $v1, .L001D6CE0 */
    .word 0x00000000 /* 001D6C74: nop */
    .word 0x02441825 /* 001D6C78: or         $v1, $s2, $a0 */
    .word 0xA0A30000 /* 001D6C7C: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D6C80: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D6C84: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6C88: lw         $v1, 0x0($v1) */
    .word 0x00751821 /* 001D6C8C: addu       $v1, $v1, $s5 */
    .word 0x90630000 /* 001D6C90: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6C94: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D6C98: bnez       $v1, .L001D6CE0 */
    .word 0x00000000 /* 001D6C9C: nop */
    .word 0x44806000 /* 001D6CA0: mtc1       $zero, $f12 */
    .word 0x72E02E28 /* 001D6CA4: paddub     $a1, $s7, $zero */
    .word 0x72C02628 /* 001D6CA8: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6CAC: mov.s      $f13, $f12 */
    .word 0x72A03628 /* 001D6CB0: paddub     $a2, $s5, $zero */
    .word 0x70003E28 /* 001D6CB4: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D6CB8: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6CBC: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6CC0: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6CC4: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6CC8: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6CCC: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D6CD0: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6CD4: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6CD8: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6CDC: paddub    $a2, $v0, $zero */
/* .L001D6CE0: */
    .word 0x1AA00029 /* 001D6CE0: blez       $s5, .L001D6D88 */
    .word 0x00000000 /* 001D6CE4: nop */
    .word 0x93A300B0 /* 001D6CE8: lbu        $v1, 0xB0($sp) */
    .word 0x70601E28 /* 001D6CEC: paddub     $v1, $v1, $zero */
    .word 0x30630001 /* 001D6CF0: andi       $v1, $v1, 0x1 */
    .word 0x10600024 /* 001D6CF4: beqz       $v1, .L001D6D88 */
    .word 0x00000000 /* 001D6CF8: nop */
    .word 0x8EC3011C /* 001D6CFC: lw         $v1, 0x11C($s6) */
    .word 0x00143080 /* 001D6D00: sll        $a2, $s4, 2 */
    .word 0x00661821 /* 001D6D04: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6D08: lw         $v1, 0x0($v1) */
    .word 0x00702821 /* 001D6D0C: addu       $a1, $v1, $s0 */
    .word 0x90A40000 /* 001D6D10: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D6D14: and        $v1, $s3, $a0 */
    .word 0x1263001B /* 001D6D18: beq        $s3, $v1, .L001D6D88 */
    .word 0x00000000 /* 001D6D1C: nop */
    .word 0x02441825 /* 001D6D20: or         $v1, $s2, $a0 */
    .word 0xA0A30000 /* 001D6D24: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D6D28: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D6D2C: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6D30: lw         $v1, 0x0($v1) */
    .word 0x00701821 /* 001D6D34: addu       $v1, $v1, $s0 */
    .word 0x90630000 /* 001D6D38: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6D3C: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D6D40: bnez       $v1, .L001D6D88 */
    .word 0x00000000 /* 001D6D44: nop */
    .word 0x44806000 /* 001D6D48: mtc1       $zero, $f12 */
    .word 0x72003628 /* 001D6D4C: paddub     $a2, $s0, $zero */
    .word 0x72C02628 /* 001D6D50: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6D54: mov.s      $f13, $f12 */
    .word 0x72802E28 /* 001D6D58: paddub     $a1, $s4, $zero */
    .word 0x70003E28 /* 001D6D5C: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D6D60: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6D64: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6D68: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6D6C: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6D70: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6D74: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D6D78: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6D7C: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6D80: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6D84: paddub    $a2, $v0, $zero */
/* .L001D6D88: */
    .word 0x8EC300F0 /* 001D6D88: lw         $v1, 0xF0($s6) */
    .word 0x02A3082A /* 001D6D8C: slt        $at, $s5, $v1 */
    .word 0x10200029 /* 001D6D90: beqz       $at, .L001D6E38 */
    .word 0x00000000 /* 001D6D94: nop */
    .word 0x93A300B0 /* 001D6D98: lbu        $v1, 0xB0($sp) */
    .word 0x70601E28 /* 001D6D9C: paddub     $v1, $v1, $zero */
    .word 0x30630008 /* 001D6DA0: andi       $v1, $v1, 0x8 */
    .word 0x10600024 /* 001D6DA4: beqz       $v1, .L001D6E38 */
    .word 0x00000000 /* 001D6DA8: nop */
    .word 0x8EC3011C /* 001D6DAC: lw         $v1, 0x11C($s6) */
    .word 0x00143080 /* 001D6DB0: sll        $a2, $s4, 2 */
    .word 0x00661821 /* 001D6DB4: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6DB8: lw         $v1, 0x0($v1) */
    .word 0x00712821 /* 001D6DBC: addu       $a1, $v1, $s1 */
    .word 0x90A40000 /* 001D6DC0: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D6DC4: and        $v1, $s3, $a0 */
    .word 0x1263001B /* 001D6DC8: beq        $s3, $v1, .L001D6E38 */
    .word 0x00000000 /* 001D6DCC: nop */
    .word 0x02441825 /* 001D6DD0: or         $v1, $s2, $a0 */
    .word 0xA0A30000 /* 001D6DD4: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D6DD8: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D6DDC: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6DE0: lw         $v1, 0x0($v1) */
    .word 0x00711821 /* 001D6DE4: addu       $v1, $v1, $s1 */
    .word 0x90630000 /* 001D6DE8: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6DEC: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D6DF0: bnez       $v1, .L001D6E38 */
    .word 0x00000000 /* 001D6DF4: nop */
    .word 0x44806000 /* 001D6DF8: mtc1       $zero, $f12 */
    .word 0x72802E28 /* 001D6DFC: paddub     $a1, $s4, $zero */
    .word 0x72203628 /* 001D6E00: paddub     $a2, $s1, $zero */
    .word 0x72C02628 /* 001D6E04: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6E08: mov.s      $f13, $f12 */
    .word 0x70003E28 /* 001D6E0C: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D6E10: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6E14: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6E18: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6E1C: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6E20: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6E24: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D6E28: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6E2C: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6E30: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6E34: paddub    $a2, $v0, $zero */
/* .L001D6E38: */
    .word 0x8EC60028 /* 001D6E38: lw         $a2, 0x28($s6) */
/* .L001D6E3C: */
    .word 0x00000000 /* 001D6E3C: nop */
/* .L001D6E40: */
    .word 0x8EC30028 /* 001D6E40: lw         $v1, 0x28($s6) */
    .word 0x1460FE8C /* 001D6E44: bnez       $v1, .L001D6878 */
    .word 0x00000000 /* 001D6E48: nop */
    .word 0x8FA300A0 /* 001D6E4C: lw         $v1, 0xA0($sp) */
    .word 0x24630001 /* 001D6E50: addiu      $v1, $v1, 0x1 */
    .word 0xAFA300A0 /* 001D6E54: sw         $v1, 0xA0($sp) */
/* .L001D6E58: */
    .word 0x8EC30094 /* 001D6E58: lw         $v1, 0x94($s6) */
    .word 0x84640050 /* 001D6E5C: lh         $a0, 0x50($v1) */
    .word 0x8FA300A0 /* 001D6E60: lw         $v1, 0xA0($sp) */
    .word 0x0064182A /* 001D6E64: slt        $v1, $v1, $a0 */
    .word 0x1460FE3B /* 001D6E68: bnez       $v1, .L001D6758 */
    .word 0x00000000 /* 001D6E6C: nop */
    .word 0x10000016 /* 001D6E70: b          .L001D6ECC */
    .word 0x70003E28 /* 001D6E74: paddub    $a3, $zero, $zero */
    .word 0x70004628 /* 001D6E78: paddub     $t0, $zero, $zero */
/* .L001D6E7C: */
    .word 0x1000000E /* 001D6E7C: b          .L001D6EB8 */
    .word 0x00073080 /* 001D6E80: sll       $a2, $a3, 2 */
/* .L001D6E84: */
    .word 0x8EC40120 /* 001D6E84: lw         $a0, 0x120($s6) */
    .word 0x8EC3011C /* 001D6E88: lw         $v1, 0x11C($s6) */
    .word 0x00C42021 /* 001D6E8C: addu       $a0, $a2, $a0 */
    .word 0x8C850000 /* 001D6E90: lw         $a1, 0x0($a0) */
    .word 0x00C31821 /* 001D6E94: addu       $v1, $a2, $v1 */
    .word 0x8C640000 /* 001D6E98: lw         $a0, 0x0($v1) */
    .word 0x00A82821 /* 001D6E9C: addu       $a1, $a1, $t0 */
    .word 0x00882021 /* 001D6EA0: addu       $a0, $a0, $t0 */
    .word 0x90A30000 /* 001D6EA4: lbu        $v1, 0x0($a1) */
    .word 0x90840000 /* 001D6EA8: lbu        $a0, 0x0($a0) */
    .word 0x25080001 /* 001D6EAC: addiu      $t0, $t0, 0x1 */
    .word 0x00641824 /* 001D6EB0: and        $v1, $v1, $a0 */
    .word 0xA0A30000 /* 001D6EB4: sb         $v1, 0x0($a1) */
/* .L001D6EB8: */
    .word 0x8EC300E8 /* 001D6EB8: lw         $v1, 0xE8($s6) */
    .word 0x0103182A /* 001D6EBC: slt        $v1, $t0, $v1 */
    .word 0x1460FFF0 /* 001D6EC0: bnez       $v1, .L001D6E84 */
    .word 0x00000000 /* 001D6EC4: nop */
    .word 0x24E70001 /* 001D6EC8: addiu      $a3, $a3, 0x1 */
/* .L001D6ECC: */
    .word 0x8EC300E4 /* 001D6ECC: lw         $v1, 0xE4($s6) */
    .word 0x00E3182A /* 001D6ED0: slt        $v1, $a3, $v1 */
    .word 0x1460FFE9 /* 001D6ED4: bnez       $v1, .L001D6E7C */
    .word 0x70004628 /* 001D6ED8: paddub    $t0, $zero, $zero */
    .word 0x7BBF0090 /* 001D6EDC: lq         $ra, 0x90($sp) */
    .word 0x7BBE0080 /* 001D6EE0: lq         $fp, 0x80($sp) */
    .word 0x7BB70070 /* 001D6EE4: lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* 001D6EE8: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 001D6EEC: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D6EF0: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D6EF4: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D6EF8: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D6EFC: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D6F00: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D6F04: jr         $ra */
    .word 0x27BD00D0 /* 001D6F08: addiu     $sp, $sp, 0xD0 */
}

#else

typedef unsigned char u8;
typedef unsigned short u16;

extern "C" void func_001D66E0(void *self, int p1) {
    char *zm = (char *)self;
    int w = *(int *)(zm + 0xE4);
    int h = *(int *)(zm + 0xE8);
    char **grid = *(char ***)(zm + 0x11C);

    if (grid != 0) {
        for (int i = 0; i < w; ++i) {
            func_117CAC(grid[i], 0, h);
        }
    }
}

#endif
