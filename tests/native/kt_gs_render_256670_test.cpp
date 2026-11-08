#include <cassert>
#include <cstdint>
#include "kt_gs_render_256670.h"

extern "C" {
uint32_t get_mock_kt_gs_render_256670_called(void);
void reset_mock_kt_gs_render_256670_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_256670_called();
    assert(get_mock_kt_gs_render_256670_called() == 0);

    func_00256670();
    assert(get_mock_kt_gs_render_256670_called() == 1);

    func_00256670();
    assert(get_mock_kt_gs_render_256670_called() == 2);

    return 0;
}
