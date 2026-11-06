#include "kt_gs_render_22e690.h"
#include <cassert>

extern int g_called_22e690;

int main() {
    g_called_22e690 = 0;
    int res = func_0022E690(nullptr, nullptr, nullptr, nullptr);
    assert(g_called_22e690 == 1);
    assert(res == 1);
    return 0;
}
