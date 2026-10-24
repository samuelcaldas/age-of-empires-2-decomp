#pragma exceptions off

#include "zone_spatial_entity_rebind_motion_target.h"

struct SpatialEntity {
    char pad[0x10];
};

extern "C" int func_001DFC60(SpatialEntity *self, void *p1, void *p2, float p3) {
    return 0;
}
