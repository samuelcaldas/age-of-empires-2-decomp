#pragma exceptions off
#include "sub_list.h"

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
