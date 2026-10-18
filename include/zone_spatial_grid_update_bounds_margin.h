#ifndef ZONE_SPATIAL_GRID_UPDATE_BOUNDS_MARGIN_H
#define ZONE_SPATIAL_GRID_UPDATE_BOUNDS_MARGIN_H

struct SpatialGrid;
struct Entity;

extern "C" {
int func_001EDF30(SpatialGrid *self, Entity *entity);
int func_123350(float val);
int func_1EE660(SpatialGrid *self, int x0, int y0, int x1, int y1, int p5);
int func_1EE780(SpatialGrid *self, int p1, int p2, int p3, int p4);
}

#endif
