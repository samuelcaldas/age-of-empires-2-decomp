#include "kt_gs_render_242d60.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_00242D60(buffer);
    assert(buffer[0] == 0x99);
    std::cout << "kt_gs_render_242d60 native tests passed." << std::endl;
    return 0;
}
