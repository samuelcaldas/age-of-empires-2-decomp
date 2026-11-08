#include <cassert>
#include <cstdint>
#include "kt_gs_render_256050.h"

extern "C" {
uint32_t get_mock_kt_gs_render_256050_called(void);
void reset_mock_kt_gs_render_256050_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_256050_called();
    assert(get_mock_kt_gs_render_256050_called() == 0);

    func_00256050();
    assert(get_mock_kt_gs_render_256050_called() == 1);

    func_00256050();
    assert(get_mock_kt_gs_render_256050_called() == 2);

    return 0;
}
