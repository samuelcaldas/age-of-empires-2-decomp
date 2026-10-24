#pragma exceptions off
#include "zone_spatial_grid_deserialize_node_array.h"

extern "C" {
int func_226D90(void *stream, void *dst, int size);
void *func_1143F8(int count, int elem_size);
}

struct NodeArrayHeader {
    char pad_1C[0x1C];
    short count;
    char pad_20[0x2];
    void *buffer;
};

extern "C" void *func_001EB2C0(void *self_ptr, void *stream) {
    NodeArrayHeader *self = (NodeArrayHeader *)self_ptr;
    func_226D90(stream, self, 0x14);
    func_226D90(stream, &self->count, 2);
    return self;
}
