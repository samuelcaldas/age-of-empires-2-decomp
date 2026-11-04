#pragma exceptions off

#include "zone_spatial_entity_set_angular_rate_z.h"

extern "C" {
void *func_1FC3B0();
}

struct SpatialEntity {
    char pad[0xBC];
    char *motion_ptr;
};

extern "C" void func_001DFF90(SpatialEntity *self, float val) {
    if (self->motion_ptr == 0) {
        if (0.0f == val) {
            return;
        }
        self->motion_ptr = (char *)func_1FC3B0();
        if (self->motion_ptr == 0) {
            return;
        }
    }
    *(float *)(self->motion_ptr + 0x14) = val;
}
