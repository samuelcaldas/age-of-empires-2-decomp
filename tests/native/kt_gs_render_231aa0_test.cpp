#include "kt_gs_render_231aa0.h"
#include <cassert>

extern int g_called_231aa0;

int main() {
    g_called_231aa0 = 0;
    int res = func_00231AA0(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_231aa0 == 1);
    assert(res == 1);
    return 0;
}
