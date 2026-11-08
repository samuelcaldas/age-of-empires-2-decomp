#include <cstdint>

extern "C" {

static uint32_t s_mock_kt_gs_render_256050_called = 0;

void func_00256050(void) {
    s_mock_kt_gs_render_256050_called++;
}

uint32_t get_mock_kt_gs_render_256050_called(void) {
    return s_mock_kt_gs_render_256050_called;
}

void reset_mock_kt_gs_render_256050_called(void) {
    s_mock_kt_gs_render_256050_called = 0;
}

}
