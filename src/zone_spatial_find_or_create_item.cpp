#pragma exceptions off

#include "zone_spatial_find_or_create_item.h"

extern "C" {
void *func_1D7BF0(void *self, void *item, int flag);
void *func_100850(unsigned int size);
void *func_117AF8(void *dst, const void *src, unsigned int size);
void *func_1D1D70(void *node, void *f8, void *item, int flag);
void func_1EE700(void *mgr, void *callback, void *self);
void func_1D7E70(void *arg);
extern void *D_004E3244;
}

struct SpatialNodeManager {
    void **items;
    int count;
    void *field_8;
};

extern "C" void func_001D7CE0(SpatialNodeManager *self, void *item, int flag) {
    if (func_1D7BF0(self, item, flag)) {
        return;
    }

    self->count++;
    void **new_items = (void **)new void*[self->count];
    if (self->items != 0) {
        func_117AF8(new_items, self->items, self->count * 4);
        delete[] self->items;
    }

    void *node;
    if ((node = func_100850(0x124)) != 0) {
        func_1D1D70(node, self->field_8, item, flag);
    }

    new_items[self->count - 1] = node;
    self->items = new_items;
    func_1EE700(D_004E3244, (void *)func_1D7E70, self);
}
