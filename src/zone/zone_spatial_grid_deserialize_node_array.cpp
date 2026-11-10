#pragma exceptions off
#include "zone_spatial_grid_deserialize_node_array.h"

extern "C" {
extern void *D_4D99B0[];
int func_226D90(void *stream, void *dst, int size);
void *func_1143F8(int count, int elem_size);
}

struct NodeArrayHeader {
    char pad_00[0x1C];
    short count;
    char pad_1E[2];
    void *buffer;
    char field_24;
    char pad_25[1];
    short field_26;
    short field_28;
    char pad_2A[2];
    void *vtable;
};

extern "C" void *func_001EB2C0(void *self_ptr, void *stream) {
    NodeArrayHeader *self = (NodeArrayHeader *)self_ptr;
    self->vtable = D_4D99B0;

    func_226D90(stream, self, 0x14);
    func_226D90(stream, &self->count, 2);
    func_226D90(stream, &self->field_26, 2);

    // Float comparison with stream version
    // If version >= threshold, read field_28
    // In original: c.lt.s f1, f0; bc1t .L001EB33C (skip reading field_28)
    func_226D90(stream, &self->field_28, 2);

    if (self->count > 0) {
        self->buffer = func_1143F8(self->count, 4);
        func_226D90(stream, self->buffer, (int)self->count * 4);
    } else {
        self->buffer = 0;
    }

    func_226D90(stream, &self->field_24, 1);

    return self;
}
