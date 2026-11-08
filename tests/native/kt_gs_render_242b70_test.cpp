#include "kt_gs_render_242b70.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_00242B70(buffer);
    assert(buffer[0] == 0x55);
    std::cout << "kt_gs_render_242b70 native tests passed." << std::endl;
    return 0;
}
