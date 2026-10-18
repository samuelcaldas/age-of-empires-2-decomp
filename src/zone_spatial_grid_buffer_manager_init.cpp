#pragma exceptions off
#include "zone_spatial_grid_buffer_manager_init.h"

struct SpatialGridBufferManager {
    void *buffer;
    char pad_04[0xAF0];
    short cap;
    short count;
};

extern "C" void *func_001ECB70(void *self_ptr) {
    SpatialGridBufferManager *self = (SpatialGridBufferManager *)self_ptr;
    self->count = 0;
    self->cap = 0;
    self->buffer = 0;
    return self;
}
