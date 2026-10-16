#pragma once
#pragma exceptions off

#include "zone_paint_cliff_line.h"

extern "C" {
typedef long long int64_t;
int64_t func_122690(int x);
int64_t func_122118(int64_t a, int64_t b);
int64_t func_122058(int64_t a, int64_t b);
float func_1228E8(int64_t a);
float sqrtf(float f);
int64_t func_1234E0(float f);
int func_122748(int64_t a);
int64_t func_1223C0(int64_t a, int64_t b);
int func_100100(int64_t a, int64_t b);
}

struct ZoneLayout {
    void **vtable;          // 0x0
    char pad_4[4];          // 0x4..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8ED8];    // 0x10..0x8EE7
    void *m_world;          // 0x8EE8 (-0x7118)
};

typedef int (*PaintCliffFn)(void *self, int x, int y, int param1, int param2);

extern "C" int func_001CD3D0(void *self, int x0, int y0, int x1, int y1, int param1, int param2) {
    ZoneLayout *zm = (ZoneLayout *)self;
    unsigned char p1 = (unsigned char)param1;
    unsigned char p2 = (unsigned char)param2;

    if (x0 < 0) x0 = 0;
    if (x1 >= zm->width) x1 = zm->width - 1;
    if (y0 < 0) y0 = 0;
    if (y1 >= zm->height) y1 = zm->height - 1;

    int64_t dx_fp = func_122690(x1 - x0);
    int64_t dy_fp = func_122690(y1 - y0);

    int64_t dx2 = func_122118(dx_fp, dx_fp);
    int64_t dy2 = func_122118(dy_fp, dy_fp);
    int64_t sum2 = func_122058(dx2, dy2);
    float dist_flt = sqrtf(func_1228E8(sum2));
    int64_t dist_fp = func_1234E0(dist_flt);
    int steps = func_122748(dist_fp);

    int64_t steps_fp = func_122690(steps);
    int64_t step_x = func_1223C0(dx_fp, steps_fp);
    int64_t step_y = func_1223C0(dy_fp, steps_fp);

    int64_t cur_x = func_122690(x0);
    int64_t cur_y = func_122690(y0);

    ((PaintCliffFn)zm->vtable[8])(zm, x0, y0, (int)p1, (int)p2);

    for (int i = steps; i > 0; i--) {
        cur_x = func_122058(cur_x, step_x);
        cur_y = func_122058(cur_y, step_y);
        int px = func_122748(cur_x);
        int py = func_122748(cur_y);
        ((PaintCliffFn)zm->vtable[8])(zm, px, py, (int)p1, (int)p2);
    }

    int64_t target_x_fp = func_122690(x1);
    if (func_100100(cur_x, target_x_fp) == 0) {
        int64_t target_y_fp = func_122690(y1);
        if (func_100100(cur_y, target_y_fp) != 0) {
            ((PaintCliffFn)zm->vtable[8])(zm, x1, y1, (int)p1, (int)p2);
        }
    }

    return 1;
}
