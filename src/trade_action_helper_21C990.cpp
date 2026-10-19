#pragma exceptions off
#include "sub_list.h"

#ifdef __MWERKS__
typedef unsigned __int128 u128;
#else
struct u128 { unsigned int words[4]; };
#endif

extern "C" {
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, u128 tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

extern unsigned int D_00392B40[];
extern unsigned short D_00CA158C[];
extern unsigned short D_00CA158E[];

void *func_0021C990(void *obj, unsigned long a1, int a2, int a3, const short *uv_rect, const short *xy_pts, int t2, int t3, int z) {
    unsigned long long v0 = ((((unsigned long long)a2) << 6) | 0x114 | (((unsigned long long)t3) << 9)) << 47;
    unsigned long long tag[2];
    *(u128 *)tag = *(u128 *)D_00392B40;
    tag[0] = 0x8000 | (0x10004000ULL << 32) | v0;

    if (obj == 0) {
        obj = func_123908(0);
    }

    int h = (int)uv_rect[2] << 4;
    int center_x = (int)D_00CA158C[0];
    int v = (int)uv_rect[1] << 4;
    int u = (int)uv_rect[0] << 4;
    int w = (int)uv_rect[3] << 4;
    int center_y = (int)D_00CA158E[0];

    int base_x = (0x800 - (center_x >> 1)) << 4;
    int base_y = (0x800 - (center_y >> 1)) << 4;
    int depth_offset = (-z) << 3;

    int xs[4];
    int ys[4];
    for (int i = 0; i < 4; ++i) {
        const short *pt = xy_pts + (i * 4);
        xs[i] = (pt[0] << 4) + base_x + depth_offset;
        ys[i] = (pt[1] << 4) + base_y + depth_offset;
    }

    func_104448(obj, 0, 0, 0);
    func_1045E8(obj, *(u128 *)tag);

    if (t3 != 0) {
        func_1046A8(obj, 0x07, a1);
    } else {
        func_1046A8(obj, 0x06, a1);
    }
    func_1046A8(obj, 0x01, a3);

    unsigned long long uv0 = (((unsigned long long)v) << 16) | ((unsigned long long)u);
    func_1046A8(obj, 0x03, uv0);

    unsigned long long z_upper = ((unsigned long long)(unsigned int)(t2 & 0xFFFF)) << 32;
    unsigned long long xyz0 = (((unsigned long long)ys[0]) << 16) | ((unsigned long long)xs[0]) | z_upper;
    func_1046A8(obj, 0x04, xyz0);

    int u1 = u + h;
    unsigned long long uv1 = (((unsigned long long)v) << 16) | ((unsigned long long)u1);
    func_1046A8(obj, 0x03, uv1);
    unsigned long long xyz1 = (((unsigned long long)ys[1]) << 16) | ((unsigned long long)xs[1]) | z_upper;
    func_1046A8(obj, 0x04, xyz1);

    int v2 = v + w;
    unsigned long long uv2 = (((unsigned long long)v2) << 16) | ((unsigned long long)u);
    func_1046A8(obj, 0x03, uv2);
    unsigned long long xyz2 = (((unsigned long long)ys[2]) << 16) | ((unsigned long long)xs[2]) | z_upper;
    func_1046A8(obj, 0x04, xyz2);

    unsigned long long uv3 = (((unsigned long long)v2) << 16) | ((unsigned long long)u1);
    func_1046A8(obj, 0x03, uv3);
    unsigned long long xyz3 = (((unsigned long long)ys[3]) << 16) | ((unsigned long long)xs[3]) | z_upper;
    func_1046A8(obj, 0x04, xyz3);

    func_104600(obj);
    return obj;
}

void *func_0021CC90(void *obj, unsigned long a1, int a2, int a3, const short *uv_rect, const short *rect, int t2, int t3, int z) {
    short pts[16];
    pts[0] = rect[0];
    pts[1] = rect[1];
    pts[4] = rect[0] + rect[2];
    pts[5] = rect[1];
    pts[8] = rect[0];
    pts[9] = rect[1] + rect[3];
    pts[12] = rect[0] + rect[2];
    pts[13] = rect[1] + rect[3];

    return func_0021C990(obj, a1, a2, a3, uv_rect, pts, t2, t3, z);
}
}
