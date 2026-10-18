#pragma exceptions off
#include "zone_spatial_grid_vector_clear.h"

extern "C" {
void func_367470(void *elem);
}

struct FastVector {
    void **buffer;
    short count;
    short cap;
    char flag;
};

extern "C" void func_001EBA30(void *self_ptr) {
    FastVector *self = (FastVector *)self_ptr;
    self->flag = 1;
    for (short i = 0; i < self->count; i++) {
        func_367470(self->buffer[i]);
        self->buffer[i] = 0;
    }
    self->count = 0;
    self->flag = 0;
}
