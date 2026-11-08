#include <cstdint>

extern "C" {

static uint32_t s_mock_func_00257DD0_called = 0;
static uint32_t s_mock_func_00257E40_called = 0;

void func_00257DD0(void) {
    s_mock_func_00257DD0_called++;
}

void func_00257E40(void) {
    s_mock_func_00257E40_called++;
}

uint32_t get_mock_func_00257DD0_called(void) {
    return s_mock_func_00257DD0_called;
}

uint32_t get_mock_func_00257E40_called(void) {
    return s_mock_func_00257E40_called;
}

void reset_mock_kt_gs_render_257dd0_called(void) {
    s_mock_func_00257DD0_called = 0;
    s_mock_func_00257E40_called = 0;
}

}
