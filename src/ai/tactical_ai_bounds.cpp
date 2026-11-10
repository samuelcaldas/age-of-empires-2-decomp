#include "sub_list.h"

#pragma exceptions off

extern "C" {
void *memset(void *dst, int val, unsigned int size);
void *func_117CAC(void *dst, int val, unsigned int size);
void func_144310(void *ptr);
void func_144340(void *ptr, int a1, int a2);
int func_21A3F0(int a0);
int func_0021A3F0(int a0);
int func_142980(void *ptr);
int func_143860(void *ptr);
int func_143440(void *ptr);
}

struct TacticalItem {
    int m_field00;
    char m_name[1024];
    int m_field404;
    int m_field408;
    int m_field40C;
    int m_field410;
    int m_field414;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_004[0x190 - 4];
    int m_field190;
    int m_field194;
    int m_field198;
    int m_field19C;
    char pad_1A0[0x2A8 - 0x1A0];
    char m_name[1024];
    char *m_field6A8;
    int m_field6AC;
    int m_field6B0;
    int m_field6B4;
    int m_field6B8;
    int m_field6BC;
    int m_item_count;
    TacticalItem m_items[10];
    int m_stack_count;
    int m_stack[50];
    int m_field3080;
};

extern "C" {

int func_00142560(TacticalAI2 *self, int a1);

#if defined(__mips__)

asm int func_001424A0(TacticalAI2 *self, int a1, int a2, int a3, int t0) {
    .word 0x27BDFFD0 /* addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0xAC850190 /* sw         $a1, 0x190($a0) */
    .word 0xAC8806B4 /* sw         $t0, 0x6B4($a0) */
    .word 0xAC873080 /* sw         $a3, 0x3080($a0) */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0xAC800194 /* sw         $zero, 0x194($a0) */
    .word 0xAC820198 /* sw         $v0, 0x198($a0) */
    .word 0xAC8006C0 /* sw         $zero, 0x6C0($a0) */
    .word 0x70C08628 /* paddub     $s0, $a2, $zero */
    .word 0x70808E28 /* paddub     $s1, $a0, $zero */
    .word 0xAC802FB4 /* sw         $zero, 0x2FB4($a0) */
    .word 0x262406C4 /* addiu      $a0, $s1, 0x6C4 */
    .word 0x240628F0 /* addiu      $a2, $zero, 0x28F0 */
    jal        func_117CAC
    .word 0x70002E28 /* paddub    $a1, $zero, $zero */
    .word 0x26242FB8 /* addiu      $a0, $s1, 0x2FB8 */
    .word 0x240600C8 /* addiu      $a2, $zero, 0xC8 */
    jal        func_117CAC
    .word 0x70002E28 /* paddub    $a1, $zero, $zero */
    jal        func_144310
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x72002E28 /* paddub     $a1, $s0, $zero */
    jal        func_00142560
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x14400003 /* bnez       $v0, .L0014251C */
    .word 0x00000000 /* nop */
    .word 0x1000000B /* b          .L00142544 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x8E220194 /* lw         $v0, 0x194($s1) */
    .word 0x14400008 /* bnez       $v0, .L00142544 */
    .word 0x24020001 /* addiu     $v0, $zero, 0x1 */
    .word 0x24050012 /* addiu      $a1, $zero, 0x12 */
    .word 0x72202628 /* paddub     $a0, $s1, $zero */
    jal        func_144340
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x10000002 /* b          .L00142544 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x7BBF0020 /* lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0030 /* addiu     $sp, $sp, 0x30 */
}


asm int func_00142560(TacticalAI2 *self, int a1) {
    .word 0x27BDFFD0 /* addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0xAC8506AC /* sw         $a1, 0x6AC($a0) */
    .word 0x8C902FB4 /* lw         $s0, 0x2FB4($a0) */
    .word 0x70808E28 /* paddub     $s1, $a0, $zero */
    .word 0x262202A8 /* addiu      $v0, $s1, 0x2A8 */
    .word 0xA08002A8 /* sb         $zero, 0x2A8($a0) */
    .word 0xAC8206A8 /* sw         $v0, 0x6A8($a0) */
    .word 0xAC8006B0 /* sw         $zero, 0x6B0($a0) */
    jal        func_0021A3F0
    .word 0x70A02628 /* paddub    $a0, $a1, $zero */
    .word 0xAE2206B8 /* sw         $v0, 0x6B8($s1) */
    .word 0x72202628 /* paddub     $a0, $s1, $zero */
    jal        func_142980
    .word 0xAE2006BC /* sw        $zero, 0x6BC($s1) */
    .word 0x1000001F /* b          .L00142624 */
    .word 0x24030002 /* addiu     $v1, $zero, 0x2 */
    .word 0x8E23019C /* lw         $v1, 0x19C($s1) */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x14620008 /* bne        $v1, $v0, .L001425D8 */
    .word 0x24020002 /* addiu     $v0, $zero, 0x2 */
    jal        func_143860
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x14400014 /* bnez       $v0, .L00142618 */
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x10000025 /* b          .L00142664 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x24020002 /* addiu      $v0, $zero, 0x2 */
    .word 0x10620008 /* beq        $v1, $v0, .L001425FC */
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x2405000F /* addiu      $a1, $zero, 0xF */
    .word 0x72202628 /* paddub     $a0, $s1, $zero */
    jal        func_144340
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x1000001C /* b          .L00142664 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x72202628 /* paddub     $a0, $s1, $zero */
    jal        func_143440
    .word 0x00000000 /* nop */
    .word 0x14400003 /* bnez       $v0, .L00142614 */
    .word 0x00000000 /* nop */
    .word 0x10000015 /* b          .L00142664 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x72202628 /* paddub     $a0, $s1, $zero */
    jal        func_142980
    .word 0x00000000 /* nop */
    .word 0x24030002 /* addiu      $v1, $zero, 0x2 */
    .word 0x1043FFE1 /* beq        $v0, $v1, .L001425AC */
    .word 0x00000000 /* nop */
    .word 0x14400003 /* bnez       $v0, .L0014263C */
    .word 0x00000000 /* nop */
    .word 0x1000000B /* b          .L00142664 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x8E222FB4 /* lw         $v0, 0x2FB4($s1) */
    .word 0x12020008 /* beq        $s0, $v0, .L00142664 */
    .word 0x24020001 /* addiu     $v0, $zero, 0x1 */
    .word 0x2405000A /* addiu      $a1, $zero, 0xA */
    .word 0x72202628 /* paddub     $a0, $s1, $zero */
    jal        func_144340
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x10000002 /* b          .L00142664 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x7BBF0020 /* lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0030 /* addiu     $sp, $sp, 0x30 */
}


#else

int func_001424A0(TacticalAI2 *self, int a1, int a2, int a3, int t0) {
    self->m_field190 = a1;
    self->m_field6B4 = t0;
    self->m_field3080 = a3;
    self->m_field194 = 0;
    self->m_field198 = 1;
    self->m_item_count = 0;
    self->m_stack_count = 0;
    memset(self->m_items, 0, 0x28F0);
    memset(self->m_stack, 0, 0xC8);
    func_144310(self);
    if (!func_00142560(self, a2)) {
        return 0;
    }
    if (!self->m_field194) {
        func_144340(self, 0x12, 0);
        return 0;
    }
    return 1;
}

int func_00142560(TacticalAI2 *self, int a1) {
    self->m_field6AC = a1;
    int saved_stack = self->m_stack_count;
    self->m_name[0] = 0;
    self->m_field6A8 = self->m_name;
    self->m_field6B0 = 0;
    self->m_field6B8 = func_21A3F0(a1);
    self->m_field6BC = 0;
    int tok = func_142980(self);
    while (tok == 2) {
        if (self->m_field19C == 1) {
            if (!func_143860(self)) {
                return 0;
            }
        } else if (self->m_field19C == 2) {
            if (!func_143440(self)) {
                return 0;
            }
        } else {
            func_144340(self, 0xF, 0);
            return 0;
        }
        tok = func_142980(self);
    }
    if (tok != 0) {
        return 0;
    }
    if (self->m_stack_count != saved_stack) {
        func_144340(self, 0xA, 0);
        return 0;
    }
    return 1;
}

#endif

}
