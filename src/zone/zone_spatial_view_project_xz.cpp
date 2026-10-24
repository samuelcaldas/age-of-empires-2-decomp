#pragma exceptions off

#include "zone_spatial_view_project_xz.h"

extern "C" {
void func_315110(void *dst, void *a1, void *a2, void *a3);
float sqrtf(float f);
}

extern "C" int func_001DAB50(Vec3f *out, void *a1, void *a2, void *a3) {
    Vec3f sp30;
    func_315110(&sp30, a1, a2, a3);
    Vec3f sp20 = sp30;
    *out = sp20;
    out->y = 0.0f;
    float len = sqrtf(out->x * out->x + out->y * out->y + out->z * out->z);
    out->x /= len;
    out->y /= len;
    out->z /= len;
    return 1;
}
