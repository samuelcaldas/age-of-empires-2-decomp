#include "kt_gs_render_232020.h"
#include <cassert>

extern int g_called_232020;
extern int g_called_2320b0;

int main() {
    g_called_232020 = 0;
    g_called_2320b0 = 0;
    int res1 = func_00232020(nullptr, nullptr, nullptr, nullptr);
    int res2 = func_002320B0(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_232020 == 1);
    assert(g_called_2320b0 == 1);
    assert(res1 == 1);
    assert(res2 == 1);
    return 0;
}
