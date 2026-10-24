#pragma exceptions off

#include "zone_spatial_entity_get_state_id.h"

struct SpatialEntity {
    char pad[0x24];
    short f24;
};

extern "C" short func_001E04F0(const SpatialEntity *self) {
    return self->f24;
}
