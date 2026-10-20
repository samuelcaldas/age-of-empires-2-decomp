#include "render_manager_status_test_support.h"
#include <cassert>

static char *query_field_status(unsigned int value, unsigned int threshold) {
    RenderManagerStatus manager = {};
    reset_mock_status();
    g_mock_status.func_190FF0_ret = 1;
    manager.field_2038[0] = value;
    manager.field_10C8 = threshold;
    return func_00189c80(&manager, 0);
}

static void assert_selected_status(char *result, int expected_id) {
    assert(result == D_00568560);
    assert(g_mock_status.last_get_string_id == expected_id);
    assert_call_order({StatusCall::Func191050, StatusCall::Func190FF0,
                       StatusCall::GetString});
}

void test_status_value_zero() {
    assert_selected_status(query_field_status(0, 5), 0x4B3);
}

void test_status_value_three() {
    assert_selected_status(query_field_status(3, 5), 0x4B3);
}

void test_status_value_four() {
    assert_selected_status(query_field_status(4, 5), 0x4B4);
}

void test_status_below_threshold() {
    assert_selected_status(query_field_status(5, 6), 0x4B4);
}

void test_status_equal_threshold() {
    assert_selected_status(query_field_status(6, 6), 0x4B0);
}

void test_status_above_threshold() {
    assert_selected_status(query_field_status(7, 6), 0x4B0);
}

void test_status_unsigned_high_value() {
    assert_selected_status(query_field_status(0x80000000u, 0x7FFFFFFFu), 0x4B0);
}

void test_status_unsigned_high_threshold() {
    assert_selected_status(query_field_status(0x7FFFFFFFu, 0x80000000u), 0x4B4);
}
