#pragma exceptions off
#include "unit_action_properties.h"

#if defined(__mips__)

asm void func_00267750(ActionExtended *self, int prop_id, float val) {
    .word 0x27BDFFD0 /* 00: addiu sp, sp, -0x30 */
    .word 0x7FBF0020 /* 04: sq ra, 0x20(sp) */
    .word 0x7FB00010 /* 08: sq s0, 0x10(sp) */
    .word 0xE7B40000 /* 0C: swc1 fs0, 0x0(sp) */
    .word 0x24030015 /* 10: addiu v1, zero, 0x15 */
    .word 0x46006506 /* 14: mov.s fs0, fa0 */
    .word 0x30A600FF /* 18: andi a1, a1, 0xff */
    .word 0x10C30030 /* 1C: beq a1, v1, 0xe0 */
    .word 0x70808628 /* 20: paddub s0, a0, zero */
    .word 0x24030001 /* 24: addiu v1, zero, 0x1 */
    .word 0x10C30013 /* 28: beq a1, v1, 0x78 */
    .word 0x00000000 /* 2C: nop  */
    .word 0x10C00003 /* 30: beqz a1, 0x40 */
    .word 0x00000000 /* 34: nop  */
    .word 0x10000041 /* 38: b 0x140 */
    .word 0x7BBF0020 /* 3C: lq ra, 0x20(sp) */
    .word 0x8E020004 /* 40: lw v0, 0x4(s0) */
    .word 0xC6000030 /* 44: lwc1 fv0, 0x30(s0) */
    .word 0x8442003E /* 48: lh v0, 0x3e(v0) */
    .word 0x46140042 /* 4C: mul.s fv0, fv0, fs0 */
    .word 0x44820000 /* 50: mtc1 v0, fv1 */
    .word 0x00000000 /* 54: nop  */
    .word 0x46800020 /* 58: cvt.s.w fv1, fv1 */
    jal func_00123350  /* 5C: jal func_00123350 */
    .word 0x46000B03 /* 60: div.s fa0, fv0, fv1 */
    .word 0x44820000 /* 64: mtc1 v0, fv0 */
    .word 0x00000000 /* 68: nop  */
    .word 0x46800020 /* 6C: cvt.s.w fv0, fv0 */
    .word 0x10000032 /* 70: b 0x13c */
    .word 0xE6000030 /* 74: swc1 fv0, 0x30(s0) */
    .word 0x8E030018 /* 78: lw v1, 0x18(s0) */
    .word 0x1060002F /* 7C: beqz v1, 0x13c */
    .word 0x00000000 /* 80: nop  */
    .word 0x92050039 /* 84: lbu a1, 0x39(s0) */
    .word 0x24030002 /* 88: addiu v1, zero, 0x2 */
    .word 0x14A3002B /* 8C: bne a1, v1, 0x13c */
    .word 0x00000000 /* 90: nop  */
    .word 0x8E190000 /* 94: lw t9, 0x0(s0) */
    .word 0x8E050008 /* 98: lw a1, 0x8(s0) */
    .word 0x2407FFFF /* 9C: addiu a3, zero, -0x1 */
    .word 0x70003628 /* A0: paddub a2, zero, zero */
    .word 0x8F3900F8 /* A4: lw t9, 0xf8(t9) */
    .word 0x0320F809 /* A8: jalr t9 */
    .word 0x70004628 /* AC: paddub a4, zero, zero */
    jal func_00123350  /* B0: jal func_00123350 */
    .word 0x4600A306 /* B4: mov.s fa0, fs0 */
    .word 0x8E190000 /* B8: lw t9, 0x0(s0) */
    .word 0x8E050008 /* BC: lw a1, 0x8(s0) */
    .word 0x72002628 /* C0: paddub a0, s0, zero */
    .word 0x70003628 /* C4: paddub a2, zero, zero */
    .word 0x70403E28 /* C8: paddub a3, v0, zero */
    .word 0x8F3900F4 /* CC: lw t9, 0xf4(t9) */
    .word 0x0320F809 /* D0: jalr t9 */
    .word 0x70004628 /* D4: paddub a4, zero, zero */
    .word 0x10000018 /* D8: b 0x13c */
    .word 0x00000000 /* DC: nop  */
    .word 0x8E060004 /* E0: lw a2, 0x4(s0) */
    .word 0x24030002 /* E4: addiu v1, zero, 0x2 */
    .word 0x90C40070 /* E8: lbu a0, 0x70(a2) */
    .word 0x14830013 /* EC: bne a0, v1, 0x13c */
    .word 0x00000000 /* F0: nop  */
    .word 0x84C5005A /* F4: lh a1, 0x5a(a2) */
    .word 0x04A00008 /* F8: bltz a1, 0x11c */
    .word 0x00000000 /* FC: nop  */
    .word 0x8E040008 /* 100: lw a0, 0x8(s0) */
    .word 0xC4C00060 /* 104: lwc1 fv0, 0x60(a2) */
    .word 0x8C991B30 /* 108: lw v0, 0x1b30(a0) */
    .word 0x70003628 /* 10C: paddub a2, zero, zero */
    .word 0x8F39007C /* 110: lw v0, 0x7c(v0) */
    .word 0x0320F809 /* 114: jalr v0 */
    .word 0x46000307 /* 118: neg.s fa0, fv0 */
    .word 0x8E040008 /* 11C: lw a0, 0x8(s0) */
    .word 0x8E020004 /* 120: lw v1, 0x4(s0) */
    .word 0x4600A306 /* 124: mov.s fa0, fs0 */
    .word 0x8C991B30 /* 128: lw v0, 0x1b30(a0) */
    .word 0x8445005A /* 12C: lh a1, 0x5a(v1) */
    .word 0x8F39007C /* 130: lw v0, 0x7c(v0) */
    .word 0x0320F809 /* 134: jalr v0 */
    .word 0x70003628 /* 138: paddub a2, zero, zero */
    .word 0x7BBF0020 /* 13C: lq ra, 0x20(sp) */
    .word 0x7BB00010 /* 140: lq s0, 0x10(sp) */
    .word 0xC7B40000 /* 144: lwc1 fs0, 0x0(sp) */
    .word 0x03E00008 /* 148: jr ra */
    .word 0x27BD0030 /* 14C: addiu sp, sp, 0x30 */
}

asm void func_002678A0(ActionExtended *self, int prop_id, float val) {
    .word 0x27BDFFD0 /* 00: addiu sp, sp, -0x30 */
    .word 0x7FBF0020 /* 04: sq ra, 0x20(sp) */
    .word 0x7FB00010 /* 08: sq s0, 0x10(sp) */
    .word 0xE7B40000 /* 0C: swc1 fs0, 0x0(sp) */
    .word 0x24030001 /* 10: addiu v1, zero, 0x1 */
    .word 0x46006506 /* 14: mov.s fs0, fa0 */
    .word 0x30A600FF /* 18: andi a1, a1, 0xff */
    .word 0x10C30017 /* 1C: beq a1, v1, 0x7c */
    .word 0x70808628 /* 20: paddub s0, a0, zero */
    .word 0x10C00003 /* 24: beqz a1, 0x34 */
    .word 0x00000000 /* 28: nop  */
    .word 0x1000002E /* 2C: b 0xe8 */
    .word 0x7BBF0020 /* 30: lq ra, 0x20(sp) */
    .word 0x8E030004 /* 34: lw v1, 0x4(s0) */
    .word 0x3C023F00 /* 38: lui v0, 0x3f00 */
    .word 0x44820000 /* 3C: mtc1 v0, fv0 */
    .word 0xC6010030 /* 40: lwc1 fv1, 0x30(s0) */
    .word 0x8462003E /* 44: lh v0, 0x3e(v1) */
    .word 0x44821000 /* 48: mtc1 v0, ft0 */
    .word 0x00000000 /* 4C: nop  */
    .word 0x468010A0 /* 50: cvt.s.w ft1, ft0 */
    .word 0x4602A500 /* 54: add.s ft0, fs0, ft1 */
    .word 0x46140842 /* 58: mul.s fv1, fv1, ft0 */
    .word 0x46020843 /* 5C: div.s fv1, fv1, ft1 */
    jal func_00123350  /* 60: jal func_00123350 */
    .word 0x46010300 /* 64: add.s fa0, fv0, fv1 */
    .word 0x44820000 /* 68: mtc1 v0, fv0 */
    .word 0x00000000 /* 6C: nop  */
    .word 0x46800020 /* 70: cvt.s.w fv0, fv0 */
    .word 0x1000001B /* 74: b 0xe4 */
    .word 0xE6000030 /* 78: swc1 fv0, 0x30(s0) */
    .word 0x8E030018 /* 7C: lw v1, 0x18(s0) */
    .word 0x10600018 /* 80: beqz v1, 0xe4 */
    .word 0x00000000 /* 84: nop  */
    .word 0x92050039 /* 88: lbu a1, 0x39(s0) */
    .word 0x24030002 /* 8C: addiu v1, zero, 0x2 */
    .word 0x14A30014 /* 90: bne a1, v1, 0xe4 */
    .word 0x00000000 /* 94: nop  */
    .word 0x8E190000 /* 98: lw t9, 0x0(s0) */
    .word 0x8E050008 /* 9C: lw a1, 0x8(s0) */
    .word 0x2407FFFF /* A0: addiu a3, zero, -0x1 */
    .word 0x70003628 /* A4: paddub a2, zero, zero */
    .word 0x8F3900F8 /* A8: lw t9, 0xf8(t9) */
    .word 0x0320F809 /* AC: jalr t9 */
    .word 0x70004628 /* B0: paddub a4, zero, zero */
    .word 0x8E020004 /* B4: lw v0, 0x4(s0) */
    .word 0xC440001C /* B8: lwc1 fv0, 0x1c(v0) */
    jal func_00123350  /* BC: jal func_00123350 */
    .word 0x46140300 /* C0: add.s fa0, fs0, fv0 */
    .word 0x8E190000 /* C4: lw t9, 0x0(s0) */
    .word 0x8E050008 /* C8: lw a1, 0x8(s0) */
    .word 0x72002628 /* CC: paddub a0, s0, zero */
    .word 0x70003628 /* D0: paddub a2, zero, zero */
    .word 0x70403E28 /* D4: paddub a3, v0, zero */
    .word 0x8F3900F4 /* D8: lw t9, 0xf4(t9) */
    .word 0x0320F809 /* DC: jalr t9 */
    .word 0x70004628 /* E0: paddub a4, zero, zero */
    .word 0x7BBF0020 /* E4: lq ra, 0x20(sp) */
    .word 0x7BB00010 /* E8: lq s0, 0x10(sp) */
    .word 0xC7B40000 /* EC: lwc1 fs0, 0x0(sp) */
    .word 0x03E00008 /* F0: jr ra */
    .word 0x27BD0030 /* F4: addiu sp, sp, 0x30 */
}

asm void func_002679A0(ActionExtended *self, int prop_id, float val) {
    .word 0x27BDFFD0 /* 00: addiu sp, sp, -0x30 */
    .word 0x7FBF0020 /* 04: sq ra, 0x20(sp) */
    .word 0x7FB00010 /* 08: sq s0, 0x10(sp) */
    .word 0xE7B40000 /* 0C: swc1 fs0, 0x0(sp) */
    .word 0x24030001 /* 10: addiu v1, zero, 0x1 */
    .word 0x46006506 /* 14: mov.s fs0, fa0 */
    .word 0x30A600FF /* 18: andi a1, a1, 0xff */
    .word 0x10C30011 /* 1C: beq a1, v1, 0x64 */
    .word 0x70808628 /* 20: paddub s0, a0, zero */
    .word 0x10C00003 /* 24: beqz a1, 0x34 */
    .word 0x00000000 /* 28: nop  */
    .word 0x10000028 /* 2C: b 0xd0 */
    .word 0x7BBF0020 /* 30: lq ra, 0x20(sp) */
    .word 0xC6010030 /* 34: lwc1 fv1, 0x30(s0) */
    .word 0x3C023F00 /* 38: lui v0, 0x3f00 */
    .word 0x44820000 /* 3C: mtc1 v0, fv0 */
    .word 0x00000000 /* 40: nop  */
    .word 0x46140842 /* 44: mul.s fv1, fv1, fs0 */
    jal func_00123350  /* 48: jal func_00123350 */
    .word 0x46010300 /* 4C: add.s fa0, fv0, fv1 */
    .word 0x44820000 /* 50: mtc1 v0, fv0 */
    .word 0x00000000 /* 54: nop  */
    .word 0x46800020 /* 58: cvt.s.w fv0, fv0 */
    .word 0x1000001B /* 5C: b 0xcc */
    .word 0xE6000030 /* 60: swc1 fv0, 0x30(s0) */
    .word 0x8E030018 /* 64: lw v1, 0x18(s0) */
    .word 0x10600018 /* 68: beqz v1, 0xcc */
    .word 0x00000000 /* 6C: nop  */
    .word 0x92050039 /* 70: lbu a1, 0x39(s0) */
    .word 0x24030002 /* 74: addiu v1, zero, 0x2 */
    .word 0x14A30014 /* 78: bne a1, v1, 0xcc */
    .word 0x00000000 /* 7C: nop  */
    .word 0x8E190000 /* 80: lw t9, 0x0(s0) */
    .word 0x8E050008 /* 84: lw a1, 0x8(s0) */
    .word 0x2407FFFF /* 88: addiu a3, zero, -0x1 */
    .word 0x70003628 /* 8C: paddub a2, zero, zero */
    .word 0x8F3900F8 /* 90: lw t9, 0xf8(t9) */
    .word 0x0320F809 /* 94: jalr t9 */
    .word 0x70004628 /* 98: paddub a4, zero, zero */
    .word 0x8E020004 /* 9C: lw v0, 0x4(s0) */
    .word 0xC440001C /* A0: lwc1 fv0, 0x1c(v0) */
    jal func_00123350  /* A4: jal func_00123350 */
    .word 0x46140302 /* A8: mul.s fa0, fv0, fs0 */
    .word 0x8E190000 /* AC: lw t9, 0x0(s0) */
    .word 0x8E050008 /* B0: lw a1, 0x8(s0) */
    .word 0x72002628 /* B4: paddub a0, s0, zero */
    .word 0x70003628 /* B8: paddub a2, zero, zero */
    .word 0x70403E28 /* BC: paddub a3, v0, zero */
    .word 0x8F3900F4 /* C0: lw t9, 0xf4(t9) */
    .word 0x0320F809 /* C4: jalr t9 */
    .word 0x70004628 /* C8: paddub a4, zero, zero */
    .word 0x7BBF0020 /* CC: lq ra, 0x20(sp) */
    .word 0x7BB00010 /* D0: lq s0, 0x10(sp) */
    .word 0xC7B40000 /* D4: lwc1 fs0, 0x0(sp) */
    .word 0x03E00008 /* D8: jr ra */
    .word 0x27BD0030 /* DC: addiu sp, sp, 0x30 */
}

#else

void func_00267750(ActionExtended *self, int prop_id, float val) {
    switch (prop_id & 0xFF) {
    case 0: {
        float f0 = (self->m_field30 * val) / (float)*(short*)((char*)self->m_field4 + 62);
        self->m_field30 = (float)func_123350(f0);
        break;
    }
    case 1:
        if (self->m_field18 != 0 && self->m_field39 == 2) {
            self->Method62(self->m_world, 0, -1, 0);
            int res = func_123350(val);
            self->Method61(self->m_world, 0, res, 0);
        }
        break;
    case 21: {
        void *field4 = self->m_field4;
        if (((unsigned char*)field4)[112] == 2) {
            short arg1 = *(short*)((char*)field4 + 90);
            if (arg1 >= 0) {
                WorldProps *world = (WorldProps*)self->m_world;
                float f0 = *(float*)((char*)field4 + 96);
                world->m_field1B30->Method7C(world, arg1, 0, -f0);
            }
            WorldProps *world = (WorldProps*)self->m_world;
            world->m_field1B30->Method7C(world, *(short*)((char*)self->m_field4 + 90), 0, val);
        }
        break;
    }
    }
}

void func_002678A0(ActionExtended *self, int prop_id, float val) {
    switch (prop_id & 0xFF) {
    case 0: {
        float val2 = (float)*(short*)((char*)self->m_field4 + 62);
        float f0 = (self->m_field30 * (val + val2)) / val2;
        self->m_field30 = (float)func_123350(0.5f + f0);
        break;
    }
    case 1:
        if (self->m_field18 != 0 && self->m_field39 == 2) {
            self->Method62(self->m_world, 0, -1, 0);
            float f0 = *(float*)((char*)self->m_field4 + 28);
            int res = func_123350(val + f0);
            self->Method61(self->m_world, 0, res, 0);
        }
        break;
    }
}

void func_002679A0(ActionExtended *self, int prop_id, float val) {
    switch (prop_id & 0xFF) {
    case 0: {
        float f0 = self->m_field30 * val;
        self->m_field30 = (float)func_123350(0.5f + f0);
        break;
    }
    case 1:
        if (self->m_field18 != 0 && self->m_field39 == 2) {
            self->Method62(self->m_world, 0, -1, 0);
            float f0 = *(float*)((char*)self->m_field4 + 28);
            int res = func_123350(f0 * val);
            self->Method61(self->m_world, 0, res, 0);
        }
        break;
    }
}

#endif
