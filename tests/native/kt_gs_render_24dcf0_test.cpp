#include <cassert>
#include "kt_gs_render_24dcf0.h"

extern "C" int kt_gs_render_24dcf0_get_call_count(void);

int main() {
    assert(kt_gs_render_24dcf0_get_call_count() == 0);
    func_0024DCF0();
    assert(kt_gs_render_24dcf0_get_call_count() == 1);
    func_0024DCF0();
    assert(kt_gs_render_24dcf0_get_call_count() == 2);
    return 0;
}
