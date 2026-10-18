#pragma exceptions off
#include "zone_spatial_grid_vector_update_elements.h"

struct FastVector {
    void **buffer;
    short count;
    short cap;
};

extern "C" void func_001EBF70(void *self_ptr) {
    FastVector *self = (FastVector *)self_ptr;
    if (self == 0 || self->buffer == 0) {
        return;
    }
}
