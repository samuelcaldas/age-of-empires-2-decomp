#include <cassert>
#include "kt_gs_render_251ec0.h"

extern "C" int kt_gs_render_251ec0_get_call_count(void);

int main() {
    assert(kt_gs_render_251ec0_get_call_count() == 0);
    func_00251EC0();
    assert(kt_gs_render_251ec0_get_call_count() == 1);
    return 0;
}
