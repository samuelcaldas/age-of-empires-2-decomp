#pragma exceptions off

#include "zone_spatial_view_set_orient.h"

extern "C" {
float sqrtf(float);
void func_3151E0(float *cross, const float *v2, const float *v1);
}

extern "C" int func_001D8CA0(void *self, const Vec3f *v1, const Vec3f *v2, int flag) {
    float dot_val = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
    if (dot_val < -0.05f || dot_val > 0.05f) {
        return 0;
    }

    float u1[3] = { v1->x, v1->y, v1->z };
    float u2[3] = { v2->x, v2->y, v2->z };
    float u3[3];

    func_3151E0(u3, u2, u1);

    float len1 = sqrtf(u1[0] * u1[0] + u1[1] * u1[1] + u1[2] * u1[2]);
    u1[0] /= len1;
    u1[1] /= len1;
    u1[2] /= len1;

    float len2 = sqrtf(u2[0] * u2[0] + u2[1] * u2[1] + u2[2] * u2[2]);
    u2[0] /= len2;
    u2[1] /= len2;
    u2[2] /= len2;

    float len3 = sqrtf(u3[0] * u3[0] + u3[1] * u3[1] + u3[2] * u3[2]);
    u3[0] /= len3;
    u3[1] /= len3;
    u3[2] /= len3;

    char *base = (char *)self;
    if (flag == 1) {
        *(float *)(base + 0x40) = u1[0];
        *(float *)(base + 0x44) = u1[1];
        *(float *)(base + 0x48) = u1[2];

        *(float *)(base + 0x10) = u1[0];
        *(float *)(base + 0x14) = u1[1];
        *(float *)(base + 0x18) = u1[2];

        *(float *)(base + 0x4C) = u2[0];
        *(float *)(base + 0x50) = u2[1];
        *(float *)(base + 0x54) = u2[2];
    }

    return 1;
}
