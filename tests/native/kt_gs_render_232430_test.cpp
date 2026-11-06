#include "kt_gs_render_232430.h"
#include <cassert>

extern int g_called_232430;

int main() {
    g_called_232430 = 0;
    int res = func_00232430(nullptr, nullptr);
    assert(g_called_232430 == 1);
    assert(res == 1);
    return 0;
}
