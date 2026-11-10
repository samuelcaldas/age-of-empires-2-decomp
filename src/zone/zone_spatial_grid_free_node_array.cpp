#pragma exceptions off
#include "zone_spatial_grid_free_node_array.h"

extern "C" {
extern void *D_4D99B0[];
void func_116F68(void *ptr);
void func_100670(void *ptr);
}

struct NodeArrayHeader {
    char pad_00[0x14];
    short field_14;
    char pad_16[2];
    int field_18;
    short count;
    char pad_1E[2];
    void *buffer;
    char pad_24[8];
    void *vtable;
};

extern "C" void *func_001EB3B0(void *self_ptr, short flag) {
    if (self_ptr != 0) {
        NodeArrayHeader *self = (NodeArrayHeader *)self_ptr;
        self->vtable = D_4D99B0;
        if (self->count > 0) {
            if (self->buffer != 0) {
                func_116F68(self->buffer);
                self->buffer = 0;
                self->count = 0;
            }
        }
        self->field_18 = 0;
        self->field_14 = 0;
        if (flag > 0) {
            func_100670(self_ptr);
        }
    }
    return self_ptr;
}
