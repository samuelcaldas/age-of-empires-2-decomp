#include "unit_action_update_test_support.h"

void test_func_00268500() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    mock.m_field1C = -1;
    mock.m_field20 = 10;
    assert(func_00268500(act) == 0);

    mock.m_field1C = 1;
    mock.m_field20 = 1;
    assert(func_00268500(act) == 0);

    mock.m_field1C = 0;
    mock.m_field20 = 0;
    assert(func_00268500(act) == 0);

    mock.m_field1C = 0;
    mock.m_field20 = 1;
    assert(func_00268500(act) != 0);

    mock.m_field1C = 0;
    mock.m_field20 = -1;
    assert(func_00268500(act) != 0);
}

void test_func_002683F0() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    mock.m_field39 = 0;
    assert(func_002683F0(act) == 1);
    mock.m_field39 = 1;
    assert(func_002683F0(act) == 1);
    mock.m_field39 = 2;
    assert(func_002683F0(act) == 1);
    mock.m_field39 = 3;
    assert(func_002683F0(act) == 0);
}

void test_func_00268410() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    mock.m_field10 = 0;
    assert(func_00268410(act) == 0);

    mock.m_field10 = 5;
    mock.m_fieldC = (void*)0x1234;
    assert(func_00268410(act) == 42);

    mock.m_field10 = 5;
    mock.m_fieldC = 0;
    mock.m_field35 = 12;
    assert(func_00268410(act) == 84);
}

void test_func_00268200_dispatch() {
    init_mock_vtable();

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    mock.m_field39 = 1;

    char dummy_field4[200] = {0};
    dummy_field4[144] = 2;
    *(float*)&dummy_field4[28] = 5.0f;
    mock.m_field4 = dummy_field4;

    g_method30_called = 0;
    func_00268200(act, 3);
    assert(mock.m_field39 == 3);
    assert(g_method30_called == 1);

    g_method29_called = 0;
    func_00268200(act, 7);
    assert(mock.m_field39 == 7);
    assert(g_method29_called == 1);
}

void test_func_00268200_transitions() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    // 0 -> 1 must succeed
    mock.m_field39 = 0;
    func_00268200(act, 1);
    assert(mock.m_field39 == 1);

    // 1 -> 2 must succeed
    func_00268200(act, 2);
    assert(mock.m_field39 == 2);

    // 0 -> 2 must succeed
    mock.m_field39 = 0;
    func_00268200(act, 2);
    assert(mock.m_field39 == 2);

    // 2 -> 1 descending must fail (remain 2)
    func_00268200(act, 1);
    assert(mock.m_field39 == 2);

    // 2 -> 0 descending to zero must succeed
    func_00268200(act, 0);
    assert(mock.m_field39 == 0);

    // Same state 2 -> 2 no-op
    mock.m_field39 = 2;
    func_00268200(act, 2);
    assert(mock.m_field39 == 2);
}

void test_func_00268200_callbacks() {
    init_mock_vtable();

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    mock.m_world = (WorldExtended*)0xABCD;
    mock.m_field18 = 1;

    char dummy_field4[200] = {0};
    *(float*)&dummy_field4[28] = 10.0f; // radius > 0
    mock.m_field4 = dummy_field4;

    // Transition from state 2 to state >= 3 triggers Method62(world, 0, -1, 0) and Method61(world, 1, -1, 0)
    mock.m_field39 = 2;
    g_method62_called = 0;
    g_method61_called = 0;
    func_00268200(act, 3);
    assert(g_method62_called == 1);
    assert(g_last_m62_a2 == 0);
    assert(g_method61_called == 1);
    assert(g_last_m61_a2 == 1);

    // Transition from state < 7 to state 7 triggers Method62(world, 1, -1, 0)
    mock.m_field39 = 4;
    g_method62_called = 0;
    func_00268200(act, 7);
    assert(g_method62_called == 1);
    assert(g_last_m62_a2 == 1);
}
