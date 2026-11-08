#include <cassert>
#include "kt_gs_render_24e010.h"

extern "C" int kt_gs_render_24e010_get_call_count(void);

int main() {
    assert(kt_gs_render_24e010_get_call_count() == 0);
    func_0024E010();
    assert(kt_gs_render_24e010_get_call_count() == 1);
    return 0;
}
