#pragma exceptions off
#include "zone_spatial_grid_buffer_manager_insert.h"

struct Element {
    char pad_08[0x8];
    char pad_BA0[0xB98];
    int team;
};

struct SpatialGridBufferManager {
    Element *owner;
    Element *items[700];
    short cap;
    short count;
};

extern "C" int func_001ECC00(void *self_ptr, void *elem_ptr) {
    SpatialGridBufferManager *self = (SpatialGridBufferManager *)self_ptr;
    Element *elem = (Element *)elem_ptr;
    if (self->count >= self->cap) {
        return 0;
    }
    if (elem->team != self->owner->team) {
        return 0;
    }
    return 1;
}
