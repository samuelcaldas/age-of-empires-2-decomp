#pragma exceptions off

#include "zone_spatial_entity_resolve_wrapper.h"

struct SpatialEntity {
    char pad[0x38];
    unsigned char f38;
    char pad2[0x130 - 0x39];
    void *sub_obj;
};

extern "C" void *func_001DBE50(SpatialEntity *self) {
    if (self == 0) {
        return self;
    }
    if (self->f38 == 0x50) {
        if (self->sub_obj != 0) {
            return self->sub_obj;
        }
    }
    return self;
}
