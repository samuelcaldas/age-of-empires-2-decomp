#include "render_manager_status_test_support.h"
#include <cassert>
#include <cstring>

void test_status_4b1_precedence() {
    RenderManagerStatus manager = {};
    reset_mock_status();
    g_mock_status.func_191050_ret = -1;
    char *result = func_00189c80(&manager, 0);
    assert(result == D_00568560);
    assert(std::strcmp(result, "Str_4B1") == 0);
    assert(g_mock_status.last_191050_self == &manager);
    assert(g_mock_status.last_191050_arg == 0);
    assert(g_mock_status.count_190FF0 == 0);
    assert(g_mock_status.last_get_string_id == 0x4B1);
    assert_call_order({StatusCall::Func191050, StatusCall::GetString});
}

void test_status_4b2_precedence() {
    RenderManagerStatus manager = {};
    reset_mock_status();
    g_mock_status.func_190FF0_ret = 0;
    char *result = func_00189c80(&manager, 0);
    assert(result == D_00568560);
    assert(std::strcmp(result, "Str_4B2") == 0);
    assert(g_mock_status.last_191050_self == &manager);
    assert(g_mock_status.last_191050_arg == 0);
    assert(g_mock_status.last_190FF0_self == &manager);
    assert(g_mock_status.last_190FF0_arg == 0);
    assert(g_mock_status.last_get_string_id == 0x4B2);
    assert_call_order({StatusCall::Func191050, StatusCall::Func190FF0,
                       StatusCall::GetString});
}
