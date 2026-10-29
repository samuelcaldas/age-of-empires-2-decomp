#pragma once
#pragma exceptions off

#include "zone_paint_terrain.h"

extern "C" {
void func_1CF830(void *self, void *world, short x, short y, int terrain_type, int p5, int p6);
}

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8ED8];    // 0x10..0x8EE7
    void *m_world;          // 0x8EE8 (-0x7118)
};

extern "C" int func_001CCD10(void *self, int cx, int cy, int radius, int terrain_type) {
    ZoneLayout *zm = (ZoneLayout *)self;

    int x0 = cx - radius;
    int x1 = cx + radius;
    int y1 = cy + radius;
    int y0 = cy - radius;

    if (x0 < 0) {
        x0 = 0;
    }
    if (!(x1 < zm->width)) {
        x1 = zm->width - 1;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (!(y1 < zm->height)) {
        y1 = zm->height - 1;
    }

    for (int y = y0; y <= y1; y++) {
        for (int x = x0; x <= x1; x++) {
            func_1CF830(zm, zm->m_world, (short)x, (short)y, terrain_type, 0, 0);
        }
    }

    return 1;
}
