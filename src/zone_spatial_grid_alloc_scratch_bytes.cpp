#pragma exceptions off
#include "zone_spatial_grid_alloc_scratch_bytes.h"

extern "C" {
extern int D_008B0AD0;
extern int D_0093EBF0[];
}

extern "C" void *func_001EB8E0(int count) {
    int old = D_008B0AD0;
    D_008B0AD0 = old + count;
    return &D_0093EBF0[old];
}
