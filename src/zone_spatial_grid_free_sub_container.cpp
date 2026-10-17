#pragma exceptions off

#include "zone_spatial_grid_free_sub_container.h"

struct SpatialGrid {
    char pad[0x10];
};

extern "C" void *func_001E6230(SpatialGrid *self, short flag) {
    return self;
}
