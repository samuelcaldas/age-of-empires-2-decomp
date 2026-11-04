#include <cassert>
#include "network_state_get_337830.h"

int D_004E3530 = 0;

int main() {
    D_004E3530 = 0x87654321;
    assert(func_00337830() == 0x87654321);

    D_004E3530 = 0;
    assert(func_00337830() == 0);

    D_004E3530 = -42;
    assert(func_00337830() == -42);

    return 0;
}
