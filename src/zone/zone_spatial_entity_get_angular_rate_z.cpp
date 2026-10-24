#pragma exceptions off

#include "zone_spatial_entity_get_angular_rate_z.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad[0xBC];
    Vector3 *vel_vec;
};

extern "C" float func_001DFF70(const SpatialEntity *self) {
    if (self->vel_vec != 0) {
        return self->vel_vec[1].z;
    }
    return 0.0f;
}
