#pragma exceptions off

#include "zone_spatial_entity_derived_dtor.h"

extern "C" {
void func_001DC0B0(void *self, void *sub);
void func_2639D0(void *self, int flag);
void func_100670(void *ptr);
extern void *D_004D96B0;
extern void *D_004D7A90;
}

class SpatialEntity {
public:
    virtual ~SpatialEntity();
};

extern "C" void *func_001DC100(SpatialEntity *self, int flags) {
    if (self == 0) {
        return self;
    }
    *(void **)self = &D_004D96B0;
    func_001DC0B0(self, 0);
    *(void **)self = &D_004D7A90;
    func_2639D0(self, 0);
    if ((short)flags > 0) {
        func_100670(self);
    }
    return self;
}
