#include <cstdint>

extern "C" {

static uint32_t s_mock_func_002576D0_called = 0;
static uint32_t s_mock_func_00257880_called = 0;

void func_002576D0(void) {
    s_mock_func_002576D0_called++;
}

void func_00257880(void) {
    s_mock_func_00257880_called++;
}

uint32_t get_mock_func_002576D0_called(void) {
    return s_mock_func_002576D0_called;
}

uint32_t get_mock_func_00257880_called(void) {
    return s_mock_func_00257880_called;
}

void reset_mock_kt_gs_render_2576d0_called(void) {
    s_mock_func_002576D0_called = 0;
    s_mock_func_00257880_called = 0;
}

}
