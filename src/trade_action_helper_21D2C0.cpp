#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

extern unsigned int D_00392B70[4];
extern unsigned int D_00392B80[4];
extern unsigned int D_00392B90[4];
extern unsigned short D_00CA158C;
extern unsigned short D_00CA158E;

static void *EnsurePacketObject(void *obj) {
    if (obj != 0) {
        return obj;
    }
    return func_123908(0);
}

static void BuildSpriteTag(unsigned long long *tag, int a1, int t1) {
    unsigned long long part1 = 0x8000ULL | (0x10004000ULL << 32);
    unsigned long long v0 = 4 | (((unsigned long long)(unsigned int)a1) << 6) | (((unsigned long long)(unsigned int)t1) << 9);
    unsigned long long part2 = v0 << 47;
    tag[0] = part1 | part2;
    tag[1] = ((unsigned long long)D_00392B70[2]) | (((unsigned long long)D_00392B70[3]) << 32);
}

void *func_0021D2C0(void *obj, int a1, int a2, const short *xy_pts, int t0, int t1, int t2, int t3) {
    void *packet = EnsurePacketObject(obj);

    unsigned long long tag[2];
    BuildSpriteTag(tag, a1, t1);

    int center_x = (int)D_00CA158C;
    int center_y = (int)D_00CA158E;
    int base_x = (0x800 - (center_x >> 1)) << 4;
    int base_y = (0x800 - (center_y >> 1)) << 4;
    int depth_offset = (-t2) << 3;

    int xs[4];
    int ys[4];
    for (int i = 0; i < 4; ++i) {
        const short *pt = xy_pts + (i * 4);
        xs[i] = (pt[0] << 4) + base_x + depth_offset;
        ys[i] = (pt[1] << 4) + base_y + depth_offset;
    }

    func_104448(packet, 0, 0, 0);
    func_1045E8(packet, tag);

    func_1046A8(packet, 0x01, (unsigned long long)(unsigned int)a2);

    unsigned long long z_upper = ((unsigned long long)(unsigned int)(t0 & 0xFFFF)) << 32;
    for (int i = 0; i < 4; ++i) {
        unsigned long long xyz = z_upper | ((unsigned long long)(unsigned int)xs[i]) | (((unsigned long long)(unsigned int)ys[i]) << 16);
        func_1046A8(packet, 0x04, xyz);
    }

    func_104600(packet);
    return packet;
}

static void BuildSpriteTagAlt(unsigned long long *tag, int a2) {
    unsigned long long part1 = 0x8000ULL | (0x10004000ULL << 32);
    unsigned long long v0 = 0x116 | (((unsigned long long)(unsigned int)a2) << 6);
    unsigned long long part2 = v0 << 47;
    tag[0] = part1 | part2;
    tag[1] = ((unsigned long long)D_00392B80[2]) | (((unsigned long long)D_00392B80[3]) << 32);
}

void *func_0021D4E0(void *obj, int a1, int a2, int a3, const short *xy_pts, int t0, int t1, int t2, int t3) {
    void *packet = EnsurePacketObject(obj);

    unsigned long long tag[2];
    BuildSpriteTagAlt(tag, a2);

    int center_x = (int)D_00CA158C;
    int center_y = (int)D_00CA158E;
    int base_x = (0x800 - (center_x >> 1)) << 4;
    int base_y = (0x800 - (center_y >> 1)) << 4;
    int depth_offset = (-t2) << 3;

    int xs[4];
    int ys[4];
    for (int i = 0; i < 4; ++i) {
        const short *pt = xy_pts + (i * 4);
        xs[i] = (pt[0] << 4) + base_x + depth_offset;
        ys[i] = (pt[1] << 4) + base_y + depth_offset;
    }

    func_104448(packet, 0, 0, 0);
    func_1045E8(packet, tag);

    if (t3 != 0) {
        func_1046A8(packet, 0x07, (unsigned long long)(unsigned int)a1);
    } else {
        func_1046A8(packet, 0x06, (unsigned long long)(unsigned int)a1);
    }
    func_1046A8(packet, 0x01, (unsigned long long)(unsigned int)a3);

    unsigned long long z_upper = ((unsigned long long)(unsigned int)(t0 & 0xFFFF)) << 32;
    for (int i = 0; i < 4; ++i) {
        unsigned long long xyz = z_upper | ((unsigned long long)(unsigned int)xs[i]) | (((unsigned long long)(unsigned int)ys[i]) << 16);
        func_1046A8(packet, 0x04, xyz);
    }

    func_104600(packet);
    return packet;
}
}
