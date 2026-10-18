#pragma exceptions off
#include "zone_spatial_grid_query_bounds.h"

struct EntityData {
    char pad_00[0x20];
    float size_x;
    float size_y;
    char pad_28[0x82 - 0x28];
    unsigned char mode;
    unsigned char field_83;
};

struct SubObject {
    int type;
    unsigned char mode;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
    void *entity;
    int field_C;
    int cell_idx;
    int list_idx;
    short field_18;
    char pad_1A[2];
    unsigned char indices[4];
    float min_x;
    float min_y;
    float max_x;
    float max_y;
    float pad_box[4];
};

struct Entity {
    char pad_00[4];
    EntityData *data;
    void *world;
    char pad_0C[0x18];
    short field_24;
    char pad_26[0x44 - 0x26];
    float pos_x;
    float pos_y;
    char pad_4C[4];
    SubObject *sub_obj;
};

struct PyramidCell {
    SubObject **items;
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
    char pad_00[0x27420];
    char buffer_27420[0x3FFC];
    char pad_after[0x12B41C - 0x27420 - 0x3FFC];
    char is_initialized;
    char pad_align[3];
    void *world;
    int width;
    int height;
    float f_width;
    float f_height;
    void *table1;
    void *table2;
    int level_count;
    PyramidCell *cells;
    int total_nodes;
    int level_lut[0x20];
    PyramidLevel levels[8];
    char pad_12B570[8];
    void *pool;
};

extern "C" int func_001EDA90(SpatialGrid *self, Entity *entity) {
    EntityData *data = entity->data;
    SubObject *sub = entity->sub_obj;
    unsigned char mode = data->mode;
    unsigned char f83 = data->field_83;

    if (mode <= 0 || f83 <= 0 || mode >= 3) {
        return 0;
    }

    float pos_x = entity->pos_x;
    float size_x = data->size_x;
    float size_y = data->size_y;
    float pos_y = entity->pos_y;

    float f_min_x = pos_x - size_x;
    int min_x = func_123350(f_min_x);
    float f_min_y = pos_y - size_y;
    int min_y = func_123350(f_min_y);
    float f_max_x = pos_x + size_x;
    int max_x = func_123350(f_max_x);
    float f_max_y = pos_y + size_y;
    int max_y = func_123350(f_max_y) - 1;

    func_1EE5A0(self, min_x, min_y, max_x, max_y, (void *)(long)f83, 0, (int)(long)entity);

    if (mode == 1) {
        return 1;
    }

    int old_cell = -1;
    int old_idx = -1;

    if (sub == 0) {
        sub = (SubObject *)func_1F2320(self->pool);
        entity->sub_obj = sub;
        sub->field_6 = 1;
        sub->entity = entity;
        sub->field_5 = 0;
        sub->field_7 = 0;
        sub->field_C = 0;
        sub->field_18 = entity->field_24;
        sub->mode = 0;
    } else {
        old_cell = sub->cell_idx;
        old_idx = sub->list_idx;
    }

    int i_min_x = func_123350(f_min_x);
    int i_min_y = func_123350(f_min_y);
    int xor_x = i_min_x ^ func_123350(f_max_x);
    int level_x = self->level_lut[(xor_x >> 3) & 0x1F];
    int xor_y = i_min_y ^ func_123350(f_max_y);
    int level_y = self->level_lut[(xor_y >> 3) & 0x1F];

    int level_idx = (level_x < level_y) ? level_x : level_y;
    PyramidLevel *lvl = &self->levels[level_idx];

    int cell_x = i_min_x >> lvl->shift;
    int cell_y = i_min_y >> lvl->shift;
    int cell_idx = lvl->offset + (cell_y << lvl->id) + cell_x;

    if (cell_idx != old_cell) {
        if (old_cell >= 0) {
            PyramidCell *pc = &self->cells[old_cell];
            int last_idx = pc->count - 1;
            if (old_idx + 1 < pc->count) {
                SubObject *last_sub = pc->items[last_idx];
                pc->items[old_idx] = last_sub;
                last_sub->list_idx = old_idx;
            }
            pc->count--;
        }

        PyramidCell *nc = &self->cells[cell_idx];
        if (nc->count >= nc->capacity) {
            nc->capacity += 0xC0;
            if (nc->capacity == 0xC0) {
                nc->items = (SubObject **)((char *)self + 0x2B41C + (cell_idx << 8));
                func_117CAC(nc->items, 0, 0x300);
            }
        }
        int new_idx = nc->count++;
        nc->items[new_idx] = sub;

        if (sub->mode != mode) {
            if ((unsigned int)(mode - 2) < 2) {
                sub->indices[0] = 0;
                sub->indices[1] = 1;
                sub->indices[2] = 2;
                sub->indices[3] = 3;
            } else if (mode == 5) {
                sub->indices[0] = 4;
                sub->indices[1] = 5;
                sub->indices[2] = 6;
                sub->indices[3] = 7;
            }
            sub->mode = mode;
        }

        sub->cell_idx = cell_idx;
        sub->list_idx = new_idx;

        if (mode == 2) {
            sub->type = 2;
            sub->min_x = entity->pos_x;
            sub->min_y = entity->pos_y;
            sub->max_x = data->size_x;
            sub->max_y = data->size_x * data->size_x;
            sub->pad_box[0] = f_min_x;
            sub->pad_box[1] = f_min_y;
            sub->pad_box[2] = f_max_x;
            sub->pad_box[3] = f_max_y;
        } else if (mode == 3) {
            sub->type = 2;
            sub->min_x = f_min_x;
            sub->min_y = f_min_y;
            sub->max_x = f_max_x;
            sub->max_y = f_max_y;
        }
    }
    return 1;
}
