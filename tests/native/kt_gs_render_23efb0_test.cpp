#include "kt_gs_render_23efb0.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_0023EFB0(buffer, 0, 0);
    std::cout << "kt_gs_render_23efb0 native tests passed." << std::endl;
    return 0;
}
