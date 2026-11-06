#include "kt_gs_render_231b70.h"
#include <cassert>

extern int g_called_231b70;

int main() {
    g_called_231b70 = 0;
    int res = func_00231B70(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_231b70 == 1);
    assert(res == 1);
    return 0;
}
