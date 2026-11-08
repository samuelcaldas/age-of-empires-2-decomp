#include <cassert>
#include "kt_gs_render_250290.h"

extern "C" int kt_gs_render_250290_get_call_count(void);

int main() {
    assert(kt_gs_render_250290_get_call_count() == 0);
    func_00250290();
    assert(kt_gs_render_250290_get_call_count() == 1);
    return 0;
}
