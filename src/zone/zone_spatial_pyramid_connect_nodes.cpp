#pragma exceptions off

#include "zone_spatial_pyramid_connect_nodes.h"

extern "C" int func_001D48B0(void *self, void *node, void *p2, void *p3) {
    char *n = (char *)node;
    void *parent = *(void **)(n + 0x24);
    if (parent == 0) {
        return 0;
    }

    int n_lvl = *(int *)(n + 0xC);
    int p_lvl = *(int *)((char *)parent + 0xC);

    if (p_lvl < n_lvl) {
        return 1;
    }

    return 0;
}
