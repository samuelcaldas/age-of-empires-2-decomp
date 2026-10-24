#pragma exceptions off

#include "zone_spatial_trigger_update.h"

extern "C" {
void func_194D70(void *self, void *arg1);
}

struct SpatialTargetObject {
    char pad[0x38];
    unsigned char flag_38;
};

extern "C" void func_001D8480(SpatialTargetObject *self, void *arg1) {
    if (self->flag_38 && arg1) {
        func_194D70(self, arg1);
    }
}
