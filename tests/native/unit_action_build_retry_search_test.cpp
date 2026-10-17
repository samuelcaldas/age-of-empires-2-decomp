#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_retry_search_fixture.h"

static void reset_test_state() {
    g_func_123350_called = g_func_314DC0_called = g_func_1CF9B0_called = 0;
    g_last_notify_zone = nullptr;
    g_last_notify_min_x = g_last_notify_min_y = 0;
    g_last_notify_max_x = g_last_notify_max_y = 0;
    g_last_notify_status = 0;
}

static void test_status_27_matching_set() {
    reset_test_state();
    DummyCell grid[4][4] = {};
    DummyCell *rows[4] = { grid[0], grid[1], grid[2], grid[3] };
    DummyGridZone zone = { nullptr, 0, 4, 4, {}, rows };
    DummySearchWorld world = { {}, &zone };
    DummySearchActor actor = { {}, &world };
    DummySearchMaster master = { {}, 50, {}, 1.0f, 1.0f };
    DummySearchAction action = { nullptr, &master, &actor, {}, 2.0f, 2.0f };

    grid[1][1].m_flag = 0; grid[1][2].m_flag = 12; grid[2][1].m_flag = 3; grid[2][2].m_flag = 8;
    func_00270BA0((ActionRebind*)&action, 27);
    assert(g_func_1CF9B0_called == 1 && g_last_notify_status == 27);
    assert(grid[1][1].m_flag == 27 && grid[1][2].m_flag == 27 && grid[2][1].m_flag == 27 && grid[2][2].m_flag == 27);
}

static void test_status_non_27_matching() {
    reset_test_state();
    DummyCell grid[4][4] = {};
    DummyCell *rows[4] = { grid[0], grid[1], grid[2], grid[3] };
    DummyGridZone zone = { nullptr, 0, 4, 4, {}, rows };
    DummySearchWorld world = { {}, &zone };
    DummySearchActor actor = { {}, &world };
    DummySearchMaster master = { {}, 50, {}, 1.0f, 1.0f };
    DummySearchAction action = { nullptr, &master, &actor, {}, 2.0f, 2.0f };

    grid[1][1].m_flag = 8; grid[1][2].m_flag = 9; grid[2][1].m_flag = 8; grid[2][2].m_flag = 0;
    func_00270BA0((ActionRebind*)&action, 8);
    assert(g_func_1CF9B0_called == 1 && g_last_notify_status == 8);
    assert(grid[1][1].m_flag == 8 && grid[1][2].m_flag == 9 && grid[2][1].m_flag == 8 && grid[2][2].m_flag == 0);
}

static void test_gate_109_excluded_points() {
    reset_test_state();
    DummyCell grid[6][6] = {};
    DummyCell *rows[6] = { grid[0], grid[1], grid[2], grid[3], grid[4], grid[5] };
    DummyGridZone zone = { nullptr, 0, 6, 6, {}, rows };
    DummySearchWorld world = { {}, &zone };
    DummySearchActor actor = { {}, &world };
    DummySearchMaster master = { {}, 109, {}, 1.5f, 2.0f };
    DummySearchAction action = { nullptr, &master, &actor, {}, 2.5f, 3.0f };

    for (int y = 0; y < 6; ++y) {
        for (int x = 0; x < 6; ++x) {
            grid[y][x].m_flag = 5;
        }
    }
    func_00270BA0((ActionRebind*)&action, 5);
    assert(g_func_1CF9B0_called == 1);
    assert(grid[3][1].m_flag == 5 && grid[4][1].m_flag == 5);
}

static void test_no_modification_skips_notify() {
    reset_test_state();
    DummyCell grid[4][4] = {};
    DummyCell *rows[4] = { grid[0], grid[1], grid[2], grid[3] };
    DummyGridZone zone = { nullptr, 0, 4, 4, {}, rows };
    DummySearchWorld world = { {}, &zone };
    DummySearchActor actor = { {}, &world };
    DummySearchMaster master = { {}, 50, {}, 1.0f, 1.0f };
    DummySearchAction action = { nullptr, &master, &actor, {}, 2.0f, 2.0f };

    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            grid[y][x].m_flag = 99;
        }
    }
    func_00270BA0((ActionRebind*)&action, 8);
    assert(g_func_1CF9B0_called == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_status_27_matching_set(); test_status_non_27_matching();
        test_gate_109_excluded_points(); test_no_modification_skips_notify();
        return 0;
    }
    int t = atoi(argv[1]);
    if (t == 0) test_status_27_matching_set();
    if (t == 1) test_status_non_27_matching();
    if (t == 2) test_gate_109_excluded_points();
    if (t == 3) test_no_modification_skips_notify();
    return 0;
}
