#pragma once
#pragma exceptions off

#include "zone_raster_extent.h"

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
    char pad_8E90[0x48];    // 0x8E90..0x8ED7
    int *f_8ED8;            // 0x8ED8 (-0x7128 = -28968)
};

extern "C" {
extern int D_00392020[];
}

extern "C" int func_001CA670(void *self, int x, int y, int *out_x1, int *out_y1, int *out_x2, int *out_y2) {
    *out_x1 = x;
    *out_y1 = y;
    *out_x2 = x;
    *out_y2 = y;

    ZoneLayout *zm = (ZoneLayout *)self;

    for (;;) {
        if (x < 0 || !(x < zm->width) || y < 0 || !(y < zm->height)) {
            return 0;
        }

        int x_off = ((x << 3) - x) << 2;
        char *cell = (char *)zm->cells_ptr[y] + x_off;

        unsigned char tag = (unsigned char)(cell[0xB] & 0x60);
        if (tag == 0x40) {
            unsigned char idx = (unsigned char)cell[0xC];
            if (!idx) {
                return 0;
            }
            int packed = zm->f_8ED8[idx - 1];
            char *bytes = (char *)&packed;
            *out_x1 = x - bytes[0];
            *out_y1 = y - bytes[1];
            *out_x2 = x + bytes[2];
            *out_y2 = y + bytes[3];
            return 1;
        }

        if (!tag) {
            return 0;
        }

        int dx = 0;
        int dy = 0;
        if (tag == 0x20) {
            unsigned char val = (unsigned char)cell[0xC];
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
