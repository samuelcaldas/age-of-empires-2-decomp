#pragma exceptions off

#include "zone_spatial_pyramid_check_rect.h"

extern "C" {
int func_1D3440(void *self, int level, int x, int y, void *p1, void *p2);
}

extern "C" int func_001D3310(void *self, int x0, int y0, int x1, int y1, void *p1, void *p2) {
    char *zm = (char *)self;
    if (x1 < x0) {
        int t = x0; x0 = x1; x1 = t;
    }
    if (y1 < y0) {
        int t = y0; y0 = y1; y1 = t;
    }

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;

    int max_x = *(int *)(zm + 0xE4);
    if (x1 >= max_x) x1 = max_x - 1;
    int max_y = *(int *)(zm + 0xE8);
    if (y1 >= max_y) y1 = max_y - 1;

    int s4 = x0 >> 3;
    int s2 = x1 >> 3;
    int s5 = y0 >> 3;
    int s3 = y1 >> 3;

    for (int x = s4; x <= s2; x++) {
        for (int y = s5; y <= s3; y++) {
            if (func_1D3440(self, 3, x, y, p1, p2) != 0) {
                return 1;
            }
        }
    }

    return 0;
}
