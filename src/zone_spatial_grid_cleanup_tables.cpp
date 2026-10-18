#pragma exceptions off
#include "zone_spatial_grid_cleanup_tables.h"

extern "C" {
extern void *D_004E2E08;
extern char D_00A801D0[];
}

struct SpatialGrid {
    char pad_00[0x27100];
    char buffer_27100[0x320];
    char buffer_27420[0x3FFC];
    char pad_after[0x12B41C - 0x27100 - 0x320 - 0x3FFC];
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
    void *nodes_table;
    int total_nodes;
    char pad_levels[0x12B570 - 0x12B450];
    void *mgr;
    char pad_12B574[4];
    void *pool;
    void *buffer_12B31C;
    int field_12B580;
    char pad_12B584[0x12B5B4 - 0x12B580 - 4];
    void *cached_nodes[4];
};

extern "C" int func_001ED840(SpatialGrid *self) {
    for (int i = 0; i < 4; ++i) {
        func_1F24A0((SpatialGrid *)self->cached_nodes[i]);
    }

    func_117CAC(self, 0, 0x27100);
    self->table1 = self;

    func_117CAC(&self->buffer_27100[0], 0, 0x320);
    self->table2 = &self->buffer_27100[0];

    func_117CAC((char *)self + 0x12B31C, 0, 0x100);
    self->buffer_12B31C = (char *)self + 0x12B31C;

    if (self->pool != 0) {
        func_1F2010((SpatialGrid *)D_004E2E08);
        self->pool = 0;
    }

    if (self->mgr != 0) {
        func_1E6380((SpatialGrid *)self->mgr);
        func_117CAC(D_00A801D0, 0, 0x9CC);
        self->mgr = 0;
    }

    func_117CAC((char *)self + 0x2B41C, 0, 0xFF00);
    func_117CAC(&self->buffer_27420[0], 0, 0x3FFC);
    self->nodes_table = 0;

    func_1ED1F0(self);
    return 1;
}
