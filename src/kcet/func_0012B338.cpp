/* Function: func_0012B338 (0x0012B338 - 0x0012B46C)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012B338(void *a0, void *a1, s32 a2) {
    .word 0x27bdffb0 // 0012B338: addiu $sp, $sp, -0x50
    .word 0xffb10020 // 0012B33C: sd $s1, 0x20($sp)
    .word 0x0080882d // 0012B340: move $s1, $a0
    .word 0xffb20030 // 0012B344: sd $s2, 0x30($sp)
    .word 0xffb00010 // 0012B348: sd $s0, 0x10($sp)
    .word 0x00a0902d // 0012B34C: move $s2, $a1
    .word 0xffbf0040 // 0012B350: sd $ra, 0x40($sp)
    .word 0x00c0802d // 0012B354: move $s0, $a2
    .word 0xae200030 // 0012B358: sw $zero, 0x30($s1)
    .word 0x0240202d // 0012B35C: move $a0, $s2
    .word 0xafa80000 // 0012B360: sw $t0, ($sp)
    .word 0x0c04ac88 // 0012B364: jal 0x12b220
    .word 0xafa90004 // 0012B368: sw $t1, 4($sp)
    .word 0xae220028 // 0012B36C: sw $v0, 0x28($s1)
    .word 0x3c02004f // 0012B370: lui $v0, 0x4f
    .word 0x8c43d30c // 0012B374: lw $v1, -0x2cf4($v0)
    .word 0xae30003c // 0012B378: sw $s0, 0x3c($s1)
    .word 0xae23001c // 0012B37C: sw $v1, 0x1c($s1)
    .word 0x12400013 // 0012B380: beqz $s2, 0x12b3d0
    .word 0xae200038 // 0012B384: sw $zero, 0x38($s1)
    .word 0x0240202d // 0012B388: move $a0, $s2
    .word 0x03a0282d // 0012B38C: move $a1, $sp
    .word 0x0c04aba0 // 0012B390: jal 0x12ae80
    .word 0x37a60004 // 0012B394: ori $a2, $sp, 4
    .word 0x5440002d // 0012B398: bnel $v0, $zero, 0x12b450
    .word 0x24120008 // 0012B39C: addiu $s2, $zero, 8
    .word 0x0c04b40e // 0012B3A0: jal 0x12d038
    .word 0x0240202d // 0012B3A4: move $a0, $s2
    .word 0xae22002c // 0012B3A8: sw $v0, 0x2c($s1)
    .word 0x0c04b3d6 // 0012B3AC: jal 0x12cf58
    .word 0x0240202d // 0012B3B0: move $a0, $s2
    .word 0x0040202d // 0012B3B4: move $a0, $v0
    .word 0x26250020 // 0012B3B8: addiu $a1, $s1, 0x20
    .word 0x0c04b2ea // 0012B3BC: jal 0x12cba8
    .word 0x26260024 // 0012B3C0: addiu $a2, $s1, 0x24
    .word 0x10000008 // 0012B3C4: b 0x12b3e8
    .word 0x8fa20000 // 0012B3C8: lw $v0, ($sp)
    .word 0x00000000 // 0012B3CC: nop
    .word 0x24020001 // 0012B3D0: addiu $v0, $zero, 1
    .word 0xae200020 // 0012B3D4: sw $zero, 0x20($s1)
    .word 0xafa20000 // 0012B3D8: sw $v0, ($sp)
    .word 0xae20002c // 0012B3DC: sw $zero, 0x2c($s1)
    .word 0xae200028 // 0012B3E0: sw $zero, 0x28($s1)
    .word 0x8fa20000 // 0012B3E4: lw $v0, ($sp)
    .word 0x8fa30004 // 0012B3E8: lw $v1, 4($sp)
    .word 0xae220014 // 0012B3EC: sw $v0, 0x14($s1)
    .word 0x10600013 // 0012B3F0: beqz $v1, 0x12b440
    .word 0xae230018 // 0012B3F4: sw $v1, 0x18($s1)
    .word 0x24020001 // 0012B3F8: addiu $v0, $zero, 1
    .word 0x10620009 // 0012B3FC: beq $v1, $v0, 0x12b424
    .word 0x3c040049 // 0012B400: lui $a0, 0x49
    .word 0x0c046378 // 0012B404: jal 0x118de0
    .word 0x2484fd80 // 0012B408: addiu $a0, $a0, -0x280
    .word 0x3c040049 // 0012B40C: lui $a0, 0x49
    .word 0x3c06004e // 0012B410: lui $a2, 0x4e
    .word 0x2484f500 // 0012B414: addiu $a0, $a0, -0xb00
    .word 0x24c62c58 // 0012B418: addiu $a2, $a2, 0x2c58
    .word 0x0c0450c8 // 0012B41C: jal 0x114320
    .word 0x2405095b // 0012B420: addiu $a1, $zero, 0x95b
    .word 0x8e30006c // 0012B424: lw $s0, 0x6c($s1)
    .word 0x24120001 // 0012B428: addiu $s2, $zero, 1
    .word 0x0220202d // 0012B42C: move $a0, $s1
    .word 0x0c04a8a2 // 0012B430: jal 0x12a288
    .word 0xae120008 // 0012B434: sw $s2, 8($s0)
    .word 0x10000005 // 0012B438: b 0x12b450
    .word 0xae02000c // 0012B43C: sw $v0, 0xc($s0)
    .word 0x0220202d // 0012B440: move $a0, $s1
    .word 0x0c04aa02 // 0012B444: jal 0x12a808
    .word 0x24050004 // 0012B448: addiu $a1, $zero, 4
    .word 0x0040902d // 0012B44C: move $s2, $v0
    .word 0x0240102d // 0012B450: move $v0, $s2
    .word 0xdfbf0040 // 0012B454: ld $ra, 0x40($sp)
    .word 0xdfb20030 // 0012B458: ld $s2, 0x30($sp)
    .word 0xdfb10020 // 0012B45C: ld $s1, 0x20($sp)
    .word 0xdfb00010 // 0012B460: ld $s0, 0x10($sp)
    .word 0x03e00008 // 0012B464: jr $ra
    .word 0x27bd0050 // 0012B468: addiu $sp, $sp, 0x50
}
#else

struct CdvdSubStruct {
    u8 pad0[8];
    s32 f_8;
    s32 f_c;
};

struct CdvdRequest {
    u8 pad0[0x14];
    s32 f_14;
    s32 f_18;
    s32 f_1c;
    s32 f_20;
    s32 f_24;
    s32 f_28;
    s32 f_2c;
    s32 f_30;
    u8 pad34[0x4];
    s32 f_38;
    s32 f_3c;
    u8 pad40[0x2c];
    CdvdSubStruct *sub;
};

struct CdvdGlobalState {
    u8 pad0[0xc];
    s32 f_c;
};

extern CdvdGlobalState D_004ED300;
extern const char D_48FD80[];
extern const char D_48F500[];
extern const char D_4E2C58[];

s32 func_0012B220(void *param1);
s32 func_0012AE80(void *param1, s32 *sp_val, s32 *s3);
s32 func_0012D038(void *param1);
s32 func_0012CF58(void *param1);
void func_0012CBA8(s32 v0, s32 *p20, s32 *p24);
void func_118de0(const char *, ...);
void func_114320(const char *, int, const char *);
s32 func_0012A288(CdvdRequest *req);
s32 func_0012A808(CdvdRequest *req, s32 code);

s32 func_0012B338(CdvdRequest *req, void *param1, s32 param2) {
    req->f_30 = 0;
    s32 v0_b220 = func_0012B220(param1);
    req->f_28 = v0_b220;
    req->f_3c = param2;
    req->f_1c = D_004ED300.f_c;
    req->f_38 = 0;

    s32 sp[2];
    if (param1 != 0) {
        if (func_0012AE80(param1, sp, &sp[1]) != 0) {
            return 8;
        }
        req->f_2c = func_0012D038(param1);
        s32 v0_cf58 = func_0012CF58(param1);
        func_0012CBA8(v0_cf58, &req->f_20, &req->f_24);
    } else {
        req->f_20 = 0;
        sp[0] = 1;
        req->f_2c = 0;
        req->f_28 = 0;
    }

    req->f_14 = sp[0];
    req->f_18 = sp[1];

    if (sp[1] == 0) {
        return func_0012A808(req, 4);
    }

    if (sp[1] != 1) {
        func_118de0(D_48FD80);
        func_114320(D_48F500, 0x95b, D_4E2C58);
    }

    CdvdSubStruct *sub = req->sub;
    sub->f_8 = 1;
    sub->f_c = func_0012A288(req);
    return 1;
}

#endif

}
