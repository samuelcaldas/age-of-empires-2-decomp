#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_retry_fixture.h"

static void reset_state() {
    g_func_123350_called = g_func_1378c0_called = g_func_270BA0_called = 0;
    g_last_1378c0_zone = nullptr;
    g_last_1378c0_tx = g_last_1378c0_ty = g_mock_1378c0_return = 0;
    g_last_270BA0_self = nullptr;
    g_last_270BA0_status = g_game_singleton.m_mode = 0;
}

static void test_mode_7_non_50_early_exit() {
    reset_state();
    g_game_singleton.m_mode = 7;
    DummyMaster master = { {}, 42 };
    DummyAction action = { nullptr, &master, nullptr, {}, 0.0f, 0.0f, {}, 0 };
    func_00270A20((ActionRebind*)&action, 5);
    assert(g_func_270BA0_called == 0 && action.m_field15A == 0);
}

static void test_status_8_rewrite_and_self_player() {
    reset_state();
    DummyZone zone = { {}, 1, 0 };
    DummyPlayerWorld pworld = { {}, &zone };
    DummyPlayer player = { {}, (void*)0x1234, &pworld };
    DummyPlayer *player_ptrs[4] = { &player, nullptr, nullptr, nullptr };
    DummyWorld world = { {}, player_ptrs, {}, 0 };
    DummyActor actor = { {}, &world };
    DummyMaster master = { {}, 50 };
    DummyAction action = { nullptr, &master, &actor, {}, 10.0f, 20.0f, {}, 0 };

    func_00270A20((ActionRebind*)&action, 8);
    assert(g_func_270BA0_called == 1 && g_last_270BA0_status == 27);

    reset_state();
    player_ptrs[0] = (DummyPlayer*)&actor;
    func_00270A20((ActionRebind*)&action, 8);
    assert(g_func_270BA0_called == 1 && g_last_270BA0_status == 8);
}

static void test_direct_flag_15_statuses() {
    int cases[3] = { 1, 28, 14 };
    for (int i = 0; i < 3; ++i) {
        reset_state();
        DummyPlayerWorld pworld = { {}, nullptr };
        DummyPlayer player = { {}, nullptr, &pworld };
        DummyPlayer *player_ptrs[4] = { &player, nullptr, nullptr, nullptr };
        DummyWorld world = { {}, player_ptrs, {}, 0 };
        DummyActor actor = { {}, &world };
        DummyMaster master = { {}, 50 };
        DummyAction action = { nullptr, &master, &actor, {}, 0.0f, 0.0f, {}, 0 };
        func_00270A20((ActionRebind*)&action, cases[i]);
        assert(g_func_270BA0_called == 1 && g_last_270BA0_status == cases[i]);
        assert(g_func_1378c0_called == 0);
    }
}

static void test_tile_and_zone_override() {
    reset_state();
    DummyZone zone = { {}, 0, 0 };
    DummyPlayerWorld pworld = { {}, &zone };
    DummyPlayer player = { {}, (void*)0x5678, &pworld };
    DummyPlayer *player_ptrs[4] = { &player, nullptr, nullptr, nullptr };
    DummyWorld world = { {}, player_ptrs, {}, 0 };
    DummyActor actor = { {}, &world };
    DummyMaster master = { {}, 50 };
    DummyAction action = { nullptr, &master, &actor, {}, 12.0f, 34.0f, {}, 0 };

    g_mock_1378c0_return = 15;
    func_00270A20((ActionRebind*)&action, 3);
    assert(g_func_1378c0_called == 1 && g_func_270BA0_called == 1 && g_last_270BA0_status == 3);

    reset_state();
    zone.f_8ECD = 1; zone.f_8ECE = 0; g_mock_1378c0_return = 0;
    func_00270A20((ActionRebind*)&action, 4);
    assert(g_func_270BA0_called == 1 && g_last_270BA0_status == 4);

    reset_state();
    zone.f_8ECD = 0; zone.f_8ECE = 0; g_mock_1378c0_return = 0x80;
    func_00270A20((ActionRebind*)&action, 6);
    assert(g_func_270BA0_called == 1 && g_last_270BA0_status == 6);
}

static void test_status_field_write_on_non_15() {
    reset_state();
    DummyZone zone = { {}, 0, 1 };
    DummyPlayerWorld pworld = { {}, &zone };
    DummyPlayer player = { {}, nullptr, &pworld };
    DummyPlayer *player_ptrs[4] = { &player, nullptr, nullptr, nullptr };
    DummyWorld world = { {}, player_ptrs, {}, 0 };
    DummyActor actor = { {}, &world };
    DummyMaster master = { {}, 50 };
    DummyAction action = { nullptr, &master, &actor, {}, 0.0f, 0.0f, {}, 0 };

    g_mock_1378c0_return = 5;
    func_00270A20((ActionRebind*)&action, 9);
    assert(g_func_270BA0_called == 0 && action.m_field15A == 9);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_mode_7_non_50_early_exit(); test_status_8_rewrite_and_self_player();
        test_direct_flag_15_statuses(); test_tile_and_zone_override();
        test_status_field_write_on_non_15();
        return 0;
    }
    int t = atoi(argv[1]);
    if (t == 0) test_mode_7_non_50_early_exit();
    if (t == 1) test_status_8_rewrite_and_self_player();
    if (t == 2) test_direct_flag_15_statuses();
    if (t == 3) test_tile_and_zone_override();
    if (t == 4) test_status_field_write_on_non_15();
    return 0;
}
