#pragma exceptions off
#include "zone_spatial_grid_scan_cell_nodes.h"

struct SpatialNode {
    char pad_00[0x18];
    void *entity;
};

struct PyramidCell {
    SpatialNode **items;
    int count;
    int capacity;
};

struct SpatialGrid {
    char pad_00[0x12B448];
    PyramidCell *cells;
};

extern "C" int func_001F1530(SpatialGrid *self, int cell_idx, int flags, void *p4, int p5) {
    if (self == 0) {
        return 0;
    }
    PyramidCell *cell = &self->cells[cell_idx];
    if (cell->count > 0) {
        return 1;
    }
    return 0;
}
