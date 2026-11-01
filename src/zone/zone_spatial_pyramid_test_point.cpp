#pragma exceptions off

#include "zone_spatial_pyramid_test_point.h"

extern "C" {
int func_1D5A30(void *self, int x, int y);
int func_00123350(float val);
void *func_1D4330(void *self, int x, int y, int level, float g_score, float h_score, void *parent, int dir, void *t2, void *t3);
void func_001D42A0(void *self, void *list_head, void *node, int flag);
}

#if defined(__mips__)

extern "C" asm void func_001D5B00(void *self, int x, int y, void *node, int dir, int flag) {
    .word 0x27BDFF70 /* 001D5B00: addiu      $sp, $sp, -0x90 */
    .word 0x7FBF0080 /* 001D5B04: sq         $ra, 0x80($sp) */
    .word 0x7FB70070 /* 001D5B08: sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* 001D5B0C: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 001D5B10: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D5B14: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D5B18: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D5B1C: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D5B20: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D5B24: sq         $s0, 0x0($sp) */
    .word 0x8C8300F4 /* 001D5B28: lw         $v1, 0xF4($a0) */
    .word 0x70C09628 /* 001D5B2C: paddub     $s2, $a2, $zero */
    .word 0x70A09E28 /* 001D5B30: paddub     $s3, $a1, $zero */
    .word 0x70E08E28 /* 001D5B34: paddub     $s1, $a3, $zero */
    .word 0x0263302A /* 001D5B38: slt        $a2, $s3, $v1 */
    .word 0x14C000B8 /* 001D5B3C: bnez       $a2, .L001D5E20 */
    .word 0x7080A628 /* 001D5B40: paddub    $s4, $a0, $zero */
    .word 0x8E8600FC /* 001D5B44: lw         $a2, 0xFC($s4) */
    .word 0x00D3082A /* 001D5B48: slt        $at, $a2, $s3 */
    .word 0x142000B4 /* 001D5B4C: bnez       $at, .L001D5E20 */
    .word 0x00000000 /* 001D5B50: nop */
    .word 0x8E8B00F8 /* 001D5B54: lw         $t3, 0xF8($s4) */
    .word 0x024B382A /* 001D5B58: slt        $a3, $s2, $t3 */
    .word 0x14E000B0 /* 001D5B5C: bnez       $a3, .L001D5E20 */
    .word 0x00000000 /* 001D5B60: nop */
    .word 0x8E8C0100 /* 001D5B64: lw         $t4, 0x100($s4) */
    .word 0x0192082A /* 001D5B68: slt        $at, $t4, $s2 */
    .word 0x10200003 /* 001D5B6C: beqz       $at, .L001D5B7C */
    .word 0x00000000 /* 001D5B70: nop */
    .word 0x100000AB /* 001D5B74: b          .L001D5E24 */
    .word 0x7BBF0080 /* 001D5B78: lq        $ra, 0x80($sp) */
/* .L001D5B7C: */
    .word 0x8E870000 /* 001D5B7C: lw         $a3, 0x0($s4) */
    .word 0x00138080 /* 001D5B80: sll        $s0, $s3, 2 */
    .word 0x00125040 /* 001D5B84: sll        $t2, $s2, 1 */
    .word 0x8CE70000 /* 001D5B88: lw         $a3, 0x0($a3) */
    .word 0x00F03821 /* 001D5B8C: addu       $a3, $a3, $s0 */
    .word 0x8CE70000 /* 001D5B90: lw         $a3, 0x0($a3) */
    .word 0x00EAA821 /* 001D5B94: addu       $s5, $a3, $t2 */
    .word 0x92AA0000 /* 001D5B98: lbu        $t2, 0x0($s5) */
    .word 0x31470010 /* 001D5B9C: andi       $a3, $t2, 0x10 */
    .word 0x14E0009F /* 001D5BA0: bnez       $a3, .L001D5E20 */
    .word 0x00000000 /* 001D5BA4: nop */
    .word 0x24020002 /* 001D5BA8: addiu      $v0, $zero, 0x2 */
    .word 0x311700FF /* 001D5BAC: andi       $s7, $t0, 0xFF */
    .word 0x12E20004 /* 001D5BB0: beq        $s7, $v0, .L001D5BC4 */
    .word 0x2416FFFF /* 001D5BB4: addiu     $s6, $zero, -0x1 */
    .word 0x24020004 /* 001D5BB8: addiu      $v0, $zero, 0x4 */
    .word 0x16E20008 /* 001D5BBC: bne        $s7, $v0, .L001D5BE0 */
    .word 0x00000000 /* 001D5BC0: nop */
/* .L001D5BC4: */
    .word 0x164B0002 /* 001D5BC4: bne        $s2, $t3, .L001D5BD0 */
    .word 0x00000000 /* 001D5BC8: nop */
    .word 0x7000B628 /* 001D5BCC: paddub     $s6, $zero, $zero */
/* .L001D5BD0: */
    .word 0x164C000A /* 001D5BD0: bne        $s2, $t4, .L001D5BFC */
    .word 0x2402FFFF /* 001D5BD4: addiu     $v0, $zero, -0x1 */
    .word 0x10000007 /* 001D5BD8: b          .L001D5BF8 */
    .word 0x2416FF9C /* 001D5BDC: addiu     $s6, $zero, -0x64 */
/* .L001D5BE0: */
    .word 0x16630002 /* 001D5BE0: bne        $s3, $v1, .L001D5BEC */
    .word 0x00000000 /* 001D5BE4: nop */
    .word 0x7000B628 /* 001D5BE8: paddub     $s6, $zero, $zero */
/* .L001D5BEC: */
    .word 0x16660002 /* 001D5BEC: bne        $s3, $a2, .L001D5BF8 */
    .word 0x00000000 /* 001D5BF0: nop */
    .word 0x2416FF9C /* 001D5BF4: addiu      $s6, $zero, -0x64 */
/* .L001D5BF8: */
    .word 0x2402FFFF /* 001D5BF8: addiu      $v0, $zero, -0x1 */
/* .L001D5BFC: */
    .word 0x16C20065 /* 001D5BFC: bne        $s6, $v0, .L001D5D94 */
    .word 0x00000000 /* 001D5C00: nop */
    .word 0x1260000A /* 001D5C04: beqz       $s3, .L001D5C30 */
    .word 0x2416000A /* 001D5C08: addiu     $s6, $zero, 0xA */
    .word 0x12400007 /* 001D5C0C: beqz       $s2, .L001D5C2C */
    .word 0x00000000 /* 001D5C10: nop */
    .word 0x8E8200EC /* 001D5C14: lw         $v0, 0xEC($s4) */
    .word 0x12620004 /* 001D5C18: beq        $s3, $v0, .L001D5C2C */
    .word 0x00000000 /* 001D5C1C: nop */
    .word 0x8E8200F0 /* 001D5C20: lw         $v0, 0xF0($s4) */
    .word 0x16420004 /* 001D5C24: bne        $s2, $v0, .L001D5C38 */
    .word 0x00000000 /* 001D5C28: nop */
/* .L001D5C2C: */
    .word 0x2416000A /* 001D5C2C: addiu      $s6, $zero, 0xA */
/* .L001D5C30: */
    .word 0x10000051 /* 001D5C30: b          .L001D5D78 */
    .word 0x8E820120 /* 001D5C34: lw        $v0, 0x120($s4) */
/* .L001D5C38: */
    .word 0x1540003E /* 001D5C38: bnez       $t2, .L001D5D34 */
    .word 0x00000000 /* 001D5C3C: nop */
    .word 0x72802628 /* 001D5C40: paddub     $a0, $s4, $zero */
    .word 0x72602E28 /* 001D5C44: paddub     $a1, $s3, $zero */
    .word 0x72403628 /* 001D5C48: paddub     $a2, $s2, $zero */
    jal        func_1D5A30 /* 001D5C4C: jal        func_1D5A30 */
    .word 0x7000B628 /* 001D5C50: paddub    $s6, $zero, $zero */
    .word 0x54400018 /* 001D5C54: bnel       $v0, $zero, .L001D5CB8 */
    .word 0x64160001 /* 001D5C58: daddiu    $s6, $zero, 0x1 */
    .word 0x26650001 /* 001D5C5C: addiu      $a1, $s3, 0x1 */
    .word 0x72802628 /* 001D5C60: paddub     $a0, $s4, $zero */
    jal        func_1D5A30 /* 001D5C64: jal        func_1D5A30 */
    .word 0x72403628 /* 001D5C68: paddub    $a2, $s2, $zero */
    .word 0x14400011 /* 001D5C6C: bnez       $v0, .L001D5CB4 */
    .word 0x26460001 /* 001D5C70: addiu     $a2, $s2, 0x1 */
    .word 0x72802628 /* 001D5C74: paddub     $a0, $s4, $zero */
    jal        func_1D5A30 /* 001D5C78: jal        func_1D5A30 */
    .word 0x72602E28 /* 001D5C7C: paddub    $a1, $s3, $zero */
    .word 0x1440000C /* 001D5C80: bnez       $v0, .L001D5CB4 */
    .word 0x00000000 /* 001D5C84: nop */
    .word 0x2665FFFF /* 001D5C88: addiu      $a1, $s3, -0x1 */
    .word 0x72802628 /* 001D5C8C: paddub     $a0, $s4, $zero */
    jal        func_1D5A30 /* 001D5C90: jal        func_1D5A30 */
    .word 0x72403628 /* 001D5C94: paddub    $a2, $s2, $zero */
    .word 0x14400006 /* 001D5C98: bnez       $v0, .L001D5CB4 */
    .word 0x2646FFFF /* 001D5C9C: addiu     $a2, $s2, -0x1 */
    .word 0x72802628 /* 001D5CA0: paddub     $a0, $s4, $zero */
    jal        func_1D5A30 /* 001D5CA4: jal        func_1D5A30 */
    .word 0x72602E28 /* 001D5CA8: paddub    $a1, $s3, $zero */
    .word 0x10400002 /* 001D5CAC: beqz       $v0, .L001D5CB8 */
    .word 0x00000000 /* 001D5CB0: nop */
/* .L001D5CB4: */
    .word 0x64160001 /* 001D5CB4: daddiu     $s6, $zero, 0x1 */
/* .L001D5CB8: */
    .word 0x12C00003 /* 001D5CB8: beqz       $s6, .L001D5CC8 */
    .word 0x24020008 /* 001D5CBC: addiu     $v0, $zero, 0x8 */
    .word 0x1000002C /* 001D5CC0: b          .L001D5D74 */
    .word 0x2416012C /* 001D5CC4: addiu     $s6, $zero, 0x12C */
/* .L001D5CC8: */
    .word 0x12E20016 /* 001D5CC8: beq        $s7, $v0, .L001D5D24 */
    .word 0x2416000A /* 001D5CCC: addiu     $s6, $zero, 0xA */
    .word 0x24020001 /* 001D5CD0: addiu      $v0, $zero, 0x1 */
    .word 0x12E2000F /* 001D5CD4: beq        $s7, $v0, .L001D5D14 */
    .word 0x24020004 /* 001D5CD8: addiu     $v0, $zero, 0x4 */
    .word 0x12E20009 /* 001D5CDC: beq        $s7, $v0, .L001D5D04 */
    .word 0x24020002 /* 001D5CE0: addiu     $v0, $zero, 0x2 */
    .word 0x12E20003 /* 001D5CE4: beq        $s7, $v0, .L001D5CF4 */
    .word 0x00000000 /* 001D5CE8: nop */
    .word 0x10000021 /* 001D5CEC: b          .L001D5D74 */
    .word 0x00000000 /* 001D5CF0: nop */
/* .L001D5CF4: */
    .word 0x8E8200F4 /* 001D5CF4: lw         $v0, 0xF4($s4) */
    .word 0x02621023 /* 001D5CF8: subu       $v0, $s3, $v0 */
    .word 0x1000001D /* 001D5CFC: b          .L001D5D74 */
    .word 0x02C2B021 /* 001D5D00: addu      $s6, $s6, $v0 */
/* .L001D5D04: */
    .word 0x8E8200FC /* 001D5D04: lw         $v0, 0xFC($s4) */
    .word 0x00531023 /* 001D5D08: subu       $v0, $v0, $s3 */
    .word 0x10000019 /* 001D5D0C: b          .L001D5D74 */
    .word 0x02C2B021 /* 001D5D10: addu      $s6, $s6, $v0 */
/* .L001D5D14: */
    .word 0x8E8200F8 /* 001D5D14: lw         $v0, 0xF8($s4) */
    .word 0x02421023 /* 001D5D18: subu       $v0, $s2, $v0 */
    .word 0x10000015 /* 001D5D1C: b          .L001D5D74 */
    .word 0x02C2B021 /* 001D5D20: addu      $s6, $s6, $v0 */
/* .L001D5D24: */
    .word 0x8E820100 /* 001D5D24: lw         $v0, 0x100($s4) */
    .word 0x00521023 /* 001D5D28: subu       $v0, $v0, $s2 */
    .word 0x10000011 /* 001D5D2C: b          .L001D5D74 */
    .word 0x02C2B021 /* 001D5D30: addu      $s6, $s6, $v0 */
/* .L001D5D34: */
    .word 0x8E860098 /* 001D5D34: lw         $a2, 0x98($s4) */
    .word 0x00123880 /* 001D5D38: sll        $a3, $s2, 2 */
    .word 0x001310C0 /* 001D5D3C: sll        $v0, $s3, 3 */
    .word 0x00531023 /* 001D5D40: subu       $v0, $v0, $s3 */
    .word 0x00021880 /* 001D5D44: sll        $v1, $v0, 2 */
    .word 0x24020004 /* 001D5D48: addiu      $v0, $zero, 0x4 */
    .word 0x00C73021 /* 001D5D4C: addu       $a2, $a2, $a3 */
    .word 0x8CC60000 /* 001D5D50: lw         $a2, 0x0($a2) */
    .word 0x00661821 /* 001D5D54: addu       $v1, $v1, $a2 */
    .word 0x90630005 /* 001D5D58: lbu        $v1, 0x5($v1) */
    .word 0x14620002 /* 001D5D5C: bne        $v1, $v0, .L001D5D68 */
    .word 0x24160064 /* 001D5D60: addiu     $s6, $zero, 0x64 */
    .word 0x2416012C /* 001D5D64: addiu      $s6, $zero, 0x12C */
/* .L001D5D68: */
    .word 0x11200002 /* 001D5D68: beqz       $t1, .L001D5D74 */
    .word 0x00000000 /* 001D5D6C: nop */
    .word 0x26D6000A /* 001D5D70: addiu      $s6, $s6, 0xA */
/* .L001D5D74: */
    .word 0x8E820120 /* 001D5D74: lw         $v0, 0x120($s4) */
/* .L001D5D78: */
    .word 0x00501021 /* 001D5D78: addu       $v0, $v0, $s0 */
    .word 0x8C420000 /* 001D5D7C: lw         $v0, 0x0($v0) */
    .word 0x00521021 /* 001D5D80: addu       $v0, $v0, $s2 */
    .word 0x90420000 /* 001D5D84: lbu        $v0, 0x0($v0) */
    .word 0x10400002 /* 001D5D88: beqz       $v0, .L001D5D94 */
    .word 0x00000000 /* 001D5D8C: nop */
    .word 0x241607D0 /* 001D5D90: addiu      $s6, $zero, 0x7D0 */
/* .L001D5D94: */
    jal        func_00123350 /* 001D5D94: jal        func_00123350 */
    .word 0xC62C001C /* 001D5D98: lwc1      $f12, 0x1C($s1) */
    .word 0x02C2B021 /* 001D5D9C: addu       $s6, $s6, $v0 */
    .word 0x24020002 /* 001D5DA0: addiu      $v0, $zero, 0x2 */
    .word 0x12E20003 /* 001D5DA4: beq        $s7, $v0, .L001D5DB4 */
    .word 0x24020004 /* 001D5DA8: addiu     $v0, $zero, 0x4 */
    .word 0x16E20004 /* 001D5DAC: bne        $s7, $v0, .L001D5DC0 */
    .word 0x00000000 /* 001D5DB0: nop */
/* .L001D5DB4: */
    .word 0x8E820100 /* 001D5DB4: lw         $v0, 0x100($s4) */
    .word 0x10000003 /* 001D5DB8: b          .L001D5DC8 */
    .word 0x00521023 /* 001D5DBC: subu      $v0, $v0, $s2 */
/* .L001D5DC0: */
    .word 0x8E8200FC /* 001D5DC0: lw         $v0, 0xFC($s4) */
    .word 0x00531023 /* 001D5DC4: subu       $v0, $v0, $s3 */
/* .L001D5DC8: */
    .word 0x44960800 /* 001D5DC8: mtc1       $s6, $f1 */
    .word 0x44820000 /* 001D5DCC: mtc1       $v0, $f0 */
    .word 0x00000000 /* 001D5DD0: nop */
    .word 0x46800B20 /* 001D5DD4: cvt.s.w    $f12, $f1 */
    .word 0x72602E28 /* 001D5DD8: paddub     $a1, $s3, $zero */
    .word 0x72403628 /* 001D5DDC: paddub     $a2, $s2, $zero */
    .word 0x72204628 /* 001D5DE0: paddub     $t0, $s1, $zero */
    .word 0x72802628 /* 001D5DE4: paddub     $a0, $s4, $zero */
    .word 0x70003E28 /* 001D5DE8: paddub     $a3, $zero, $zero */
    .word 0x46800360 /* 001D5DEC: cvt.s.w    $f13, $f0 */
    .word 0x70004E28 /* 001D5DF0: paddub     $t1, $zero, $zero */
    .word 0x70005628 /* 001D5DF4: paddub     $t2, $zero, $zero */
    jal        func_1D4330 /* 001D5DF8: jal        func_1D4330 */
    .word 0x70005E28 /* 001D5DFC: paddub    $t3, $zero, $zero */
    .word 0x26850008 /* 001D5E00: addiu      $a1, $s4, 0x8 */
    .word 0x72802628 /* 001D5E04: paddub     $a0, $s4, $zero */
    .word 0x70403628 /* 001D5E08: paddub     $a2, $v0, $zero */
    jal        func_001D42A0 /* 001D5E0C: jal        func_001D42A0 */
    .word 0x70003E28 /* 001D5E10: paddub    $a3, $zero, $zero */
    .word 0x92A30000 /* 001D5E14: lbu        $v1, 0x0($s5) */
    .word 0x24630010 /* 001D5E18: addiu      $v1, $v1, 0x10 */
    .word 0xA2A30000 /* 001D5E1C: sb         $v1, 0x0($s5) */
/* .L001D5E20: */
    .word 0x7BBF0080 /* 001D5E20: lq         $ra, 0x80($sp) */
/* .L001D5E24: */
    .word 0x7BB70070 /* 001D5E24: lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* 001D5E28: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 001D5E2C: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D5E30: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D5E34: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D5E38: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D5E3C: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D5E40: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D5E44: jr         $ra */
    .word 0x27BD0090 /* 001D5E48: addiu     $sp, $sp, 0x90 */
}

#else

typedef unsigned char u8;
typedef unsigned short u16;

extern "C" void func_001D5B00(void *self, int x, int y, void *node, int dir, int flag) {
    char *zm = (char *)self;
    int min_x = *(int *)(zm + 0xF4);
    int max_x = *(int *)(zm + 0xFC);
    int min_y = *(int *)(zm + 0xF8);
    int max_y = *(int *)(zm + 0x100);

    if (x < min_x || x > max_x || y < min_y || y > max_y) {
        return;
    }

    void ***grid = *(void ****)(zm + 0x0);
    u8 *flags_ptr = (u8 *)((char *)grid[0][x] + y * 2);
    u8 flags = *flags_ptr;
    if (flags & 0x10) {
        return;
    }

    int cost_mod = -1;
    int d = dir & 0xFF;
    if (d == 2 || d == 4) {
        if (y == min_y) cost_mod = 0;
        if (y == max_y) cost_mod = -100;
    } else {
        if (x == min_x) cost_mod = 0;
        if (x == max_x) cost_mod = -100;
    }

    if (cost_mod == -1) {
        int map_w = *(int *)(zm + 0xEC);
        int map_h = *(int *)(zm + 0xF0);
        if (x == 0 || y == 0 || x == map_w || y == map_h) {
            cost_mod = 10;
        } else {
            if (flags == 0) {
                int blocked = func_1D5A30(self, x, y);
                if (!blocked) blocked = func_1D5A30(self, x + 1, y);
                if (!blocked) blocked = func_1D5A30(self, x, y + 1);
                if (!blocked) blocked = func_1D5A30(self, x - 1, y);
                if (!blocked) blocked = func_1D5A30(self, x, y - 1);
                if (blocked) {
                    cost_mod = 300;
                } else {
                    if (d == 8) cost_mod = 10 + (max_y - y);
                    else if (d == 1) cost_mod = 10 + (y - min_y);
                    else if (d == 4) cost_mod = 10 + (max_x - x);
                    else if (d == 2) cost_mod = 10 + (x - min_x);
                    else cost_mod = 10;
                }
            } else {
                char **map_tiles = *(char ***)(zm + 0x98);
                char *tile = (char *)map_tiles[y] + x * 28;
                u8 f5 = *(u8 *)(tile + 5);
                cost_mod = (f5 != 4) ? 100 : 300;
                if (flag != 0) {
                    cost_mod += 10;
                }
            }
        }
        u8 **arr120 = *(u8 ***)(zm + 0x120);
        if (arr120[x][y] != 0) {
            cost_mod = 2000;
        }
    }

    float parent_g = *(float *)((char *)node + 0x1C);
    cost_mod += func_00123350(parent_g);

    int h;
    if (d == 2 || d == 4) {
        h = max_y - y;
    } else {
        h = max_x - x;
    }

    void *new_node = func_1D4330(self, x, y, 0, (float)cost_mod, (float)h, node, 0, 0, 0);
    func_001D42A0(self, zm + 8, new_node, 0);
    *flags_ptr = flags + 0x10;
}

#endif
