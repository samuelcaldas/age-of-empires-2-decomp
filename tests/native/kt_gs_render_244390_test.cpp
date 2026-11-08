#include "kt_gs_render_244390.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_00244390(buffer);
    assert(buffer[0] == 0x3F);
    std::cout << "kt_gs_render_244390 native tests passed." << std::endl;
    return 0;
}
