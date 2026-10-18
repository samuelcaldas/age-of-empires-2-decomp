#pragma exceptions off
#include "zone_spatial_grid_node_pool_clear.h"

struct NodePool {
    char pad_00[0x138800];
    int field_138800;
    int field_138804;
    int field_138808;
    int field_13880C;
    void **table_138810;
    void *table_138814;
    int count_138818;
    int flag_13881C;
    int field_138820;
    char pad_after[0x138834 - 0x138824];
    int capacity_138834;
};

extern "C" void func_001F2010(NodePool *self) {
    if (self->table_138810 != 0) {
        for (int i = 0; i < self->count_138818; ++i) {
            if (self->table_138810[i] != 0) {
                func_117CAC(&self->field_138810, 0, 8);
            }
        }
    }
    void *old_138814 = self->table_138814;
    func_117CAC(&self->table_138810, 0, 8);
    if (old_138814 != 0) {
        func_117CAC(&self->field_138808, 0, 8);
    }
}
