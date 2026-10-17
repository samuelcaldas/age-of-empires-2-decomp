#pragma exceptions off
#include "zone_spatial_grid_test_point_in_bounds.h"

struct SpatialGrid {
    char pad_BC[0xBC];
    float margin;
    float min_x;
    float max_x;
    float max_y;
};

extern "C" int func_001E7080(const SpatialGrid *self, float x, float y) {
    if (x < self->margin) {
        return 0;
    }
    if (x > self->max_x) {
        return 0;
    }
    if (y < self->min_x) {
        return 0;
    }
    if (y > self->max_y) {
        return 0;
    }
    return 1;
}
