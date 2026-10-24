#pragma once
#pragma exceptions off

#include "zone_raster_trace.h"

struct ZoneCell {
    char pad_0[11];         // 0x0..0xA
    unsigned char f_B;      // 0xB (11)
    unsigned char f_C;      // 0xC (12)
    char pad_D[15];         // to reach 0x1C (28 bytes)
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
};

extern "C" {
extern int D_00392020[];
}

extern "C" int func_001CA560(void *self, int x, int y, int *out_x, int *out_y) {
    *out_x = x;
    *out_y = y;

    ZoneLayout *zm = (ZoneLayout *)self;

loop:
    if (x < 0) return 0;
    if (!(x < zm->width)) return 0;
    if (y < 0) return 0;
    if (!(y < zm->height)) return 0;

    {
        int x_offset = (x * 8 - x) * 4;
        ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + x_offset);

        unsigned char tag = (unsigned char)(cell->f_B & 0x60);
        if (tag == 0x40 || !tag) {
            *out_x = x;
            *out_y = y;
            return 1;
        }

        if (tag != 0x20) {
            return 0;
        }

        unsigned char val = cell->f_C;
        int dx = D_00392020[val & 0xF];
        int dy = D_00392020[(val & 0xF0) >> 4];

        x -= dx;
        if (dx != 0) {
            y -= dy;
            goto loop;
        }
        y -= dy;
        if (dy != 0) {
            goto loop;
        }
    }

    return 0;
}
