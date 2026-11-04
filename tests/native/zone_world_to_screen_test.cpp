#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_world_to_screen.h"

struct ZoneCell {
    short f_0;              // 0x0
    short f_2;              // 0x2
    unsigned char f_4;      // 0x4 (slope type)
    unsigned char f_5;      // 0x5
    char f_6;               // 0x6
    char pad_7[21];         // 28 bytes total
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C
    char pad_8E90[8];       // 0x8E90..0x8E97
    float width_f;          // 0x8E98
    float height_f;         // 0x8E9C
    char pad_8EA0[0x12];    // 0x8EA0..0x8EB1
    short f_8EB2;           // 0x8EB2
    short f_8EB4;           // 0x8EB4
    short f_8EB6;           // 0x8EB6
};

extern "C" {
int D_004E3530 = 100;
int D_004E3534 = 50;

int func_00123350(float val) {
    return (int)val;
}
}

int main() {
    ZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 10;
    zm.height = 10;
    zm.width_f = 10.0f;
    zm.height_f = 10.0f;
    zm.f_8EB4 = 32; // tile half width
    zm.f_8EB2 = 16; // tile half height

    ZoneCell cell;
    std::memset(&cell, 0, sizeof(cell));
    cell.f_0 = 500; // cell base screen X
    cell.f_2 = 300; // cell base screen Y
    cell.f_4 = 0;   // flat type
    cell.f_6 = 0;   // elevation

    ZoneCell *row0[1] = {&cell};
    zm.cells_ptr = row0;

    int out_x = 0;
    int out_y = 0;

    // Test flat type (0) with flag == 0
    int res = func_001CAFB0(&zm, &out_x, &out_y, 0, 0.5f, 0.5f);
    assert(res == 1);
    // screen_x_f = 32 * (0.5 + 0.5) = 32 -> out_x = 500 + 32 = 532
    assert(out_x == 532);
    // screen_y_f = 16 * ((1.0 + 0 + 0.5 - 0.5 + 0) - 0) = 16 * 1.0 = 16 -> out_y = 300 + 16 = 316
    assert(out_y == 316);

    // Test with flag == 1 (applies D_004E3530 / D_004E3534 offset)
    res = func_001CAFB0(&zm, &out_x, &out_y, 1, 0.5f, 0.5f);
    assert(res == 1);
    assert(out_x == 532 - 100);
    assert(out_y == 316 - 50);

    // Test clamped boundary values
    res = func_001CAFB0(&zm, &out_x, &out_y, 0, -10.0f, -10.0f);
    assert(res == 1);
    assert(out_x == 500);
    assert(out_y == 316);

    return 0;
}
