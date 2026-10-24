#pragma exceptions off

#include "zone_spatial_pyramid_alloc_grid.h"

extern "C" {
void *func_100730(int size);
}

extern "C" void func_001D4E70(void *self, int p1, int p2, int p3) {
    char *zm = (char *)self;
    int e4 = *(int *)(zm + 0xE4);
    int e8 = *(int *)(zm + 0xE8);

    void **rows = (void **)func_100730(e4 * 4);
    *(void ***)(zm + 0x11C) = rows;

    for (int i = 0; i < e4; i++) {
        rows[i] = func_100730(e8);
    }
}
