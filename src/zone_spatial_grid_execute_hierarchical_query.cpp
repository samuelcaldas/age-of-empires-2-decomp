#pragma exceptions off
#include "zone_spatial_grid_execute_hierarchical_query.h"

extern "C" {
void func_1E7020(void *self, float margin);
int func_1E7070(void *self, float x, float y);
void *func_332E60(void *mgr, int id);
void func_269220(void *entity, float *out_x, float *out_y, float z);
void func_1E6FC0(void *self, int size);
void func_1EE8F0(void *world, int flag, float radius);
void func_1EE070(void *world);
void func_1EE850(void *world, int flag, void *arr, int count);
int func_1E8CD0(void *self, void *start, void *end, int flag, void *t0, void *t1, int p6, int p7, float margin, int p9);
int func_123350(float val);
void *func_1E82D0(void *self, int *out_idx);
int func_1EA7E0(void *self, void *start, void *end, int flag, void *out_path, int *out_len, int *out_status);
void func_1EB210(void *self, void *p1, void *nodes, int flag, void *p4, void *p5, void *p6);
}

struct Point2D {
    float x;
    float y;
};

struct WorldMap {
    char pad[0x10];
};

struct SpatialGrid {
    WorldMap *world;
    char pad_88[0x88 - 4];
    char flag_88;
    char pad_8C[3];
    int count_8C;
    char pad_94[4];
    int *array_94;
    char pad_A4[0xC];
    int min_x;
    int min_y;
    int max_x;
    int max_y;
};

static void reset_bounding_extents(SpatialGrid *self) {
    self->min_x = -1;
    self->min_y = -1;
    self->max_x = -1;
    self->max_y = -1;
}

static int validate_boundary_points(SpatialGrid *self, float fx0, float fy0, float fx1, float fy1, float margin) {
    func_1E7020(self, margin);
    if (func_1E7070(self, fx0, fy0) == 0) {
        return 0;
    }
    if (func_1E7070(self, fx1, fy1) == 0) {
        return 0;
    }
    return 1;
}

static int is_within_range(float dx, float dy, float range, float radius) {
    float max_dist = range + radius;
    float dist2 = dx * dx + dy * dy;
    if (dist2 <= max_dist * max_dist) {
        return 1;
    }
    return 0;
}

static void compute_bounding_tiles(SpatialGrid *self, float x0, float y0, float x1, float y1) {
    float min_x = (x0 < x1) ? x0 : x1;
    float max_x = (x0 < x1) ? x1 : x0;
    float min_y = (y0 < y1) ? y0 : y1;
    float max_y = (y0 < y1) ? y1 : y0;

    self->min_x = func_123350(min_x) - 2;
    self->max_x = func_123350(max_x) + 2;
    self->min_y = func_123350(min_y) - 2;
    self->max_y = func_123350(max_y) + 2;
}

static int execute_traversal_query(SpatialGrid *self, Point2D *start, Point2D *end, int flag, void *out_path, int *out_len, int *out_status) {
    int width = self->max_x - self->min_x + 1;
    int height = self->max_y - self->min_y + 1;
    int area = width * height;

    if (area >= 101) {
        int dummy_idx = 0;
        func_1E82D0(self, &dummy_idx);
    }

    int res = func_1EA7E0(self, start, end, flag, out_path, out_len, out_status);
    if (res != 0) {
        func_1EB210(self, 0, out_path, 0, 0, 0, 0);
    }
    return res;
}

extern "C" int func_001E9160(SpatialGrid *self, int a1, int a2, int a3, char t0, void *t1, void *t2, void *t3, float f12, float f13, float f14, float f15, float f16, float f17, void *stack_arg) {
    if (t0 == 0) {
        reset_bounding_extents(self);
    }
    if (a3 == 0) {
        return 4;
    }
    if (validate_boundary_points(self, f12, f13, f15, f16, f14) == 0) {
        return 4;
    }
    Point2D start = { f12, f13 };
    Point2D end = { f15, f16 };
    if (a1 < 0 && is_within_range(end.x - start.x, end.y - start.y, f17, f14) != 0) {
        return 0;
    }
    func_1E6FC0(self, 0x100);
    int mode = (int)(long)stack_arg;
    if (mode == 1) {
        int hit = func_1E8CD0(self, &start, &end, a3, t1, t2, 0, 0, f14, 0);
        if (hit != 0) {
            return 1;
        }
    }
    compute_bounding_tiles(self, start.x, start.y, end.x, end.y);
    return execute_traversal_query(self, &start, &end, a3, t1, (int *)t2, (int *)t3);
}
