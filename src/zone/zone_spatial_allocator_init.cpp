#pragma exceptions off

#include "zone_spatial_allocator_init.h"

struct SpatialNodeProps {
    char pad0[4];
    int prop1;
    int prop2;
    char pad1[0x18 - 0xC];
    char prop3;
};

extern "C" int func_001D81C0(SpatialNodeProps *self, int p1, int p2, char p3) {
    self->prop1 = p1;
    self->prop2 = p2;
    self->prop3 = p3;
    return 1;
}
