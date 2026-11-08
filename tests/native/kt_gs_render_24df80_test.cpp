#include <cassert>
#include "kt_gs_render_24df80.h"

extern "C" int kt_gs_render_24df80_get_call_count(void);

int main() {
    assert(kt_gs_render_24df80_get_call_count() == 0);
    func_0024DF80();
    assert(kt_gs_render_24df80_get_call_count() == 1);
    func_0024DF80();
    assert(kt_gs_render_24df80_get_call_count() == 2);
    return 0;
}
