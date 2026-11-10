#pragma exceptions off
#include "tactical_ai_action_handler_340d70.h"

extern "C" {
#if defined(__mips__)
int func_0021A1C0(void *ptr);
int func_00341040(void *self, int a1, int a2, int a3, int a4, int a5);
int func_2261c0();

asm int func_00340D70(TacticalObj_340D70 *self, int cmd, int arg2) {
    .word 0x27BDFFD0 /* 00340D70 addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* 00340D74 sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* 00340D78 sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 00340D7C sq         $s0, 0x0($sp) */
    .word 0x8C830840 /* 00340D80 lw         $v1, 0x840($a0) */
    .word 0x2402FFFF /* 00340D84 addiu      $v0, $zero, -0x1 */
    .word 0x14620003 /* 00340D88 bne        $v1, $v0, .L00340D98 */
    .word 0x70808E28 /* 00340D8C paddub    $s1, $a0, $zero */
    .word 0x100000A6 /* 00340D90 b          .L0034102C */
    .word 0x70001628 /* 00340D94 paddub    $v0, $zero, $zero */
    .word 0x240200FF /* 00340D98 addiu      $v0, $zero, 0xFF */
    .word 0x10A2007E /* 00340D9C beq        $a1, $v0, .L00340F98 */
    .word 0x8E30084C /* 00340DA0 lw        $s0, 0x84C($s1) */
    .word 0x24020012 /* 00340DA4 addiu      $v0, $zero, 0x12 */
    .word 0x10A2004C /* 00340DA8 beq        $a1, $v0, .L00340EDC */
    .word 0x24020009 /* 00340DAC addiu     $v0, $zero, 0x9 */
    .word 0x24020011 /* 00340DB0 addiu      $v0, $zero, 0x11 */
    .word 0x10A20034 /* 00340DB4 beq        $a1, $v0, .L00340E88 */
    .word 0x24020010 /* 00340DB8 addiu     $v0, $zero, 0x10 */
    .word 0x24020010 /* 00340DBC addiu      $v0, $zero, 0x10 */
    .word 0x10A20030 /* 00340DC0 beq        $a1, $v0, .L00340E84 */
    .word 0x00000000 /* 00340DC4 nop */
    .word 0x2402000E /* 00340DC8 addiu      $v0, $zero, 0xE */
    .word 0x10A2002B /* 00340DCC beq        $a1, $v0, .L00340E7C */
    .word 0x24020013 /* 00340DD0 addiu     $v0, $zero, 0x13 */
    .word 0x2402000D /* 00340DD4 addiu      $v0, $zero, 0xD */
    .word 0x10A20025 /* 00340DD8 beq        $a1, $v0, .L00340E70 */
    .word 0x2402000F /* 00340DDC addiu     $v0, $zero, 0xF */
    .word 0x2402000A /* 00340DE0 addiu      $v0, $zero, 0xA */
    .word 0x10A2000D /* 00340DE4 beq        $a1, $v0, .L00340E1C */
    .word 0x2402001C /* 00340DE8 addiu     $v0, $zero, 0x1C */
    .word 0x2403000C /* 00340DEC addiu      $v1, $zero, 0xC */
    .word 0x10A30009 /* 00340DF0 beq        $a1, $v1, .L00340E18 */
    .word 0x00000000 /* 00340DF4 nop */
    .word 0x2402000B /* 00340DF8 addiu      $v0, $zero, 0xB */
    .word 0x10A20003 /* 00340DFC beq        $a1, $v0, .L00340E0C */
    .word 0x00000000 /* 00340E00 nop */
    .word 0x1000006B /* 00340E04 b          .L00340FB4 */
    .word 0x2402000B /* 00340E08 addiu     $v0, $zero, 0xB */
    .word 0xAE23084C /* 00340E0C sw         $v1, 0x84C($s1) */
    .word 0x10000067 /* 00340E10 b          .L00340FB0 */
    .word 0xAE23083C /* 00340E14 sw        $v1, 0x83C($s1) */
    .word 0x2402001C /* 00340E18 addiu      $v0, $zero, 0x1C */
    .word 0x12020064 /* 00340E1C beq        $s0, $v0, .L00340FB0 */
    .word 0x00000000 /* 00340E20 nop */
    .word 0x2402000E /* 00340E24 addiu      $v0, $zero, 0xE */
    .word 0xAE22084C /* 00340E28 sw         $v0, 0x84C($s1) */
    .word 0x8E220840 /* 00340E2C lw         $v0, 0x840($s1) */
    .word 0x1440005F /* 00340E30 bnez       $v0, .L00340FB0 */
    .word 0x00000000 /* 00340E34 nop */
    .word 0x24020008 /* 00340E38 addiu      $v0, $zero, 0x8 */
    .word 0x1202005C /* 00340E3C beq        $s0, $v0, .L00340FB0 */
    .word 0x00000000 /* 00340E40 nop */
    .word 0x8E390000 /* 00340E44 lw         $t9, 0x0($s1) */
    .word 0x8E250830 /* 00340E48 lw         $a1, 0x830($s1) */
    .word 0x24060001 /* 00340E4C addiu      $a2, $zero, 0x1 */
    .word 0x72202628 /* 00340E50 paddub     $a0, $s1, $zero */
    .word 0x70003E28 /* 00340E54 paddub     $a3, $zero, $zero */
    .word 0x8F3900D0 /* 00340E58 lw         $t9, 0xD0($t9) */
    .word 0x0320F809 /* 00340E5C jalr       $t9 */
    .word 0x70004628 /* 00340E60 paddub    $t0, $zero, $zero */
    .word 0x10000071 /* 00340E64 b          .L0034102C */
    .word 0x24020001 /* 00340E68 addiu     $v0, $zero, 0x1 */
    .word 0x2402000F /* 00340E6C addiu      $v0, $zero, 0xF */
    .word 0x1000004F /* 00340E70 b          .L00340FB0 */
    .word 0xAE22084C /* 00340E74 sw        $v0, 0x84C($s1) */
    .word 0x24020013 /* 00340E78 addiu      $v0, $zero, 0x13 */
    .word 0x1000004C /* 00340E7C b          .L00340FB0 */
    .word 0xAE22084C /* 00340E80 sw        $v0, 0x84C($s1) */
    .word 0x24020010 /* 00340E84 addiu      $v0, $zero, 0x10 */
    .word 0x16020005 /* 00340E88 bne        $s0, $v0, .L00340EA0 */
    .word 0x24020008 /* 00340E8C addiu     $v0, $zero, 0x8 */
    .word 0x24020016 /* 00340E90 addiu      $v0, $zero, 0x16 */
    .word 0x10000046 /* 00340E94 b          .L00340FB0 */
    .word 0xAE22084C /* 00340E98 sw        $v0, 0x84C($s1) */
    .word 0x24020008 /* 00340E9C addiu      $v0, $zero, 0x8 */
    .word 0x16020005 /* 00340EA0 bne        $s0, $v0, .L00340EB8 */
    .word 0x24020009 /* 00340EA4 addiu     $v0, $zero, 0x9 */
    .word 0x24020018 /* 00340EA8 addiu      $v0, $zero, 0x18 */
    .word 0x10000040 /* 00340EAC b          .L00340FB0 */
    .word 0xAE22084C /* 00340EB0 sw        $v0, 0x84C($s1) */
    .word 0x24020009 /* 00340EB4 addiu      $v0, $zero, 0x9 */
    .word 0x16020005 /* 00340EB8 bne        $s0, $v0, .L00340ED0 */
    .word 0x24020015 /* 00340EBC addiu     $v0, $zero, 0x15 */
    .word 0x24020017 /* 00340EC0 addiu      $v0, $zero, 0x17 */
    .word 0x1000003A /* 00340EC4 b          .L00340FB0 */
    .word 0xAE22084C /* 00340EC8 sw        $v0, 0x84C($s1) */
    .word 0x24020015 /* 00340ECC addiu      $v0, $zero, 0x15 */
    .word 0x10000037 /* 00340ED0 b          .L00340FB0 */
    .word 0xAE22084C /* 00340ED4 sw        $v0, 0x84C($s1) */
    .word 0x24020009 /* 00340ED8 addiu      $v0, $zero, 0x9 */
    .word 0x16020004 /* 00340EDC bne        $s0, $v0, .L00340EF0 */
    .word 0x24020009 /* 00340EE0 addiu     $v0, $zero, 0x9 */
    jal func_0021A1C0
    .word 0x00000000 /* 00340EE8 nop */
    .word 0x24020009 /* 00340EEC addiu      $v0, $zero, 0x9 */
    .word 0x1602000B /* 00340EF0 bne        $s0, $v0, .L00340F20 */
    .word 0x24020008 /* 00340EF4 addiu     $v0, $zero, 0x8 */
    .word 0x24020019 /* 00340EF8 addiu      $v0, $zero, 0x19 */
    .word 0xAE22084C /* 00340EFC sw         $v0, 0x84C($s1) */
    jal func_00341040
    .word 0x72202628 /* 00340F04 paddub    $a0, $s1, $zero */
    jal func_2261c0
    .word 0x00000000 /* 00340F0C nop */
    .word 0xAE220854 /* 00340F10 sw         $v0, 0x854($s1) */
    .word 0x10000016 /* 00340F14 b          .L00340F70 */
    .word 0xAE200858 /* 00340F18 sw        $zero, 0x858($s1) */
    .word 0x24020008 /* 00340F1C addiu      $v0, $zero, 0x8 */
    .word 0x1602000B /* 00340F20 bne        $s0, $v0, .L00340F50 */
    .word 0x24020010 /* 00340F24 addiu     $v0, $zero, 0x10 */
    .word 0x2402001A /* 00340F28 addiu      $v0, $zero, 0x1A */
    .word 0xAE22084C /* 00340F2C sw         $v0, 0x84C($s1) */
    jal func_00341040
    .word 0x72202628 /* 00340F34 paddub    $a0, $s1, $zero */
    jal func_2261c0
    .word 0x00000000 /* 00340F3C nop */
    .word 0xAE220854 /* 00340F40 sw         $v0, 0x854($s1) */
    .word 0x1000000A /* 00340F44 b          .L00340F70 */
    .word 0xAE200858 /* 00340F48 sw        $zero, 0x858($s1) */
    .word 0x24020010 /* 00340F4C addiu      $v0, $zero, 0x10 */
    .word 0x16020007 /* 00340F50 bne        $s0, $v0, .L00340F70 */
    .word 0x00000000 /* 00340F54 nop */
    .word 0x2402001B /* 00340F58 addiu      $v0, $zero, 0x1B */
    .word 0xAE22084C /* 00340F5C sw         $v0, 0x84C($s1) */
    jal func_00341040
    .word 0x72202628 /* 00340F64 paddub    $a0, $s1, $zero */
    .word 0x10000030 /* 00340F68 b          .L0034102C */
    .word 0x70001628 /* 00340F6C paddub    $v0, $zero, $zero */
    .word 0x8E390000 /* 00340F70 lw         $t9, 0x0($s1) */
    .word 0x8E250830 /* 00340F74 lw         $a1, 0x830($s1) */
    .word 0x24060001 /* 00340F78 addiu      $a2, $zero, 0x1 */
    .word 0x72202628 /* 00340F7C paddub     $a0, $s1, $zero */
    .word 0x70003E28 /* 00340F80 paddub     $a3, $zero, $zero */
    .word 0x8F3900D0 /* 00340F84 lw         $t9, 0xD0($t9) */
    .word 0x0320F809 /* 00340F88 jalr       $t9 */
    .word 0x3408FFFF /* 00340F8C ori       $t0, $zero, 0xFFFF */
    .word 0x10000026 /* 00340F90 b          .L0034102C */
    .word 0x24020001 /* 00340F94 addiu     $v0, $zero, 0x1 */
    .word 0x8E390000 /* 00340F98 lw         $t9, 0x0($s1) */
    .word 0x8F39001C /* 00340F9C lw         $t9, 0x1C($t9) */
    .word 0x0320F809 /* 00340FA0 jalr       $t9 */
    .word 0x24050001 /* 00340FA4 addiu     $a1, $zero, 0x1 */
    .word 0x10000020 /* 00340FA8 b          .L0034102C */
    .word 0x70001628 /* 00340FAC paddub    $v0, $zero, $zero */
    .word 0x2402000B /* 00340FB0 addiu      $v0, $zero, 0xB */
    .word 0x10A20011 /* 00340FB4 beq        $a1, $v0, .L00340FFC */
    .word 0x00000000 /* 00340FB8 nop */
    .word 0x24020011 /* 00340FBC addiu      $v0, $zero, 0x11 */
    .word 0x10A2000E /* 00340FC0 beq        $a1, $v0, .L00340FFC */
    .word 0x00000000 /* 00340FC4 nop */
    .word 0x2602FFF8 /* 00340FC8 addiu      $v0, $s0, -0x8 */
    .word 0x2C410002 /* 00340FCC sltiu      $at, $v0, 0x2 */
    .word 0x1020000A /* 00340FD0 beqz       $at, .L00340FFC */
    .word 0x00000000 /* 00340FD4 nop */
    .word 0x8E23084C /* 00340FD8 lw         $v1, 0x84C($s1) */
    .word 0x24020009 /* 00340FDC addiu      $v0, $zero, 0x9 */
    .word 0x16020004 /* 00340FE0 bne        $s0, $v0, .L00340FF4 */
    .word 0xAE230850 /* 00340FE4 sw        $v1, 0x850($s1) */
    .word 0x2402001C /* 00340FE8 addiu      $v0, $zero, 0x1C */
    .word 0x10000003 /* 00340FEC b          .L00340FFC */
    .word 0xAE22084C /* 00340FF0 sw        $v0, 0x84C($s1) */
    .word 0x2402001D /* 00340FF4 addiu      $v0, $zero, 0x1D */
    .word 0xAE22084C /* 00340FF8 sw         $v0, 0x84C($s1) */
    .word 0x8E22084C /* 00340FFC lw         $v0, 0x84C($s1) */
    .word 0x1202000A /* 00341000 beq        $s0, $v0, .L0034102C */
    .word 0x70001628 /* 00341004 paddub    $v0, $zero, $zero */
    .word 0x24020009 /* 00341008 addiu      $v0, $zero, 0x9 */
    .word 0x16020004 /* 0034100C bne        $s0, $v0, .L00341020 */
    .word 0x72202628 /* 00341010 paddub    $a0, $s1, $zero */
    jal func_0021A1C0
    .word 0x00000000 /* 00341018 nop */
    .word 0x72202628 /* 0034101C paddub     $a0, $s1, $zero */
    jal func_00341040
    .word 0x00000000 /* 00341024 nop */
    .word 0x70001628 /* 00341028 paddub     $v0, $zero, $zero */
    .word 0x7BBF0020 /* 0034102C lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* 00341030 lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 00341034 lq         $s0, 0x0($sp) */
}

asm void func_00341038(void) {
    .word 0x03E00008 /* 00341038 jr         $ra */
    .word 0x27BD0030 /* 0034103C addiu     $sp, $sp, 0x30 */
}

#else
int func_21A1C0(TacticalObj_340D70 *self);
void func_341040(TacticalObj_340D70 *self);
int func_2261c0();

int func_00340D70(TacticalObj_340D70 *self, int cmd, int arg2) {
    (void)arg2;
    if (self->field_840 == -1) {
        return 0;
    }

    int s0 = self->field_84C;

    if (cmd == 255) goto L_255;
    if (cmd == 18) goto L_18;
    if (cmd == 17) goto L_17;
    if (cmd == 16) goto L_16;
    if (cmd == 14) goto L_14;
    if (cmd == 13) goto L_13;
    if (cmd == 10) goto L_10;
    if (cmd == 12) goto L_12;
    if (cmd == 11) goto L_11;
    goto L_not_11;

L_11:
    self->field_84C = 12;
    self->field_83C = 12;
    goto L_fb0;

L_12:
L_10:
    if (s0 != 28) {
        self->field_84C = 14;
        if (self->field_840 == 0 && s0 != 8) {
            self->vfunc_d0(self->field_830, 1, 0, 0);
            return 1;
        }
    }
    goto L_fb0;

L_13:
    self->field_84C = 15;
    goto L_fb0;

L_14:
    self->field_84C = 19;
    goto L_fb0;

L_16:
L_17:
    if (s0 == 16) {
        self->field_84C = 22;
    } else if (s0 == 8) {
        self->field_84C = 24;
    } else if (s0 == 9) {
        self->field_84C = 23;
    } else {
        self->field_84C = 21;
    }
    goto L_fb0;

L_18:
    if (s0 == 9) {
        func_21A1C0(self);
    }
    if (s0 == 9) {
        self->field_84C = 25;
        func_341040(self);
        self->field_854 = func_2261c0();
        self->field_858 = 0;
    } else if (s0 == 8) {
        self->field_84C = 26;
        func_341040(self);
        self->field_854 = func_2261c0();
        self->field_858 = 0;
    } else if (s0 == 16) {
        self->field_84C = 27;
        func_341040(self);
        return 0;
    }
    self->vfunc_d0(self->field_830, 1, 0, 0xffff);
    return 1;

L_255:
    self->vfunc_1c(1);
    return 0;

L_fb0:
    if (cmd == 11) goto L_skip_850;
L_not_11:
    if (cmd == 17) goto L_skip_850;

    if ((unsigned int)(s0 - 8) < 2) {
        self->field_850 = self->field_84C;
        if (s0 == 9) {
            self->field_84C = 28;
        } else {
            self->field_84C = 29;
        }
    }

L_skip_850:
    if (s0 != self->field_84C) {
        if (s0 == 9) {
            func_21A1C0(self);
        }
        func_341040(self);
    }

    return 0;
}

#endif
}
