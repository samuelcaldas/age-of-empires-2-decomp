#include <cassert>
#include <cstdint>
#include "kt_gs_render_255990.h"

extern "C" {
uint32_t get_mock_kt_gs_render_255990_called(void);
void reset_mock_kt_gs_render_255990_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_255990_called();
    assert(get_mock_kt_gs_render_255990_called() == 0);

    func_00255990();
    assert(get_mock_kt_gs_render_255990_called() == 1);

    func_00255990();
    assert(get_mock_kt_gs_render_255990_called() == 2);

    return 0;
}
