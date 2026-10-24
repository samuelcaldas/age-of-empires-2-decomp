#pragma exceptions off

#include "zone_spatial_entity_get_waypoint_entry.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad[0x88];
    Vector3 *items;
    short count;
};

extern "C" void *func_001DEB50(SpatialEntity *self, int index) {
    if (index >= 0 && index < self->count) {
        return &self->items[index];
    }
    return 0;
}
