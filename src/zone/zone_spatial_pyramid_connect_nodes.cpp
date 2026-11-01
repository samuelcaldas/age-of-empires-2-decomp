#pragma exceptions off

#include "zone_spatial_pyramid_connect_nodes.h"

#if defined(__mips__)

extern "C" asm int func_001D48B0(void *self, void *node, int *out_x, int *out_y) {
    .word 0x8CA20024 /* 001D48B0: lw         $v0, 0x24($a1) */
    .word 0x14400003 /* 001D48B4: bnez       $v0, .L001D48C4 */
    .word 0x00000000 /* 001D48B8: nop */
    .word 0x100000D6 /* 001D48BC: b          .L001D4C18 */
    .word 0x70001628 /* 001D48C0: paddub    $v0, $zero, $zero */
    .word 0x8CAB000C /* 001D48C4: lw         $t3, 0xC($a1) */
    .word 0x8C4D000C /* 001D48C8: lw         $t5, 0xC($v0) */
    .word 0x90AC0028 /* 001D48CC: lbu        $t4, 0x28($a1) */
    .word 0x70001E28 /* 001D48D0: paddub     $v1, $zero, $zero */
    .word 0x70004628 /* 001D48D4: paddub     $t0, $zero, $zero */
    .word 0x70004E28 /* 001D48D8: paddub     $t1, $zero, $zero */
    .word 0x01AB082A /* 001D48DC: slt        $at, $t5, $t3 */
    .word 0x14200004 /* 001D48E0: bnez       $at, .L001D48F4 */
    .word 0x70005628 /* 001D48E4: paddub    $t2, $zero, $zero */
    .word 0x8CAF0008 /* 001D48E8: lw         $t7, 0x8($a1) */
    .word 0x10000004 /* 001D48EC: b          .L001D4900 */
    .word 0x8CAE0004 /* 001D48F0: lw        $t6, 0x4($a1) */
    .word 0x8C4E0004 /* 001D48F4: lw         $t6, 0x4($v0) */
    .word 0x8C4F0008 /* 001D48F8: lw         $t7, 0x8($v0) */
    .word 0x71A05E28 /* 001D48FC: paddub     $t3, $t5, $zero */
    .word 0x24020001 /* 001D4900: addiu      $v0, $zero, 0x1 */
    .word 0x318C00FF /* 001D4904: andi       $t4, $t4, 0xFF */
    .word 0x15820012 /* 001D4908: bne        $t4, $v0, .L001D4954 */
    .word 0x240D0008 /* 001D490C: addiu     $t5, $zero, 0x8 */
    .word 0x016E6804 /* 001D4910: sllv       $t5, $t6, $t3 */
    .word 0x19600009 /* 001D4914: blez       $t3, .L001D493C */
    .word 0xACCD0000 /* 001D4918: sw        $t5, 0x0($a2) */
    .word 0x8CC30000 /* 001D491C: lw         $v1, 0x0($a2) */
    .word 0x2568FFFF /* 001D4920: addiu      $t0, $t3, -0x1 */
    .word 0x01626804 /* 001D4924: sllv       $t5, $v0, $t3 */
    .word 0x01021004 /* 001D4928: sllv       $v0, $v0, $t0 */
    .word 0x006D4021 /* 001D492C: addu       $t0, $v1, $t5 */
    .word 0x00621021 /* 001D4930: addu       $v0, $v1, $v0 */
    .word 0x2508FFFF /* 001D4934: addiu      $t0, $t0, -0x1 */
    .word 0xACC20000 /* 001D4938: sw         $v0, 0x0($a2) */
    .word 0x8CAD0008 /* 001D493C: lw         $t5, 0x8($a1) */
    .word 0x8CA2000C /* 001D4940: lw         $v0, 0xC($a1) */
    .word 0x004D1004 /* 001D4944: sllv       $v0, $t5, $v0 */
    .word 0x1000003D /* 001D4948: b          .L001D4A40 */
    .word 0xACE20000 /* 001D494C: sw        $v0, 0x0($a3) */
    .word 0x240D0008 /* 001D4950: addiu      $t5, $zero, 0x8 */
    .word 0x158D0014 /* 001D4954: bne        $t4, $t5, .L001D49A8 */
    .word 0x240D0002 /* 001D4958: addiu     $t5, $zero, 0x2 */
    .word 0x016E6804 /* 001D495C: sllv       $t5, $t6, $t3 */
    .word 0x19600009 /* 001D4960: blez       $t3, .L001D4988 */
    .word 0xACCD0000 /* 001D4964: sw        $t5, 0x0($a2) */
    .word 0x8CC30000 /* 001D4968: lw         $v1, 0x0($a2) */
    .word 0x2568FFFF /* 001D496C: addiu      $t0, $t3, -0x1 */
    .word 0x01626804 /* 001D4970: sllv       $t5, $v0, $t3 */
    .word 0x01021004 /* 001D4974: sllv       $v0, $v0, $t0 */
    .word 0x006D4021 /* 001D4978: addu       $t0, $v1, $t5 */
    .word 0x00621021 /* 001D497C: addu       $v0, $v1, $v0 */
    .word 0x2508FFFF /* 001D4980: addiu      $t0, $t0, -0x1 */
    .word 0xACC20000 /* 001D4984: sw         $v0, 0x0($a2) */
    .word 0x8CAD0008 /* 001D4988: lw         $t5, 0x8($a1) */
    .word 0x8CA2000C /* 001D498C: lw         $v0, 0xC($a1) */
    .word 0x25A50001 /* 001D4990: addiu      $a1, $t5, 0x1 */
    .word 0x00451004 /* 001D4994: sllv       $v0, $a1, $v0 */
    .word 0x2442FFFF /* 001D4998: addiu      $v0, $v0, -0x1 */
    .word 0x10000028 /* 001D499C: b          .L001D4A40 */
    .word 0xACE20000 /* 001D49A0: sw        $v0, 0x0($a3) */
    .word 0x240D0002 /* 001D49A4: addiu      $t5, $zero, 0x2 */
    .word 0x158D0012 /* 001D49A8: bne        $t4, $t5, .L001D49F4 */
    .word 0x240D0004 /* 001D49AC: addiu     $t5, $zero, 0x4 */
    .word 0x016F6804 /* 001D49B0: sllv       $t5, $t7, $t3 */
    .word 0x19600009 /* 001D49B4: blez       $t3, .L001D49DC */
    .word 0xACED0000 /* 001D49B8: sw        $t5, 0x0($a3) */
    .word 0x8CE90000 /* 001D49BC: lw         $t1, 0x0($a3) */
    .word 0x256AFFFF /* 001D49C0: addiu      $t2, $t3, -0x1 */
    .word 0x01626804 /* 001D49C4: sllv       $t5, $v0, $t3 */
    .word 0x01421004 /* 001D49C8: sllv       $v0, $v0, $t2 */
    .word 0x012D5021 /* 001D49CC: addu       $t2, $t1, $t5 */
    .word 0x01221021 /* 001D49D0: addu       $v0, $t1, $v0 */
    .word 0x254AFFFF /* 001D49D4: addiu      $t2, $t2, -0x1 */
    .word 0xACE20000 /* 001D49D8: sw         $v0, 0x0($a3) */
    .word 0x8CAD0004 /* 001D49DC: lw         $t5, 0x4($a1) */
    .word 0x8CA2000C /* 001D49E0: lw         $v0, 0xC($a1) */
    .word 0x004D1004 /* 001D49E4: sllv       $v0, $t5, $v0 */
    .word 0x10000015 /* 001D49E8: b          .L001D4A40 */
    .word 0xACC20000 /* 001D49EC: sw        $v0, 0x0($a2) */
    .word 0x240D0004 /* 001D49F0: addiu      $t5, $zero, 0x4 */
    .word 0x158D0012 /* 001D49F4: bne        $t4, $t5, .L001D4A40 */
    .word 0x00000000 /* 001D49F8: nop */
    .word 0x016F6804 /* 001D49FC: sllv       $t5, $t7, $t3 */
    .word 0x19600009 /* 001D4A00: blez       $t3, .L001D4A28 */
    .word 0xACED0000 /* 001D4A04: sw        $t5, 0x0($a3) */
    .word 0x8CE90000 /* 001D4A08: lw         $t1, 0x0($a3) */
    .word 0x256AFFFF /* 001D4A0C: addiu      $t2, $t3, -0x1 */
    .word 0x01626804 /* 001D4A10: sllv       $t5, $v0, $t3 */
    .word 0x01421004 /* 001D4A14: sllv       $v0, $v0, $t2 */
    .word 0x012D5021 /* 001D4A18: addu       $t2, $t1, $t5 */
    .word 0x01221021 /* 001D4A1C: addu       $v0, $t1, $v0 */
    .word 0x254AFFFF /* 001D4A20: addiu      $t2, $t2, -0x1 */
    .word 0xACE20000 /* 001D4A24: sw         $v0, 0x0($a3) */
    .word 0x8CAD0004 /* 001D4A28: lw         $t5, 0x4($a1) */
    .word 0x8CA2000C /* 001D4A2C: lw         $v0, 0xC($a1) */
    .word 0x25A50001 /* 001D4A30: addiu      $a1, $t5, 0x1 */
    .word 0x00451004 /* 001D4A34: sllv       $v0, $a1, $v0 */
    .word 0x2442FFFF /* 001D4A38: addiu      $v0, $v0, -0x1 */
    .word 0xACC20000 /* 001D4A3C: sw         $v0, 0x0($a2) */
    .word 0x19600068 /* 001D4A40: blez       $t3, .L001D4BE4 */
    .word 0x00000000 /* 001D4A44: nop */
    .word 0x24020001 /* 001D4A48: addiu      $v0, $zero, 0x1 */
    .word 0x11820004 /* 001D4A4C: beq        $t4, $v0, .L001D4A60 */
    .word 0x00000000 /* 001D4A50: nop */
    .word 0x24020008 /* 001D4A54: addiu      $v0, $zero, 0x8 */
    .word 0x15820033 /* 001D4A58: bne        $t4, $v0, .L001D4B28 */
    .word 0x00000000 /* 001D4A5C: nop */
    .word 0x8CC90000 /* 001D4A60: lw         $t1, 0x0($a2) */
    .word 0x3C020001 /* 001D4A64: lui        $v0, (0x1869F >> 16) */
    .word 0x3442869F /* 001D4A68: ori        $v0, $v0, (0x1869F & 0xFFFF) */
    .word 0x71202E28 /* 001D4A6C: paddub     $a1, $t1, $zero */
    .word 0x10000011 /* 001D4A70: b          .L001D4AB8 */
    .word 0x71207E28 /* 001D4A74: paddub    $t7, $t1, $zero */
    .word 0x8C8B0000 /* 001D4A78: lw         $t3, 0x0($a0) */
    .word 0x8CEA0000 /* 001D4A7C: lw         $t2, 0x0($a3) */
    .word 0x000F7080 /* 001D4A80: sll        $t6, $t7, 2 */
    .word 0x8D6D0000 /* 001D4A84: lw         $t5, 0x0($t3) */
    .word 0x000A5840 /* 001D4A88: sll        $t3, $t2, 1 */
    .word 0x01AE5021 /* 001D4A8C: addu       $t2, $t5, $t6 */
    .word 0x8D4A0000 /* 001D4A90: lw         $t2, 0x0($t2) */
    .word 0x016A5021 /* 001D4A94: addu       $t2, $t3, $t2 */
    .word 0x914A0000 /* 001D4A98: lbu        $t2, 0x0($t2) */
    .word 0x018A5024 /* 001D4A9C: and        $t2, $t4, $t2 */
    .word 0x51400005 /* 001D4AA0: beql       $t2, $zero, .L001D4AB8 */
    .word 0x25EF0001 /* 001D4AA4: addiu     $t7, $t7, 0x1 */
    .word 0x71E02E28 /* 001D4AA8: paddub     $a1, $t7, $zero */
    .word 0x10000005 /* 001D4AAC: b          .L001D4AC4 */
    .word 0x01E91023 /* 001D4AB0: subu      $v0, $t7, $t1 */
    .word 0x25EF0001 /* 001D4AB4: addiu      $t7, $t7, 0x1 */
    .word 0x010F082A /* 001D4AB8: slt        $at, $t0, $t7 */
    .word 0x1020FFEE /* 001D4ABC: beqz       $at, .L001D4A78 */
    .word 0x00000000 /* 001D4AC0: nop */
    .word 0x10000012 /* 001D4AC4: b          .L001D4B10 */
    .word 0x0123402A /* 001D4AC8: slt       $t0, $t1, $v1 */
    .word 0x8C8A0000 /* 001D4ACC: lw         $t2, 0x0($a0) */
    .word 0x8CE80000 /* 001D4AD0: lw         $t0, 0x0($a3) */
    .word 0x00096880 /* 001D4AD4: sll        $t5, $t1, 2 */
    .word 0x8D4B0000 /* 001D4AD8: lw         $t3, 0x0($t2) */
    .word 0x00085040 /* 001D4ADC: sll        $t2, $t0, 1 */
    .word 0x016D4021 /* 001D4AE0: addu       $t0, $t3, $t5 */
    .word 0x8D080000 /* 001D4AE4: lw         $t0, 0x0($t0) */
    .word 0x01484021 /* 001D4AE8: addu       $t0, $t2, $t0 */
    .word 0x91080000 /* 001D4AEC: lbu        $t0, 0x0($t0) */
    .word 0x01884024 /* 001D4AF0: and        $t0, $t4, $t0 */
    .word 0x51000004 /* 001D4AF4: beql       $t0, $zero, .L001D4B08 */
    .word 0x2529FFFF /* 001D4AF8: addiu     $t1, $t1, -0x1 */
    .word 0x10000008 /* 001D4AFC: b          .L001D4B20 */
    .word 0x71202E28 /* 001D4B00: paddub    $a1, $t1, $zero */
    .word 0x2529FFFF /* 001D4B04: addiu      $t1, $t1, -0x1 */
    .word 0x2442FFFF /* 001D4B08: addiu      $v0, $v0, -0x1 */
    .word 0x0123402A /* 001D4B0C: slt        $t0, $t1, $v1 */
    .word 0x15000003 /* 001D4B10: bnez       $t0, .L001D4B20 */
    .word 0x00000000 /* 001D4B14: nop */
    .word 0x1C40FFEC /* 001D4B18: bgtz       $v0, .L001D4ACC */
    .word 0x00000000 /* 001D4B1C: nop */
    .word 0x10000030 /* 001D4B20: b          .L001D4BE4 */
    .word 0xACC50000 /* 001D4B24: sw        $a1, 0x0($a2) */
    .word 0x8CE50000 /* 001D4B28: lw         $a1, 0x0($a3) */
    .word 0x3C020001 /* 001D4B2C: lui        $v0, (0x1869F >> 16) */
    .word 0x3442869F /* 001D4B30: ori        $v0, $v0, (0x1869F & 0xFFFF) */
    .word 0x70A01E28 /* 001D4B34: paddub     $v1, $a1, $zero */
    .word 0x10000011 /* 001D4B38: b          .L001D4B80 */
    .word 0x70A07628 /* 001D4B3C: paddub    $t6, $a1, $zero */
    .word 0x8C880000 /* 001D4B40: lw         $t0, 0x0($a0) */
    .word 0x8CCD0000 /* 001D4B44: lw         $t5, 0x0($a2) */
    .word 0x000E5840 /* 001D4B48: sll        $t3, $t6, 1 */
    .word 0x8D080000 /* 001D4B4C: lw         $t0, 0x0($t0) */
    .word 0x000D6880 /* 001D4B50: sll        $t5, $t5, 2 */
    .word 0x010D4021 /* 001D4B54: addu       $t0, $t0, $t5 */
    .word 0x8D080000 /* 001D4B58: lw         $t0, 0x0($t0) */
    .word 0x010B4021 /* 001D4B5C: addu       $t0, $t0, $t3 */
    .word 0x91080000 /* 001D4B60: lbu        $t0, 0x0($t0) */
    .word 0x01884024 /* 001D4B64: and        $t0, $t4, $t0 */
    .word 0x51000005 /* 001D4B68: beql       $t0, $zero, .L001D4B80 */
    .word 0x25CE0001 /* 001D4B6C: addiu     $t6, $t6, 0x1 */
    .word 0x71C01E28 /* 001D4B70: paddub     $v1, $t6, $zero */
    .word 0x10000005 /* 001D4B74: b          .L001D4B8C */
    .word 0x01C51023 /* 001D4B78: subu      $v0, $t6, $a1 */
    .word 0x25CE0001 /* 001D4B7C: addiu      $t6, $t6, 0x1 */
    .word 0x014E082A /* 001D4B80: slt        $at, $t2, $t6 */
    .word 0x1020FFEE /* 001D4B84: beqz       $at, .L001D4B40 */
    .word 0x00000000 /* 001D4B88: nop */
    .word 0x1000000F /* 001D4B8C: b          .L001D4BCC */
    .word 0x00055880 /* 001D4B90: sll       $t3, $a1, 2 */
    .word 0x8C880000 /* 001D4B94: lw         $t0, 0x0($a0) */
    .word 0x00055040 /* 001D4B98: sll        $t2, $a1, 1 */
    .word 0x8D080000 /* 001D4B9C: lw         $t0, 0x0($t0) */
    .word 0x010B4021 /* 001D4BA0: addu       $t0, $t0, $t3 */
    .word 0x8D080000 /* 001D4BA4: lw         $t0, 0x0($t0) */
    .word 0x010A4021 /* 001D4BA8: addu       $t0, $t0, $t2 */
    .word 0x91080000 /* 001D4BAC: lbu        $t0, 0x0($t0) */
    .word 0x01884024 /* 001D4BB0: and        $t0, $t4, $t0 */
    .word 0x51000004 /* 001D4BB4: beql       $t0, $zero, .L001D4BC8 */
    .word 0x24A5FFFF /* 001D4BB8: addiu     $a1, $a1, -0x1 */
    .word 0x10000008 /* 001D4BBC: b          .L001D4BE0 */
    .word 0x70A01E28 /* 001D4BC0: paddub    $v1, $a1, $zero */
    .word 0x24A5FFFF /* 001D4BC4: addiu      $a1, $a1, -0x1 */
    .word 0x2442FFFF /* 001D4BC8: addiu      $v0, $v0, -0x1 */
    .word 0x00A9402A /* 001D4BCC: slt        $t0, $a1, $t1 */
    .word 0x15000003 /* 001D4BD0: bnez       $t0, .L001D4BE0 */
    .word 0x00000000 /* 001D4BD4: nop */
    .word 0x1C40FFEE /* 001D4BD8: bgtz       $v0, .L001D4B94 */
    .word 0x00000000 /* 001D4BDC: nop */
    .word 0xACE30000 /* 001D4BE0: sw         $v1, 0x0($a3) */
    .word 0x8CC20000 /* 001D4BE4: lw         $v0, 0x0($a2) */
    .word 0x8C8300EC /* 001D4BE8: lw         $v1, 0xEC($a0) */
    .word 0x0062082A /* 001D4BEC: slt        $at, $v1, $v0 */
    .word 0x10200002 /* 001D4BF0: beqz       $at, .L001D4BFC */
    .word 0x00000000 /* 001D4BF4: nop */
    .word 0xACC30000 /* 001D4BF8: sw         $v1, 0x0($a2) */
    .word 0x8C8300F0 /* 001D4BFC: lw         $v1, 0xF0($a0) */
    .word 0x8CE20000 /* 001D4C00: lw         $v0, 0x0($a3) */
    .word 0x0062082A /* 001D4C04: slt        $at, $v1, $v0 */
    .word 0x10200003 /* 001D4C08: beqz       $at, .L001D4C18 */
    .word 0x24020001 /* 001D4C0C: addiu     $v0, $zero, 0x1 */
    .word 0xACE30000 /* 001D4C10: sw         $v1, 0x0($a3) */
    .word 0x24020001 /* 001D4C14: addiu      $v0, $zero, 0x1 */
    .word 0x03E00008 /* 001D4C18: jr         $ra */
    .word 0x00000000 /* 001D4C1C: nop */
}

#else

extern "C" int func_001D48B0(void *self, void *node, int *out_x, int *out_y) {
    char *n = (char *)node;
    void *parent = *(void **)(n + 0x24);
    if (!parent) {
        return 0;
    }

    char *p = (char *)parent;
    int n_lvl = *(int *)(n + 0xC);
    int p_lvl = *(int *)(p + 0xC);
    unsigned char dir = *(unsigned char *)(n + 0x28);

    int base_x;
    int base_y;
    int lvl;

    if (p_lvl < n_lvl) {
        base_x = *(int *)(p + 0x4);
        base_y = *(int *)(p + 0x8);
        lvl = p_lvl;
    } else {
        base_x = *(int *)(n + 0x4);
        base_y = *(int *)(n + 0x8);
        lvl = n_lvl;
    }

    int t0_bound = 0;
    int min_bound = 0;

    if (dir == 1) {
        int v = base_x << lvl;
        min_bound = v;
        if (lvl > 0) {
            t0_bound = v + (1 << lvl) - 1;
            v += (1 << (lvl - 1));
        }
        if (out_x) *out_x = v;
        if (out_y) *out_y = (*(int *)(n + 0x8)) << (*(int *)(n + 0xC));
    } else if (dir == 8) {
        int v = base_x << lvl;
        min_bound = v;
        if (lvl > 0) {
            t0_bound = v + (1 << lvl) - 1;
            v += (1 << (lvl - 1));
        }
        if (out_x) *out_x = v;
        int ny = *(int *)(n + 0x8);
        int nlvl = *(int *)(n + 0xC);
        if (out_y) *out_y = ((ny + 1) << nlvl) - 1;
    } else if (dir == 2) {
        int v = base_y << lvl;
        min_bound = v;
        if (lvl > 0) {
            t0_bound = v + (1 << lvl) - 1;
            v += (1 << (lvl - 1));
        }
        if (out_y) *out_y = v;
        if (out_x) *out_x = (*(int *)(n + 0x4)) << (*(int *)(n + 0xC));
    } else if (dir == 4) {
        int v = base_y << lvl;
        min_bound = v;
        if (lvl > 0) {
            t0_bound = v + (1 << lvl) - 1;
            v += (1 << (lvl - 1));
        }
        if (out_y) *out_y = v;
        int nx = *(int *)(n + 0x4);
        int nlvl = *(int *)(n + 0xC);
        if (out_x) *out_x = ((nx + 1) << nlvl) - 1;
    }

    if (lvl > 0) {
        if (dir == 1 || dir == 8) {
            int cur_x = out_x ? *out_x : 0;
            int chosen_x = cur_x;
            int found = 0;
            int y = out_y ? *out_y : 0;
            unsigned char ***grid_ptr = *(unsigned char ****)self;
            unsigned char **cols = grid_ptr ? *grid_ptr : 0;

            for (int x = cur_x; x <= t0_bound; ++x) {
                if (cols && cols[x]) {
                    if (cols[x][y * 2] & dir) {
                        chosen_x = x;
                        found = 1;
                        break;
                    }
                }
            }

            if (!found) {
                for (int x = cur_x; x >= min_bound; --x) {
                    if (cols && cols[x]) {
                        if (cols[x][y * 2] & dir) {
                            chosen_x = x;
                            break;
                        }
                    }
                }
            }
            if (out_x) *out_x = chosen_x;
        } else if (dir == 2 || dir == 4) {
            int cur_y = out_y ? *out_y : 0;
            int chosen_y = cur_y;
            int found = 0;
            int x = out_x ? *out_x : 0;
            unsigned char ***grid_ptr = *(unsigned char ****)self;
            unsigned char **cols = grid_ptr ? *grid_ptr : 0;

            for (int y = cur_y; y <= t0_bound; ++y) {
                if (cols && cols[x]) {
                    if (cols[x][y * 2] & dir) {
                        chosen_y = y;
                        found = 1;
                        break;
                    }
                }
            }

            if (!found) {
                for (int y = cur_y; y >= min_bound; --y) {
                    if (cols && cols[x]) {
                        if (cols[x][y * 2] & dir) {
                            chosen_y = y;
                            break;
                        }
                    }
                }
            }
            if (out_y) *out_y = chosen_y;
        }
    }

    if (out_x && *out_x > *(int *)((char *)self + 0xEC)) {
        *out_x = *(int *)((char *)self + 0xEC);
    }
    if (out_y && *out_y > *(int *)((char *)self + 0xF0)) {
        *out_y = *(int *)((char *)self + 0xF0);
    }

    return 1;
}

#endif
