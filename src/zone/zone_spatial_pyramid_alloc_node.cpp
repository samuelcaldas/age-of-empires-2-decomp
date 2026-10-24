#pragma exceptions off

#include "zone_spatial_pyramid_alloc_node.h"

extern "C" {
void *func_100850(int size);
}

extern "C" void *func_001D4330(
    void *self, int x, int y, int level, float g_score, float h_score,
    void *parent, int dir, void *t2, void *t3
) {
    char *zm = (char *)self;
    void *node = *(void **)(zm + 0x80);

    if (node != 0) {
        *(void **)(zm + 0x80) = *(void **)((char *)node + 0x20);
    } else {
        node = func_100850(0x2C);
    }

    char *n = (char *)node;
    *(int *)(n + 0x4) = x;
    *(int *)(n + 0x8) = y;
    *(int *)(n + 0xC) = level;
    *(float *)(n + 0x1C) = g_score;
    *(float *)(n + 0x18) = g_score + h_score;
    *(void **)(n + 0x24) = parent;
    *(char *)(n + 0x28) = (char)dir;

    void ***root = *(void ****)(zm + 0x0);
    void *cell = (char *)root[level][x] + y * 2;
    *(void **)(n + 0x0) = cell;

    *(void **)(n + 0x10) = t2;
    *(void **)(n + 0x14) = t3;
    *(void **)(n + 0x20) = 0;

    return node;
}
