#include "kt_gs_render_245590.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_00245590(buffer);
    assert(buffer[0] == 0x55);
    std::cout << "kt_gs_render_245590 native tests passed." << std::endl;
    return 0;
}
