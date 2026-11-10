#pragma exceptions off
#include "zone_spatial_grid_deserialize_child_entries.h"

extern "C" {
int func_226D90(void *stream, void *dst, int size);
void *func_36C3F0(int size);
}

class ChildCallback {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void Method10(void *stream, unsigned char flag, void *p2, void *p3, int idx); // offset 0x10
};

struct ChildContainer {
    char pad_00[0x14];
    short count;          // 0x14
    char pad_16[2];
    void **items;         // 0x18
    char pad_1C[0x10];    // 0x1C to 0x2C
    ChildCallback *cb;    // 0x2C
};

extern "C" void func_001EB440(void *self_ptr, void *stream, void *p2, void *p3) {
    ChildContainer *self = (ChildContainer *)self_ptr;
    func_226D90(stream, &self->count, 2);

    if (self->count <= 0) {
        self->items = 0;
        return;
    }

    self->items = (void **)func_36C3F0((int)self->count * 4);
    func_226D90(stream, self->items, (int)self->count * 4);

    for (int i = 0; i < (int)self->count; ++i) {
        if (self->items[i] != 0) {
            unsigned char flag = 0;
            func_226D90(stream, &flag, 1);
            if (self->cb != 0) {
                self->cb->Method10(stream, flag, p2, p3, i);
            }
        }
    }
}
