#include <cassert>
#include "kt_gs_render_2507b0.h"

extern "C" int kt_gs_render_2507b0_get_call_count(void);

int main() {
    assert(kt_gs_render_2507b0_get_call_count() == 0);
    func_002507B0();
    assert(kt_gs_render_2507b0_get_call_count() == 1);
    return 0;
}
