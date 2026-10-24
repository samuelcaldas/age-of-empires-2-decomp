#pragma exceptions off

#include "zone_spatial_entity_update_pos.h"

extern "C" {
void func_194E90(void *self, void *arg1, void *arg2, float x, float y, float z);
}

struct SpatialEntityState {
    char pad[0x104];
    short field_104;
    char field_106;
    char field_107;
};

extern "C" int func_001D8520(SpatialEntityState *self, void *arg1, void *arg2, float x, float y, float z) {
    self->field_106 = 1;
    self->field_104 = -1;
    self->field_107 = 0;
    func_194E90(self, arg1, arg2, x, y, z);
    return 1;
}
