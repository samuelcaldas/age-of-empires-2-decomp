#include "kt_gs_render_22f520.h"
#include <cassert>

extern int g_called_22f520;

int main() {
    g_called_22f520 = 0;
    int res = func_0022F520(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_22f520 == 1);
    assert(res == 1);
    return 0;
}
