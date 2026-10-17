// Tests for func_802753E0 — Milestone 83 (796B)
// Verifies spatial particle coordinate calculation, tile conversion,
// and target object vtable dispatch.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_53e0.h"

static int g_tile_x_arg = 0;
static int g_tile_y_arg = 0;
static int g_target_update_calls = 0;

extern "C" int func_123350(float val) {
    return (int)std::round(val);
}

extern "C" void func_8033D560(void *, int tile_x) {
    g_tile_x_arg = tile_x;
}

extern "C" void func_8033D530(void *, int tile_y) {
    g_tile_y_arg = tile_y;
}

static void mock_target_update(void *) {
    g_target_update_calls++;
}

static void test_coordinate_calculation_and_dispatch() {
    unsigned char target[256] = {};
    void *vtbl[16] = {};
    vtbl[4] = (void *)mock_target_update;

    void *vtbl_ptr = vtbl;
    std::memcpy(target, &vtbl_ptr, sizeof(void *));

    g_tile_x_arg = 0;
    g_tile_y_arg = 0;
    g_target_update_calls = 0;

    func_802753E0(nullptr, target, 0, 10.0f, 20.0f, 5.0f, 2.3f, -1.2f);

    assert(g_tile_x_arg == 12); // round(10.0 + 2.3 = 12.3) = 12
    assert(g_tile_y_arg == 19); // round(20.0 - 1.2 = 18.8) = 19
    assert(g_target_update_calls == 1);
    printf("PASS test_coordinate_calculation_and_dispatch\n");
}

int main() {
    test_coordinate_calculation_and_dispatch();
    printf("All unit_action_build_53e0 tests passed!\n");
    return 0;
}
