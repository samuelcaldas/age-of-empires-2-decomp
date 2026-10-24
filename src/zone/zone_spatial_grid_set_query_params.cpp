#pragma exceptions off
#include "zone_spatial_grid_set_query_params.h"

struct SpatialGrid {
    char pad_00[0x12B590];
    int param1;
    int param2;
    int param3;
};

extern "C" void func_001EE8D0(SpatialGrid *self, int p1, int p2, int p3) {
    self->param1 = p1;
    self->param2 = p2;
    self->param3 = p3;
}
