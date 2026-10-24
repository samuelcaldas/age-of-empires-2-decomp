#pragma exceptions off
#include "zone_spatial_grid_init_tables.h"

extern "C" {
extern void *D_004E2E08;
extern char D_00A801D0[];
}

#ifndef __MWERKS__
void *D_004E2E08 = 0;
char D_00A801D0[0x9CC] = { 0 };
#endif

struct PyramidLevel {
    int id;
    int shift;
    int dim;
    int offset;
    void *nodes;
};

struct SpatialGrid {
    char pad_00[0x27100];
    char buffer_27100[0x320];
    char buffer_27420[0x3FFC];
    char pad_after[0x12B41C - 0x27100 - 0x320 - 0x3FFC];
    char is_initialized;
    char pad_align[3];
    GameWorld *world;
    int width;
    int height;
    float f_width;
    float f_height;
    void *table1;
    void **table2;
    int level_count;
    void *nodes_table;
    int total_nodes;
    int level_lut[0x20];
    PyramidLevel levels[8];
    void *mgr;
    char pad_12B574[4];
    void *pool;
    void *buffer_12B31C;
    int field_12B580;
    char pad_12B584[0x12B5B4 - 0x12B580 - 4];
    void *cached_nodes[4];
};

extern "C" int func_001ED3D0(SpatialGrid *self, GameWorld *world) {
    self->world = world;
    self->width = world->map_info->width;
    self->height = world->map_info->height;
    self->f_width = (float)self->width;
    self->f_height = (float)self->height;

    self->table1 = (void *)self;
    func_117CAC(self, 0, 0x27100);
    self->table2 = (void **)&self->buffer_27100[0];
    func_117CAC(&self->buffer_27100[0], 0, 0x320);

    for (int y = 0; y < self->height; ++y) {
        self->table2[y] = (void *)((char *)self->table1 + y * self->width * 4);
    }

    func_1F1ED0((SpatialGrid *)D_004E2E08);
    self->pool = D_004E2E08;

    int max_dim = (self->width < self->height) ? self->height : self->width;
    max_dim += max_dim;
    int v1 = 0x1000;
    v1 >>= 1;
    while (max_dim < v1) {
        v1 >>= 1;
    }

    self->level_count = 0;
    self->total_nodes = 0;
    int a0 = 1;
    int s0 = v1;
    while (v1 >= 8) {
        self->total_nodes += a0;
        v1 >>= 1;
        self->level_count++;
        a0 <<= 2;
    }

    func_117CAC(&self->buffer_27420[0], 0, 0x3FFC);
    self->nodes_table = &self->buffer_27420[0];

    int t1 = 1;
    int a2 = 0;
    int a3 = 0;
    while (a3 < self->level_count) {
        self->levels[a3].id = a3;
        self->levels[a3].shift = (self->level_count + 2) - a3;
        self->levels[a3].dim = s0 >> a3;
        self->levels[a3].offset = a2;
        self->levels[a3].nodes = (char *)self->nodes_table + a2 * 12;
        a2 += t1;
        a3++;
        t1 <<= 2;
    }

    while (a3 < 8) {
        self->levels[a3].id = -1;
        self->levels[a3].shift = -1;
        self->levels[a3].dim = 0;
        self->levels[a3].offset = -1;
        self->levels[a3].nodes = 0;
        a3++;
    }

    for (int i = 0; i < 0x20; ++i) {
        int val = self->level_count - 1;
        int temp = i;
        while (temp > 0) {
            temp >>= 1;
            val--;
        }
        if (val < 0) {
            val = -1;
        }
        self->level_lut[i] = val;
    }

    self->field_12B580 = 0x10;
    func_117CAC((char *)self + 0x12B31C, 0, 0x100);
    self->buffer_12B31C = (char *)self + 0x12B31C;

    func_117CAC(D_00A801D0, 0, 0x9CC);
    self->mgr = D_00A801D0;
    func_1E6340((SpatialGrid *)self->mgr);

    self->is_initialized = 1;

    for (int i = 0; i < 4; ++i) {
        self->cached_nodes[i] = (void *)(long)func_1F2320((SpatialGrid *)self->pool);
    }

    return 1;
}
