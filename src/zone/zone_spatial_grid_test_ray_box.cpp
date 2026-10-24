#pragma exceptions off
#include "zone_spatial_grid_test_ray_box.h"

struct Point2D {
    float x;
    float y;
};

struct SpatialNode {
    char pad_00[0x20];
    float min_x;
    float min_y;
    float max_x;
    float max_y;
};

struct SpatialGrid {
    char pad_00[0x12B584];
};

extern "C" {
extern float D_00947960;
extern float D_00947964;
extern float D_00947968;
extern float D_0094796C;
}

#ifndef __MWERKS__
float D_00947960 = 0.0f;
float D_00947964 = 0.0f;
float D_00947968 = 0.0f;
float D_0094796C = 0.0f;
#endif

extern "C" int func_001F0340(SpatialGrid *self, SpatialNode *node, void *p3) {
    float x1 = D_00947960;
    float y1 = D_00947964;
    float x2 = D_00947968;
    float y2 = D_0094796C;

    float bx0 = node->min_x;
    float by0 = node->min_y;
    float bx1 = node->max_x;
    float by1 = node->max_y;

    float best_t = 2.0f;
    Point2D hit_pt;
    int hit_any = 0;

    float t = 0.0f;
    if (func_1F0530(x1, y1, x2, y2, bx0, by0, bx1, by0, &t) != 0) {
        if (t < best_t) {
            best_t = t;
            hit_pt.x = x1 + t * (x2 - x1);
            hit_pt.y = y1 + t * (y2 - y1);
            hit_any = 1;
        }
    }

    if (func_1F0530(x1, y1, x2, y2, bx1, by0, bx1, by1, &t) != 0) {
        if (t < best_t) {
            best_t = t;
            hit_pt.x = x1 + t * (x2 - x1);
            hit_pt.y = y1 + t * (y2 - y1);
            hit_any = 1;
        }
    }

    if (func_1F0530(x1, y1, x2, y2, bx1, by1, bx0, by1, &t) != 0) {
        if (t < best_t) {
            best_t = t;
            hit_pt.x = x1 + t * (x2 - x1);
            hit_pt.y = y1 + t * (y2 - y1);
            hit_any = 1;
        }
    }

    if (func_1F0530(x1, y1, x2, y2, bx0, by1, bx0, by0, &t) != 0) {
        if (t < best_t) {
            best_t = t;
            hit_pt.x = x1 + t * (x2 - x1);
            hit_pt.y = y1 + t * (y2 - y1);
            hit_any = 1;
        }
    }

    if (hit_any != 0) {
        func_1F0290(self, node, (::Point2D *)&hit_pt);
        return 1;
    }
    return 0;
}
