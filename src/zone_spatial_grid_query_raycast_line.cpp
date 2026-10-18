#pragma exceptions off
#include "zone_spatial_grid_query_raycast_line.h"

struct Point2D {
    float x;
    float y;
};

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

extern "C" int func_001EF910(SpatialGrid *self, int flags, void *p2, void *p3, int p4, float f12, float f13, float f14, float f15) {
    self->query_target = p2;

    if (flags & 0x10) {
        if (self->param1 > 0) {
            self->flag_64 = (self->param3 > 0);
        }
    }

    self->flag_63 = (flags & 0x40) != 0;

    if (self->flag_64) {
        if (self->param2 != 0) {
            *self->param2 = 0;
        }
    }

    Point2D pts[32];
    int pt_count = 0;
    func_1EF450(self, f12, f13, f14, f15, pts, &pt_count);

    int hit = func_1EFF50(self, 0, flags, p3, p4);
    if (hit != 0) {
        return 1;
    }

    func_1F1520(self, 0, flags, p3, p4);
    return 0;
}
