#pragma exceptions off
#include "zone_spatial_grid_execute_query.h"

extern "C" {
extern float D_00947960;
extern float D_00947964;
extern float D_00947968;
extern float D_0094796C;
extern float D_004E32A0;
extern float D_004E32A4;
extern float D_004E32A8;
extern float D_004E32AC;
}

#ifndef __MWERKS__
float D_00947960 = 0.0f;
float D_00947964 = 0.0f;
float D_00947968 = 0.0f;
float D_0094796C = 0.0f;
float D_004E32A0 = 0.0f;
float D_004E32A4 = 0.0f;
float D_004E32A8 = 0.0f;
float D_004E32AC = 0.0f;
#endif

struct PyramidCell {
    void **items;
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
    char pad_00[0x12B41C];
    char is_initialized;
    char pad_align[3];
    void *world;
    int width;
    int height;
    float f_width;
    float f_height;
    char pad_table[0x12B444 - 0x12B434];
    int level_count;
    PyramidCell *cells;
    int total_nodes;
    int level_lut[0x20];
    PyramidLevel levels[8];
    char pad_12B570[8];
    void *pool;
    char pad_12B57C[4];
    int param1;
    int *param2;
    int param3;
    char pad_align2[2];
    unsigned char has_margin;
    unsigned char flag_63;
    unsigned char flag_64;
    char pad_align3;
    float margin;
    void *query_target;
};

extern "C" int func_001EE920(SpatialGrid *self, int flags, void *p2, void *p3, int p4, float f12, float f13, float f14, float f15) {
    self->query_target = p2;

    if (flags & 0x10) {
        if (self->param1 > 0) {
            self->flag_64 = (self->param3 > 0);
        }
    }

    int is_flag20 = (flags & 0x20) != 0;
    self->flag_63 = (flags & 0x40) != 0;

    if (self->flag_64) {
        if (self->param2 != 0) {
            *self->param2 = 0;
        }
    }

    D_00947960 = f12;
    D_00947964 = f13;
    D_00947968 = f12;
    D_0094796C = f13;

    float min_x, max_x, min_y, max_y;
    if (f12 < f14) {
        min_x = f12;
        max_x = f14;
    } else {
        min_x = f14;
        max_x = f12;
    }

    if (f13 < f15) {
        min_y = f13;
        max_y = f15;
    } else {
        min_y = f15;
        max_y = f13;
    }

    if (self->has_margin != 0) {
        float m = self->margin;
        min_x -= m;
        min_y -= m;
        max_x += m;
        max_y += m;
    }

    int i_min_x = func_123350(min_x);
    int i_min_y = func_123350(min_y);
    int i_max_x = func_123350(max_x);
    int i_max_y = func_123350(max_y);

    if (min_x < 0.0f || min_y < 0.0f || max_x > (float)self->width || max_y > (float)self->height) {
        return 1;
    }

    if (i_min_x < 0) i_min_x = 0;
    if (i_min_y < 0) i_min_y = 0;
    if (i_max_x >= self->width) i_max_x = self->width - 1;
    if (i_max_y >= self->height) i_max_y = self->height - 1;

    int xor_y = i_min_y ^ i_max_y;
    int lut_y = self->level_lut[(xor_y >> 3) & 0x1F];

    int xor_x = i_min_x ^ i_max_x;
    int lut_x = self->level_lut[(xor_x >> 3) & 0x1F];

    int level_idx = (lut_x < lut_y) ? lut_y : lut_x;
    PyramidLevel *lvl = &self->levels[level_idx];

    int cell_x = i_min_x >> lvl->shift;
    int cell_y = i_min_y >> lvl->shift;

    for (int lvl_idx = level_idx; lvl_idx >= 0; --lvl_idx) {
        PyramidLevel *cur_lvl = &self->levels[lvl_idx];
        int c_idx = cur_lvl->offset + (cell_y << cur_lvl->id) + cell_x;
        PyramidCell *cell = &self->cells[c_idx];

        if (cell->count != 0) {
            int hit = 0;
            if (is_flag20) {
                hit = func_1EF180(self, (void *)(long)c_idx, (void *)(long)flags);
            } else {
                hit = func_1EEEA0(self, (void *)(long)c_idx, (void *)(long)flags);
            }
            if (hit != 0) {
                return 1;
            }
        }
        cell_x >>= 1;
        cell_y >>= 1;
    }

    return 0;
}
