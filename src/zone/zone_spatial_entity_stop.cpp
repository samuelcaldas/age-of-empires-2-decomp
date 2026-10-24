#pragma exceptions off

#include "zone_spatial_entity_stop.h"

extern "C" {
void func_267A80(void *self);
}

class SpatialEntity {
public:
    virtual void m0();
    char pad_vtable_to_motion[0x70 - 4];
    int f70;
    int f74;
    int f78;
    char pad_motion_to_80[0x80 - 0x7C];
    int f80;
    int f84;
    virtual void Method2E8();
};

extern "C" void func_001DCAA0(SpatialEntity *self) {
    func_267A80(self);
    self->f70 = 0;
    self->f74 = 0;
    self->f78 = 0;
    self->f84 = 0;
    self->f80 = 0;
    self->Method2E8();
}
