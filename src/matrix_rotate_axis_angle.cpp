#pragma exceptions off

#include "matrix_rotate_axis_angle.h"

extern "C" {
int func_123350(float val);
float func_33D560(int idx);
float func_33D530(int idx);
}

static const float s_pi = 3.1415927f;
static const float s_two_pi = 6.2831855f;

extern "C" void func_001D7ED0(float *dst, const float *axis, float angle) {
    float val = (angle * 4096.0f + s_pi) / s_two_pi;
    float cos_val = func_33D560(func_123350(val));
    float one_minus_cos = 1.0f - cos_val;
    float sin_val = func_33D530(func_123350(val));

    float x = axis[0];
    float z = axis[2];
    float y = axis[1];

    dst[0] = cos_val + one_minus_cos * (x * x);

    float f1 = x * y;
    float f6 = f1 * one_minus_cos;
    float f2 = z * sin_val;
    dst[1] = f6 - f2;
    float dst4 = f6 + f2;

    f2 = x * z;
    f6 = f2 * one_minus_cos;
    float x_sin = x * sin_val;
    f2 = y * sin_val;
    dst[2] = f6 + f2;
    dst[3] = 0.0f;

    dst[4] = dst4;
    dst[5] = cos_val + one_minus_cos * (y * y);

    f1 = y * z;
    float f4 = f1 * one_minus_cos;
    dst[6] = f4 - x_sin;
    dst[7] = 0.0f;

    dst[8] = f6 - f2;
    dst[9] = f4 + x_sin;
    dst[10] = cos_val + one_minus_cos * (z * z);
    dst[11] = 0.0f;
}
