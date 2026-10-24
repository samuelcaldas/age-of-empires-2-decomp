#pragma exceptions off
#include "zone_spatial_grid_deserialize_child_entries.h"

extern "C" {
int func_226D90(void *stream, void *dst, int size);
void *func_36C3F0(int size);
}

struct ChildContainer {
    char pad_14[0x14];
    short count;
    char pad_18[0x2];
    void **items;
};

extern "C" void func_001EB440(void *self_ptr, void *stream, void *p2, void *p3) {
    ChildContainer *self = (ChildContainer *)self_ptr;
    func_226D90(stream, &self->count, 2);
    if (self->count <= 0) {
        self->items = 0;
        return;
    }
}
