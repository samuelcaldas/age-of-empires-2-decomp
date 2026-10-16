#pragma once
#pragma exceptions off

#include "zone_grid_getters.h"

struct ZoneCell;

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174 = -29044)
};

extern "C" {

void *func_001CB6A0(void *self) {
    ZoneLayout *zm = (ZoneLayout *)self;
    return zm->cells_ptr;
}

int func_001CB6B0(void *self) {
    ZoneLayout *zm = (ZoneLayout *)self;
    return zm->width;
}

int func_001CB6C0(void *self) {
    ZoneLayout *zm = (ZoneLayout *)self;
    return zm->height;
}

}
