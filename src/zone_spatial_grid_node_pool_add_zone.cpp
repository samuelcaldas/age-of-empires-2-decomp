#pragma exceptions off
#include "zone_spatial_grid_node_pool_add_zone.h"

struct NodePool {
    char pad_00[0x10];
    char buffer_10[0x138800];
    void **table_138810;
    void **table_138814;
    int count_138818;
    int field_13881C;
    int field_138820;
    int field_138824;
    int field_138828;
    int field_13882C;
    int field_138830;
    int capacity_138834;
};

extern "C" void func_001F21E0(NodePool *self, int num_items) {
    if (self->count_138818 == self->field_13881C) {
        func_118de0("%s(%d) Used_Zones == Max_Zones(%d)\n", "obmanager.cpp", 0x1481, self->field_13881C);
    }
    int idx = self->count_138818;
    self->count_138818 = idx + 1;
    self->table_138814[idx] = (void *)num_items;
    void *buf = func_117CAC(self->buffer_10, 0, 0x138800);
    self->table_138810[idx] = (void **)buf;
    self->field_13882C += num_items;
    self->field_138830 += num_items;
    if (self->field_138824 == -1) {
        self->field_138824 = idx;
        self->field_138828 = 0;
    }
}
