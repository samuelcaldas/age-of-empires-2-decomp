#include "kt_gs_render_242aa0.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_00242AA0(buffer);
    assert(buffer[0] == 0x77);
    std::cout << "kt_gs_render_242aa0 native tests passed." << std::endl;
    return 0;
}
