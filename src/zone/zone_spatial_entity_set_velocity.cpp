#pragma exceptions off

#include "zone_spatial_entity_set_velocity.h"

struct SpatialEntity {
    char pad[0x70];
    float f70;
    float f74;
    float f78;
};

extern "C" void func_001DD6E0(SpatialEntity *self, float vx, float vy, float vz) {
    self->f70 = vx;
    self->f74 = vy;
    self->f78 = vz;
}
