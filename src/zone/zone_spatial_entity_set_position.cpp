#pragma exceptions off

#include "zone_spatial_entity_set_position.h"

struct SpatialEntity {
    char pad[0x70];
    float x;
    float y;
    float z;
};

extern "C" void func_001DC180(SpatialEntity *self, int a1, int a2, float x, float y, float z) {
    self->x = x;
    self->y = y;
    self->z = z;
}
