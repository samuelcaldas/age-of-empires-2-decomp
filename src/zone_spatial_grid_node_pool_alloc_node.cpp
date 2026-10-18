#pragma exceptions off
#include "zone_spatial_grid_node_pool_alloc_node.h"

struct NodePool {
    char pad_00[0x10];
    char buffer_10[0x138800];
    void **table_138810;
    void **table_138814;
    int count_138818;
    int field_13881C;
    void *field_138820;
    int field_138824;
    int field_138828;
    int field_13882C;
    int field_138830;
    int capacity_138834;
};

extern "C" void *func_001F2320(NodePool *self) {
    // Stub implementation to establish test harness
    return 0;
}
