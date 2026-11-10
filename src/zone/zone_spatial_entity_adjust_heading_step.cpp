#pragma exceptions off

#include "zone_spatial_entity_adjust_heading_step.h"

extern "C" {
#if defined(__mips__)
asm void func_001DF350(SpatialEntity *self, int a1) {
    .word 0x8C820010 /* 001DF350: lw $v0, 0x10($a0) */
    .word 0x50400004 /* 001DF354: beql $v0, $zero, lbl_1DF368 */
    .word 0x70001628 /* 001DF358: paddub $v0, $zero, $zero */
    .word 0x10000002 /* 001DF35C: b lbl_1DF368 */
    .word 0x9042003A /* 001DF360: lbu $v0, 0x3A($v0) */
    .word 0x70001628 /* 001DF364: paddub $v0, $zero, $zero */
lbl_1DF368:
    .word 0x28410008 /* 001DF368: slti $at, $v0, 0x8 */
    .word 0x10200002 /* 001DF36C: beqz $at, lbl_1DF378 */
    .word 0x00000000 /* 001DF370: nop */
    .word 0x24020008 /* 001DF374: addiu $v0, $zero, 0x8 */
lbl_1DF378:
    .word 0x44850000 /* 001DF378: mtc1 $a1, $f0 */
    .word 0x44820800 /* 001DF37C: mtc1 $v0, $f1 */
    .word 0x00000000 /* 001DF380: nop */
    .word 0x468000A0 /* 001DF384: cvt.s.w $f2, $f0 */
    .word 0xC783803C /* 001DF388: lwc1 $f3, -0x7FC4($gp) */
    .word 0x46800860 /* 001DF38C: cvt.s.w $f1, $f1 */
    .word 0xC480007C /* 001DF390: lwc1 $f0, 0x7C($a0) */
    .word 0x46021882 /* 001DF394: mul.s $f2, $f3, $f2 */
    .word 0x46011043 /* 001DF398: div.s $f1, $f2, $f1 */
    .word 0x46010300 /* 001DF39C: add.s $f12, $f0, $f1 */
    .word 0x44800000 /* 001DF3A0: mtc1 $zero, $f0 */
    .word 0x10000002 /* 001DF3A4: b lbl_1DF3B0 */
    .word 0x00000000 /* 001DF3A8: nop */
    .word 0x46036300 /* 001DF3AC: add.s $f12, $f12, $f3 */
lbl_1DF3B0:
    .word 0x46006034 /* 001DF3B0: c.lt.s $f12, $f0 */
    .word 0x00000000 /* 001DF3B4: nop */
    .word 0x4503FFFD /* 001DF3B8: bc1tl lbl_1DF3B0 */
    .word 0x46036300 /* 001DF3BC: add.s $f12, $f12, $f3 */
    .word 0x10000002 /* 001DF3C0: b lbl_1DF3CC */
    .word 0xC780803C /* 001DF3C4: lwc1 $f0, -0x7FC4($gp) */
    .word 0x46006301 /* 001DF3C8: sub.s $f12, $f12, $f0 */
lbl_1DF3CC:
    .word 0x46006034 /* 001DF3CC: c.lt.s $f12, $f0 */
    .word 0x00000000 /* 001DF3D0: nop */
    .word 0x4502FFFD /* 001DF3D4: bc1fl lbl_1DF3CC */
    .word 0x46006301 /* 001DF3D8: sub.s $f12, $f12, $f0 */
    .word 0x8C990000 /* 001DF3DC: lw $t9, 0x0($a0) */
    .word 0x8F3900C4 /* 001DF3E0: lw $t9, 0xC4($t9) */
    .word 0x03200008 /* 001DF3E4: jr $t9 */
    .word 0x00000000 /* 001DF3E8: nop */
}
#else
struct SpatialEntity {
    virtual void pad00();
    virtual void pad01(); virtual void pad02(); virtual void pad03(); virtual void pad04();
    virtual void pad05(); virtual void pad06(); virtual void pad07(); virtual void pad08();
    virtual void pad09(); virtual void pad0a(); virtual void pad0b(); virtual void pad0c();
    virtual void pad0d(); virtual void pad0e(); virtual void pad0f(); virtual void pad10();
    virtual void pad11(); virtual void pad12(); virtual void pad13(); virtual void pad14();
    virtual void pad15(); virtual void pad16(); virtual void pad17(); virtual void pad18();
    virtual void pad19(); virtual void pad1a(); virtual void pad1b(); virtual void pad1c();
    virtual void pad1d(); virtual void pad1e(); virtual void pad1f(); virtual void pad20();
    virtual void pad21(); virtual void pad22(); virtual void pad23(); virtual void pad24();
    virtual void pad25(); virtual void pad26(); virtual void pad27(); virtual void pad28();
    virtual void pad29(); virtual void pad2a(); virtual void pad2b(); virtual void pad2c();
    virtual void pad2d(); virtual void pad2e(); virtual void pad2f(); virtual void pad30();
    virtual void methodC4(float heading);

    char pad_after_vptr[0x0C];
    void *field_10;
    char pad_14[0x68];
    float heading;
};

struct SubObj {
    char pad[0x3A];
    unsigned char count;
};

void func_001DF350(SpatialEntity *self, int a1) {
    int count = 0;
    if (self->field_10 != 0) {
        count = ((SubObj *)self->field_10)->count;
    }
    if (count < 8) {
        count = 8;
    }

    const float two_pi = 6.283185307179586f;
    float delta_rad = (two_pi * (float)a1) / (float)count;
    float new_heading = self->heading + delta_rad;

    while (new_heading < 0.0f) {
        new_heading += two_pi;
    }
    while (!(new_heading < two_pi)) {
        new_heading -= two_pi;
    }

    self->methodC4(new_heading);
}
#endif
}
