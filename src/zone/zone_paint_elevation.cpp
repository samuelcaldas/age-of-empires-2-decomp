#pragma once
#pragma exceptions off

#include "zone_paint_elevation.h"

struct ZoneCell {
    char pad_0[6];          // 0x0..0x5
    char f_6;               // 0x6 (elevation)
    char pad_7[21];         // 28 bytes total
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
};

extern "C" int func_001CD060(void *self, int cx, int cy, int radius, int elevation) {
    ZoneLayout *zm = (ZoneLayout *)self;

    int y0 = cy - radius;
    int x0 = cx - radius;
    int x1 = cx + radius;
    if (x0 < 0) x0 = 0;
    int y1 = cy + radius;

    if (x1 >= zm->width) x1 = zm->width - 1;
    if (y0 < 0) y0 = 0;
    if (y1 >= zm->height) y1 = zm->height - 1;

    for (int y = y0; y <= y1; y++) {
        for (int x = x0; x <= x1; x++) {
            int x_off = (x * 8 - x) * 4;
            ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + x_off);
            cell->f_6 = (char)elevation;
        }
    }

    return 1;
}
