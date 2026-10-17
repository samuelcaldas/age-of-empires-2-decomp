#pragma exceptions off

#include "zone_spatial_tree_manager_dtor.h"

extern "C" {
void func_100630(void *ptr);
void *func_1D8070(void *self, int flag);
void func_100670(void *ptr);
}

struct SpatialTreeManager {
    void *root;
    char pad[0x10];
    void *buffer;
};

extern "C" void *func_001D8160(SpatialTreeManager *self, int flag) {
    if (self) {
        func_100630(self->buffer);
        func_1D8070(self->root, 1);
        if ((short)flag > 0) func_100670(self);
    }
    return self;
}
