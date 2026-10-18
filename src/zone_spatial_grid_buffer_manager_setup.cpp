#pragma exceptions off
#include "zone_spatial_grid_buffer_manager_setup.h"

struct SpatialGridBufferManager {
    void *buffer;
    char pad_04[0xAF0];
    short cap;
    short count;
};

extern "C" void func_001ECBE0(void *self_ptr, void *buffer) {
    SpatialGridBufferManager *self = (SpatialGridBufferManager *)self_ptr;
    self->cap = 0xC8;
    self->count = 0;
    self->buffer = buffer;
}
