#ifndef ZONE_SPATIAL_GRID_FIND_NEAREST_QUAD_INTERSECTION_H
#define ZONE_SPATIAL_GRID_FIND_NEAREST_QUAD_INTERSECTION_H

struct SpatialGrid;

extern "C" {
int func_001E8BB0(SpatialGrid *self, void *p1, void *origin, void *target, void *out_hit, int *out_node_idx, int *out_val);
}

#endif // ZONE_SPATIAL_GRID_FIND_NEAREST_QUAD_INTERSECTION_H
