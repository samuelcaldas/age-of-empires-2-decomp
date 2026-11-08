#include <cassert>
#include "kt_gs_render_251b70.h"

extern "C" int kt_gs_render_251b70_get_call_count(void);

int main() {
    assert(kt_gs_render_251b70_get_call_count() == 0);
    func_00251B70();
    assert(kt_gs_render_251b70_get_call_count() == 1);
    return 0;
}
