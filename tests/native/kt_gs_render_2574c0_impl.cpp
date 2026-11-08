#include <cstdint>

extern "C" {

static uint32_t s_mock_kt_gs_render_2574c0_called = 0;

void func_002574C0(void) {
    s_mock_kt_gs_render_2574c0_called++;
}

uint32_t get_mock_kt_gs_render_2574c0_called(void) {
    return s_mock_kt_gs_render_2574c0_called;
}

void reset_mock_kt_gs_render_2574c0_called(void) {
    s_mock_kt_gs_render_2574c0_called = 0;
}

}
