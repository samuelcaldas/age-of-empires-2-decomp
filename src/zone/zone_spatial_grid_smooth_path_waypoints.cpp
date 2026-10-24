#pragma exceptions off
#include "zone_spatial_grid_smooth_path_waypoints.h"

extern "C" {
void func_1EE350(void *p1, int p2);
int func_1EE910(void *p1, int p2, void *p3, void *p4, float f14, float f15, void *t0);
void func_1FD540(void *p1, void *p2);
}

struct PathNode {
    float x;
    float y;
    PathNode *next;
};

struct SpatialGrid {
    void *world;
};

extern "C" void func_001EB0E0(SpatialGrid *self, void *p1, void *path_nodes, int flag_a3, void *p4, void *p5, void *p6) {
    if (self == 0 || path_nodes == 0) {
        return;
    }
}
