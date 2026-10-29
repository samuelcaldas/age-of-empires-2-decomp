#pragma exceptions off

#include "zone_spatial_view_calc_deflection.h"

extern "C" {
float func_3154A0(void *v1);
void func_3151E0(void *cross, void *v1, void *v2);
}

struct Vec3f {
    float x, y, z;
};

struct SpatialViewObj {
    char pad[0x9C];
    float field_9C;
};

extern "C" float func_001DAC10(SpatialViewObj *self, void *v1, void *v2, int flag, float scale) {
    float val = func_3154A0(v2);
    float limit = self->field_9C;
    if (flag == 1) {
        limit = limit * scale;
        if (val > limit) {
            val = limit;
        }
    }
    Vec3f cross;
    func_3151E0(&cross, v2, v1);
    if (!(cross.y <= 0.0f)) {
        val = -val;
    }
    return val;
}
