#include "kt_gs_render_22f490.h"
#include <cassert>

extern int g_called_22f490;

int main() {
    g_called_22f490 = 0;
    int res = func_0022F490(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_22f490 == 1);
    assert(res == 1);
    return 0;
}
