#include "kt_gs_render_22efe0.h"
#include <cassert>

extern int g_called_22efe0;

int main() {
    g_called_22efe0 = 0;
    int res = func_0022EFE0(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_22efe0 == 1);
    assert(res == 1);
    return 0;
}
