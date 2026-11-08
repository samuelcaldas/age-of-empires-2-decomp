#include <cassert>
#include "kt_gs_render_24fd90.h"

extern "C" int kt_gs_render_24fd90_get_call_count(void);

int main() {
    assert(kt_gs_render_24fd90_get_call_count() == 0);
    func_0024FD90();
    assert(kt_gs_render_24fd90_get_call_count() == 1);
    func_0024FDA0();
    assert(kt_gs_render_24fd90_get_call_count() == 2);
    func_0024FDB0();
    assert(kt_gs_render_24fd90_get_call_count() == 3);
    return 0;
}
