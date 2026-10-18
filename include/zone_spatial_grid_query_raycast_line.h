#ifndef ZONE_SPATIAL_GRID_QUERY_RAYCAST_LINE_H
#define ZONE_SPATIAL_GRID_QUERY_RAYCAST_LINE_H

struct SpatialGrid;
struct Point2D;

extern "C" {
int func_001EF910(SpatialGrid *self, int flags, void *p2, void *p3, int p4, float f12, float f13, float f14, float f15);
int func_123350(float val);
int func_1EF450(SpatialGrid *self, float fx0, float fy0, float fx1, float fy1, Point2D *out_pts, int *out_cnt);
int func_1EFF50(SpatialGrid *self, int cell_idx, int flags, void *p4, int p5);
int func_1F1520(SpatialGrid *self, int cell_idx, int flags, void *p4, int p5);
}

#endif
