#pragma exceptions off

#include "zone_spatial_pyramid_build_graph.h"

extern "C" {
void *func_117CAC(void *dst, int val, int size);
}

extern "C" int func_001D5EB0(void *self, int p1) {
    char *zm = (char *)self;
    int e4 = *(int *)(zm + 0xE4);
    int e8 = *(int *)(zm + 0xE8);
    char **grid = *(char ***)(zm + 0x11C);

    if (grid != 0) {
        for (int i = 0; i < e4; i++) {
            func_117CAC(grid[i], 0, e8);
        }
    }

    return 1;
}
