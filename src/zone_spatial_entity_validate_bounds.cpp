#pragma exceptions off

#include "zone_spatial_entity_validate_bounds.h"

struct SpatialEntity {
    char pad[0x10];
};

extern "C" int func_001DDBF0(SpatialEntity *self, float x, float y) {
    return 1;
}
