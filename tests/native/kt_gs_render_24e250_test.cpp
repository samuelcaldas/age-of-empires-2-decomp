#include <cassert>
#include "kt_gs_render_24e250.h"

extern "C" int kt_gs_render_24e250_get_call_count(void);

int main() {
    assert(kt_gs_render_24e250_get_call_count() == 0);
    func_0024E250();
    assert(kt_gs_render_24e250_get_call_count() == 1);
    func_0024E260();
    assert(kt_gs_render_24e250_get_call_count() == 2);
    func_0024E270();
    assert(kt_gs_render_24e250_get_call_count() == 3);
    return 0;
}
