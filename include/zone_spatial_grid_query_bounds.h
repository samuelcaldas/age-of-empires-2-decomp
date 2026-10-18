#ifndef ZONE_SPATIAL_GRID_QUERY_BOUNDS_H
#define ZONE_SPATIAL_GRID_QUERY_BOUNDS_H

struct SpatialGrid;
struct Entity;

extern "C" {
int func_001EDA90(SpatialGrid *self, Entity *entity);
int func_123350(float val);
int func_1EE5A0(SpatialGrid *self, int x0, int y0, int x1, int y1, void *p5, int p6, int p7);
void *func_1F2320(void *pool);
void func_117CAC(void *dst, int val, int size);
}

#endif
