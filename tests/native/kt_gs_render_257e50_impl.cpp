#include <cstdint>

extern "C" {

static uint32_t s_mock_kt_gs_render_257e50_called = 0;

void func_00257E50(void) {
    s_mock_kt_gs_render_257e50_called++;
}

uint32_t get_mock_kt_gs_render_257e50_called(void) {
    return s_mock_kt_gs_render_257e50_called;
}

void reset_mock_kt_gs_render_257e50_called(void) {
    s_mock_kt_gs_render_257e50_called = 0;
}

}
