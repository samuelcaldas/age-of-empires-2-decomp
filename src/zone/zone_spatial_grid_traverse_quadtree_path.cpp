#pragma exceptions off
#include "zone_spatial_grid_traverse_quadtree_path.h"

struct PyramidCell {
    void **items;
    int count;
    int capacity;
};

struct SpatialGrid {
    char pad_00[0x12B448];
    PyramidCell *cells;
};

extern "C" int func_001F1810(SpatialGrid *self, int cell_idx, int flags, void *p4, int p5) {
    if (self == 0) {
        return 0;
    }
    PyramidCell *cell = &self->cells[cell_idx];
    if (cell->count > 0) {
        return 1;
    }
    return 0;
}
