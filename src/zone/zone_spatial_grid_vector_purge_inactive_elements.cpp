#pragma exceptions off
#include "zone_spatial_grid_vector_purge_inactive_elements.h"

extern "C" {
void func_367470(void *elem);
void func_194760();
}

struct FastVector {
    void **buffer;
    short count;
    short cap;
};

extern "C" void func_001EBFE0(void *self_ptr) {
    FastVector *self = (FastVector *)self_ptr;
    if (self == 0 || self->buffer == 0) {
        return;
    }
}
