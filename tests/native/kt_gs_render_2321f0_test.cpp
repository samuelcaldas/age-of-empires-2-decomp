#include "kt_gs_render_2321f0.h"
#include <cassert>

extern int g_called_2321f0;

int main() {
    g_called_2321f0 = 0;
    int res = func_002321F0(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_2321f0 == 1);
    assert(res == 1);
    return 0;
}
