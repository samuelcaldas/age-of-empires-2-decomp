#pragma exceptions off
#include "zone_spatial_grid_remove_node.h"

struct Node {
    char pad_00[7];
    unsigned char field_7;
    char pad_08[8];
    int cell_idx;
    int list_idx;
};

struct PyramidCell {
    Node **items;
    int count;
    int capacity;
};

struct SpatialGrid {
    char pad_00[0x12B440];
    int field_12B440;
    char pad_after[0x12B448 - 0x12B440 - 4];
    PyramidCell *cells;
    char pad_after2[0x12B578 - 0x12B448 - 4];
    void *pool;
};

extern "C" void func_001EE790(SpatialGrid *self, Node *node) {
    if (node == 0) {
        return;
    }

    int cell_idx = node->cell_idx;
    int list_idx = node->list_idx;
    PyramidCell *cell = &self->cells[cell_idx];

    if (list_idx + 1 < cell->count) {
        Node *last_node = cell->items[cell->count - 1];
        cell->items[list_idx] = last_node;
        last_node->list_idx = list_idx;
    }

    cell->count--;

    if (node->field_7 == 0xED) {
        self->field_12B440--;
    }

    func_1F24A0(self->pool);
}
