#include <cassert>
#include <cstdint>
#include "kt_gs_render_257dd0.h"

extern "C" {
uint32_t get_mock_func_00257DD0_called(void);
uint32_t get_mock_func_00257E40_called(void);
void reset_mock_kt_gs_render_257dd0_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_257dd0_called();
    assert(get_mock_func_00257DD0_called() == 0);
    assert(get_mock_func_00257E40_called() == 0);

    func_00257DD0();
    assert(get_mock_func_00257DD0_called() == 1);
    assert(get_mock_func_00257E40_called() == 0);

    func_00257E40();
    assert(get_mock_func_00257DD0_called() == 1);
    assert(get_mock_func_00257E40_called() == 1);

    return 0;
}
