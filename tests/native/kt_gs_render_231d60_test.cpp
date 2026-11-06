#include "kt_gs_render_231d60.h"
#include <cassert>

extern int g_called_231d60;

int main() {
    g_called_231d60 = 0;
    int res = func_00231D60(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_231d60 == 1);
    assert(res == 1);
    return 0;
}
