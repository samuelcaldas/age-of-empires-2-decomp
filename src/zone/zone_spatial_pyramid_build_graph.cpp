#pragma exceptions off

#include "zone_spatial_pyramid_build_graph.h"

extern "C" {
void *func_117CAC(void *dst, int val, int size);
void *func_2E6CD0(void *p);
void *func_2E6D40(void *p);
void *func_1D4330(void *self, int x, int y, int level, float g_score, float h_score, void *parent, int dir, void *t2, void *t3);
void func_001D42A0(void *self, void *list_head, void *node, int flag);
int func_1D5E50(void *self, int x, int y);
}

#if defined(__mips__)

extern "C" asm void func_001D5EB0(void *self, int p1) {
    .word 0x27BDFF10 /* 001D5EB0: addiu      $sp, $sp, -0xF0 */
    .word 0x7FBF0090 /* 001D5EB4: sq         $ra, 0x90($sp) */
    .word 0x7FBE0080 /* 001D5EB8: sq         $fp, 0x80($sp) */
    .word 0x7FB70070 /* 001D5EBC: sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* 001D5EC0: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 001D5EC4: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D5EC8: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D5ECC: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D5ED0: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D5ED4: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D5ED8: sq         $s0, 0x0($sp) */
    .word 0x7080B628 /* 001D5EDC: paddub     $s6, $a0, $zero */
    .word 0xA3A500EF /* 001D5EE0: sb         $a1, 0xEF($sp) */
    .word 0x10000009 /* 001D5EE4: b          .L001D5F0C */
    .word 0x70008628 /* 001D5EE8: paddub    $s0, $zero, $zero */
/* .L001D5EEC: */
    .word 0x8EC2011C /* 001D5EEC: lw         $v0, 0x11C($s6) */
    .word 0x00101880 /* 001D5EF0: sll        $v1, $s0, 2 */
    .word 0x8EC600E8 /* 001D5EF4: lw         $a2, 0xE8($s6) */
    .word 0x00431021 /* 001D5EF8: addu       $v0, $v0, $v1 */
    .word 0x8C440000 /* 001D5EFC: lw         $a0, 0x0($v0) */
    jal        func_117CAC /* 001D5F00: jal        func_117CAC */
    .word 0x70002E28 /* 001D5F04: paddub    $a1, $zero, $zero */
    .word 0x26100001 /* 001D5F08: addiu      $s0, $s0, 0x1 */
/* .L001D5F0C: */
    .word 0x8EC300E4 /* 001D5F0C: lw         $v1, 0xE4($s6) */
    .word 0x0203182A /* 001D5F10: slt        $v1, $s0, $v1 */
    .word 0x1460FFF5 /* 001D5F14: bnez       $v1, .L001D5EEC */
    .word 0x00000000 /* 001D5F18: nop */
    .word 0x100001C1 /* 001D5F1C: b          .L001D6624 */
    .word 0x24170001 /* 001D5F20: addiu     $s7, $zero, 0x1 */
/* .L001D5F24: */
    .word 0x8C820054 /* 001D5F24: lw         $v0, 0x54($a0) */
    .word 0x00178080 /* 001D5F28: sll        $s0, $s7, 2 */
    .word 0x24030001 /* 001D5F2C: addiu      $v1, $zero, 0x1 */
    .word 0x26E4FFFF /* 001D5F30: addiu      $a0, $s7, -0x1 */
    .word 0x00831804 /* 001D5F34: sllv       $v1, $v1, $a0 */
    .word 0x00501021 /* 001D5F38: addu       $v0, $v0, $s0 */
    .word 0x8C440000 /* 001D5F3C: lw         $a0, 0x0($v0) */
    jal        func_2E6CD0 /* 001D5F40: jal        func_2E6CD0 */
    .word 0x307200FF /* 001D5F44: andi      $s2, $v1, 0xFF */
    .word 0x70408E28 /* 001D5F48: paddub     $s1, $v0, $zero */
    .word 0x8EC20094 /* 001D5F4C: lw         $v0, 0x94($s6) */
    .word 0x8C420054 /* 001D5F50: lw         $v0, 0x54($v0) */
    .word 0x00501021 /* 001D5F54: addu       $v0, $v0, $s0 */
    jal        func_2E6D40 /* 001D5F58: jal        func_2E6D40 */
    .word 0x8C440000 /* 001D5F5C: lw        $a0, 0x0($v0) */
    .word 0x44806000 /* 001D5F60: mtc1       $zero, $f12 */
    .word 0x70408628 /* 001D5F64: paddub     $s0, $v0, $zero */
    .word 0x72C02628 /* 001D5F68: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D5F6C: mov.s      $f13, $f12 */
    .word 0x72202E28 /* 001D5F70: paddub     $a1, $s1, $zero */
    .word 0x72003628 /* 001D5F74: paddub     $a2, $s0, $zero */
    .word 0x70003E28 /* 001D5F78: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D5F7C: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D5F80: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D5F84: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D5F88: jal        func_1D4330 */
    .word 0x70005E28 /* 001D5F8C: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D5F90: addiu      $a1, $s6, 0x8 */
    .word 0x72C02628 /* 001D5F94: paddub     $a0, $s6, $zero */
    .word 0x70403628 /* 001D5F98: paddub     $a2, $v0, $zero */
    jal        func_001D42A0 /* 001D5F9C: jal        func_001D42A0 */
    .word 0x70003E28 /* 001D5FA0: paddub    $a3, $zero, $zero */
    .word 0x8EC3011C /* 001D5FA4: lw         $v1, 0x11C($s6) */
    .word 0x00112080 /* 001D5FA8: sll        $a0, $s1, 2 */
    .word 0x00641821 /* 001D5FAC: addu       $v1, $v1, $a0 */
    .word 0x8C630000 /* 001D5FB0: lw         $v1, 0x0($v1) */
    .word 0x00702021 /* 001D5FB4: addu       $a0, $v1, $s0 */
    .word 0x90830000 /* 001D5FB8: lbu        $v1, 0x0($a0) */
    .word 0x00721821 /* 001D5FBC: addu       $v1, $v1, $s2 */
    .word 0xA0830000 /* 001D5FC0: sb         $v1, 0x0($a0) */
    .word 0x8EC60028 /* 001D5FC4: lw         $a2, 0x28($s6) */
    .word 0x10000192 /* 001D5FC8: b          .L001D6614 */
    .word 0x325300FF /* 001D5FCC: andi      $s3, $s2, 0xFF */
/* .L001D5FD0: */
    .word 0x8CD40004 /* 001D5FD0: lw         $s4, 0x4($a2) */
    .word 0x8CD50008 /* 001D5FD4: lw         $s5, 0x8($a2) */
    .word 0x8CC70000 /* 001D5FD8: lw         $a3, 0x0($a2) */
    .word 0x8C630020 /* 001D5FDC: lw         $v1, 0x20($v1) */
    .word 0x26C50060 /* 001D5FE0: addiu      $a1, $s6, 0x60 */
    .word 0x2682FFFF /* 001D5FE4: addiu      $v0, $s4, -0x1 */
    .word 0xAFA200A0 /* 001D5FE8: sw         $v0, 0xA0($sp) */
    .word 0x90E20000 /* 001D5FEC: lbu        $v0, 0x0($a3) */
    .word 0x72C02628 /* 001D5FF0: paddub     $a0, $s6, $zero */
    .word 0x269E0001 /* 001D5FF4: addiu      $fp, $s4, 0x1 */
    .word 0x26B0FFFF /* 001D5FF8: addiu      $s0, $s5, -0x1 */
    .word 0x24070001 /* 001D5FFC: addiu      $a3, $zero, 0x1 */
    .word 0xA3A200B0 /* 001D6000: sb         $v0, 0xB0($sp) */
    .word 0x26B10001 /* 001D6004: addiu      $s1, $s5, 0x1 */
    jal        func_001D42A0 /* 001D6008: jal        func_001D42A0 */
    .word 0xAEC30028 /* 001D600C: sw        $v1, 0x28($s6) */
    .word 0x93A300EF /* 001D6010: lbu        $v1, 0xEF($sp) */
    .word 0x106000D0 /* 001D6014: beqz       $v1, .L001D6358 */
    .word 0x00000000 /* 001D6018: nop */
    .word 0x1A800034 /* 001D601C: blez       $s4, .L001D60F0 */
    .word 0x00000000 /* 001D6020: nop */
    .word 0x8FA300A0 /* 001D6024: lw         $v1, 0xA0($sp) */
    .word 0x8EC4011C /* 001D6028: lw         $a0, 0x11C($s6) */
    .word 0x00031880 /* 001D602C: sll        $v1, $v1, 2 */
    .word 0xAFA300C0 /* 001D6030: sw         $v1, 0xC0($sp) */
    .word 0x8FA300C0 /* 001D6034: lw         $v1, 0xC0($sp) */
    .word 0x00831821 /* 001D6038: addu       $v1, $a0, $v1 */
    .word 0x8C630000 /* 001D603C: lw         $v1, 0x0($v1) */
    .word 0x00751821 /* 001D6040: addu       $v1, $v1, $s5 */
    .word 0x90630000 /* 001D6044: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6048: and        $v1, $s3, $v1 */
    .word 0x14600028 /* 001D604C: bnez       $v1, .L001D60F0 */
    .word 0x00000000 /* 001D6050: nop */
    .word 0x8FA500A0 /* 001D6054: lw         $a1, 0xA0($sp) */
    .word 0x72C02628 /* 001D6058: paddub     $a0, $s6, $zero */
    jal        func_1D5E50 /* 001D605C: jal        func_1D5E50 */
    .word 0x72A03628 /* 001D6060: paddub    $a2, $s5, $zero */
    .word 0x10400022 /* 001D6064: beqz       $v0, .L001D60F0 */
    .word 0x00000000 /* 001D6068: nop */
    .word 0x8EC4011C /* 001D606C: lw         $a0, 0x11C($s6) */
    .word 0x8FA300C0 /* 001D6070: lw         $v1, 0xC0($sp) */
    .word 0x00831821 /* 001D6074: addu       $v1, $a0, $v1 */
    .word 0x8C630000 /* 001D6078: lw         $v1, 0x0($v1) */
    .word 0x00752021 /* 001D607C: addu       $a0, $v1, $s5 */
    .word 0x90830000 /* 001D6080: lbu        $v1, 0x0($a0) */
    .word 0x00721821 /* 001D6084: addu       $v1, $v1, $s2 */
    .word 0xA0830000 /* 001D6088: sb         $v1, 0x0($a0) */
    .word 0x8EC40120 /* 001D608C: lw         $a0, 0x120($s6) */
    .word 0x8FA300C0 /* 001D6090: lw         $v1, 0xC0($sp) */
    .word 0x00831821 /* 001D6094: addu       $v1, $a0, $v1 */
    .word 0x8C630000 /* 001D6098: lw         $v1, 0x0($v1) */
    .word 0x00751821 /* 001D609C: addu       $v1, $v1, $s5 */
    .word 0x90630000 /* 001D60A0: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D60A4: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D60A8: bnez       $v1, .L001D60F0 */
    .word 0x00000000 /* 001D60AC: nop */
    .word 0x8FA500A0 /* 001D60B0: lw         $a1, 0xA0($sp) */
    .word 0x44806000 /* 001D60B4: mtc1       $zero, $f12 */
    .word 0x72C02628 /* 001D60B8: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D60BC: mov.s      $f13, $f12 */
    .word 0x72A03628 /* 001D60C0: paddub     $a2, $s5, $zero */
    .word 0x70003E28 /* 001D60C4: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D60C8: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D60CC: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D60D0: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D60D4: jal        func_1D4330 */
    .word 0x70005E28 /* 001D60D8: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D60DC: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D60E0: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D60E4: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D60E8: jal        func_001D42A0 */
    .word 0x70403628 /* 001D60EC: paddub    $a2, $v0, $zero */
/* .L001D60F0: */
    .word 0x8EC300EC /* 001D60F0: lw         $v1, 0xEC($s6) */
    .word 0x0283082A /* 001D60F4: slt        $at, $s4, $v1 */
    .word 0x10200033 /* 001D60F8: beqz       $at, .L001D61C8 */
    .word 0x00000000 /* 001D60FC: nop */
    .word 0x001E1880 /* 001D6100: sll        $v1, $fp, 2 */
    .word 0xAFA300D0 /* 001D6104: sw         $v1, 0xD0($sp) */
    .word 0x8EC4011C /* 001D6108: lw         $a0, 0x11C($s6) */
    .word 0x8FA300D0 /* 001D610C: lw         $v1, 0xD0($sp) */
    .word 0x00831821 /* 001D6110: addu       $v1, $a0, $v1 */
    .word 0x8C630000 /* 001D6114: lw         $v1, 0x0($v1) */
    .word 0x00751821 /* 001D6118: addu       $v1, $v1, $s5 */
    .word 0x90630000 /* 001D611C: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6120: and        $v1, $s3, $v1 */
    .word 0x14600028 /* 001D6124: bnez       $v1, .L001D61C8 */
    .word 0x00000000 /* 001D6128: nop */
    .word 0x72C02628 /* 001D612C: paddub     $a0, $s6, $zero */
    .word 0x73C02E28 /* 001D6130: paddub     $a1, $fp, $zero */
    jal        func_1D5E50 /* 001D6134: jal        func_1D5E50 */
    .word 0x72A03628 /* 001D6138: paddub    $a2, $s5, $zero */
    .word 0x10400022 /* 001D613C: beqz       $v0, .L001D61C8 */
    .word 0x00000000 /* 001D6140: nop */
    .word 0x8EC4011C /* 001D6144: lw         $a0, 0x11C($s6) */
    .word 0x8FA300D0 /* 001D6148: lw         $v1, 0xD0($sp) */
    .word 0x00831821 /* 001D614C: addu       $v1, $a0, $v1 */
    .word 0x8C630000 /* 001D6150: lw         $v1, 0x0($v1) */
    .word 0x00752021 /* 001D6154: addu       $a0, $v1, $s5 */
    .word 0x90830000 /* 001D6158: lbu        $v1, 0x0($a0) */
    .word 0x00721821 /* 001D615C: addu       $v1, $v1, $s2 */
    .word 0xA0830000 /* 001D6160: sb         $v1, 0x0($a0) */
    .word 0x8EC40120 /* 001D6164: lw         $a0, 0x120($s6) */
    .word 0x8FA300D0 /* 001D6168: lw         $v1, 0xD0($sp) */
    .word 0x00831821 /* 001D616C: addu       $v1, $a0, $v1 */
    .word 0x8C630000 /* 001D6170: lw         $v1, 0x0($v1) */
    .word 0x00751821 /* 001D6174: addu       $v1, $v1, $s5 */
    .word 0x90630000 /* 001D6178: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D617C: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D6180: bnez       $v1, .L001D61C8 */
    .word 0x00000000 /* 001D6184: nop */
    .word 0x44806000 /* 001D6188: mtc1       $zero, $f12 */
    .word 0x73C02E28 /* 001D618C: paddub     $a1, $fp, $zero */
    .word 0x72C02628 /* 001D6190: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6194: mov.s      $f13, $f12 */
    .word 0x72A03628 /* 001D6198: paddub     $a2, $s5, $zero */
    .word 0x70003E28 /* 001D619C: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D61A0: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D61A4: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D61A8: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D61AC: jal        func_1D4330 */
    .word 0x70005E28 /* 001D61B0: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D61B4: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D61B8: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D61BC: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D61C0: jal        func_001D42A0 */
    .word 0x70403628 /* 001D61C4: paddub    $a2, $v0, $zero */
/* .L001D61C8: */
    .word 0x1AA0002F /* 001D61C8: blez       $s5, .L001D6288 */
    .word 0x00000000 /* 001D61CC: nop */
    .word 0x8EC3011C /* 001D61D0: lw         $v1, 0x11C($s6) */
    .word 0x0014F080 /* 001D61D4: sll        $fp, $s4, 2 */
    .word 0x007E1821 /* 001D61D8: addu       $v1, $v1, $fp */
    .word 0x8C630000 /* 001D61DC: lw         $v1, 0x0($v1) */
    .word 0x00701821 /* 001D61E0: addu       $v1, $v1, $s0 */
    .word 0x90630000 /* 001D61E4: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D61E8: and        $v1, $s3, $v1 */
    .word 0x14600026 /* 001D61EC: bnez       $v1, .L001D6288 */
    .word 0x00000000 /* 001D61F0: nop */
    .word 0x72C02628 /* 001D61F4: paddub     $a0, $s6, $zero */
    .word 0x72802E28 /* 001D61F8: paddub     $a1, $s4, $zero */
    jal        func_1D5E50 /* 001D61FC: jal        func_1D5E50 */
    .word 0x72003628 /* 001D6200: paddub    $a2, $s0, $zero */
    .word 0x10400020 /* 001D6204: beqz       $v0, .L001D6288 */
    .word 0x00000000 /* 001D6208: nop */
    .word 0x8EC3011C /* 001D620C: lw         $v1, 0x11C($s6) */
    .word 0x007E1821 /* 001D6210: addu       $v1, $v1, $fp */
    .word 0x8C630000 /* 001D6214: lw         $v1, 0x0($v1) */
    .word 0x00702021 /* 001D6218: addu       $a0, $v1, $s0 */
    .word 0x90830000 /* 001D621C: lbu        $v1, 0x0($a0) */
    .word 0x00721821 /* 001D6220: addu       $v1, $v1, $s2 */
    .word 0xA0830000 /* 001D6224: sb         $v1, 0x0($a0) */
    .word 0x8EC30120 /* 001D6228: lw         $v1, 0x120($s6) */
    .word 0x007E1821 /* 001D622C: addu       $v1, $v1, $fp */
    .word 0x8C630000 /* 001D6230: lw         $v1, 0x0($v1) */
    .word 0x00701821 /* 001D6234: addu       $v1, $v1, $s0 */
    .word 0x90630000 /* 001D6238: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D623C: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D6240: bnez       $v1, .L001D6288 */
    .word 0x00000000 /* 001D6244: nop */
    .word 0x44806000 /* 001D6248: mtc1       $zero, $f12 */
    .word 0x72003628 /* 001D624C: paddub     $a2, $s0, $zero */
    .word 0x72C02628 /* 001D6250: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6254: mov.s      $f13, $f12 */
    .word 0x72802E28 /* 001D6258: paddub     $a1, $s4, $zero */
    .word 0x70003E28 /* 001D625C: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D6260: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6264: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6268: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D626C: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6270: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6274: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D6278: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D627C: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6280: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6284: paddub    $a2, $v0, $zero */
/* .L001D6288: */
    .word 0x8EC300F0 /* 001D6288: lw         $v1, 0xF0($s6) */
    .word 0x02A3082A /* 001D628C: slt        $at, $s5, $v1 */
    .word 0x102000DE /* 001D6290: beqz       $at, .L001D660C */
    .word 0x00000000 /* 001D6294: nop */
    .word 0x8EC3011C /* 001D6298: lw         $v1, 0x11C($s6) */
    .word 0x00148080 /* 001D629C: sll        $s0, $s4, 2 */
    .word 0x00701821 /* 001D62A0: addu       $v1, $v1, $s0 */
    .word 0x8C630000 /* 001D62A4: lw         $v1, 0x0($v1) */
    .word 0x00711821 /* 001D62A8: addu       $v1, $v1, $s1 */
    .word 0x90630000 /* 001D62AC: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D62B0: and        $v1, $s3, $v1 */
    .word 0x146000D5 /* 001D62B4: bnez       $v1, .L001D660C */
    .word 0x00000000 /* 001D62B8: nop */
    .word 0x72C02628 /* 001D62BC: paddub     $a0, $s6, $zero */
    .word 0x72802E28 /* 001D62C0: paddub     $a1, $s4, $zero */
    jal        func_1D5E50 /* 001D62C4: jal        func_1D5E50 */
    .word 0x72203628 /* 001D62C8: paddub    $a2, $s1, $zero */
    .word 0x104000CF /* 001D62CC: beqz       $v0, .L001D660C */
    .word 0x00000000 /* 001D62D0: nop */
    .word 0x8EC3011C /* 001D62D4: lw         $v1, 0x11C($s6) */
    .word 0x00701821 /* 001D62D8: addu       $v1, $v1, $s0 */
    .word 0x8C630000 /* 001D62DC: lw         $v1, 0x0($v1) */
    .word 0x00712021 /* 001D62E0: addu       $a0, $v1, $s1 */
    .word 0x90830000 /* 001D62E4: lbu        $v1, 0x0($a0) */
    .word 0x00721821 /* 001D62E8: addu       $v1, $v1, $s2 */
    .word 0xA0830000 /* 001D62EC: sb         $v1, 0x0($a0) */
    .word 0x8EC30120 /* 001D62F0: lw         $v1, 0x120($s6) */
    .word 0x00701821 /* 001D62F4: addu       $v1, $v1, $s0 */
    .word 0x8C630000 /* 001D62F8: lw         $v1, 0x0($v1) */
    .word 0x00711821 /* 001D62FC: addu       $v1, $v1, $s1 */
    .word 0x90630000 /* 001D6300: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6304: and        $v1, $s3, $v1 */
    .word 0x146000C0 /* 001D6308: bnez       $v1, .L001D660C */
    .word 0x00000000 /* 001D630C: nop */
    .word 0x44806000 /* 001D6310: mtc1       $zero, $f12 */
    .word 0x72802E28 /* 001D6314: paddub     $a1, $s4, $zero */
    .word 0x72203628 /* 001D6318: paddub     $a2, $s1, $zero */
    .word 0x72C02628 /* 001D631C: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6320: mov.s      $f13, $f12 */
    .word 0x70003E28 /* 001D6324: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D6328: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D632C: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6330: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6334: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6338: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D633C: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D6340: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6344: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6348: jal        func_001D42A0 */
    .word 0x70403628 /* 001D634C: paddub    $a2, $v0, $zero */
    .word 0x100000AF /* 001D6350: b          .L001D6610 */
    .word 0x8EC60028 /* 001D6354: lw        $a2, 0x28($s6) */
/* .L001D6358: */
    .word 0x1A80002A /* 001D6358: blez       $s4, .L001D6404 */
    .word 0x00000000 /* 001D635C: nop */
    .word 0x8FA300A0 /* 001D6360: lw         $v1, 0xA0($sp) */
    .word 0x00033080 /* 001D6364: sll        $a2, $v1, 2 */
    .word 0x8EC3011C /* 001D6368: lw         $v1, 0x11C($s6) */
    .word 0x00661821 /* 001D636C: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6370: lw         $v1, 0x0($v1) */
    .word 0x00752821 /* 001D6374: addu       $a1, $v1, $s5 */
    .word 0x90A40000 /* 001D6378: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D637C: and        $v1, $s3, $a0 */
    .word 0x14600020 /* 001D6380: bnez       $v1, .L001D6404 */
    .word 0x00000000 /* 001D6384: nop */
    .word 0x93A300B0 /* 001D6388: lbu        $v1, 0xB0($sp) */
    .word 0x70601E28 /* 001D638C: paddub     $v1, $v1, $zero */
    .word 0x30630002 /* 001D6390: andi       $v1, $v1, 0x2 */
    .word 0x1060001B /* 001D6394: beqz       $v1, .L001D6404 */
    .word 0x00000000 /* 001D6398: nop */
    .word 0x00921821 /* 001D639C: addu       $v1, $a0, $s2 */
    .word 0xA0A30000 /* 001D63A0: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D63A4: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D63A8: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D63AC: lw         $v1, 0x0($v1) */
    .word 0x00751821 /* 001D63B0: addu       $v1, $v1, $s5 */
    .word 0x90630000 /* 001D63B4: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D63B8: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D63BC: bnez       $v1, .L001D6404 */
    .word 0x00000000 /* 001D63C0: nop */
    .word 0x8FA500A0 /* 001D63C4: lw         $a1, 0xA0($sp) */
    .word 0x44806000 /* 001D63C8: mtc1       $zero, $f12 */
    .word 0x72C02628 /* 001D63CC: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D63D0: mov.s      $f13, $f12 */
    .word 0x72A03628 /* 001D63D4: paddub     $a2, $s5, $zero */
    .word 0x70003E28 /* 001D63D8: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D63DC: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D63E0: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D63E4: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D63E8: jal        func_1D4330 */
    .word 0x70005E28 /* 001D63EC: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D63F0: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D63F4: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D63F8: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D63FC: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6400: paddub    $a2, $v0, $zero */
/* .L001D6404: */
    .word 0x8EC300EC /* 001D6404: lw         $v1, 0xEC($s6) */
    .word 0x0283082A /* 001D6408: slt        $at, $s4, $v1 */
    .word 0x10200029 /* 001D640C: beqz       $at, .L001D64B4 */
    .word 0x00000000 /* 001D6410: nop */
    .word 0x8EC3011C /* 001D6414: lw         $v1, 0x11C($s6) */
    .word 0x001E3080 /* 001D6418: sll        $a2, $fp, 2 */
    .word 0x00661821 /* 001D641C: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6420: lw         $v1, 0x0($v1) */
    .word 0x00752821 /* 001D6424: addu       $a1, $v1, $s5 */
    .word 0x90A40000 /* 001D6428: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D642C: and        $v1, $s3, $a0 */
    .word 0x14600020 /* 001D6430: bnez       $v1, .L001D64B4 */
    .word 0x00000000 /* 001D6434: nop */
    .word 0x93A300B0 /* 001D6438: lbu        $v1, 0xB0($sp) */
    .word 0x70601E28 /* 001D643C: paddub     $v1, $v1, $zero */
    .word 0x30630004 /* 001D6440: andi       $v1, $v1, 0x4 */
    .word 0x1060001B /* 001D6444: beqz       $v1, .L001D64B4 */
    .word 0x00000000 /* 001D6448: nop */
    .word 0x00921821 /* 001D644C: addu       $v1, $a0, $s2 */
    .word 0xA0A30000 /* 001D6450: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D6454: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D6458: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D645C: lw         $v1, 0x0($v1) */
    .word 0x00751821 /* 001D6460: addu       $v1, $v1, $s5 */
    .word 0x90630000 /* 001D6464: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6468: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D646C: bnez       $v1, .L001D64B4 */
    .word 0x00000000 /* 001D6470: nop */
    .word 0x44806000 /* 001D6474: mtc1       $zero, $f12 */
    .word 0x73C02E28 /* 001D6478: paddub     $a1, $fp, $zero */
    .word 0x72C02628 /* 001D647C: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6480: mov.s      $f13, $f12 */
    .word 0x72A03628 /* 001D6484: paddub     $a2, $s5, $zero */
    .word 0x70003E28 /* 001D6488: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D648C: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6490: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D6494: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6498: jal        func_1D4330 */
    .word 0x70005E28 /* 001D649C: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D64A0: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D64A4: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D64A8: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D64AC: jal        func_001D42A0 */
    .word 0x70403628 /* 001D64B0: paddub    $a2, $v0, $zero */
/* .L001D64B4: */
    .word 0x1AA00029 /* 001D64B4: blez       $s5, .L001D655C */
    .word 0x00000000 /* 001D64B8: nop */
    .word 0x8EC3011C /* 001D64BC: lw         $v1, 0x11C($s6) */
    .word 0x00143080 /* 001D64C0: sll        $a2, $s4, 2 */
    .word 0x00661821 /* 001D64C4: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D64C8: lw         $v1, 0x0($v1) */
    .word 0x00702821 /* 001D64CC: addu       $a1, $v1, $s0 */
    .word 0x90A40000 /* 001D64D0: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D64D4: and        $v1, $s3, $a0 */
    .word 0x14600020 /* 001D64D8: bnez       $v1, .L001D655C */
    .word 0x00000000 /* 001D64DC: nop */
    .word 0x93A300B0 /* 001D64E0: lbu        $v1, 0xB0($sp) */
    .word 0x70601E28 /* 001D64E4: paddub     $v1, $v1, $zero */
    .word 0x30630001 /* 001D64E8: andi       $v1, $v1, 0x1 */
    .word 0x1060001B /* 001D64EC: beqz       $v1, .L001D655C */
    .word 0x00000000 /* 001D64F0: nop */
    .word 0x00921821 /* 001D64F4: addu       $v1, $a0, $s2 */
    .word 0xA0A30000 /* 001D64F8: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D64FC: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D6500: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6504: lw         $v1, 0x0($v1) */
    .word 0x00701821 /* 001D6508: addu       $v1, $v1, $s0 */
    .word 0x90630000 /* 001D650C: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D6510: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D6514: bnez       $v1, .L001D655C */
    .word 0x00000000 /* 001D6518: nop */
    .word 0x44806000 /* 001D651C: mtc1       $zero, $f12 */
    .word 0x72003628 /* 001D6520: paddub     $a2, $s0, $zero */
    .word 0x72C02628 /* 001D6524: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D6528: mov.s      $f13, $f12 */
    .word 0x72802E28 /* 001D652C: paddub     $a1, $s4, $zero */
    .word 0x70003E28 /* 001D6530: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D6534: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D6538: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D653C: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D6540: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6544: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D6548: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D654C: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6550: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6554: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6558: paddub    $a2, $v0, $zero */
/* .L001D655C: */
    .word 0x8EC300F0 /* 001D655C: lw         $v1, 0xF0($s6) */
    .word 0x02A3082A /* 001D6560: slt        $at, $s5, $v1 */
    .word 0x10200029 /* 001D6564: beqz       $at, .L001D660C */
    .word 0x00000000 /* 001D6568: nop */
    .word 0x8EC3011C /* 001D656C: lw         $v1, 0x11C($s6) */
    .word 0x00143080 /* 001D6570: sll        $a2, $s4, 2 */
    .word 0x00661821 /* 001D6574: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D6578: lw         $v1, 0x0($v1) */
    .word 0x00712821 /* 001D657C: addu       $a1, $v1, $s1 */
    .word 0x90A40000 /* 001D6580: lbu        $a0, 0x0($a1) */
    .word 0x02641824 /* 001D6584: and        $v1, $s3, $a0 */
    .word 0x14600020 /* 001D6588: bnez       $v1, .L001D660C */
    .word 0x00000000 /* 001D658C: nop */
    .word 0x93A300B0 /* 001D6590: lbu        $v1, 0xB0($sp) */
    .word 0x70601E28 /* 001D6594: paddub     $v1, $v1, $zero */
    .word 0x30630008 /* 001D6598: andi       $v1, $v1, 0x8 */
    .word 0x1060001B /* 001D659C: beqz       $v1, .L001D660C */
    .word 0x00000000 /* 001D65A0: nop */
    .word 0x00921821 /* 001D65A4: addu       $v1, $a0, $s2 */
    .word 0xA0A30000 /* 001D65A8: sb         $v1, 0x0($a1) */
    .word 0x8EC30120 /* 001D65AC: lw         $v1, 0x120($s6) */
    .word 0x00661821 /* 001D65B0: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* 001D65B4: lw         $v1, 0x0($v1) */
    .word 0x00711821 /* 001D65B8: addu       $v1, $v1, $s1 */
    .word 0x90630000 /* 001D65BC: lbu        $v1, 0x0($v1) */
    .word 0x02631824 /* 001D65C0: and        $v1, $s3, $v1 */
    .word 0x14600011 /* 001D65C4: bnez       $v1, .L001D660C */
    .word 0x00000000 /* 001D65C8: nop */
    .word 0x44806000 /* 001D65CC: mtc1       $zero, $f12 */
    .word 0x72802E28 /* 001D65D0: paddub     $a1, $s4, $zero */
    .word 0x72203628 /* 001D65D4: paddub     $a2, $s1, $zero */
    .word 0x72C02628 /* 001D65D8: paddub     $a0, $s6, $zero */
    .word 0x46006346 /* 001D65DC: mov.s      $f13, $f12 */
    .word 0x70003E28 /* 001D65E0: paddub     $a3, $zero, $zero */
    .word 0x70004628 /* 001D65E4: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D65E8: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D65EC: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D65F0: jal        func_1D4330 */
    .word 0x70005E28 /* 001D65F4: paddub    $t3, $zero, $zero */
    .word 0x26C50008 /* 001D65F8: addiu      $a1, $s6, 0x8 */
    .word 0x24070001 /* 001D65FC: addiu      $a3, $zero, 0x1 */
    .word 0x72C02628 /* 001D6600: paddub     $a0, $s6, $zero */
    jal        func_001D42A0 /* 001D6604: jal        func_001D42A0 */
    .word 0x70403628 /* 001D6608: paddub    $a2, $v0, $zero */
/* .L001D660C: */
    .word 0x8EC60028 /* 001D660C: lw         $a2, 0x28($s6) */
/* .L001D6610: */
    .word 0x00000000 /* 001D6610: nop */
/* .L001D6614: */
    .word 0x8EC30028 /* 001D6614: lw         $v1, 0x28($s6) */
    .word 0x1460FE6D /* 001D6618: bnez       $v1, .L001D5FD0 */
    .word 0x00000000 /* 001D661C: nop */
    .word 0x26F70001 /* 001D6620: addiu      $s7, $s7, 0x1 */
/* .L001D6624: */
    .word 0x8EC40094 /* 001D6624: lw         $a0, 0x94($s6) */
    .word 0x84830050 /* 001D6628: lh         $v1, 0x50($a0) */
    .word 0x02E3182A /* 001D662C: slt        $v1, $s7, $v1 */
    .word 0x1460FE3C /* 001D6630: bnez       $v1, .L001D5F24 */
    .word 0x00000000 /* 001D6634: nop */
    .word 0x10000016 /* 001D6638: b          .L001D6694 */
    .word 0x70003E28 /* 001D663C: paddub    $a3, $zero, $zero */
    .word 0x70004628 /* 001D6640: paddub     $t0, $zero, $zero */
/* .L001D6644: */
    .word 0x1000000E /* 001D6644: b          .L001D6680 */
    .word 0x00073080 /* 001D6648: sll       $a2, $a3, 2 */
/* .L001D664C: */
    .word 0x8EC40120 /* 001D664C: lw         $a0, 0x120($s6) */
    .word 0x8EC3011C /* 001D6650: lw         $v1, 0x11C($s6) */
    .word 0x00C42021 /* 001D6654: addu       $a0, $a2, $a0 */
    .word 0x8C850000 /* 001D6658: lw         $a1, 0x0($a0) */
    .word 0x00C31821 /* 001D665C: addu       $v1, $a2, $v1 */
    .word 0x8C640000 /* 001D6660: lw         $a0, 0x0($v1) */
    .word 0x00A82821 /* 001D6664: addu       $a1, $a1, $t0 */
    .word 0x00882021 /* 001D6668: addu       $a0, $a0, $t0 */
    .word 0x90A30000 /* 001D666C: lbu        $v1, 0x0($a1) */
    .word 0x90840000 /* 001D6670: lbu        $a0, 0x0($a0) */
    .word 0x25080001 /* 001D6674: addiu      $t0, $t0, 0x1 */
    .word 0x00641824 /* 001D6678: and        $v1, $v1, $a0 */
    .word 0xA0A30000 /* 001D667C: sb         $v1, 0x0($a1) */
/* .L001D6680: */
    .word 0x8EC300E8 /* 001D6680: lw         $v1, 0xE8($s6) */
    .word 0x0103182A /* 001D6684: slt        $v1, $t0, $v1 */
    .word 0x1460FFF0 /* 001D6688: bnez       $v1, .L001D664C */
    .word 0x00000000 /* 001D668C: nop */
    .word 0x24E70001 /* 001D6690: addiu      $a3, $a3, 0x1 */
/* .L001D6694: */
    .word 0x8EC300E4 /* 001D6694: lw         $v1, 0xE4($s6) */
    .word 0x00E3182A /* 001D6698: slt        $v1, $a3, $v1 */
    .word 0x1460FFE9 /* 001D669C: bnez       $v1, .L001D6644 */
    .word 0x70004628 /* 001D66A0: paddub    $t0, $zero, $zero */
    .word 0x7BBF0090 /* 001D66A4: lq         $ra, 0x90($sp) */
    .word 0x7BBE0080 /* 001D66A8: lq         $fp, 0x80($sp) */
    .word 0x7BB70070 /* 001D66AC: lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* 001D66B0: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 001D66B4: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D66B8: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D66BC: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D66C0: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D66C4: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D66C8: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D66CC: jr         $ra */
    .word 0x27BD00F0 /* 001D66D0: addiu     $sp, $sp, 0xF0 */
}

#else

typedef unsigned char u8;
typedef unsigned short u16;

extern "C" void func_001D5EB0(void *self, int p1) {
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
