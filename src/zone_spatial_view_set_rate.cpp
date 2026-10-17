#pragma exceptions off

#include "zone_spatial_view_set_rate.h"

extern "C" {
extern float D_004E2808;
extern float D_004E27FC;
}

struct SpatialViewObj {
    char pad[0xA0];
    float fA0;
    float fA4;
};

extern "C" void func_001D8F90(SpatialViewObj *self, float val) {
    self->fA0 = val;
    if (val == 0.0f) {
        self->fA4 = D_004E2808;
    } else {
        self->fA4 = D_004E27FC / val;
    }
}
