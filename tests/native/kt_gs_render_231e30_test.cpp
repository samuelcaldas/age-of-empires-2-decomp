#include "kt_gs_render_231e30.h"
#include <cassert>

extern int g_called_231e30;

int main() {
    g_called_231e30 = 0;
    int res = func_00231E30(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_231e30 == 1);
    assert(res == 1);
    return 0;
}
