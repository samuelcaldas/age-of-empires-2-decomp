#include <cassert>
#include <cstdint>
#include "kt_gs_render_255350.h"

extern "C" {
uint32_t get_mock_kt_gs_render_255350_called(void);
void reset_mock_kt_gs_render_255350_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_255350_called();
    assert(get_mock_kt_gs_render_255350_called() == 0);

    func_00255350();
    assert(get_mock_kt_gs_render_255350_called() == 1);

    func_00255350();
    assert(get_mock_kt_gs_render_255350_called() == 2);

    return 0;
}
