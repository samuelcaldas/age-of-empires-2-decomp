#pragma once
#pragma exceptions off

#include "zone_raster_register.h"

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8EC0];    // 0x10..0x8ECF
    int f_8ED0;             // 0x8ED0 (-28976)
    int f_8ED4;             // 0x8ED4 (-28972)
    int *f_8ED8;            // 0x8ED8 (-28968)
    short **f_8EDC;         // 0x8EDC (-28964)
};

extern "C" {
void *func_00100730(unsigned int size);
void func_001CAC00(void *self, short *buffer, int p1, int p2);
}

extern "C" int func_001CA7F0(void *self, int px, int py, int x0, int y0, int x1, int y1) {
    if (x1 < x0) {
        int tmp = x0; x0 = x1; x1 = tmp;
    }
    if (y1 < y0) {
        int tmp = y0; y0 = y1; y1 = tmp;
    }

    ZoneLayout *zm = (ZoneLayout *)self;

    if (!(x0 < zm->width)) return 0;
    if (!(y0 < zm->height)) return 0;
    if (x1 < 0) return 0;
    if (y1 < 0) return 0;

    if (x0 == x1 && y0 == y1) return 0;

    signed char ext[4];
    ext[0] = (signed char)(px - x0);
    ext[1] = (signed char)(py - y0);
    ext[2] = (signed char)(x1 - px);
    ext[3] = (signed char)(y1 - py);
    int packed = *(int *)ext;

    int search_limit = zm->f_8ED4;
    if (search_limit > 0) {
        int count = zm->f_8ED0;
        for (int i = 0; i < count; i++) {
            if (zm->f_8ED8[i] == packed) {
                return i + 1;
            }
        }
    }

    int idx = zm->f_8ED0;
    int rect_w = (x1 - x0) + 1;
    int rect_h = (y1 - y0) + 1;

    zm->f_8ED8[idx] = packed;

    int s0 = 1;
    if (rect_w != 1) {
        s0 = 2;
        if (rect_w >= 3) {
            s0 = (rect_w + 1) >> 1;
        }
    }

    int s1 = 1;
    int s7 = s0 << 1;
    if (rect_h != 1) {
        s1 = 2;
        if (rect_h >= 3) {
            s1 = (rect_h + 1) >> 1;
            s7 = (s0 + (s1 - 2)) << 1;
        }
    }

    int total_alloc = (s7 + 2) << 2;
    short *buf = (short *)func_00100730((unsigned int)total_alloc);
    zm->f_8EDC[idx] = buf;

    buf[0] = 0;
    buf[1] = (short)(s7 + 1);

    int dx_left = x0 - px;
    int dy_top = y0 - py;
    int dx_right = x1 - px;
    int dy_bottom = y1 - py;

    func_001CAC00(self, buf, dx_left, dy_top);
    func_001CAC00(self, buf, dx_right, dy_top);
    func_001CAC00(self, buf, dx_left, dy_bottom);
    func_001CAC00(self, buf, dx_right, dy_bottom);

    if (s0 >= 3) {
        for (int s5 = 1; s5 <= s0 - 2; s5++) {
            int step = s5 << 1;
            func_001CAC00(self, buf, dx_left + step, dy_top);
            if (s1 >= 2) {
                func_001CAC00(self, buf, dx_right - step, dy_bottom);
            }
        }
    }

    if (s1 >= 3) {
        for (int s5 = 1; s5 <= s1 - 2; s5++) {
            int step = s5 << 1;
            func_001CAC00(self, buf, dx_left, dy_top + step);
            if (s0 >= 2) {
                func_001CAC00(self, buf, dx_right, dy_bottom - step);
            }
        }
    }

    zm->f_8ED0++;
    return zm->f_8ED0;
}
