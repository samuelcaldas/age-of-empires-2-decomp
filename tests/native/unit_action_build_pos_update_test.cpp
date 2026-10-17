#include <cassert>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_pos_update_fixture.h"

static int g_func_1CA430_called = 0;
static int g_func_1CA180_called = 0;
static int g_func_1CA7F0_called = 0;
static int g_func_197E40_called = 0;

static float g_mock_move_ret = 42.0f;

extern "C" {
    int func_123350(float val) {
        return (int)val;
    }

    float func_197E40(void *action, float x, float y, float z) {
        (void)action; (void)x; (void)y; (void)z;
        g_func_197E40_called++;
        return g_mock_move_ret;
    }

    void func_1CA430(void *map, int min_x, int min_y, int max_x, int max_y) {
        (void)map; (void)min_x; (void)min_y; (void)max_x; (void)max_y;
        g_func_1CA430_called++;
    }

    void func_1CA180(void *map, int tile_x, int tile_y, int min_x, int min_y, int max_x, int max_y) {
        (void)map; (void)tile_x; (void)tile_y; (void)min_x; (void)min_y; (void)max_x; (void)max_y;
        g_func_1CA180_called++;
    }

    char func_1CA7F0(void *map, int tile_x, int tile_y, int min_x, int min_y, int max_x, int max_y) {
        (void)map; (void)tile_x; (void)tile_y; (void)min_x; (void)min_y; (void)max_x; (void)max_y;
        g_func_1CA7F0_called++;
        return 7;
    }
}

static void reset_test_state() {
    g_func_1CA430_called = 0;
    g_func_1CA180_called = 0;
    g_func_1CA7F0_called = 0;
    g_func_197E40_called = 0;
}

// Case 0: m_field18 == 0 skips map grid calls, only invokes func_197E40
static void test_flag_zero() {
    reset_test_state();
    DummyAction action = {};
    action.m_field18 = 0;

    float ret = func_0026F9E0((ActionRebind*)&action, 10.0f, 20.0f, 30.0f);
    assert(ret == g_mock_move_ret);
    assert(g_func_197E40_called == 1);
    assert(g_func_1CA430_called == 0);
    assert(g_func_1CA180_called == 0);
    assert(g_func_1CA7F0_called == 0);
}

// Case 1: m_field18 != 0 but m_p304 != null skips map grid calls
static void test_subaction_present() {
    reset_test_state();
    DummyAction action = {};
    action.m_field18 = 1;
    char dummy_sub[16];
    action.m_p304 = dummy_sub;

    float ret = func_0026F9E0((ActionRebind*)&action, 10.0f, 20.0f, 30.0f);
    assert(ret == g_mock_move_ret);
    assert(g_func_197E40_called == 1);
    assert(g_func_1CA430_called == 0);
}

// Case 2: active footprint updates map grid before and after movement
static void test_full_grid_update() {
    reset_test_state();
    DummyMasterUnit master = {};
    master.m_ext_x = 2.0f;
    master.m_ext_y = 2.0f;

    char dummy_map[16];
    DummyMapContainer container = {};
    container.m_map = dummy_map;

    DummyWorld world = {};
    world.m_container = &container;

    DummyAction action = {};
    action.m_master = &master;
    action.m_world = &world;
    action.m_field18 = 1;
    action.m_pos_x = 50.0f;
    action.m_pos_y = 60.0f;

    float ret = func_0026F9E0((ActionRebind*)&action, 10.0f, 20.0f, 30.0f);
    assert(ret == g_mock_move_ret);
    assert(g_func_197E40_called == 1);
    assert(g_func_1CA430_called == 1);
    assert(g_func_1CA180_called == 1);
    assert(g_func_1CA7F0_called == 1);
    assert(action.m_fieldC6 == 7);
    assert(action.m_fieldC7 == 2); // 0.5 + (2.0 + 2.0)/2 = 2.5 -> (int)2
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_flag_zero();
        test_subaction_present();
        test_full_grid_update();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_flag_zero(); break;
        case 1: test_subaction_present(); break;
        case 2: test_full_grid_update(); break;
        default: return 1;
    }
    return 0;
}
