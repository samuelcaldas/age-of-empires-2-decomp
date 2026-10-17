#pragma exceptions off

#include "zone_spatial_entity_get_angular_velocity.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad[0xBC];
    Vector3 *vel_vec;
};

extern "C" Vector3 *func_001DFE00(Vector3 *out, const SpatialEntity *ent) {
    Vector3 *v;
    if ((v = ent->vel_vec) != 0) {
        out->x = v[1].x;
        out->y = v[1].y;
        out->z = v[1].z;
    } else {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
    }
    return out;
}
