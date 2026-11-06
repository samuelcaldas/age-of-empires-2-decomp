#include "kt_gs_render_232300.h"
#include <cassert>

extern int g_called_232300;

int main() {
    g_called_232300 = 0;
    int res = func_00232300(nullptr, nullptr);
    assert(g_called_232300 == 1);
    assert(res == 1);
    return 0;
}
