#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "unit_action_build_child_iterate_fixture.h"

static int g_func_278590_called = 0;
static int g_func_26F590_called = 0;
static float g_last_26F590_x = 0.0f;
static float g_last_26F590_y = 0.0f;
static int g_method58_called = 0;
static int g_method31_called = 0;

static std::vector<int> g_queried_indices;

static int g_mock_child_count = 0;
static ActionRebind *g_mock_children[8] = {};

extern "C" {
    void func_278590(void *self, int a1, int a2) {
        (void)self; (void)a1; (void)a2;
        g_func_278590_called++;
    }

    int func_00268530(ActionRebind *self) {
        (void)self;
        return g_mock_child_count;
    }

    ActionRebind* func_00268590(ActionRebind *self, int target_index) {
        (void)self;
        g_queried_indices.push_back(target_index);
        if (target_index >= 0 && target_index < g_mock_child_count) {
            return g_mock_children[target_index];
        }
        return nullptr;
    }

    int func_0026F590(ActionRebind *self, ActionRebind *child, float x, float y) {
        (void)self; (void)child;
        g_func_26F590_called++;
        g_last_26F590_x = x;
        g_last_26F590_y = y;
        return 1;
    }
}

static void mock_m58(void *c) {
    (void)c;
    g_method58_called++;
}

static void mock_m31(void *c) {
    (void)c;
    g_method31_called++;
}

static void *dummy_child_vtable[64] = {};

static void init_child_vtable() {
    memset(dummy_child_vtable, 0, sizeof(dummy_child_vtable));
    dummy_child_vtable[58] = (void*)mock_m58;
    dummy_child_vtable[31] = (void*)mock_m31;
}

static void reset_test_state() {
    g_func_278590_called = 0;
    g_func_26F590_called = 0;
    g_last_26F590_x = 0.0f;
    g_last_26F590_y = 0.0f;
    g_method58_called = 0;
    g_method31_called = 0;
    g_queried_indices.clear();
    g_mock_child_count = 0;
    memset(g_mock_children, 0, sizeof(g_mock_children));
}

// Case 0: a2 == 0 calls func_278590 and skips child iteration
static void test_flag_zero() {
    reset_test_state();
    init_child_vtable();
    DummyIterWorld world = {};
    DummyIterChild children[3] = {};
    for (int i = 0; i < 3; ++i) {
        children[i].m_world = &world;
        g_mock_children[i] = (ActionRebind*)&children[i];
    }
    g_mock_child_count = 3;
    char self_buf[512] = {};
    func_0026F910((ActionRebind*)self_buf, 1, 0);

    assert(g_func_278590_called == 1);
    assert(g_queried_indices.empty());
    assert(g_func_26F590_called == 0);
}

// Case 1: a2 != 0 iterates children in reverse (count - 1 down to 0)
static void test_reverse_iteration() {
    reset_test_state();
    init_child_vtable();
    DummyIterWorld world = {};
    world.m_player_index = 99;
    DummyIterChild children[3] = {};
    for (int i = 0; i < 3; ++i) {
        children[i].m_world = &world;
        g_mock_children[i] = (ActionRebind*)&children[i];
    }
    g_mock_child_count = 3;
    char self_buf[512] = {};
    func_0026F910((ActionRebind*)self_buf, 1, 1);

    assert(g_func_278590_called == 1);
    assert(g_queried_indices.size() == 3);
    assert(g_queried_indices[0] == 2 && g_queried_indices[1] == 1 && g_queried_indices[2] == 0);
}

// Case 2: Matching player index calls func_0026F590 with (-1.0f, -1.0f)
static void test_matching_player() {
    reset_test_state();
    init_child_vtable();
    DummyIterWorld world = {};
    world.m_player_index = 5;
    DummyIterChild child = {};
    child.vtable = dummy_child_vtable;
    child.m_world = &world;
    child.m_field1C = 0;
    g_mock_child_count = 1;
    g_mock_children[0] = (ActionRebind*)&child;
    char self_buf[512] = {};
    func_0026F910((ActionRebind*)self_buf, 5, 1);

    assert(g_func_26F590_called == 1);
    assert(g_last_26F590_x == -1.0f && g_last_26F590_y == -1.0f);
    assert(g_method58_called == 0 && g_method31_called == 0);
}

// Case 3: When child m_field1C != 0, dispatches Method58 and Method31
static void test_method_dispatch() {
    reset_test_state();
    init_child_vtable();
    DummyIterWorld world = {};
    world.m_player_index = 3;
    DummyIterChild child = {};
    child.vtable = dummy_child_vtable;
    child.m_world = &world;
    child.m_field1C = 1;
    g_mock_child_count = 1;
    g_mock_children[0] = (ActionRebind*)&child;
    char self_buf[512] = {};
    func_0026F910((ActionRebind*)self_buf, 3, 1);

    assert(g_func_26F590_called == 1);
    assert(g_method58_called == 1 && g_method31_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_flag_zero();
        test_reverse_iteration();
        test_matching_player();
        test_method_dispatch();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_flag_zero(); break;
        case 1: test_reverse_iteration(); break;
        case 2: test_matching_player(); break;
        case 3: test_method_dispatch(); break;
        default: return 1;
    }
    return 0;
}
