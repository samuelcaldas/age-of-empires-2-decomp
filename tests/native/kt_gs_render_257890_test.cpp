#include <cassert>
#include <cstdint>
#include "kt_gs_render_257890.h"

extern "C" {
uint32_t get_mock_kt_gs_render_257890_called(void);
void reset_mock_kt_gs_render_257890_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_257890_called();
    assert(get_mock_kt_gs_render_257890_called() == 0);

    func_00257890();
    assert(get_mock_kt_gs_render_257890_called() == 1);

    func_00257890();
    assert(get_mock_kt_gs_render_257890_called() == 2);

    return 0;
}
