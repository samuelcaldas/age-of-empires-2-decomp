#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

void *func_0021CFB0(void *obj, unsigned long long tex0_val, int s0, int tex0_reg_flag, const int *src_rect, const int *dst_rect, int depth_z, int priority);

asm void *func_0021CFB0(void *obj, unsigned long long tex0_val, int s0, int tex0_reg_flag, const int *src_rect, const int *dst_rect, int depth_z, int priority) {
    .word 0x27BDFEF0 /* addiu      $sp, $sp, -0x110 */
    .word 0x0006103C /* dsll32     $v0, $a2, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x7FBF0090 /* sq         $ra, 0x90($sp) */
    .word 0x000211B8 /* dsll       $v0, $v0, 6 */
    .word 0x7FBE0080 /* sq         $fp, 0x80($sp) */
    .word 0x34430114 /* ori        $v1, $v0, 0x114 */
    .word 0x7FB70070 /* sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x000B103C /* dsll32     $v0, $t3, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x00021278 /* dsll       $v0, $v0, 9 */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7080B628 /* paddub     $s6, $a0, $zero */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x000223FC /* dsll32     $a0, $v0, 15 */
    .word 0x3C020039 /* lui        $v0, 0x39 */
    .word 0x24422B60 /* addiu      $v0, $v0, (0x392B60 & 0xFFFF) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x70A09628 /* paddub     $s2, $a1, $zero */
    .word 0x78450000 /* lq         $a1, 0x0($v0) */
    .word 0x27A60100 /* addiu      $a2, $sp, 0x100 */
    .word 0x3C0100CA /* lui        $at, (0xCA158C >> 16) */
    .word 0x70E0A628 /* paddub     $s4, $a3, $zero */
    .word 0x24070800 /* addiu      $a3, $zero, 0x800 */
    .word 0x3C021000 /* lui        $v0, (0x10004000 >> 16) */
    .word 0x34424000 /* ori        $v0, $v0, (0x10004000 & 0xFFFF) */
    .word 0x0002183C /* dsll32     $v1, $v0, 0 */
    .word 0x34028000 /* ori        $v0, $zero, 0x8000 */
    .word 0x00431025 /* or         $v0, $v0, $v1 */
    .word 0x7CC50000 /* sq         $a1, 0x0($a2) */
    .word 0x00821025 /* or         $v0, $a0, $v0 */
    .word 0xFFA20100 /* sd         $v0, 0x100($sp) */
    .word 0x9426158C /* lhu        $a2, (0xCA158C & 0xFFFF)($at) */
    .word 0x8D220000 /* lw         $v0, 0x0($t1) */
    .word 0x8FA40110 /* lw         $a0, 0x110($sp) */
    .word 0x8D230008 /* lw         $v1, 0x8($t1) */
    .word 0x7100AE28 /* paddub     $s5, $t0, $zero */
    .word 0xA7AA00FE /* sh         $t2, 0xFE($sp) */
    .word 0x3C0100CA /* lui        $at, (0xCA158E >> 16) */
    .word 0x00021100 /* sll        $v0, $v0, 4 */
    .word 0xAFA200B0 /* sw         $v0, 0xB0($sp) */
    .word 0x00031100 /* sll        $v0, $v1, 4 */
    .word 0xAFA200C0 /* sw         $v0, 0xC0($sp) */
    .word 0x8D220004 /* lw         $v0, 0x4($t1) */
    .word 0x9425158E /* lhu        $a1, (0xCA158E & 0xFFFF)($at) */
    .word 0x00063043 /* sra        $a2, $a2, 1 */
    .word 0x00E63023 /* subu       $a2, $a3, $a2 */
    .word 0x00042023 /* negu       $a0, $a0 */
    .word 0x8D23000C /* lw         $v1, 0xC($t1) */
    .word 0x00021100 /* sll        $v0, $v0, 4 */
    .word 0x00052843 /* sra        $a1, $a1, 1 */
    .word 0xAFA200D0 /* sw         $v0, 0xD0($sp) */
    .word 0x00E52823 /* subu       $a1, $a3, $a1 */
    .word 0xAFAB00AC /* sw         $t3, 0xAC($sp) */
    .word 0x00031100 /* sll        $v0, $v1, 4 */
    .word 0x00068100 /* sll        $s0, $a2, 4 */
    .word 0x00058900 /* sll        $s1, $a1, 4 */
    .word 0x000498C0 /* sll        $s3, $a0, 3 */
    .word 0x16C00004 /* bnez       $s6, .L0021D0C0 */
    .word 0xAFA200E0 /* sw        $v0, 0xE0($sp) */
    jal func_123908
    .word 0x70002628 /* paddub    $a0, $zero, $zero */
    .word 0x7040B628 /* paddub     $s6, $v0, $zero */
    .word 0x8EA70000 /* lw         $a3, 0x0($s5) */
    .word 0x8EA60008 /* lw         $a2, 0x8($s5) */
    .word 0x8EA30004 /* lw         $v1, 0x4($s5) */
    .word 0x8EA2000C /* lw         $v0, 0xC($s5) */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    .word 0x00073900 /* sll        $a3, $a3, 4 */
    .word 0x00063100 /* sll        $a2, $a2, 4 */
    .word 0x00F03821 /* addu       $a3, $a3, $s0 */
    .word 0x00D03021 /* addu       $a2, $a2, $s0 */
    .word 0x00031900 /* sll        $v1, $v1, 4 */
    .word 0x00021100 /* sll        $v0, $v0, 4 */
    .word 0x00711821 /* addu       $v1, $v1, $s1 */
    .word 0x00511021 /* addu       $v0, $v0, $s1 */
    .word 0x0267F021 /* addu       $fp, $s3, $a3 */
    .word 0x0266B821 /* addu       $s7, $s3, $a2 */
    .word 0x02638021 /* addu       $s0, $s3, $v1 */
    .word 0x02628821 /* addu       $s1, $s3, $v0 */
    .word 0x70003628 /* paddub     $a2, $zero, $zero */
    jal func_104448
    .word 0x70003E28 /* paddub    $a3, $zero, $zero */
    .word 0x27A20100 /* addiu      $v0, $sp, 0x100 */
    .word 0x78450000 /* lq         $a1, 0x0($v0) */
    jal func_1045E8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x8FA200AC /* lw         $v0, 0xAC($sp) */
    .word 0x10400008 /* beqz       $v0, .L0021D14C */
    .word 0x24050006 /* addiu     $a1, $zero, 0x6 */
    .word 0x24050007 /* addiu      $a1, $zero, 0x7 */
    .word 0x72403628 /* paddub     $a2, $s2, $zero */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x10000006 /* b          .L0021D15C */
    .word 0x0014303C /* dsll32    $a2, $s4, 0 */
    .word 0x24050006 /* addiu      $a1, $zero, 0x6 */
    .word 0x72403628 /* paddub     $a2, $s2, $zero */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x0014303C /* dsll32     $a2, $s4, 0 */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    .word 0x0006303F /* dsra32     $a2, $a2, 0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x8FA200B0 /* lw         $v0, 0xB0($sp) */
    .word 0x24050003 /* addiu      $a1, $zero, 0x3 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x7040A628 /* paddub     $s4, $v0, $zero */
    .word 0x8FA200D0 /* lw         $v0, 0xD0($sp) */
    .word 0x70401628 /* paddub     $v0, $v0, $zero */
    .word 0x00029438 /* dsll       $s2, $v0, 16 */
    jal func_1046A8
    .word 0x02923025 /* or        $a2, $s4, $s2 */
    .word 0x97A200FE /* lhu        $v0, 0xFE($sp) */
    .word 0x001E183C /* dsll32     $v1, $fp, 0 */
    .word 0x0003183F /* dsra32     $v1, $v1, 0 */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x70401628 /* paddub     $v0, $v0, $zero */
    .word 0x0002983C /* dsll32     $s3, $v0, 0 */
    .word 0x0010103C /* dsll32     $v0, $s0, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    jal func_1046A8
    .word 0x02623025 /* or        $a2, $s3, $v0 */
    .word 0x8FA200C0 /* lw         $v0, 0xC0($sp) */
    .word 0x24050003 /* addiu      $a1, $zero, 0x3 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x7040AE28 /* paddub     $s5, $v0, $zero */
    jal func_1046A8
    .word 0x02B23025 /* or        $a2, $s5, $s2 */
    .word 0x0010103C /* dsll32     $v0, $s0, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x0017183C /* dsll32     $v1, $s7, 0 */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x0003183F /* dsra32     $v1, $v1, 0 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x02623025 /* or         $a2, $s3, $v0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x8FA200E0 /* lw         $v0, 0xE0($sp) */
    .word 0x24050003 /* addiu      $a1, $zero, 0x3 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x70401628 /* paddub     $v0, $v0, $zero */
    .word 0x00028438 /* dsll       $s0, $v0, 16 */
    jal func_1046A8
    .word 0x02903025 /* or        $a2, $s4, $s0 */
    .word 0x0011103C /* dsll32     $v0, $s1, 0 */
    .word 0x001E183C /* dsll32     $v1, $fp, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x0003183F /* dsra32     $v1, $v1, 0 */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x02623025 /* or         $a2, $s3, $v0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x24050003 /* addiu      $a1, $zero, 0x3 */
    .word 0x02B03025 /* or         $a2, $s5, $s0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x0011103C /* dsll32     $v0, $s1, 0 */
    .word 0x0017183C /* dsll32     $v1, $s7, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x0003183F /* dsra32     $v1, $v1, 0 */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x02623025 /* or         $a2, $s3, $v0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    jal func_104600
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
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
    .word 0x27BD0110 /* addiu     $sp, $sp, 0x110 */
}
}

#else

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

extern unsigned int D_00392B60[4];
extern unsigned short D_00CA158C;
extern unsigned short D_00CA158E;

static void *EnsurePacketObject(void *obj) {
    if (obj != 0) {
        return obj;
    }
    return func_123908(0);
}

static void BuildQuadTag(unsigned long long *tag, int a1, int t1) {
    unsigned long long part1 = 0x8000ULL | (0x10004000ULL << 32);
    unsigned long long v0 = 4 | (((unsigned long long)(unsigned int)a1) << 6) | (((unsigned long long)(unsigned int)t1) << 9);
    unsigned long long part2 = v0 << 47;
    tag[0] = part1 | part2;
    tag[1] = ((unsigned long long)D_00392B60[2]) | (((unsigned long long)D_00392B60[3]) << 32);
}

static void TransformDstCoords(int *out_x, int *out_y, const int *rect, int t2) {
    int center_x = (int)D_00CA158C;
    int center_y = (int)D_00CA158E;
    int base_x = (0x800 - (center_x >> 1)) << 4;
    int base_y = (0x800 - (center_y >> 1)) << 4;
    int depth_offset = (-t2) << 3;

    int x = rect[0];
    int y = rect[1];
    int w = rect[2];
    int h = rect[3];

    out_x[0] = (x << 4) + base_x + depth_offset;
    out_y[0] = (y << 4) + base_y + depth_offset;

    out_x[1] = ((x + w) << 4) + base_x + depth_offset;
    out_y[1] = (y << 4) + base_y + depth_offset;

    out_x[2] = (x << 4) + base_x + depth_offset;
    out_y[2] = ((y + h) << 4) + base_y + depth_offset;

    out_x[3] = ((x + w) << 4) + base_x + depth_offset;
    out_y[3] = ((y + h) << 4) + base_y + depth_offset;
}

static void TransformSrcCoords(int *out_u, int *out_v, const int *rect) {
    int u = rect[0];
    int v = rect[1];
    int w = rect[2];
    int h = rect[3];

    out_u[0] = (u << 4);
    out_v[0] = (v << 4);

    out_u[1] = ((u + w) << 4);
    out_v[1] = (v << 4);

    out_u[2] = (u << 4);
    out_v[2] = ((v + h) << 4);

    out_u[3] = ((u + w) << 4);
    out_v[3] = ((v + h) << 4);
}

void *func_0021CFB0(void *obj, unsigned long long tex0_val, int s0, int tex0_reg_flag, const int *src_rect, const int *dst_rect, int depth_z, int priority) {
    void *packet = EnsurePacketObject(obj);

    unsigned long long tag[2];
    BuildQuadTag(tag, s0, priority);

    int xs[4], ys[4];
    TransformDstCoords(xs, ys, dst_rect, priority);

    int us[4], vs[4];
    TransformSrcCoords(us, vs, src_rect);

    func_104448(packet, 0, 0, 0);
    func_1045E8(packet, tag);

    int tex_reg = tex0_reg_flag ? 0x07 : 0x06;
    func_1046A8(packet, tex_reg, tex0_val);

    // Default white RGBAQ (0x80808080 or passed color)
    func_1046A8(packet, 0x01, 0x80808080ULL);

    unsigned long long z_upper = ((unsigned long long)(unsigned int)(depth_z & 0xFFFF)) << 32;

    for (int i = 0; i < 4; ++i) {
        unsigned long long uv = ((unsigned long long)(unsigned int)us[i]) | (((unsigned long long)(unsigned int)vs[i]) << 16);
        func_1046A8(packet, 0x03, uv);

        unsigned long long xyz = z_upper | ((unsigned long long)(unsigned int)xs[i]) | (((unsigned long long)(unsigned int)ys[i]) << 16);
        func_1046A8(packet, 0x04, xyz);
    }

    func_104600(packet);
    return packet;
}
}

#endif
