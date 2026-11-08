#include <cassert>
#include <cstdint>
#include "kt_gs_render_255850.h"

extern "C" {
uint32_t get_mock_kt_gs_render_255850_called(void);
void reset_mock_kt_gs_render_255850_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_255850_called();
    assert(get_mock_kt_gs_render_255850_called() == 0);

    func_00255850();
    assert(get_mock_kt_gs_render_255850_called() == 1);

    func_00255850();
    assert(get_mock_kt_gs_render_255850_called() == 2);

    return 0;
}
