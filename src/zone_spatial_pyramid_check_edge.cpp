#pragma exceptions off

#include "zone_spatial_pyramid_check_edge.h"

extern "C" int func_001D4440(void *self, void *node) {
    char *n = (char *)node;
    void *parent = *(void **)(n + 0x24);
    if (parent == 0) {
        return 0;
    }

    int n_lvl = *(int *)(n + 0xC);
    int p_lvl = *(int *)((char *)parent + 0xC);
    unsigned char dir = *(unsigned char *)(n + 0x28);

    if (p_lvl < n_lvl) {
        return 1;
    }

    return 0;
}
