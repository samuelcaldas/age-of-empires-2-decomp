#pragma exceptions off

#include "zone_spatial_entity_resolve_occupant.h"

struct SpatialEntity {
    char pad[0x10];
};

extern "C" int func_001DD990(SpatialEntity *self, float x, float y, void *out_node) {
    return 0;
}
