#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

void *func_0021CD20(void *obj, int a1, int a2, const short *xy_pts, int t0, int t1, int t2);

asm void *func_0021CD20(void *obj, int a1, int a2, const short *xy_pts, int t0, int t1, int t2) {
    .word 0x27BDFF70 /* addiu      $sp, $sp, -0x90 */
    .word 0x0005103C /* dsll32     $v0, $a1, 0 */
    .word 0x7FBF0050 /* sq         $ra, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x000211B8 /* dsll       $v0, $v0, 6 */
    .word 0x34430004 /* ori        $v1, $v0, 0x4 */
    .word 0x0009103C /* dsll32     $v0, $t1, 0 */
    .word 0x0002103F /* dsra32     $v0, $v0, 0 */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x00021278 /* dsll       $v0, $v0, 9 */
    .word 0x70808628 /* paddub     $s0, $a0, $zero */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    .word 0x000223FC /* dsll32     $a0, $v0, 15 */
    .word 0x3C020039 /* lui        $v0, (0x392B50 >> 16) */
    .word 0x24422B50 /* addiu      $v0, $v0, (0x392B50 & 0xFFFF) */
    .word 0x78450000 /* lq         $a1, 0x0($v0) */
    .word 0x70C0A628 /* paddub     $s4, $a2, $zero */
    .word 0x27A60060 /* addiu      $a2, $sp, 0x60 */
    .word 0x70E09E28 /* paddub     $s3, $a3, $zero */
    .word 0x71009628 /* paddub     $s2, $t0, $zero */
    .word 0x3C021000 /* lui        $v0, (0x10004000 >> 16) */
    .word 0x34424000 /* ori        $v0, $v0, (0x10004000 & 0xFFFF) */
    .word 0x0002183C /* dsll32     $v1, $v0, 0 */
    .word 0x34028000 /* ori        $v0, $zero, 0x8000 */
    .word 0x00431025 /* or         $v0, $v0, $v1 */
    .word 0x7CC50000 /* sq         $a1, 0x0($a2) */
    .word 0x00821025 /* or         $v0, $a0, $v0 */
    .word 0x71408E28 /* paddub     $s1, $t2, $zero */
    .word 0x16000004 /* bnez       $s0, .L0021CDB4 */
    .word 0xFFA20060 /* sd         $v0, 0x60($sp) */
    jal func_123908
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    .word 0x70408628 /* paddub     $s0, $v0, $zero */
    .word 0x3C0100CA /* lui        $at, (0xCA158C >> 16) */
    .word 0x9425158C /* lhu        $a1, (0xCA158C & 0xFFFF)($at) */
    .word 0x00111023 /* negu       $v0, $s1 */
    .word 0x000218C0 /* sll        $v1, $v0, 3 */
    .word 0x24060800 /* addiu      $a2, $zero, 0x800 */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x3C0100CA /* lui        $at, (0xCA158E >> 16) */
    .word 0x9424158E /* lhu        $a0, (0xCA158E & 0xFFFF)($at) */
    .word 0x00052843 /* sra        $a1, $a1, 1 */
    .word 0x00C52823 /* subu       $a1, $a2, $a1 */
    .word 0x00053900 /* sll        $a3, $a1, 4 */
    .word 0x00042043 /* sra        $a0, $a0, 1 */
    .word 0x00C42023 /* subu       $a0, $a2, $a0 */
    .word 0x10000010 /* b          .L0021CE2C */
    .word 0x00043100 /* sll        $a2, $a0, 4 */
    .word 0x000220C0 /* sll        $a0, $v0, 3 */
    .word 0x02644021 /* addu       $t0, $s3, $a0 */
    .word 0x85040000 /* lh         $a0, 0x0($t0) */
    .word 0x00022880 /* sll        $a1, $v0, 2 */
    .word 0x00BD2821 /* addu       $a1, $a1, $sp */
    .word 0x24420001 /* addiu      $v0, $v0, 0x1 */
    .word 0x00042100 /* sll        $a0, $a0, 4 */
    .word 0x00E42021 /* addu       $a0, $a3, $a0 */
    .word 0x00642021 /* addu       $a0, $v1, $a0 */
    .word 0xACA40070 /* sw         $a0, 0x70($a1) */
    .word 0x85040002 /* lh         $a0, 0x2($t0) */
    .word 0x00042100 /* sll        $a0, $a0, 4 */
    .word 0x00C42021 /* addu       $a0, $a2, $a0 */
    .word 0x00642021 /* addu       $a0, $v1, $a0 */
    .word 0xACA40080 /* sw         $a0, 0x80($a1) */
    .word 0x28440004 /* slti       $a0, $v0, 0x4 */
    .word 0x1480FFF0 /* bnez       $a0, .L0021CDF4 */
    .word 0x000220C0 /* sll        $a0, $v0, 3 */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    .word 0x70003628 /* paddub     $a2, $zero, $zero */
    jal func_104448
    .word 0x70003E28 /* paddub     $a3, $zero, $zero */
    .word 0x27A20060 /* addiu      $v0, $sp, 0x60 */
    .word 0x78450000 /* lq         $a1, 0x0($v0) */
    jal func_1045E8
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x0014303C /* dsll32     $a2, $s4, 0 */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    .word 0x0006303F /* dsra32     $a2, $a2, 0 */
    jal func_1046A8
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x3242FFFF /* andi       $v0, $s2, 0xFFFF */
    .word 0x0002883C /* dsll32     $s1, $v0, 0 */
    .word 0x8FA20080 /* lw         $v0, 0x80($sp) */
    .word 0x8FA30070 /* lw         $v1, 0x70($sp) */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    jal func_1046A8
    .word 0x02223025 /* or         $a2, $s1, $v0 */
    .word 0x8FA20084 /* lw         $v0, 0x84($sp) */
    .word 0x8FA30074 /* lw         $v1, 0x74($sp) */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    jal func_1046A8
    .word 0x02223025 /* or         $a2, $s1, $v0 */
    .word 0x8FA20088 /* lw         $v0, 0x88($sp) */
    .word 0x8FA30078 /* lw         $v1, 0x78($sp) */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    jal func_1046A8
    .word 0x02223025 /* or         $a2, $s1, $v0 */
    .word 0x8FA2008C /* lw         $v0, 0x8C($sp) */
    .word 0x8FA3007C /* lw         $v1, 0x7C($sp) */
    .word 0x24050004 /* addiu      $a1, $zero, 0x4 */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x00021438 /* dsll       $v0, $v0, 16 */
    .word 0x00621025 /* or         $v0, $v1, $v0 */
    jal func_1046A8
    .word 0x02223025 /* or         $a2, $s1, $v0 */
    jal func_104600
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x72001628 /* paddub     $v0, $s0, $zero */
    .word 0x7BBF0050 /* lq         $ra, 0x50($sp) */
    .word 0x7BB40040 /* lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0090 /* addiu      $sp, $sp, 0x90 */
}

asm void *func_0021CF30(void *obj, int a1, int a2, const short *rect, int t0, int t1) {
    .word 0x27BDFFD0 /* addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0000 /* sq         $ra, 0x0($sp) */
    .word 0x84E20000 /* lh         $v0, 0x0($a3) */
    .word 0x240A0001 /* addiu      $t2, $zero, 0x1 */
    .word 0xA7A20010 /* sh         $v0, 0x10($sp) */
    .word 0x84E20002 /* lh         $v0, 0x2($a3) */
    .word 0xA7A20012 /* sh         $v0, 0x12($sp) */
    .word 0x84E30000 /* lh         $v1, 0x0($a3) */
    .word 0x84E20004 /* lh         $v0, 0x4($a3) */
    .word 0x00621021 /* addu       $v0, $v1, $v0 */
    .word 0xA7A20018 /* sh         $v0, 0x18($sp) */
    .word 0x84E20002 /* lh         $v0, 0x2($a3) */
    .word 0xA7A2001A /* sh         $v0, 0x1A($sp) */
    .word 0x84E20000 /* lh         $v0, 0x0($a3) */
    .word 0xA7A20020 /* sh         $v0, 0x20($sp) */
    .word 0x84E30002 /* lh         $v1, 0x2($a3) */
    .word 0x84E20006 /* lh         $v0, 0x6($a3) */
    .word 0x00621021 /* addu       $v0, $v1, $v0 */
    .word 0xA7A20022 /* sh         $v0, 0x22($sp) */
    .word 0x84E30000 /* lh         $v1, 0x0($a3) */
    .word 0x84E20004 /* lh         $v0, 0x4($a3) */
    .word 0x00621021 /* addu       $v0, $v1, $v0 */
    .word 0xA7A20028 /* sh         $v0, 0x28($sp) */
    .word 0x84E30002 /* lh         $v1, 0x2($a3) */
    .word 0x84E20006 /* lh         $v0, 0x6($a3) */
    .word 0x00621021 /* addu       $v0, $v1, $v0 */
    .word 0x27A70010 /* addiu      $a3, $sp, 0x10 */
    jal func_0021CD20
    .word 0xA7A2002A /* sh         $v0, 0x2A($sp) */
    .word 0x7BBF0000 /* lq         $ra, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0030 /* addiu      $sp, $sp, 0x30 */
}

}

#else

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

extern unsigned int D_00392B50[4];
extern unsigned short D_00CA158C;
extern unsigned short D_00CA158E;

static void *EnsurePacketObject(void *obj) {
    if (obj != 0) {
        return obj;
    }
    return func_123908(0);
}

static void BuildLineTag(unsigned long long *tag, int a1, int t1) {
    unsigned long long part1 = 0x8000ULL | (0x10004000ULL << 32);
    unsigned long long v0 = 4 | (((unsigned long long)(unsigned int)a1) << 6) | (((unsigned long long)(unsigned int)t1) << 9);
    unsigned long long part2 = v0 << 47;
    tag[0] = part1 | part2;
    tag[1] = ((unsigned long long)D_00392B50[2]) | (((unsigned long long)D_00392B50[3]) << 32);
}

static void TransformQuadCoords(int *out_x, int *out_y, const short *xy_pts, int t2) {
    int center_x = (int)D_00CA158C;
    int center_y = (int)D_00CA158E;
    int base_x = (0x800 - (center_x >> 1)) << 4;
    int base_y = (0x800 - (center_y >> 1)) << 4;
    int depth_offset = (-t2) << 3;

    for (int i = 0; i < 4; ++i) {
        const short *pt = xy_pts + (i * 4);
        out_x[i] = (pt[0] << 4) + base_x + depth_offset;
        out_y[i] = (pt[1] << 4) + base_y + depth_offset;
    }
}

static void EmitQuadVertices(void *obj, const int *xs, const int *ys, int t0) {
    unsigned long long z_upper = ((unsigned long long)(unsigned int)(t0 & 0xFFFF)) << 32;

    for (int i = 0; i < 4; ++i) {
        unsigned long long xyz = z_upper | ((unsigned long long)(unsigned int)xs[i]) | (((unsigned long long)(unsigned int)ys[i]) << 16);
        func_1046A8(obj, 0x04, xyz);
    }
}

void *func_0021CD20(void *obj, int a1, int a2, const short *xy_pts, int t0, int t1, int t2) {
    void *packet = EnsurePacketObject(obj);

    unsigned long long tag[2];
    BuildLineTag(tag, a1, t1);

    int xs[4];
    int ys[4];
    TransformQuadCoords(xs, ys, xy_pts, t2);

    func_104448(packet, 0, 0, 0);
    func_1045E8(packet, tag);

    func_1046A8(packet, 0x01, (unsigned long long)(unsigned int)a2);
    EmitQuadVertices(packet, xs, ys, t0);

    func_104600(packet);
    return packet;
}

void *func_0021CF30(void *obj, int a1, int a2, const short *rect, int t0, int t1) {
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

    return func_0021CD20(obj, a1, a2, pts, t0, t1, 1);
}
}

#endif
