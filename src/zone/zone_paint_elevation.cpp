#pragma once
#pragma exceptions off

#include "zone_paint_elevation.h"

#if defined(__mips__)

extern "C" asm int func_001CD060(void *self, int cx, int cy, int radius, int elevation) {
    .word 0x00C75823
    .word 0x00A74823
    .word 0x00A75021
    .word 0x05210002
    .word 0x00C73021
    .word 0x70004E28
    .word 0x8C830008
    .word 0x0143102A
    .word 0x14400002
    .word 0x00000000
    .word 0x246AFFFF
    .word 0x05610002
    .word 0x00000000
    .word 0x70005E28
    .word 0x8C83000C
    .word 0x00C3102A
    .word 0x14400014
    .word 0x00CB082A
    .word 0x10000011
    .word 0x2466FFFF
    .word 0x1000000B
    .word 0x000B6080
    .word 0x00810821
    .word 0x8C258E8C
    .word 0x000710C0
    .word 0x00471023
    .word 0x00021880
    .word 0x24E70001
    .word 0x01851021
    .word 0x8C420000
    .word 0x00431021
    .word 0xA0480006
    .word 0x0147082A
    .word 0x1020FFF4
    .word 0x3C010001
    .word 0x256B0001
    .word 0x00CB082A
    .word 0x1020FFEE
    .word 0x71203E28
    .word 0x03E00008
    .word 0x24020001
}

#else

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

#endif
