#pragma exceptions off

#include "zone_spatial_entity_has_positive_threshold.h"

struct SpatialEntity {
    char pad[0x68];
    float f68;
};

extern "C" int func_001DCAF0(SpatialEntity *self) {
    if (self->f68 <= 0.0f) {
        return 0;
    }
    return 1;
}
