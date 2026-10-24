#pragma exceptions off
#include "zone_spatial_grid_intersect_ray_edge.h"

extern "C" int func_001F0540(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float *out_t) {
    float dx_ray = x2 - x1;
    float dy_ray = y2 - y1;
    float dx_edge = x4 - x3;
    float dy_edge = y4 - y3;

    float denom = dx_ray * dy_edge - dy_ray * dx_edge;
    if (denom == 0.0f) {
        return 0;
    }

    float dx_ac = x1 - x3;
    float dy_ac = y1 - y3;
    float t = (dy_ac * dx_edge - dx_ac * dy_edge) / denom;
    float u = (dy_ac * dx_ray - dx_ac * dy_ray) / denom;

    if (t >= 0.0f && t <= 1.0f && u >= 0.0f && u <= 1.0f) {
        if (out_t != 0) {
            *out_t = t;
        }
        return 1;
    }
    return 0;
}
