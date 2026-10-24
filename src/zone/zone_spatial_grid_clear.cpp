#pragma exceptions off
#include "zone_spatial_grid_clear.h"

struct ZoneSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    void *field_14;
    int field_18;
    int field_1C;
};

extern "C" void func_001F28A0(ZoneSpatialGrid *self, int val) {
    if (self->field_10 == val) {
        self->field_10 = 0;
    }
    if (self->field_04 == val) {
        self->field_04 = 0;
    }
    if (self->field_08 == val) {
        self->field_08 = 0;
    }
    if (self->field_0C == val) {
        self->field_0C = 0;
    }
    if (self->field_1C == val) {
        self->field_1C = 0;
    }
}
