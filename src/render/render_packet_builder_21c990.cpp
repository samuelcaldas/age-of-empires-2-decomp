#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

void *func_0021C990(void *obj, int a1, int a2, int a3, const short *uv_rect, const short *xy_pts, int t2, int t3, int z);

asm void *func_0021C990(void *obj, int a1, int a2, int a3, const short *uv_rect, const short *xy_pts, int t2, int t3, int z) {
    .word 0x27BDFF20 /* addiu      $sp, $sp, -0xE0 */
    .word 0x0006103C /* dsll32     $v0, $a2, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x7FBF0090 /* sq         $ra, 0x90($sp) */
    .word 0x000211B8 /* dsll       $v0, $v0, 6 */
    .word 0x7FBE0080 /* sq         $fp, 0x80($sp) */
    .word 0x7FB70070 /* sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x34430114 /* ori        $v1, $v0, 0x114 */
    .word 0x000B103C /* dsll32     $v0, $t3, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x00021278 /* dsll       $v0, $v0, 9 */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x7080B628 /* paddub     $s6, $a0, $zero */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x000223FC /* dsll32     $a0, $v0, 15 */
    .word 0x3C020039 /* lui        $v0, (0x392B40 >> 16) */
    .word 0x24422B40 /* addiu      $v0, $v0, (0x392B40 & 0xFFFF) */
    .word 0x70A0AE28 /* paddub     $s5, $a1, $zero */
    .word 0x78450000 /* lq         $a1, 0x0($v0) */
    .word 0x27A600B0 /* addiu      $a2, $sp, 0xB0 */
    .word 0x70E0A628 /* paddub     $s4, $a3, $zero */
    .word 0x71008628 /* paddub     $s0, $t0, $zero */
    .word 0x71209E28 /* paddub     $s3, $t1, $zero */
    .word 0x3C021000 /* lui        $v0, (0x10004000 >> 16) */
    .word 0x34424000 /* ori        $v0, $v0, (0x10004000 & 0xFFFF) */
    .word 0x0002183C /* dsll32     $v1, $v0, 0 */
    .word 0x34028000 /* ori        $v0, $zero, 0x8000 */
    .word 0x00431025 /* or         $v0, $v0, $v1 */
    .word 0x7CC50000 /* sq         $a1, 0x0($a2) */
    .word 0x00821025 /* or         $v0, $a0, $v0 */
    .word 0x71409628 /* paddub     $s2, $t2, $zero */
    .word 0x7160BE28 /* paddub     $s7, $t3, $zero */
    .word 0x16C00004 /* bnez       $s6, .L0021CA3C */
    .word 0xFFA200B0 /* sd         $v0, 0xB0($sp) */
    jal func_123908
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    .word 0x7040B628 /* paddub     $s6, $v0, $zero */
    .word 0x86020004 /* lh         $v0, 0x4($s0) */
    .word 0x3C0100CA /* lui        $at, (0xCA158C >> 16) */
    .word 0x9425158C /* lhu        $a1, (0xCA158C & 0xFFFF)($at) */
    .word 0x86070002 /* lh         $a3, 0x2($s0) */
    .word 0x86060006 /* lh         $a2, 0x6($s0) */
    .word 0x86080000 /* lh         $t0, 0x0($s0) */
    .word 0x00021100 /* sll        $v0, $v0, 4 */
    .word 0xAFA200A0 /* sw         $v0, 0xA0($sp) */
    .word 0x3C0100CA /* lui        $at, (0xCA158E >> 16) */
    .word 0x9423158E /* lhu        $v1, (0xCA158E & 0xFFFF)($at) */
    .word 0x00051043 /* sra        $v0, $a1, 1 */
    .word 0x8FA500E0 /* lw         $a1, 0xE0($sp) */
    .word 0x24040800 /* addiu      $a0, $zero, 0x800 */
    .word 0x00821023 /* subu       $v0, $a0, $v0 */
    .word 0x00031843 /* sra        $v1, $v1, 1 */
    .word 0x00831823 /* subu       $v1, $a0, $v1 */
    .word 0x00078900 /* sll        $s1, $a3, 4 */
    .word 0x00052823 /* subu       $a1, $zero, $a1 */
    .word 0x00088100 /* sll        $s0, $t0, 4 */
    .word 0x0006F100 /* sll        $fp, $a2, 4 */
    .word 0x00021100 /* sll        $v0, $v0, 4 */
    .word 0x00031900 /* sll        $v1, $v1, 4 */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    .word 0x10000010 /* b          .L0021CADC */
    .word 0x000538C0 /* sll        $a3, $a1, 3 */
    .word 0x000428C0 /* sll        $a1, $a0, 3 */
    .word 0x02654021 /* addu       $t0, $s3, $a1 */
    .word 0x85050000 /* lh         $a1, 0x0($t0) */
    .word 0x00043080 /* sll        $a2, $a0, 2 */
    .word 0x00DD3021 /* addu       $a2, $a2, $sp */
    .word 0x24840001 /* addiu      $a0, $a0, 0x1 */
    .word 0x00052900 /* sll        $a1, $a1, 4 */
    .word 0x00452821 /* addu       $a1, $v0, $a1 */
    .word 0x00E52821 /* addu       $a1, $a3, $a1 */
    .word 0xACC500C0 /* sw         $a1, 0xC0($a2) */
    .word 0x85050002 /* lh         $a1, 0x2($t0) */
    .word 0x00052900 /* sll        $a1, $a1, 4 */
    .word 0x00652821 /* addu       $a1, $v1, $a1 */
    .word 0x00E52821 /* addu       $a1, $a3, $a1 */
    .word 0xACC500D0 /* sw         $a1, 0xD0($a2) */
    .word 0x28850004 /* slti       $a1, $a0, 0x4 */
    .word 0x14A0FFF0 /* bnez       $a1, .L0021CAA4 */
    .word 0x000428C0 /* sll        $a1, $a0, 3 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    .word 0x70003628 /* paddub     $a2, $zero, $zero */
    jal func_104448
    .word 0x70003E28 /* paddub     $a3, $zero, $zero */
    .word 0x27A200B0 /* addiu      $v0, $sp, 0xB0 */
    .word 0x78450000 /* lq         $a1, 0x0($v0) */
    jal func_1045E8
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x12E00008 /* beqz       $s7, .L0021CB30 */
    .word 0x24050006 /* addiu      $a1, $zero, 0x6 */
    .word 0x24050007 /* addiu      $a1, $zero, 0x7 */
    .word 0x72A03628 /* paddub     $a2, $s5, $zero */
    jal func_1046A8
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x10000006 /* b          .L0021CB40 */
    .word 0x0014303C /* dsll32     $a2, $s4, 0 */
    .word 0x24050006 /* addiu      $a1, $zero, 0x6 */
    .word 0x72A03628 /* paddub     $a2, $s5, $zero */
    jal func_1046A8
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x0014303C /* dsll32     $a2, $s4, 0 */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    .word 0x0006303F /* dsra32     $a2, $a2, 0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x0011103C /* dsll32     $v0, $s1, 0 */
    .word 0x0010983C /* dsll32     $s3, $s0, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x0013983F /* dsra32     $s3, $s3, 0 */
    .word 0x0002A438 /* dsll       $s4, $v0, 16 */
    .word 0x24050003 /* addiu      $a1, $zero, 0x3 */
    .word 0x02743025 /* or         $a2, $s3, $s4 */
    jal func_1046A8
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x3242FFFF /* andi       $v0, $s2, 0xFFFF */
    .word 0x0002903C /* dsll32     $s2, $v0, 0 */
    .word 0x8FA200D0 /* lw         $v0, 0xD0($sp) */
    .word 0x8FA300C0 /* lw         $v1, 0xC0($sp) */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    jal func_1046A8
    .word 0x02423025 /* or         $a2, $s2, $v0 */
    .word 0x8FA200A0 /* lw         $v0, 0xA0($sp) */
    .word 0x24050003 /* addiu      $a1, $zero, 0x3 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x02021021 /* addu       $v0, $s0, $v0 */
    .word 0x0002803C /* dsll32     $s0, $v0, 0 */
    .word 0x0010803F /* dsra32     $s0, $s0, 0 */
    jal func_1046A8
    .word 0x02903025 /* or         $a2, $s4, $s0 */
    .word 0x8FA200D4 /* lw         $v0, 0xD4($sp) */
    .word 0x8FA300C4 /* lw         $v1, 0xC4($sp) */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    jal func_1046A8
    .word 0x02423025 /* or         $a2, $s2, $v0 */
    .word 0x023E1021 /* addu       $v0, $s1, $fp */
    .word 0x0002103C /* dsll32     $v0, $v0, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x00028C38 /* dsll       $s1, $v0, 16 */
    .word 0x24050003 /* addiu      $a1, $zero, 0x3 */
    .word 0x02713025 /* or         $a2, $s3, $s1 */
    jal func_1046A8
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x8FA200D8 /* lw         $v0, 0xD8($sp) */
    .word 0x8FA300C8 /* lw         $v1, 0xC8($sp) */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    jal func_1046A8
    .word 0x02423025 /* or         $a2, $s2, $v0 */
    .word 0x24050003 /* addiu      $a1, $zero, 0x3 */
    .word 0x02113025 /* or         $a2, $s0, $s1 */
    jal func_1046A8
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x8FA200DC /* lw         $v0, 0xDC($sp) */
    .word 0x8FA300CC /* lw         $v1, 0xCC($sp) */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    jal func_1046A8
    .word 0x02423025 /* or         $a2, $s2, $v0 */
    jal func_104600
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x72C01628 /* paddub     $v0, $s6, $zero */
    .word 0x7BBF0090 /* lq         $ra, 0x90($sp) */
    .word 0x7BBE0080 /* lq         $fp, 0x80($sp) */
    .word 0x7BB70070 /* lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD00E0 /* addiu      $sp, $sp, 0xE0 */
}

asm void *func_0021CC90(void *obj, int a1, int a2, int a3, const short *uv_rect, const short *rect, int t2, int t3, int z) {
    .word 0x27BDFFC0 /* addiu      $sp, $sp, -0x40 */
    .word 0x7FBF0010 /* sq         $ra, 0x10($sp) */
    .word 0x85230000 /* lh         $v1, 0x0($t1) */
    .word 0x8FA20040 /* lw         $v0, 0x40($sp) */
    .word 0xA7A30020 /* sh         $v1, 0x20($sp) */
    .word 0x85230002 /* lh         $v1, 0x2($t1) */
    .word 0xA7A30022 /* sh         $v1, 0x22($sp) */
    .word 0x852C0000 /* lh         $t4, 0x0($t1) */
    .word 0x85230004 /* lh         $v1, 0x4($t1) */
    .word 0x01831821 /* addu       $v1, $t4, $v1 */
    .word 0xA7A30028 /* sh         $v1, 0x28($sp) */
    .word 0x85230002 /* lh         $v1, 0x2($t1) */
    .word 0xA7A3002A /* sh         $v1, 0x2A($sp) */
    .word 0x85230000 /* lh         $v1, 0x0($t1) */
    .word 0xA7A30030 /* sh         $v1, 0x30($sp) */
    .word 0x852C0002 /* lh         $t4, 0x2($t1) */
    .word 0x85230006 /* lh         $v1, 0x6($t1) */
    .word 0x01831821 /* addu       $v1, $t4, $v1 */
    .word 0xA7A30032 /* sh         $v1, 0x32($sp) */
    .word 0x852C0000 /* lh         $t4, 0x0($t1) */
    .word 0x85230004 /* lh         $v1, 0x4($t1) */
    .word 0x01831821 /* addu       $v1, $t4, $v1 */
    .word 0xA7A30038 /* sh         $v1, 0x38($sp) */
    .word 0x852C0002 /* lh         $t4, 0x2($t1) */
    .word 0x85230006 /* lh         $v1, 0x6($t1) */
    .word 0x01831821 /* addu       $v1, $t4, $v1 */
    .word 0xA7A3003A /* sh         $v1, 0x3A($sp) */
    .word 0x27A90020 /* addiu      $t1, $sp, 0x20 */
    jal func_0021C990
    .word 0xFFA20000 /* sd         $v0, 0x0($sp) */
    .word 0x7BBF0010 /* lq         $ra, 0x10($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0040 /* addiu      $sp, $sp, 0x40 */
}

}

#else

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

extern unsigned int D_00392B40[4];
extern unsigned short D_00CA158C;
extern unsigned short D_00CA158E;

static void *EnsurePacketObject(void *obj) {
    if (obj != 0) {
        return obj;
    }
    return func_123908(0);
}

static void BuildSpriteTag(unsigned long long *tag, int a2, int t3) {
    unsigned long long part1 = 0x8000ULL | (0x10004000ULL << 32);
    unsigned long long v0 = 0x114 | (((unsigned long long)(unsigned int)a2) << 6) | (((unsigned long long)(unsigned int)t3) << 9);
    unsigned long long part2 = v0 << 47;
    tag[0] = part1 | part2;
    tag[1] = ((unsigned long long)D_00392B40[2]) | (((unsigned long long)D_00392B40[3]) << 32);
}

static void TransformQuadCoords(int *out_x, int *out_y, const short *xy_pts, int z) {
    int center_x = (int)D_00CA158C;
    int center_y = (int)D_00CA158E;
    int base_x = (0x800 - (center_x >> 1)) << 4;
    int base_y = (0x800 - (center_y >> 1)) << 4;
    int depth_offset = (-z) << 3;

    for (int i = 0; i < 4; ++i) {
        const short *pt = xy_pts + (i * 4);
        out_x[i] = (pt[0] << 4) + base_x + depth_offset;
        out_y[i] = (pt[1] << 4) + base_y + depth_offset;
    }
}

static void EmitSpriteRegisters(void *obj, int a1, int a3, int t3) {
    int reg = 0x06;
    if (t3 != 0) {
        reg = 0x07;
    }
    func_1046A8(obj, reg, (unsigned long long)(unsigned int)a1);
    func_1046A8(obj, 0x01, (unsigned long long)(unsigned int)a3);
}

static void EmitQuadVertices(void *obj, const short *uv_rect, const int *xs, const int *ys, int t2) {
    int u = (int)uv_rect[0] << 4;
    int v = (int)uv_rect[1] << 4;
    int w = (int)uv_rect[3] << 4;
    int h = (int)uv_rect[2] << 4;

    unsigned long long z_upper = ((unsigned long long)(unsigned int)(t2 & 0xFFFF)) << 32;

    unsigned long long uv0 = ((unsigned long long)(unsigned int)u) | (((unsigned long long)(unsigned int)v) << 16);
    unsigned long long xyz0 = z_upper | ((unsigned long long)(unsigned int)xs[0]) | (((unsigned long long)(unsigned int)ys[0]) << 16);
    func_1046A8(obj, 0x03, uv0);
    func_1046A8(obj, 0x04, xyz0);

    unsigned long long uv1 = ((unsigned long long)(unsigned int)(u + h)) | (((unsigned long long)(unsigned int)v) << 16);
    unsigned long long xyz1 = z_upper | ((unsigned long long)(unsigned int)xs[1]) | (((unsigned long long)(unsigned int)ys[1]) << 16);
    func_1046A8(obj, 0x03, uv1);
    func_1046A8(obj, 0x04, xyz1);

    unsigned long long uv2 = ((unsigned long long)(unsigned int)u) | (((unsigned long long)(unsigned int)(v + w)) << 16);
    unsigned long long xyz2 = z_upper | ((unsigned long long)(unsigned int)xs[2]) | (((unsigned long long)(unsigned int)ys[2]) << 16);
    func_1046A8(obj, 0x03, uv2);
    func_1046A8(obj, 0x04, xyz2);

    unsigned long long uv3 = ((unsigned long long)(unsigned int)(u + h)) | (((unsigned long long)(unsigned int)(v + w)) << 16);
    unsigned long long xyz3 = z_upper | ((unsigned long long)(unsigned int)xs[3]) | (((unsigned long long)(unsigned int)ys[3]) << 16);
    func_1046A8(obj, 0x03, uv3);
    func_1046A8(obj, 0x04, xyz3);
}

void *func_0021C990(void *obj, int a1, int a2, int a3, const short *uv_rect, const short *xy_pts, int t2, int t3, int z) {
    void *packet = EnsurePacketObject(obj);

    unsigned long long tag[2];
    BuildSpriteTag(tag, a2, t3);

    int xs[4];
    int ys[4];
    TransformQuadCoords(xs, ys, xy_pts, z);

    func_104448(packet, 0, 0, 0);
    func_1045E8(packet, tag);

    EmitSpriteRegisters(packet, a1, a3, t3);
    EmitQuadVertices(packet, uv_rect, xs, ys, t2);

    func_104600(packet);
    return packet;
}

void *func_0021CC90(void *obj, int a1, int a2, int a3, const short *uv_rect, const short *rect, int t2, int t3, int z) {
    short pts[16];
    short x = rect[0];
    short y = rect[1];
    short w = rect[2];
    short h = rect[3];

    pts[0] = x;
    pts[1] = y;

    pts[4] = x + w;
    pts[5] = y;

    pts[8] = x;
    pts[9] = y + h;

    pts[12] = x + w;
    pts[13] = y + h;

    return func_0021C990(obj, a1, a2, a3, uv_rect, pts, t2, t3, z);
}
}

#endif
