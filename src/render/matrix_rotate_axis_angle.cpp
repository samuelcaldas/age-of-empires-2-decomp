#pragma exceptions off

#include "matrix_rotate_axis_angle.h"

extern "C" {
int func_00123350(float val);
float func_33D560(int idx);
float func_33D530(int idx);
}

static const float s_pi = 3.1415927f;
static const float s_two_pi = 6.2831855f;

extern "C" void func_001D7ED0(float *dst, const float *axis, float angle) {
    float val = (angle * 4096.0f + s_pi) / s_two_pi;
    float cos_val = func_33D560(func_00123350(val));
    float one_minus_cos = 1.0f - cos_val;
    float sin_val = func_33D530(func_00123350(val));

    float x = axis[0];
    float y = axis[1];
    float z = axis[2];

    dst[0] = cos_val + one_minus_cos * (x * x);

    float z_sin;
    float xy_cos;
    float xy = x * y;
    xy_cos = xy * one_minus_cos;
    z_sin = z * sin_val;
    dst[1] = xy_cos - z_sin;
    float dst4 = xy_cos + z_sin;

    float y_sin;
    float xz_cos;
    float xz = x * z;
    xz_cos = xz * one_minus_cos;
    float x_sin = x * sin_val;
    y_sin = y * sin_val;
    dst[2] = xz_cos + y_sin;

    float yy = y * y;
    dst[3] = 0.0f;
    dst[4] = dst4;

    float y_cos = one_minus_cos * yy;
    dst[5] = cos_val + y_cos;

    float yz = y * z;
    float yz_cos = yz * one_minus_cos;
    float zz = z * z;
    dst[6] = yz_cos - x_sin;

    float z_cos = one_minus_cos * zz;
    dst[7] = 0.0f;

    float dst8 = xz_cos - y_sin;
    float dst9 = yz_cos + x_sin;
    dst[8] = dst8;
    float dst10 = cos_val + z_cos;
    dst[9] = dst9;
    dst[10] = dst10;
    dst[11] = 0.0f;
}
