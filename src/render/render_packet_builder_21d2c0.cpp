#pragma exceptions off
#include "sub_list.h"

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
