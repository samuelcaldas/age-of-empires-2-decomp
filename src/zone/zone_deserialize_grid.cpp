#pragma once
#pragma exceptions off

#include "zone_deserialize_grid.h"

struct ZoneCell {
    char pad_0[5];          // 0x0..0x4
    unsigned char f_5;      // 0x5
    unsigned char f_6;      // 0x6
    char pad_7[21];         // to reach 0x1C (28 bytes)
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
};

extern "C" {
void func_00226D90(void *stream, void *data, int size);
void func_1C98A0(void *self, int width, int height);
void func_1CF3E0(void *self, int a1, int a2, short a3, short a4, int t1, int t2, int t3);
void func_1CF9B0(void *self, int a1, int a2, int a3, int t0, short a5, short a6, int t1, long long sp0, long long sp8);
}

extern "C" void func_001CB4D0(void *self, void *stream) {
    int w = 0;
    int h = 0;
    func_00226D90(stream, &w, 4);
    func_00226D90(stream, &h, 4);

    func_1C98A0(self, w, h);

    ZoneLayout *zm = (ZoneLayout *)self;

    for (short y = 0; y < (short)zm->height; y++) {
        for (short x = 0; x < (short)zm->width; x++) {
            unsigned char b1 = 0, b2 = 0, b3 = 0;
            func_00226D90(stream, &b1, 1);
            func_00226D90(stream, &b2, 1);
            func_00226D90(stream, &b3, 1);

            ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + (x * 8 - x) * 4);
            cell->f_5 = b1;
            cell->f_6 = b2;
        }
    }

    short max_x = (short)(zm->width - 1);
    short max_y = (short)(zm->height - 1);

    func_1CF3E0(self, 0, 0, max_x, max_y, 0, 0, 0);
    func_1CF9B0(self, 0, 0, 0, 0, max_x, max_y, 0, 0, 0);
}
