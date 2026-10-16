#pragma once
#pragma exceptions off

#include "zone_world_to_screen.h"

struct ZoneCell {
    short f_0;              // 0x0
    short f_2;              // 0x2
    unsigned char f_4;      // 0x4
    unsigned char f_5;      // 0x5
    char f_6;               // 0x6
    char pad_7[21];         // to reach 0x1C (28 bytes)
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
    char pad_8E90[8];       // 0x8E90..0x8E97
    float width_f;          // 0x8E98 (-0x7168)
    float height_f;         // 0x8E9C (-0x7164)
    char pad_8EA0[0x12];    // 0x8EA0..0x8EB1
    short f_8EB2;           // 0x8EB2 (-0x714E)
    short f_8EB4;           // 0x8EB4 (-0x714C)
    short f_8EB6;           // 0x8EB6 (-0x714A)
};

extern "C" {
int func_00123350(float val);
extern int D_004E3530;
extern int D_004E3534;
}

extern "C" int func_001CAFB0(void *self, int *out_x, int *out_y, int flag, float fx, float fy) {
    ZoneLayout *zm = (ZoneLayout *)self;

    if (fx < 0.0f) fx = 0.0f;
    if (fy < 0.0f) fy = 0.0f;
    if (fx >= zm->width_f) fx = zm->width_f - 0.0001f;
    if (fy >= zm->height_f) fy = zm->height_f - 0.0001f;

    *out_x = 0;
    *out_y = 0;

    int tile_x = func_00123350(fx);
    int tile_y = func_00123350(fy);

    float frac_x = fx - (float)tile_x;
    float frac_y = fy - (float)tile_y;

    ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[tile_y] + (tile_x * 8 - tile_x) * 4);

    float f22 = 0.0f;
    float f23 = 0.0f;

    unsigned char type = cell->f_4;
    switch (type) {
    case 0:
        f23 = 0.0f;
        break;
    case 1:
        if (frac_x + frac_y < 1.0f) {
            f23 = 1.0f - frac_x;
        } else {
            f23 = frac_y;
        }
        break;
    case 2:
        if (frac_x + frac_y < 1.0f) {
            f23 = 1.0f - frac_y;
        } else {
            f23 = frac_x;
        }
        f22 = 1.0f;
        break;
    case 3:
        if (frac_x <= frac_y) {
            f23 = 1.0f - frac_x;
        } else {
            f23 = 1.0f - frac_y;
        }
        f22 = 1.0f;
        break;
    case 4:
        if (frac_x <= frac_y) {
            f23 = frac_x;
        } else {
            f23 = frac_y;
        }
        break;
    case 5:
        f23 = frac_y;
        break;
    case 6:
        f23 = 1.0f - frac_x;
        f22 = 1.0f;
        break;
    case 7:
        f23 = 1.0f - frac_y;
        f22 = 1.0f;
        break;
    case 8:
        f23 = frac_x;
        break;
    case 9:
        f23 = (frac_x + frac_y) * 0.5f;
        break;
    case 10:
        f23 = 1.0f - (frac_x + frac_y) * 0.5f;
        f22 = 1.0f;
        break;
    case 11:
        f23 = (1.0f - frac_x + frac_y) * 0.5f;
        f22 = 0.5f;
        break;
    case 12:
        f23 = (1.0f - frac_y + frac_x) * 0.5f;
        f22 = 0.5f;
        break;
    case 13:
        if (frac_x + frac_y < 1.0f) {
            f23 = frac_y;
        } else {
            f23 = 1.0f - frac_x;
        }
        break;
    case 14:
        if (frac_x + frac_y < 1.0f) {
            f23 = frac_x;
        } else {
            f23 = 1.0f - frac_y;
        }
        f22 = 1.0f;
        break;
    case 15:
        if (frac_x <= frac_y) {
            f23 = frac_y;
        } else {
            f23 = frac_x;
        }
        f22 = 1.0f;
        break;
    case 16:
        if (frac_x <= frac_y) {
            f23 = 1.0f - frac_y;
        } else {
            f23 = 1.0f - frac_x;
        }
        f22 = 1.0f;
        break;
    default:
        break;
    }

    float elev = (float)cell->f_6 + f23;

    float screen_x_f = (float)zm->f_8EB4 * (frac_x + frac_y);
    *out_x = cell->f_0 + func_00123350(screen_x_f);

    float screen_y_f = (float)zm->f_8EB2 * ((1.0f + f22 + frac_y - frac_x + (float)cell->f_6) - elev);
    *out_y = cell->f_2 + func_00123350(screen_y_f);

    if (flag != 0) {
        *out_x -= D_004E3530;
        *out_y -= D_004E3534;
    }

    return 1;
}
