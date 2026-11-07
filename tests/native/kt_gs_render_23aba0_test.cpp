#include "kt_gs_render_23aba0.h"
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x2000];
    std::memset(buffer, 0, sizeof(buffer));

    uint32_t* slots = (uint32_t*)(buffer + 0x1054);
    slots[0] = 0x11111111;
    slots[1] = 0x22222222;
    slots[2] = 0x33333333;
    slots[3] = 0x44444444;
    slots[4] = 0x55555555;

    assert((uintptr_t)func_0023AD20(buffer, 0) == 0x11111111);
    assert((uintptr_t)func_0023AD20(buffer, 1) == 0x22222222);
    assert((uintptr_t)func_0023AD20(buffer, 2) == 0x33333333);
    assert((uintptr_t)func_0023AD20(buffer, 3) == 0x44444444);
    assert((uintptr_t)func_0023AD20(buffer, 4) == 0x55555555);
    assert(func_0023AD20(buffer, 5) == 0);
    assert(func_0023AD20(buffer, -1) == 0);

    assert(func_0023ADA0() == 0);
    func_0023ADB0();

    std::cout << "kt_gs_render_23aba0 native tests passed." << std::endl;
    return 0;
}
