#include "kt_gs_render_23fa60.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x1000];
    std::memset(buffer, 0, sizeof(buffer));

    func_0023FA60(buffer);
    std::cout << "kt_gs_render_23fa60 native tests passed." << std::endl;
    return 0;
}
