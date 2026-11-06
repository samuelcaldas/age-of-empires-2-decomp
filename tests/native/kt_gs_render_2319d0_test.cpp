#include "kt_gs_render_2319d0.h"
#include <cassert>

extern int g_called_2319d0;

int main() {
    g_called_2319d0 = 0;
    int res = func_002319D0(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_2319d0 == 1);
    assert(res == 1);
    return 0;
}
