#include "kt_gs_render_2432c0.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_002432C0(buffer);
    assert(buffer[0] == 0xDE);
    std::cout << "kt_gs_render_2432c0 native tests passed." << std::endl;
    return 0;
}
