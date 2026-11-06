#include "kt_gs_render_22f950.h"
#include <cassert>

extern int g_called_22f950;

int main() {
    g_called_22f950 = 0;
    int res = func_0022F950(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_22f950 == 1);
    assert(res == 1);
    return 0;
}
