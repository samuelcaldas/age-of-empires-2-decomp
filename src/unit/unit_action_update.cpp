#pragma exceptions off
#include "unit_action_update.h"

extern "C" {
void func_2643c0(void *action);
char func_26AD20(void *action, int flag);
void func_0026A540(void *action, int flag);
int func_00183070(void *fieldC);
int func_262ba0(int target, unsigned char field35);

#if defined(__mips__)
asm void func_00268200(ActionRebind *self, unsigned char new_state) {
    .word 0x27BDFFC0 /* 00268200 addiu      $sp, $sp, -0x40 */
    .word 0x7FBF0030 /* 00268204 sq         $ra, 0x30($sp) */
    .word 0x7FB20020 /* 00268208 sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 0026820C sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 00268210 sq         $s0, 0x0($sp) */
    .word 0x90830039 /* 00268214 lbu        $v1, 0x39($a0) */
    .word 0x30B000FF /* 00268218 andi       $s0, $a1, 0xFF */
    .word 0x70809628 /* 0026821C paddub     $s2, $a0, $zero */
    .word 0x1070006B /* 00268220 beq        $v1, $s0, .L002683D0 */
    .word 0x70A08E28 /* 00268224 paddub    $s1, $a1, $zero */
    .word 0x0203082A /* 00268228 slt        $at, $s0, $v1 */
    .word 0x50200004 /* 0026822C beql       $at, $zero, .L00268240 */
    .word 0x2A020003 /* 00268230 slti      $v0, $s0, 0x3 */
    .word 0x16000066 /* 00268234 bnez       $s0, .L002683D0 */
    .word 0x00000000 /* 00268238 nop */
    .word 0x2A020003 /* 0026823C slti       $v0, $s0, 0x3 */
    .word 0x1440000F /* 00268240 bnez       $v0, .L00268280 */
    .word 0x00000000 /* 00268244 nop */
    .word 0x28610003 /* 00268248 slti       $at, $v1, 0x3 */
    .word 0x1020000C /* 0026824C beqz       $at, .L00268280 */
    .word 0x00000000 /* 00268250 nop */
    jal func_2643c0
    .word 0x72402628 /* 00268258 paddub    $a0, $s2, $zero */
    .word 0x8E430004 /* 0026825C lw         $v1, 0x4($s2) */
    .word 0x24020002 /* 00268260 addiu      $v0, $zero, 0x2 */
    .word 0x90630090 /* 00268264 lbu        $v1, 0x90($v1) */
    .word 0x14620005 /* 00268268 bne        $v1, $v0, .L00268280 */
    .word 0x00000000 /* 0026826C nop */
    .word 0x8E590000 /* 00268270 lw         $t9, 0x0($s2) */
    .word 0x8F390078 /* 00268274 lw         $t9, 0x78($t9) */
    .word 0x0320F809 /* 00268278 jalr       $t9 */
    .word 0x72402628 /* 0026827C paddub    $a0, $s2, $zero */
    .word 0x92420039 /* 00268280 lbu        $v0, 0x39($s2) */
    .word 0x28410004 /* 00268284 slti       $at, $v0, 0x4 */
    .word 0x10200009 /* 00268288 beqz       $at, .L002682B0 */
    .word 0x2A010003 /* 0026828C slti      $at, $s0, 0x3 */
    .word 0x2A020007 /* 00268290 slti       $v0, $s0, 0x7 */
    .word 0x14400005 /* 00268294 bnez       $v0, .L002682AC */
    .word 0x00000000 /* 00268298 nop */
    .word 0x8E590000 /* 0026829C lw         $t9, 0x0($s2) */
    .word 0x8F390074 /* 002682A0 lw         $t9, 0x74($t9) */
    .word 0x0320F809 /* 002682A4 jalr       $t9 */
    .word 0x72402628 /* 002682A8 paddub    $a0, $s2, $zero */
    .word 0x2A010003 /* 002682AC slti       $at, $s0, 0x3 */
    .word 0x10200003 /* 002682B0 beqz       $at, .L002682C0 */
    .word 0x00000000 /* 002682B4 nop */
    .word 0x1600001F /* 002682B8 bnez       $s0, .L00268338 */
    .word 0x00000000 /* 002682BC nop */
    .word 0x92430039 /* 002682C0 lbu        $v1, 0x39($s2) */
    .word 0x24020002 /* 002682C4 addiu      $v0, $zero, 0x2 */
    .word 0x1462001B /* 002682C8 bne        $v1, $v0, .L00268338 */
    .word 0x00000000 /* 002682CC nop */
    .word 0x8E420018 /* 002682D0 lw         $v0, 0x18($s2) */
    .word 0x10400018 /* 002682D4 beqz       $v0, .L00268338 */
    .word 0x00000000 /* 002682D8 nop */
    .word 0x8E590000 /* 002682DC lw         $t9, 0x0($s2) */
    .word 0x8E450008 /* 002682E0 lw         $a1, 0x8($s2) */
    .word 0x2407FFFF /* 002682E4 addiu      $a3, $zero, -0x1 */
    .word 0x72402628 /* 002682E8 paddub     $a0, $s2, $zero */
    .word 0x70003628 /* 002682EC paddub     $a2, $zero, $zero */
    .word 0x8F3900F8 /* 002682F0 lw         $t9, 0xF8($t9) */
    .word 0x0320F809 /* 002682F4 jalr       $t9 */
    .word 0x70004628 /* 002682F8 paddub    $t0, $zero, $zero */
    .word 0x8E420004 /* 002682FC lw         $v0, 0x4($s2) */
    .word 0x44800000 /* 00268300 mtc1       $zero, $f0 */
    .word 0xC441001C /* 00268304 lwc1       $f1, 0x1C($v0) */
    .word 0x46000836 /* 00268308 c.le.s     $f1, $f0 */
    .word 0x00000000 /* 0026830C nop */
    .word 0x45010009 /* 00268310 bc1t       .L00268338 */
    .word 0x00000000 /* 00268314 nop */
    .word 0x8E590000 /* 00268318 lw         $t9, 0x0($s2) */
    .word 0x8E450008 /* 0026831C lw         $a1, 0x8($s2) */
    .word 0x24060001 /* 00268320 addiu      $a2, $zero, 0x1 */
    .word 0x2407FFFF /* 00268324 addiu      $a3, $zero, -0x1 */
    .word 0x8F3900F4 /* 00268328 lw         $t9, 0xF4($t9) */
    .word 0x72402628 /* 0026832C paddub     $a0, $s2, $zero */
    .word 0x0320F809 /* 00268330 jalr       $t9 */
    .word 0x70004628 /* 00268334 paddub    $t0, $zero, $zero */
    .word 0x92420039 /* 00268338 lbu        $v0, 0x39($s2) */
    .word 0x28410007 /* 0026833C slti       $at, $v0, 0x7 */
    .word 0x10200017 /* 00268340 beqz       $at, .L002683A0 */
    .word 0x24050001 /* 00268344 addiu     $a1, $zero, 0x1 */
    .word 0x24020007 /* 00268348 addiu      $v0, $zero, 0x7 */
    .word 0x16020013 /* 0026834C bne        $s0, $v0, .L0026839C */
    .word 0x00000000 /* 00268350 nop */
    .word 0x8E420018 /* 00268354 lw         $v0, 0x18($s2) */
    .word 0x10400010 /* 00268358 beqz       $v0, .L0026839C */
    .word 0x00000000 /* 0026835C nop */
    .word 0x8E420004 /* 00268360 lw         $v0, 0x4($s2) */
    .word 0x44800000 /* 00268364 mtc1       $zero, $f0 */
    .word 0xC441001C /* 00268368 lwc1       $f1, 0x1C($v0) */
    .word 0x46000836 /* 0026836C c.le.s     $f1, $f0 */
    .word 0x00000000 /* 00268370 nop */
    .word 0x45010009 /* 00268374 bc1t       .L0026839C */
    .word 0x00000000 /* 00268378 nop */
    .word 0x8E590000 /* 0026837C lw         $t9, 0x0($s2) */
    .word 0x8E450008 /* 00268380 lw         $a1, 0x8($s2) */
    .word 0x24060001 /* 00268384 addiu      $a2, $zero, 0x1 */
    .word 0x2407FFFF /* 00268388 addiu      $a3, $zero, -0x1 */
    .word 0x8F3900F8 /* 0026838C lw         $t9, 0xF8($t9) */
    .word 0x72402628 /* 00268390 paddub     $a0, $s2, $zero */
    .word 0x0320F809 /* 00268394 jalr       $t9 */
    .word 0x70004628 /* 00268398 paddub    $t0, $zero, $zero */
    .word 0x24050001 /* 0026839C addiu      $a1, $zero, 0x1 */
    .word 0x72402628 /* 002683A0 paddub     $a0, $s2, $zero */
    jal func_26AD20
    .word 0xA2510039 /* 002683A8 sb        $s1, 0x39($s2) */
    .word 0x10400008 /* 002683AC beqz       $v0, .L002683D0 */
    .word 0x00000000 /* 002683B0 nop */
    .word 0x92440039 /* 002683B4 lbu        $a0, 0x39($s2) */
    .word 0x24030002 /* 002683B8 addiu      $v1, $zero, 0x2 */
    .word 0x10830004 /* 002683BC beq        $a0, $v1, .L002683D0 */
    .word 0x00000000 /* 002683C0 nop */
    .word 0x72402628 /* 002683C4 paddub     $a0, $s2, $zero */
    jal func_0026A540
    .word 0x70002E28 /* 002683CC paddub    $a1, $zero, $zero */
    .word 0x7BBF0030 /* 002683D0 lq         $ra, 0x30($sp) */
    .word 0x7BB20020 /* 002683D4 lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 002683D8 lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 002683DC lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 002683E0 jr         $ra */
    .word 0x27BD0040 /* 002683E4 addiu     $sp, $sp, 0x40 */
}

asm int func_002683F0(ActionRebind *self) {
    .word 0x90820039 /* 002683F0 lbu        $v0, 0x39($a0) */
    .word 0x28410003 /* 002683F4 slti       $at, $v0, 0x3 */
    .word 0x24020001 /* 002683F8 addiu      $v0, $zero, 0x1 */
    .word 0x03E00008 /* 002683FC jr         $ra */
    .word 0x0001100B /* 00268400 movn      $v0, $zero, $at */
}

asm int func_00268410(ActionRebind *self) {
    .word 0x27BDFFF0 /* 00268410 addiu      $sp, $sp, -0x10 */
    .word 0x7FBF0000 /* 00268414 sq         $ra, 0x0($sp) */
    .word 0x8C890010 /* 00268418 lw         $t1, 0x10($a0) */
    .word 0x15200003 /* 0026841C bnez       $t1, .L0026842C */
    .word 0x00000000 /* 00268420 nop */
    .word 0x1000000E /* 00268424 b          .L00268460 */
    .word 0x70001628 /* 00268428 paddub    $v0, $zero, $zero */
    .word 0x8C82000C /* 0026842C lw         $v0, 0xC($a0) */
    .word 0x10400006 /* 00268430 beqz       $v0, .L0026844C */
    .word 0x00000000 /* 00268434 nop */
    .word 0x908A0035 /* 00268438 lbu        $t2, 0x35($a0) */
    jal func_00183070
    .word 0x70402628 /* 00268440 paddub    $a0, $v0, $zero */
    .word 0x10000006 /* 00268444 b          .L00268460 */
    .word 0x304200FF /* 00268448 andi      $v0, $v0, 0xFF */
    .word 0x90820035 /* 0026844C lbu        $v0, 0x35($a0) */
    .word 0x70005628 /* 00268450 paddub     $t2, $zero, $zero */
    .word 0x71202628 /* 00268454 paddub     $a0, $t1, $zero */
    jal func_262ba0
    .word 0x70404E28 /* 0026845C paddub    $t1, $v0, $zero */
    .word 0x7BBF0000 /* 00268460 lq         $ra, 0x0($sp) */
    .word 0x03E00008 /* 00268464 jr         $ra */
    .word 0x27BD0010 /* 00268468 addiu     $sp, $sp, 0x10 */
}

asm void func_00268470(ActionRebind *self, int arg) {
    .word 0x27BDFFF0 /* 00268470 addiu      $sp, $sp, -0x10 */
    .word 0x7FBF0000 /* 00268474 sq         $ra, 0x0($sp) */
    .word 0x70A03628 /* 00268478 paddub     $a2, $a1, $zero */
    .word 0x8C850010 /* 0026847C lw         $a1, 0x10($a0) */
    .word 0x10A00008 /* 00268480 beqz       $a1, .L002684A4 */
    .word 0x00000000 /* 00268484 nop */
    .word 0x8C84000C /* 00268488 lw         $a0, 0xC($a0) */
    .word 0x10800005 /* 0026848C beqz       $a0, .L002684A4 */
    .word 0x00000000 /* 00268490 nop */
    .word 0x8C990008 /* 00268494 lw         $t9, 0x8($a0) */
    .word 0x8F390024 /* 00268498 lw         $t9, 0x24($t9) */
    .word 0x0320F809 /* 0026849C jalr       $t9 */
    .word 0x00000000 /* 002684A0 nop */
    .word 0x7BBF0000 /* 002684A4 lq         $ra, 0x0($sp) */
    .word 0x03E00008 /* 002684A8 jr         $ra */
    .word 0x27BD0010 /* 002684AC addiu     $sp, $sp, 0x10 */
}

asm int func_002684B0(ActionRebind *self) {
    .word 0x27BDFFF0 /* 002684B0 addiu      $sp, $sp, -0x10 */
    .word 0x7FBF0000 /* 002684B4 sq         $ra, 0x0($sp) */
    .word 0x8C850010 /* 002684B8 lw         $a1, 0x10($a0) */
    .word 0x10A0000B /* 002684BC beqz       $a1, .L002684EC */
    .word 0x70001628 /* 002684C0 paddub    $v0, $zero, $zero */
    .word 0x8C84000C /* 002684C4 lw         $a0, 0xC($a0) */
    .word 0x10800007 /* 002684C8 beqz       $a0, .L002684E8 */
    .word 0x00000000 /* 002684CC nop */
    .word 0x8C990008 /* 002684D0 lw         $t9, 0x8($a0) */
    .word 0x8F39000C /* 002684D4 lw         $t9, 0xC($t9) */
    .word 0x0320F809 /* 002684D8 jalr       $t9 */
    .word 0x00000000 /* 002684DC nop */
    .word 0x10000003 /* 002684E0 b          .L002684F0 */
    .word 0x7BBF0000 /* 002684E4 lq        $ra, 0x0($sp) */
    .word 0x70001628 /* 002684E8 paddub     $v0, $zero, $zero */
    .word 0x7BBF0000 /* 002684EC lq         $ra, 0x0($sp) */
    .word 0x03E00008 /* 002684F0 jr         $ra */
    .word 0x27BD0010 /* 002684F4 addiu     $sp, $sp, 0x10 */
}

asm int func_00268500(ActionRebind *self) {
    .word 0x8C82001C /* 00268500 lw         $v0, 0x1C($a0) */
    .word 0x0002102B /* 00268504 sltu       $v0, $zero, $v0 */
    .word 0x38420001 /* 00268508 xori       $v0, $v0, 0x1 */
    .word 0x50400004 /* 0026850C beql       $v0, $zero, .L00268520 */
    .word 0x304200FF /* 00268510 andi      $v0, $v0, 0xFF */
    .word 0x8C820020 /* 00268514 lw         $v0, 0x20($a0) */
    .word 0x0002102B /* 00268518 sltu       $v0, $zero, $v0 */
    .word 0x304200FF /* 0026851C andi       $v0, $v0, 0xFF */
    .word 0x03E00008 /* 00268520 jr         $ra */
    .word 0x00000000 /* 00268524 nop */
}

#else
#pragma exceptions off
#include "unit_action_update.h"

void func_00268200(ActionRebind *self, unsigned char new_state) {
    if (self->m_field39 == new_state) {
        return;
    }
    if (new_state < self->m_field39 && new_state != 0) {
        return;
    }

    if (new_state >= 3 && self->m_field39 < 3) {
        func_2643C0(self);
        if (*(unsigned char*)((char*)self->m_field4 + 144) == 2) {
            self->Method30();
        }
    }

    if (self->m_field39 < 4) {
        if (new_state >= 7) {
            self->Method29();
        }
    }

    if (new_state >= 3) {
        if (self->m_field39 == 2 && self->m_field18 != 0) {
            self->Method62(self->m_world, 0, -1, 0);
            if (*(float*)((char*)self->m_field4 + 28) > 0.0f) {
                self->Method61(self->m_world, 1, -1, 0);
            }
        }
    }

    if (self->m_field39 < 7) {
        if (new_state == 7 && self->m_field18 != 0) {
            if (*(float*)((char*)self->m_field4 + 28) > 0.0f) {
                self->Method62(self->m_world, 1, -1, 0);
            }
        }
    }

    self->m_field39 = new_state;

    if (func_26AD20(self, 1) != 0) {
        if (self->m_field39 != 2) {
            func_26A540(self, 0);
        }
    }
}

int func_002683F0(ActionRebind *self) {
    return self->m_field39 >= 3;
}

int func_00268410(ActionRebind *self) {
    if (self->m_field10 == 0) {
        return 0;
    }
    if (self->m_fieldC != 0) {
        return (unsigned char)func_183070(self->m_fieldC);
    }
    return (unsigned char)func_262BA0(self->m_field10, self->m_field35);
}

void func_00268470(ActionRebind *self, int arg) {
    if (self->m_field10 == 0) {
        return;
    }
    if (self->m_fieldC == 0) {
        return;
    }
    typedef void (*Method36Fn)(void *fieldC, int target, int arg);
    void *sub = *(void**)((char*)self->m_fieldC + 8);
    Method36Fn method36 = *(Method36Fn*)((char*)sub + 36);
    method36(self->m_fieldC, self->m_field10, arg);
}

int func_002684B0(ActionRebind *self) {
    int res = 0;
    if (self->m_field10 != 0 && self->m_fieldC != 0) {
        typedef int (*Method12Fn)(void *fieldC, int target);
        void *sub = *(void**)((char*)self->m_fieldC + 8);
        Method12Fn method12 = *(Method12Fn*)((char*)sub + 12);
        res = method12(self->m_fieldC, self->m_field10);
    }
    return res;
}

int func_00268500(ActionRebind *self) {
    if ((unsigned int)self->m_field1C != 0) {
        return 0;
    }
    return (unsigned int)self->m_field20 != 0;
}

#endif
}
