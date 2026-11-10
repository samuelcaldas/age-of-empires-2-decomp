#pragma exceptions off
#include "zone_spatial_grid_vector_update_elements.h"

class VectorItem {
public:
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void update(); // 0x38 in MWCC PS2
};

struct FastVector {
    VectorItem **buffer;
    short count;
    short cap;
};

extern "C" {
void func_001EBF70(void *self_ptr) {
    int i = 0;
    FastVector *self = (FastVector *)self_ptr;
    while (i < self->count) {
        self->buffer[i]->update();
        i++;
    }
}
}
