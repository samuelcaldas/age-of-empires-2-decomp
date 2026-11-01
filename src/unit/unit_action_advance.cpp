#pragma exceptions off
#include "unit_action_advance.h"

#if defined(__mips__)

asm void func_00268DE0(ActionRebind *self) {
    .word 0x27BDFFC0 /* addiu      $sp, $sp, -0x40 */
    .word 0x7FBF0020 /* sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x70808E28 /* paddub     $s1, $a0, $zero */
    .word 0x8E390000 /* lw         $t9, 0x0($s1) */
    .word 0x8F390088 /* lw         $t9, 0x88($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x00000000 /* nop */
    .word 0xC6220030 /* lwc1       $f2, 0x30($s1) */
    .word 0x3C033F80 /* lui        $v1, (0x3F800000 >> 16) */
    .word 0x44830800 /* mtc1       $v1, $f1 */
    .word 0x00000000 /* nop */
    .word 0x46001001 /* sub.s      $f0, $f2, $f0 */
    .word 0x46010034 /* c.lt.s     $f0, $f1 */
    .word 0x00000000 /* nop */
    .word 0x45000005 /* bc1f       .L00268E38 */
    .word 0xE6200030 /* swc1      $f0, 0x30($s1) */
    .word 0x72202628 /* paddub     $a0, $s1, $zero */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    jal        func_0026A540
    .word 0xAE200030 /* sw        $zero, 0x30($s1) */
    .word 0x8E230004 /* lw         $v1, 0x4($s1) */
    .word 0x8C630038 /* lw         $v1, 0x38($v1) */
    .word 0x10600015 /* beqz       $v1, .L00268E98 */
    .word 0x00000000 /* nop */
    jal        func_001AAB30
    .word 0x00000000 /* nop */
    .word 0x27A50038 /* addiu      $a1, $sp, 0x38 */
    .word 0x27A6003C /* addiu      $a2, $sp, 0x3C */
    .word 0x70408628 /* paddub     $s0, $v0, $zero */
    jal        func_0026A700
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x1040000A /* beqz       $v0, .L00268E90 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x8E220004 /* lw         $v0, 0x4($s1) */
    .word 0x2408FFFF /* addiu      $t0, $zero, -0x1 */
    .word 0x8FA60038 /* lw         $a2, 0x38($sp) */
    .word 0x8FA7003C /* lw         $a3, 0x3C($sp) */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    .word 0x8C440038 /* lw         $a0, 0x38($v0) */
    jal        func_25F6E0
    .word 0x71004E28 /* paddub    $t1, $t0, $zero */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    jal        func_1AAB70
    .word 0x00000000 /* nop */
    .word 0x7BBF0020 /* lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0040 /* addiu     $sp, $sp, 0x40 */
}

asm float func_00268EB0(int count, void *arr, float scale) {
    .word 0x44800000 /* mtc1       $zero, $f0 */
    .word 0x10C0000F /* beqz       $a2, .L00268EF4 */
    .word 0x00000000 /* nop */
    .word 0x1000000A /* b          .L00268EE8 */
    .word 0x70001E28 /* paddub    $v1, $zero, $zero */
    .word 0x00031080 /* sll        $v0, $v1, 2 */
    .word 0x00C21021 /* addu       $v0, $a2, $v0 */
    .word 0x84420002 /* lh         $v0, 0x2($v0) */
    .word 0x24630001 /* addiu      $v1, $v1, 0x1 */
    .word 0x44820800 /* mtc1       $v0, $f1 */
    .word 0x00000000 /* nop */
    .word 0x46800860 /* cvt.s.w    $f1, $f1 */
    .word 0x46016042 /* mul.s      $f1, $f12, $f1 */
    .word 0x46010000 /* add.s      $f0, $f0, $f1 */
    .word 0x0065102A /* slt        $v0, $v1, $a1 */
    .word 0x1440FFF6 /* bnez       $v0, .L00268EC8 */
    .word 0x00031080 /* sll       $v0, $v1, 2 */
    .word 0x03E00008 /* jr         $ra */
    .word 0x00000000 /* nop */
}

asm void func_00268F00(ActionRebind *self, int delta) {
    .word 0x8C830010 /* lw         $v1, 0x10($a0) */
    .word 0x90820035 /* lbu        $v0, 0x35($a0) */
    .word 0x9063003A /* lbu        $v1, 0x3A($v1) */
    .word 0x10000002 /* b          .L00268F18 */
    .word 0x00451021 /* addu      $v0, $v0, $a1 */
    .word 0x00431021 /* addu       $v0, $v0, $v1 */
    .word 0x0442FFFF /* bltzl      $v0, .L00268F18 */
    .word 0x00431021 /* addu      $v0, $v0, $v1 */
    .word 0x10000003 /* b          .L00268F30 */
    .word 0x0043082A /* slt       $at, $v0, $v1 */
    .word 0x00431023 /* subu       $v0, $v0, $v1 */
    .word 0x0043082A /* slt        $at, $v0, $v1 */
    .word 0x5020FFFE /* beql       $at, $zero, .L00268F2C */
    .word 0x00431023 /* subu      $v0, $v0, $v1 */
    j          func_0026A680
    .word 0x304500FF /* andi      $a1, $v0, 0xFF */
}

asm void func_00268F40(ActionRebind *self, short val, float fval) {
    .word 0xA485003C /* sh         $a1, 0x3C($a0) */
    .word 0x03E00008 /* jr         $ra */
    .word 0xE48C0040 /* swc1      $f12, 0x40($a0) */
    .word 0x00000000 /* nop */
}

asm void func_00268F50(ActionRebind *self, int add_flag, int clamp_flag, float delta) {
    .word 0x10A00005 /* beqz       $a1, .L00268F68 */
    .word 0x00000000 /* nop */
    .word 0xC4800040 /* lwc1       $f0, 0x40($a0) */
    .word 0x460C0000 /* add.s      $f0, $f0, $f12 */
    .word 0x10000002 /* b          .L00268F6C */
    .word 0xE4800040 /* swc1      $f0, 0x40($a0) */
    .word 0xE48C0040 /* swc1       $f12, 0x40($a0) */
    .word 0x10C0000C /* beqz       $a2, .L00268FA0 */
    .word 0x00000000 /* nop */
    .word 0x8C830004 /* lw         $v1, 0x4($a0) */
    .word 0xC4800040 /* lwc1       $f0, 0x40($a0) */
    .word 0x84630054 /* lh         $v1, 0x54($v1) */
    .word 0x44830800 /* mtc1       $v1, $f1 */
    .word 0x00000000 /* nop */
    .word 0x46800860 /* cvt.s.w    $f1, $f1 */
    .word 0x46010036 /* c.le.s     $f0, $f1 */
    .word 0x00000000 /* nop */
    .word 0x45010002 /* bc1t       .L00268FA0 */
    .word 0x00000000 /* nop */
    .word 0xE4810040 /* swc1       $f1, 0x40($a0) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x00000000 /* nop */
}

asm int func_00268FB0(ActionRebind *self, float delta) {
    .word 0xC4810030 /* lwc1       $f1, 0x30($a0) */
    .word 0x44800000 /* mtc1       $zero, $f0 */
    .word 0x00000000 /* nop */
    .word 0x46006034 /* c.lt.s     $f12, $f0 */
    .word 0x460C0800 /* add.s      $f0, $f1, $f12 */
    .word 0x4500000A /* bc1f       .L00268FF0 */
    .word 0xE4800030 /* swc1      $f0, 0x30($a0) */
    .word 0xC4810030 /* lwc1       $f1, 0x30($a0) */
    .word 0x3C023F80 /* lui        $v0, (0x3F800000 >> 16) */
    .word 0x44820000 /* mtc1       $v0, $f0 */
    .word 0x00000000 /* nop */
    .word 0x46000834 /* c.lt.s     $f1, $f0 */
    .word 0x00000000 /* nop */
    .word 0x45000002 /* bc1f       .L00268FF0 */
    .word 0x00000000 /* nop */
    .word 0xAC820030 /* sw         $v0, 0x30($a0) */
    .word 0x8C820004 /* lw         $v0, 0x4($a0) */
    .word 0xC4800030 /* lwc1       $f0, 0x30($a0) */
    .word 0x8442003E /* lh         $v0, 0x3E($v0) */
    .word 0x44820800 /* mtc1       $v0, $f1 */
    .word 0x00000000 /* nop */
    .word 0x46800860 /* cvt.s.w    $f1, $f1 */
    .word 0x46010034 /* c.lt.s     $f0, $f1 */
    .word 0x00000000 /* nop */
    .word 0x45010005 /* bc1t       .L00269028 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x10000002 /* b          .L00269028 */
    .word 0xE4810030 /* swc1      $f1, 0x30($a0) */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* jr         $ra */
    .word 0x00000000 /* nop */
}



#else

void func_00268DE0(ActionRebind *self) {
    float elapsed = self->Method32();
    float val = self->m_field30 - elapsed;
    if (val < 1.0f) {
        self->m_field30 = val;
        func_0026A540(self, 0);
        self->m_field30 = 0.0f;
    }

    void *field4 = self->m_field4;
    void *field38 = *(void**)((char*)field4 + 0x38);
    if (field38 != 0) {
        int obj = func_001AAB30();
        int arg1, arg2;
        int res = func_26A700(self, &arg1, &arg2);
        if (res != 0) {
            void *f4 = self->m_field4;
            void *f38 = *(void**)((char*)f4 + 0x38);
            func_25F6E0(f38, 1, arg1, arg2, -1, -1);
        }
        func_001AAB70(obj);
    }
}

float func_00268EB0(int count, void *arr, float scale) {
    float sum = 0.0f;
    if (arr != 0) {
        for (int i = 0; i < count; i++) {
            short val = *(short*)((char*)arr + i * 4 + 2);
            sum += scale * (float)val;
        }
    }
    return sum;
}

void func_00268F00(ActionRebind *self, int delta) {
    void *field10 = (void*)self->m_field10;
    int cur = self->m_field35;
    int total = *(unsigned char*)((char*)field10 + 0x3A);
    cur += delta;
    while (cur < 0) {
        cur += total;
    }
    while (cur >= total) {
        cur -= total;
    }
    func_26A680(self, (unsigned char)cur);
}

void func_00268F40(ActionRebind *self, short val, float fval) {
    self->m_field3C = val;
    *(float*)((char*)self + 0x40) = fval;
}

void func_00268F50(ActionRebind *self, int add_flag, int clamp_flag, float delta) {
    if (add_flag != 0) {
        *(float*)((char*)self + 0x40) += delta;
    } else {
        *(float*)((char*)self + 0x40) = delta;
    }
    if (clamp_flag != 0) {
        void *field4 = self->m_field4;
        float limit = (float)*(short*)((char*)field4 + 0x54);
        if (*(float*)((char*)self + 0x40) > limit) {
            *(float*)((char*)self + 0x40) = limit;
        }
    }
}

int func_00268FB0(ActionRebind *self, float delta) {
    float f1 = self->m_field30;
    self->m_field30 = f1 + delta;
    if (delta < 0.0f && self->m_field30 < 1.0f) {
        self->m_field30 = 1.0f;
    }

    void *field4 = self->m_field4;
    float limit = (float)*(short*)((char*)field4 + 0x3E);
    if (self->m_field30 < limit) {
        return 0;
    }
    self->m_field30 = limit;
    return 1;
}

#endif
