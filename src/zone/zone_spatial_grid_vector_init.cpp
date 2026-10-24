#pragma exceptions off
#include "zone_spatial_grid_vector_init.h"

extern "C" {
void *func_1EB8D0(int cap);
void *func_117CAC(void *dst, int val, unsigned int size);
}

struct FastVector {
    void *buffer;
    short count;
    short cap;
    char flag;
};

extern "C" void func_001EB980(void *self_ptr, short cap) {
    FastVector *self = (FastVector *)self_ptr;
    self->cap = cap;
    self->buffer = func_1EB8D0(self->cap);
    func_117CAC(self->buffer, 0, (unsigned int)self->cap * 4);
    self->count = 0;
    self->flag = 0;
}
