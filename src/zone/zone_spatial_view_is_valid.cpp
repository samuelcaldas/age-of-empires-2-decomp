#pragma exceptions off

#include "zone_spatial_view_is_valid.h"

extern "C" float sqrtf(float);

struct SpatialViewObj {
    char pad[0x64];
    float x;
    float y;
    float z;
};

extern "C" int func_001D8FD0(SpatialViewObj *self) {
    float sum = self->x * self->x + self->y * self->y + self->z * self->z;
    float len = sqrtf(sum);
    if (len <= 0.0f) {
        return 0;
    }
    return 1;
}
