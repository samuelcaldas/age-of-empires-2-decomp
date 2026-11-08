#include "kt_gs_render_23f6c0.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x1000];
    std::memset(buffer, 0, sizeof(buffer));

    func_0023F6C0(buffer, 0);
    func_0023F7D0(buffer);
    std::cout << "kt_gs_render_23f6c0 native tests passed." << std::endl;
    return 0;
}
