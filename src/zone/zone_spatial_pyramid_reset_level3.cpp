#pragma exceptions off

#include "zone_spatial_pyramid_reset_level3.h"

extern "C" {
int func_001D21B0(void *self, int level, int x, int y);
}

struct ZonePyramidResetLayout {
    char pad_0[0xD0];
    int max_x; // 0xD0
    char pad_D4[0xC];
    int max_y; // 0xE0
};

extern "C" void func_001D2140(void *self) {
    ZonePyramidResetLayout *zm = (ZonePyramidResetLayout *)self;
    int s0 = zm->max_x;
    for (; s0 >= 0; s0--) {
        for (int s1 = zm->max_y; s1 >= 0; s1--) {
            func_001D21B0(self, 3, s0, s1);
        }
    }
}
