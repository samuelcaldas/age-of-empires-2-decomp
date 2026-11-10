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

    for (;;) {
        if (!(x >= 0 && x < zm->width && y >= 0 && y < zm->height)) {
            return 0;
        }

        int x_offset = ((x << 3) - x) << 2;
        ZoneCell **rows = zm->cells_ptr;
        ZoneCell *row = rows[y];
        unsigned char *cell = (unsigned char *)row + x_offset;

        unsigned int tag = (unsigned int)(cell[0xB] & 0x60);
        if (tag == 0x40 || tag == 0) {
            *out_x = x;
            *out_y = y;
            return 1;
        }

        int dx = 0;
        int dy = 0;
        if (tag == 0x20) {
            char val = (char)cell[0xC];
            dx = D_00392020[val & 0xF];
            dy = D_00392020[(val & 0xF0) >> 4];
        }

        x -= dx;
        y -= dy;
        if (dx == 0 && dy == 0) {
            return 0;
        }
    }
}
