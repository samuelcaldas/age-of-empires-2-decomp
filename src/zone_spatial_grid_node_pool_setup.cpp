#pragma exceptions off
#include "zone_spatial_grid_node_pool_setup.h"

struct NodePool {
    char pad_00[0x138810];
    int field_138810;
    int field_138814;
    int field_138818;
    int field_13881C;
    int field_138820;
    int field_138824;
    int field_138828;
    int field_13882C;
    int field_138830;
    int capacity_138834;
};

extern "C" int func_001F1EE0(NodePool *self, void *p1, int count) {
    self->field_138810 = 0;
    self->field_138814 = 0;
    self->field_138818 = 0;
    self->field_13881C = 1;
    self->field_138820 = 0;
    self->field_138824 = -1;
    self->field_138828 = -1;
    self->field_13882C = 0;
    self->field_138830 = 0;
    self->capacity_138834 = count;

    func_118DE0((int)(long)"%s(%d) make SonftOb_ArrayList.\n", (int)(long)"obmanager.cpp", 0x13D6);
    func_1F20E0(self, self->field_13881C);
    func_1F21E0(self, p1);
    return 1;
}

extern "C" int func_001F1ED0(NodePool *self, void *p1, int count) {
    return func_001F1EE0(self, p1, count);
}
