#ifndef ZONE_SPATIAL_GRID_FIND_SPATIAL_PATH_H
#define ZONE_SPATIAL_GRID_FIND_SPATIAL_PATH_H

struct SpatialGrid;

extern "C" {
int func_001EA7F0(SpatialGrid *self, void *start, void *end, int flag, void *out_path, int *out_len, int *out_status);
}

#endif // ZONE_SPATIAL_GRID_FIND_SPATIAL_PATH_H
