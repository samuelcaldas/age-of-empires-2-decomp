#pragma once
#pragma exceptions off

#include "zone_raster_untag.h"

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

extern "C" int func_001CA430(void *self, int x0, int y0, int x1, int y1) {
    if (x0 == x1 && y0 == y1) {
        return 1;
    }

    if (x1 < x0) {
        int tmp = x0; x0 = x1; x1 = tmp;
    }
    if (y1 < y0) {
        int tmp = y0; y0 = y1; y1 = tmp;
    }

    ZoneLayout *zm = (ZoneLayout *)self;

    if (!(x0 < zm->width && y0 < zm->height && x1 >= 0 && y1 >= 0)) {
        return 0;
    }

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= zm->width) x1 = zm->width - 1;
    if (y1 >= zm->height) y1 = zm->height - 1;

    int x0_offset = (x0 * 7) << 2;

    for (int y = y0; y <= y1; y++) {
        char *cell = (char *)zm->cells_ptr[y] + x0_offset;
        for (int x = x0; x <= x1; x++, cell += 0x1C) {
            cell[0xC] = 0;
            cell[0xB] = (unsigned char)(cell[0xB] & 0x9F);
        }
    }

    return 1;
}
