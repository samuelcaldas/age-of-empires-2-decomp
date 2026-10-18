#pragma exceptions off
#include "zone_spatial_grid_node_pool_setup.h"

struct NodePool {
    char pad_00[0x138800];
    int field_138800;
    int field_138804;
    int field_138808;
    int field_13880C;
    void *table_138810;
    void *table_138814;
    int count_138818;
    int flag_13881C;
    int field_138820;
    char pad_after[0x138834 - 0x138824];
    int capacity_138834;
};

extern "C" int func_001F1ED0(NodePool *self, void *p1, int count) {
    self->table_138810 = 0;
    self->table_138814 = 0;
    self->flag_13881C = 1;
    self->count_138818 = 0;
    self->field_138820 = 0;
    self->capacity_138834 = count;

    func_118DE0((int)(long)"obmanager.cpp");
    func_1F20E0(self);
    func_1F21E0(self);
    return 1;
}
