#pragma exceptions off
#include "zone_spatial_grid_node_pool_expand.h"

struct NodePool {
    char pad_00[0x10];
    char buffer_10[0x138800];
    void **table_138810;
    void *table_138814;
    int count_138818;
    int field_13881C;
    int field_138820;
    int field_138824;
    int field_138828;
    int field_13882C;
    int field_138830;
    int capacity_138834;
};

extern "C" void func_001F20E0(NodePool *self, int new_cap) {
    // Stub implementation to establish test harness
}
