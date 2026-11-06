#include "kt_gs_render_22f2f0.h"
#include <cassert>

extern int g_called_22f2f0;

int main() {
    g_called_22f2f0 = 0;
    int res = func_0022F2F0(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_22f2f0 == 1);
    assert(res == 1);
    return 0;
}
