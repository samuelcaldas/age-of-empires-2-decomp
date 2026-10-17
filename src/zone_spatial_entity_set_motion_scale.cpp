#pragma exceptions off

#include "zone_spatial_entity_set_motion_scale.h"

struct SubEntity {
    char pad[0x1C];
    float f1C;
};

struct SpatialEntity {
    char pad[0xB4];
    SubEntity *fB4;
};

extern "C" void func_001E04D0(SpatialEntity *self, float val) {
    SubEntity *s = self->fB4;
    if (s != 0) {
        s->f1C = val;
    }
}
