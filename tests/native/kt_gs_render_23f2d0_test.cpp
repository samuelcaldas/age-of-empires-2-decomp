#include "kt_gs_render_23f2d0.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_0023F2D0(buffer, 0, 0);
    func_0023F3B0(buffer);
    func_0023F3D0(buffer);
    std::cout << "kt_gs_render_23f2d0 native tests passed." << std::endl;
    return 0;
}
