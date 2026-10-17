#pragma exceptions off

#include "zone_spatial_entity_setup.h"

extern "C" {
void func_1E3710(void *self);
void func_151B90(void *self, void *sub);
}

extern "C" void func_001DC0B0(SpatialEntity *self, void *sub) {
    func_1E3710(self);
    if (sub != 0) {
        func_151B90(self, sub);
    }
}
