#pragma exceptions off
#include "zone_spatial_grid_reset_query_state.h"

struct SpatialGridState {
    char pad_00[0x12B574];
    int field_12B574;
    char pad_12B578[0x12B5B0 - 0x12B574 - 4];
    int field_12B5B0;
};

extern "C" void func_001ED160(SpatialGridState *self) {
    self->field_12B5B0 = -2;
    func_1ED1F0(self);
    self->field_12B574 = -1;
}
