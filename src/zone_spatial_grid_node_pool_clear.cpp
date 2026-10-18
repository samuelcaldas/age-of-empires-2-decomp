#pragma exceptions off
#include "zone_spatial_grid_node_pool_clear.h"

struct NodePool {
    char pad_00[0x8];
    char buffer_8[0x8];
    char pad_16[0x10];
    char buffer_10[0x88];
};

extern "C" void func_001F2020(NodePool *self) {
    func_117CAC(&self->buffer_8[0], 0, 8);
    func_117CAC(&self->buffer_10[0], 0, 0x88);
}
