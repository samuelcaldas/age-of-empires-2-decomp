#pragma exceptions off
#include "zone_spatial_grid_set_obstacle_callback.h"

struct SpatialGrid {
    char pad_00[0x12B5A4];
    void *callback_fn;
    void *callback_ctx;
};

extern "C" void func_001EE710(SpatialGrid *self, void *cb, void *ctx) {
    self->callback_fn = cb;
    self->callback_ctx = ctx;
}
