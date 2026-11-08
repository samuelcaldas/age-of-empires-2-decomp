#include <cassert>
#include <cstdint>
#include "kt_gs_render_2576d0.h"

extern "C" {
uint32_t get_mock_func_002576D0_called(void);
uint32_t get_mock_func_00257880_called(void);
void reset_mock_kt_gs_render_2576d0_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_2576d0_called();
    assert(get_mock_func_002576D0_called() == 0);
    assert(get_mock_func_00257880_called() == 0);

    func_002576D0();
    assert(get_mock_func_002576D0_called() == 1);
    assert(get_mock_func_00257880_called() == 0);

    func_00257880();
    assert(get_mock_func_002576D0_called() == 1);
    assert(get_mock_func_00257880_called() == 1);

    return 0;
}
