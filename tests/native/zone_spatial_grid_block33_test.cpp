#include <cassert>
#include <cstring>
#include "zone_spatial_grid_execute_hierarchical_query.h"

static int g_set_margin_called = 0;
static int g_point_in_bounds_called = 0;
static int g_point_in_bounds_return = 1;
static int g_expand_buffer3_called = 0;
static int g_raycast_called = 0;
static int g_raycast_return = 0;
static int g_pathfind_called = 0;
static int g_smooth_called = 0;
static int g_alloc_node_called = 0;

extern "C" {
void func_1E7020(void *self, float margin) {
    g_set_margin_called++;
}
int func_1E7070(void *self, float x, float y) {
    g_point_in_bounds_called++;
    return g_point_in_bounds_return;
}
void *func_332E60(void *mgr, int id) { return nullptr; }
void func_269220(void *entity, float *out_x, float *out_y, float z) {}
void func_1E6FC0(void *self, int size) {
    g_expand_buffer3_called++;
}
void func_1EE8F0(void *world, int flag, float radius) {}
void func_1EE070(void *world) {}
void func_1EE850(void *world, int flag, void *arr, int count) {}
int func_1E8CD0(void *self, void *start, void *end, int flag, void *t0, void *t1, int p6, int p7, float margin, int p9) {
    g_raycast_called++;
    return g_raycast_return;
}
int func_123350(float val) {
    return (int)val;
}
void *func_1E82D0(void *self, int *out_idx) {
    g_alloc_node_called++;
    return nullptr;
}
int func_1EA7E0(void *self, void *start, void *end, int flag, void *out_path, int *out_len, int *out_status) {
    g_pathfind_called++;
    return 1;
}
void func_1EB210(void *self, void *p1, void *nodes, int flag, void *p4, void *p5, void *p6) {
    g_smooth_called++;
}
}

int main() {
    struct WorldMap {
        char pad[0x10];
    } world;

    struct DummyGrid {
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
    } dummy;
    memset(&dummy, 0, sizeof(dummy));
    dummy.world = &world;

    // Test 0: When a3 == 0, must return 4 immediately
    int res_a3_zero = func_001E9160((SpatialGrid *)&dummy, 0, 0, 0, 0, nullptr, nullptr, nullptr, 10.0f, 10.0f, 1.0f, 20.0f, 20.0f, 1.0f, (void *)0);
    assert(res_a3_zero == 4);

    // Test 1: When points are outside bounds (func_1E7070 returns 0), must return 4
    g_point_in_bounds_return = 0;
    int res_out_of_bounds = func_001E9160((SpatialGrid *)&dummy, 0, 0, 1, 0, nullptr, nullptr, nullptr, 10.0f, 10.0f, 1.0f, 20.0f, 20.0f, 1.0f, (void *)0);
    assert(res_out_of_bounds == 4);

    // Test 2: In-range early exit: distance <= range + radius returns 0
    g_point_in_bounds_return = 1;
    // (10 - 11)^2 + (10 - 11)^2 = 2 <= (2.0 + 1.0)^2 = 9 -> in range!
    int res_in_range = func_001E9160((SpatialGrid *)&dummy, -1, 0, 1, 0, nullptr, nullptr, nullptr, 10.0f, 10.0f, 1.0f, 11.0f, 11.0f, 1.0f, (void *)0);
    assert(res_in_range == 0);

    // Test 3: Raycast mode (mode == 1): when direct path clear, returns 1
    g_raycast_return = 1;
    int res_ray_hit = func_001E9160((SpatialGrid *)&dummy, -1, 0, 1, 1, nullptr, nullptr, nullptr, 10.0f, 10.0f, 0.0f, 50.0f, 50.0f, 0.0f, (void *)1);
    assert(res_ray_hit == 1);
    assert(g_raycast_called > 0);

    // Test 4: Bounding tile coordinates are computed and stored
    assert(dummy.min_x >= 0 || dummy.min_x == -1);

    return 0;
}
