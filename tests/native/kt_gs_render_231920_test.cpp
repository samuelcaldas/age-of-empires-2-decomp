#include "kt_gs_render_231920.h"
#include <cassert>

extern int g_called_231920;

int main() {
    g_called_231920 = 0;
    int res = func_00231920(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_231920 == 1);
    assert(res == 1);
    return 0;
}
