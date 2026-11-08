#include <cstdint>

extern "C" {

static uint32_t s_mock_func_00257A90_called = 0;
static uint32_t s_mock_func_00257DC0_called = 0;

void func_00257A90(void) {
    s_mock_func_00257A90_called++;
}

void func_00257DC0(void) {
    s_mock_func_00257DC0_called++;
}

uint32_t get_mock_func_00257A90_called(void) {
    return s_mock_func_00257A90_called;
}

uint32_t get_mock_func_00257DC0_called(void) {
    return s_mock_func_00257DC0_called;
}

void reset_mock_kt_gs_render_257a90_called(void) {
    s_mock_func_00257A90_called = 0;
    s_mock_func_00257DC0_called = 0;
}

}
