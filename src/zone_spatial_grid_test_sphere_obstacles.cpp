#pragma exceptions off
#include "zone_spatial_grid_test_sphere_obstacles.h"

extern "C" {
float func_1B3860(float val);
}

struct Point2D {
    float x;
    float y;
    char pad[0x10];
    float radius;
};

extern "C" int func_001E82E0(void *p0, int p1, char p2, void *p3, void *p4, void *p5, int p6, int p7, char p8) {
    Point2D *obs = (Point2D *)p3;
    Point2D *orig = (Point2D *)p4;
    if (obs == 0 || orig == 0) {
        return 0;
    }
    float dx = obs->x - orig->x;
    float dy = obs->y - orig->y;
    float dist = func_1B3860(dx * dx + dy * dy);
    if (dist > obs->radius) {
        return 0;
    }
    return 1;
}
