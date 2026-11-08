#include <cassert>
#include <cstdint>
#include "kt_gs_render_2560a0.h"

extern "C" {
uint32_t get_mock_kt_gs_render_2560a0_called(void);
void reset_mock_kt_gs_render_2560a0_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_2560a0_called();
    assert(get_mock_kt_gs_render_2560a0_called() == 0);

    func_002560A0();
    assert(get_mock_kt_gs_render_2560a0_called() == 1);

    func_002560A0();
    assert(get_mock_kt_gs_render_2560a0_called() == 2);

    return 0;
}
