#include <cassert>
#include "network_state_set_337820.h"

int D_004E3530 = 0;

int main() {
    D_004E3530 = 0;
    func_00337820(0x12345678);
    assert(D_004E3530 == 0x12345678);

    func_00337820(0);
    assert(D_004E3530 == 0);

    func_00337820(-1);
    assert(D_004E3530 == -1);

    return 0;
}
