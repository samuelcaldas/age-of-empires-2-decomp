#pragma exceptions off
#include "zone_spatial_grid_vector_push_back.h"

extern "C" {
int func_1EBA00(void *self);
}

struct FastVector {
    void **buffer;
    short count;
    short cap;
    char flag;
};

extern "C" int func_001EBAB0(void *self_ptr, void *elem) {
    FastVector *self = (FastVector *)self_ptr;
    if (func_1EBA00(self) == 0) {
        return -1;
    }
    short idx = self->count;
    self->buffer[idx] = elem;
    self->count++;
    return self->count - 1;
}
