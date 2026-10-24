#pragma exceptions off
#include "zone_spatial_grid_set_margin_bounds.h"

struct WorldMap {
    char pad[0x12B424];
    int map_width;
    int map_height;
};

struct SpatialGrid {
    WorldMap *map;
    char pad_BC[0xBC - 4];
    float margin;
    float min_x;
    float max_x;
    float max_y;
};

extern "C" void func_001E7030(SpatialGrid *self, float margin) {
    self->margin = margin;
    self->max_x = (float)self->map->map_width - margin;
    self->min_x = margin;
    self->max_y = (float)self->map->map_height - margin;
}
