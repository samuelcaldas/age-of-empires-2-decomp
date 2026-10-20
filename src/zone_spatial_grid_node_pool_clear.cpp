#pragma exceptions off
#include "zone_spatial_grid_node_pool_clear.h"

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

extern "C" void func_001F2020(NodePool *self) {
    if (self->table_138810 != 0) {
        for (int i = 0; i < self->count_138818; ++i) {
            if (self->table_138810[i] != 0) {
                func_117CAC(self->buffer_10, 0, 0x138800);
            }
        }
        func_117CAC(self, 0, 8);
    }
    if (self->table_138814 != 0) {
        func_117CAC((char *)self + 8, 0, 8);
    }
}

extern "C" void func_001F2010(NodePool *self) {
    func_001F2020(self);
}
