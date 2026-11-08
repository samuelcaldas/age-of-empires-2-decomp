#include "kt_gs_render_243f80.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_00243F80(buffer);
    assert(buffer[0] == 0xEF);
    std::cout << "kt_gs_render_243f80 native tests passed." << std::endl;
    return 0;
}
