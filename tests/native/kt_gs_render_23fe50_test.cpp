#include "kt_gs_render_23fe50.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_0023FE50(buffer);
    std::cout << "kt_gs_render_23fe50 native tests passed." << std::endl;
    return 0;
}
