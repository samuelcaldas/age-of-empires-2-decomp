#pragma exceptions off

#include "zone_spatial_grid_init_sub_container.h"

struct SpatialGrid {
    char pad[0x10];
};

extern "C" void *func_001E61E0(SpatialGrid *self) {
    return self;
}
