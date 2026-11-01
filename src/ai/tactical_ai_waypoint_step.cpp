#pragma once
#pragma exceptions off

#include "tactical_ai_waypoint_step.h"

#if defined(__mips__)

extern "C" asm void func_00307A00(WaypointActionManager *self) {
    addiu      $sp, $sp, -0x40
    sq         $ra, 0x30($sp)
    sq         $s2, 0x20($sp)
    sq         $s1, 0x10($sp)
    sq         $s0, 0x0($sp)
    lbu        $v1, 0x1B2($a0)
    sll        $s1, $v1, 2
    addu       $v1, $s1, $a0
    lw         $v1, 0x1D4($v1)
    beqz       $v1, lbl_307A94
    paddub     $s0, $a0, $zero
    jal        func_00186010
    lw         $a0, -0x7640($gp)
    addu       $v1, $s1, $s0
    lwc1       $f12, 0x210($v1)
    lwc1       $f13, 0x224($v1)
    paddub     $a0, $v0, $zero
    jal        func_204920
    paddub     $a1, $zero, $zero
    lbu        $v0, 0x1B2($s0)
    lw         $a0, -0x7640($gp)
    jal        func_00186010
    sll        $s1, $v0, 2
    paddub     $s2, $v0, $zero
    addu       $v0, $s1, $s0
    jal        func_00123350
    lwc1       $f12, 0x210($v0)
    addu       $v1, $s1, $s0
    lwc1       $f12, 0x224($v1)
    jal        func_00123350
    paddub     $s1, $v0, $zero
    paddub     $a0, $s2, $zero
    paddub     $a1, $s1, $zero
    jal        func_204910
    paddub     $a2, $v0, $zero
    b          lbl_307B28
    lbu        $v1, 0x1B2($s0)
lbl_307A94:
    lw         $a0, 0x1D0($s0)
    addiu      $v1, $zero, -0x1
    beq        $a0, $v1, lbl_307B60
    nop
    lbu        $v1, 0x1D0($s0)
    sb         $v1, 0x1B2($s0)
    lbu        $v1, 0x1B2($s0)
    sll        $s1, $v1, 2
    addu       $v1, $s1, $s0
    lw         $v1, 0x1D4($v1)
    beqz       $v1, lbl_307B24
    nop
    jal        func_00186010
    lw         $a0, -0x7640($gp)
    addu       $v1, $s1, $s0
    lwc1       $f12, 0x210($v1)
    lwc1       $f13, 0x224($v1)
    paddub     $a0, $v0, $zero
    jal        func_204920
    paddub     $a1, $zero, $zero
    lbu        $v0, 0x1B2($s0)
    lw         $a0, -0x7640($gp)
    jal        func_00186010
    sll        $s1, $v0, 2
    paddub     $s2, $v0, $zero
    addu       $v0, $s1, $s0
    jal        func_00123350
    lwc1       $f12, 0x210($v0)
    addu       $v1, $s1, $s0
    lwc1       $f12, 0x224($v1)
    jal        func_00123350
    paddub     $s1, $v0, $zero
    paddub     $a0, $s2, $zero
    paddub     $a1, $s1, $zero
    jal        func_204910
    paddub     $a2, $v0, $zero
lbl_307B24:
    lbu        $v1, 0x1B2($s0)
lbl_307B28:
    addiu      $v1, $v1, -0x1
    sb         $v1, 0x1B2($s0)
    lbu        $v1, 0x1B2($s0)
    slti       $at, $v1, 0x80
    bnez       $at, lbl_307B60
    nop
    lbu        $v1, 0x1B3($s0)
    beqz       $v1, lbl_307B58
    nop
    addiu      $v1, $zero, 0x4
    b          lbl_307B60
    sb         $v1, 0x1B2($s0)
lbl_307B58:
    lbu        $v1, 0x1D0($s0)
    sb         $v1, 0x1B2($s0)
lbl_307B60:
    lq         $ra, 0x30($sp)
    lq         $s2, 0x20($sp)
    lq         $s1, 0x10($sp)
    lq         $s0, 0x0($sp)
    jr         $ra
    addiu      $sp, $sp, 0x40
}

#else

static inline void RenderWaypoint(WaypointActionManager *self, unsigned char idx) {
    void *v0 = func_186010(D_004E3180);
    func_204920(v0, 0, self->m_array4[idx], self->m_array5[idx]);

    int v0_idx = (unsigned char)self->m_field1B2;
    void *s2 = func_186010(D_004E3180);
    int tx = func_123350(self->m_array4[v0_idx]);
    int ty = func_123350(self->m_array5[v0_idx]);
    func_204910(s2, tx, ty);
}

void func_00307A00(WaypointActionManager *self) {
    unsigned char idx = self->m_field1B2;
    if (self->m_array1[idx]) {
        RenderWaypoint(self, idx);
    } else {
        if (self->m_field1D0 == -1) {
            return;
        }
        self->m_field1B2 = (unsigned char)self->m_field1D0;
        idx = self->m_field1B2;
        if (self->m_array1[idx]) {
            RenderWaypoint(self, idx);
        }
    }

    self->m_field1B2--;
    if (self->m_field1B2 >= 128) {
        if (self->m_field1B3) {
            self->m_field1B2 = 4;
        } else {
            self->m_field1B2 = (unsigned char)self->m_field1D0;
        }
    }
}

#endif
