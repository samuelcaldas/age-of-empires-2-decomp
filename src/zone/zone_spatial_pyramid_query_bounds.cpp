#pragma exceptions off

#include "zone_spatial_pyramid_query_bounds.h"

extern "C" {
void *func_333500(void *mgr);
void func_3335C0(void *mgr, void *field_8);
int func_1D2DE0(void *self, void *item, int p2, int p3, int p4, float min_x, float min_y, float max_x, float max_y, float p9);
void func_1FD4E0(void *out_point, void *item, int index);
int func_00123350(float val);
}

#if defined(__mips__)

extern "C" asm int func_001D2C70(void *self, float min_x, float min_y, float max_x, float max_y, float *out_x, float *out_y) {
    .word 0x27BDFF60 /* 001D2C70: addiu      $sp, $sp, -0xA0 */
    .word 0x7FBF0080 /* 001D2C74: sq         $ra, 0x80($sp) */
    .word 0x7FB60070 /* 001D2C78: sq         $s6, 0x70($sp) */
    .word 0x7FB50060 /* 001D2C7C: sq         $s5, 0x60($sp) */
    .word 0x7FB40050 /* 001D2C80: sq         $s4, 0x50($sp) */
    .word 0x7FB30040 /* 001D2C84: sq         $s3, 0x40($sp) */
    .word 0x7FB20030 /* 001D2C88: sq         $s2, 0x30($sp) */
    .word 0x7FB10020 /* 001D2C8C: sq         $s1, 0x20($sp) */
    .word 0x7FB00010 /* 001D2C90: sq         $s0, 0x10($sp) */
    .word 0xE7B7000C /* 001D2C94: swc1       $f23, 0xC($sp) */
    .word 0xE7B60008 /* 001D2C98: swc1       $f22, 0x8($sp) */
    .word 0xE7B50004 /* 001D2C9C: swc1       $f21, 0x4($sp) */
    .word 0xE7B40000 /* 001D2CA0: swc1       $f20, 0x0($sp) */
    .word 0x8F8289C0 /* 001D2CA4: lw         $v0, -0x7640($gp) */
    .word 0x70809E28 /* 001D2CA8: paddub     $s3, $a0, $zero */
    .word 0x460065C6 /* 001D2CAC: mov.s      $f23, $f12 */
    .word 0x46006D86 /* 001D2CB0: mov.s      $f22, $f13 */
    .word 0x46007546 /* 001D2CB4: mov.s      $f21, $f14 */
    .word 0x46007D06 /* 001D2CB8: mov.s      $f20, $f15 */
    .word 0x8C440404 /* 001D2CBC: lw         $a0, 0x404($v0) */
    .word 0x70A09628 /* 001D2CC0: paddub     $s2, $a1, $zero */
    .word 0x70C0B628 /* 001D2CC4: paddub     $s6, $a2, $zero */
    jal func_333500  /* 001D2CC8: jal        func_333500 */
    .word 0x7000AE28 /* 001D2CCC: paddub     $s5, $zero, $zero */
    .word 0x70408628 /* 001D2CD0: paddub     $s0, $v0, $zero */
    .word 0x12000032 /* 001D2CD4: beqz       $s0, .L001D2DA0 */
    .word 0x72A01628 /* 001D2CD8: paddub     $v0, $s5, $zero */
    .word 0x44808800 /* 001D2CDC: mtc1       $zero, $f17 */
    .word 0x4600BB06 /* 001D2CE0: mov.s      $f12, $f23 */
    .word 0x4600B346 /* 001D2CE4: mov.s      $f13, $f22 */
    .word 0x4600AB86 /* 001D2CE8: mov.s      $f14, $f21 */
    .word 0x4600A3C6 /* 001D2CEC: mov.s      $f15, $f20 */
    .word 0x72602628 /* 001D2CF0: paddub     $a0, $s3, $zero */
    .word 0x46008C06 /* 001D2CF4: mov.s      $f16, $f17 */
    .word 0x72002E28 /* 001D2CF8: paddub     $a1, $s0, $zero */
    .word 0x70003628 /* 001D2CFC: paddub     $a2, $zero, $zero */
    .word 0x70003E28 /* 001D2D00: paddub     $a3, $zero, $zero */
    jal func_1D2DE0  /* 001D2D04: jal        func_1D2DE0 */
    .word 0x70004628 /* 001D2D08: paddub     $t0, $zero, $zero */
    .word 0x304200FF /* 001D2D0C: andi       $v0, $v0, 0xFF */
    .word 0x1040001E /* 001D2D10: beqz       $v0, .L001D2D8C */
    .word 0x00000000 /* 001D2D14: nop */
    .word 0x1000001A /* 001D2D18: b          .L001D2D84 */
    .word 0x82110020 /* 001D2D1C: lb         $s1, 0x20($s0) */
    .word 0x2626FFFF /* 001D2D20: addiu      $a2, $s1, -0x1 */
    /* .L001D2D24: */
    .word 0x27A40090 /* 001D2D24: addiu      $a0, $sp, 0x90 */
    jal func_1FD4E0  /* 001D2D28: jal        func_1FD4E0 */
    .word 0x72002E28 /* 001D2D2C: paddub     $a1, $s0, $zero */
    .word 0xC7AC0090 /* 001D2D30: lwc1       $f12, 0x90($sp) */
    .word 0xC7B50098 /* 001D2D34: lwc1       $f21, 0x98($sp) */
    .word 0x8E740000 /* 001D2D38: lw         $s4, 0x0($s3) */
    jal func_00123350 /* 001D2D3C: jal       func_00123350 */
    .word 0x46006506 /* 001D2D40: mov.s      $f20, $f12 */
    .word 0x8E830000 /* 001D2D44: lw         $v1, 0x0($s4) */
    .word 0x00021080 /* 001D2D48: sll        $v0, $v0, 2 */
    .word 0x4600AB06 /* 001D2D4C: mov.s      $f12, $f21 */
    jal func_00123350 /* 001D2D50: jal       func_00123350 */
    .word 0x0062A021 /* 001D2D54: addu       $s4, $v1, $v0 */
    .word 0x00021840 /* 001D2D58: sll        $v1, $v0, 1 */
    .word 0x8E820000 /* 001D2D5C: lw         $v0, 0x0($s4) */
    .word 0x00431021 /* 001D2D60: addu       $v0, $v0, $v1 */
    .word 0x90420000 /* 001D2D64: lbu        $v0, 0x0($v0) */
    .word 0x50400006 /* 001D2D68: beql       $v0, $zero, .L001D2D84 */
    .word 0x2631FFFF /* 001D2D6C: addiu      $s1, $s1, -0x1 */
    .word 0xE6540000 /* 001D2D70: swc1       $f20, 0x0($s2) */
    .word 0xE6D50000 /* 001D2D74: swc1       $f21, 0x0($s6) */
    .word 0x10000004 /* 001D2D78: b          .L001D2D8C */
    .word 0x64150001 /* 001D2D7C: daddiu     $s5, $zero, 0x1 */
    .word 0x2631FFFF /* 001D2D80: addiu      $s1, $s1, -0x1 */
    /* .L001D2D84: */
    .word 0x1E20FFE7 /* 001D2D84: bgtz       $s1, .L001D2D24 */
    .word 0x2626FFFF /* 001D2D88: addiu      $a2, $s1, -0x1 */
    /* .L001D2D8C: */
    .word 0x8F8289C0 /* 001D2D8C: lw         $v0, -0x7640($gp) */
    .word 0x8C440404 /* 001D2D90: lw         $a0, 0x404($v0) */
    jal func_3335C0  /* 001D2D94: jal        func_3335C0 */
    .word 0x8E050008 /* 001D2D98: lw         $a1, 0x8($s0) */
    .word 0x72A01628 /* 001D2D9C: paddub     $v0, $s5, $zero */
    /* .L001D2DA0: */
    .word 0x7BBF0080 /* 001D2DA0: lq         $ra, 0x80($sp) */
    .word 0x7BB60070 /* 001D2DA4: lq         $s6, 0x70($sp) */
    .word 0x7BB50060 /* 001D2DA8: lq         $s5, 0x60($sp) */
    .word 0x7BB40050 /* 001D2DAC: lq         $s4, 0x50($sp) */
    .word 0x7BB30040 /* 001D2DB0: lq         $s3, 0x40($sp) */
    .word 0x7BB20030 /* 001D2DB4: lq         $s2, 0x30($sp) */
    .word 0x7BB10020 /* 001D2DB8: lq         $s1, 0x20($sp) */
    .word 0x7BB00010 /* 001D2DBC: lq         $s0, 0x10($sp) */
    .word 0xC7B7000C /* 001D2DC0: lwc1       $f23, 0xC($sp) */
    .word 0xC7B60008 /* 001D2DC4: lwc1       $f22, 0x8($sp) */
    .word 0xC7B50004 /* 001D2DC8: lwc1       $f21, 0x4($sp) */
    .word 0xC7B40000 /* 001D2DCC: lwc1       $f20, 0x0($sp) */
    .word 0x03E00008 /* 001D2DD0: jr         $ra */
    .word 0x27BD00A0 /* 001D2DD4: addiu      $sp, $sp, 0xA0 */
}

#else

extern "C" int func_001D2C70(void *self, float min_x, float min_y, float max_x, float max_y, float *out_x, float *out_y) {
    void *item = func_333500(self);
    if (!item) {
        return 0;
    }

    int success = 0;
    if (func_1D2DE0(self, item, 0, 0, 0, min_x, min_y, max_x, max_y, 0.0f) & 0xFF) {
        char *zm = (char *)self;
        void ***root = *(void ****)(zm + 0x0);
        int count = *(char *)((char *)item + 0x20);
        for (int i = count - 1; i >= 0; i--) {
            struct {
                float x;
                float z;
                float y;
            } pt;
            func_1FD4E0(&pt, item, i);

            int ix = func_00123350(pt.x);
            int iy = func_00123350(pt.y);

            char *cell = (char *)root[0][ix] + iy * 2;
            if (*(unsigned char *)cell != 0) {
                if (out_x) *out_x = pt.x;
                if (out_y) *out_y = pt.y;
                success = 1;
                break;
            }
        }
    }

    func_3335C0(self, *(void **)((char *)item + 0x8));
    return success;
}

#endif
