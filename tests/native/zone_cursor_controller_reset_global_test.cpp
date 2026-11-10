#include <cassert>
#include <cstdio>

extern "C" {
void *D_004E3260 = (void*)0x1234;
}

#include "../../src/zone/zone_cursor_controller_reset_global.cpp"

int main() {
    D_004E3260 = (void*)0xABCD;
    func_001DBB80();
    assert(D_004E3260 == 0);

    printf("zone_cursor_controller_reset_global_test passed\n");
    return 0;
}
