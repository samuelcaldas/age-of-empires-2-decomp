#pragma exceptions off

#include "zone_spatial_entity_has_positive_velocity.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad[0xBC];
    Vector3 *vel_vec;
};

extern "C" int func_001E0280(const SpatialEntity *self) {
    Vector3 *v;
    if ((v = self->vel_vec) != 0) {
        float sq = v->y * v->y + v->x * v->x + v->z * v->z;
        if (sq > 0.0f) {
            return 1;
        }
    }
    return 0;
}
