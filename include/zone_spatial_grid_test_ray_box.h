#ifndef ZONE_SPATIAL_GRID_TEST_RAY_BOX_H
#define ZONE_SPATIAL_GRID_TEST_RAY_BOX_H

struct SpatialGrid;
struct SpatialNode;
struct Point2D;

extern "C" {
int func_001F0340(SpatialGrid *self, SpatialNode *node, void *p3);
int func_1F0530(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float *out_t);
int func_1F0290(SpatialGrid *self, void *node, Point2D *pos);
}

#endif
