#pragma exceptions off

#include "zone_spatial_pyramid_update_rect.h"

extern "C" {
void func_1D2460(void *self, int level, int x, int y, void *p1, void *p2);
}

extern "C" void func_001D2320(void *self, int x0, int y0, int x1, int y1) {
    char *zm = (char *)self;
    if (x1 < x0) {
        int t = x0;
        x0 = x1;
        x1 = t;
    }
    if (y1 < y0) {
        int t = y0;
        y0 = y1;
        y1 = t;
    }

    x0--;
    y0--;
    x1++;
    y1++;

    if (x0 < 0) {
        x0 = 0;
    }
    if (y0 < 0) {
        y0 = 0;
    }

    int e4 = *(int *)(zm + 0xE4);
    if (x1 >= e4) {
        x1 = *(int *)(zm + 0xEC);
    }
    int e8 = *(int *)(zm + 0xE8);
    if (y1 >= e8) {
        y1 = *(int *)(zm + 0xF0);
    }

    *(int *)(zm + 0xF4) = x0;
    *(int *)(zm + 0xF8) = y0;
    *(int *)(zm + 0xFC) = x1;
    *(int *)(zm + 0x100) = y1;

    int s1 = y0 >> 3;
    int s2 = x1 >> 3;
    int s3 = y1 >> 3;
    int s4 = x0 >> 3;

    char stack_7e = 0;
    char stack_7f = 0;

    for (int x = s4; x <= s2; x++) {
        for (int y = s1; y <= s3; y++) {
            func_1D2460(self, 3, x, y, &stack_7e, &stack_7f);
        }
    }
}
