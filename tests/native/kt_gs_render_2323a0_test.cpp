#include "kt_gs_render_2323a0.h"
#include <cassert>

extern int g_called_2323a0;

int main() {
    g_called_2323a0 = 0;
    int res = func_002323A0(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_2323a0 == 1);
    assert(res == 1);
    return 0;
}
