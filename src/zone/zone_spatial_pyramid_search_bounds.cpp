#pragma exceptions off

#include "zone_spatial_pyramid_search_bounds.h"

extern "C" {
int func_1D40E0(void *self, int level, int x, int y, float *f1, float *f2);
}

extern "C" int func_001D3EB0(
    void *self, int level, int x, int y, float f12, float f13, float f14, float f15,
    void *out1
) {
    char *zm = (char *)self;
    int x0 = *(int *)(zm + 0xF4) >> level;
    if (x < x0) {
        return 0;
    }
    int y0 = *(int *)(zm + 0xF8) >> level;
    if (y < y0) {
        return 0;
    }
    int x1 = *(int *)(zm + 0xFC) >> level;
    if (x > x1) {
        return 0;
    }
    int y1 = *(int *)(zm + 0x100) >> level;
    if (y > y1) {
        return 0;
    }

    return 1;
}
