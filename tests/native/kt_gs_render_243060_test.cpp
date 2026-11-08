#include "kt_gs_render_243060.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_00243060(buffer);
    assert(buffer[0] == 0xBC);
    std::cout << "kt_gs_render_243060 native tests passed." << std::endl;
    return 0;
}
