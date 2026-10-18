#ifndef ZONE_SPATIAL_GRID_CLEAR_ENTITY_MARKERS_H
#define ZONE_SPATIAL_GRID_CLEAR_ENTITY_MARKERS_H

struct SpatialGrid;
struct Entity;

extern "C" {
int func_001EE730(SpatialGrid *self, Entity *entity);
void func_1EE780(SpatialGrid *self, void *node);
}

#endif
