#include "kt_gs_render_231ef0.h"
#include <cassert>

extern int g_called_231ef0;

int main() {
    g_called_231ef0 = 0;
    int res = func_00231EF0(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_231ef0 == 1);
    assert(res == 1);
    return 0;
}
