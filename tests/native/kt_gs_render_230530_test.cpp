#include "kt_gs_render_230530.h"
#include <cassert>

extern int g_called_230530;

int main() {
    g_called_230530 = 0;
    int res = func_00230530(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_230530 == 1);
    assert(res == 1);
    return 0;
}
