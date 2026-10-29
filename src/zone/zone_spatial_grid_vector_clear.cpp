#pragma exceptions off
#include "zone_spatial_grid_vector_clear.h"

extern "C" {
void func_367470(void *elem);
}

struct FastVector {
    void **buffer; // 0x0
    short count;   // 0x4
    short cap;     // 0x6
    char flag;     // 0x8
};

extern "C" void func_001EBA30(void *self_ptr) {
    FastVector *self = (FastVector *)self_ptr;
    self->flag = 1;
    for (int i = 0; i < (int)self->count; i++) {
        func_367470(self->buffer[i]);
        self->buffer[i] = 0;
    }
    self->count = 0;
    self->flag = 0;
}
