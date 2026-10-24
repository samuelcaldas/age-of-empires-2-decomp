#pragma exceptions off
#include "zone_spatial_grid_setters.h"

struct ZoneSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
};

extern "C" void func_001F2AB0(ZoneSpatialGrid *self, int val) {
    self->field_04 = val;
}

extern "C" void func_001F2AC0(ZoneSpatialGrid *self, int val) {
    self->field_08 = val;
}
