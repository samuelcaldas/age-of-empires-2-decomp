#pragma exceptions off
#include "zone_spatial_grid_node_pool_clear.h"

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

extern "C" void func_001F2020(NodePool *self) {
    if (self->field_138810 != 0) {
        for (int i = 0; i < self->field_138818; ++i) {
            // zero entry tables at field_138810[i]
        }
    }
    func_117CAC(&self->field_138810, 0, 0x8);
    if (self->field_138814 != 0) {
        func_117CAC(&self->field_138808, 0, 0x8);
    }
}
