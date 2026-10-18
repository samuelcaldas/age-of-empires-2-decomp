#pragma exceptions off
#include "zone_spatial_grid_test_cell_items.h"

struct SpatialNode {
    int type;
    unsigned char mode;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
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
    char pad_after[0x12B5B0 - 0x12B448 - 4];
    void *query_target;
};

extern "C" int func_001EEEB0(SpatialGrid *self, int cell_idx, int flags, void *p4, int p5) {
    PyramidCell *cell = &self->cells[cell_idx];
    for (int i = 0; i < cell->count; ++i) {
        SpatialNode *node = cell->items[i];
        if (node->entity == self->query_target) {
            continue;
        }
        if (node->type == 1) {
            if (func_1F0A10(self, node, p4) != 0) {
                return 1;
            }
        } else if (node->type == 2) {
            if (func_1F1190(self, node, p4) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
