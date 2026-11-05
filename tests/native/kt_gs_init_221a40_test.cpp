#include <cassert>
#include "kt_gs_init_221a40.h"

int g_calls_00103920 = 0;
int g_last_arg_00103920 = 0;
int g_calls_00221a40 = 0;

extern "C" void func_00103920(int arg) {
    g_calls_00103920++;
    g_last_arg_00103920 = arg;
}

int main() {
    g_calls_00103920 = 0;
    func_00221A40();
    assert(g_calls_00103920 == 2);
    assert(g_last_arg_00103920 == 8);

    func_00221AC0();
    return 0;
}
