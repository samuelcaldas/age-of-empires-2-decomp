#pragma exceptions off
#include "sub_list.h"

struct TacticalAI2;

extern "C" {
extern const char D_48E100[];

int func_142980(void *self);
void func_144340(void *self, int code, void *param);
void *func_26B0A0(void *table, const char *name, int a2);
int func_00142CC0(void *self);
int func_00143020(TacticalAI2 *self, int a1);
int func_001427A0(void *self);
int func_1446A0(void *ptr);
#if defined(__mips__)
int atoi(const char *str);
#else
int func_114378(const char *str);
#define atoi func_114378
#endif
void *func_00142730(void *self, const char *token);
}

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0xC];
    char *field_10;
    char pad_14[0x20];
    char field_34[0xC];
    int field_40;
    char pad_44[0x158];
    int field_19C;
    char field_1A0[0x100];
};

#if defined(__mips__)
extern "C" {

asm int func_00143020(TacticalAI2 *self, int a1) {
    .word 0x27BDFFB0 /* 00143020: addiu      $sp, $sp, -0x50 */
    .word 0x7FBF0040 /* 00143024: sq         $ra, 0x40($sp) */
    .word 0x7FB30030 /* 00143028: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 0014302C: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 00143030: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 00143034: sq         $s0, 0x0($sp) */
    .word 0x14A00019 /* 00143038: bnez       $a1, .L001430A0 */
    .word 0x70809E28 /* 0014303C: paddub    $s3, $a0, $zero */
    jal        func_142980 /* 00143040 */
    .word 0x00000000 /* 00143044: nop */
    .word 0x24030002 /* 00143048: addiu      $v1, $zero, 0x2 */
    .word 0x1043000B /* 0014304C: beq        $v0, $v1, .L0014307C */
    .word 0x00000000 /* 00143050: nop */
    .word 0x24030001 /* 00143054: addiu      $v1, $zero, 0x1 */
    .word 0x14430006 /* 00143058: bne        $v0, $v1, .L00143074 */
    .word 0x70001628 /* 0014305C: paddub    $v0, $zero, $zero */
    .word 0x2405001A /* 00143060: addiu      $a1, $zero, 0x1A */
    .word 0x72602628 /* 00143064: paddub     $a0, $s3, $zero */
    jal        func_144340 /* 00143068 */
    .word 0x70003628 /* 0014306C: paddub    $a2, $zero, $zero */
    .word 0x70001628 /* 00143070: paddub     $v0, $zero, $zero */
    .word 0x100000E9 /* 00143074: b          .L0014341C */
    .word 0x7BBF0040 /* 00143078: lq        $ra, 0x40($sp) */
    .word 0x8E62019C /* 0014307C: lw         $v0, 0x19C($s3) */
    .word 0x10430008 /* 00143080: beq        $v0, $v1, .L001430A4 */
    .word 0x72602628 /* 00143084: paddub    $a0, $s3, $zero */
    .word 0x2405000F /* 00143088: addiu      $a1, $zero, 0xF */
    .word 0x72602628 /* 0014308C: paddub     $a0, $s3, $zero */
    jal        func_144340 /* 00143090 */
    .word 0x70003628 /* 00143094: paddub    $a2, $zero, $zero */
    .word 0x100000DF /* 00143098: b          .L00143418 */
    .word 0x70001628 /* 0014309C: paddub    $v0, $zero, $zero */
    .word 0x72602628 /* 001430A0: paddub     $a0, $s3, $zero */
    jal        func_142980 /* 001430A4 */
    .word 0x00000000 /* 001430A8: nop */
    .word 0x24030002 /* 001430AC: addiu      $v1, $zero, 0x2 */
    .word 0x1043000B /* 001430B0: beq        $v0, $v1, .L001430E0 */
    .word 0x00000000 /* 001430B4: nop */
    .word 0x24030001 /* 001430B8: addiu      $v1, $zero, 0x1 */
    .word 0x14430006 /* 001430BC: bne        $v0, $v1, .L001430D8 */
    .word 0x70001628 /* 001430C0: paddub    $v0, $zero, $zero */
    .word 0x2405001A /* 001430C4: addiu      $a1, $zero, 0x1A */
    .word 0x72602628 /* 001430C8: paddub     $a0, $s3, $zero */
    jal        func_144340 /* 001430CC */
    .word 0x70003628 /* 001430D0: paddub    $a2, $zero, $zero */
    .word 0x70001628 /* 001430D4: paddub     $v0, $zero, $zero */
    .word 0x100000CF /* 001430D8: b          .L00143418 */
    .word 0x00000000 /* 001430DC: nop */
    .word 0x8E62019C /* 001430E0: lw         $v0, 0x19C($s3) */
    .word 0x24060001 /* 001430E4: addiu      $a2, $zero, 0x1 */
    .word 0x10460008 /* 001430E8: beq        $v0, $a2, .L0014310C */
    .word 0x26640034 /* 001430EC: addiu     $a0, $s3, 0x34 */
    .word 0x2405000C /* 001430F0: addiu      $a1, $zero, 0xC */
    .word 0x72602628 /* 001430F4: paddub     $a0, $s3, $zero */
    jal        func_144340 /* 001430F8 */
    .word 0x70003628 /* 001430FC: paddub    $a2, $zero, $zero */
    .word 0x100000C5 /* 00143100: b          .L00143418 */
    .word 0x70001628 /* 00143104: paddub    $v0, $zero, $zero */
    .word 0x26640034 /* 00143108: addiu      $a0, $s3, 0x34 */
    jal        func_26B0A0 /* 0014310C */
    .word 0x266501A0 /* 00143110: addiu     $a1, $s3, 0x1A0 */
    .word 0x70408628 /* 00143114: paddub     $s0, $v0, $zero */
    .word 0x12000032 /* 00143118: beqz       $s0, .L001431E4 */
    .word 0x26640034 /* 0014311C: addiu     $a0, $s3, 0x34 */
    .word 0x8E630040 /* 00143120: lw         $v1, 0x40($s3) */
    .word 0x24050002 /* 00143124: addiu      $a1, $zero, 0x2 */
    .word 0x72602628 /* 00143128: paddub     $a0, $s3, $zero */
    .word 0x00031080 /* 0014312C: sll        $v0, $v1, 2 */
    .word 0x00431021 /* 00143130: addu       $v0, $v0, $v1 */
    .word 0x00021080 /* 00143134: sll        $v0, $v0, 2 */
    .word 0x00531021 /* 00143138: addu       $v0, $v0, $s3 */
    .word 0xA445004C /* 0014313C: sh         $a1, 0x4C($v0) */
    .word 0x8E630040 /* 00143140: lw         $v1, 0x40($s3) */
    .word 0x86050002 /* 00143144: lh         $a1, 0x2($s0) */
    .word 0x00031080 /* 00143148: sll        $v0, $v1, 2 */
    .word 0x00431021 /* 0014314C: addu       $v0, $v0, $v1 */
    .word 0x00021080 /* 00143150: sll        $v0, $v0, 2 */
    .word 0x00531021 /* 00143154: addu       $v0, $v0, $s3 */
    jal        func_00142CC0 /* 00143158 */
    .word 0xA445004E /* 0014315C: sh        $a1, 0x4E($v0) */
    .word 0x14400004 /* 00143160: bnez       $v0, .L00143174 */
    .word 0x72602628 /* 00143164: paddub    $a0, $s3, $zero */
    .word 0x100000AB /* 00143168: b          .L00143418 */
    .word 0x70001628 /* 0014316C: paddub    $v0, $zero, $zero */
    .word 0x72602628 /* 00143170: paddub     $a0, $s3, $zero */
    jal        func_00143020 /* 00143174 */
    .word 0x70002E28 /* 00143178: paddub    $a1, $zero, $zero */
    .word 0x14400003 /* 0014317C: bnez       $v0, .L0014318C */
    .word 0x00000000 /* 00143180: nop */
    .word 0x100000A4 /* 00143184: b          .L00143418 */
    .word 0x70001628 /* 00143188: paddub    $v0, $zero, $zero */
    .word 0x86020002 /* 0014318C: lh         $v0, 0x2($s0) */
    .word 0x1040000F /* 00143190: beqz       $v0, .L001431D0 */
    .word 0x72602628 /* 00143194: paddub    $a0, $s3, $zero */
    jal        func_00142CC0 /* 00143198 */
    .word 0x72602628 /* 0014319C: paddub    $a0, $s3, $zero */
    .word 0x14400004 /* 001431A0: bnez       $v0, .L001431B4 */
    .word 0x72602628 /* 001431A4: paddub    $a0, $s3, $zero */
    .word 0x1000009B /* 001431A8: b          .L00143418 */
    .word 0x70001628 /* 001431AC: paddub    $v0, $zero, $zero */
    .word 0x72602628 /* 001431B0: paddub     $a0, $s3, $zero */
    jal        func_00143020 /* 001431B4 */
    .word 0x70002E28 /* 001431B8: paddub    $a1, $zero, $zero */
    .word 0x14400003 /* 001431BC: bnez       $v0, .L001431CC */
    .word 0x00000000 /* 001431C0: nop */
    .word 0x10000094 /* 001431C4: b          .L00143418 */
    .word 0x70001628 /* 001431C8: paddub    $v0, $zero, $zero */
    .word 0x72602628 /* 001431CC: paddub     $a0, $s3, $zero */
    jal        func_001427A0 /* 001431D0 */
    .word 0x00000000 /* 001431D4: nop */
    .word 0x1000008F /* 001431D8: b          .L00143418 */
    .word 0x00000000 /* 001431DC: nop */
    .word 0x26640034 /* 001431E0: addiu      $a0, $s3, 0x34 */
    .word 0x266501A0 /* 001431E4: addiu      $a1, $s3, 0x1A0 */
    jal        func_26B0A0 /* 001431E8 */
    .word 0x24060003 /* 001431EC: addiu     $a2, $zero, 0x3 */
    .word 0x70409628 /* 001431F0: paddub     $s2, $v0, $zero */
    .word 0x16400007 /* 001431F4: bnez       $s2, .L00143214 */
    .word 0x00000000 /* 001431F8: nop */
    .word 0x266601A0 /* 001431FC: addiu      $a2, $s3, 0x1A0 */
    .word 0x24050003 /* 00143200: addiu      $a1, $zero, 0x3 */
    jal        func_144340 /* 00143204 */
    .word 0x72602628 /* 00143208: paddub    $a0, $s3, $zero */
    .word 0x10000082 /* 0014320C: b          .L00143418 */
    .word 0x70001628 /* 00143210: paddub    $v0, $zero, $zero */
    .word 0x86440002 /* 00143214: lh         $a0, 0x2($s2) */
    .word 0x8E620010 /* 00143218: lw         $v0, 0x10($s3) */
    .word 0x00041840 /* 0014321C: sll        $v1, $a0, 1 */
    .word 0x00641821 /* 00143220: addu       $v1, $v1, $a0 */
    .word 0x000318C0 /* 00143224: sll        $v1, $v1, 3 */
    jal        func_1446A0 /* 00143228 */
    .word 0x00432021 /* 0014322C: addu      $a0, $v0, $v1 */
    .word 0x8E630040 /* 00143230: lw         $v1, 0x40($s3) */
    .word 0x70408628 /* 00143234: paddub     $s0, $v0, $zero */
    .word 0x24040003 /* 00143238: addiu      $a0, $zero, 0x3 */
    .word 0x70008E28 /* 0014323C: paddub     $s1, $zero, $zero */
    .word 0x00031080 /* 00143240: sll        $v0, $v1, 2 */
    .word 0x00431021 /* 00143244: addu       $v0, $v0, $v1 */
    .word 0x00021080 /* 00143248: sll        $v0, $v0, 2 */
    .word 0x00531021 /* 0014324C: addu       $v0, $v0, $s3 */
    .word 0xA444004C /* 00143250: sh         $a0, 0x4C($v0) */
    .word 0x8E630040 /* 00143254: lw         $v1, 0x40($s3) */
    .word 0x86440002 /* 00143258: lh         $a0, 0x2($s2) */
    .word 0x00031080 /* 0014325C: sll        $v0, $v1, 2 */
    .word 0x00431021 /* 00143260: addu       $v0, $v0, $v1 */
    .word 0x00021080 /* 00143264: sll        $v0, $v0, 2 */
    .word 0x00531021 /* 00143268: addu       $v0, $v0, $s3 */
    .word 0x10000065 /* 0014326C: b          .L00143404 */
    .word 0xA444004E /* 00143270: sh        $a0, 0x4E($v0) */
    jal        func_142980 /* 00143274 */
    .word 0x72602628 /* 00143278: paddub    $a0, $s3, $zero */
    .word 0x24060002 /* 0014327C: addiu      $a2, $zero, 0x2 */
    .word 0x1046000B /* 00143280: beq        $v0, $a2, .L001432B0 */
    .word 0x00000000 /* 00143284: nop */
    .word 0x24030001 /* 00143288: addiu      $v1, $zero, 0x1 */
    .word 0x14430006 /* 0014328C: bne        $v0, $v1, .L001432A8 */
    .word 0x70001628 /* 00143290: paddub    $v0, $zero, $zero */
    .word 0x2405001A /* 00143294: addiu      $a1, $zero, 0x1A */
    .word 0x72602628 /* 00143298: paddub     $a0, $s3, $zero */
    jal        func_144340 /* 0014329C */
    .word 0x70003628 /* 001432A0: paddub    $a2, $zero, $zero */
    .word 0x70001628 /* 001432A4: paddub     $v0, $zero, $zero */
    .word 0x1000005B /* 001432A8: b          .L00143418 */
    .word 0x00000000 /* 001432AC: nop */
    .word 0x8E63019C /* 001432B0: lw         $v1, 0x19C($s3) */
    .word 0x24020001 /* 001432B4: addiu      $v0, $zero, 0x1 */
    .word 0x10620007 /* 001432B8: beq        $v1, $v0, .L001432D8 */
    .word 0x00000000 /* 001432BC: nop */
    .word 0x2405000C /* 001432C0: addiu      $a1, $zero, 0xC */
    .word 0x72602628 /* 001432C4: paddub     $a0, $s3, $zero */
    jal        func_144340 /* 001432C8 */
    .word 0x70003628 /* 001432CC: paddub    $a2, $zero, $zero */
    .word 0x10000051 /* 001432D0: b          .L00143418 */
    .word 0x70001628 /* 001432D4: paddub    $v0, $zero, $zero */
    .word 0x826301A0 /* 001432D8: lb         $v1, 0x1A0($s3) */
    la         v0, D_48E100
    .word 0x00431021 /* 001432E4: addu       $v0, $v0, $v1 */
    .word 0x80420001 /* 001432E8: lb         $v0, 0x1($v0) */
    .word 0x30420004 /* 001432EC: andi       $v0, $v0, 0x4 */
    .word 0x1440000A /* 001432F0: bnez       $v0, .L0014331C */
    .word 0x266401A0 /* 001432F4: addiu     $a0, $s3, 0x1A0 */
    .word 0x00031E3C /* 001432F8: dsll32     $v1, $v1, 24 */
    .word 0x2402002B /* 001432FC: addiu      $v0, $zero, 0x2B */
    .word 0x00031E3F /* 00143300: dsra32     $v1, $v1, 24 */
    .word 0x10620004 /* 00143304: beq        $v1, $v0, .L00143318 */
    .word 0x00000000 /* 00143308: nop */
    .word 0x2402002D /* 0014330C: addiu      $v0, $zero, 0x2D */
    .word 0x14620007 /* 00143310: bne        $v1, $v0, .L00143330 */
    .word 0x266501A0 /* 00143314: addiu     $a1, $s3, 0x1A0 */
    .word 0x266401A0 /* 00143318: addiu      $a0, $s3, 0x1A0 */
    jal        atoi /* 0014331C */
    .word 0x00000000 /* 00143320: nop */
    .word 0x1000000F /* 00143324: b          .L00143364 */
    .word 0x24030003 /* 00143328: addiu     $v1, $zero, 0x3 */
    .word 0x266501A0 /* 0014332C: addiu      $a1, $s3, 0x1A0 */
    jal        func_00142730 /* 00143330 */
    .word 0x72602628 /* 00143334: paddub    $a0, $s3, $zero */
    .word 0x14400007 /* 00143338: bnez       $v0, .L00143358 */
    .word 0x00000000 /* 0014333C: nop */
    .word 0x266601A0 /* 00143340: addiu      $a2, $s3, 0x1A0 */
    .word 0x24050003 /* 00143344: addiu      $a1, $zero, 0x3 */
    jal        func_144340 /* 00143348 */
    .word 0x72602628 /* 0014334C: paddub    $a0, $s3, $zero */
    .word 0x10000031 /* 00143350: b          .L00143418 */
    .word 0x70001628 /* 00143354: paddub    $v0, $zero, $zero */
    .word 0x84420002 /* 00143358: lh         $v0, 0x2($v0) */
    .word 0x00000000 /* 0014335C: nop */
    .word 0x24030003 /* 00143360: addiu      $v1, $zero, 0x3 */
    .word 0x12230020 /* 00143364: beq        $s1, $v1, .L001433E8 */
    .word 0x00000000 /* 00143368: nop */
    .word 0x24030002 /* 0014336C: addiu      $v1, $zero, 0x2 */
    .word 0x12230016 /* 00143370: beq        $s1, $v1, .L001433CC */
    .word 0x00000000 /* 00143374: nop */
    .word 0x24030001 /* 00143378: addiu      $v1, $zero, 0x1 */
    .word 0x1223000C /* 0014337C: beq        $s1, $v1, .L001433B0 */
    .word 0x00000000 /* 00143380: nop */
    .word 0x12200003 /* 00143384: beqz       $s1, .L00143394 */
    .word 0x00000000 /* 00143388: nop */
    .word 0x1000001D /* 0014338C: b          .L00143404 */
    .word 0x26310001 /* 00143390: addiu     $s1, $s1, 0x1 */
    .word 0x8E640040 /* 00143394: lw         $a0, 0x40($s3) */
    .word 0x00041880 /* 00143398: sll        $v1, $a0, 2 */
    .word 0x00641821 /* 0014339C: addu       $v1, $v1, $a0 */
    .word 0x00031880 /* 001433A0: sll        $v1, $v1, 2 */
    .word 0x02631821 /* 001433A4: addu       $v1, $s3, $v1 */
    .word 0x10000015 /* 001433A8: b          .L00143400 */
    .word 0xAC620050 /* 001433AC: sw        $v0, 0x50($v1) */
    .word 0x8E640040 /* 001433B0: lw         $a0, 0x40($s3) */
    .word 0x00041880 /* 001433B4: sll        $v1, $a0, 2 */
    .word 0x00641821 /* 001433B8: addu       $v1, $v1, $a0 */
    .word 0x00031880 /* 001433BC: sll        $v1, $v1, 2 */
    .word 0x02631821 /* 001433C0: addu       $v1, $s3, $v1 */
    .word 0x1000000E /* 001433C4: b          .L00143400 */
    .word 0xAC620054 /* 001433C8: sw        $v0, 0x54($v1) */
    .word 0x8E640040 /* 001433CC: lw         $a0, 0x40($s3) */
    .word 0x00041880 /* 001433D0: sll        $v1, $a0, 2 */
    .word 0x00641821 /* 001433D4: addu       $v1, $v1, $a0 */
    .word 0x00031880 /* 001433D8: sll        $v1, $v1, 2 */
    .word 0x02631821 /* 001433DC: addu       $v1, $s3, $v1 */
    .word 0x10000007 /* 001433E0: b          .L00143400 */
    .word 0xAC620058 /* 001433E4: sw        $v0, 0x58($v1) */
    .word 0x8E640040 /* 001433E8: lw         $a0, 0x40($s3) */
    .word 0x00041880 /* 001433EC: sll        $v1, $a0, 2 */
    .word 0x00641821 /* 001433F0: addu       $v1, $v1, $a0 */
    .word 0x00031880 /* 001433F4: sll        $v1, $v1, 2 */
    .word 0x02631821 /* 001433F8: addu       $v1, $s3, $v1 */
    .word 0xAC62005C /* 001433FC: sw         $v0, 0x5C($v1) */
    .word 0x26310001 /* 00143400: addiu      $s1, $s1, 0x1 */
    .word 0x0230102A /* 00143404: slt        $v0, $s1, $s0 */
    .word 0x1440FF9A /* 00143408: bnez       $v0, .L00143274 */
    .word 0x00000000 /* 0014340C: nop */
    jal        func_001427A0 /* 00143410 */
    .word 0x72602628 /* 00143414: paddub    $a0, $s3, $zero */
    .word 0x7BBF0040 /* 00143418: lq         $ra, 0x40($sp) */
    .word 0x7BB30030 /* 0014341C: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 00143420: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 00143424: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 00143428: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 0014342C: jr         $ra */
    .word 0x27BD0050 /* 00143430: addiu     $sp, $sp, 0x50 */
}
}

#else
extern "C" {

int func_00143020(TacticalAI2 *self, int a1) {
    if (!a1) {
        int token = func_142980(self);
        if (token != 2) {
            if (token == 1) {
                func_144340(self, 0x1A, 0);
            }
            return 0;
        }
        if (self->field_19C != 2) {
            func_144340(self, 0xF, 0);
            return 0;
        }
    }

    int token = func_142980(self);
    if (token != 2) {
        if (token == 1) {
            func_144340(self, 0x1A, 0);
        }
        return 0;
    }

    if (self->field_19C != 1) {
        func_144340(self, 0xC, 0);
        return 0;
    }

    short *s0 = (short *)func_26B0A0(&self->field_34, self->field_1A0, 1);
    if (s0) {
        *(short *)(self->field_40 * 20 + (char *)self + 0x4C) = 2;
        *(short *)(self->field_40 * 20 + (char *)self + 0x4E) = s0[1];

        if (!func_00142CC0(self)) {
            return 0;
        }

        if (!func_00143020(self, 0)) {
            return 0;
        }

        if (s0[1] != 0) {
            if (!func_00142CC0(self)) {
                return 0;
            }
            if (!func_00143020(self, 0)) {
                return 0;
            }
        }

        return func_001427A0(self);
    }

    short *s2 = (short *)func_26B0A0(&self->field_34, self->field_1A0, 3);
    if (!s2) {
        func_144340(self, 3, self->field_1A0);
        return 0;
    }

    short cond_id = s2[1];
    void *s0_obj = (void *)func_1446A0((char *)self->field_10 + cond_id * 24);

    *(short *)(self->field_40 * 20 + (char *)self + 0x4C) = 3;
    *(short *)(self->field_40 * 20 + (char *)self + 0x4E) = cond_id;

    int s1 = 0;
    while (s1 < (int)s0_obj) {
        int t = func_142980(self);
        if (t != 2) {
            if (t == 1) {
                func_144340(self, 0x1A, 0);
            }
            return 0;
        }

        if (self->field_19C != 1) {
            func_144340(self, 0xC, 0);
            return 0;
        }

        char first = self->field_1A0[0];
        int val;
        if ((D_48E100[first + 1] & 4) || (char)first == '+' || (char)first == '-') {
            val = atoi(self->field_1A0);
        } else {
            void *sym = func_00142730(self, self->field_1A0);
            if (!sym) {
                func_144340(self, 3, self->field_1A0);
                return 0;
            }
            val = *(short *)((char *)sym + 2);
        }

        switch (s1) {
        case 0:
            *(int *)(self->field_40 * 20 + (char *)self + 0x50) = val;
            break;
        case 1:
            *(int *)(self->field_40 * 20 + (char *)self + 0x54) = val;
            break;
        case 2:
            *(int *)(self->field_40 * 20 + (char *)self + 0x58) = val;
            break;
        case 3:
            *(int *)(self->field_40 * 20 + (char *)self + 0x5C) = val;
            break;
        }

        s1++;
    }

    return func_001427A0(self);
}

}

#endif
