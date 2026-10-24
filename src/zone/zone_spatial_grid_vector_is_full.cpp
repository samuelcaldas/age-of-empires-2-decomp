#pragma exceptions off
#include "zone_spatial_grid_vector_is_full.h"

struct FastVector {
    void *buffer;
    short count;
    short cap;
    char flag;
};

extern "C" int func_001EBA10(void *self_ptr) {
    FastVector *self = (FastVector *)self_ptr;
    return self->count >= self->cap;
}
