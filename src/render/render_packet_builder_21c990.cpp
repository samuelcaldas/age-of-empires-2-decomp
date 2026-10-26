#pragma exceptions off
#include "sub_list.h"

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
