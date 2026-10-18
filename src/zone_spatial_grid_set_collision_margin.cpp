#pragma exceptions off
#include "zone_spatial_grid_set_collision_margin.h"

struct SpatialGrid {
    char pad_00[0x12B59E];
    unsigned char has_margin;
    char pad_align;
    float margin;
};

extern "C" void func_001EE900(SpatialGrid *self, int flag, float margin) {
    self->has_margin = (unsigned char)flag;
    self->margin = margin;
}
