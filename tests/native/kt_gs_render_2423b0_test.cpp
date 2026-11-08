#include "kt_gs_render_2423b0.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x1000];
    std::memset(buffer, 0, sizeof(buffer));

    func_002423B0(buffer);
    assert(buffer[0] == 0x42);
    std::cout << "kt_gs_render_2423b0 native tests passed." << std::endl;
    return 0;
}
