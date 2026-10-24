#pragma exceptions off
#include "zone_spatial_grid_reset.h"

struct SpatialItem;

struct ZoneSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    SpatialItem *field_0C;
    SpatialItem *field_10;
    void *field_14;
    int field_18;
    SpatialItem *field_1C;
};

extern "C" void func_001F2BD0(ZoneSpatialGrid *self) {
    if (self->field_0C != 0 && self->field_0C != self->field_10) {
        func_001F6CC0(self->field_10, self->field_0C);
    }
    self->field_0C = self->field_10;
}
