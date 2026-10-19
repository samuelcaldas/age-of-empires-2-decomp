#pragma exceptions off
#include "zone_spatial_grid_getters.h"

struct ZoneSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
};

extern "C" int func_001F26C0(ZoneSpatialGrid *self) {
    return self->field_10;
}

extern "C" int func_001F26D0(ZoneSpatialGrid *self) {
    return self->field_04;
}

extern "C" int func_001F26E0(ZoneSpatialGrid *self) {
    return self->field_08;
}

extern "C" int func_001F26F0(ZoneSpatialGrid *self) {
    return self->field_0C;
}
