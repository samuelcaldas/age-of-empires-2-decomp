#ifndef ZONE_SPATIAL_GRID_EVALUATE_EDGE_CROSS_H
#define ZONE_SPATIAL_GRID_EVALUATE_EDGE_CROSS_H

struct SpatialGrid;

extern "C" {
unsigned char func_1E59F0(SpatialGrid *self, void *p1, void *p2, void *p3);
unsigned char func_1E5BC0(SpatialGrid *self, void *p1, void *p2, void *p3);
unsigned char func_1E5D90(SpatialGrid *self, void *p1, void *p2, void *p3);
unsigned char func_1E5F60(SpatialGrid *self, void *p1, void *p2, void *p3);

unsigned char func_001E5960(SpatialGrid *self, void *p1, int edge, void *p3, void *p4);
}

#endif // ZONE_SPATIAL_GRID_EVALUATE_EDGE_CROSS_H
