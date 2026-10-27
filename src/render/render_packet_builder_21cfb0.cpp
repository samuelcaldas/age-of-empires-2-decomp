#pragma exceptions off
#include "sub_list.h"

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
