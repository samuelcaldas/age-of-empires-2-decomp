#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_clear_area_fixture.h"

static void reset_test_state() {
    g_func_123350_called = 0;
    g_func_26ad20_ret = 1;
    g_cleared_entities.clear();
}

static DummyCell s_row[20] = {};
static DummyCell *s_grid_rows[20] = {};

static void setup_cell(void **ent_list, int count) {
    for (int i = 0; i < 20; ++i) {
        s_grid_rows[i] = s_row;
        s_row[i] = {};
    }
    s_row[10].m_count = (unsigned char)count;
    s_row[10].m_entities = ent_list;
}

static void test_clear_overlapping_type_80_entity() {
    reset_test_state();
    DummyClearMaster master = { 50, {}, 2.0f, 2.0f };
    DummyClearMaster tree_master = { 80, {}, 1.0f, 1.0f };
    DummyClearEntity tree = { nullptr, &tree_master, {}, 10.5f, 10.5f };
    void *ent_list[1] = { &tree };
    setup_cell(ent_list, 1);

    DummySpatial spatial = { {}, 20, 20, {}, s_grid_rows };
    DummyPlayerWorld pworld = { {}, &spatial };
    DummyClearWorld world = {};
    world.m_player_world = &pworld;

    DummyClearAction action = { nullptr, &master, &world, {}, 10.0f, 10.0f };
    func_00271220((ActionRebind*)&action);
    assert(g_cleared_entities.size() >= 1);
    assert(g_cleared_entities[0] == &tree);
}

static void test_ignore_non_type_80_entity() {
    reset_test_state();
    DummyClearMaster master = { 50, {}, 2.0f, 2.0f };
    DummyClearMaster villager_master = { 70, {}, 1.0f, 1.0f };
    DummyClearEntity villager = { nullptr, &villager_master, {}, 10.5f, 10.5f };
    void *ent_list[1] = { &villager };
    setup_cell(ent_list, 1);

    DummySpatial spatial = { {}, 20, 20, {}, s_grid_rows };
    DummyPlayerWorld pworld = { {}, &spatial };
    DummyClearWorld world = {};
    world.m_player_world = &pworld;

    DummyClearAction action = { nullptr, &master, &world, {}, 10.0f, 10.0f };
    func_00271220((ActionRebind*)&action);
    assert(g_cleared_entities.empty());
}

static void test_ignore_flag_check_failure() {
    reset_test_state();
    g_func_26ad20_ret = 0;
    DummyClearMaster master = { 50, {}, 2.0f, 2.0f };
    DummyClearMaster tree_master = { 80, {}, 1.0f, 1.0f };
    DummyClearEntity tree = { nullptr, &tree_master, {}, 10.5f, 10.5f };
    void *ent_list[1] = { &tree };
    setup_cell(ent_list, 1);

    DummySpatial spatial = { {}, 20, 20, {}, s_grid_rows };
    DummyPlayerWorld pworld = { {}, &spatial };
    DummyClearWorld world = {};
    world.m_player_world = &pworld;

    DummyClearAction action = { nullptr, &master, &world, {}, 10.0f, 10.0f };
    func_00271220((ActionRebind*)&action);
    assert(g_cleared_entities.empty());
}

static void test_ignore_out_of_radius_entity() {
    reset_test_state();
    DummyClearMaster master = { 50, {}, 1.0f, 1.0f };
    DummyClearMaster tree_master = { 80, {}, 1.0f, 1.0f };
    DummyClearEntity tree = { nullptr, &tree_master, {}, 15.0f, 15.0f };
    void *ent_list[1] = { &tree };
    setup_cell(ent_list, 1);

    DummySpatial spatial = { {}, 20, 20, {}, s_grid_rows };
    DummyPlayerWorld pworld = { {}, &spatial };
    DummyClearWorld world = {};
    world.m_player_world = &pworld;

    DummyClearAction action = { nullptr, &master, &world, {}, 10.0f, 10.0f };
    func_00271220((ActionRebind*)&action);
    assert(g_cleared_entities.empty());
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_clear_overlapping_type_80_entity(); test_ignore_non_type_80_entity();
        test_ignore_flag_check_failure(); test_ignore_out_of_radius_entity();
        return 0;
    }
    int t = atoi(argv[1]);
    if (t == 0) test_clear_overlapping_type_80_entity();
    if (t == 1) test_ignore_non_type_80_entity();
    if (t == 2) test_ignore_flag_check_failure();
    if (t == 3) test_ignore_out_of_radius_entity();
    return 0;
}
