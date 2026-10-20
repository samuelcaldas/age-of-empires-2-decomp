#include "render_manager_status_test_support.h"
#include <cassert>

void test_status_dispatch_order_and_arguments() {
    RenderManagerStatus manager = {};
    int object = 123;
    manager.field_1600 = &object;
    reset_mock_status();
    func_00189e00(&manager, 5);
    func_00189e40(&manager);
    assert(g_mock_status.last_19a1e0_ptr == &object);
    assert(g_mock_status.last_19a1e0_arg == 5);
    assert(g_mock_status.last_19a1d0_ptr == &object);
    assert(g_mock_status.last_19a1d0_arg == 5);
    assert(g_mock_status.last_19a1f0_ptr == &object);
    assert_call_order({StatusCall::Func19A1E0, StatusCall::Func19A1D0,
                       StatusCall::Func19A1F0});
}

void test_status_dispatch_reloads_field_1600() {
    RenderManagerStatus manager = {};
    int original_object = 1;
    int replacement_object = 2;
    manager.field_1600 = &original_object;
    reset_mock_status();
    g_mock_status.field_1600_slot_to_mutate = &manager.field_1600;
    g_mock_status.field_1600_value_after_19a1e0 = &replacement_object;
    func_00189e00(&manager, 5);
    assert(g_mock_status.last_19a1e0_ptr == &original_object);
    assert(g_mock_status.last_19a1e0_arg == 5);
    assert(g_mock_status.last_19a1d0_ptr == &replacement_object);
    assert(g_mock_status.last_19a1d0_arg == 5);
    assert(manager.field_1600 == &replacement_object);
    assert_call_order({StatusCall::Func19A1E0, StatusCall::Func19A1D0});
}

void test_status_dispatch_forwards_null_field() {
    RenderManagerStatus manager = {};
    reset_mock_status();
    func_00189e00(&manager, 5);
    func_00189e40(&manager);
    assert(g_mock_status.last_19a1e0_ptr == nullptr);
    assert(g_mock_status.last_19a1d0_ptr == nullptr);
    assert(g_mock_status.last_19a1f0_ptr == nullptr);
    assert_call_order({StatusCall::Func19A1E0, StatusCall::Func19A1D0,
                       StatusCall::Func19A1F0});
}

void test_status_empty_stubs() {
    reset_mock_status();
    func_00189e50();
    func_00189e60();
    assert(g_mock_status.call_count == 0);
}
