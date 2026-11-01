#pragma exceptions off

#include "zone_spatial_entity_dispatch_registration.h"

extern "C" {
extern void *D_004D6F34;
void func_1EE040(void *mgr, void *ent, int flag);
}

extern "C" void func_001DD790(SpatialEntity *self) {
    if (self->Method270()) {
        func_1EE040(D_004D6F34, self, 0x10);
    } else {
        func_1EE040(D_004D6F34, self, 0);
    }
}
