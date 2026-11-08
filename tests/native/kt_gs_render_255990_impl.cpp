#include <cstdint>

extern "C" {

static uint32_t s_mock_kt_gs_render_255990_called = 0;

void func_00255990(void) {
    s_mock_kt_gs_render_255990_called++;
}

uint32_t get_mock_kt_gs_render_255990_called(void) {
    return s_mock_kt_gs_render_255990_called;
}

void reset_mock_kt_gs_render_255990_called(void) {
    s_mock_kt_gs_render_255990_called = 0;
}

}
