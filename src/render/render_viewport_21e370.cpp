#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x0021E370 */
extern "C" {
void func_123908();
void func_102C88();
void func_104448();
void func_1045E8();
void func_104890();
void func_104600();
void func_104FA0();

asm void *func_0021E370(void *obj, short s5, short s4, short s3, short s2, short s1, short s0, short s7) {
    .word 0x27BDFEE0 /* addiu      $sp, $sp, -0x120 */
    .word 0x7FBF0080 /* sq         $ra, 0x80($sp) */
    .word 0x7FB70070 /* sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x3C020039 /* lui        $v0, 0x39 */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x24422BB0 /* addiu      $v0, $v0, (0x392BB0 & 0xFFFF) */
    .word 0x78420000 /* lq         $v0, 0x0($v0) */
    .word 0x27A30090 /* addiu      $v1, $sp, 0x90 */
    .word 0x7080B628 /* paddub     $s6, $a0, $zero */
    .word 0x70A0AE28 /* paddub     $s5, $a1, $zero */
    .word 0x70C0A628 /* paddub     $s4, $a2, $zero */
    .word 0x70E09E28 /* paddub     $s3, $a3, $zero */
    .word 0x71009628 /* paddub     $s2, $t0, $zero */
    .word 0x71208E28 /* paddub     $s1, $t1, $zero */
    .word 0x71408628 /* paddub     $s0, $t2, $zero */
    .word 0x7160BE28 /* paddub     $s7, $t3, $zero */
    .word 0x16C00004 /* bnez       $s6, .L0021E3DC */
    .word 0x7C620000 /* sq         $v0, 0x0($v1) */
    jal func_123908
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    .word 0x7040B628 /* paddub     $s6, $v0, $zero */
    .word 0x0010443C /* dsll32     $t0, $s0, 16 */
    .word 0x00174C3C /* dsll32     $t1, $s7, 16 */
    .word 0x00142C3C /* dsll32     $a1, $s4, 16 */
    .word 0x0013343C /* dsll32     $a2, $s3, 16 */
    .word 0x00123C3C /* dsll32     $a3, $s2, 16 */
    .word 0x27A400A0 /* addiu      $a0, $sp, 0xA0 */
    .word 0x0008443F /* dsra32     $t0, $t0, 16 */
    .word 0x00094C3F /* dsra32     $t1, $t1, 16 */
    .word 0x00052C3F /* dsra32     $a1, $a1, 16 */
    .word 0x0006343F /* dsra32     $a2, $a2, 16 */
    jal func_102C88
    .word 0x00073C3F /* dsra32     $a3, $a3, 16 */
    .word 0x001512C3 /* sra        $v0, $s5, 11 */
    .word 0x304901FF /* andi       $t1, $v0, 0x1FF */
    .word 0x001112C3 /* sra        $v0, $s1, 11 */
    .word 0x304301FF /* andi       $v1, $v0, 0x1FF */
    .word 0x00131183 /* sra        $v0, $s3, 6 */
    .word 0x304A003F /* andi       $t2, $v0, 0x3F */
    .word 0x93A200A3 /* lbu        $v0, 0xA3($sp) */
    .word 0x240BFFC0 /* addiu      $t3, $zero, -0x40 */
    .word 0x3C0100CA /* lui        $at, (0xCA158C >> 16) */
    .word 0xA433158C /* sh         $s3, (0xCA158C & 0xFFFF)($at) */
    .word 0x3C0100CA /* lui        $at, (0xCA158E >> 16) */
    .word 0x3285003F /* andi       $a1, $s4, 0x3F */
    .word 0x004B1024 /* and        $v0, $v0, $t3 */
    .word 0x00451025 /* or         $v0, $v0, $a1 */
    .word 0xA3A200A3 /* sb         $v0, 0xA3($sp) */
    .word 0x93A200A2 /* lbu        $v0, 0xA2($sp) */
    .word 0x2408FE00 /* addiu      $t0, $zero, -0x200 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    .word 0x70003628 /* paddub     $a2, $zero, $zero */
    .word 0x004B1024 /* and        $v0, $v0, $t3 */
    .word 0x004A1025 /* or         $v0, $v0, $t2 */
    .word 0xA3A200A2 /* sb         $v0, 0xA2($sp) */
    .word 0x97A200A0 /* lhu        $v0, 0xA0($sp) */
    .word 0x70003E28 /* paddub     $a3, $zero, $zero */
    .word 0xA432158E /* sh         $s2, (0xCA158E & 0xFFFF)($at) */
    .word 0x00481024 /* and        $v0, $v0, $t0 */
    .word 0x00491025 /* or         $v0, $v0, $t1 */
    .word 0xA7A200A0 /* sh         $v0, 0xA0($sp) */
    .word 0x97A200B0 /* lhu        $v0, 0xB0($sp) */
    .word 0x00481024 /* and        $v0, $v0, $t0 */
    .word 0x00431025 /* or         $v0, $v0, $v1 */
    jal func_104448
    .word 0xA7A200B0 /* sh         $v0, 0xB0($sp) */
    .word 0x27A20090 /* addiu      $v0, $sp, 0x90 */
    .word 0x78450000 /* lq         $a1, 0x0($v0) */
    jal func_1045E8
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x27A500A0 /* addiu      $a1, $sp, 0xA0 */
    .word 0x24060008 /* addiu      $a2, $zero, 0x8 */
    jal func_104890
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    jal func_104600
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    jal func_104FA0
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    .word 0x72C01628 /* paddub     $v0, $s6, $zero */
    .word 0x7BBF0080 /* lq         $ra, 0x80($sp) */
    .word 0x7BB70070 /* lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0120 /* addiu      $sp, $sp, 0x120 */
}
}

#else

extern "C" {
void *func_123908(void *obj);
void func_102C88(void *buffer, int a1, int a2, int a3, int a4, int a5);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_104890(void *obj, void *data, int count);
void *func_104600(void *obj);
void func_104FA0(void *obj);

struct ViewportTag {
    unsigned int words[4];
};

extern ViewportTag D_392BB0;
extern unsigned short D_00CA158C;
extern unsigned short D_00CA158E;

void *func_0021E370(void *obj, short s5, short s4, short s3, short s2,
                    short s1, short s0, short s7) {
    ViewportTag tag = D_392BB0;

    if (obj == 0) {
        obj = func_123908(0);
    }

    unsigned char buf[128];
    func_102C88(buf, (short)s4, (short)s3, (short)s2, (short)s0, (short)s7);

    int t1 = (s5 >> 11) & 0x1FF;
    int v1 = (s1 >> 11) & 0x1FF;
    int t2 = (s3 >> 6) & 0x3F;

    D_00CA158C = (unsigned short)s3;
    buf[3] = (unsigned char)((buf[3] & -0x40) | (s4 & 0x3F));
    buf[2] = (unsigned char)((buf[2] & -0x40) | t2);
    D_00CA158E = (unsigned short)s2;
    *(unsigned short *)(buf + 0) = (unsigned short)((*(unsigned short *)(buf + 0) & -0x200) | t1);
    *(unsigned short *)(buf + 16) = (unsigned short)((*(unsigned short *)(buf + 16) & -0x200) | v1);

    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, &tag);
    func_104890(obj, buf, 8);
    func_104600(obj);
    func_104FA0(0);
    return obj;
}
}

#endif
