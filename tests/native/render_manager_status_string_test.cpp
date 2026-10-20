#include "render_manager_status_test_support.h"
#include <cassert>
#include <cstring>

void test_status_string_contract_and_shared_buffer() {
    RenderManagerStatus manager = {};
    char alternate_return[16] = "alternate";
    reset_mock_status();
    g_mock_status.func_191050_ret = 1;
    g_mock_status.get_string_return_override = alternate_return;
    char *first = func_00189c80(&manager, 0);
    assert(first == D_00568560);
    assert(first != alternate_return);
    assert(g_mock_status.last_get_string_return == alternate_return);
    assert(g_mock_status.last_get_string_id == 0x4B1);
    assert(g_mock_status.last_get_string_dest == D_00568560);
    assert(g_mock_status.last_get_string_max_len == 32);
    assert(std::strcmp(first, "Str_4B1") == 0);
    assert_call_order({StatusCall::Func191050, StatusCall::GetString});

    g_mock_status.func_191050_ret = 0;
    char *second = func_00189c80(&manager, 0);
    assert(second == first);
    assert(std::strcmp(first, "Str_4B2") == 0);
    assert(g_mock_status.last_get_string_return == alternate_return);
    assert(g_mock_status.last_get_string_id == 0x4B2);
    assert(g_mock_status.last_get_string_dest == D_00568560);
    assert(g_mock_status.last_get_string_max_len == 32);
    assert(g_mock_status.count_get_string == 2);
    assert_call_order({StatusCall::Func191050, StatusCall::GetString,
                       StatusCall::Func191050, StatusCall::Func190FF0,
                       StatusCall::GetString});
}
