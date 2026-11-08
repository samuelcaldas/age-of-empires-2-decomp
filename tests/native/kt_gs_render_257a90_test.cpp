#include <cassert>
#include <cstdint>
#include "kt_gs_render_257a90.h"

extern "C" {
uint32_t get_mock_func_00257A90_called(void);
uint32_t get_mock_func_00257DC0_called(void);
void reset_mock_kt_gs_render_257a90_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_257a90_called();
    assert(get_mock_func_00257A90_called() == 0);
    assert(get_mock_func_00257DC0_called() == 0);

    func_00257A90();
    assert(get_mock_func_00257A90_called() == 1);
    assert(get_mock_func_00257DC0_called() == 0);

    func_00257DC0();
    assert(get_mock_func_00257A90_called() == 1);
    assert(get_mock_func_00257DC0_called() == 1);

    return 0;
}
