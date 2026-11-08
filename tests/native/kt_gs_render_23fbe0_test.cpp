#include "kt_gs_render_23fbe0.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_0023FBE0(buffer, 0);
    func_0023FC30(buffer);
    func_0023FC40();
    std::cout << "kt_gs_render_23fbe0 native tests passed." << std::endl;
    return 0;
}
