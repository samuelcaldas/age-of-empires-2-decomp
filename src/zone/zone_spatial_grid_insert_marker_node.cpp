#pragma exceptions off
#include "zone_spatial_grid_insert_marker_node.h"

struct MarkerNode {
    int type;
    unsigned char mode;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
    void *entity;
    MarkerNode *next;
    int cell_idx;
    int list_idx;
    unsigned int coord;
    unsigned char indices[4];
    float min_x;
    float min_y;
    float max_x;
    float max_y;
};

struct PyramidCell {
    MarkerNode **items;
    int count;
    int capacity;
};

struct PyramidLevel {
    int id;
    int shift;
    int dim;
    int offset;
    void *nodes;
};

struct SpatialGrid {
    char pad_00[0x12B438];
    int **grid_table;
    int marker_count;
    char pad_after[0x12B444 - 0x12B43C - 4];
    int level_count;
    PyramidCell *cells;
    int total_nodes;
    int level_lut[0x20];
    PyramidLevel levels[8];
    char pad_12B570[8];
    void *pool;
    char pad_12B57C[0x12B5AC - 0x12B578 - 4];
    MarkerNode *marker_head;
};

extern "C" int func_001EE140(SpatialGrid *self, int x, int y) {
    self->grid_table[y][x] ^= 0x80;
    MarkerNode *node = (MarkerNode *)func_1F2320(self->pool);
    self->marker_count++;

    node->field_6 = 1;
    node->entity = 0;
    node->field_5 = 0;
    node->field_7 = 0;
    node->next = self->marker_head;
    node->coord = 0xFC000000 | y | (x << 8);
    node->mode = 3;
    node->indices[0] = 0;
    node->indices[1] = 1;
    node->indices[2] = 2;
    node->indices[3] = 3;
    node->type = 2;
    node->min_x = (float)x;
    node->min_y = (float)y;
    node->max_x = (float)x + 1.0f;
    node->max_y = (float)y + 1.0f;

    int level_idx = self->level_lut[0];
    PyramidLevel *lvl = &self->levels[level_idx];
    int cell_x = x >> lvl->shift;
    int cell_y = y >> lvl->shift;
    int cell_idx = lvl->offset + (cell_y << lvl->id) + cell_x;

    PyramidCell *c = &self->cells[cell_idx];
    if (c->count >= c->capacity) {
        c->capacity += 0xC0;
        if (c->capacity == 0xC0) {
            c->items = (MarkerNode **)((char *)self + 0x2B41C + (cell_idx << 8));
            func_117CAC(c->items, 0, 0x300);
        }
    }

    int idx = c->count++;
    c->items[idx] = node;
    node->cell_idx = cell_idx;
    node->list_idx = idx;
    self->marker_head = node;

    return 1;
}
