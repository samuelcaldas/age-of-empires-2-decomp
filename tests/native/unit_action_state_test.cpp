#include "unit_action_state_fixture.h"

// Case 0: func_00268590 index traversal
static void test_index_traversal() {
    init_mock_vtable();
    ActionMock parent;
    ActionMock child0;
    ActionMock child1;
    ActionMock child2;

    parent.m_field20 = &child0;
    child0.m_field20 = &child1;
    child1.m_field20 = &child2;
    child2.m_field20 = nullptr;

    ActionRebind *p = (ActionRebind*)&parent;
    assert(func_00268590(p, 0) == (ActionRebind*)&child0);
    assert(func_00268590(p, 1) == (ActionRebind*)&child1);
    assert(func_00268590(p, 2) == (ActionRebind*)&child2);
    assert(func_00268590(p, 3) == nullptr);
    assert(func_00268590(p, 99) == nullptr);
}

// Case 1: func_002687C0 capacity check at field4 + 1
static void test_capacity_offset() {
    init_mock_vtable();
    ActionMock parent;
    ActionMock child0;
    parent.m_field20 = &child0;

    DummyEntityData ent;
    memset(&ent, 0, sizeof(ent));
    ent.m_capacity = 2;
    parent.m_field4 = &ent;

    ActionRebind *p = (ActionRebind*)&parent;
    g_func_268500_ret = 1; // func_00268530 returns count = 1
    assert(func_002687C0(p) == 1);

    ent.m_capacity = 1;
    assert(func_002687C0(p) == 0);

    ent.m_capacity = 0;
    assert(func_002687C0(p) == 0);
}

// Case 2: func_00268610 filter child actions by state, entity attributes, and bounds
static void test_filter_children() {
    init_mock_vtable();
    ActionMock parent;
    ActionMock child0;
    ActionMock child1;

    DummyEntityData ent0;
    memset(&ent0, 0, sizeof(ent0));
    ent0.m_field8 = 100;
    ent0.m_fieldE = 200;
    ent0.m_field74 = 55;

    DummyEntityData ent1;
    memset(&ent1, 0, sizeof(ent1));
    ent1.m_field8 = 100;
    ent1.m_fieldE = 300;
    ent1.m_field74 = 55;

    parent.m_field20 = &child0;
    child0.m_field20 = &child1;
    child1.m_field20 = nullptr;

    child0.m_field4 = &ent0;
    child0.m_field39 = 2;
    child0.m_x = 10.0f;
    child0.m_y = 20.0f;

    child1.m_field4 = &ent1;
    child1.m_field39 = 3;
    child1.m_x = 50.0f;
    child1.m_y = 60.0f;

    ActionRebind *p = (ActionRebind*)&parent;
    ActionRebind *out[10] = {nullptr};

    g_func_268500_ret = 0;
    assert(func_00268610(p, -1, -1, -1, -1, -1, -1, -1, -1, out) == 0);

    g_func_268500_ret = 1;
    int count = func_00268610(p, -1, -1, 2, -1, -1, -1, -1, -1, out);
    assert(count == 1);
    assert(out[0] == (ActionRebind*)&child0);

    count = func_00268610(p, -1, -1, 3, -1, -1, -1, -1, -1, out);
    assert(count == 1);
    assert(out[0] == (ActionRebind*)&child1);

    count = func_00268610(p, 100, -1, -1, -1, -1, -1, -1, -1, out);
    assert(count == 2);
    assert(out[0] == (ActionRebind*)&child0);
    assert(out[1] == (ActionRebind*)&child1);

    count = func_00268610(p, -1, -1, -1, 0, 0, 25, 25, -1, out);
    assert(count == 1);
    assert(out[0] == (ActionRebind*)&child0);
}

// Case 3: func_002685C0 while loop calling Method58 until 3-child list empty
static void test_child_detachment_loop() {
    init_mock_vtable();
    ActionMock parent;
    ActionMock child0;
    ActionMock child1;
    ActionMock child2;

    parent.m_field20 = &child0;
    child0.m_field20 = &child1;
    child1.m_field20 = &child2;
    child2.m_field20 = nullptr;

    child0.m_parent = &parent;
    child1.m_parent = &parent;
    child2.m_parent = &parent;

    g_func_268500_ret = 1;
    g_method58_called = 0;
    for (int i = 0; i < 8; ++i) g_m58_history[i] = nullptr;

    ActionRebind *p = (ActionRebind*)&parent;
    func_002685C0(p);

    assert(g_method58_called == 3);
    assert(g_m58_history[0] == (void*)&child0);
    assert(g_m58_history[1] == (void*)&child1);
    assert(g_m58_history[2] == (void*)&child2);
    assert(parent.m_field20 == nullptr);
}

// Case 4: func_00268530 guard behavior (0 => 0, non-zero => counts children)
static void test_child_counter_guard() {
    init_mock_vtable();
    ActionMock parent;
    ActionMock child0;
    ActionMock child1;
    parent.m_field20 = &child0;
    child0.m_field20 = &child1;
    child1.m_field20 = nullptr;

    ActionRebind *p = (ActionRebind*)&parent;

    g_func_268500_ret = 1;
    assert(func_00268530(p) == 2);

    g_func_268500_ret = 0;
    assert(func_00268530(p) == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_index_traversal();
        test_capacity_offset();
        test_filter_children();
        test_child_detachment_loop();
        test_child_counter_guard();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_index_traversal(); break;
        case 1: test_capacity_offset(); break;
        case 2: test_filter_children(); break;
        case 3: test_child_detachment_loop(); break;
        case 4: test_child_counter_guard(); break;
        default: return 1;
    }
    return 0;
}
