#pragma exceptions off
#include "zone_spatial_grid_serialize_vector.h"

extern "C" {
int func_226F70(void *stream, void *src, int size);
}

struct FastVector {
    void **buffer;
    short count;
    short cap;
};

extern "C" void func_001EBE90(void *self_ptr, void *stream) {
    FastVector *self = (FastVector *)self_ptr;
    if (self == 0 || stream == 0) {
        return;
    }
}
