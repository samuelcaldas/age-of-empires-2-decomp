#pragma exceptions off

#include "zone_spatial_entity_clear_velocity_threshold.h"

struct SpatialEntity {
    char pad[0x68];
    float f68;
};

extern "C" void func_001DCB20(SpatialEntity *self) {
    self->f68 = 0.0f;
}
