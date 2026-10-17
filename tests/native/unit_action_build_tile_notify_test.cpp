#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_tile_notify_fixture.h"

static int g_func_26A700_called = 0;
static int g_func_26A700_ret = 1;
static int g_mock_tile_x = 15;
static int g_mock_tile_y = 25;

static int g_func_25F6E0_called = 0;
static void *g_last_25F6E0_target = nullptr;
static int g_last_25F6E0_a1 = 0;
static int g_last_25F6E0_a2 = 0;
static int g_last_25F6E0_a3 = 0;
static int g_last_25F6E0_a4 = 0;
static int g_last_25F6E0_a5 = 0;

extern "C" {
    int func_26A700(void *action, int *out1, int *out2) {
        (void)action;
        g_func_26A700_called++;
        *out1 = g_mock_tile_x;
        *out2 = g_mock_tile_y;
        return g_func_26A700_ret;
    }

    void func_25F6E0(void *field38, int a1, int a2, int a3, int a4, int a5) {
        g_func_25F6E0_called++;
        g_last_25F6E0_target = field38;
        g_last_25F6E0_a1 = a1;
        g_last_25F6E0_a2 = a2;
        g_last_25F6E0_a3 = a3;
        g_last_25F6E0_a4 = a4;
        g_last_25F6E0_a5 = a5;
    }
}

static void reset_test_state() {
    g_func_26A700_called = 0;
    g_func_26A700_ret = 1;
    g_func_25F6E0_called = 0;
    g_last_25F6E0_target = nullptr;
    g_last_25F6E0_a1 = 0;
    g_last_25F6E0_a2 = 0;
    g_last_25F6E0_a3 = 0;
    g_last_25F6E0_a4 = 0;
    g_last_25F6E0_a5 = 0;
}

// Case 0: func_26A700 returns 0 skips func_25F6E0
static void test_coords_fail() {
    reset_test_state();
    g_func_26A700_ret = 0;
    DummyAction action = {};

    func_0026F8A0((ActionRebind*)&action);

    assert(g_func_26A700_called == 1);
    assert(g_func_25F6E0_called == 0);
}

// Case 1: target is null skips func_25F6E0
static void test_null_target() {
    reset_test_state();
    DummyGrid grid = {};
    grid.m_target = nullptr; // null

    DummyLayer layer = {};
    layer.m_grid = &grid;

    DummyWorld world = {};
    world.m_layer = &layer;

    DummyAction action = {};
    action.m_world = &world;

    func_0026F8A0((ActionRebind*)&action);

    assert(g_func_26A700_called == 1);
    assert(g_func_25F6E0_called == 0);
}

// Case 2: valid target receives exact coordinates and -1 sentinels
static void test_valid_notification() {
    reset_test_state();
    char dummy_target[16];
    DummyGrid grid = {};
    grid.m_target = dummy_target;

    DummyLayer layer = {};
    layer.m_grid = &grid;

    DummyWorld world = {};
    world.m_layer = &layer;

    DummyAction action = {};
    action.m_world = &world;

    g_mock_tile_x = 33;
    g_mock_tile_y = 77;

    func_0026F8A0((ActionRebind*)&action);

    assert(g_func_26A700_called == 1);
    assert(g_func_25F6E0_called == 1);
    assert(g_last_25F6E0_target == dummy_target);
    assert(g_last_25F6E0_a1 == 1);
    assert(g_last_25F6E0_a2 == 33);
    assert(g_last_25F6E0_a3 == 77);
    assert(g_last_25F6E0_a4 == -1);
    assert(g_last_25F6E0_a5 == -1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_coords_fail();
        test_null_target();
        test_valid_notification();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_coords_fail(); break;
        case 1: test_null_target(); break;
        case 2: test_valid_notification(); break;
        default: return 1;
    }
    return 0;
}
