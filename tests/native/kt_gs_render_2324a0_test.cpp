#include "kt_gs_render_2324a0.h"
#include <cassert>

extern int g_called_2324a0;

int main() {
    g_called_2324a0 = 0;
    int res = func_002324A0(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_2324a0 == 1);
    assert(res == 1);
    return 0;
}
