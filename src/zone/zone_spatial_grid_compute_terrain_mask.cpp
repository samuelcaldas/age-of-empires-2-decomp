#pragma exceptions off
#include "zone_spatial_grid_compute_terrain_mask.h"

extern "C" {
extern unsigned char D_00392070[];
}

#ifndef __MWERKS__
unsigned char D_00392070[32] = { 1, 2, 4, 8 };
#endif

extern "C" int func_001EE550(void *unused, float *weights) {
    int mask = 0;
    for (int i = 0; i < 32; ++i) {
        if (weights[i] > 0.0f) {
            mask |= D_00392070[i];
        }
    }
    return mask;
}
