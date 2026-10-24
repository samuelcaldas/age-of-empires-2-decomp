#pragma exceptions off
#include "zone_spatial_grid_set_field10.h"

struct SpatialGrid {
    char pad_10[0x10];
    void *val_10;
};

extern "C" void func_001E7100(SpatialGrid *self, void *val) {
    self->val_10 = val;
}
