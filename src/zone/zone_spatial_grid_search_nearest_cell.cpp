#pragma exceptions off
#include "zone_spatial_grid_search_nearest_cell.h"

extern "C" int func_001EC090(void *p0, void *p1, void *p2, char flag_a3, void *t0, void *t1, float fx, float fy) {
    if (fx <= -1.0f || fy <= -1.0f) {
        return -1;
    }
    return 0;
}
