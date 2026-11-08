#include "kt_gs_render_244f20.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_00244F20(buffer);
    assert(buffer[0] == 0xF2);
    std::cout << "kt_gs_render_244f20 native tests passed." << std::endl;
    return 0;
}
