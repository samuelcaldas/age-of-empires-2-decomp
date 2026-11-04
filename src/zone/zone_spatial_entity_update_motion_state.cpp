#pragma exceptions off

#include "zone_spatial_entity_update_motion_state.h"

extern "C" {
void func_1002A0(void *ptr, void *fn);
}

struct SpatialEntity {
    char pad[0x88];
    void *field_88;
    short field_8c;
    short field_8e;
};

extern "C" void func_001DED70(SpatialEntity *self) {
    if (self->field_88 != 0) {
        func_1002A0(self->field_88, 0);
        self->field_88 = 0;
    }
    self->field_8c = 0;
    self->field_8e = 0;
}
