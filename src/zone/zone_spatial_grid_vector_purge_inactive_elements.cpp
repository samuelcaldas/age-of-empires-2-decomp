#pragma exceptions off
#include "zone_spatial_grid_vector_purge_inactive_elements.h"

extern "C" {
void func_367470(void *elem);
void func_00194760(void *param);
extern void *D_004E3108;
}

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
    virtual int is_active(); // 0x30 in MWCC PS2
};

struct FastVector {
    VectorItem **buffer;
    short count;
    short cap;
};

extern "C" {
void func_001EBFE0(void *self_ptr) {
    int s0;
    int s1;
    FastVector *self;
    self = (FastVector *)self_ptr;
    s1 = 0;
    s0 = 0;
    while (s0 < self->count) {
        VectorItem *item = self->buffer[s0];
        if (item->is_active()) {
            func_367470(item);
            s0--;
        }
        s1++;
        if (s1 <= 90) {
            goto next;
        }
        {
            void *param = D_004E3108;
            s1 = 0;
            if (param != 0) {
                func_00194760(param);
            }
        }
    next:
        s0++;
    }
}
}
