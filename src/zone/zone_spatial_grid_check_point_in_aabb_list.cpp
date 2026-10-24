#pragma exceptions off

#include "zone_spatial_grid_check_point_in_aabb_list.h"

struct AABB {
    float min_x;
    float min_y;
    float max_x;
    float max_y;
    float z;
};

struct Point2D {
    float x;
    float y;
};

struct AABBList {
    char pad[0x20];
    int count;
    char pad2[0x4];
    AABB *items;
};

extern "C" int func_001E6140(const AABBList *self, const Point2D *pt) {
    int n = self->count;
    for (int i = 0; i < n; i++) {
        const AABB *b = &self->items[i];
        if (pt->x <= b->min_x) continue;
        if (pt->x >= b->max_x) continue;
        if (pt->y <= b->min_y) continue;
        if (pt->y < b->max_y) {
            return 1;
        }
    }
    return 0;
}
