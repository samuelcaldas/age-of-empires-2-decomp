#pragma exceptions off

#include "zone_spatial_tree_append_child.h"

struct SpatialTreeNode {
    void *buffer;
    SpatialTreeNode *child;
};

extern "C" void func_001D8120(SpatialTreeNode *self, SpatialTreeNode *child) {
    if (self->child == 0) {
        self->child = child;
        return;
    }
    func_001D8120(self->child, child);
}
