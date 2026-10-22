#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "unit_action_build_tile_path_fixture.h"

static int g_func_123350_called = 0;
static int g_func_26AD20_called = 0;
static int g_func_26E750_called = 0;
static std::vector<void*> g_notified_units;
static int g_mock_flag_800_result = 1;

extern "C" {
    int func_123350(float val) {
        g_func_123350_called++;
        return (int)val;
    }
    char func_26AD20(void *unit, int flag) {
        (void)unit;
        g_func_26AD20_called++;
        if (flag == 0x800) {
            return (char)g_mock_flag_800_result;
        }
        return 0;
    }
    void func_0026E750(void *unit) {
        g_func_26E750_called++;
        g_notified_units.push_back(unit);
    }
}

static void reset_state() {
    g_func_123350_called = g_func_26AD20_called = g_func_26E750_called = 0;
    g_notified_units.clear();
    g_mock_flag_800_result = 1;
}

static void test_class_80_and_flag_800_overlap_notifies() {
    reset_state();
    DummyPathMaster nmaster = { 80, {}, 2.0f };
    DummyPathUnit nunit = { nullptr, &nmaster, {}, 0.5f, 0.5f };
    DummyPathUnit *unit_ptrs[1] = { &nunit };

    DummyPathTile grid[1][1] = {};
    grid[0][0].m_unit_count = 1;
    grid[0][0].m_units = unit_ptrs;
    DummyPathTile *rows[1] = { grid[0] };

    DummyPathZone zone = { nullptr, 0, 1, 1, {}, rows };
    DummyPathWorld world = { {}, &zone };
    DummyPathActor actor = { {}, &world };
    DummyPathMaster master = { 80, {}, 2.0f };
    DummyPathAction action = { nullptr, &master, &actor, {}, 0.0f, 0.0f };

    func_00271220((ActionRebind*)&action);
    assert(g_func_26E750_called == 1);
    assert(g_notified_units.size() == 1 && g_notified_units[0] == &nunit);
}

static void test_non_80_class_ignored() {
    reset_state();
    DummyPathMaster nmaster = { 70, {}, 2.0f };
    DummyPathUnit nunit = { nullptr, &nmaster, {}, 0.0f, 0.0f };
    DummyPathUnit *unit_ptrs[1] = { &nunit };

    DummyPathTile grid[1][1] = {};
    grid[0][0].m_unit_count = 1;
    grid[0][0].m_units = unit_ptrs;
    DummyPathTile *rows[1] = { grid[0] };

    DummyPathZone zone = { nullptr, 0, 1, 1, {}, rows };
    DummyPathWorld world = { {}, &zone };
    DummyPathActor actor = { {}, &world };
    DummyPathMaster master = { 80, {}, 2.0f };
    DummyPathAction action = { nullptr, &master, &actor, {}, 0.0f, 0.0f };

    func_00271220((ActionRebind*)&action);
    assert(g_func_26E750_called == 0);
}

static void test_missing_flag_800_ignored() {
    reset_state();
    g_mock_flag_800_result = 0;
    DummyPathMaster nmaster = { 80, {}, 2.0f };
    DummyPathUnit nunit = { nullptr, &nmaster, {}, 0.0f, 0.0f };
    DummyPathUnit *unit_ptrs[1] = { &nunit };

    DummyPathTile grid[1][1] = {};
    grid[0][0].m_unit_count = 1;
    grid[0][0].m_units = unit_ptrs;
    DummyPathTile *rows[1] = { grid[0] };

    DummyPathZone zone = { nullptr, 0, 1, 1, {}, rows };
    DummyPathWorld world = { {}, &zone };
    DummyPathActor actor = { {}, &world };
    DummyPathMaster master = { 80, {}, 2.0f };
    DummyPathAction action = { nullptr, &master, &actor, {}, 0.0f, 0.0f };

    func_00271220((ActionRebind*)&action);
    assert(g_func_26AD20_called == 1);
    assert(g_func_26E750_called == 0);
}

static void test_distance_exceeding_threshold_ignored() {
    reset_state();
    DummyPathMaster nmaster = { 80, {}, 0.2f };
    DummyPathUnit nunit = { nullptr, &nmaster, {}, 0.8f, 0.8f };
    DummyPathUnit *unit_ptrs[1] = { &nunit };

    DummyPathTile grid[1][1] = {};
    grid[0][0].m_unit_count = 1;
    grid[0][0].m_units = unit_ptrs;
    DummyPathTile *rows[1] = { grid[0] };

    DummyPathZone zone = { nullptr, 0, 1, 1, {}, rows };
    DummyPathWorld world = { {}, &zone };
    DummyPathActor actor = { {}, &world };
    DummyPathMaster master = { 80, {}, 0.2f };
    DummyPathAction action = { nullptr, &master, &actor, {}, 0.0f, 0.0f };

    func_00271220((ActionRebind*)&action);
    assert(g_func_26E750_called == 0);
}

static void test_empty_tile_and_clamping() {
    reset_state();
    DummyPathTile grid[1][1] = {};
    grid[0][0].m_unit_count = 0;
    grid[0][0].m_units = nullptr;
    DummyPathTile *rows[1] = { grid[0] };

    DummyPathZone zone = { nullptr, 0, 1, 1, {}, rows };
    DummyPathWorld world = { {}, &zone };
    DummyPathActor actor = { {}, &world };
    DummyPathMaster master = { 80, {}, 5.0f };
    DummyPathAction action = { nullptr, &master, &actor, {}, 0.0f, 0.0f };

    func_00271220((ActionRebind*)&action);
    assert(g_func_26E750_called == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_class_80_and_flag_800_overlap_notifies();
        test_non_80_class_ignored();
        test_missing_flag_800_ignored();
        test_distance_exceeding_threshold_ignored();
        test_empty_tile_and_clamping();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_class_80_and_flag_800_overlap_notifies(); break;
        case 1: test_non_80_class_ignored(); break;
        case 2: test_missing_flag_800_ignored(); break;
        case 3: test_distance_exceeding_threshold_ignored(); break;
        case 4: test_empty_tile_and_clamping(); break;
        default: return 1;
    }
    return 0;
}
