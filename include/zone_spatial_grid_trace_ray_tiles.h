#ifndef ZONE_SPATIAL_GRID_TRACE_RAY_TILES_H
#define ZONE_SPATIAL_GRID_TRACE_RAY_TILES_H

struct SpatialGrid;

struct Point2D {
    float x;
    float y;
};

extern "C" {
int func_001EF460(SpatialGrid *self, float fx0, float fy0, float fx1, float fy1, Point2D *out_points, int *out_count);
void func_001EF410(float *out_x, float *out_y, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
int func_123350(float val);
}

#endif
