#pragma exceptions off
#include "zone_spatial_grid_find_nearest_quad_intersection.h"

extern "C" {
int func_1E5010(void *p1, void *p2, void *p3, void *p4);
}

struct Point2D {
    float x;
    float y;
};

struct SpatialGrid {
    char pad_04[0x4];
    int count;
    char pad_0C[0x4];
    void **nodes;
};

extern "C" int func_001E8BB0(SpatialGrid *self, void *p1, void *origin, void *target, void *out_hit, int *out_node_idx, int *out_val) {
    if (self == 0 || origin == 0 || target == 0) {
        return 0;
    }
    return 0;
}
