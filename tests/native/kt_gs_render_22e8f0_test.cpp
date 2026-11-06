#include "kt_gs_render_22e8f0.h"
#include <cassert>

extern int g_called_22e8f0;

int main() {
    g_called_22e8f0 = 0;
    int res = func_0022E8F0(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_22e8f0 == 1);
    assert(res == 1);
    return 0;
}
