#pragma exceptions off
#include "zone_spatial_grid_node_pool_setup.h"

struct NodePool {
    char pad_00[0x138810];
    void *table_138810;
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

extern "C" void func_001F1EE0(NodePool *self, void *p1, int count) {
    self->table_138810 = 0;
    self->table_138814 = 0;
    self->field_13881C = 1;
    self->count_138818 = 0;
    self->field_138820 = 0;
    self->field_138824 = -1;
    self->field_138828 = -1;
    self->field_13882C = 0;
    self->field_138830 = 0;
    self->capacity_138834 = count;

    func_118de0("%s(%d) make SonftOb_ArrayList.\n", "obmanager.cpp", 0x13D6);
    func_001F20E0(self, self->field_13881C);
    func_1F21E0(self, p1);
}
