#pragma exceptions off
#include "zone_spatial_grid_node_pool_setup.h"

struct NodePool {
    char pad_00[0x138800];
    int field_138800;
    int field_138804;
    int field_138808;
    int field_13880C;
    int field_138810;
    int field_138814;
    int field_138818;
    int field_13881C;
    int field_138820;
    int field_138824;
};

extern "C" int func_001F1EE0(NodePool *self, void *p1, int count) {
    self->field_138810 = 0;
    self->field_138814 = 0;
    self->field_138808 = 1;
    self->field_138818 = 0;
    self->field_138820 = 0;
    self->field_138824 = -1;
    self->field_13881C = -1;
    self->field_138800 = 0;
    self->field_138804 = 0;
    self->field_13880C = count;

    func_118DE0(0x13D6); // allocation call (return discarded)
    func_1F20E0(self);
    func_1F21E0(self);
    return 1;
}
