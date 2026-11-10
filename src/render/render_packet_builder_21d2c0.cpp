#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

void *func_0021D2C0(void *obj, int a1, unsigned long long a2, const int *rect, int a4, int a5);

asm void *func_0021D2C0(void *obj, int a1, unsigned long long a2, const int *rect, int a4, int a5) {
    .word 0x27BDFF60 /* addiu      $sp, $sp, -0xA0 */
    .word 0x0005103C /* dsll32     $v0, $a1, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x7FBF0080 /* sq         $ra, 0x80($sp) */
    .word 0x7FB70070 /* sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* sq         $s5, 0x50($sp) */
    .word 0x000211B8 /* dsll       $v0, $v0, 6 */
    .word 0x34430004 /* ori        $v1, $v0, 0x4 */
    .word 0x0009103C /* dsll32     $v0, $t1, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x00021278 /* dsll       $v0, $v0, 9 */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7080B628 /* paddub     $s6, $a0, $zero */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x000223FC /* dsll32     $a0, $v0, 15 */
    .word 0x000A1023 /* negu       $v0, $t2 */
    .word 0x000288C0 /* sll        $s1, $v0, 3 */
    .word 0x3C020039 /* lui        $v0, 0x39 */
    .word 0x70C0AE28 /* paddub     $s5, $a2, $zero */
    .word 0x24422B70 /* addiu      $v0, $v0, (0x392B70 & 0xFFFF) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x78450000 /* lq         $a1, 0x0($v0) */
    .word 0x27A60090 /* addiu      $a2, $sp, 0x90 */
    .word 0x3C0100CA /* lui        $at, (0xCA158C >> 16) */
    .word 0x70E09628 /* paddub     $s2, $a3, $zero */
    .word 0x7100BE28 /* paddub     $s7, $t0, $zero */
    .word 0x3C021000 /* lui        $v0, (0x10004000 >> 16) */
    .word 0x34424000 /* ori        $v0, $v0, (0x10004000 & 0xFFFF) */
    .word 0x0002183C /* dsll32     $v1, $v0, 0 */
    .word 0x34028000 /* ori        $v0, $zero, 0x8000 */
    .word 0x00431025 /* or         $v0, $v0, $v1 */
    .word 0x7CC50000 /* sq         $a1, 0x0($a2) */
    .word 0x9423158C /* lhu        $v1, (0xCA158C & 0xFFFF)($at) */
    .word 0x00821025 /* or         $v0, $a0, $v0 */
    .word 0xFFA20090 /* sd         $v0, 0x90($sp) */
    .word 0x24040800 /* addiu      $a0, $zero, 0x800 */
    .word 0x3C0100CA /* lui        $at, (0xCA158E >> 16) */
    .word 0x9422158E /* lhu        $v0, (0xCA158E & 0xFFFF)($at) */
    .word 0x00031843 /* sra        $v1, $v1, 1 */
    .word 0x00831823 /* subu       $v1, $a0, $v1 */
    .word 0x00039900 /* sll        $s3, $v1, 4 */
    .word 0x00021043 /* sra        $v0, $v0, 1 */
    .word 0x00821023 /* subu       $v0, $a0, $v0 */
    .word 0x16C00004 /* bnez       $s6, .L0021D390 */
    .word 0x00028100 /* sll       $s0, $v0, 4 */
    jal func_123908
    .word 0x70002628 /* paddub    $a0, $zero, $zero */
    .word 0x7040B628 /* paddub     $s6, $v0, $zero */
    .word 0x8E470000 /* lw         $a3, 0x0($s2) */
    .word 0x8E460008 /* lw         $a2, 0x8($s2) */
    .word 0x8E430004 /* lw         $v1, 0x4($s2) */
    .word 0x8E42000C /* lw         $v0, 0xC($s2) */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    .word 0x00073900 /* sll        $a3, $a3, 4 */
    .word 0x00063100 /* sll        $a2, $a2, 4 */
    .word 0x00F33821 /* addu       $a3, $a3, $s3 */
    .word 0x00D33021 /* addu       $a2, $a2, $s3 */
    .word 0x00031900 /* sll        $v1, $v1, 4 */
    .word 0x00021100 /* sll        $v0, $v0, 4 */
    .word 0x00701821 /* addu       $v1, $v1, $s0 */
    .word 0x00501021 /* addu       $v0, $v0, $s0 */
    .word 0x02279021 /* addu       $s2, $s1, $a3 */
    .word 0x02269821 /* addu       $s3, $s1, $a2 */
    .word 0x0223A021 /* addu       $s4, $s1, $v1 */
    .word 0x02228021 /* addu       $s0, $s1, $v0 */
    .word 0x70003628 /* paddub     $a2, $zero, $zero */
    jal func_104448
    .word 0x70003E28 /* paddub    $a3, $zero, $zero */
    .word 0x27A20090 /* addiu      $v0, $sp, 0x90 */
    .word 0x78450000 /* lq         $a1, 0x0($v0) */
    jal func_1045E8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x0015303C /* dsll32     $a2, $s5, 0 */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    .word 0x0006303F /* dsra32     $a2, $a2, 0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x32E2FFFF /* andi       $v0, $s7, 0xFFFF */
    .word 0x0002883C /* dsll32     $s1, $v0, 0 */
    .word 0x0014103C /* dsll32     $v0, $s4, 0 */
    .word 0x0012183C /* dsll32     $v1, $s2, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x0003183F /* dsra32     $v1, $v1, 0 */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x02223025 /* or         $a2, $s1, $v0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x0014103C /* dsll32     $v0, $s4, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x0013183C /* dsll32     $v1, $s3, 0 */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x0003183F /* dsra32     $v1, $v1, 0 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x02223025 /* or         $a2, $s1, $v0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x0010103C /* dsll32     $v0, $s0, 0 */
    .word 0x0012183C /* dsll32     $v1, $s2, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x0003183F /* dsra32     $v1, $v1, 0 */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x02223025 /* or         $a2, $s1, $v0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x0010103C /* dsll32     $v0, $s0, 0 */
    .word 0x0013183C /* dsll32     $v1, $s3, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x0003183F /* dsra32     $v1, $v1, 0 */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x02223025 /* or         $a2, $s1, $v0 */
    jal func_1046A8
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    jal func_104600
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
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
    .word 0x27BD00A0 /* addiu     $sp, $sp, 0xA0 */
}
}

#else

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

extern unsigned int D_00392B70[4];
extern unsigned short D_00CA158C;
extern unsigned short D_00CA158E;

static void *EnsurePacketObject(void *obj) {
    if (obj != 0) {
        return obj;
    }
    return func_123908(0);
}

static void BuildFillTag(unsigned long long *tag, int a1, int t1) {
    unsigned long long part1 = 0x8000ULL | (0x10004000ULL << 32);
    unsigned long long v0 = 4 | (((unsigned long long)(unsigned int)a1) << 6) | (((unsigned long long)(unsigned int)t1) << 9);
    unsigned long long part2 = v0 << 47;
    tag[0] = part1 | part2;
    tag[1] = ((unsigned long long)D_00392B70[2]) | (((unsigned long long)D_00392B70[3]) << 32);
}

static void TransformFillCoords(int *out_x, int *out_y, const int *rect, int t2) {
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

static void EmitFillVertices(void *obj, const int *xs, const int *ys, int t0) {
    unsigned long long z_upper = ((unsigned long long)(unsigned int)(t0 & 0xFFFF)) << 32;

    for (int i = 0; i < 4; ++i) {
        unsigned long long xyz = z_upper | ((unsigned long long)(unsigned int)xs[i]) | (((unsigned long long)(unsigned int)ys[i]) << 16);
        func_1046A8(obj, 0x04, xyz);
    }
}

void *func_0021D2C0(void *obj, int a1, unsigned long long a2, const int *rect, int a4, int a5) {
    void *packet = EnsurePacketObject(obj);

    unsigned long long tag[2];
    BuildFillTag(tag, a1, a5);

    int xs[4];
    int ys[4];
    TransformFillCoords(xs, ys, rect, a5);

    func_104448(packet, 0, 0, 0);
    func_1045E8(packet, tag);

    func_1046A8(packet, 0x01, a2);
    EmitFillVertices(packet, xs, ys, a4);

    func_104600(packet);
    return packet;
}
}

#endif
