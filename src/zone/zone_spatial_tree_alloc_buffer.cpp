#pragma exceptions off

#include "zone_spatial_tree_alloc_buffer.h"

extern "C" void *func_100730(unsigned int size);

struct SpatialBufferHolder {
    void *buffer;
};

extern "C" int func_001D80D0(SpatialBufferHolder *self, unsigned int w, unsigned int h) {
    self->buffer = new void*[w * h];
    return 1;
}
