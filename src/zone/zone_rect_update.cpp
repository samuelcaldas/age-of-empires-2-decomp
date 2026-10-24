#pragma once
#pragma exceptions off

#include "zone_rect_update.h"

struct ZoneCell {
    short f_0;              // 0x0
    short f_2;              // 0x2
    unsigned char f_4;      // 0x4
    unsigned char f_5;      // 0x5
    unsigned char f_6;      // 0x6
    unsigned char f_7;      // 0x7
    char pad_8[20];         // to reach 0x1C (28 bytes)
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
    char pad_8E90[0x22];    // 0x8E90..0x8EB1
    short f_8EB2;           // 0x8EB2 (-0x714E)
    short f_8EB4;           // 0x8EB4 (-0x714C)
    short f_8EB6;           // 0x8EB6 (-0x714A)
};

extern "C" void func_001C9FA0(void *self, int x0, int y0, int x1, int y1) {
    ZoneLayout *zm = (ZoneLayout *)self;

    if (x0 < 0) {
        x0 = 0;
    } else {
        int max_x = zm->width - 1;
        if (max_x < x0) {
            x0 = max_x;
        }
    }

    if (y0 < 0) {
        y0 = 0;
    } else {
        int max_y = zm->height - 1;
        if (max_y < y0) {
            y0 = max_y;
        }
    }

    if (x1 < 0) {
        x1 = 0;
    } else {
        int max_x = zm->width - 1;
        if (max_x < x1) {
            x1 = max_x;
        }
    }

    if (y1 < 0) {
        y1 = 0;
    } else {
        int max_y = zm->height - 1;
        if (max_y < y1) {
            y1 = max_y;
        }
    }

    int x0_offset = (x0 * 8 - x0) * 4;

    int y = y0;
    while (y <= y1) {
        ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + x0_offset);
        int x = x0;
        while (x <= x1) {
            cell->f_0 = (short)((x + y) * zm->f_8EB4);
            cell->f_2 = (short)((y - x) * zm->f_8EB2 - cell->f_6 * zm->f_8EB6);
            unsigned char f4 = cell->f_4;
            if (f4 == 15) goto update;
            if (f4 == 16) goto update;
            if (f4 == 14) goto update;
            if (f4 == 10) goto update;
            if (f4 == 6) goto update;
            if (f4 == 8) goto update;
            if (f4 == 2) goto update;
            goto next;
        update:
            cell->f_2 = (short)(cell->f_2 - zm->f_8EB6);
        next:
            cell = (ZoneCell *)((char *)cell + 0x1C);
            x++;
        }
        y++;
    }
}
