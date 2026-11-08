#include <cassert>
#include <cstdio>
#include <cstdint>
#include "kt_gs_render_252c90.h"

extern "C" {
uint32_t test_get_call_count_252c90();
uint32_t test_get_call_count_252ca0();
uint32_t test_get_call_count_252ce0();
uint32_t test_get_call_count_252cf0();
uint32_t test_get_call_count_252d00();
uint32_t test_get_call_count_252d10();
uint32_t test_get_call_count_252d40();
}

int main() {
    assert(test_get_call_count_252c90() == 0);
    func_00252C90();
    assert(test_get_call_count_252c90() == 1);

    assert(test_get_call_count_252ca0() == 0);
    func_00252CA0();
    assert(test_get_call_count_252ca0() == 1);

    assert(test_get_call_count_252ce0() == 0);
    func_00252CE0();
    assert(test_get_call_count_252ce0() == 1);

    assert(test_get_call_count_252cf0() == 0);
    func_00252CF0();
    assert(test_get_call_count_252cf0() == 1);

    assert(test_get_call_count_252d00() == 0);
    func_00252D00();
    assert(test_get_call_count_252d00() == 1);

    assert(test_get_call_count_252d10() == 0);
    func_00252D10();
    assert(test_get_call_count_252d10() == 1);

    assert(test_get_call_count_252d40() == 0);
    func_00252D40();
    assert(test_get_call_count_252d40() == 1);

    printf("kt_gs_render_252c90 native tests passed successfully.\n");
    return 0;
}
