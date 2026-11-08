#include <cassert>
#include <cstdint>
#include "kt_gs_render_257e50.h"

extern "C" {
uint32_t get_mock_kt_gs_render_257e50_called(void);
void reset_mock_kt_gs_render_257e50_called(void);
}

int main(void) {
    reset_mock_kt_gs_render_257e50_called();
    assert(get_mock_kt_gs_render_257e50_called() == 0);

    func_00257E50();
    assert(get_mock_kt_gs_render_257e50_called() == 1);

    func_00257E50();
    assert(get_mock_kt_gs_render_257e50_called() == 2);

    return 0;
}
