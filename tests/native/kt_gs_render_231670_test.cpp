#include "kt_gs_render_231670.h"
#include <cassert>

extern int g_called_231670;
extern int g_called_2316b0;
extern int g_called_231710;
extern int g_called_231760;

int main() {
    g_called_231670 = 0;
    g_called_2316b0 = 0;
    g_called_231710 = 0;
    g_called_231760 = 0;

    int r0 = func_00231670(nullptr, nullptr, nullptr, nullptr);
    int r1 = func_002316B0(nullptr, nullptr, nullptr, nullptr);
    int r2 = func_00231710(nullptr, nullptr, nullptr, nullptr);
    int r3 = func_00231760(nullptr, nullptr, nullptr, nullptr);

    assert(g_called_231670 == 1);
    assert(g_called_2316b0 == 1);
    assert(g_called_231710 == 1);
    assert(g_called_231760 == 1);
    assert(r0 == 1 && r1 == 1 && r2 == 1 && r3 == 1);
    return 0;
}
