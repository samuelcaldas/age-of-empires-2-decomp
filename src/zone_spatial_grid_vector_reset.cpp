#pragma exceptions off
#include "zone_spatial_grid_vector_reset.h"

extern "C" {
void func_1EBA20(void *self);
}

struct FastVector {
    void *buffer;
    short count;
    short cap;
    char flag;
};

extern "C" void func_001EB9D0(void *self_ptr) {
    FastVector *self = (FastVector *)self_ptr;
    if (self->buffer != 0) {
        func_1EBA20(self);
    }
    self->buffer = 0;
    self->cap = 0;
    self->count = 0;
    self->flag = 0;
}
