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
    if (new_cap >= self->field_13881C) {
        void **table0 = (void **)func_117CAC(self, 0, 8);
        void **table1 = (void **)func_117CAC((char *)self + 8, 0, 8);
        for (int i = 0; i < new_cap; ++i) {
            table0[i] = 0;
            table1[i] = 0;
        }
        if (self->table_138810 != 0) {
            func_118de0("!!!err!!!(%s,%d)Zone_Ptrs > PS2_MAX_ZONE_SIZE_M(=%d)\n", "obmanager.cpp", 0x145F, 10000);
        }
        self->table_138810 = table0;
        self->table_138814 = table1;
        self->field_13881C = new_cap;
    }
}
