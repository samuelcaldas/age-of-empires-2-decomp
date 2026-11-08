#include <cstdint>

extern "C" {

static uint32_t s_mock_kt_gs_render_255bf0_called = 0;

void func_00255BF0(void) {
    s_mock_kt_gs_render_255bf0_called++;
}

uint32_t get_mock_kt_gs_render_255bf0_called(void) {
    return s_mock_kt_gs_render_255bf0_called;
}

void reset_mock_kt_gs_render_255bf0_called(void) {
    s_mock_kt_gs_render_255bf0_called = 0;
}

}
