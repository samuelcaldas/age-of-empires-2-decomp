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

static void BuildSpriteTag(unsigned long long *tag, int a2, int t3) {
    unsigned long long part1 = 0x8000ULL | (0x10004000ULL << 32);
    unsigned long long v0 = 0x114 | (((unsigned long long)(unsigned int)a2) << 6) | (((unsigned long long)(unsigned int)t3) << 9);
    unsigned long long part2 = v0 << 47;
    tag[0] = part1 | part2;
    tag[1] = ((unsigned long long)D_00392B60[2]) | (((unsigned long long)D_00392B60[3]) << 32);
}

static void TransformRectCoords(int *out_coords, const int *xy_rect, int z) {
    int center_x = (int)D_00CA158C;
    int center_y = (int)D_00CA158E;
    int base_x = (0x800 - (center_x >> 1)) << 4;
    int base_y = (0x800 - (center_y >> 1)) << 4;
    int depth_offset = (-z) << 3;

    out_coords[0] = (xy_rect[0] << 4) + base_x + depth_offset; // X0
    out_coords[1] = (xy_rect[2] << 4) + base_x + depth_offset; // X1
    out_coords[2] = (xy_rect[1] << 4) + base_y + depth_offset; // Y0
    out_coords[3] = (xy_rect[3] << 4) + base_y + depth_offset; // Y1
}

static void EmitSpriteRegisters(void *obj, int a1, int a3, int t3) {
    int reg = 0x06;
    if (t3 != 0) {
        reg = 0x07;
    }
    func_1046A8(obj, reg, (unsigned long long)(unsigned int)a1);
    func_1046A8(obj, 0x01, (unsigned long long)(unsigned int)a3);
}

static void EmitQuadVertices(void *obj, const int *uv_rect, const int *coords, int t2) {
    unsigned long long u0 = (unsigned long long)(unsigned int)(uv_rect[0] << 4);
    unsigned long long v0 = (unsigned long long)(unsigned int)(uv_rect[1] << 4);
    unsigned long long u1 = (unsigned long long)(unsigned int)(uv_rect[2] << 4);
    unsigned long long v1 = (unsigned long long)(unsigned int)(uv_rect[3] << 4);

    int x0 = coords[0];
    int x1 = coords[1];
    int y0 = coords[2];
    int y1 = coords[3];

    unsigned long long z_upper = ((unsigned long long)(unsigned int)(t2 & 0xFFFF)) << 32;

    func_1046A8(obj, 0x03, u0 | (v0 << 16));
    func_1046A8(obj, 0x04, z_upper | ((unsigned long long)(unsigned int)x0) | (((unsigned long long)(unsigned int)y0) << 16));

    func_1046A8(obj, 0x03, u1 | (v0 << 16));
    func_1046A8(obj, 0x04, z_upper | ((unsigned long long)(unsigned int)x1) | (((unsigned long long)(unsigned int)y0) << 16));

    func_1046A8(obj, 0x03, u0 | (v1 << 16));
    func_1046A8(obj, 0x04, z_upper | ((unsigned long long)(unsigned int)x0) | (((unsigned long long)(unsigned int)y1) << 16));

    func_1046A8(obj, 0x03, u1 | (v1 << 16));
    func_1046A8(obj, 0x04, z_upper | ((unsigned long long)(unsigned int)x1) | (((unsigned long long)(unsigned int)y1) << 16));
}

void *func_0021CFB0(void *obj, int a1, int a2, int a3, const int *xy_rect, const int *uv_rect, int t2, int t3, int z) {
    void *packet = EnsurePacketObject(obj);

    unsigned long long tag[2];
    BuildSpriteTag(tag, a2, t3);

    int coords[4];
    TransformRectCoords(coords, xy_rect, z);

    func_104448(packet, 0, 0, 0);
    func_1045E8(packet, tag);

    EmitSpriteRegisters(packet, a1, a3, t3);
    EmitQuadVertices(packet, uv_rect, coords, t2);

    func_104600(packet);
    return packet;
}
}
