#include "kt_gs_render_23ff80.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x1000];
    std::memset(buffer, 0, sizeof(buffer));

    func_0023FF80(buffer);
    std::cout << "kt_gs_render_23ff80 native tests passed." << std::endl;
    return 0;
}
