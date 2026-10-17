#pragma exceptions off

#include "zone_spatial_entity_get_vertical_velocity.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad[0xBC];
    Vector3 *vel_vec;
};

extern "C" float func_001DFEE0(const SpatialEntity *self) {
    if (self->vel_vec != 0) {
        return self->vel_vec->z;
    }
    return 0.0f;
}
