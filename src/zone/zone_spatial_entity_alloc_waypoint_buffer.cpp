#pragma exceptions off

#include "zone_spatial_entity_alloc_waypoint_buffer.h"

struct SpatialEntity {
    char pad[0x10];
};

extern "C" int func_001DEDC0(SpatialEntity *self, int count) {
    return 0;
}
