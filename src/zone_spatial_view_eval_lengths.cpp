#pragma exceptions off

#include "zone_spatial_view_eval_lengths.h"

extern "C" {
void func_315110(void *dst, void *a1, void *a2, void *a3);
float sqrtf(float f);
extern float D_004E2820;
}

struct Vec3f {
    float x, y, z;
};

extern "C" int func_001DACD0(void *a0, void *a1, void *a2, void *a3, void *s0, void *s1, void *s2) {
    Vec3f v1;
    func_315110(&v1, a1, a3, a2);
    Vec3f v2;
    func_315110(&v2, s2, s0, a0);
    Vec3f v3;
    func_315110(&v3, s0, s1, a0);

    v1.y = 0.0f;
    v2.y = 0.0f;
    v3.y = 0.0f;

    float len1 = sqrtf(v1.x * v1.x + v1.z * v1.z);
    float len2 = sqrtf(v2.x * v2.x + v2.z * v2.z);
    float len3 = sqrtf(v3.x * v3.x + v3.z * v3.z);

    if (len1 <= len2) {
        return 0;
    }
    if (len2 < len3) {
        return 2;
    }
    if (len1 < D_004E2820) {
        return 1;
    }
    return 2;
}
