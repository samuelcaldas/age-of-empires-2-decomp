#pragma exceptions off

#include "zone_spatial_view_is_valid.h"

struct SpatialViewObj {
    char pad[0x64];
    float x;
    float y;
    float z;
};

extern "C" int func_001D8FD0(SpatialViewObj *self) {
    if ((self->x * self->x + self->y * self->y) + self->z * self->z <= 0.0f) {
        return 0;
    } else {
        return 1;
    }
    return 0;
}
