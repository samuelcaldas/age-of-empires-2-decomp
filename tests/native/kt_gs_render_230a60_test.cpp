#include "kt_gs_render_230a60.h"
#include <cassert>

extern int g_called_230a60;

int main() {
    g_called_230a60 = 0;
    int res = func_00230A60(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_230a60 == 1);
    assert(res == 1);
    return 0;
}
