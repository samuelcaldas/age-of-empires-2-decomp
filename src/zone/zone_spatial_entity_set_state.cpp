#pragma exceptions off

#include "zone_spatial_entity_set_state.h"

extern "C" {
void func_2673D0(void *self, int state);
}

struct SpatialEntityInfo {
    char pad[0x10];
    int default_state;
};

class SpatialEntity {
public:
    virtual void m0();
    SpatialEntityInfo *info;
    char pad[0x10 - 8];
    int state;
    int prev_state;
    virtual void Method2E8();
};

extern "C" void func_001DC9D0(SpatialEntity *self, int target_state) {
    if (target_state == 0) {
        target_state = self->info->default_state;
    }
    if (self->state != target_state) {
        self->prev_state = self->state;
        func_2673D0(self, target_state);
        self->Method2E8();
    }
}
