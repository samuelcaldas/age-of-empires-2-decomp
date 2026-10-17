#pragma exceptions off
#include "zone_spatial_grid_reset_bounding_indices.h"

struct SpatialGrid {
    char pad_A4[0xA4];
    int min_x;
    int min_y;
    int max_x;
    int max_y;
};

extern "C" void func_001E9140(SpatialGrid *self) {
    self->min_x = -1;
    self->min_y = -1;
    self->max_x = -1;
    self->max_y = -1;
}
