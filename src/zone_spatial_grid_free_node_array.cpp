#pragma exceptions off
#include "zone_spatial_grid_free_node_array.h"

extern "C" {
void func_116F68(void *ptr);
void func_100670(void *ptr);
}

struct NodeArrayHeader {
    char pad_1C[0x1C];
    short count;
    char pad_20[0x2];
    void *buffer;
};

extern "C" void *func_001EB3B0(void *self_ptr, int flag) {
    NodeArrayHeader *self = (NodeArrayHeader *)self_ptr;
    if (self == 0) {
        return 0;
    }
    if (self->buffer != 0) {
        func_116F68(self->buffer);
        self->buffer = 0;
    }
    if (flag > 0) {
        func_100670(self);
    }
    return self;
}
