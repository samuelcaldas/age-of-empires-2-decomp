#pragma exceptions off
#include "zone_spatial_grid_intersect_segments_2d.h"

extern "C" void func_001EF410(float *out_x, float *out_y, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    float dx_cd = x4 - x3;
    float dy_cd = y4 - y3;
    float dx_ab = x2 - x1;
    float dy_ab = y2 - y1;
    float dx_ac = x1 - x3;
    float dy_ac = y1 - y3;

    float num = dy_ac * dx_cd - dx_ac * dy_cd;
    float denom = dx_ab * dy_cd - dy_ab * dx_cd;
    float t = num / denom;

    *out_x = x1 + t * dx_ab;
    *out_y = y1 + t * dy_ab;
}
