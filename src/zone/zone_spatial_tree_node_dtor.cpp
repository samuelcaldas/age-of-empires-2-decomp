#pragma exceptions off

#include "zone_spatial_tree_node_dtor.h"

extern "C" {
void func_100630(void *ptr);
void func_100670(void *ptr);
}

struct SpatialTreeNode {
    void *buffer;
    SpatialTreeNode *child;
};

extern "C" void *func_001D8070(SpatialTreeNode *self, int flag) {
    if (self) {
        func_100630(self->buffer);
        func_001D8070(self->child, 1);
        if ((short)flag > 0) func_100670(self);
    }
    return self;
}
