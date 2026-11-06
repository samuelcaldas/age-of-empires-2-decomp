#include "kt_gs_render_232f10.h"
#include <cassert>

extern int g_called_232f10;

int main() {
    g_called_232f10 = 0;
    int res = func_00232F10(nullptr, nullptr);
    assert(g_called_232f10 == 1);
    assert(res == 1);
    return 0;
}
