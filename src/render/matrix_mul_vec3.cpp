#pragma exceptions off

#include "matrix_mul_vec3.h"

extern "C" void func_001D8000(float *dst, const float *m, const float *v) {
    float x = m[0] * v[0] + m[1] * v[1] + m[2] * v[2];
    float y = m[4] * v[0] + m[5] * v[1] + m[6] * v[2];
    float z = m[8] * v[0] + m[9] * v[1] + m[10] * v[2];
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}
