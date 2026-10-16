#include "unit_action_collision_fixture.h"

// Case 0: Guard conditions return 0
static void test_collision_guards() {
    init_mock_vtable();
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_field4[100] = {0};
    mock.m_field4 = dummy_field4;
    mock.m_field20 = nullptr;

    g_func_268500_ret = 0;
    assert(func_002697C0(act, 0) == 0);

    g_func_268500_ret = 1;
    assert(func_002697C0(act, 0) == 0);
}

// Case 1: Multi-child reverse traversal (count-1 down to 0) and full ABI arguments
static void test_multi_child_reverse_and_abi() {
    init_mock_vtable();
    ActionMock parent, child0, child1;
    ActionRebind *parent_act = (ActionRebind*)&parent;
    ActionRebind *child0_act = (ActionRebind*)&child0;
    ActionRebind *child1_act = (ActionRebind*)&child1;

    char dummy_parent_f4[100] = {0}, dummy_child0_f4[100] = {0}, dummy_child1_f4[100] = {0};
    *(float*)(dummy_parent_f4 + 0x20) = 1.5f; *(float*)(dummy_parent_f4 + 0x24) = 2.5f;
    *(float*)(dummy_child0_f4 + 0x20) = 3.5f; *(float*)(dummy_child0_f4 + 0x24) = 4.5f;
    *(float*)(dummy_child1_f4 + 0x20) = 5.5f; *(float*)(dummy_child1_f4 + 0x24) = 6.5f;

    parent.m_field4 = dummy_parent_f4;
    child0.m_field4 = dummy_child0_f4;
    child1.m_field4 = dummy_child1_f4;
    parent.m_x = 100.0f; parent.m_y = 200.0f; parent.m_z = 300.0f;

    // Real linked list: parent -> child0 -> child1
    parent.m_field20 = child0_act;
    child0.m_field20 = child1_act;
    child1.m_field20 = nullptr;

    g_func_268500_ret = 1;
    g_call_count = 0;
    for (int i = 0; i < 16; ++i) g_forced_helper_rets[i] = 1;

    int successes = func_002697C0(parent_act, 42);
    assert(successes == 2);
    // Child1 (count - 1) tested first, then child0 (0)
    assert(g_calls[0].child == (void*)child1_act && g_calls[0].self == (void*)parent_act);
    assert(g_calls[0].arg1 == 42 && g_calls[0].child_f4 == (void*)dummy_child1_f4);
    assert(g_calls[0].coord_x == 100.0f && g_calls[0].coord_y == 200.0f);
    assert(g_calls[0].ext_x == 1.5f && g_calls[0].ext_y == 2.5f);
    assert(g_calls[1].child == (void*)child0_act && g_calls[1].self == (void*)parent_act);
    assert(g_calls[1].arg1 == 42 && g_calls[1].child_f4 == (void*)dummy_child0_f4);
    assert(g_last_set_pos_self == (void*)child0_act && g_last_m15_self == (void*)child0_act);
    assert(g_last_m58_self == (void*)child0_act);
    assert(g_last_set_pos_self != (void*)parent_act && g_last_m15_self != (void*)parent_act);
    assert(g_last_m58_self != (void*)parent_act);
}

// Case 2: Candidate retry mechanism (candidate 2 fails, falls back to candidate 1)
static void test_candidate_retry() {
    init_mock_vtable();
    ActionMock parent, child0, child1;
    char dummy_f4[100] = {0};
    parent.m_field4 = dummy_f4; child0.m_field4 = dummy_f4; child1.m_field4 = dummy_f4;

    parent.m_field20 = (ActionRebind*)&child0;
    child0.m_field20 = (ActionRebind*)&child1;
    child1.m_field20 = nullptr;

    g_func_268500_ret = 1;
    g_call_count = 0;
    g_forced_helper_rets[0] = 1; // child1 candidate 1 succeeds
    g_forced_helper_rets[1] = 0; // child0 candidate 2 fails
    g_forced_helper_rets[2] = 1; // child0 candidate 1 succeeds

    int successes = func_002697C0((ActionRebind*)&parent, 0);
    assert(successes == 2 && g_call_count == 3);
    assert(g_calls[1].ret_val == 0 && g_calls[2].ret_val == 1);
}

// Case 3: All candidates fail -> returns 0, no methods dispatched
static void test_all_candidates_fail() {
    init_mock_vtable();
    ActionMock parent, child;
    char dummy_f4[100] = {0};
    parent.m_field4 = dummy_f4; child.m_field4 = dummy_f4;

    parent.m_field20 = (ActionRebind*)&child;
    child.m_field20 = nullptr;

    g_func_268500_ret = 1;
    g_call_count = 0;
    g_forced_helper_rets[0] = 0;
    g_method15_called = 0; g_method58_called = 0; g_method87_called = 0;

    int successes = func_002697C0((ActionRebind*)&parent, 0);
    assert(successes == 0 && g_method15_called == 0);
    assert(g_method58_called == 0 && g_method87_called == 0);
}

// Case 4: Double Method87 returns 2 distinct targets; store happens ONLY in 2nd
static void test_double_method87_distinct_targets() {
    init_mock_vtable();
    ActionMock parent, child;
    char dummy_f4[100] = {0};
    parent.m_field4 = dummy_f4; child.m_field4 = dummy_f4;

    parent.m_field20 = (ActionRebind*)&child;
    child.m_field20 = nullptr;

    memset(&g_inner1, 0, sizeof(g_inner1));
    memset(&g_inner2, 0, sizeof(g_inner2));
    g_func_268500_ret = 1;
    g_call_count = 0;
    g_forced_helper_rets[0] = 1;
    g_m87_return_sequence[0] = (void*)&g_inner1_ptr;
    g_m87_return_sequence[1] = (void*)&g_inner2_ptr;
    g_method87_called = 0;

    int successes = func_002697C0((ActionRebind*)&parent, 0);
    assert(successes == 1 && g_method87_called == 2);
    // Inner 1 untouched; Inner 2 received coordinates
    assert(g_inner1.m_pos_x == 0.0f && g_inner1.m_pos_y == 0.0f);
    assert(g_inner2.m_pos_x == 55.0f && g_inner2.m_pos_y == 66.0f);
    assert(g_last_m58_self == (void*)&child);
    assert(g_last_set_pos_self == (void*)&child && g_last_m15_self == (void*)&child);
    assert(g_last_set_pos_self != (void*)&parent && g_last_m15_self != (void*)&parent);
    assert(g_m87_self_history[0] == (void*)&child && g_m87_self_history[1] == (void*)&child);
}

// Case 5: Integrated state+collision with real linked children (no unconditional count stub)
static void test_integrated_state_collision() {
    init_mock_vtable();
    ActionMock parent, child0, child1;
    char dummy_f4[100] = {0};
    parent.m_field4 = dummy_f4; child0.m_field4 = dummy_f4; child1.m_field4 = dummy_f4;

    parent.m_field20 = &child0;
    child0.m_field20 = &child1;
    child1.m_field20 = nullptr;

    g_func_268500_ret = 1;
    g_call_count = 0;
    for (int i = 0; i < 16; ++i) g_forced_helper_rets[i] = 1;

    int successes = func_002697C0((ActionRebind*)&parent, 99);
    assert(successes == 2);
    assert(g_calls[0].child == (void*)&child1);
    assert(g_calls[1].child == (void*)&child0);

    // When func_00268500 returns 0, real count is 0 -> collision returns 0
    g_func_268500_ret = 0;
    assert(func_002697C0((ActionRebind*)&parent, 99) == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_collision_guards();
        test_multi_child_reverse_and_abi();
        test_candidate_retry();
        test_all_candidates_fail();
        test_double_method87_distinct_targets();
        test_integrated_state_collision();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_collision_guards(); break;
        case 1: test_multi_child_reverse_and_abi(); break;
        case 2: test_candidate_retry(); break;
        case 3: test_all_candidates_fail(); break;
        case 4: test_double_method87_distinct_targets(); break;
        case 5: test_integrated_state_collision(); break;
        default: return 1;
    }
    return 0;
}
