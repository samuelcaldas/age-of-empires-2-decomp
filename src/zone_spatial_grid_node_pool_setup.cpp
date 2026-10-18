#pragma exceptions off
#include "zone_spatial_grid_node_pool_setup.h"

struct NodePool {
    char pad_00[0x10];
    int capacity;
    int count;
    void *nodes;
};

extern "C" int func_001F1EE0(NodePool *self, int count) {
    self->capacity = count;
    self->count = 0;
    self->nodes = func_118DE0(count * 32);
    func_1F20E0(self);
    func_1F21E0(self);
    return 1;
}
