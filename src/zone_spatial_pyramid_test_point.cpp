#pragma exceptions off

#include "zone_spatial_pyramid_test_point.h"

extern "C" {
int func_1D5E50(void *self, int x, int y);
int func_1D5A30(void *self, int x, int y);
}

extern "C" int func_001D5B00(void *self, int x, int y, int flag) {
    char *zm = (char *)self;
    int min_x = *(int *)(zm + 0xF4);
    if (x < min_x) {
        return 0;
    }
    int max_x = *(int *)(zm + 0xFC);
    if (x > max_x) {
        return 0;
    }
    int min_y = *(int *)(zm + 0xF8);
    if (y < min_y) {
        return 0;
    }
    int max_y = *(int *)(zm + 0x100);
    if (y > max_y) {
        return 0;
    }

    if (func_1D5E50(self, x, y) == 0) {
        return 0;
    }

    if (func_1D5A30(self, x, y) != 0) {
        return 0;
    }

    return 1;
}
