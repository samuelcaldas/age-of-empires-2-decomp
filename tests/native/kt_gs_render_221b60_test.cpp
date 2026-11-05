#include <cassert>
#include "kt_gs_render_221b60.h"

int g_calls_00221ac0 = 0;

extern "C" void func_00221AC0(void) {
    g_calls_00221ac0++;
}

int main() {
    g_calls_00221ac0 = 0;
    func_00221B60();
    func_00221C00();
    assert(g_calls_00221ac0 == 1);
    return 0;
}

