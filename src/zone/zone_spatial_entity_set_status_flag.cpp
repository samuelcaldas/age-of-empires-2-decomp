#pragma exceptions off

#include "zone_spatial_entity_set_status_flag.h"

extern "C" {
void func_26AD30(void *self, int a1, int a2);
}

struct SpatialEntity {
    char pad[0x10];
};

extern "C" void func_001DEB40(SpatialEntity *self, int a1) {
    func_26AD30(self, 0x40, a1);
}
