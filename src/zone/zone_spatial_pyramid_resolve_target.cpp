#pragma exceptions off

#include "zone_spatial_pyramid_resolve_target.h"

extern "C" void func_001D4C20(void *self, void *node, int *out_x, int *out_y, int tx, int ty) {
    char *n = (char *)node;
    int lvl = *(int *)(n + 0xC);

    if (lvl == 0) {
        *out_x = *(int *)(n + 0x4);
        *out_y = *(int *)(n + 0x8);
        return;
    }

    *out_x = *(int *)(n + 0x4) << lvl;
    *out_y = *(int *)(n + 0x8) << lvl;
}
