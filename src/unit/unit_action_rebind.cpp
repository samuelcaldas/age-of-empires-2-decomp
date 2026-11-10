#pragma exceptions off
#include "unit_action_rebind.h"


extern "C" {
    void func_2643c0(void *action);
    void func_207ab0(void *world, short id, int delta);
    void func_207c30(void *world, short id, int delta);
    void func_1edf20(void *obj, void *action);
    void func_1eda80(void *obj, void *action);
    void func_264330(void *action);
    void func_205f70(void *world, void *action);
    void func_0026A540(void *action, int flag);
    int func_00123350(float val);
}

#if defined(__mips__)

extern "C" {
asm void func_00267A80(ActionRebind *self, void *new_entity) {
    .word 0x27BDFFC0 /* 00267A80: addiu      $sp, $sp, -0x40 */
    .word 0x7FBF0030 /* 00267A84: sq         $ra, 0x30($sp) */
    .word 0x7FB10020 /* 00267A88: sq         $s1, 0x20($sp) */
    .word 0x7FB00010 /* 00267A8C: sq         $s0, 0x10($sp) */
    .word 0xE7B40000 /* 00267A90: swc1       $f20, 0x0($sp) */
    .word 0x90830039 /* 00267A94: lbu        $v1, 0x39($a0) */
    .word 0x70A08628 /* 00267A98: paddub     $s0, $a1, $zero */
    .word 0x28610003 /* 00267A9C: slti       $at, $v1, 0x3 */
    .word 0x10200058 /* 00267AA0: beqz       $at, .L00267C04 */
    .word 0x70808E28 /* 00267AA4: paddub    $s1, $a0, $zero */
    jal        func_2643c0 /* 00267AA8 */
    .word 0x00000000 /* 00267AAC: nop */
    .word 0x8604003E /* 00267AB0: lh         $a0, 0x3E($s0) */
    .word 0x8E230004 /* 00267AB4: lw         $v1, 0x4($s1) */
    .word 0xC6200030 /* 00267AB8: lwc1       $f0, 0x30($s1) */
    .word 0x24020002 /* 00267ABC: addiu      $v0, $zero, 0x2 */
    .word 0x44840800 /* 00267AC0: mtc1       $a0, $f1 */
    .word 0x8463003E /* 00267AC4: lh         $v1, 0x3E($v1) */
    .word 0x46800860 /* 00267AC8: cvt.s.w    $f1, $f1 */
    .word 0x46000842 /* 00267ACC: mul.s      $f1, $f1, $f0 */
    .word 0x44830000 /* 00267AD0: mtc1       $v1, $f0 */
    .word 0x00000000 /* 00267AD4: nop */
    .word 0x46800020 /* 00267AD8: cvt.s.w    $f0, $f0 */
    .word 0xE6200030 /* 00267ADC: swc1       $f0, 0x30($s1) */
    .word 0x92230039 /* 00267AE0: lbu        $v1, 0x39($s1) */
    .word 0x14620005 /* 00267AE4: bne        $v1, $v0, .L00267AFC */
    .word 0x46000D03 /* 00267AE8: div.s     $f20, $f1, $f0 */
    .word 0x8E390000 /* 00267AEC: lw         $t9, 0x0($s1) */
    .word 0x8F390034 /* 00267AF0: lw         $t9, 0x34($t9) */
    .word 0x0320F809 /* 00267AF4: jalr       $t9 */
    .word 0x72202628 /* 00267AF8: paddub    $a0, $s1, $zero */
    .word 0x8E220018 /* 00267AFC: lw         $v0, 0x18($s1) */
    .word 0x10400009 /* 00267B00: beqz       $v0, .L00267B28 */
    .word 0x00000000 /* 00267B04: nop */
    .word 0x8E390000 /* 00267B08: lw         $t9, 0x0($s1) */
    .word 0x8E250008 /* 00267B0C: lw         $a1, 0x8($s1) */
    .word 0x2407FFFF /* 00267B10: addiu      $a3, $zero, -0x1 */
    .word 0x72202628 /* 00267B14: paddub     $a0, $s1, $zero */
    .word 0x70003628 /* 00267B18: paddub     $a2, $zero, $zero */
    .word 0x8F3900F8 /* 00267B1C: lw         $t9, 0xF8($t9) */
    .word 0x0320F809 /* 00267B20: jalr       $t9 */
    .word 0x70004628 /* 00267B24: paddub    $t0, $zero, $zero */
    .word 0x8E220004 /* 00267B28: lw         $v0, 0x4($s1) */
    .word 0x8E240008 /* 00267B2C: lw         $a0, 0x8($s1) */
    .word 0x84450008 /* 00267B30: lh         $a1, 0x8($v0) */
    jal        func_207ab0 /* 00267B34 */
    .word 0x2406FFFF /* 00267B38: addiu     $a2, $zero, -0x1 */
    .word 0x8E220004 /* 00267B3C: lw         $v0, 0x4($s1) */
    .word 0x8E240008 /* 00267B40: lw         $a0, 0x8($s1) */
    .word 0x84450008 /* 00267B44: lh         $a1, 0x8($v0) */
    jal        func_207c30 /* 00267B48 */
    .word 0x2406FFFF /* 00267B4C: addiu     $a2, $zero, -0x1 */
    .word 0x8F848A84 /* 00267B50: lw         $a0, -0x757C($gp) */
    jal        func_1edf20 /* 00267B54 */
    .word 0x72202E28 /* 00267B58: paddub    $a1, $s1, $zero */
    .word 0xAE300004 /* 00267B5C: sw         $s0, 0x4($s1) */
    .word 0x8E220004 /* 00267B60: lw         $v0, 0x4($s1) */
    .word 0x8E240008 /* 00267B64: lw         $a0, 0x8($s1) */
    .word 0x84450008 /* 00267B68: lh         $a1, 0x8($v0) */
    jal        func_207ab0 /* 00267B6C */
    .word 0x24060001 /* 00267B70: addiu     $a2, $zero, 0x1 */
    .word 0x8E220004 /* 00267B74: lw         $v0, 0x4($s1) */
    .word 0x8E240008 /* 00267B78: lw         $a0, 0x8($s1) */
    .word 0x84450008 /* 00267B7C: lh         $a1, 0x8($v0) */
    jal        func_207c30 /* 00267B80 */
    .word 0x24060001 /* 00267B84: addiu     $a2, $zero, 0x1 */
    .word 0x8E220018 /* 00267B88: lw         $v0, 0x18($s1) */
    .word 0x10400009 /* 00267B8C: beqz       $v0, .L00267BB4 */
    .word 0x00000000 /* 00267B90: nop */
    .word 0x8E390000 /* 00267B94: lw         $t9, 0x0($s1) */
    .word 0x8E250008 /* 00267B98: lw         $a1, 0x8($s1) */
    .word 0x2407FFFF /* 00267B9C: addiu      $a3, $zero, -0x1 */
    .word 0x72202628 /* 00267BA0: paddub     $a0, $s1, $zero */
    .word 0x70003628 /* 00267BA4: paddub     $a2, $zero, $zero */
    .word 0x8F3900F4 /* 00267BA8: lw         $t9, 0xF4($t9) */
    .word 0x0320F809 /* 00267BAC: jalr       $t9 */
    .word 0x70004628 /* 00267BB0: paddub    $t0, $zero, $zero */
    .word 0x8F848A84 /* 00267BB4: lw         $a0, -0x757C($gp) */
    jal        func_1eda80 /* 00267BB8 */
    .word 0x72202E28 /* 00267BBC: paddub    $a1, $s1, $zero */
    .word 0x8E390000 /* 00267BC0: lw         $t9, 0x0($s1) */
    .word 0x8E050010 /* 00267BC4: lw         $a1, 0x10($s0) */
    .word 0x8F39004C /* 00267BC8: lw         $t9, 0x4C($t9) */
    .word 0x0320F809 /* 00267BCC: jalr       $t9 */
    .word 0x72202628 /* 00267BD0: paddub    $a0, $s1, $zero */
    .word 0xE6340030 /* 00267BD4: swc1       $f20, 0x30($s1) */
    .word 0x92230039 /* 00267BD8: lbu        $v1, 0x39($s1) */
    .word 0x24020002 /* 00267BDC: addiu      $v0, $zero, 0x2 */
    .word 0x14620006 /* 00267BE0: bne        $v1, $v0, .L00267BFC */
    .word 0x72202628 /* 00267BE4: paddub    $a0, $s1, $zero */
    .word 0x8E390000 /* 00267BE8: lw         $t9, 0x0($s1) */
    .word 0x8F390034 /* 00267BEC: lw         $t9, 0x34($t9) */
    .word 0x0320F809 /* 00267BF0: jalr       $t9 */
    .word 0x72202628 /* 00267BF4: paddub    $a0, $s1, $zero */
    .word 0x72202628 /* 00267BF8: paddub     $a0, $s1, $zero */
    jal        func_264330 /* 00267BFC */
    .word 0x00000000 /* 00267C00: nop */
    .word 0x7BBF0030 /* 00267C04: lq         $ra, 0x30($sp) */
    .word 0x7BB10020 /* 00267C08: lq         $s1, 0x20($sp) */
    .word 0x7BB00010 /* 00267C0C: lq         $s0, 0x10($sp) */
    .word 0xC7B40000 /* 00267C10: lwc1       $f20, 0x0($sp) */
    .word 0x03E00008 /* 00267C14: jr         $ra */
    .word 0x27BD0040 /* 00267C18: addiu     $sp, $sp, 0x40 */
}

asm void func_00267C20(ActionRebind *self, void *new_entity) {
    .word 0x27BDFF90 /* 00267C20: addiu      $sp, $sp, -0x70 */
    .word 0x7FBF0060 /* 00267C24: sq         $ra, 0x60($sp) */
    .word 0x7FB40050 /* 00267C28: sq         $s4, 0x50($sp) */
    .word 0x7FB30040 /* 00267C2C: sq         $s3, 0x40($sp) */
    .word 0x7FB20030 /* 00267C30: sq         $s2, 0x30($sp) */
    .word 0x7FB10020 /* 00267C34: sq         $s1, 0x20($sp) */
    .word 0x7FB00010 /* 00267C38: sq         $s0, 0x10($sp) */
    .word 0xE7B40000 /* 00267C3C: swc1       $f20, 0x0($sp) */
    .word 0x8C830018 /* 00267C40: lw         $v1, 0x18($a0) */
    .word 0x70809E28 /* 00267C44: paddub     $s3, $a0, $zero */
    .word 0x70A09628 /* 00267C48: paddub     $s2, $a1, $zero */
    .word 0x10600016 /* 00267C4C: beqz       $v1, .L00267CA8 */
    .word 0x70008628 /* 00267C50: paddub    $s0, $zero, $zero */
    .word 0x92660039 /* 00267C54: lbu        $a2, 0x39($s3) */
    .word 0x24030002 /* 00267C58: addiu      $v1, $zero, 0x2 */
    .word 0x14C30012 /* 00267C5C: bne        $a2, $v1, .L00267CA8 */
    .word 0x00000000 /* 00267C60: nop */
    .word 0x8E790000 /* 00267C64: lw         $t9, 0x0($s3) */
    .word 0x8E650008 /* 00267C68: lw         $a1, 0x8($s3) */
    .word 0x2407FFFF /* 00267C6C: addiu      $a3, $zero, -0x1 */
    .word 0x70003628 /* 00267C70: paddub     $a2, $zero, $zero */
    .word 0x8F3900F8 /* 00267C74: lw         $t9, 0xF8($t9) */
    .word 0x0320F809 /* 00267C78: jalr       $t9 */
    .word 0x70004628 /* 00267C7C: paddub    $t0, $zero, $zero */
    jal        func_00123350 /* 00267C80 */
    .word 0xC64C001C /* 00267C84: lwc1      $f12, 0x1C($s2) */
    .word 0x8E790000 /* 00267C88: lw         $t9, 0x0($s3) */
    .word 0x8E650008 /* 00267C8C: lw         $a1, 0x8($s3) */
    .word 0x72602628 /* 00267C90: paddub     $a0, $s3, $zero */
    .word 0x70003628 /* 00267C94: paddub     $a2, $zero, $zero */
    .word 0x70403E28 /* 00267C98: paddub     $a3, $v0, $zero */
    .word 0x8F3900F4 /* 00267C9C: lw         $t9, 0xF4($t9) */
    .word 0x0320F809 /* 00267CA0: jalr       $t9 */
    .word 0x70004628 /* 00267CA4: paddub    $t0, $zero, $zero */
    .word 0x8E630004 /* 00267CA8: lw         $v1, 0x4($s3) */
    .word 0x8471003E /* 00267CAC: lh         $s1, 0x3E($v1) */
    .word 0x12200010 /* 00267CB0: beqz       $s1, .L00267CF4 */
    .word 0x00000000 /* 00267CB4: nop */
    .word 0x8654003E /* 00267CB8: lh         $s4, 0x3E($s2) */
    jal        func_00123350 /* 00267CBC */
    .word 0xC66C0030 /* 00267CC0: lwc1      $f12, 0x30($s3) */
    .word 0x00021C3C /* 00267CC4: dsll32     $v1, $v0, 16 */
    .word 0x00031C3F /* 00267CC8: dsra32     $v1, $v1, 16 */
    .word 0x02832018 /* 00267CCC: mult       $a0, $s4, $v1 */
    .word 0x00111C3C /* 00267CD0: dsll32     $v1, $s1, 16 */
    .word 0x00031C3F /* 00267CD4: dsra32     $v1, $v1, 16 */
    .word 0x14600002 /* 00267CD8: bnez       $v1, .L00267CE4 */
    .word 0x0083001A /* 00267CDC: div       $zero, $a0, $v1 */
    .word 0x000001CD /* 00267CE0: break      0, 7 */
    .word 0x00001812 /* 00267CE4: mflo       $v1 */
    .word 0x44830000 /* 00267CE8: mtc1       $v1, $f0 */
    .word 0x10000003 /* 00267CEC: b          .L00267CFC */
    .word 0x46800520 /* 00267CF0: cvt.s.w   $f20, $f0 */
    .word 0xC6740030 /* 00267CF4: lwc1       $f20, 0x30($s3) */
    .word 0x00000000 /* 00267CF8: nop */
    .word 0x44910000 /* 00267CFC: mtc1       $s1, $f0 */
    .word 0x24030002 /* 00267D00: addiu      $v1, $zero, 0x2 */
    .word 0x46800020 /* 00267D04: cvt.s.w    $f0, $f0 */
    .word 0xE6600030 /* 00267D08: swc1       $f0, 0x30($s3) */
    .word 0x92640039 /* 00267D0C: lbu        $a0, 0x39($s3) */
    .word 0x14830005 /* 00267D10: bne        $a0, $v1, .L00267D28 */
    .word 0x00000000 /* 00267D14: nop */
    .word 0x8E790000 /* 00267D18: lw         $t9, 0x0($s3) */
    .word 0x8F390034 /* 00267D1C: lw         $t9, 0x34($t9) */
    .word 0x0320F809 /* 00267D20: jalr       $t9 */
    .word 0x72602628 /* 00267D24: paddub    $a0, $s3, $zero */
    .word 0x8E640004 /* 00267D28: lw         $a0, 0x4($s3) */
    .word 0x8E650010 /* 00267D2C: lw         $a1, 0x10($s3) */
    .word 0x8C830010 /* 00267D30: lw         $v1, 0x10($a0) */
    .word 0x14A30003 /* 00267D34: bne        $a1, $v1, .L00267D44 */
    .word 0x00000000 /* 00267D38: nop */
    .word 0x10000006 /* 00267D3C: b          .L00267D58 */
    .word 0x8E500010 /* 00267D40: lw        $s0, 0x10($s2) */
    .word 0x8C830018 /* 00267D44: lw         $v1, 0x18($a0) */
    .word 0x14A30003 /* 00267D48: bne        $a1, $v1, .L00267D58 */
    .word 0x00000000 /* 00267D4C: nop */
    .word 0x8E500018 /* 00267D50: lw         $s0, 0x18($s2) */
    .word 0x00000000 /* 00267D54: nop */
    .word 0x12000006 /* 00267D58: beqz       $s0, .L00267D74 */
    .word 0xE6740030 /* 00267D5C: swc1      $f20, 0x30($s3) */
    .word 0x8E790000 /* 00267D60: lw         $t9, 0x0($s3) */
    .word 0x72002E28 /* 00267D64: paddub     $a1, $s0, $zero */
    .word 0x8F39004C /* 00267D68: lw         $t9, 0x4C($t9) */
    .word 0x0320F809 /* 00267D6C: jalr       $t9 */
    .word 0x72602628 /* 00267D70: paddub    $a0, $s3, $zero */
    .word 0x8E700004 /* 00267D74: lw         $s0, 0x4($s3) */
    .word 0x24030002 /* 00267D78: addiu      $v1, $zero, 0x2 */
    .word 0xAE720004 /* 00267D7C: sw         $s2, 0x4($s3) */
    .word 0x92640039 /* 00267D80: lbu        $a0, 0x39($s3) */
    .word 0x14830005 /* 00267D84: bne        $a0, $v1, .L00267D9C */
    .word 0x00000000 /* 00267D88: nop */
    .word 0x8E790000 /* 00267D8C: lw         $t9, 0x0($s3) */
    .word 0x8F390034 /* 00267D90: lw         $t9, 0x34($t9) */
    .word 0x0320F809 /* 00267D94: jalr       $t9 */
    .word 0x72602628 /* 00267D98: paddub    $a0, $s3, $zero */
    .word 0xAE700004 /* 00267D9C: sw         $s0, 0x4($s3) */
    .word 0x7BBF0060 /* 00267DA0: lq         $ra, 0x60($sp) */
    .word 0x7BB40050 /* 00267DA4: lq         $s4, 0x50($sp) */
    .word 0x7BB30040 /* 00267DA8: lq         $s3, 0x40($sp) */
    .word 0x7BB20030 /* 00267DAC: lq         $s2, 0x30($sp) */
    .word 0x7BB10020 /* 00267DB0: lq         $s1, 0x20($sp) */
    .word 0x7BB00010 /* 00267DB4: lq         $s0, 0x10($sp) */
    .word 0xC7B40000 /* 00267DB8: lwc1       $f20, 0x0($sp) */
    .word 0x03E00008 /* 00267DBC: jr         $ra */
    .word 0x27BD0070 /* 00267DC0: addiu     $sp, $sp, 0x70 */
}

asm void func_267DD0(ActionRebind *self) {
    .word 0x27BDFFE0 /* 00267DD0: addiu      $sp, $sp, -0x20 */
    .word 0x7FBF0010 /* 00267DD4: sq         $ra, 0x10($sp) */
    .word 0x7FB00000 /* 00267DD8: sq         $s0, 0x0($sp) */
    .word 0x90830039 /* 00267DDC: lbu        $v1, 0x39($a0) */
    .word 0x28610007 /* 00267DE0: slti       $at, $v1, 0x7 */
    .word 0x10200018 /* 00267DE4: beqz       $at, .L00267E48 */
    .word 0x70808628 /* 00267DE8: paddub    $s0, $a0, $zero */
    .word 0x8E02001C /* 00267DEC: lw         $v0, 0x1C($s0) */
    .word 0x10400005 /* 00267DF0: beqz       $v0, .L00267E08 */
    .word 0x00000000 /* 00267DF4: nop */
    .word 0x8E190000 /* 00267DF8: lw         $t9, 0x0($s0) */
    .word 0x8F3900E8 /* 00267DFC: lw         $t9, 0xE8($t9) */
    .word 0x0320F809 /* 00267E00: jalr       $t9 */
    .word 0x00000000 /* 00267E04: nop */
    .word 0x92020036 /* 00267E08: lbu        $v0, 0x36($s0) */
    .word 0x30420001 /* 00267E0C: andi       $v0, $v0, 0x1 */
    .word 0x10400005 /* 00267E10: beqz       $v0, .L00267E28 */
    .word 0x72002628 /* 00267E14: paddub    $a0, $s0, $zero */
    .word 0x8E040008 /* 00267E18: lw         $a0, 0x8($s0) */
    jal        func_205f70 /* 00267E1C */
    .word 0x72002E28 /* 00267E20: paddub    $a1, $s0, $zero */
    .word 0x72002628 /* 00267E24: paddub     $a0, $s0, $zero */
    .word 0x70002E28 /* 00267E28: paddub     $a1, $zero, $zero */
    jal        func_0026A540 /* 00267E2C */
    .word 0xAE000030 /* 00267E30: sw        $zero, 0x30($s0) */
    .word 0x8E190000 /* 00267E34: lw         $t9, 0x0($s0) */
    .word 0x24050007 /* 00267E38: addiu      $a1, $zero, 0x7 */
    .word 0x8F390070 /* 00267E3C: lw         $t9, 0x70($t9) */
    .word 0x0320F809 /* 00267E40: jalr       $t9 */
    .word 0x72002628 /* 00267E44: paddub    $a0, $s0, $zero */
    .word 0x7BBF0010 /* 00267E48: lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* 00267E4C: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 00267E50: jr         $ra */
    .word 0x27BD0020 /* 00267E54: addiu     $sp, $sp, 0x20 */
}
}

#else

void func_00267A80(ActionRebind *self, void *new_entity) {
    if (self->m_field39 >= 3) {
        return;
    }

    func_2643C0(self);

    short new_val = *(short*)((char*)new_entity + 62);
    short old_val = *(short*)((char*)self->m_field4 + 62);
    float f20 = ((float)new_val * self->m_field30) / (float)old_val;
    self->m_field30 = (float)old_val;

    if (self->m_field39 == 2) {
        self->Method13();
    }

    if (self->m_field18 != 0) {
        self->Method62(self->m_world, 0, -1, 0);
    }

    func_207AB0(self->m_world, *(short*)((char*)self->m_field4 + 8), -1);
    func_207C30(self->m_world, *(short*)((char*)self->m_field4 + 8), -1);

    func_1EDF20(D_004E3244, self);

    self->m_field4 = new_entity;

    func_207AB0(self->m_world, *(short*)((char*)self->m_field4 + 8), 1);
    func_207C30(self->m_world, *(short*)((char*)self->m_field4 + 8), 1);

    if (self->m_field18 != 0) {
        self->Method61(self->m_world, 0, -1, 0);
    }

    func_1EDA80(D_004E3244, self);

    self->Method19(*(int*)((char*)new_entity + 16));

    self->m_field30 = f20;

    if (self->m_field39 == 2) {
        self->Method13();
    }

    func_264330(self);
}

void func_00267C20(ActionRebind *self, void *new_entity) {
    int target_id = 0;
    if (self->m_field18 != 0 && self->m_field39 == 2) {
        self->Method62(self->m_world, 0, -1, 0);
        float f0 = *(float*)((char*)new_entity + 28);
        int res = func_123350(f0);
        self->Method61(self->m_world, 0, res, 0);
    }

    short old_val = *(short*)((char*)self->m_field4 + 62);
    float f20;
    if (old_val != 0) {
        short new_val = *(short*)((char*)new_entity + 62);
        short res = (short)func_123350(self->m_field30);
        int scaled = ((int)res * (int)new_val) / (int)old_val;
        f20 = (float)scaled;
    } else {
        f20 = self->m_field30;
    }

    self->m_field30 = (float)old_val;

    if (self->m_field39 == 2) {
        self->Method13();
    }

    if (self->m_field10 == *(int*)((char*)self->m_field4 + 16)) {
        target_id = *(int*)((char*)new_entity + 16);
    } else if (self->m_field10 == *(int*)((char*)self->m_field4 + 24)) {
        target_id = *(int*)((char*)new_entity + 24);
    }

    self->m_field30 = f20;

    if (target_id != 0) {
        self->Method19(target_id);
    }

    void *old_field4 = self->m_field4;
    self->m_field4 = new_entity;

    if (self->m_field39 == 2) {
        self->Method13();
    }

    self->m_field4 = old_field4;
}

void func_267DD0(ActionRebind *self) {
    if (self->m_field39 >= 7) {
        return;
    }

    if (self->m_field1C != 0) {
        self->Method58();
    }

    if ((self->m_field36 & 1) != 0) {
        func_205F70(self->m_world, self);
    }

    self->m_field30 = 0.0f;
    func_26A540(self, 0);

    self->Method28(7);
}

#endif
