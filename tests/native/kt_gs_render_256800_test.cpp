#include <cassert>
#include <cstdint>
#include "kt_gs_render_256800.h"

extern "C" {
uint32_t get_mock_kt_gs_render_256800_called(void);
void reset_mock_kt_gs_render_256800_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_256800_called();
    assert(get_mock_kt_gs_render_256800_called() == 0);

    func_00256800();
    assert(get_mock_kt_gs_render_256800_called() == 1);

    func_00256800();
    assert(get_mock_kt_gs_render_256800_called() == 2);

    return 0;
}
